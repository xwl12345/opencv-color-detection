#include "readImage.h"

bool readImage::getMat(std::string path)
{
	//读取图片
	cv::Mat target = cv::imread(path);
	if (target.empty())
	{
		std::cout << "读取失败" << std::endl;
		return false;
	}
	std::cout << target.rows <<std::endl;
	std::cout << target.cols << std::endl;
	//BGR转化为HSV
	cv::Mat hsv;
	cv::cvtColor(target, hsv, cv::COLOR_BGR2HSV);
	//获取掩膜
	cv::Mat mask;
	cv::inRange(hsv,cv::Scalar(100, 50, 50), cv::Scalar(130,255,255),mask);

	cv::imshow("mask1", mask);

	//创建3*3椭圆核来做开运算去噪点
	cv::Mat kernel = cv::getStructuringElement(cv::MORPH_ELLIPSE, cv::Size(3, 3));
	cv::morphologyEx(mask, mask, cv::MORPH_OPEN, kernel);
	//获取轮廓
	std::vector<std::vector<cv::Point>> contours;
	cv::findContours(mask, contours, cv::RETR_EXTERNAL, cv::CHAIN_APPROX_SIMPLE);
	std::cout << contours.size() << std::endl;
	cv::imshow("origin", target);
	cv::imshow("hsv", hsv);
	cv::imshow("mask", mask);
	cv::waitKey(0);
	cv::destroyAllWindows();
	return true;
}
