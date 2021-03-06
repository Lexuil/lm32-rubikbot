#ifndef CAM_H
#define CAM_H

const int GET_SIZE [5]         = {0x56, 0x00, 0x34, 0x01, 0x00};
const int QUICK_SERIAL [7]     = {0x56 ,0x00 ,0x24 ,0x03 ,0x01 ,0x0D ,0xA6};
const int RESET_CAMERA [4]     = {0x56, 0x00, 0x26, 0x00};
const int TAKE_PICTURE [5]     = {0x56, 0x00, 0x36, 0x01, 0x00};
const int STOP_TAKING_PICS [5] = {0x56, 0x00, 0x36, 0x01, 0x03};
const int SEND_JPG [12] = {0x56 ,0x00 ,0x32 ,0x0C ,0x00 ,0x0A ,0x00 ,0x00 ,0x00 ,0x00 ,0x00 ,0x00};

#include "soc-hw.h"

class  cam{

public:
	void reset();
	void takepicture();
	void sendpicture();
	void getsize();
	void stoptaking();
private:
	uint32_t xh,xl;
};





#endif