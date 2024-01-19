val ndkVersion by extra("26.1.10909125")
val nameId by extra("com.sergey.los.freelanceideas.renderings")
val buildTVer by extra("34.0.0")
val versionCurrent by extra(34)
val minVersion1 by extra(28)
val minVersion2 by extra(33)

plugins {
    alias(libs.plugins.com.android.application) apply false
    alias(libs.plugins.org.jetbrains.kotlin.android) apply false
}

// https://www.lambdatest.com/mobile-app-testing real device tests

tasks.create<Delete>("clean") {
    delete {
        rootProject.buildDir
    }
}
