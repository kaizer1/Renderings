# For more information about using CMake with Android Studio, read the
# documentation: https://d.android.com/studio/projects/add-native-code.html

cmake_minimum_required(VERSION 3.30.5)

project("renderings")


MESSAGE(WARNING "sdf: " ${ANDROID_PLATFORM})
set(gluLos lGlue)

if(${ANDROID_PLATFORM} MATCHES "android-24" )
  MESSAGE(WARNING " minAPI 24 ok ")
  set(exists30 false)
else()
  MESSAGE(WARNING " minAPi 30 ok  ")
  set(exists30 true)
endif()


add_library(glueLos STATIC ${gluLos}/los_android_native_app_glue.c)


set(CMAKE_SHARED_LINKER_FLAGS
        "${CMAKE_SHARED_LINKER_FLAGS} -u ANativeActivity_onCreate")


add_library( renderingsLos  SHARED

        src/main/cpp/renderingStart.cpp)


find_library(  log-lib

              log )

target_include_directories(renderingsLos PRIVATE
        ${gluLos}
        ../../VulkanHeaders/include

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