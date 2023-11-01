
plugins {
    alias(libs.plugins.com.android.application)
    alias(libs.plugins.org.jetbrains.kotlin.android)
}

android {
    compileSdk = rootProject.extra["versionCurrent"] as Int

    // ok work
    signingConfigs {
        register("release") {
            keyAlias = "upload"
            keyPassword = System.getenv("KEYSTORE_PASSPHRASE")
            storeFile = file("../owntracks.release.keystore.jks")
            storePassword = System.getenv("KEYSTORE_PASSPHRASE")
            enableV1Signing = true
            enableV2Signing = true
            enableV3Signing = true
            enableV4Signing = true
        }
    }

    packaging {
        jniLibs {
            useLegacyPackaging = false
        }

        lint {
            abortOnError = false
        }
    }




    defaultConfig {
        minSdk =  rootProject.extra["minVersion1"] as Int // val versionCurrent by extra(34)
        targetSdk =  rootProject.extra["versionCurrent"] as Int
        versionCode = 1
        versionName = "1.0"


        @Suppress("UnstableApiUsage")
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
                    //"-DCMAKE_C_COMPILER='C:/Program Files/LLVM/bin/Clang.exe' -DCMAKE_CXX_COMPILER='C:/Program Files/LLVM/bin/Clang++.exe' ",
                    "-DBUILD_SHARED_LIBS=false",
                    "-DANDROID_STL=c++_static",
                )
            }
        }

        //noinspection ChromeOsAbiSupport
        ndk { abiFilters += listOf("arm64-v8a") }
    }



     flavorDimensions += "api"
    productFlavors {
        create("minApi33") {
            minSdk = rootProject.extra["minVersion2"] as Int
            versionNameSuffix = "-minApi33"
        }

        create("minApi28"){
            minSdk = rootProject.extra["minVersion1"] as Int
            versionNameSuffix = "-minApi28"
        }
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
            version  = "3.27.1" // was 3.18.1  //arguments "-DHWASAN=1"
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
        sourceCompatibility = JavaVersion.VERSION_17
        targetCompatibility = JavaVersion.VERSION_17
    }
    kotlinOptions {
        jvmTarget = JavaVersion.VERSION_17.toString()
    }

    ndkVersion = rootProject.extra["ndkVersion"] as String
    namespace = rootProject.extra["nameId"] as String

}

dependencies {
    implementation(libs.kotlinm)
    implementation(libs.corek)
}