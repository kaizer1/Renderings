# For more information about using CMake with Android Studio, read the
# documentation: https://d.android.com/studio/projects/add-native-code.html

# was 3.18.1
cmake_minimum_required(VERSION 3.18.1)

project("renderings")

# see library Q:\AndroidSDK\ndk\24.0.7956693\toolchains\llvm\prebuilt\windows-x86_64\sysroot\usr\lib\aarch64-linux-android\28
MESSAGE(WARNING "sdf: " ${ANDROID_PLATFORM})
set(gluLos ../../GlueLos)

set(cpuFeatures ../../../AndroidSDK/ndk/25.0.8775105/sources/android/cpufeatures)

if(${ANDROID_PLATFORM} MATCHES "android-24" )
  MESSAGE(WARNING " minAPI 24 ok ")
  set(exists30 false)
else()
  MESSAGE(WARNING " minAPi 30 ok  ")
  set(exists30 true)
endif()


#add_library(glueLos STATIC ${gluLos}/los_android_native_app_glue.c)

add_library(glueLos STATIC IMPORTED)
set_property(TARGET glueLos PROPERTY IMPORTED_LOCATION "../../../../src/jniLibs/arm64-v8a/libglueLos.a")


#add_library(featureCPU STATIC ${cpuFeatures}/cpu-features.c)
add_library(featureCPU STATIC IMPORTED)
set_property(TARGET featureCPU PROPERTY IMPORTED_LOCATION "../../../../src/jniLibs/arm64-v8a/libfeatureCPU.a")

#set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -D_LIBCPP_HAS_PARALLEL_ALGORITHMS")
set(CMAKE_SHARED_LINKER_FLAGS "${CMAKE_SHARED_LINKER_FLAGS} -u ANativeActivity_onCreate")


add_library( renderingsLos  SHARED

        src/main/cpp/renderingStart.cpp
       #
       # src/main/cpp/moduletest/LosModule.cpp
#        src/main/cpp/mainLos/LosMainVulkan.cpp
#        src/main/cpp/mainLos/assetsLos.c
#        src/main/cpp/gameRender.cpp
        # src/main/cpp/foo.ixx
#        src/main/cpp/AudioEngines/AudioMain.cpp
        )


find_library(  log-lib

              log )

target_include_directories(renderingsLos PRIVATE
        ${gluLos}
        ../../VulkanHeaders/include
        src/main/cpp/mainLos/
        src/main/cpp/AudioEngines/
        ${cpuFeatures}

        )


if(${exists30})
  set(BinaryLibraryAdd EGL GLESv3)
else()
  set(BinaryLibraryAdd vulkan)
endif()



set_target_properties(renderingsLos PROPERTIES COMPILE_OPTIONS -fopenmp)

target_link_libraries(renderingsLos
                      ${BinaryLibraryAdd}
                       android
                       glueLos
                       featureCPU
                      -fopenmp
                      -static-openmp
                       aaudio # olny api 26 added
                      -pthread # ok added this
                      ${log-lib} )

# add sanitize for android
#if(ANDROID_ABI STREQUAL "arm64-v8a" AND HWASAN)
#  MESSAGE(WARNING " in hwasan " )
#  target_compile_options(renderingsLos PUBLIC -fsanitize=hwaddress -fno-omit-frame-pointer)
#  set_target_properties(renderingsLos PROPERTIES LINK_FLAGS -fsanitize=hwaddress)
#endif()
