# sdlgtm

SDL image - LGTM - example project

* renders static LGTM XPM
* generate android project
* project build by conan

# Requirements

* [SDL2](https://www.libsdl.org)
* [conan](https://conan.io)

# Build

`./build.sh`

# Android project

To generate an Android project

* install Android SDK and NDK
* checkout SDL2 project `hg clone http://hg.libsdl.org/SDL`
* `./android-build.sh -h` to see the required options

eg. `./android-build.sh -a ~/Android/Sdk -n ~/Android/Ndk -s ~/Projects/SDL -p org.lgtm`

```
Android/
└── lgtm
    ├── app
    ├── build.gradle
    ├── gradle
    ├── gradle.properties
    ├── gradlew
    ├── gradlew.bat
    └── settings.gradle
```
