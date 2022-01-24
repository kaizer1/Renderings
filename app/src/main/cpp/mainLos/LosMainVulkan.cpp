//
// Created by loskutnikov on 24.01.2022.
//

#include <assert.h>
#include "LosMainVulkan.h"


inline void cb(VkResult myResult ) noexcept {

    if(myResult == VK_SUCCESS){
        logRun(" vk_success is very all good ");
    }else{
        switch (myResult) {
            case VK_NOT_READY:
                logRun (  " vk not ready ! \n");
                break;

            case VK_INCOMPLETE:
                logRun (  " vk is not Incompete \n");
                break;

            case  VK_EVENT_SET:
                logRun (  " vk event set \n");
                break;

            case VK_EVENT_RESET:
                logRun (  " vk event reset \n");
                break;

                /*     case VK_INCOMPLETE:
                     logRun (  " vk incomplete \n";
                       break;*/

            case VK_ERROR_OUT_OF_HOST_MEMORY:
                logRun (  " VK_ERROR_OUT_OF_HOST_MEMORY  this error \n");
                break;


            case VK_ERROR_OUT_OF_DEVICE_MEMORY:
                logRun (  " VK_ERROR_OUT_OF_DEVICE_MEMORY error \n");
                break;


            case  VK_ERROR_INITIALIZATION_FAILED:
                logRun (  " VK_ERROR_INITIALIZATION_FAILED error \n");
                break;

            case VK_ERROR_DEVICE_LOST:
                logRun (  "VK_ERROR_DEVICE_LOST \n");
                break;

            case VK_ERROR_MEMORY_MAP_FAILED:
                logRun (  "VK_ERROR_MEMORY_MAP_FAILED \n");
                break;

            case VK_ERROR_LAYER_NOT_PRESENT:
                logRun (  " VK_ERROR_LAYER_NOT_PRESENT \n");
                break;

            case VK_ERROR_EXTENSION_NOT_PRESENT:
                logRun (  " VK_ERROR_EXTENSION_NOT_PRESENT \n");
                break;


            case VK_ERROR_FEATURE_NOT_PRESENT:
                logRun (  "VK_ERROR_FEATURE_NOT_PRESENT \n");
                break;


            case VK_ERROR_INCOMPATIBLE_DRIVER:
                logRun ( "VK_ERROR_INCOMPATIBLE_DRIVER \n");
                break;

            case VK_ERROR_TOO_MANY_OBJECTS:
                logRun (  "VK_ERROR_TOO_MANY_OBJECTS  \n");
                break;


            case VK_ERROR_FORMAT_NOT_SUPPORTED:
                logRun (  " VK_ERROR_FORMAT_NOT_SUPPORTED error \n");
                break;

            case VK_ERROR_FRAGMENTED_POOL:
                logRun (  "  VK_ERROR_FRAGMENTED_POOL \n");
                break;

//             case VK_ERROR_UNKNOWN:
//                 logRun (  "VK_ERROR_UNKNOWN \n");
//                 break;



            case VK_ERROR_OUT_OF_POOL_MEMORY:
                logRun (  "VK_ERROR_OUT_OF_POOL_MEMORY \n");
                break;


            case VK_ERROR_INVALID_EXTERNAL_HANDLE:
                logRun (  "VK_ERROR_INVALID_EXTERNAL_HANDLE \n");
                break;

//             case VK_ERROR_FRAGMENTATION:
//                 logRun (  " eror m y VK_ERROR_FRAGMENTATION \n");
//                 break;


//             case VK_ERROR_INVALID_OPAQUE_CAPTURE_ADDRESS:
//                 logRun (  "VK_ERROR_INVALID_OPAQUE_CAPTURE_ADDRESS \n");
//                 break;


            case VK_ERROR_SURFACE_LOST_KHR:
                logRun (  "VK_ERROR_SURFACE_LOST_KHR \n");
                break;



            case VK_ERROR_NATIVE_WINDOW_IN_USE_KHR:
                logRun (  "VK_ERROR_NATIVE_WINDOW_IN_USE_KHR \n");
                break;


            case VK_SUBOPTIMAL_KHR:
                logRun (  "VK_SUBOPTIMAL_KHR \n");
                break;



            case VK_ERROR_OUT_OF_DATE_KHR:
                logRun (  "VK_ERROR_OUT_OF_DATE_KHR \n");
                break;


            case VK_ERROR_INCOMPATIBLE_DISPLAY_KHR:
                logRun (  "VK_ERROR_INCOMPATIBLE_DISPLAY_KHR \n");
                break;
                // VK_ERROR_OUT_OF_POOL_MEMORY = -1000069000,
                // VK_ERROR_INVALID_EXTERNAL_HANDLE = -1000072003,
                // VK_ERROR_FRAGMENTATION = -1000161000,

            case VK_ERROR_VALIDATION_FAILED_EXT:
                logRun (  "VK_ERROR_VALIDATION_FAILED_EXT \n");
                break;


            case VK_ERROR_INVALID_SHADER_NV:
                logRun (  "VK_ERROR_INVALID_SHADER_NV \n");
                break;


            case VK_ERROR_INVALID_DRM_FORMAT_MODIFIER_PLANE_LAYOUT_EXT:
                logRun (  "VK_ERROR_INVALID_DRM_FORMAT_MODIFIER_PLANE_LAYOUT_EXT \n");
                break;


            case VK_ERROR_NOT_PERMITTED_EXT:
                logRun (  "VK_ERROR_NOT_PERMITTED_EXT \n");
                break;



            case VK_ERROR_FULL_SCREEN_EXCLUSIVE_MODE_LOST_EXT:
                logRun (  "VK_ERROR_FULL_SCREEN_EXCLUSIVE_MODE_LOST_EXT \n");
                break;



//             case VK_THREAD_IDLE_KHR:
//                 logRun (  "VK_THREAD_IDLE_KHR \n");
//                 break;


//             case VK_THREAD_DONE_KHR:
//                 logRun (  "VK_THREAD_DONE_KHR \n");
//                 break;
//
//
//
//             case VK_OPERATION_DEFERRED_KHR:
//                 logRun (  "VK_OPERATION_DEFERRED_KHR \n");
//                 break;
//
//
//
//             case VK_OPERATION_NOT_DEFERRED_KHR:
//                 logRun (  "VK_OPERATION_NOT_DEFERRED_KHR \n");
//                 break;
//
//
//             case VK_PIPELINE_COMPILE_REQUIRED_EXT:
//                 logRun (  "VK_PIPELINE_COMPILE_REQUIRED_EXT");
//                 break;

            default:
                logRun (  " not found error's \n");
        }
    }


}



std::string_view to_string( VkResult r ){
    switch( r ){
        case VK_SUCCESS: return "VK_SUCCESS";
        case VK_NOT_READY: return "VK_NOT_READY";
        case VK_TIMEOUT: return "VK_TIMEOUT";
        case VK_EVENT_SET: return "VK_EVENT_SET";
        case VK_EVENT_RESET: return "VK_EVENT_RESET";
        case VK_INCOMPLETE: return "VK_INCOMPLETE";
        case VK_ERROR_OUT_OF_HOST_MEMORY: return "VK_ERROR_OUT_OF_HOST_MEMORY";
        case VK_ERROR_OUT_OF_DEVICE_MEMORY: return "VK_ERROR_OUT_OF_DEVICE_MEMORY";
        case VK_ERROR_INITIALIZATION_FAILED: return "VK_ERROR_INITIALIZATION_FAILED";
        case VK_ERROR_DEVICE_LOST: return "VK_ERROR_DEVICE_LOST";
        case VK_ERROR_MEMORY_MAP_FAILED: return "VK_ERROR_MEMORY_MAP_FAILED";
        case VK_ERROR_LAYER_NOT_PRESENT: return "VK_ERROR_LAYER_NOT_PRESENT";
        case VK_ERROR_EXTENSION_NOT_PRESENT: return "VK_ERROR_EXTENSION_NOT_PRESENT";
        case VK_ERROR_FEATURE_NOT_PRESENT: return "VK_ERROR_FEATURE_NOT_PRESENT";
        case VK_ERROR_INCOMPATIBLE_DRIVER: return "VK_ERROR_INCOMPATIBLE_DRIVER";
        case VK_ERROR_TOO_MANY_OBJECTS: return "VK_ERROR_TOO_MANY_OBJECTS";
        case VK_ERROR_FORMAT_NOT_SUPPORTED: return "VK_ERROR_FORMAT_NOT_SUPPORTED";
        case VK_ERROR_SURFACE_LOST_KHR: return "VK_ERROR_SURFACE_LOST_KHR";
        case VK_ERROR_NATIVE_WINDOW_IN_USE_KHR: return "VK_ERROR_NATIVE_WINDOW_IN_USE_KHR";
        case VK_SUBOPTIMAL_KHR: return "VK_SUBOPTIMAL_KHR";
        case VK_ERROR_OUT_OF_DATE_KHR: return "VK_ERROR_OUT_OF_DATE_KHR";
        case VK_ERROR_INCOMPATIBLE_DISPLAY_KHR: return "VK_ERROR_INCOMPATIBLE_DISPLAY_KHR";
        case VK_ERROR_VALIDATION_FAILED_EXT: return "VK_ERROR_VALIDATION_FAILED_EXT";
        case VK_ERROR_INVALID_SHADER_NV: return "VK_ERROR_INVALID_SHADER_NV";
        default: return "unrecognized VkResult code";
    }
}


std::string_view to_string( VkDebugReportObjectTypeEXT o ){
    switch( o ){
        case VK_DEBUG_REPORT_OBJECT_TYPE_UNKNOWN_EXT: return "unknown";
        case VK_DEBUG_REPORT_OBJECT_TYPE_INSTANCE_EXT: return "Instance";
        case VK_DEBUG_REPORT_OBJECT_TYPE_PHYSICAL_DEVICE_EXT: return "PhysicalDevice";
        case VK_DEBUG_REPORT_OBJECT_TYPE_DEVICE_EXT: return "Device";
        case VK_DEBUG_REPORT_OBJECT_TYPE_QUEUE_EXT: return "Queue";
        case VK_DEBUG_REPORT_OBJECT_TYPE_SEMAPHORE_EXT: return "Semaphore";
        case VK_DEBUG_REPORT_OBJECT_TYPE_COMMAND_BUFFER_EXT: return "CommandBuffer";
        case VK_DEBUG_REPORT_OBJECT_TYPE_FENCE_EXT: return "Fence";
        case VK_DEBUG_REPORT_OBJECT_TYPE_DEVICE_MEMORY_EXT: return "DeviceMemory";
        case VK_DEBUG_REPORT_OBJECT_TYPE_BUFFER_EXT: return "Buffer";
        case VK_DEBUG_REPORT_OBJECT_TYPE_IMAGE_EXT: return "Image";
        case VK_DEBUG_REPORT_OBJECT_TYPE_EVENT_EXT: return "Event";
        case VK_DEBUG_REPORT_OBJECT_TYPE_QUERY_POOL_EXT: return "QueryPool";
        case VK_DEBUG_REPORT_OBJECT_TYPE_BUFFER_VIEW_EXT: return "BufferView";
        case VK_DEBUG_REPORT_OBJECT_TYPE_IMAGE_VIEW_EXT: return "ImageView";
        case VK_DEBUG_REPORT_OBJECT_TYPE_SHADER_MODULE_EXT: return "ShaderModule";
        case VK_DEBUG_REPORT_OBJECT_TYPE_PIPELINE_CACHE_EXT: return "PipelineCache";
        case VK_DEBUG_REPORT_OBJECT_TYPE_PIPELINE_LAYOUT_EXT: return "PipelineLayout";
        case VK_DEBUG_REPORT_OBJECT_TYPE_RENDER_PASS_EXT: return "RenderPass";
        case VK_DEBUG_REPORT_OBJECT_TYPE_PIPELINE_EXT: return "Pipeline";
        case VK_DEBUG_REPORT_OBJECT_TYPE_DESCRIPTOR_SET_LAYOUT_EXT: return "DescriptorSetLayout";
        case VK_DEBUG_REPORT_OBJECT_TYPE_SAMPLER_EXT: return "Sampler";
        case VK_DEBUG_REPORT_OBJECT_TYPE_DESCRIPTOR_POOL_EXT: return "DescriptorPool";
        case VK_DEBUG_REPORT_OBJECT_TYPE_DESCRIPTOR_SET_EXT: return "DescriptorSet";
        case VK_DEBUG_REPORT_OBJECT_TYPE_FRAMEBUFFER_EXT: return "Framebuffer";
        case VK_DEBUG_REPORT_OBJECT_TYPE_COMMAND_POOL_EXT: return "Command pool";
        case VK_DEBUG_REPORT_OBJECT_TYPE_SURFACE_KHR_EXT: return "SurfaceKHR";
        case VK_DEBUG_REPORT_OBJECT_TYPE_SWAPCHAIN_KHR_EXT: return "SwapchainKHR";
        case VK_DEBUG_REPORT_OBJECT_TYPE_DEBUG_REPORT_EXT: return "DebugReport";
        default: return "unrecognized";
    }
}


VKAPI_ATTR VkBool32 VKAPI_CALL genericDebugCallback(
        VkDebugReportFlagsEXT msgFlags,
        VkDebugReportObjectTypeEXT objType,
        uint64_t srcObject,
        size_t /*location*/,
        int32_t msgCode,
        const char* pLayerPrefix,
        const char* pMsg,
        void* /*pUserData*/
);


VKAPI_ATTR VkBool32 VKAPI_CALL genericDebugCallback(
        VkDebugReportFlagsEXT msgFlags,    // was VkDebugReportFlagsEXT
        VkDebugReportObjectTypeEXT objType,
        uint64_t srcObject,
        size_t /*location*/,
        int32_t msgCode,
        const char* pLayerPrefix,
        const char* pMsg,
        void* /*pUserData*/
){
    // just print everything
    logRun(" ours Debugging messages android  %s \n", pMsg);


    std::string report = std::string(to_string( objType )) + ", " + pLayerPrefix + ", " + pMsg;

    switch( msgFlags ){
        case VK_DEBUG_REPORT_INFORMATION_BIT_EXT:
            logRun("Info: %s \n",  report.c_str() );
            break;

        case VK_DEBUG_REPORT_WARNING_BIT_EXT:
            logRun("!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!\n");
            logRun("WARNING: %s \n", report.c_str());
            logRun ( "!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!\n");
            break;

        case VK_DEBUG_REPORT_PERFORMANCE_WARNING_BIT_EXT:
            logRun( "!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!\n");
            logRun("PERFORMANCE: %s \n", report.c_str() );
            logRun("!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!\n");
            break;

        case VK_DEBUG_REPORT_ERROR_BIT_EXT:
            logRun( "!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!\n");
            logRun("ERROR: %s \n ", report.c_str());
            logRun("!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!\n");
            break;

        case VK_DEBUG_REPORT_DEBUG_BIT_EXT:
            report += "Debug: ";
            break;
    }





    return VK_FALSE;
}



LosMainVulkan::LosMainVulkan() {

    mainAp->userData = this;
    mainAp->onAppCmd = LosApplicationCMD;
    mainAp->onInputEvent = losInputWorkingHandle;



}

void LosMainVulkan::LosApplicationCMD(struct android_app *app, int cmd) {

    auto* losMain = (LosMainVulkan*)app->userData;

    if(!losMain)
        logRun(" fucking CMD  ! \n");

    losMain->inputWrapper(cmd);

}


void LosMainVulkan::inputWrapper(int32_t cmd)
{


    logRun(" in Los CMD ! \n");

    switch (cmd) {
        case APP_CMD_SAVE_STATE:
            logRun("APP_CMD_SAVE_STATE \n");
           // mainAp->savedState = malloc(sizeof(struct saved_state));
           // *((struct saved_state*)mainAp->savedState) = losStateCos;
           // mainAp->savedStateSize = sizeof(struct saved_state);
            break;

        case APP_CMD_INIT_WINDOW:
            logRun("APP_CMD_INIT_WINDOW \n");
            //has_focus_= true;
            //StartFPSThrottle();
            initializeMyVulkan();

            // The window is being shown, get it ready.
            // if (engine->app->window != NULL) {
            //     engine_init_display(engine);
            //     engine_draw_frame(engine);
            // }
            break;
        case APP_CMD_TERM_WINDOW:
            logRun("APP_CMD_TERM_WINDOW \n");
            //has_focus_ = false;
            // renderWork3->~RenderExampleGo();
            // renderWork3->~PreRenderCalss();
            // The window is being hidden or closed, clean it up.
            // engine_term_display(engine);
            //~LosMainApp();

            break;
        case APP_CMD_GAINED_FOCUS:
            logRun("APP_CMD_GAINED_FOCUS \n");
            // When our app gains focus, we start monitoring the accelerometer.
            //if (engine->accelerometerSensor != NULL) {
//                 ASensorEventQueue_enableSensor(sensorEventQueue,
//                                                accelerometerSensor);
//                 // We'd like to get 60 events per second (in us).
//                 ASensorEventQueue_setEventRate(sensorEventQueue,
//                                                accelerometerSensor,
            //  (1000L/60)*1000);

            break;

        case APP_CMD_LOST_FOCUS:
            logRun("APP_CMD_LOST_FOCUS \n");
            // When our app loses focus, we stop monitoring the accelerometer.
            // This is to avoid consuming battery while not being used.
           // ASensorEventQueue_disableSensor(this->sensorEventQueue,
                                   //         this->accelerometerSensor);
           // has_focus_ = true;
           // UpdateScreen();

            break;

        case APP_CMD_INPUT_CHANGED:
            logRun("APP_CMD_INPUT_CHANGED \n");

            break;


        case APP_CMD_WINDOW_RESIZED:
            logRun("APP_CMD_WINDOW_RESIZED \n");

            break;


        case APP_CMD_WINDOW_REDRAW_NEEDED:
            logRun("APP_CMD_WINDOW_REDRAW_NEEDED \n");

            break;


        case APP_CMD_CONTENT_RECT_CHANGED:
            logRun("APP_CMD_CONTENT_RECT_CHANGED \n");

            break;


        case APP_CMD_CONFIG_CHANGED:
            logRun("APP_CMD_CONFIG_CHANGED \n");

            break;


        case APP_CMD_LOW_MEMORY:
            logRun("APP_CMD_LOW_MEMORY \n");


            break;


        case APP_CMD_START:
            logRun("APP_CMD_START \n");

            break;


        case APP_CMD_RESUME:
            logRun("APP_CMD_RESUME \n");

            break;


        case APP_CMD_PAUSE:
            logRun("APP_CMD_PAUSE \n");

            break;



        case APP_CMD_STOP:
            logRun("APP_CMD_STOP \n");

            break;


        case APP_CMD_DESTROY:
            logRun("APP_CMD_DESTROY \n");
            //  renderWork3->~RenderExampleGo();
            // renderWork3->~PreRenderCalss();
            break;


//            case LOS_APP_CMD_USER:
//                loginfo("LOS_APP_CMD_USER \n");
//
//            break;


        default:
            logRun(" case default ! \n");
            break;

    }
}



int32_t LosMainVulkan::losInputWorkingHandle (struct android_app* app, AInputEvent* event) {


   // auto *losMain = (LosMainApp *) app->userData;


    //losMain->inputData(event);
    int32_t aReturn = 1;
    return aReturn;
}



void LosMainVulkan::initializeMyVulkan(){


    myVulkan vulkanA = myVulkan();
    bool debugUtilsExists = false;
    bool debugReport = false;
    bool surface_capa2 = false;
    bool phDeviceProperty2 = false;


    // ANativeWindow* lef =  state->window;

    //   lef->setFra
    //   lef->setFra

//       if(state->pendingWindow == nullptr){
//           logRun(" error s \n");
//       }
//
//     logRun(" my width screen == %d \n ", ANativeWindow_getWidth(state->pendingWindow));



  // getCPU count



    CheckVulkan *check = new CheckVulkan();
    check->initializedAll();

    VkResult res;
    uint32_t versionVulkan = 0;
    uint32_t currentVersionVulkan;
    res = check->vkEnumerateInstanceVersion(&versionVulkan);

    if (res != VK_SUCCESS) {
        logRun(" not loaded Vulkan is ");
    } else {
        logRun(" loadede Vulkan's !! ");
        uint16_t lMajor = VK_VERSION_MAJOR(versionVulkan);
        uint16_t lMijor = VK_VERSION_MINOR(versionVulkan);
        logRun(" My vulkan version's == %d.%d", lMajor, lMijor);
        if (lMijor == 2) {
            currentVersionVulkan = VK_VERSION_1_1;
        } else if (lMijor == 1) {
            currentVersionVulkan = VK_VERSION_1_1;
        } else {
            currentVersionVulkan = VK_VERSION_1_0;
        }
    }


//          auto opengl_info = {GL_VENDOR, GL_RENDERER, GL_VERSION, GL_EXTENSIONS};
//    for (auto name : opengl_info) {
//        auto info = glGetString(name);
//        logRun("OpenGL Info: %s", info);
//    }
    //

    // vkEnumerateInstanceExtensionProperties

    uint32_t instancExtensCount = 0;
    res = check->vkEnumerateInstanceExtensionProperties(nullptr, &instancExtensCount, nullptr);
    VkExtensionProperties *instaProperty = new VkExtensionProperties[instancExtensCount];
    res = check->vkEnumerateInstanceExtensionProperties(nullptr, &instancExtensCount,
                                                        instaProperty);

    if (res != VK_SUCCESS) {

        logRun(" error this 01 ");
    }

    std::vector<const char *> extensionForAdd;
    const char* myExtension2[100];
    int countExtens = 0;

    for (auto i = 0; i < instancExtensCount; i++) {
        logRun(" my extension names == %s \n", instaProperty[i].extensionName);
        //  extensionForAdd.push_back(instaProperty[i].extensionName);

        if (strcmp(instaProperty[i].extensionName, VK_KHR_SURFACE_EXTENSION_NAME) == 0) {
            logRun(" Exists VK_KHR_SURFACE_EXTENSION_NAME %s  \n", VK_KHR_SURFACE_EXTENSION_NAME);
            myExtension2[countExtens++] = VK_KHR_SURFACE_EXTENSION_NAME;
            debugUtilsExists = true;
        }


        if (strcmp(instaProperty[i].extensionName, "VK_EXT_debug_utils") == 0) {
            logRun(" Exists DEBUG_utils  \n");

            debugUtilsExists = true;
        }

        if (strcmp(instaProperty[i].extensionName, "VK_EXT_debug_report") == 0) {
            logRun(" Exists debug_report \n");
            myExtension2[countExtens++] = "VK_EXT_debug_report";
            debugReport = true;
        }

        // VK_KHR_get_surface_capabilities2
        if (strcmp(instaProperty[i].extensionName, "VK_KHR_get_surface_capabilities2") == 0) {
            logRun(" Exists Surface_capability_2 ! \n");
            myExtension2[countExtens++] = "VK_KHR_get_surface_capabilities2";
            surface_capa2 = true;
        }

        if(strcmp(instaProperty[i].extensionName, "VK_KHR_android_surface") == 0){
            logRun(" ok found VK_KHR_android_surface ! \n");
            myExtension2[countExtens++] = VK_KHR_ANDROID_SURFACE_EXTENSION_NAME;
        }

        if (strcmp(instaProperty[i].extensionName, "VK_KHR_get_physical_device_properties2") == 0) {
            logRun(" Exists Physical Device Property2 \n");
            phDeviceProperty2 = true;
        }
    }


    VkApplicationInfo applicationInfo = {};
    applicationInfo.sType = VK_STRUCTURE_TYPE_APPLICATION_INFO;
    applicationInfo.pNext = nullptr;
    applicationInfo.pApplicationName = "LosRenderings";
    applicationInfo.applicationVersion = 0;
    applicationInfo.pEngineName = "EngineRender";
    applicationInfo.engineVersion = 1;
    applicationInfo.apiVersion = currentVersionVulkan;


    // layers Vulkan a


    uint32_t numInstanceLayers = 0;
    check->vkEnumerateInstanceLayerProperties(&numInstanceLayers, nullptr);
    logRun(" number layers count's  == %d \n", numInstanceLayers);
    VkLayerProperties *layerProperties = (VkLayerProperties *) malloc(
            numInstanceLayers * sizeof(VkLayerProperties));
    check->vkEnumerateInstanceLayerProperties(&numInstanceLayers, layerProperties);

    std::vector<const char *> layName;
    layName.push_back("VK_LAYER_KHRONOS_validation");


    if (!debugUtilsExists) {
        logRun(" Debug is ok ! ");
        if (debugReport) {

        } else {
            logRun(" no debug ! \n");
        }
    }



    //tension names == VK_KHR_surfac

    // TODO: samsung s21+
    // VK_KHR_android_surface
    // VK_EXT_swapchain_colorspace
    // VK_KHR_get_surface_capabilities2
    // VK_EXT_debug_report
    // VK_KHR_device_group_creation
    // VK_KHR_external_fence_capabilities
    // VK_KHR_external_memory_capabilities
    // VK_KHR_external_semaphore_capabilities
    // VK_KHR_get_physical_device_properties2

    // TODO: Realme 6


    // TODO: Xiaomi 8 Lite
    // VK_KHR_surface
    // VK_KHR_android_surface
    // VK_EXT_swapchain_colorspace
    // VK_KHR_get_surface_capabilities2
    // VK_EXT_debug_report
    // VK_KHR_get_physical_device_properties2
    // VK_KHR_external_semaphore_capabilities
    // VK_KHR_external_memory_capabilities
    // VK_KHR_device_group_creation
    // VK_KHR_external_fence_capabilities

    VkInstanceCreateInfo instanceInfo = {};
    instanceInfo.sType = VK_STRUCTURE_TYPE_INSTANCE_CREATE_INFO;
    instanceInfo.pNext = nullptr;
    instanceInfo.pApplicationInfo = &applicationInfo;
    instanceInfo.enabledLayerCount = 1;
    instanceInfo.ppEnabledLayerNames = layName.data();

    //    const char* myExtension2[10];
    //    int countExtens = 0;


    // logRun(" my extens number == %d \n", instancExtensCount);

    //logRun(" size == $d \n",  sizeof(*myExtension2));
    std::string myStringExten = std::string(*myExtension2);
    logRun(" my string ==%s  \n", myStringExten.c_str());
    myStringExten += std::string(VK_KHR_ANDROID_SURFACE_EXTENSION_NAME);
    logRun(" my string ==%s  \n", myStringExten.c_str());
    logRun(" extens2 my ==%d,  %s,  ", countExtens, *myExtension2);

    // VK_EXT_debug_report
    const char*  extenslos[6];// = "VK_EXT_debug_report;VK_KHR_android_surface;VK_KHR_surface";
    extenslos[0] = "VK_EXT_debug_report";
    extenslos[1] = "VK_KHR_android_surface";
    extenslos[2] = "VK_KHR_surface";
    extenslos[3] = "VK_KHR_get_physical_device_properties2";
    extenslos[4] = "VK_KHR_get_surface_capabilities2";
    extenslos[5] = "VK_KHR_external_memory_capabilities";


    logRun(" my extens == %s \n", extenslos[1]);

    instanceInfo.enabledExtensionCount = 6;// countExtens;//  instancExtensCount;
    instanceInfo.ppEnabledExtensionNames = extenslos; //myExtension2;  //extensionForAdd.data();
    logRun(" sdf  wei8 8 \n");
    res = check->vkCreateInstance(&instanceInfo, nullptr, &vulkanA.mainInstance);
    logRun(" sdf  wei8 8 final  \n");
    // if debug exists
    cb(res);


    VkDebugReportCallbackEXT cb1;
    // VK_STRUCTURE_TYPE_DEBUG_REPORT_CALLBACK_CREATE_INFO_EXT
    VkDebugReportCallbackCreateInfoEXT callback1 = {
            VK_STRUCTURE_TYPE_DEBUG_REPORT_CREATE_INFO_EXT,
            nullptr,
            VK_DEBUG_REPORT_ERROR_BIT_EXT | VK_DEBUG_REPORT_WARNING_BIT_EXT,
            genericDebugCallback,
            nullptr
    };


    // std::experimental::pmr::polymorphic_allocator sdf(); // ok this



    // PFN_vkCreateDebugReportCallbackEXT FpvkCreateDebugReportCallbackEXT = check->vkCreateDebugReportCallbackEXT_loader;



    // PFN_vkCreateDebugReportCallbackEXT FpvkCreateDebugReportCallbackEXT = &vkCreateDebugReportCallbackEXT_loader;

    logRun("pre loading vkCreateDebugReportCallbackEXT \n");
    //    res =check->vkCreateDebugReportCallbackEXT(vulkanA.mainInstance,  &callback1, nullptr, &cb1);


    PFN_vkVoidFunction temp_fp = check->vkGetInstanceProcAddr(vulkanA.mainInstance,
                                                              "vkCreateDebugReportCallbackEXT");
    if (!temp_fp) throw "Failed to load vkCreateDebugReportCallbackEXT";

    PFN_vkCreateDebugReportCallbackEXT FpvkCreateDebugReportCallbackEXT = reinterpret_cast<PFN_vkCreateDebugReportCallbackEXT>( temp_fp );


    PFN_vkVoidFunction temp_fp2 = check->vkGetInstanceProcAddr(vulkanA.mainInstance,
                                                               "vkDestroyDebugReportCallbackEXT");
    if (!temp_fp2) throw "Failed to load vkCreateDebugReportCallbackEXT";

    PFN_vkDestroyDebugReportCallbackEXT FpvkDestroyDebugReportCallbackEXT = reinterpret_cast<PFN_vkDestroyDebugReportCallbackEXT>( temp_fp2 );
    FpvkCreateDebugReportCallbackEXT(vulkanA.mainInstance, &callback1, nullptr, &cb1);


    PFN_vkVoidFunction temp_fp2Enum = check->vkGetInstanceProcAddr(vulkanA.mainInstance,
                                                                   "vkEnumeratePhysicalDevices");
    if (!temp_fp2Enum) throw "Failed to load vkCreateDebugReportCallbackEXT";

    uint32_t ip; // = memAllocInt(1);
    PFN_vkEnumeratePhysicalDevices vkEnumeratePhysicalDevices1 = reinterpret_cast<PFN_vkEnumeratePhysicalDevices>( temp_fp2Enum );

    res = vkEnumeratePhysicalDevices1(vulkanA.mainInstance, &ip, nullptr);
    logRun(" my pysical devices numbres == %d \n", ip);
    VkPhysicalDevice *mpPhysicalDevices = nullptr;
    mpPhysicalDevices = new VkPhysicalDevice[ip];
    res = vkEnumeratePhysicalDevices1(vulkanA.mainInstance, &ip, mpPhysicalDevices);

    auto myPhysicalDevice = mpPhysicalDevices[0];

    PFN_vkVoidFunction temp_fp2DevProperties = check->vkGetInstanceProcAddr(vulkanA.mainInstance,
                                                                            "vkGetPhysicalDeviceProperties");
    if (!temp_fp2DevProperties) throw "Failed to load vkGetPhysicalDeviceProperties";

    PFN_vkGetPhysicalDeviceProperties vkGetPhysicalDeviceProperties1 = reinterpret_cast<PFN_vkGetPhysicalDeviceProperties>( temp_fp2DevProperties );
    // get Data to enumerate physics devices
    VkPhysicalDeviceProperties mPhysicalDevicesProperties;
    vkGetPhysicalDeviceProperties1(myPhysicalDevice, &mPhysicalDevicesProperties);
    logRun(" my physical device prorerties ID == %u \n", mPhysicalDevicesProperties.deviceID);
    logRun(" my physical device prorerties name == %s \n", mPhysicalDevicesProperties.deviceName);


    PFN_vkVoidFunction temp_fp2DevDmProper = check->vkGetInstanceProcAddr(vulkanA.mainInstance,
                                                                          "vkGetPhysicalDeviceMemoryProperties");
    if (!temp_fp2DevDmProper) throw "Failed to load vkGetPhysicalDeviceMemoryProperties";

    PFN_vkGetPhysicalDeviceMemoryProperties vkGetPhysicalDeviceMemoryProperties1 = reinterpret_cast<PFN_vkGetPhysicalDeviceMemoryProperties>( temp_fp2DevDmProper );

    VkPhysicalDeviceMemoryProperties myPhysicalDeviceMemoryPropertises2;
    vkGetPhysicalDeviceMemoryProperties1(myPhysicalDevice, &myPhysicalDeviceMemoryPropertises2);


    // vkEnumerateDeviceExtensionProperties ???
    PFN_vkVoidFunction temp_fp2DevExtProeper = check->vkGetInstanceProcAddr(vulkanA.mainInstance, "vkEnumerateDeviceExtensionProperties");
    if (!temp_fp2DevExtProeper) throw "Failed to load vkGetPhysicalDeviceMemoryProperties";

    PFN_vkEnumerateDeviceExtensionProperties vkEnumerateDeviceExtensionProperties1 = reinterpret_cast<PFN_vkEnumerateDeviceExtensionProperties>( temp_fp2DevExtProeper );

    uint32_t deviceExten = 0;
    VkExtensionProperties *deviceExtenPo = nullptr;
    res = vkEnumerateDeviceExtensionProperties1(myPhysicalDevice, nullptr, &deviceExten, nullptr);
    logRun(" my nubmer exten == %d \n", deviceExten);

    VkBool32 swapchainExtFound = 0;
    VkExtensionProperties *deveExten1 = new VkExtensionProperties[deviceExten];
    res = vkEnumerateDeviceExtensionProperties1(myPhysicalDevice, nullptr, &deviceExten,
                                                deveExten1);
    cb(res);

    // uint32_t enabledExtensionCount = 0;
    // const char *extensionNames[16] = {0};
    /*   for (uint32_t i = 0; i < deviceExten; i++)
       {
        logRun(" my extension this == %s \n", deveExten1[i].extensionName);
       }*/




    // init surface
    VkAndroidSurfaceCreateInfoKHR surfaceCreateInfo = {};
    surfaceCreateInfo.sType = VK_STRUCTURE_TYPE_ANDROID_SURFACE_CREATE_INFO_KHR;
    surfaceCreateInfo.pNext = nullptr;
    surfaceCreateInfo.flags = 0;
    surfaceCreateInfo.window = mainAp->window;


    logRun(" sdf   pre this !! ");
    PFN_vkVoidFunction temp_fp2DeCreaWindo = check->vkGetInstanceProcAddr( vulkanA.mainInstance, "vkCreateAndroidSurfaceKHR" );
    if( !temp_fp2DeCreaWindo ) throw  "Failed to load vkCreateAndroidSurfaceKHR";

    PFN_vkCreateAndroidSurfaceKHR vkCreateAndroidSurfaceKHR1 = reinterpret_cast<PFN_vkCreateAndroidSurfaceKHR>( temp_fp2DeCreaWindo );

    VkSurfaceKHR mSurfaceLos;
    VkSurfaceFormatKHR mSurfaceFormat;
    logRun(" sdf   pre this 22!! ");
    // check->activateAndroid();

    if (vulkanA.mainInstance == VK_NULL_HANDLE )
    {
        logRun(" Empty fucks instance \n\n");
        //return VK_NULL_HANDLE;
    }

    if (!mainAp->window){

        logRun("Empty fucks windows \n\n");
    }


    // res = check->vkCreateAndroidSurfaceKHRNew(vulkanA.mainInstance, &surfaceCreateInfo, nullptr, &mSurfaceLos);
    res = vkCreateAndroidSurfaceKHR1(vulkanA.mainInstance, &surfaceCreateInfo, nullptr, &mSurfaceLos);
    logRun(" sdf   pre this 23!! ");
    cb(res);

    // Before we create our main Vulkan device, we must ensure our physical device
    // has queue families which can perform the actions we require. For this, we request
    // the number of queue families, and their properties.


    PFN_vkVoidFunction tempDeviceQueuFamilyProe = check->vkGetInstanceProcAddr( vulkanA.mainInstance, "vkGetPhysicalDeviceQueueFamilyProperties" );
    if( !tempDeviceQueuFamilyProe ) throw  "Failed to load vkGetPhysicalDeviceQueueFamilyProperties";

    PFN_vkGetPhysicalDeviceQueueFamilyProperties vkGetPhysicalDeviceQueueFamilyProperties1 = reinterpret_cast<PFN_vkGetPhysicalDeviceQueueFamilyProperties>( tempDeviceQueuFamilyProe );


    PFN_vkVoidFunction deviSurSuppoe = check->vkGetInstanceProcAddr( vulkanA.mainInstance, "vkGetPhysicalDeviceSurfaceSupportKHR" );
    if( !deviSurSuppoe ) throw  "Failed to load vkGetPhysicalDeviceSurfaceSupportKHR";

    PFN_vkGetPhysicalDeviceSurfaceSupportKHR vkGetPhysicalDeviceSurfaceSupportKHR1 = reinterpret_cast<PFN_vkGetPhysicalDeviceSurfaceSupportKHR>( deviSurSuppoe );



      uint32_t queueFamilyCount = 0;
    vkGetPhysicalDeviceQueueFamilyProperties1(myPhysicalDevice, &queueFamilyCount, nullptr);
    logRun(" my queue properties count == %d \n", queueFamilyCount);
    VkQueueFamilyProperties* queuePropeties = new VkQueueFamilyProperties[queueFamilyCount];
    vkGetPhysicalDeviceQueueFamilyProperties1(myPhysicalDevice, &queueFamilyCount, queuePropeties);
     assert(queueFamilyCount >= 1);

       VkBool32* supportPresent = new VkBool32[queueFamilyCount];
       for (uint32_t i = 0; i < queueFamilyCount; i++){
           vkGetPhysicalDeviceSurfaceSupportKHR1(myPhysicalDevice, i, mSurfaceLos, &supportPresent[i]);
       }

       // check graphics bit
      uint32_t  queueIndex = UINT32_MAX;
       for (uint32_t i = 0; i < queueFamilyCount; i++){
           if((queuePropeties[i].queueFlags & VK_QUEUE_GRAPHICS_BIT) != 0){
                if(supportPresent[i] == VK_TRUE){
                    queueIndex = i;
                     logRun(" my index this ! ok ");
                    break;
                }
           }
       }

        delete[] supportPresent;
        delete[] queuePropeties;

         if (queueIndex == UINT32_MAX){
              logRun(" Could not obtain a queue family for both graphics and p \n");
         }


         vulkanA.mLosQueueFIndex = queueIndex;

         float queuePriorities[1] = {1.0 };
         VkDeviceQueueCreateInfo  deviceQueueCreateInfo = {};
         deviceQueueCreateInfo.sType = VK_STRUCTURE_TYPE_DEVICE_QUEUE_CREATE_INFO;
         deviceQueueCreateInfo.pNext = nullptr;
         deviceQueueCreateInfo.queueFamilyIndex = vulkanA.mLosQueueFIndex;
         deviceQueueCreateInfo.queueCount = 1;
         deviceQueueCreateInfo.pQueuePriorities = queuePriorities;

         VkDeviceCreateInfo deviceCreateInfo = {};
    deviceCreateInfo.sType = VK_STRUCTURE_TYPE_DEVICE_CREATE_INFO;
    deviceCreateInfo.pNext = nullptr;
    deviceCreateInfo.queueCreateInfoCount = 1;
    deviceCreateInfo.pQueueCreateInfos = &deviceQueueCreateInfo;
    deviceCreateInfo.enabledLayerCount = 0;
    deviceCreateInfo.ppEnabledLayerNames = nullptr;

    //  VK_EXT_external_memory_dma_buf
    //   VK_EXT_image_drm_format_modifier
    //   VK_ANDROID_external_memory_android_hardware_buffer
    //   VK_KHR_swapchain
    // VK_KHR_variable_pointers
    //   VK_KHR_incremental_present
    //   VK_KHR_shared_presentable_image
    //   VK_GOOGLE_display_timing
    //   VK_KHR_16bit_storage

     const char* newExtenHonor[19];
    newExtenHonor[0] = "VK_EXT_external_memory_dma_buf";
    newExtenHonor[1] = "VK_EXT_image_drm_format_modifier";
    newExtenHonor[2] = "VK_ANDROID_external_memory_android_hardware_buffer";
    newExtenHonor[3] = "VK_KHR_swapchain";
    newExtenHonor[4] = "VK_KHR_variable_pointers";
    newExtenHonor[5] = "VK_KHR_incremental_present";
    newExtenHonor[6] = "VK_KHR_shared_presentable_image";
    newExtenHonor[7] = "VK_GOOGLE_display_timing";
    newExtenHonor[8] = "VK_KHR_16bit_storage";
    newExtenHonor[9] = "VK_KHR_external_memory_fd";
    newExtenHonor[10] = "VK_KHR_bind_memory2";
    newExtenHonor[11] = "VK_KHR_image_format_list";
    newExtenHonor[12] = "VK_KHR_sampler_ycbcr_conversion";

    newExtenHonor[13] = "VK_KHR_external_memory";
    newExtenHonor[14] = "VK_EXT_queue_family_foreign";
    newExtenHonor[15] = "VK_KHR_storage_buffer_storage_class";
    newExtenHonor[16] = "VK_KHR_external_memory";
    newExtenHonor[17] = "VK_KHR_maintenance1";
    newExtenHonor[18] = "VK_KHR_get_memory_requirements2";

    // VK_KHR_external_memory,
    // VK_EXT_queue_family_foreign
    // VK_KHR_storage_buffer_storage_class
    // VK_KHR_get_surface_capabilities2
    // VK_KHR_external_memory
    // VK_KHR_maintenance1,
    // VK_KHR_get_memory_requirements2

    deviceCreateInfo.enabledExtensionCount =  19;
    deviceCreateInfo.ppEnabledExtensionNames = newExtenHonor;


   // PFN_vkVoidFunction kCeDevies = check->vkGetInstanceProcAddr( vulkanA.mainInstance, "vkCreateDevice" );
   // if( !kCeDevies ) throw  "Failed to load vkCreateDevice";

   // PFN_vkCreateDevice vkCreateDevice1 = reinterpret_cast<PFN_vkCreateDevice>( kCeDevies );

    // create Device
    res = check->vkCreateDevice(myPhysicalDevice, &deviceCreateInfo, nullptr, &vulkanA.mDeviceLos);
     cb(res);



    PFN_vkVoidFunction getDeviQueu = check->vkGetInstanceProcAddr( vulkanA.mainInstance, "vkGetDeviceQueue" );
    if( !getDeviQueu ) throw  "Failed to load vkGetDeviceQueue";

    PFN_vkGetDeviceQueue vkGetDeviceQueue1 = reinterpret_cast<PFN_vkGetDeviceQueue>( getDeviQueu );
    vkGetDeviceQueue1(vulkanA.mDeviceLos, vulkanA.mLosQueueFIndex, 0, &vulkanA.mQueueLos);
         // check compute bit


    // vkGetPhysicalDeviceQueueFamilyProperties



    // and CreateDevice


    // initCommandbuffers



    // initSwapChain



    // initDepthBuffers


    // surface created


    // image created


     // destroy vkDevice, mSurfaceLos
     // mSurfaceLos





    check->vkDestroyDevice(vulkanA.mDeviceLos, nullptr);
    check->vkDestroySurfaceKHR(vulkanA.mainInstance, mSurfaceLos, nullptr);
   // vkDestroyInstance(vulkanA.mainInstance, nullptr);

    FpvkDestroyDebugReportCallbackEXT(vulkanA.mainInstance, cb1, nullptr);
    logRun("post loading vkCreateDebugReportCallbackEXT \n");



    cb(res);


#if(__ANDROID_API__ >= 30)

#else

#endif



    logRun(" pre Destroy instance \n");


    check->vkDestroyInstance(vulkanA.mainInstance, nullptr);
    vulkanA.mainInstance = VK_NULL_HANDLE;


}


 const void  LosMainVulkan::looperMainVulkan(){

    int32_t ident;
    int32_t events;
    struct android_poll_source *source;


    while (los_app_status_running(mainAp)) // was los_app_status_running(androidMainApp)
    {
        while ((ident = ALooper_pollAll(los_android_app_loop_wait(mainAp), nullptr, &events,
                                        (void **) &source)) >= 0)
        {
            //logRun("  looperMainApp 1  \n");
            if (source != nullptr) {
                source->process(mainAp, source);
            } else if (los_app_is_redraw(ident))
            {
                logRun(" redraw event \n");
            }


            if (!los_app_status_running(mainAp))
            {
                logRun(" ! los_app \n");
                break;
            }

        } // end's while !

        //UpdateScreen();
    }
}

LosMainVulkan::~LosMainVulkan() {

}