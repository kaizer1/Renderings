//apply plugin 'com.android.settings'


//android {
  //  compileSdk 31
  //  minSdk 24
//}
//include ':app'

pluginManagement {
    repositories{
        google()
        mavenCentral()
        gradlePluginPortal()
    }
}

dependencyResolutionManagement {
    repositoriesMode.set(RepositoriesMode.FAIL_ON_PROJECT_REPOS)
    repositories {
         google()
        mavenCentral()
    }
}
rootProject.name = "Renderings"
include(":app")