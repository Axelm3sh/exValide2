call ndk-build NDK_MODULE_PATH="../../../oxygine-framework-with-sdl/"
call gradlew assembleDebug
call adb install -r build/outputs/apk/proj.android-debug.apk
call adb shell am start -n org.oxygine.ExValide2/org.oxygine.ExValide2.MainActivity