#include <opencv2/opencv.hpp>
#include <iostream>

// 画线
void drawLine(cv::Mat &imageMat)
{
    cv::Point startPoint(0, 0);
    cv::Point endPoint(300, 300);
    cv::Scalar colorScalar(20, 20, 100);

    cv::line(imageMat, startPoint, endPoint, colorScalar, 1, cv::LINE_4);
}

// 画矩形
void drawRect(cv::Mat &imageMat)
{
    cv::Point startPoint(300, 50);
    cv::Point endPoint(680, 500);
    cv::Scalar colorScalar(20, 20, 100);

    cv::rectangle(imageMat, startPoint, endPoint, colorScalar, 2, cv::LINE_4);
}

// 画圆形
void drawCircle(cv::Mat &imageMat)
{
    cv::Point centerPoint(500, 300);
    int radius = 50;
    cv::Scalar colorScalar(20, 20, 100);

    cv::circle(imageMat, centerPoint, radius, colorScalar, 2, cv::LINE_4);
}

// 画椭圆
void drawEllipse(cv::Mat &imageMat)
{
    cv::RotatedRect rotateRect(cv::Point2f(500, 500), cv::Size2f(80, 80), 90);
    cv::Scalar colorScalar(20, 20, 100);

    cv::ellipse(imageMat, rotateRect, colorScalar, 2, cv::LINE_4);
}

// 画路径填充
void drawPolyon(cv::Mat &imageMat)
{
    std::vector<std::vector<cv::Point>> dataVectorArray;
    std::vector<cv::Point> dataVector;

    dataVector.push_back(cv::Point(0, 0));
    dataVector.push_back(cv::Point(20, 0));
    dataVector.push_back(cv::Point(30, 10));
    dataVector.push_back(cv::Point(40, 30));
    dataVector.push_back(cv::Point(50, 100));

    dataVectorArray.push_back(dataVector);

    cv::Scalar colorScalar(20, 20, 100);
    cv::fillPoly(imageMat, dataVectorArray, colorScalar, cv::LINE_4);
}


// 画文本
void drawText(cv::Mat &imageMat)
{
    cv::Point orgPoint(680, 500);
    cv::Scalar colorScalar(20, 200, 200);

    cv::putText(imageMat, "Beautiful Girl", orgPoint, cv::FONT_HERSHEY_SCRIPT_COMPLEX, 1.0, colorScalar);
}

// 主函数入口
int main()
{
    cv::Mat srcMat = cv::imread("test.jpg");

    if (srcMat.empty())
    {
        std::cout << "error" << std::endl;
        return -1;
    }

    drawLine(srcMat);

    drawRect(srcMat);

    drawCircle(srcMat);

    drawEllipse(srcMat);

    drawPolyon(srcMat);

    drawText(srcMat);

    cv::imshow("SrcMat", srcMat);

    cv::waitKey(0);

    return 0;
}

