#pragma once

#include <raspicam/raspicam_cv.h>

class opcv
{
	public:
		int readx(int &xw);
		int readx(int &xw, int &yh);
		opcv();
		~opcv();

private:
	raspicam::RaspiCam_Cv Camera; //Camera object
};
