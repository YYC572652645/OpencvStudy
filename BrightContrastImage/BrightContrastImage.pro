QT -= gui

CONFIG += c++11 console
CONFIG -= app_bundle

# The following define makes your compiler emit warnings if you use
# any Qt feature that has been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
        main.cpp

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

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
