#include <opencv2/opencv.hpp>
#include <iostream>

int main()
{
    cv::Mat srcImg = cv::imread("test.jpg");

    if (!srcImg.empty())
    {
        cv::imshow("Src Image", srcImg);
    }

    // 定义掩膜矩阵
    // 什么是图像的掩膜操作？
    // 掩膜操作是指根据掩膜矩阵（也称作核kernel）重新计算图像中每个像素的值。
    // 掩膜矩阵中的值表示了邻近像素值（包括该像素自身的值）对新像素值有多大的影响。
    // 从数学的观点来看，我们用自己设置的权值，对像素领域内的值做了个加权平均。
    // 比如，下面这个公式表示用5倍当前像素的值减去该像素上、下、左、右四个像素值和，
    // 得到的结果赋值给当前像素。使用该公式可以用于提升图像的对比度。
    // 调节I(i,j)的系数权重可以得到不同的对比度提升效果。
    // 公式：I(i,j)=5∗I(i,j)−[I(i−1,j)+I(i+1,j)+I(i,j−1)+I(i,j+1)]
    cv::Mat kernerMat = (cv::Mat_<char>(3, 3) <<
                         0, -1, 0,
                         -1, 5, -1,
                         0, -1, 0);

    cv::Mat dstImg;

    // 掩膜操作函数
    cv::filter2D(srcImg, dstImg, srcImg.depth(), kernerMat);

    if (!dstImg.empty())
    {
        cv::imshow("Filter Image", dstImg);
    }

    cv::waitKey(0);

    return 0;
}
