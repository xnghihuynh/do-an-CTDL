#include <bits/stdc++.h>
#include <conio.h>

using namespace std;

//may bay
class MayBay{
	private:
		string soHieu;
		string loai;
		int soDay;
		int soDong;
	public:
//ham khoi tao may bay
		MayBay(){}
		MayBay(string soHieu, string loai, int soDay, int soDong){
			MayBay::soHieu = soHieu;
			MayBay::loai = loai;
			MayBay::soDay = soDay;
			MayBay::soDong = soDong;
		}
		
//setter may bay
		void setSoHieu(string soHieu){
			MayBay::soHieu = soHieu;
		}
		void setLoai(string loai){
			MayBay::loai = loai;
		}
		void setSoDay(int soDay){
			MayBay::soDay = soDay;
		}
		void setSoDong(int soDong){
			MayBay::soDong = soDong;
		}
		
//getter may bay
		string getSoHieu(){
			return soHieu;
		}
		string getLoai(){
			return loai;
		}
		int getSoDay(){
			return soDay;
		}
		int getSoDong(){
			return soDong;
		}
		
//nhap may bay
		void nhap(string soHieu){
			MayBay::soHieu = soHieu;
			cout << "Loai may bay: ";
			getline(cin, loai);
			do{
				cout << "So day: ";
				cin >> soDay;
				cout << "So dong: ";
				cin >> soDong;
				cout << "So cho: " << soDay*soDong << endl;
				if(soDay*soDong < 20){
					cout << "So cho phai >= 20. Vui long nhap lai.\n";
					system("cls");
				}
			}while(soDay*soDong < 20);
		}
		
//xuat may bay
		void xuat(){
			cout << soHieu << "\t\t" << loai << "\t\t" << soDay*soDong << endl;
			//soDay*soDong = so cho
		}
};

//danh sach may bay
#define TOIDA_MAYBAY 300

class DanhSachMayBay{
	private:
		int soLuong = 0;
		MayBay *danhSach[TOIDA_MAYBAY];
	public:
		
//ham tim kiem may bay
		int timMayBay(string soHieu){
			for(int i=0; i<soLuong; i++){
				if(soHieu.compare(danhSach[i]->getSoHieu()) == 0){
					return i;
				}
			}
			return -1;
		}
		
//ham xoa may bay
		int xoaMayBay(MayBay mayBay, string &thongBao){
			int tim = timMayBay(mayBay.getSoHieu());
			if(tim == -1){
				thongBao = "\nSo hieu khong ton tai. Vui long nhap lai.\n";
				return 0;
			}
			for(int i=tim; i<soLuong-1; i++){
				*danhSach[i] = *danhSach[i+1];
			}
			delete danhSach[soLuong-1];
			soLuong--;
			return 1;
		}
		
//ham sap xep may bay
		void sapXepMayBay(){
			for(int i=0; i<soLuong-1; i++){
				for(int j=i+1; j<soLuong; j++){
					if(danhSach[i]->getSoHieu().compare(danhSach[j]->getSoHieu()) > 0){
						MayBay *tmp = danhSach[i];
						danhSach[i] = danhSach[j];
						danhSach[j] = tmp;
					}
				}
			}
		}

//a. Cap nhat danh sach cac may bay
//them may bay
		int themMayBay(MayBay mayBay){
			danhSach[soLuong] = new MayBay(mayBay.getSoHieu(), mayBay.getLoai(), mayBay.getSoDay(), mayBay.getSoDong());
			soLuong++;
			return 1;
		}
		void thucHienThemMayBay(){
			MayBay mayBay;
			string soHieuNhap;
			if(soLuong == TOIDA_MAYBAY){
				cout << "Danh sach day. Khong the them.\n";
				return;
			}
			cout << "//NHAP THONG TIN MAY BAY//\n";
			cout << "So hieu may bay: ";
			fflush(stdin);
			getline(cin, soHieuNhap);
			if(timMayBay(soHieuNhap) != -1){
				cout << "\nSo hieu may bay bi trung. Vui long nhap lai.\n";
				return;
			}
			mayBay.nhap(soHieuNhap);
			themMayBay(mayBay);
			cout << "\nThem thanh cong.\n";
		}
		
//xuat may bay
		void xuatDanhSachMayBay(){
			cout << "//DANH SACH MAY BAY//\n";
			cout << "\nSTT\tSO HIEU\t\tLOAI MAY BAY\tSO CHO\n";
			for(int i=0; i<soLuong; i++){
				cout << i+1 << "\t";
				danhSach[i]->xuat();	
			}
		}
		
//thuc hien xoa may bay
		void thucHienXoaMayBay(){
			MayBay mayBay;
			string thongBao;
			string soHieuNhap;
			if(soLuong == 0){
				cout << "Danh sach rong. Khong the xoa.\n";
				return;
			}
			cout << "//XOA MAY BAY//\n";
			cout << "Nhap so hieu may bay can xoa: ";
			fflush(stdin);
			getline(cin, soHieuNhap);
			mayBay.setSoHieu(soHieuNhap);
			if(xoaMayBay(mayBay, thongBao) == 0){
				cout << thongBao << endl;
				return;
			}
			cout << "\nXoa thanh cong.\n";
		}
		
//sua may bay
		int suaMayBay(MayBay mayBay, int viTri){
			*danhSach[viTri] = mayBay;
		}
		
//thuc hien sua may bay
		void thucHienSuaMayBay(){
			MayBay mayBay;
			string soHieuNhap;
			if (soLuong == 0){
				cout << "Danh sach rong. Khong the sua.\n";
				return;
			}
			cout << "//SUA THONG TIN MAY BAY//\n";
			cout << "Nhap so hieu may bay: ";
			fflush(stdin);
			getline(cin, soHieuNhap);
			mayBay.setSoHieu(soHieuNhap);
			int viTri = timMayBay(mayBay.getSoHieu());
			if(viTri == -1){
				cout << "\nMa so khong ton tai. Vui long nhap lai.\n";
				return;
			}
			mayBay.nhap(soHieuNhap);
			suaMayBay(mayBay, viTri);
			cout << "\nSua thanh cong.\n";
		}

//xoa danh sach may bay
		void xoaDanhSach(){
			while(soLuong>0){
				delete danhSach[soLuong];
				soLuong--;
			}
		}
};

void danhSachChucNangMayBay(){
	cout << "//DANH SACH CHUC NANG//\n";
	cout << "1. Them may bay vao danh sach\n";
	cout << "2. Xuat danh sach may bay\n";
	cout << "3. Xoa may bay\n";
	cout << "4. Sua thong tin may bay\n";
	cout << "0. Ket thuc chuong trinh\n";
	cout << "Nhap so tuong ung de chon: ";
}

void chonChucNangMayBay(){
	DanhSachMayBay ds;
	while(true){
		danhSachChucNang();
		char luaChon = getch();
		system("cls");
		switch(luaChon){
			case '1':{
				ds.thucHienThemMayBay();
				ds.sapXepMayBay();
				break;
			}
			case '2':{
				ds.xuatDanhSachMayBay();
				break;
			}
			case '3':{
				ds.thucHienXoaMayBay();
				break;
			}
			case '4':{
				ds.thucHienSuaMayBay();
				break;
			}
			case '0':{
				cout << "Chuong trinh ket thuc.\n";
				ds.xoaDanhSach();
				return;
			}
		}
		cout << "\n-----------------------------\n";
		cout << "Bam phim bat ky de tiep tuc\n";
		getch();
		system("cls");
	}
	
}

int main(){
	chonChucNangMayBay();
	return 0;
}
