#include "opcv.h"
#include <opencv2/opencv.hpp>
#include <iostream>

int main()
{
	using namespace std;
	opcv x;
	int xw = 0,yh=0;
	for (int i = 0; i < 100; i++)
	{
		cout << x.readx(xw,yh) << "\t"
			 << xw <<"\t"<<yh<< endl;
	}
	return 0;
}
