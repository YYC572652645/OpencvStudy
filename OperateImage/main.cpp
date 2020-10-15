#include <iostream>
#include "opencv2/opencv.hpp"

int main()
{
    cv::Mat srcImg = cv::imread("test.jpg", cv::IMREAD_COLOR);

    if(srcImg.empty())
    {
        std::cout << "Load Image error!" << std::endl;
        return -1;
    }
    cv::namedWindow("Src Image", CV_WINDOW_AUTOSIZE);
    cv::imshow("Src Image", srcImg);

    cv::Mat grayImg;
    cv::cvtColor(srcImg, grayImg, CV_BGR2GRAY);
    cv::namedWindow("Gray Image", CV_WINDOW_AUTOSIZE);
    cv::imshow("Gray Image", grayImg);

    for (int i = 0; i < grayImg.rows; i++)
    {
        for (int j = 0; j < grayImg.cols; j++)
        {
            int gray = grayImg.at<uchar>(i, j);
            grayImg.at<uchar>(i, j) = static_cast<uchar>(255 - gray);
        }
    }

    cv::namedWindow("Change Gray Image", CV_WINDOW_AUTOSIZE);
    cv::imshow("Change Gray Image", grayImg);

    for (int i = 0; i < srcImg.rows; i++)
    {
        for (int j = 0; j < srcImg.cols; j++)
        {
            int blue = srcImg.at<cv::Vec3b>(i, j)[0];
            int green = srcImg.at<cv::Vec3b>(i, j)[1];
            int red = srcImg.at<cv::Vec3b>(i, j)[2];
            srcImg.at<cv::Vec3b>(i, j)[0] = static_cast<uchar>(255 - blue);
            srcImg.at<cv::Vec3b>(i, j)[1] = static_cast<uchar>(255 - green);
            srcImg.at<cv::Vec3b>(i, j)[2] = static_cast<uchar>(255 - red);
        }
    }

    cv::namedWindow("Change Src Image", CV_WINDOW_AUTOSIZE);
    cv::imshow("Change Src Image", srcImg);

    cv::waitKey(0);
    return 0;
}
