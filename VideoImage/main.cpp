#include <opencv2/opencv.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <iostream>
#include <QDebug>

// 边缘检测
void CandyImage(cv::Mat &mat)
{
    // 图片变为灰度
    cv::cvtColor(mat, mat, CV_BGR2GRAY);

    // 均值滤波降噪
    cv::blur(mat, mat, cv::Size(7, 7));

    // 边缘检测
    cv::Canny(mat, mat, 0, 30, 3);
}

// 播放视频
int main()
{
    cv::VideoCapture videoCapture("test.mp4");

    while (true)
    {
        cv::Mat frameImage;
        videoCapture >> frameImage;

        if (frameImage.empty()) return -1;
        CandyImage(frameImage);
        cv::imshow("Video", frameImage);
        cv::waitKey(30);
    }

    return 0;
}
