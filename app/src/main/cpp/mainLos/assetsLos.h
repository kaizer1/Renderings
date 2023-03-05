//
// Created by loskutnikov on 24.01.2022.
//

#ifndef RENDERINGS_ASSETSLOS_H
#define RENDERINGS_ASSETSLOS_H


#include <stdbool.h>
#include <android/asset_manager.h>


#ifdef __cplusplus
extern "C"{
#endif


typedef void* LosAssetFile;


bool LosAssetLoaderInit(void* goAsset);
AAssetManager* backAssetMan();

#ifdef __cplusplus
}
#endif


#endif //RENDERINGS_ASSETSLOS_H
