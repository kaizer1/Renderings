# For more information about using CMake with Android Studio, read the
# documentation: https://d.android.com/studio/projects/add-native-code.html

# was 3.18.1
cmake_minimum_required(VERSION 3.18.1)


project("renderings")


MESSAGE(WARNING "sdf: " ${ANDROID_PLATFORM})
set(gluLos ../../GlueLos)

if(${ANDROID_PLATFORM} MATCHES "android-24" )
  MESSAGE(WARNING " minAPI 24 ok ")
  set(exists30 false)
else()
  MESSAGE(WARNING " minAPi 30 ok  ")
  set(exists30 true)
endif()


add_library(glueLos STATIC ${gluLos}/los_android_native_app_glue.c)

#set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -DVK_USE_PLATFORM_ANDROID_KHR")
set(CMAKE_SHARED_LINKER_FLAGS "${CMAKE_SHARED_LINKER_FLAGS} -u ANativeActivity_onCreate")


add_library( renderingsLos  SHARED

        src/main/cpp/renderingStart.cpp
        src/main/cpp/mainLos/LosMainVulkan.cpp
        src/main/cpp/mainLos/assetsLos.c
        src/main/cpp/gameRender.cpp
        )


find_library(  log-lib

              log )

target_include_directories(renderingsLos PRIVATE
        ${gluLos}
        ../../VulkanHeaders/include
        src/main/cpp/mainLos/

        )


if(${exists30})
  set(BinaryLibraryAdd EGL GLESv3)
else()
  set(BinaryLibraryAdd vulkan)
endif()


target_link_libraries(renderingsLos
                      ${BinaryLibraryAdd}
                       android
                       glueLos

                      ${log-lib} )

# add sanitize for android
#[[
if(ANDROID_ABI STREQUAL "arm64-v8a" AND HWASAN)
  target_compile_options(native-lib PUBLIC -fsanitize=hwaddress -fno-omit-frame-pointer)
  set_target_properties(native-lib PROPERTIES LINK_FLAGS -fsanitize=hwaddress)
endif()]]
