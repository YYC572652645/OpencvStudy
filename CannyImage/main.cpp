#include <opencv2/opencv.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <iostream>

// 腐蚀
int main()
{
    cv::Mat srcMat = cv::imread("test.jpg");

    if (srcMat.empty())
    {
        std::cout << "error" << std::endl;
        return -1;
    }

    // 图片变为灰度
    cv::Mat grayMat;
    cv::cvtColor(srcMat, grayMat, CV_BGR2GRAY);

    // 均值滤波降噪
    cv::Mat cannyMat;
    cv::blur(grayMat, cannyMat, cv::Size(3, 3));

    // 边缘检测
    cv::Canny(cannyMat, cannyMat, 3, 9, 3);

    cv::imshow("SrcImage", srcMat);
    cv::imshow("CannyImage", cannyMat);

    cv::waitKey(0);

    return 0;
}
