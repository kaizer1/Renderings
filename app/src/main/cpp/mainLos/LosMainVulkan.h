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

#include "AudioMain.h"



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



#if(__ANDROID_API__ >= 29)
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

struct Vertices
{
    VkBuffer buf;
    VkDeviceMemory mem;
    VkPipelineVertexInputStateCreateInfo vi;
    VkVertexInputBindingDescription      vi_bindings[1];
    VkVertexInputAttributeDescription    vi_attrs[2];
};


#include <logLos.h>


//PFN_vkEnumerateInstanceVersion vkEnumerateInstanceVersion;

struct CheckVulkan {

    // checking Vulkan
public:



    void aa(){

    }

    CheckVulkan() {
        logRun(" not loading 01 ");
        losLibrary = dlopen("libvulkan.so", RTLD_NOW | RTLD_LOCAL);

        if (!losLibrary)
        {
           logRun(" not loading ");

            losLibrary = dlopen("libvulkan.so.1", RTLD_NOW | RTLD_LOCAL);
        }else{
            logRun(" ok loading !! !");

   // PFN_vkEnumerateInstanceVersion vkEnumerateInstanceVersion = LOAD_HARD(vkEnumerateInstanceVersion);
   // PFN_vkEnumerateInstanceExtensionProperties vkEnumerateInstanceExtensionProperties =
     //       LOAD_HARD(vkEnumerateInstanceExtensionProperties);


            initializedAll();
    //    PFN_vkEnumerateInstanceLayerProperties vkEnumerateInstanceLayerProperties = LOAD_HARD(vkEnumerateInstanceLayerProperties);
//    PFN_vkCreateInstance vkCreateInstance = LOAD_HARD(vkCreateInstance);
//    PFN_vkGetInstanceProcAddr vkGetInstanceProcAddr = LOAD_HARD(vkGetInstanceProcAddr);
//    PFN_vkDestroyInstance vkDestroyInstance = LOAD_HARD(vkDestroyInstance);
//    //PFN_vkCreateDebugReportCallbackEXT vkCreateDebugReportCallbackEXT = LOAD_HARD(vkCreateDebugReportCallbackEXT);
//    PFN_vkDebugReportCallbackEXT vkDebugReportCallbackEXT = LOAD_HARD(vkDebugReportCallbackEXT);
//    //PFN_vkCreateAndroidSurfaceKHR vkCreateAndroidSurfaceKHRNew = LOAD_HARD(vkCreateAndroidSurfaceKHRNew);
//    PFN_vkDestroyDevice vkDestroyDevice = LOAD_HARD(vkDestroyDevice);
//    PFN_vkDestroySurfaceKHR vkDestroySurfaceKHR = LOAD_HARD(vkDestroySurfaceKHR);
//    PFN_vkDestroySwapchainKHR vkDestroySwapchainKHR = LOAD_HARD(vkDestroySwapchainKHR);
//    PFN_vkCreateDevice vkCreateDevice = LOAD_HARD(vkCreateDevice);
//    PFN_vkCreateSwapchainKHR vkCreateSwapchainKHR = LOAD_HARD(vkCreateSwapchainKHR);
//    PFN_vkCreateImageView vkCreateImageView = LOAD_HARD(vkCreateImageView);
//    PFN_vkCreateImage vkCreateImage = LOAD_HARD(vkCreateImage);
//    PFN_vkAllocateMemory vkAllocateMemory = LOAD_HARD(vkAllocateMemory);
//    PFN_vkBindImageMemory vkBindImageMemory = LOAD_HARD(vkBindImageMemory);
//    PFN_vkCreateCommandPool vkCreateCommandPool = LOAD_HARD(vkCreateCommandPool);
//    PFN_vkAllocateCommandBuffers vkAllocateCommandBuffers = LOAD_HARD(vkAllocateCommandBuffers);
//    PFN_vkCreateSemaphore vkCreateSemaphore = LOAD_HARD(vkCreateSemaphore);
//    PFN_vkCreateFence vkCreateFence = LOAD_HARD(vkCreateFence);
//    PFN_vkResetCommandBuffer vkResetCommandBuffer = LOAD_HARD(vkResetCommandBuffer);
//    PFN_vkBeginCommandBuffer vkBeginCommandBuffer = LOAD_HARD(vkBeginCommandBuffer);
//    PFN_vkEndCommandBuffer vkEndCommandBuffer = LOAD_HARD(vkEndCommandBuffer);
//    PFN_vkQueueSubmit vkQueueSubmit = LOAD_HARD(vkQueueSubmit);
//    PFN_vkResetFences vkResetFences = LOAD_HARD(vkResetFences);
//    PFN_vkWaitForFences vkWaitForFences = LOAD_HARD(vkWaitForFences);
//    PFN_vkCmdPipelineBarrier vkCmdPipelineBarrier = LOAD_HARD(vkCmdPipelineBarrier);
//    PFN_vkFreeCommandBuffers vkFreeCommandBuffers = LOAD_HARD(vkFreeCommandBuffers);
//    PFN_vkDestroyImageView vkDestroyImageView = LOAD_HARD(vkDestroyImageView);
//    PFN_vkDestroyImage vkDestroyImage = LOAD_HARD(vkDestroyImage);
//    PFN_vkFreeMemory vkFreeMemory = LOAD_HARD(vkFreeMemory);
//    PFN_vkDestroyCommandPool vkDestroyCommandPool = LOAD_HARD(vkDestroyCommandPool);
//    PFN_vkDestroySemaphore vkDestroySemaphore = LOAD_HARD(vkDestroySemaphore);
//    PFN_vkDestroyFence vkDestroyFence = LOAD_HARD(vkDestroyFence);
//    PFN_vkCreateRenderPass vkCreateRenderPass = LOAD_HARD(vkCreateRenderPass);
//    PFN_vkCreateShaderModule vkCreateShaderModule = LOAD_HARD(vkCreateShaderModule);
//    PFN_vkCreateGraphicsPipelines vkCreateGraphicsPipelines = LOAD_HARD(vkCreateGraphicsPipelines);
//    PFN_vkCreatePipelineCache vkCreatePipelineCache = LOAD_HARD(vkCreatePipelineCache);
//    PFN_vkDestroyPipelineCache vkDestroyPipelineCache = LOAD_HARD(vkDestroyPipelineCache);
//    PFN_vkDestroyShaderModule vkDestroyShaderModule = LOAD_HARD(vkDestroyShaderModule);
//    PFN_vkCreateBuffer vkCreateBuffer = LOAD_HARD(vkCreateBuffer);
//    PFN_vkGetBufferMemoryRequirements vkGetBufferMemoryRequirements = LOAD_HARD(vkGetBufferMemoryRequirements);
//    PFN_vkQueuePresentKHR vkQueuePresentKHR = LOAD_HARD(vkQueuePresentKHR);
//    PFN_vkAcquireNextImageKHR vkAcquireNextImageKhr = LOAD_HARD(vkAcquireNextImageKhr);
//    PFN_vkCmdBeginRenderPass vkCmdBeginRenderPass = LOAD_HARD(vkCmdBeginRenderPass);
//    PFN_vkCmdBindPipeline vkCmdBindPipeline = LOAD_HARD(vkCmdBindPipeline);
//    PFN_vkCmdEndRenderPass vkCmdEndRenderPass = LOAD_HARD(vkCmdEndRenderPass);
//    PFN_vkCmdDraw vkCmdDraw = LOAD_HARD(vkCmdDraw);
//    PFN_vkCmdBindVertexBuffers vkCmdBindVertexBuffers = LOAD_HARD(vkCmdBindVertexBuffers);
//    PFN_vkMapMemory vkMapMemory = LOAD_HARD(vkMapMemory);
//    PFN_vkUnmapMemory vkUnmapMemory = LOAD_HARD(vkUnmapMemory);
//    PFN_vkBindBufferMemory vkBindBufferMemory = LOAD_HARD(vkBindBufferMemory);
//    PFN_vkCreateFramebuffer vkCreateFramebuffer = LOAD_HARD(vkCreateFramebuffer);

        }


    }

    PFN_vkEnumerateInstanceVersion vkEnumerateInstanceVersion = LOAD_HARD(vkEnumerateInstanceVersion);
    PFN_vkEnumerateInstanceExtensionProperties vkEnumerateInstanceExtensionProperties = LOAD_HARD(vkEnumerateInstanceExtensionProperties);
//    PFN_vkEnumerateInstanceLayerProperties vkEnumerateInstanceLayerProperties = LOAD_HARD(vkEnumerateInstanceLayerProperties);
//    PFN_vkCreateInstance vkCreateInstance = LOAD_HARD(vkCreateInstance);
//    PFN_vkGetInstanceProcAddr vkGetInstanceProcAddr = LOAD_HARD(vkGetInstanceProcAddr);
//    PFN_vkDestroyInstance vkDestroyInstance = LOAD_HARD(vkDestroyInstance);
//    //PFN_vkCreateDebugReportCallbackEXT vkCreateDebugReportCallbackEXT = LOAD_HARD(vkCreateDebugReportCallbackEXT);
//    PFN_vkDebugReportCallbackEXT vkDebugReportCallbackEXT = LOAD_HARD(vkDebugReportCallbackEXT);
//    //PFN_vkCreateAndroidSurfaceKHR vkCreateAndroidSurfaceKHRNew = LOAD_HARD(vkCreateAndroidSurfaceKHRNew);
//    PFN_vkDestroyDevice vkDestroyDevice = LOAD_HARD(vkDestroyDevice);
//    PFN_vkDestroySurfaceKHR vkDestroySurfaceKHR = LOAD_HARD(vkDestroySurfaceKHR);
//    PFN_vkDestroySwapchainKHR vkDestroySwapchainKHR = LOAD_HARD(vkDestroySwapchainKHR);
//    PFN_vkCreateDevice vkCreateDevice = LOAD_HARD(vkCreateDevice);
//    PFN_vkCreateSwapchainKHR vkCreateSwapchainKHR = LOAD_HARD(vkCreateSwapchainKHR);
//    PFN_vkCreateImageView vkCreateImageView = LOAD_HARD(vkCreateImageView);
//    PFN_vkCreateImage vkCreateImage = LOAD_HARD(vkCreateImage);
//    PFN_vkAllocateMemory vkAllocateMemory = LOAD_HARD(vkAllocateMemory);
//    PFN_vkBindImageMemory vkBindImageMemory = LOAD_HARD(vkBindImageMemory);
//    PFN_vkCreateCommandPool vkCreateCommandPool = LOAD_HARD(vkCreateCommandPool);
//    PFN_vkAllocateCommandBuffers vkAllocateCommandBuffers = LOAD_HARD(vkAllocateCommandBuffers);
//    PFN_vkCreateSemaphore vkCreateSemaphore = LOAD_HARD(vkCreateSemaphore);
//    PFN_vkCreateFence vkCreateFence = LOAD_HARD(vkCreateFence);
//    PFN_vkResetCommandBuffer vkResetCommandBuffer = LOAD_HARD(vkResetCommandBuffer);
//    PFN_vkBeginCommandBuffer vkBeginCommandBuffer = LOAD_HARD(vkBeginCommandBuffer);
//    PFN_vkEndCommandBuffer vkEndCommandBuffer = LOAD_HARD(vkEndCommandBuffer);
//    PFN_vkQueueSubmit vkQueueSubmit = LOAD_HARD(vkQueueSubmit);
//    PFN_vkResetFences vkResetFences = LOAD_HARD(vkResetFences);
//    PFN_vkWaitForFences vkWaitForFences = LOAD_HARD(vkWaitForFences);
//    PFN_vkCmdPipelineBarrier vkCmdPipelineBarrier = LOAD_HARD(vkCmdPipelineBarrier);
//    PFN_vkFreeCommandBuffers vkFreeCommandBuffers = LOAD_HARD(vkFreeCommandBuffers);
//    PFN_vkDestroyImageView vkDestroyImageView = LOAD_HARD(vkDestroyImageView);
//    PFN_vkDestroyImage vkDestroyImage = LOAD_HARD(vkDestroyImage);
//    PFN_vkFreeMemory vkFreeMemory = LOAD_HARD(vkFreeMemory);
//    PFN_vkDestroyCommandPool vkDestroyCommandPool = LOAD_HARD(vkDestroyCommandPool);
//    PFN_vkDestroySemaphore vkDestroySemaphore = LOAD_HARD(vkDestroySemaphore);
//    PFN_vkDestroyFence vkDestroyFence = LOAD_HARD(vkDestroyFence);
//    PFN_vkCreateRenderPass vkCreateRenderPass = LOAD_HARD(vkCreateRenderPass);
//    PFN_vkCreateShaderModule vkCreateShaderModule = LOAD_HARD(vkCreateShaderModule);
//    PFN_vkCreateGraphicsPipelines vkCreateGraphicsPipelines = LOAD_HARD(vkCreateGraphicsPipelines);
//    PFN_vkCreatePipelineCache vkCreatePipelineCache = LOAD_HARD(vkCreatePipelineCache);
//    PFN_vkDestroyPipelineCache vkDestroyPipelineCache = LOAD_HARD(vkDestroyPipelineCache);
//    PFN_vkDestroyShaderModule vkDestroyShaderModule = LOAD_HARD(vkDestroyShaderModule);
//    PFN_vkCreateBuffer vkCreateBuffer = LOAD_HARD(vkCreateBuffer);
//    PFN_vkGetBufferMemoryRequirements vkGetBufferMemoryRequirements = LOAD_HARD(vkGetBufferMemoryRequirements);
//    PFN_vkQueuePresentKHR vkQueuePresentKHR = LOAD_HARD(vkQueuePresentKHR);
//    PFN_vkAcquireNextImageKHR vkAcquireNextImageKhr = LOAD_HARD(vkAcquireNextImageKhr);
//    PFN_vkCmdBeginRenderPass vkCmdBeginRenderPass = LOAD_HARD(vkCmdBeginRenderPass);
//    PFN_vkCmdBindPipeline vkCmdBindPipeline = LOAD_HARD(vkCmdBindPipeline);
//    PFN_vkCmdEndRenderPass vkCmdEndRenderPass = LOAD_HARD(vkCmdEndRenderPass);
//    PFN_vkCmdDraw vkCmdDraw = LOAD_HARD(vkCmdDraw);
//    PFN_vkCmdBindVertexBuffers vkCmdBindVertexBuffers = LOAD_HARD(vkCmdBindVertexBuffers);
//    PFN_vkMapMemory vkMapMemory = LOAD_HARD(vkMapMemory);
//    PFN_vkUnmapMemory vkUnmapMemory = LOAD_HARD(vkUnmapMemory);
//    PFN_vkBindBufferMemory vkBindBufferMemory = LOAD_HARD(vkBindBufferMemory);
//    PFN_vkCreateFramebuffer vkCreateFramebuffer = LOAD_HARD(vkCreateFramebuffer);



    void initializedAll() {

        logRun(" initialize oz 1 ");
        Load(vkEnumerateInstanceVersion, "vkEnumerateInstanceVersion");
        logRun(" initialize oz 2 ");
        Load(vkEnumerateInstanceExtensionProperties, "vkEnumerateInstanceExtensionProperties");
        logRun(" initiailize oz 3 ");

        VkResult res;
        uint32_t versionVulkan = 0;
        uint32_t currentVersionVulkan;
        res = vkEnumerateInstanceVersion(&versionVulkan);

        uint16_t lMajor = VK_VERSION_MAJOR(versionVulkan);
        uint16_t lMijor = VK_VERSION_MINOR(versionVulkan);
        logRun(" My vulkan version's == %d.%d", lMajor, lMijor);

//        Load(vkEnumerateInstanceLayerProperties, "vkEnumerateInstanceLayerProperties");
//        Load(vkCreateInstance, "vkCreateInstance");
//        Load(vkDestroyInstance, "vkDestroyInstance");
//        Load(vkDestroyDevice, "vkDestroyDevice");
//        Load(vkDestroySurfaceKHR, "vkDestroySurfaceKHR");
//        Load(vkDestroySwapchainKHR, "vkDestroySwapchainKHR");
//        Load(vkCreateDevice, "vkCreateDevice");
//        Load(vkCreateSwapchainKHR, "vkCreateSwapchainKHR");
//        Load(vkCreateImageView, "vkCreateImageView");
//        Load(vkCreateImage, "vkCreateImage");
//        Load(vkAllocateMemory, "vkAllocateMemory");
//        Load(vkBindImageMemory, "vkBindImageMemory");
//        Load(vkCreateCommandPool, "vkCreateCommandPool");
//        Load(vkAllocateCommandBuffers, "vkAllocateCommandBuffers");
//        Load(vkCreateSemaphore, "vkCreateSemaphore");
//        Load(vkCreateFence, "vkCreateFence");
//        Load(vkResetCommandBuffer, "vkResetCommandBuffer");
//        Load(vkBeginCommandBuffer, "vkBeginCommandBuffer");
//        Load(vkEndCommandBuffer, "vkEndCommandBuffer");
//        Load(vkQueueSubmit, "vkQueueSubmit");
//        Load(vkResetFences, "vkResetFences");
//        Load(vkWaitForFences, "vkWaitForFences");
//        Load(vkCmdPipelineBarrier, "vkCmdPipelineBarrier");
//        Load(vkFreeCommandBuffers, "vkFreeCommandBuffers");
//        Load(vkDestroyImageView, "vkDestroyImageView");
//        Load(vkDestroyImage, "vkDestroyImage");
//        Load(vkFreeMemory, "vkFreeMemory");
//        Load(vkDestroyCommandPool, "vkDestroyCommandPool");
//        Load(vkDestroySemaphore, "vkDestroySemaphore");
//        Load(vkDestroyFence, "vkDestroyFence");
//        Load(vkCreateRenderPass, "vkCreateRenderPass");
//        Load(vkCreateShaderModule, "vkCreateShaderModule");
//        Load(vkCreateGraphicsPipelines, "vkCreateGraphicsPipelines");
//        Load(vkCreatePipelineCache, "vkCreatePipelineCache");
//        Load(vkCreateBuffer, "vkCreateBuffer");
//        Load(vkGetBufferMemoryRequirements, "vkGetBufferMemoryRequirements");
//        Load(vkQueuePresentKHR, "vkQueuePresentKHR");
//      //  Load(vkAcquireNextImageKhr, "vkAcquireNextImageKhr");
//        Load(vkCmdBeginRenderPass, "vkCmdBeginRenderPass");
//        Load(vkCmdBindPipeline, "vkCmdBindPipeline");
//        Load(vkCmdEndRenderPass, "vkCmdEndRenderPass");
//        Load(vkCmdDraw, "vkCmdDraw");
//        Load(vkCmdBindVertexBuffers, "vkCmdBindVertexBuffers");
//        Load(vkMapMemory, "vkMapMemory");
//        Load(vkUnmapMemory, "vkUnmapMemory");
//        Load(vkBindBufferMemory, "vkBindBufferMemory");
//        Load(vkCreateFramebuffer, "vkCreateFramebuffer");
//
//
//        // vkGetInstanceProcAddr
//        Load(vkDestroyPipelineCache, "vkDestroyPipelineCache");
//        Load(vkDestroyShaderModule, "vkDestroyShaderModule");
//        Load(vkGetInstanceProcAddr, "vkGetInstanceProcAddr");


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
      explicit LosMainVulkan();
      ~LosMainVulkan();

      static void LosApplicationCMD(struct android_app* app, int32_t cmd);
      static int32_t losInputWorkingHandle (struct android_app* app, AInputEvent* event);

      void looperMainVulkan();

      VkDebugReportCallbackEXT cb1;

    void PresentBBuffers();
    void SetNextBuf();

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
    Vertices mVerticesL;
    VkDescriptorSetLayout lDescriptor;
    VkPipelineLayout lPipelineLos;
    VkPipeline mPipe;
    VkRenderPass losRenderPass;
    VkFramebuffer*  losFrameBuff;
    VkShaderModule createShaderLos(const uint32_t* code, uint32_t size);
    //VkPipelineLayout lPipelineLosLayout;
    uint32_t swapchainCurrentIndex;

private:

    void inputWrapper(int32_t cmd);
    static void initializeMyVulkan();

    uint32_t LosWidth;
    uint32_t LosHeight;
    myVulkan vulkanA;

    //  CheckVulkan *check
    std::unique_ptr<CheckVulkan> check;

    void PreDestroyAll() noexcept;
    bool initialize_isOk = false;

};


//#endif //RENDERINGS_LOSMAINVULKAN_H
