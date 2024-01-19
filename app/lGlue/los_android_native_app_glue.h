//--------------------------
// File : los_android_native_app_glue.h
// Email : nithce9@gmail.com 
// Creator : Sergei Loskutnikov
// ---------------------------
#pragma once

#include <poll.h>
#include <pthread.h>
#include <sched.h>

#include <android/configuration.h>
#include <android/looper.h>
#include <android/native_activity.h>

#ifdef __cplusplus
extern "C"{
#endif

struct android_app;

struct android_poll_source
{
	int32_t id;
	struct android_app* app;

	void (*process)(struct android_app* app, struct android_poll_source* source);
};


struct android_app
{
   
     void* userData;

     void (*onAppCmd) (struct android_app* app, int32_t cmd);

     int32_t (*onInputEvent)(struct android_app* app, AInputEvent* event);

     ANativeActivity* activity;
     AConfiguration* config;

     void* savedState;
     size_t savedStateSize;

     ALooper* looper;

     AInputQueue* inputQueue;

     ANativeWindow* window;

    ARect contentRect;

    JNIEnv* appThreadEnv;
    jobject appThreadThis;

    int activityState;

    int destroyRequested;

    pthread_mutex_t mutex;
    pthread_cond_t cond;

    int msgread;
    int msgwrite;

    int renderRead;
    int renderWrite;
    int usesChoreographer;

   pthread_t thread;

   unsigned int lifecycleFlags;

   struct android_poll_source cmdPollSource;
   struct android_poll_source inputPollSource;

   int running;
   int stateSaved;
   int destroyed;
   int redrawNeeded;
   AInputQueue* pendingInputQueue;
   ANativeWindow* pendingWindow;
   ARect pendingContentRect;

   jobject appThreadDisp;
   jmethodID appThreadDispGetRotation;
 };


enum 
{
	LOOPER_ID_MAIN = 1,

	LOOPER_ID_INPUT = 2,

	LOS_LOOPER_ID_REDRAW = 3,

	LOOPER_ID_USER = 4,
};


enum 
{
	APP_CMD_INPUT_CHANGED,

	APP_CMD_INIT_WINDOW,

	APP_CMD_TERM_WINDOW,

	APP_CMD_WINDOW_RESIZED,

	APP_CMD_WINDOW_REDRAW_NEEDED,

	APP_CMD_CONTENT_RECT_CHANGED,

	APP_CMD_GAINED_FOCUS,

	APP_CMD_LOST_FOCUS,

	APP_CMD_CONFIG_CHANGED,

	APP_CMD_LOW_MEMORY,

	APP_CMD_START,

	APP_CMD_RESUME,

	APP_CMD_SAVE_STATE,

	APP_CMD_PAUSE,

	APP_CMD_STOP,

	APP_CMD_DESTROY,
   

   // offset value for purshing commands from the Java level
	LOS_APP_CMD_USER
};


int los_app_status_running(struct android_app* android_app);

int los_app_status_active(struct android_app* android_app);

int los_app_statuc_focused(struct android_app* android_app);

int los_app_status_valid_surface(struct android_app* android_app);

int los_app_status_interactable(struct android_app* android_app);

int los_app_get_display_rotation(struct android_app* android_app);

void los_app_force_quit_no_cleanup(struct android_app* android_app);

int los_app_is_redraw(int ident);

int64_t los_app_process_redraw(struct android_app* android_app);

void los_app_post_redraw(struct android_app* android_app, int64_t time);

int32_t los_android_app_loop_wait(struct android_app* android_app);

int32_t los_android_app_free_redraw(struct android_app* android_app);

int8_t android_app_read_cmd(struct android_app* android_app);

void android_app_pre_exec_cmd(struct android_app* android_app, int8_t cmd);

void android_app_post_exec_cmd(struct android_app* android_app, int8_t cmd);

void app_dummy();

extern void android_main(struct android_app* app);


/**
  * OPTIONAL.  Loskutnikov added !   If defined in the app's code, this will be called pre-android_main
  * on the main Java thread, meaning that your activity's class loader is available
  * DO NOT forget that this is extern-"C"'ed, like android_main
  */

extern void los_android_init(ANativeActivity* act) __attribute__((weak));

#ifdef __cplusplus
}
 #endif