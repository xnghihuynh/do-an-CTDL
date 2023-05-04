#include <bits/stdc++.h>
#include <conio.h>
#include <mylib.h>
using namespace std;

void doiKichThuocConsole(int width, int height)
{
	HWND console = GetConsoleWindow();
	RECT r;
	GetWindowRect(console, &r);
	MoveWindow(console, r.left, r.top, width, height, TRUE);
}

void hopChon(int x, int y, int cao, int rong, int mauChu, string noiDung){
	SetColor(9);
	for(int ix = x; ix <= x+rong; ix++){
		gotoxy(ix, y);
		cout << char(196);
		gotoxy(ix, y+cao);
		cout << char(196);
	}
	for (int iy = y; iy <= y+cao; iy++){
		gotoxy(x, iy);
		cout << char(179);
		gotoxy(x+rong, iy);
		cout << char(179);
	}
	gotoxy(x, y);
	cout << char(218);
	gotoxy(x+rong, y);
	cout << char(191);
	gotoxy(x, y+cao);
	cout << char(192);
	gotoxy(x+rong, y+cao);
	cout << char(217);
	
	SetColor(mauChu);
	gotoxy(x+2, y+1);
	cout << noiDung;
}

void hangMayBay(int x, int y, int cao, int rong){
	for(int ix = x; ix <= rong; ix++){
		for(int iy = y; iy <= cao; iy++){
			SetBGColor(9);
			gotoxy(ix, iy);
			cout << " ";
		}	
	}
	SetColor(15);
	gotoxy(2, 1);
	cout << "47 AIRLINES";
	gotoxy(105, 1);
	cout << "YOUR HAPPINESS IS OUR PRIDE";
	SetBGColor(0);
}

void danhSachChucNangMayBay(string &noiDung, int soLuong){
	switch(soLuong){
		case 0:{
			noiDung = "Them may bay vao danh sach";
			break;
		}
		case 1:{
			noiDung = "Xuat danh sach may bay";
			break;
		}
		case 2:{
			noiDung = "Xoa may bay";
			break;
		}
		case 3:{
			noiDung = "Sua thong tin may bay";
			break;
		}
	}
	soLuong++;
}

void nHopChonMayBay(int x, int y, int cao, int rong, int mauChu, int sl){
	string noiDung;
	for(int i = 0; i < sl; i++){
		danhSachChucNangMayBay(noiDung, i);
		hopChon(x, y+(i*cao), cao, rong, mauChu, noiDung);
		if(i!=0){
			SetColor(9);
			gotoxy(x, y+(i*cao));
			cout << char(195);
			gotoxy(x+rong, y+(i*cao));
			cout << char(180);
			gotoxy(x, y+cao+(i*cao));
			cout << char(192);
		}
	}
}

void menuMayBay(){
	nHopChonMayBay(50, 10, 2, 30, 14, 4);
}

void danhSachChucNangChinh(string &noiDung, int soLuong){
	switch(soLuong){
		case 0:{
			noiDung = "Quan ly may bay";
			break;
		}
		case 1:{
			noiDung = "Quan ly chuyen bay";
			break;
		}
	}
	soLuong++;
}

void hopChonChinh(int x, int y, int cao, int rong, int mauChu, string noiDung){
	SetColor(9);
	for(int ix = x; ix <= x+rong; ix++){
	gotoxy(ix, y);
	cout << char(196);
	gotoxy(ix, y+cao);
	cout << char(196);
	}	
	SetColor(0);
	for(int iy = y; iy <= y+cao; iy++){
		gotoxy(x, iy);
		cout << char(179);
		gotoxy(x+rong, iy);
		cout << char(179);
	}
	
	SetColor(mauChu);
	gotoxy(x+24, y+1);
	cout << noiDung;
}

void nHopChonChinh(int x, int y, int cao, int rong, int mauChu, int sl){
	string noiDung;
	for(int i = 0; i < sl; i++){
		danhSachChucNangChinh(noiDung, i);
		hopChonChinh(x+(i*rong), y, cao, rong, mauChu, noiDung);
		if(i!=0){
			SetColor(9);
			for(int iy = y; iy <= y+cao; iy++){
				gotoxy(x+(i*rong), iy);
				cout << char(179);
			}
			gotoxy(x+rong, y);
			cout << char(194);
			gotoxy(x+rong, y+cao);
			cout << char(193);
		}
	}
}

void menuChinh(){
	doiKichThuocConsole(1000, 600);
	hangMayBay(0, 0, 2, 133);
	nHopChonChinh(0, 3, 2, 66, 14, 2);
	gotoxy(48, 14);
	cout << "Chon";
	gotoxy(86, 14);
	cout << "Thoat";
	hopChon(38, 13, 2, 8, 9, "ENTER");
	hopChon(78, 13, 2, 6, 9, "ESC");
	cout << endl;
}

int main(){
	menuChinh();
	return 0;
}
