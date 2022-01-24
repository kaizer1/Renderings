// Loskutnikov Games .inc

#pragma once


#include <jni.h>
#include <string>
#include <dlfcn.h>
#include <los_android_native_app_glue.h>



#define LOAD_HARD(nama) nullptr


#include <vulkan/vulkan.h>
#include <vulkan/vulkan_core.h>
#include <android/log.h>
#include <android/native_window.h>
#include <vector>
#include <string>

#include <thread>
#include <concepts>
#include <experimental/coroutine>
#include <experimental/algorithm>
#include <execution>

#include <experimental/memory_resource>
#include <vulkan/vulkan_android.h>


#include "../gameRender.h"
//#include <module.modulemap>

/*import Foo;
import std.core;
using namespace std;*/
//improt module modulemap
//#include <execution>
// jthread


//#include <source_location>
//template <typename... Ts>
//void log(Ts&&... ts, const std::source_location& loc = std::source_location::current()) {
//    std::cout << loc.function_name() << " line " << loc.line() << ": ";
//    ((std::cout << std::forward<Ts>(ts) << " "), ...);
//    std::cout << '\n';
//}
//
//int main() {
//    log<int, int, std::string>(42, 100, "hello world");
//    log<double, std::string>(10.75, "an important parameter");
//}

#define logRun(...) ((void)__android_log_print(ANDROID_LOG_INFO, "RunGame", __VA_ARGS__))

#if(__ANDROID_API__ >= 30)
#include <android/thermal.h>
#include <vulkan/vulkan_android.h>

#else

#endif

struct myVulkan{
public:

    myVulkan() : mainInstance(VK_NULL_HANDLE) {

    }

    VkInstance  mainInstance;
};


//extern PFN_vkCreateDebugReportCallbackEXT FpvkCreateDebugReportCallbackEXT;



struct CheckVulkan {

    // checking Vulkan
public:

    CheckVulkan() {
        losLibrary = dlopen("libvulkan.so", RTLD_NOW | RTLD_LOCAL);
        if (!losLibrary)
            losLibrary = dlopen("libvulkan.so.1", RTLD_NOW | RTLD_LOCAL);
    }

    PFN_vkEnumerateInstanceVersion vkEnumerateInstanceVersion = LOAD_HARD(vkEnumerateInstanceVersion);
    PFN_vkEnumerateInstanceExtensionProperties vkEnumerateInstanceExtensionProperties =
            LOAD_HARD(vkEnumerateInstanceExtensionProperties);
    PFN_vkEnumerateInstanceLayerProperties vkEnumerateInstanceLayerProperties = LOAD_HARD(vkEnumerateInstanceLayerProperties);
    PFN_vkCreateInstance vkCreateInstance = LOAD_HARD(vkCreateInstance);
    PFN_vkGetInstanceProcAddr vkGetInstanceProcAddr = LOAD_HARD(vkGetInstanceProcAddr);
    PFN_vkDestroyInstance vkDestroyInstance = LOAD_HARD(vkDestroyInstance);
    //PFN_vkCreateDebugReportCallbackEXT vkCreateDebugReportCallbackEXT = LOAD_HARD(vkCreateDebugReportCallbackEXT);
    PFN_vkDebugReportCallbackEXT vkDebugReportCallbackEXT = LOAD_HARD(vkDebugReportCallbackEXT);
    //PFN_vkCreateAndroidSurfaceKHR vkCreateAndroidSurfaceKHRNew = LOAD_HARD(vkCreateAndroidSurfaceKHRNew);

    void initializedAll(){


        Load(vkEnumerateInstanceVersion, "vkEnumerateInstanceVersion");
        Load(vkEnumerateInstanceExtensionProperties, "vkEnumerateInstanceExtensionProperties");
        Load(vkEnumerateInstanceLayerProperties, "vkEnumerateInstanceLayerProperties");
        Load(vkCreateInstance, "vkCreateInstance");
        Load(vkDestroyInstance, "vkDestroyInstance");

        // vkGetInstanceProcAddr
        Load(vkGetInstanceProcAddr, "vkGetInstanceProcAddr");


        // extension not loading ??
        // Load(vkDebugReportCallbackEXT, "vkDebugReportCallbackEXT");
        // Load(vkCreateDebugReportCallbackEXT, "vkCreateDebugReportCallbackEXT");





    }

    void activateAndroid(){

        // LoadSurface(vkCreateAndroidSurfaceKHRNew, "vkCreateAndroidSurfaceKHR");
    }

    template <typename T>
    void Load(T& func_dest, const char* func_name) {
        func_dest = reinterpret_cast<T>(dlsym(losLibrary, func_name));

    }

    template <typename T>
    void LoadSurface(T& func_dest, const char* func_name) {
        func_dest = reinterpret_cast<PFN_vkCreateAndroidSurfaceKHR>(dlsym(losLibrary, func_name));

    }



private:
    void *losLibrary;
};




//extern "C" JNIEXPORT jstring JNICALL
//Java_com_sergey_los_freelanceideas_renderings_MainActivity_stringFromJNI(
//        JNIEnv* env,
//        jobject /* this */) {





/*VKAPI_ATTR VkResult VKAPI_CALL vkCreateDebugReportCallbackEXT_loader(
        VkInstance instance,
        const VkDebugReportCallbackCreateInfoEXT* pCreateInfo,
        const VkAllocationCallbacks* pAllocator,
        VkDebugReportCallbackEXT* pCallback
){
    PFN_vkVoidFunction temp_fp = vkGetInstanceProcAddr( instance, "vkCreateDebugReportCallbackEXT" );
    if( !temp_fp ) throw  "Failed to load vkCreateDebugReportCallbackEXT";

    FpvkCreateDebugReportCallbackEXT = reinterpret_cast<PFN_vkCreateDebugReportCallbackEXT>( temp_fp );

    return vkCreateDebugReportCallbackEXT( instance, pCreateInfo, pAllocator, pCallback );
}*/

//PFN_vkCreateDebugReportCallbackEXT FpvkCreateDebugReportCallbackEXT = &vkCreateDebugReportCallbackEXT_loader;


/*VKAPI_ATTR VkResult VKAPI_CALL vkCreateDebugReportCallbackEXT(
        VkInstance instance,
        const VkDebugReportCallbackCreateInfoEXT* pCreateInfo,
        const VkAllocationCallbacks* pAllocator,
        VkDebugReportCallbackEXT* pCallback
){
    return FpvkCreateDebugReportCallbackEXT( instance, pCreateInfo, pAllocator, pCallback );
}*/



extern android_app* mainAp;


struct saved_state
{
    float x;
    float y;
};


class LosMainVulkan {

public:
      LosMainVulkan();
      ~LosMainVulkan();

      static void LosApplicationCMD(struct android_app* app, int32_t cmd);
      static int32_t losInputWorkingHandle (struct android_app* app, AInputEvent* event);

      const void looperMainVulkan();

private:

    void inputWrapper(int32_t cmd);
    void initializeMyVulkan();
};


//#endif //RENDERINGS_LOSMAINVULKAN_H
