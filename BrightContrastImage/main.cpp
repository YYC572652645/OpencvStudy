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

    cv::Mat chageMat = cv::Mat::zeros(srcImg.size(), srcImg.type());

    float alpha = 1.5;
    float beta = 0;
    for (int i = 0; i < srcImg.rows; i++)
    {
        for (int j = 0; j < srcImg.cols; j++)
        {
            for(int k = 0; k < srcImg.channels(); k++)
            {
                int color = srcImg.at<cv::Vec3b>(i, j)[k];
                chageMat.at<cv::Vec3b>(i, j)[k] = cv::saturate_cast<uchar>(color * alpha + beta);
            }
        }
    }

    cv::imshow("Src Image", chageMat);

    cv::waitKey(0);
    return 0;
}
