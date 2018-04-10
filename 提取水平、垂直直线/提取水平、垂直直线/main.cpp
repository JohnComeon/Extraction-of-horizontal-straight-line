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

	//������ͼ��ת��Ϊ�Ҷ�ͼ��
	cvtColor(src, graysrc, CV_BGR2GRAY);     
	imshow("gray image", graysrc);
	//imwrite("C:\\IMAGE\\8grayImg.png", graysrc);
	
	//�ѻҶ�ͼ��ת��Ϊ��ֵͼ��(	�ر�ע�⣺Ҫ�Ȱѱ���ת��Ϊ��ɫ	)
	adaptiveThreshold(~graysrc, binImg, 255, ADAPTIVE_THRESH_MEAN_C, THRESH_BINARY, 7, -2);   
	imshow("binary image", binImg);
//	imwrite("C:\\IMAGE\\8binaryImg.png", binImg);
	
	//����ṹԪ�أ�ˮƽ����
	Mat xline = getStructuringElement(MORPH_RECT, Size(23, 1), Point(-1, -1));
	//����ṹԪ�أ���ֱ����
	Mat yline = getStructuringElement(MORPH_RECT,Size(1,23),Point(-1,-1));
	//�������ṹ
	Mat kernel = getStructuringElement(MORPH_RECT,Size(3,3),Point(-1,-1));

	//���п�����
	morphologyEx(binImg,dst,MORPH_OPEN, kernel);
	//Mat temp;
	//erode(binImg,temp,xline);
	//dilate(temp,dst, xline);
	bitwise_not(dst,dst);        //��ͼ��ȡ������Ϊ��ɫ���������Ӻÿ���
	//blur(dst,dst,Size(3,3),Point(-1,-1));        //��ͼ�����ģ�������Ӻÿ���
	imshow("final image",dst);
	//imwrite("C:\\IMAGE\\7final.png", dst);
	waitKey(0);
	return 0;
}