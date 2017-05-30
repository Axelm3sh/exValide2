#!/usr/bin/env sh

ndk-build NDK_MODULE_PATH="../../../oxygine-framework-with-sdl/"
gradlew assembleDebug
adb install -r build/outputs/apk/proj.android-debug.apk
adb shell am start -n org.oxygine.ExValide2/org.oxygine.ExValide2.MainActivity