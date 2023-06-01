// TODO Loskutnikov Games .inc

#include "mainLos/LosMainVulkan.h"
#include "mainLos/assetsLos.h"

//import androidndk;

//import "xlocale.h";

//#include <string>


//import std_config;
//import string;
//import math;
//#include <xlocale.h>

//import std;
//import std_config;
//import std:locale_h;

//#include <xlocale.h>
#include <los_android_native_app_glue.h>
#include "logLos.h"
#include <string_view>

#include <atomic>
#include <thread>
#include <vector>
//import string;
//import locale_h;
//import __locale;

//import math;
//#include <los_android_native_app_glue.h>
//import android_ndk_main;
//import ModuleA;
//import Foo;
//import std;
//import androidndk;
//#include <los_android_native_app_glue.h>
//import <los_android_native_app_glue.h>;






enum class Color {
     red,
     green,
     blue,
     purple
};

class Point3D {
public:
     int x;
     int y;
     int z;
};

std::string_view toString(Color cdf){
    switch(cdf){

        using enum Color;
        case red: return "lodRed";
        case green: [[likely]] return "losGreen";
        case blue:  return "losBlue";
        case purple: return "Purple";

    }
    return "unknown";
}



//std::vector<int> myvec{};
//std::atomic<bool> atomicBool{false};
//
//void prepareWork() {
//    myvec.insert(myvec.end(), {0, 1, 0, 3});
//    logRun(" data prepare ! ");
//    atomicBool.store(true);
//    atomicBool.notify_one();
//}
//
//void completeWork() {
//
//    logRun(" Waiting for data   ! ");
//    atomicBool.wait(false);
//    myvec[2] = 2;
//    logRun(" Waiting complete  ");
//    for (auto i : myvec) logRun(" %d ", myvec[i]);
//}


void android_main(struct android_app* state)
{

      //std::string adfsdf("sdfasdf");

    logRun(" my values ! %d", 3000);

    // new render is

     using enum Color;

    //logRun(" my values ! %s", toString(Color::green)); // ok test


    logRun(" building  1 ");
     Point3D los3D{3, 6, 10};
    logRun(" my values ! %d, %d, %d", los3D.x, los3D.y, los3D.z);

    logRun("simple start ");

    //std::thread t1(prepareWork);
    //std::thread t2(completeWork);

   // t1.join();
   // t2.join();



    LosAssetLoaderInit((void *) state->activity->assetManager);
   // mainAp = state;
    logRun("86 " );
    mainAp = state;
    auto run = std::make_unique<LosMainVulkan>();
    logRun("Pre loop " );
    run->looperMainVulkan();
    run->~LosMainVulkan();

}