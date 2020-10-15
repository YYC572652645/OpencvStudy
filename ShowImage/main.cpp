#include <opencv2/opencv.hpp>
#include <iostream>
#include <QDebug>

int main()
{
    QByteArray envPath = qgetenv("PATH");
    envPath += ";D:\\Program\\OpencvStudy\\dll";

    qputenv("PATH", envPath);
    qunsetenv("PATH");

    // 读取图片
    // IMREAD_UNCHANGED (<0) 表示加载原图，不做任何改变
    // IMREAD_GRAYSCALE (0)表示把原图作为灰度图像加载进来
    // IMREAD_COLOR (>0) 表示把原图作为RGB图像加载进来
    cv::Mat image = cv::imread("test.jpg");

    if (image.empty())
    {
        std::cout << "error";
        return -1;
    }

    // 设置窗口根据图形大小改变
    cv::namedWindow("ShowImage", CV_WINDOW_AUTOSIZE);

    // 显示图片窗口
    cv::imshow("ShowImage", image);

    // 设置窗口根据图形大小改变
    // WINDOW_AUTOSIZE会自动根据图像大小，显示窗口大小，不能人为改变窗口大小
    // WINDOW_NORMAL,跟QT集成的时候会使用，允许修改窗口大小。
    cv::namedWindow("Modefied Image", CV_WINDOW_AUTOSIZE);

    cv::Mat modefiedImage;

    // 转为灰度图像
    cv::cvtColor(image, modefiedImage, CV_BGR2GRAY);

    // 显示图片窗口
    cv::imshow("Modefied Image", modefiedImage);

    // 保存图片
    cv::imwrite("modefiedImage.jpg", modefiedImage);

    // 等待键盘点击退出
    cv::waitKey(0);
    return 0;
}
