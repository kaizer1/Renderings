// Top-level build file where you can add configuration options common to all sub-projects/modules.
//buildscript {
//    ext.kotlin_version = '1.8.10'
//    repositories {
//        google()
//        mavenCentral()
//
//    }
//    dependencies {
//        classpath 'com.android.tools.build:gradle:8.1.0-beta04'
//        classpath 'com.android.tools.build:gradle-settings:8.0.1' // was 7.3.1
//        classpath 'com.android.tools.build:gradle-settings-api:8.1.0-beta01'
//        classpath "org.jetbrains.kotlin:kotlin-gradle-plugin:$kotlin_version"
//
//        // distributionUrl=https\://services.gradle.org/distributions/gradle-7.4-all.zip
//        // NOTE: Do not place your application dependencies here; they belong
//        // in the individual module build.gradle files
//    }
//}

//allprojects {
//    repositories {
//        google()
//        mavenCentral()
//
//    }
//}

@Suppress("DSL_SCOPE_VIOLATION")
plugins {
    //alias(libs.plugins.caa)
    alias(libs.plugins.com.android.application) apply false
    alias(libs.plugins.org.jetbrains.kotlin.android) apply false
}
true

/*
task clean(type: Delete) {
    delete rootProject.buildDir
}*/
