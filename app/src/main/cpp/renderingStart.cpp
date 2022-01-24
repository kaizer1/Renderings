//


void android_main(struct android_app* state)
{

    LosAssetLoaderInit((void *) state->activity->assetManager);
    mainAp = state;
    auto*  run = new LosMainApp();
    run->looperMainCos();
    run->~LosMainApp();

}