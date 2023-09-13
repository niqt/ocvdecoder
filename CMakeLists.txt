


qt6_add_qml_module(ocvdecoder
    URI ocvdecoder
    VERSION 1.0
    SOURCES
        ocvdecoder.h ocvdecoder.cpp
)


if (ANDROID)
    target_link_libraries(ocvdecoder
        PRIVATE Qt6::Quick Qt6::Multimedia
        -static-openmp -fopenmp
    )
endif()

if (IOS)
    target_link_libraries(ocvdecoder
        PRIVATE Qt6::Quick Qt6::Multimedia
    )
endif()


target_include_directories(ocvdecoder PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/opencv/include/)

target_link_libraries(ocvdecoder PUBLIC Qt::CorePrivate)
message(PROJECT_SOURCE_DIR=${ANDROID_ABI})
if(IOS)
    target_link_libraries(ocvdecoder PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}/opencv/ios/libopencv_hfs.a
        ${CMAKE_CURRENT_SOURCE_DIR}/opencv/ios/libopencv_rgbd.a
        ${CMAKE_CURRENT_SOURCE_DIR}/opencv/ios/libopencv_aruco.a
        ${CMAKE_CURRENT_SOURCE_DIR}/opencv/ios/libopencv_highgui.a
        ${CMAKE_CURRENT_SOURCE_DIR}/opencv/ios/libopencv_saliency.a
        ${CMAKE_CURRENT_SOURCE_DIR}/opencv/ios/libopencv_bgsegm.a
        ${CMAKE_CURRENT_SOURCE_DIR}/opencv/ios/libopencv_img_hash.a
        ${CMAKE_CURRENT_SOURCE_DIR}/opencv/ios/libopencv_shape.a
        ${CMAKE_CURRENT_SOURCE_DIR}/opencv/ios/libopencv_bioinspired.a
        ${CMAKE_CURRENT_SOURCE_DIR}/opencv/ios/libopencv_imgcodecs.a
        ${CMAKE_CURRENT_SOURCE_DIR}/opencv/ios/libopencv_structured_light.a
        ${CMAKE_CURRENT_SOURCE_DIR}/opencv/ios/libopencv_calib3d.a
        ${CMAKE_CURRENT_SOURCE_DIR}/opencv/ios/libopencv_imgproc.a
        ${CMAKE_CURRENT_SOURCE_DIR}/opencv/ios/libopencv_surface_matching.a
        ${CMAKE_CURRENT_SOURCE_DIR}/opencv/ios/libopencv_ccalib.a
        ${CMAKE_CURRENT_SOURCE_DIR}/opencv/ios/libopencv_intensity_transform.a
        ${CMAKE_CURRENT_SOURCE_DIR}/opencv/ios/libopencv_tracking.a
        ${CMAKE_CURRENT_SOURCE_DIR}/opencv/ios/libopencv_core.a
        ${CMAKE_CURRENT_SOURCE_DIR}/opencv/ios/libopencv_line_descriptor.a
        ${CMAKE_CURRENT_SOURCE_DIR}/opencv/ios/libopencv_video.a
        ${CMAKE_CURRENT_SOURCE_DIR}/opencv/ios/libopencv_dnn.a
        ${CMAKE_CURRENT_SOURCE_DIR}/opencv/ios/libopencv_mcc.a
        ${CMAKE_CURRENT_SOURCE_DIR}/opencv/ios/libopencv_videoio.a
        ${CMAKE_CURRENT_SOURCE_DIR}/opencv/ios/libopencv_dnn_objdetect.a
        ${CMAKE_CURRENT_SOURCE_DIR}/opencv/ios/libopencv_objdetect.a
        ${CMAKE_CURRENT_SOURCE_DIR}/opencv/ios/libopencv_videostab.a
        ${CMAKE_CURRENT_SOURCE_DIR}/opencv/ios/libopencv_dnn_superres.a
        ${CMAKE_CURRENT_SOURCE_DIR}/opencv/ios/libopencv_optflow.a
        ${CMAKE_CURRENT_SOURCE_DIR}/opencv/ios/libopencv_wechat_qrcode.a
        ${CMAKE_CURRENT_SOURCE_DIR}/opencv/ios/libopencv_dpm.a
        ${CMAKE_CURRENT_SOURCE_DIR}/opencv/ios/libopencv_phase_unwrapping.a
        ${CMAKE_CURRENT_SOURCE_DIR}/opencv/ios/libopencv_xfeatures2d.a
        ${CMAKE_CURRENT_SOURCE_DIR}/opencv/ios/libopencv_face.a
        ${CMAKE_CURRENT_SOURCE_DIR}/opencv/ios/libopencv_photo.a
        ${CMAKE_CURRENT_SOURCE_DIR}/opencv/ios/libopencv_ximgproc.a
        ${CMAKE_CURRENT_SOURCE_DIR}/opencv/ios/libopencv_xobjdetect.a
        ${CMAKE_CURRENT_SOURCE_DIR}/opencv/ios/libopencv_xphoto.a
        ${CMAKE_CURRENT_SOURCE_DIR}/opencv/ios/libopencv_features2d.a
        ${CMAKE_CURRENT_SOURCE_DIR}/opencv/ios/libopencv_plot.a
        ${CMAKE_CURRENT_SOURCE_DIR}/opencv/ios/libopencv_xobjdetect.a
        ${CMAKE_CURRENT_SOURCE_DIR}/opencv/ios/libopencv_xphoto.a
        ${CMAKE_CURRENT_SOURCE_DIR}/opencv/ios/libopencv_flann.a
        ${CMAKE_CURRENT_SOURCE_DIR}/opencv/ios/libopencv_rapid.a
        ${CMAKE_CURRENT_SOURCE_DIR}/opencv/ios/libopencv_fuzzy.a
        ${CMAKE_CURRENT_SOURCE_DIR}/opencv/ios/libopencv_reg.a
        ${CMAKE_CURRENT_SOURCE_DIR}/opencv/ios/libquirc.a
    )

endif()

if (ANDROID)

target_link_libraries(ocvdecoder PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/opencv/android/arm64-v8a/libopencv_hfs.a
    ${CMAKE_CURRENT_SOURCE_DIR}/opencv/android/arm64-v8a/libopencv_rgbd.a
    ${CMAKE_CURRENT_SOURCE_DIR}/opencv/android/arm64-v8a/libopencv_aruco.a
    ${CMAKE_CURRENT_SOURCE_DIR}/opencv/android/arm64-v8a/libopencv_highgui.a
    ${CMAKE_CURRENT_SOURCE_DIR}/opencv/android/arm64-v8a/libopencv_saliency.a
    ${CMAKE_CURRENT_SOURCE_DIR}/opencv/android/arm64-v8a/libopencv_bgsegm.a
    ${CMAKE_CURRENT_SOURCE_DIR}/opencv/android/arm64-v8a/libopencv_img_hash.a
    ${CMAKE_CURRENT_SOURCE_DIR}/opencv/android/arm64-v8a/libopencv_shape.a
    ${CMAKE_CURRENT_SOURCE_DIR}/opencv/android/arm64-v8a/libopencv_bioinspired.a
    ${CMAKE_CURRENT_SOURCE_DIR}/opencv/android/arm64-v8a/libopencv_imgcodecs.a
    ${CMAKE_CURRENT_SOURCE_DIR}/opencv/android/arm64-v8a/libopencv_structured_light.a
    ${CMAKE_CURRENT_SOURCE_DIR}/opencv/android/arm64-v8a/libopencv_calib3d.a
    ${CMAKE_CURRENT_SOURCE_DIR}/opencv/android/arm64-v8a/libopencv_imgproc.a
    ${CMAKE_CURRENT_SOURCE_DIR}/opencv/android/arm64-v8a/libopencv_surface_matching.a
    ${CMAKE_CURRENT_SOURCE_DIR}/opencv/android/arm64-v8a/libopencv_ccalib.a
    ${CMAKE_CURRENT_SOURCE_DIR}/opencv/android/arm64-v8a/libopencv_intensity_transform.a
    ${CMAKE_CURRENT_SOURCE_DIR}/opencv/android/arm64-v8a/libopencv_tracking.a
    ${CMAKE_CURRENT_SOURCE_DIR}/opencv/android/arm64-v8a/libopencv_core.a
    ${CMAKE_CURRENT_SOURCE_DIR}/opencv/android/arm64-v8a/libopencv_line_descriptor.a
    ${CMAKE_CURRENT_SOURCE_DIR}/opencv/android/arm64-v8a/libopencv_video.a
    ${CMAKE_CURRENT_SOURCE_DIR}/opencv/android/arm64-v8a/libopencv_dnn.a
    ${CMAKE_CURRENT_SOURCE_DIR}/opencv/android/arm64-v8a/libopencv_mcc.a
    ${CMAKE_CURRENT_SOURCE_DIR}/opencv/android/arm64-v8a/libopencv_videoio.a
    ${CMAKE_CURRENT_SOURCE_DIR}/opencv/android/arm64-v8a/libopencv_dnn_objdetect.a
    ${CMAKE_CURRENT_SOURCE_DIR}/opencv/android/arm64-v8a/libopencv_objdetect.a
    ${CMAKE_CURRENT_SOURCE_DIR}/opencv/android/arm64-v8a/libopencv_videostab.a
    ${CMAKE_CURRENT_SOURCE_DIR}/opencv/android/arm64-v8a/libopencv_dnn_superres.a
    ${CMAKE_CURRENT_SOURCE_DIR}/opencv/android/arm64-v8a/libopencv_optflow.a
    ${CMAKE_CURRENT_SOURCE_DIR}/opencv/android/arm64-v8a/libopencv_wechat_qrcode.a
    ${CMAKE_CURRENT_SOURCE_DIR}/opencv/android/arm64-v8a/libopencv_dpm.a
    ${CMAKE_CURRENT_SOURCE_DIR}/opencv/android/arm64-v8a/libopencv_phase_unwrapping.a
    ${CMAKE_CURRENT_SOURCE_DIR}/opencv/android/arm64-v8a/libopencv_xfeatures2d.a
    ${CMAKE_CURRENT_SOURCE_DIR}/opencv/android/arm64-v8a/libopencv_face.a
    ${CMAKE_CURRENT_SOURCE_DIR}/opencv/android/arm64-v8a/libopencv_photo.a
    ${CMAKE_CURRENT_SOURCE_DIR}/opencv/android/arm64-v8a/libopencv_ximgproc.a
    ${CMAKE_CURRENT_SOURCE_DIR}/opencv/android/arm64-v8a/libopencv_xobjdetect.a
    ${CMAKE_CURRENT_SOURCE_DIR}/opencv/android/arm64-v8a/libopencv_xphoto.a
    ${CMAKE_CURRENT_SOURCE_DIR}/opencv/android/arm64-v8a/libopencv_features2d.a
    ${CMAKE_CURRENT_SOURCE_DIR}/opencv/android/arm64-v8a/libopencv_plot.a
    ${CMAKE_CURRENT_SOURCE_DIR}/opencv/android/arm64-v8a/libopencv_xobjdetect.a
    ${CMAKE_CURRENT_SOURCE_DIR}/opencv/android/arm64-v8a/libopencv_xphoto.a
    ${CMAKE_CURRENT_SOURCE_DIR}/opencv/android/arm64-v8a/libopencv_flann.a
    ${CMAKE_CURRENT_SOURCE_DIR}/opencv/android/arm64-v8a/libopencv_rapid.a
    ${CMAKE_CURRENT_SOURCE_DIR}/opencv/android/arm64-v8a/libopencv_fuzzy.a
    ${CMAKE_CURRENT_SOURCE_DIR}/opencv/android/arm64-v8a/libopencv_reg.a
    ${CMAKE_CURRENT_SOURCE_DIR}/opencv/android/arm64-v8a/libquirc.a
)

endif()
