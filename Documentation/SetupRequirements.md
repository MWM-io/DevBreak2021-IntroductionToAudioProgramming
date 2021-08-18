# Before the workshop: setup and requirements

- [📚  Prerequisites](#--prerequisites)
- [🛠️  Technical requirements](#️--technical-requirements)
  - [💻  Computer requirements](#--computer-requirements)
    - [For all platforms: the JUCE framework](#for-all-platforms-the-juce-framework)
    - [macOS](#macos)
    - [Windows](#windows)
    - [Linux](#linux)
  - [🎧  Audio hardware requirements](#--audio-hardware-requirements)
  - [📱  Mobile device requirements (optional)](#--mobile-device-requirements-optional)
    - [iOS](#ios)
    - [Android](#android)


## 📚  Prerequisites

- Basic knowledge of **_C/C++ and its core concepts_** is highly recommended to attend the workshop. During the workshop, you will be invited to code in C/C++ yourself.
- The workshop has been designed for either **_Xcode on macOS_** or **_Visual Studio on Windows_**. Basic knowledge of the IDE you will use is recommended.
- The workshop projects are based on the [JUCE framework](https://juce.com/). It is not necessary to have prior knowledge about JUCE and the Projucer before the workshop. Nevertheless, you can consult the [JUCE repository](https://github.com/juce-framework/JUCE) and the [JUCE documentation](https://juce.com/learn/tutorials) if you want to know more about it.


## 🛠️  Technical requirements


### 💻  Computer requirements

To attend the worshop, you need a computer with either macOS (recommended) or Windows. The following configurations are recommended:
| macOS                  | Windows                      |
|------------------------|------------------------------|
| Intel or Apple Silicon | 64 bits CPU                  |
| macOS 10.15 or higher  | Windows 8.1 or higher        |
| Xcode 12.0 or higher   | Visual Studio 2015 or higher |

> ⚠️  You can attend the workshop with a Linux system, but the setup is more complicated and we will not have time to assist you if you encounter an issue with your development environment during the workshop.

#### For all platforms: the JUCE framework

You will need to have the [**_JUCE framework_**](https://juce.com/) installed on your machine to work on the workshop projects. **_Version 6.0.8 or higher_** is required.     
If you don't already have JUCE, we advise you to get [JUCE with a personal free license](https://juce.com/get-juce). We recommend installing JUCE and the Projucer by downloading [the latest stable JUCE framework corresponding to your platform](https://juce.com/get-juce/download), and placing the `JUCE` folder inside your home directory, usually `/Users/USERNAME/` aliased as `~/` or `$HOME/` on macOS, `/home/USERNAME/` aliased as `~/` or `$HOME/` on Linux and `C:\Users\USERNAME\` on Windows.

#### macOS

Before the workshop, please be sure to
- install [**_Xcode_**](https://apps.apple.com/fr/app/xcode/id497799835?mt=12),
- create an [**_Apple ID_**](https://appleid.apple.com/) if you do not already have one,
- register an Apple ID (standard or Developer account) in Xcode (Xcode > Preferences > Accounts).

If you are not familiar with Xcode, we highly recommend to follow basic tutorials about macOS applications development using Xcode before attending the workshop.

#### Windows

Before the workshop, please be sure to install [**_Visual Studio_**](https://visualstudio.microsoft.com/vs/).    

If you are not familiar with Visual Studio, we highly recommend to follow basic tutorials about Windows applications development using Visual Studio before attending the workshop.

#### Linux

Please refer to the [JUCE documentation](https://github.com/juce-framework/JUCE) for specific JUCE installation procedure on Linux.  

We highly recommend you to compile and run demo JUCE projects prior to the workshop to ensure your JUCE development environment is fully functionnal.


### 🎧  Audio hardware requirements

We recommend bringing **_headphones_** to the workshop.


### 📱  Mobile device requirements (optional)

During the workshop, you will have the possibility to compile and run applications on iOS or Android mobile devices.

#### iOS

Requirements are the same as [macOS](#macOS).     
Please be sure to bring **_your own iOS device_** and a cable to plug it to your computer. Apple cables are highly recommended for iOS development, cable from other brands might not fully work with Xcode.

If you are not familiar with iOS development on Xcode, we highly recommend to follow basic tutorials before attending the workshop.

#### Android

The workshop projects can be compiled for Android on all platforms.

In order to compile the projects for Android, please make sure to install, prior to the workshop:
- [**_Android Studio_**](https://developer.android.com/studio), ideally version 2020.3.1 or higher,
- and the following components, installed from Android SDK Manager CLI or GUI:
  - **_Android SDK platform 29_** (Android 10.0 - Q),
  - **_Android SDK Platform-Tools_** (latest),
  - **_Android SDK Build-Tools 29.0.2_**,
  - **_Android NDK 21.0.6113669_**,
  - **_cmake 3.10.2.4988404_**.

Please ensure you have a **_valid Android debug keystore_** (should be located in `~/.android/debug.keystore` on macOS/Linux or `C:\Users\USERNAME\.android\debug.keystore` on Windows). If needed, you can easily generate one by creating a new project in Android Studio.

Please be sure to bring **_your own Android device_** and a cable to plug it to your computer.

If you are not familiar with Android development on Android Studio, we highly recommend to follow basic tutorials before attending the workshop.
