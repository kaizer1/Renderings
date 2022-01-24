// Loskutnikov Games .inc

#include "mainLos/LosMainVulkan.h"
#include "mainLos/assetsLos.h"


void android_main(struct android_app* state)
{

    LosAssetLoaderInit((void *) state->activity->assetManager);
    mainAp = state;
    auto  run = std::make_unique<LosMainVulkan>();
    run->looperMainVulkan();
    run->~LosMainVulkan();

}