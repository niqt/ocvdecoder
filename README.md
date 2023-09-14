# OCVDecoder (Aka YAQD)

I started this project because i don't find a QR decoder that working well on iOS and Android using Qt6 and Felgo.
I decided to use a decoder from OpenCV contrib ([opencv_contrib)](https://github.com/opencv/opencv_contrib/tree/4.x) precesely wechat_qrcode.
In the main branch it's possible already find the library compiled, don't worry no virus, no back door.
If you want compile by yourself, feel free following the instructions.


# Build

## Prepare the code

 1. clone the opencv mobile from [opencv-mobile](https://github.com/nihui/opencv-mobile)
	 

    wget -q https://github.com/opencv/opencv/archive/4.8.0.zip -O opencv-4.8.0.zip
	unzip -q opencv-4.8.0.zip
	cd opencv-4.8.0
	git clone https://github.com/opencv/opencv_contrib.git

	patch -p1 -i ../opencv-4.8.0-no-zlib.patch
	truncate -s 0 cmake/OpenCVFindLibsGrfmt.cmake
	rm -rf modules/gapi
	rm -rf modules/highgui
	cp -r ../highgui modules/
	
	patch -p1 -i ../opencv-4.8.0-no-rtti.patch

 2. Overwrite the opencv4_cmake_options.txt with which you find in this project


## Build

### iOS

 In the opencv directory:
 

 1. mkdir build-ios
 2. cd build-ios
 3. `cmake -DPLATFORM="OS" -DARCHS="arm64" \
 -DOPENCV_EXTRA_MODULES_PATH=../opencv_contrib/modules \
-DDEPLOYMENT_TARGET=$IOS_DEPLOYMENT_TARGET -DENABLE_BITCODE=$ENABLE_BITCODE \ -DENABLE_ARC=$ENABLE_ARC -DENABLE_VISIBILITY=$ENABLE_VISIBILITY \
-DCMAKE_C_FLAGS="-frtti" -DCMAKE_CXX_FLAGS="-frtti " \
-DCMAKE_INSTALL_PREFIX=install -DCMAKE_BUILD_TYPE=Release `cat ../../opencv4_cmake_options.txt` -DCMAKE_TOOLCHAIN_FILE=../../toolchains/ios.toolchain.cmake -DOPENCV_DISABLE_FILESYSTEM_SUPPORT=ON ..`

### Android
Set ANDROID_NDK_LATEST_HOME to the path of you Andoid NDK installation, then

 1. mkdir build-android
 2. cd build-android
 3. `cmake -DCMAKE_TOOLCHAIN_FILE=$ANDROID_NDK_LATEST_HOME/build/cmake/android.toolchain.cmake\  -DOPENCV_EXTRA_MODULES_PATH=../opencv_contrib/modules \ -DANDROID_USE_LEGACY_TOOLCHAIN_FILE=False -DANDROID_ABI="arm64-v8a" \ -DANDROID_PLATFORM=android-24 -DANDROID_CPP_FEATURES="rtti no-exceptions" \ -DCMAKE_INSTALL_PREFIX=install -DCMAKE_BUILD_TYPE=Release `cat ../../opencv4_cmake_options.txt`\ -DBUILD_opencv_world=OFF -DOPENCV_DISABLE_FILESYSTEM_SUPPORT=ON \ 
-DOPENCV_EXTRA_FLAGS="-mno-outline-atomics" ..`

### Installation
Thus copy the libraries in the correct path (see in the CMakeFile.txt). Don't forget to copy the library from the 3rdyparty directory.


## Use

 1. Copy the ocvdecoder in your Qt project
 2. Add this line `add_subdirectory(ocvdecoder ${CMAKE_BINARY_DIR}/ocvdecoder)` to the CMakeList.txt
 3. Add the library ocvdecoder to the target_link_libraries
 4. use import ocvdecoder in your Qml file

In the example directory there is an example created with [Felgo](https://www.felgo.com) but with pure Qt it's the same.

This project is working in progress, but stable to be used in project to decode Qr code like that
