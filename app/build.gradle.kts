@Suppress("DSL_SCOPE_VIOLATION")
plugins {
    alias(libs.plugins.com.android.application)
    alias(libs.plugins.org.jetbrains.kotlin.android)
}

android {
    compileSdk = 33

    // ok work
//    signingConfigs {
//        register("release") {
//            keyAlias = "upload"
//            keyPassword = System.getenv("KEYSTORE_PASSPHRASE")
//            storeFile = file("../owntracks.release.keystore.jks")
//            storePassword = System.getenv("KEYSTORE_PASSPHRASE")
//            enableV1Signing = true
//            enableV2Signing = true
//            enableV3Signing = true
//            enableV4Signing = true
//        }
//    }

    packaging {
        jniLibs {
            useLegacyPackaging = false
        }
    }



//    execution {
//        profiles {
//            high {
//                r8 {
//                    jvmOptions += ["-Xms2048m", "-Xmx8192m", "-XX:+HeapDumpOnOutOfMemoryError"]
//                    runInSeparateProcess true
//                }
//            }
//            low {
//                r8 {
//                    jvmOptions += ["-Xms256m", "-Xmx2048m", "-XX:+HeapDumpOnOutOfMemoryError"]
//                    runInSeparateProcess true
//                }
//            }
//            ci {
//                r8.runInSeparateProcess false
//            }
//        }
//        defaultProfile "high"
//    }

    defaultConfig {
        applicationId = "com.sergey.los.freelanceideas.renderings"
        minSdk =  28
        targetSdk = 33
        versionCode = 1
        versionName = "1.0"


        externalNativeBuild {
            cmake {
                // -fbuiltin-module-map
                // ok module -fmodule-map-file=Q:\AndroidSDK\ndk\24.0.7856742\toolchains\llvm\prebuilt\windows-x86_64\sysroot\usr\include\c++\v1\module.modulemap
                // -fmodules -fmodule-map-file=Q:\AndroidSDK\ndk\24.0.7956693\sources\cxx-stl\llvm-libc++\include\module.modulemap
                // -fmodule-map-file=Q:\AndroidProject\Renderings\app\src\main\cpp\losmod.modulemap - ok too ( but error also )
                //fmodules

                //        arguments "-DANDROID_ARM_NEON=TRUE", "-DANDROID_TOOLCHAIN=clang"
                // -fmodule-map-file=Q:/AndroidSDK/ndk/25.0.8775105/toolchains/llvm/prebuilt/windows-x86_64/sysroot/usr/include/c++/v1/module.modulemap
                cppFlags ( "-std=c++20",  "-Ofast",  "-O3",  "-ftree-vectorize") // -Ofast  -fsanitize=memory  -fimplicit-module-maps
              // -fmodules -fmodule-map-file=Q:\AndroidSDK\ndk\24.0.8215888\toolchains\llvm\prebuilt\windows-x86_64\sysroot\usr\include\c++\v1\module.modulemap -fmodules-decluse -fno-implicit-modules
               // -fmodules -fmodule-map-file=Q:\AndroidSDK\ndk\24.0.7856742\toolchains\llvm\prebuilt\windows-x86_64\sysroot\usr\include\c++\v1\module.modulemap
           // -fmodules -fmodule-map-file=Q:\AndroidProject\Renderings\app\src\main\cpp\losmod.modulemap
                // -Ofast -O3 -ftree-vectorize


                arguments(
                    //"-DCMAKE_ANDROID_API=" + minSdk.toString(),
                    //"-DICU_ASSET_EXPORT_DIR=" + project.file("src/main/assets/icu4c").absolutePath,
                    "-DBUILD_SHARED_LIBS=false",
                    "-DANDROID_STL=c++_static",
                )
            }
        }

        //noinspection ChromeOsAbiSupport
        ndk { abiFilters += listOf("arm64-v8a") }
        ndkVersion = "25.0.8775105"
    }


    //flavorDimensions.add("api")

     flavorDimensions += "api"

    productFlavors {
        create("minApi33") {
            minSdk = 33
            versionNameSuffix = "-minApi33"
        }

        create("minApi28"){
            minSdk = 28
            versionNameSuffix = "-minApi28"
        }
    }

//    productFlavors {
//        minApi33 {
//            minSdkVersion = "33"
//            versionNameSuffix = "-minApi33"
//        }
//
//        minApi29 {
//            minSdkVersion = "28"
//            versionNameSuffix = "-minApi28"
//        }
//    }

    buildFeatures {
        viewBinding =  true
    }


    buildTypes {
      named("debug") {
          isDebuggable  =  true
          isJniDebuggable = true
          isMinifyEnabled =  true
          isShrinkResources  =  false
        }
        named("release") {
            isDebuggable =  false
            isJniDebuggable = false
            isMinifyEnabled =  true
            isShrinkResources  =  true
            proguardFiles( getDefaultProguardFile("proguard-android-optimize.txt"), "proguard-rules.pro")
        }
    }

    externalNativeBuild {
        cmake {
            path ( "CMakeLists.txt" )
            version  = "3.22.0" // was 3.18.1
            //arguments "-DHWASAN=1"
        }
    }

    sourceSets {
//        main {
//            jniLibs {
//              //  srcDir "Q:\\AndroidSDK\\ndk\\22.0.7026061\\sources\\third_party\\vulkan\\src\\build-android\\jniLibs"
//              //
//            }
//        }
    }


    compileOptions {
        sourceCompatibility = JavaVersion.VERSION_1_8
        targetCompatibility = JavaVersion.VERSION_1_8
    }
    kotlinOptions {
        //jvmTarget = '1.8'
        jvmTarget = JavaVersion.VERSION_1_8.toString()
    }
    ndkVersion = "25.0.8775105"
    namespace = "com.sergey.los.freelanceideas.renderings"


//     execution {
//          profiles {
//               high {
//                   r8 {
//                        jvmOptions += ["-Xms2048m", "-Xmx8192m", "-XX:+HeapDumpOnOutOfMemoryError"]
//                        runInSeparateProcess true
//                   }
//               }
//              low {
//                  r8 {
//                      jvmOptions += ["-Xms256m", "-Xmx2048m", "-XX:+HeapDumpOnOutOfMemoryError"]
//                      runInSeparateProcess true
//                  }
//              }
//              ci {
//                  r8.runInSeparateProcess false
//              }
//          }
//         defaultProfile "high"
//     }

}

dependencies {
    //implementation "org.jetbrains.kotlin:kotlin-stdlib:$kotlin_version"
    //implementation 'androidx.core:core-ktx:1.10.1'

    implementation(libs.kotlinm)
    implementation(libs.corek)

}