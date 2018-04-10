#include <opencv2/opencv.hpp>
#include <iostream>
using namespace cv;

int elementsize = 3;
int maxsize = 21;
char Outputwin[] = "output image";

Mat src,graysrc,binImg,dst;
int main()
{
	src = imread("C:\\IMAGE\\8.png");
	if (!src.data)
	{
		printf("could not load...");
		return -1;
	}
	namedWindow("input image", CV_WINDOW_AUTOSIZE);
	imshow("input image", src);

	//把输入图像转换为灰度图像
	cvtColor(src, graysrc, CV_BGR2GRAY);     
	imshow("gray image", graysrc);
	//imwrite("C:\\IMAGE\\8grayImg.png", graysrc);
	
	//把灰度图像转换为二值图像(	特别注意：要先把背景转换为黑色	)
	adaptiveThreshold(~graysrc, binImg, 255, ADAPTIVE_THRESH_MEAN_C, THRESH_BINARY, 7, -2);   
	imshow("binary image", binImg);
//	imwrite("C:\\IMAGE\\8binaryImg.png", binImg);
	
	//定义结构元素（水平方向）
	Mat xline = getStructuringElement(MORPH_RECT, Size(23, 1), Point(-1, -1));
	//定义结构元素（垂直方向）
	Mat yline = getStructuringElement(MORPH_RECT,Size(1,23),Point(-1,-1));
	//定义矩阵结构
	Mat kernel = getStructuringElement(MORPH_RECT,Size(3,3),Point(-1,-1));

	//进行开操作
	morphologyEx(binImg,dst,MORPH_OPEN, kernel);
	//Mat temp;
	//erode(binImg,temp,xline);
	//dilate(temp,dst, xline);
	bitwise_not(dst,dst);        //对图像取反，变为白色背景（更加好看）
	//blur(dst,dst,Size(3,3),Point(-1,-1));        //对图像进行模糊（更加好看）
	imshow("final image",dst);
	//imwrite("C:\\IMAGE\\7final.png", dst);
	waitKey(0);
	return 0;
}