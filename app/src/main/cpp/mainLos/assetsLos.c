//
// Created by loskutnikov on 24.01.2022.
//
#include "assetsLos.h"

static AAssetManager* s_assetManager = NULL;


bool LosAssetLoaderInit(void* goAsset)
{
    if(!goAsset)
        return false;

    s_assetManager = (AAssetManager*)goAsset;

    return true;
}




AAssetManager* backAssetMan()
{

    if(s_assetManager == NULL)
        return NULL;

    return s_assetManager;


}
