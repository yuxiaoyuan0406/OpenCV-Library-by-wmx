
#include "opcv.h"
#include <opencv2/opencv.hpp>
#include <iostream>
//#include <stdio.h>
#include <raspicam/raspicam_cv.h>

opcv::opcv()
{
	/*	
	Camera.set(CV_CAP_PROP_FRAME_WIDTH, 640);
	Camera.set(CV_CAP_PROP_FORMAT, CV_8UC3);
	Camera.set(CV_CAP_PROP_GAIN, 30);
	Camera.set(CV_CAP_PROP_SATURATION, 80);
	Camera.set(CV_CAP_PROP_CONTRAST, 90);
	Camera.set(CV_CAP_PROP_EXPOSURE, 10);
*/
	Camera.set(CV_CAP_PROP_FRAME_WIDTH, 640);
	Camera.set(CV_CAP_PROP_FRAME_HEIGHT, 480);
	Camera.set(CV_CAP_PROP_FORMAT, CV_8UC3);
	Camera.set(CV_CAP_PROP_BRIGHTNESS, 20);
	Camera.set(CV_CAP_PROP_GAIN, 20);
	Camera.set(CV_CAP_PROP_SATURATION, 90);
	Camera.set(CV_CAP_PROP_CONTRAST, 90);
	Camera.set(CV_CAP_PROP_EXPOSURE, 12);
	Camera.open();
}

int opcv::readx(int &xw)
{
	using namespace cv;
	using namespace std;
	//using namespace raspicam;
	//
	//RaspiCam_Cv Camera; //Camera object
	//Camera.set(CV_CAP_PROP_FRAME_WIDTH,640);
	//Camera.set(CV_CAP_PROP_FORMAT, CV_8UC3);
	//Camera.set(CV_CAP_PROP_BRIGHTNESS,0);
	//Camera.set(CV_CAP_PROP_GAIN,30);
	//Camera.set(CV_CAP_PROP_SATURATION,80);
	//Camera.set(CV_CAP_PROP_CONTRAST,90);
	//Camera.set(CV_CAP_PROP_EXPOSURE,10);
	//Camera.set(CV_CAP_PROP_WHITE_BALANCE_RED_V,1);
	//Camera.set(CV_CAP_PROP_WHITE_BALANCE_BLUE_U,1);
	//Camera.set(CV_CAP_PROP_FPS,1);

	//
	int k = 1;
	int x1 = -1;
	int x2 = -1;
	int sum1 = 0, sum2 = 0, count1 = 1, count2 = 1, temp = 0;
	Mat image;
	//image = imread("C:/Users/������/Desktop/b.jpg");

	//VideoCapture capture(0);
	//capture >> image;
	//printf("%d\n", image.cols);

	//Camera.open();

	Camera.grab();
	Camera.retrieve(image);
	//Camera.release();

	for (int i = 0; i < image.rows; i++)
	{
		for (int j = 0; j < image.cols; j++)
		{

			uchar *data1 = image.ptr<uchar>(i, j); // �������ֵ

			if (data1[0] < 50 && data1[1] < 50 && data1[2] > 230)
			//ע�������012��Ӧ����bgr����Χ����˼�Ƿ�ֹ���ߵ�����Ӱ�죬�����ʵ��ſ�������Ҳ����ѡ����������ɫ�ռ䣬����ֱ��ȡ������Ӱ�죬����HSV
			{
				if (k == 1)
				{
					x1 = j;
					k = 2;
				}
			}

			if (data1[0] < 50 && data1[1] < 50 && data1[2] < 230)
			{
				if (k == 2)
				{
					x2 = (j - 1);
					k = 3;
				}
				if (k == 3)
				{
					int x3 = (x1 + x2) / 2;
					uchar *data2 = image.ptr<uchar>(i, x3);

					if (data2[0] < 50 && data2[1] < 50 && data2[2] > 230)
					{
						sum1 += x3;
						count1++;
						if (temp < (x2 - x1))
						{
							temp = (x2 - x1);
						}
						//printf("%d\t%d\t%d\n", x3, sum1, count1);
					}
					k = 1;
					x1 = -1;
					x2 = -1;
				}
			}
			else
			{
			}
		}
		k = 1;
		x1 = -1;
		x2 = -1;
	}
	imwrite("image.jpg", image);
	xw = temp;
	if (count1 == 1)
	{
		cout << -1 << endl;
		return -1;
	}
	else
	{
		cout << "light found at " << (sum1 / (count1 - 1)) << endl;
		return sum1 / (count1 - 1);
	}
}

opcv::~opcv()
{ /*
	using namespace std;
	cout << Camera.get(CV_CAP_PROP_FRAME_WIDTH) << endl
		 << Camera.get(CV_CAP_PROP_FRAME_HEIGHT) << endl
		 << Camera.get(CV_CAP_PROP_BRIGHTNESS) << endl
		 << Camera.get(CV_CAP_PROP_GAIN) << endl
		 << Camera.get(CV_CAP_PROP_SATURATION) << endl
		 << Camera.get(CV_CAP_PROP_CONTRAST) << endl
		 << Camera.get(CV_CAP_PROP_EXPOSURE) << endl
		 << Camera.get(CV_CAP_PROP_WHITE_BALANCE_RED_V) << endl
		 << Camera.get(CV_CAP_PROP_WHITE_BALANCE_BLUE_U) << endl
		 << Camera.get(CV_CAP_PROP_FPS) << endl;

	Camera.release();*/
}
