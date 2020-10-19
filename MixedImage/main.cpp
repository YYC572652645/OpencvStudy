#include <iostream>
#include <QImage>
#include "opencv2/opencv.hpp"
#include <QCoreApplication>

// 图像混合，相当于opencv中的addWeighted函数
void mixedImage(const QImage& first, double alpha, const QImage &last, double beta, QImage &dst)
{
    if (first.width() != last.width() || first.height() != last.height())
    {
        return;
    }

    dst = QImage(first.width(), first.height(), QImage::Format_RGB888);
    for (int i = 0; i < first.width(); i ++)
    {
        for (int j = 0; j < first.height(); j++)
        {
            QColor firstColor = first.pixelColor(i, j);
            QColor lastColor = last.pixelColor(i, j);

            int red = static_cast<int> (alpha * firstColor.red() + beta * lastColor.red());
            int green = static_cast<int> (alpha * firstColor.green() + beta * lastColor.green());
            int blue = static_cast<int> (alpha * firstColor.blue() + beta * lastColor.blue());
            dst.setPixelColor(i, j, QColor(red, green, blue));
        }
    }

}


int main()
{
    cv::Mat matFirst= cv::imread("first.jpg", cv::IMREAD_COLOR);
    cv::Mat matLast = cv::imread("last.jpg", cv::IMREAD_COLOR);

    if (matFirst.empty() || matLast.empty())
    {
        std::cout << "load image error ...";
        return -1;
    }

    cv::Mat matDst;
    if (matFirst.rows == matLast.rows && matLast.cols == matLast.cols)
    {
        cv::addWeighted(matFirst, 0.3, matLast, 0.7, 0, matDst);
        cv::imshow("Mix Image", matDst);

        cv::add(matFirst, matLast, matDst);
        cv::imshow("Mix1 Image", matDst);

        cv::multiply(matFirst, matLast, matDst);
        cv::imshow("Mix2 Image", matDst);
    }

    QImage firstImage("first.jpg");
    QImage lastImage("last.jpg");
    QImage dstImage;

    mixedImage(firstImage, 0.3, lastImage, 0.7, dstImage);
    dstImage.save("mixed.jpg");

    cv::waitKey(0);
    return 0;
}
