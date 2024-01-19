
cmake_minimum_required(VERSION 3.27.0)

project("renderings" LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED YES)


if(CMAKE_VERSION VERSION_LESS "3.27.0")
  set(CMAKE_EXPERIMENTAL_CXX_MODULE_CMAKE_API "2182bf5c-ef0d-489a-91da-49dbc3090d2a")
else()
  set(CMAKE_EXPERIMENTAL_CXX_MODULE_CMAKE_API "aa1f7df0-828a-4fcd-9afc-2dc80491aca7")
endif()
set(CMAKE_EXPERIMENTAL_CXX_MODULE_DYNDEP 1)





#set(LIBCXX_BUILD "Q:/LosProgram/clangModule/llvm-project/build")
#add_compile_options($<$<COMPILE_LANGUAGE:CXX>:-fprebuilt-module-path=${CMAKE_BINARY_DIR}/_deps/std-build/CMakeFiles/std.dir/>)
#add_compile_options($<$<COMPILE_LANGUAGE:CXX>:-nostdinc++>)
## The include path needs to be set to be able to use macros from headers.
## For example from, the headers <cassert> and <version>.
#add_compile_options($<$<COMPILE_LANGUAGE:CXX>:-isystem>)
#add_compile_options($<$<COMPILE_LANGUAGE:CXX>:${LIBCXX_BUILD}/include/c++/v1>)

set(CMAKE_ANDROID_ARCH_ABI arm64-v8a)

# see library Q:\AndroidSDK\ndk\24.0.7956693\toolchains\llvm\prebuilt\windows-x86_64\sysroot\usr\lib\aarch64-linux-android\28
MESSAGE(WARNING "sdf: " ${ANDROID_PLATFORM})
set(gluLos ../../GlueLos)

set(cpuFeatures ../../../AndroidSDK/ndk/25.0.8775105/sources/android/cpufeatures)

if(${ANDROID_PLATFORM} MATCHES "android-28" )
  MESSAGE(WARNING " minAPI 28 ok ")  #  was 24
  set(exists33 false)
else()
  MESSAGE(WARNING " minAPi 33 ok  ")
  set(exists33 true)
endif()


#add_definitions(-DLIBCXX_ENABLE_STD_MODULES=ON)
#add_definitions(-DLLVM_ENABLE_RUNTIMES="libcxx;libcxxabi;libunwind")
add_definitions(-DVK_USE_PLATFORM_ANDROID_KHR=1)

#add_library(glueLos STATIC ${gluLos}/los_android_native_app_glue.c)

add_library(glueLos STATIC IMPORTED)
set_property(TARGET glueLos PROPERTY IMPORTED_LOCATION "../../../../src/jniLibs/arm64-v8a/libglueLos.a")


#add_library(featureCPU STATIC ${cpuFeatures}/cpu-features.c)
add_library(featureCPU STATIC IMPORTED)
set_property(TARGET featureCPU PROPERTY IMPORTED_LOCATION "../../../../src/jniLibs/arm64-v8a/libfeatureCPU.a")

set(CMAKE_SHARED_LINKER_FLAGS "${CMAKE_SHARED_LINKER_FLAGS} -u ANativeActivity_onCreate")

add_library( renderingsLos  SHARED

        src/main/cpp/renderingStart.cpp
       #
       # src/main/cpp/moduletest/LosModule.cpp
        src/main/cpp/mainLos/LosMainVulkan.cpp
        src/main/cpp/mainLos/assetsLos.c
        src/main/cpp/gameRender.cpp
        # src/main/cpp/foo.ixx
        src/main/cpp/AudioEngines/AudioMain.cpp
        )

#add_library(validKhronosLayers SHARED IMPORTED)
#set_property(TARGET renderingsLos PROPERTY IMPORTED_LOCATION "../../../../src/jniLibs/arm64-v8a/libVkLayer_khronos_validation.so")


find_library(  log-lib

              log )


target_sources(renderingsLos
        PUBLIC
        FILE_SET all_my_modules TYPE CXX_MODULES FILES
        src/main/cpp/foo.ixx
        )


target_include_directories(renderingsLos PRIVATE
        ${gluLos}
        ../../VulkanHeaders/include
        src/main/cpp/mainLos/
        src/main/cpp/AudioEngines/
        ${cpuFeatures}

        )


target_compile_options(renderingsLos PUBLIC -fsanitize=address -fno-omit-frame-pointer)
set_target_properties(renderingsLos PROPERTIES LINK_FLAGS -fsanitize=address)

get_filename_component(HINT_PATH ${ANDROID_C_COMPILER} DIRECTORY)
#set(ARCH_STR ${CMAKE_ANDROID_ARCH})
set(ARCH_STR "aarch64")

find_file(ASAN
        NAMES libclang_rt.asan-${ARCH_STR}-android.so
        HINTS ${HINT_PATH}/../lib64/clang/14.0.1/lib/linux)


get_filename_component(ASAN_NAME ${ASAN} NAME)
set(ASAN_NAME ${CMAKE_SOURCE_DIR}/../jniLibs/${CMAKE_ANDROID_ARCH_ABI}/${ASAN_NAME})






if(${exists33})
  #set(BinaryLibraryAdd EGL GLESv3)
   set(BinaryLibraryAdd vulkan)
else()
  set(BinaryLibraryAdd vulkan)
endif()

add_custom_command(
        TARGET renderingsLos PRE_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy ${ASAN} ${ASAN_NAME})

set_target_properties(renderingsLos PROPERTIES COMPILE_OPTIONS -fopenmp)

target_link_libraries(renderingsLos
                      ${BinaryLibraryAdd}
                       android
                       glueLos
                       featureCPU
                      -fopenmp
                      -static-openmp
                       aaudio
                      -pthread
                      ${log-lib} )

# add sanitize for android
#if(ANDROID_ABI STREQUAL "arm64-v8a" AND HWASAN)
#  MESSAGE(WARNING " in hwasan " )
#  target_compile_options(renderingsLos PUBLIC -fsanitize=hwaddress -fno-omit-frame-pointer)
#  set_target_properties(renderingsLos PROPERTIES LINK_FLAGS -fsanitize=hwaddress)
#endif()
