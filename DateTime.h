#pragma once
#include <ctime>

using namespace std;

struct datetime {
	int y ;
	int m ;
	int d;
	int h; // gio
	int mi; // phut
};
typedef struct datetime DateTime ;
void KhoiTaoDateTime( DateTime &DT); // khoi tao du lieu cho bien DateTime , lay d/m
bool TestFormatDateTime( DateTime dt ); // ktra ding dang d/m/y;
bool TestValidDateTime( DateTime dt ) ; // ktra d/m/y co hop le 0;
void OutputDateTime( DateTime &dt); // xuat d/m/y ;
bool CompareDate( DateTime dt1, DateTime dt2) ; // ssanh 2 d/m/y;


