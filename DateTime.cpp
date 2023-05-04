//#pragma once ( tat cho khoi canh bao)
#include <ctime> // dung cho ngay gio
#include "DateTime.h"
#include "Filetong.h"
//#include " UserInterfaceTP.h"

int nDayOfMonth[13]= { 0,31,28,31,30,31,30,31,31,30,31,30,31} ;
// khoi tao mang so ngay moi thang , vidu thang 1 31 ngay...
void KhoiTaoDateTime( DateTime &DT) 
{
	time_t baygio = time(0); // time he thong
	tm* ltm = localtime(&baygio) ; //* con tro the hien time he thong
	DT.h = ltm->tm_hour;
	DT.mi=ltm->tm_min ;
	DT.d=ltm->tm_mday;
	DT.m=1+ltm->tm_mon; 
	DT.y= 1990+ltm->tm_year; 	
}
bool TestFormatDateTime (DateTime dt) 
{
	nDayOfMonth[2]= 28; // cho thang 2 co 28 ngay
 	if ((dt.y %400==0) || (dt.y %4==0 && dt.y %100 != 0))
	 	{
 			nDayOfMonth[2]= 29; // nhuan thi = 29
		 }
	if (dt.d > nDayOfMonth[dt.m]) // ktra so ngay nhap co lon hon so ngay mac dinh khong
		return false ;
	return true; 
}
// ktra dinh dang gio phu hop voi d/m/y . return true -> nhap dung
bool TestValidDateTime(DateTime dt)
{
	if(TestFormatDateTime(dt)) {} else return false ;  // ktra ham right dung kh , dung thi thuc hien{}
	
	nDayOfMonth[2]=28;
	time_t baygio= time(0);
	tm *ltm= localtime(&baygio);
	DateTime dtNow ;
	dtNow.y = 1990 + ltm->tm_yday;
	dtNow.m= 1+ltm->tm_mon;
	dtNow.d= ltm->tm_mday;
	dtNow.h= ltm->tm_hour;
	dtNow.mi= ltm->tm_min;
	// tra ve false neu nhu 
	if (dt.y<dtNow.y) return false ; // nam nhap vao nho hon macdinh
	if ((dt.y==dtNow.y)&&(dt.m<dtNow.m)) return false ; // thang < thang macdinh
	if ((dt.y%400==0)||(dt.y %4==0)&&(dt.y%100!=0))
			nDayOfMonth[2]=29;
	if (dt.y==dtNow.y && dt.m==dtNow.m && dt.d<dtNow.d) return false;//ngay<
	if (dt.y==dtNow.y && dt.m==dtNow.m && dt.d==dtNow.d && dt.h<dtNow.h) return false ; //gio
	if (dt.y==dtNow.y && dt.m==dtNow.m && dt.d<dtNow.d && dt.h<dtNow.h && dt.mi <=dtNow.mi) return false ;
	return true ; 	
}

void OutputDateTime( DateTime &dt) 
{
	cout<< dt.h << ":"<<dt.mi<<" "<< dt.d << "/"<<dt.m<<"/"<<dt.y;
}
bool CompareDate(DateTime dt1,DateTime dt2)
{
	return dt1.d == dt2.d && dt2.m == dt1.m && dt1.y == dt2.y;

}

// CHAY THU NHO XOA 

//int main() {
//    DateTime dt;
//    cout << "Nhap ngay: ";
//    cin >> dt.d;
//    cout << "Nhap thang: ";
//    cin >> dt.m;
//    cout << "Nhap nam: ";
//    cin >> dt.y;
//    cout << "Nhap gio: ";
//    cin >> dt.h;
//    cout << "Nhap phut: ";
//    cin >> dt.mi;
//    if (TestFormatDateTime(dt)){
//		cout << "nam nhuan "<< endl;
//	} else {
//		cout << " khong nhuan "<< endl;
//	}
//	if (TestValidDateTime(dt)){
//		cout << "dung dinh dang "<< endl;
//	} else {
//		cout << " sai dinh dang "<< endl;
//	}
//    cout << "Ngay thang da nhap: ";
//    OutputDateTime(dt);
//    cout << endl;
//    return 0;
//}
