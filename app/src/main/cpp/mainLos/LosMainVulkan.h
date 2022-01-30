// Loskutnikov Games .inc

#pragma once

//import std_config;
//import cstring;
//import string;

#include <jni.h>

#include <string>
#include <dlfcn.h>
#include <los_android_native_app_glue.h>



#define LOAD_HARD(nama) nullptr


#include <vulkan/vulkan.h>
#include <vulkan/vulkan_core.h>
#include <android/log.h>
#include <android/native_window.h>





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
    uint32_t mLosQueueFIndex; // graphics index
    VkDevice mDeviceLos;
    VkQueue mQueueLos;
    VkSurfaceFormatKHR mSurfaceLosFormat;
    VkSwapchainKHR swapChainMain;
};


//extern PFN_vkCreateDebugReportCallbackEXT FpvkCreateDebugReportCallbackEXT;

struct SwapchainBuffer
{
    VkImage image;
    VkCommandBuffer cmdBuffer;
    VkImageView view;
};

struct DepthBufferLos
{
    VkFormat format;
    VkImage image;
    VkDeviceMemory mem;
    VkImageView view;
};


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
    PFN_vkDestroyDevice vkDestroyDevice = LOAD_HARD(vkDestroyDevice);
    PFN_vkDestroySurfaceKHR vkDestroySurfaceKHR = LOAD_HARD(vkDestroySurfaceKHR);
    PFN_vkDestroySwapchainKHR vkDestroySwapchainKHR = LOAD_HARD(vkDestroySwapchainKHR);
    PFN_vkCreateDevice vkCreateDevice = LOAD_HARD(vkCreateDevice);
    PFN_vkCreateSwapchainKHR vkCreateSwapchainKHR = LOAD_HARD(vkCreateSwapchainKHR);
    PFN_vkCreateImageView vkCreateImageView = LOAD_HARD(vkCreateImageView);
    PFN_vkCreateImage vkCreateImage = LOAD_HARD(vkCreateImage);
    PFN_vkAllocateMemory vkAllocateMemory = LOAD_HARD(vkAllocateMemory);
    PFN_vkBindImageMemory vkBindImageMemory = LOAD_HARD(vkBindImageMemory);
    PFN_vkCreateCommandPool vkCreateCommandPool = LOAD_HARD(vkCreateCommandPool);
    PFN_vkAllocateCommandBuffers vkAllocateCommandBuffers = LOAD_HARD(vkAllocateCommandBuffers);
    PFN_vkCreateSemaphore vkCreateSemaphore = LOAD_HARD(vkCreateSemaphore);
    PFN_vkCreateFence vkCreateFence = LOAD_HARD(vkCreateFence);
    PFN_vkResetCommandBuffer vkResetCommandBuffer = LOAD_HARD(vkResetCommandBuffer);
    PFN_vkBeginCommandBuffer vkBeginCommandBuffer = LOAD_HARD(vkBeginCommandBuffer);
    PFN_vkEndCommandBuffer vkEndCommandBuffer = LOAD_HARD(vkEndCommandBuffer);
    PFN_vkQueueSubmit vkQueueSubmit = LOAD_HARD(vkQueueSubmit);
    PFN_vkResetFences vkResetFences = LOAD_HARD(vkResetFences);
    PFN_vkWaitForFences vkWaitForFences = LOAD_HARD(vkWaitForFences);
    PFN_vkCmdPipelineBarrier vkCmdPipelineBarrier = LOAD_HARD(vkCmdPipelineBarrier);
    PFN_vkFreeCommandBuffers vkFreeCommandBuffers = LOAD_HARD(vkFreeCommandBuffers);
    PFN_vkDestroyImageView vkDestroyImageView = LOAD_HARD(vkDestroyImageView);
    PFN_vkDestroyImage vkDestroyImage = LOAD_HARD(vkDestroyImage);
    PFN_vkFreeMemory vkFreeMemory = LOAD_HARD(vkFreeMemory);
    PFN_vkDestroyCommandPool vkDestroyCommandPool = LOAD_HARD(vkDestroyCommandPool);
    PFN_vkDestroySemaphore vkDestroySemaphore = LOAD_HARD(vkDestroySemaphore);
    PFN_vkDestroyFence vkDestroyFence = LOAD_HARD(vkDestroyFence);




    void initializedAll(){


        Load(vkEnumerateInstanceVersion, "vkEnumerateInstanceVersion");
        Load(vkEnumerateInstanceExtensionProperties, "vkEnumerateInstanceExtensionProperties");
        Load(vkEnumerateInstanceLayerProperties, "vkEnumerateInstanceLayerProperties");
        Load(vkCreateInstance, "vkCreateInstance");
        Load(vkDestroyInstance, "vkDestroyInstance");
        Load(vkDestroyDevice, "vkDestroyDevice");
        Load(vkDestroySurfaceKHR, "vkDestroySurfaceKHR");
        Load(vkDestroySwapchainKHR, "vkDestroySwapchainKHR");
        Load(vkCreateDevice, "vkCreateDevice");
        Load(vkCreateSwapchainKHR, "vkCreateSwapchainKHR");
        Load(vkCreateImageView, "vkCreateImageView");
        Load(vkCreateImage, "vkCreateImage");
        Load(vkAllocateMemory, "vkAllocateMemory");
        Load(vkBindImageMemory, "vkBindImageMemory");
        Load(vkCreateCommandPool, "vkCreateCommandPool");
        Load(vkAllocateCommandBuffers, "vkAllocateCommandBuffers");
        Load(vkCreateSemaphore, "vkCreateSemaphore");
        Load(vkCreateFence, "vkCreateFence");
        Load(vkResetCommandBuffer, "vkResetCommandBuffer");
        Load(vkBeginCommandBuffer, "vkBeginCommandBuffer");
        Load(vkEndCommandBuffer, "vkEndCommandBuffer");
        Load(vkQueueSubmit, "vkQueueSubmit");
        Load(vkResetFences, "vkResetFences");
        Load(vkWaitForFences, "vkWaitForFences");
        Load(vkCmdPipelineBarrier, "vkCmdPipelineBarrier");
        Load(vkFreeCommandBuffers, "vkFreeCommandBuffers");
        Load(vkDestroyImageView, "vkDestroyImageView");
        Load(vkDestroyImage, "vkDestroyImage");
        Load(vkFreeMemory, "vkFreeMemory");
        Load(vkDestroyCommandPool, "vkDestroyCommandPool");
        Load(vkDestroySemaphore, "vkDestroySemaphore");
        Load(vkDestroyFence, "vkDestroyFence");

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

    VkDebugReportCallbackEXT cb1;

protected:
    void Render() noexcept;
     std::unique_ptr<gameRender> losGame;

     VkCommandPool lCommandPool;
     VkCommandBuffer setupBuffeCommands;

     VkSemaphore backBufferSema;
     VkSemaphore renderCompleteSema;
     VkFence fenceLos;

    //SwapchainBuffer* mySwapBuffer
    SwapchainBuffer* mySwapBuffer = nullptr;
    uint32_t mSwapImCountL;
    DepthBufferLos* depthLosBuffer = nullptr;
    void SetImageLayoutLos(VkImage image, VkCommandBuffer cmdBuffer, VkImageAspectFlags aspect,
                            VkImageLayout oldLayout, VkImageLayout newLayout, VkPipelineStageFlags scrMask=VK_PIPELINE_STAGE_TOP_OF_PIPE_BIT,
                            VkPipelineStageFlags  dstMask=VK_PIPELINE_STAGE_TOP_OF_PIPE_BIT, uint32_t mipLevel=0, uint32_t mipLevelCount = 1);


    VkSurfaceKHR mSurfaceLos;
    VkSurfaceFormatKHR mSurfaceFormat;
private:

    void inputWrapper(int32_t cmd);
    void initializeMyVulkan();

    uint32_t LosWidth;
    uint32_t LosHeight;
    myVulkan vulkanA;

    //  CheckVulkan *check
    std::unique_ptr<CheckVulkan> check;

    void PreDestroyAll() noexcept;
};


//#endif //RENDERINGS_LOSMAINVULKAN_H
