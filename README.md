#ApplovinX
A C++ wrapper of [Applovin](http://www.applovin.com/index) for [Cocos2d-X](https://github.com/cocos2d/cocos2d-x). Supports Android and iOS.

#Environment

* ###Applovin SDK
	* Android: v5.2.2
	* iOS: v2.2.4

* ###cocos2d-x
	* cocos2d-x-2.0.3 or higher

#Example Project
1. iOS: example/proj.ios/HelloCpp.xcodeproj
2. Android: example/proj.android

***You need to change the build script (such as build_native.sh) according to your own environment before compiling***.

#Add to Your Own Project

***iOS and Android will share the same `ApplovinX.h` header file. You need add `applovin-x/ApplovinX.h` to your `Classes` folder in the beginning.***

### iOS

All the following files you need in iOS are in `applovin-x/ios` fold.

1. Add the previous `ApplovinX.h` to your Xcode project
2. Add `headers/`, `ApplovinX_ios.mm`, `libAppLovinSdk.a` to your Xcode project
3. Add `#import "ALSdk.h"` to `AppController.mm`, and call `[ALSdk initializeSdk];` in AppController's `applicationDidFinishLaunching` method
4. Go to your Project Settings. Select "Info", right-click on one of the rows of "Custom iOS Properties" and select "Add Row".
The key of the new row should be AppLovinSdkKey and the value shouble be YOUR\_SDK\_KEY
5. Ensure you're linking with the following libraries:
	* AdSupport.framework
	* CoreTelephony.framework
	* CoreGraphics.framework
	* MediaPlayer.framework
	* StoreKit.framework
	* SystemConfiguration.framework
	* UIKit.framework
6. Go to your Project Settings. Select "Build Settings", search for "Other Linker Flags" and add -all_load -ObjC.

### Android

All the following files you need in Android are in `applovin-x/android` fold.

1. Add the package `com.wenbin.ApplovinX` and its `ApplovinXBridge.java` to your Eclipse project.
*(You can just add the whole `com` fold to `src` fold in Eclipse project, and refresh in Eclipse)*
2. Add `applovin-sdk-5.1.0.jar` as an external jar to your project.
*(You can just add the `applovin-sdk-5.1.0.jar` file to `libs` fold in Eclipse project, and refresh in Eclipse)*
3. Add `ApplovinX_android.cpp`, `ApplovinXJni.cpp` and `ApplovinXJni.h` to your `jni` fold.
4. Add `ApplovinX_android.cpp`, `ApplovinXJni.cpp` to your jni's `Android.mk`.
5. In the java implementation of your main activity (which should have been created by the Cocos2d-X script), `import com.wenbin.ApplovinX.*;`
6. At the beginning of `onCreate(Bundle savedInstanceState)`, right after `super.onCreate(savedInstanceState)`, add the following code:

		ApplovinXBridge.initApplovinXBridge(this);

7. Add the following xml to your Android Manifest file:

	Add Sdk Key. This needs to go inside the "application" tag:

		<meta-data android:name="applovin.sdk.key"
			android:value="YOUR_SDK_KEY"  />

	Add permission:

		<uses-permission android:name="android.permission.INTERNET" />
		<uses-permission android:name="android.permission.ACCESS_NETWORK_STATE" />
		<uses-permission android:name="android.permission.READ_PHONE_STATE"/>

	Add activity:

		<activity android:name="com.applovin.adview.AppLovinInterstitialActivity" />

##Email: <wenbin1989@gmail.com>
##Blog: <http://geeksavetheworld.com>

##You're welcome to contribute. ;-)
