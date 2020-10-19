#include <opencv2/opencv.hpp>
#include <iostream>
#include <QDebug>

#define WINDOW_NAME "TrackImage"

cv::Mat g_srcImage;
cv::Mat g_dstImage;
int g_alphaValue = 70;
int g_betaValue = 0;

// 滑动条的回调函数
void trackbarCallback(int pos, void* userdata)
{
    g_dstImage = cv::Mat::zeros(g_srcImage.size(), g_srcImage.type());

    for (int i = 0; i < g_dstImage.rows; i++)
    {
        for (int j = 0; j < g_dstImage.cols; j++)
        {
            for (int k = 0; k < g_dstImage.channels(); k++)
            {
                int color = g_srcImage.at<cv::Vec3b>(i, j)[k];
                float alpha = g_alphaValue / 100.0;
                g_dstImage.at<cv::Vec3b>(i, j)[k] = cv::saturate_cast<uchar>(color * alpha + g_betaValue);
            }
        }
    }
    cv::imshow(WINDOW_NAME, g_dstImage);
}

// 使用滚动条控制图片
int main()
{
    g_srcImage = cv::imread("test.jpg");

    if (g_srcImage.empty())
    {
        std::cout << "error";
        return -1;
    }

    cv::namedWindow(WINDOW_NAME);

    cv::createTrackbar("TrackAlphaBar", WINDOW_NAME, &g_alphaValue, 255, trackbarCallback);
    cv::createTrackbar("TrackBetaBar", WINDOW_NAME, &g_betaValue, 100, trackbarCallback);
    cv::imshow(WINDOW_NAME, g_srcImage);
    cv::waitKey(0);
    return 0;
}
