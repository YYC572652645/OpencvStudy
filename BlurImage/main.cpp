#include <opencv2/opencv.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <iostream>
#include <QDebug>

// 图像模糊，采用均值滤波
int main()
{
    cv::Mat srcImage = cv::imread("test.jpg");

    if (srcImage.empty())
    {
        std::cout << "error" << std::endl;
        return -1;
    }

    cv::Mat dstImage;

    // 均值滤波
    cv::blur(srcImage, dstImage, cv::Size(7, 7));

    cv::imshow("SrcImage", srcImage);
    cv::imshow("DstImage", dstImage);

    cv::waitKey(0);
    return 0;
}
