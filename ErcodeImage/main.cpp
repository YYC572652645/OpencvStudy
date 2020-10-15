#include <opencv2/opencv.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <iostream>

// 腐蚀
int main()
{
    cv::Mat dstMat;
    cv::Mat srcMat = cv::imread("test.jpg");

    if (srcMat.empty())
    {
        std::cout << "error" << std::endl;
        return -1;
    }

    // 返回值为指定形状和尺寸的结构元素（内核矩阵）
    cv::Mat structMat = cv::getStructuringElement(cv::MORPH_CROSS, cv::Size(15, 15));

    // 腐蚀接口函数
    cv::erode(srcMat, dstMat, structMat);

    cv::imshow("腐蚀", dstMat);

    cv::waitKey(0);

    return 0;
}

