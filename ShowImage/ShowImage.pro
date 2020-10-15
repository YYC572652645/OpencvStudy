CONFIG += c++11

TARGET = ShowImage
TEMPLATE = app

SOURCES += main.cpp

INCLUDEPATH += $$PWD/../include
DEPENDPATH += $$PWD/../include

win32:CONFIG(release, debug|release):
{
LIBS += -L$$PWD/../lib/ -llibopencv_calib3d320.dll \
-llibopencv_calib3d320.dll \
-llibopencv_core320.dll \
-llibopencv_features2d320.dll \
-llibopencv_flann320.dll \
-llibopencv_highgui320.dll \
-llibopencv_imgcodecs320.dll \
-llibopencv_imgproc320.dll \
-llibopencv_ml320.dll \
-llibopencv_objdetect320.dll \
-llibopencv_photo320.dll \
-llibopencv_shape320.dll \
-llibopencv_stitching320.dll \
-llibopencv_superres320.dll \
-llibopencv_video320.dll \
-llibopencv_videoio320.dll \
-llibopencv_videostab320.dll
}
