#include<conio.h>
#include <iostream>
#include <string.h>
#include<stdio.h>
#define MAX 100
using namespace std;
 
struct HanhKhach {
    int stt;
    int sove;
    int cmnd;
    int chuyenbay;
    char ten[30];
    char gioitinh[5];
};
 
typedef HanhKhach HK;
 
void printLine(int n);
void nhapThongTinHK(HK &hk);
void nhapHK(HK a[], int n);
void showHK(HK a[], int n);
int docFile(HK a[], char fileName[]);
void ghiFile(HK a[], int n, char fileName[]);
void pressAnyKey();

 
int main() {
    int key;
    char fileName[] = "hanhkhach.txt";
    HK arrayHK[MAX];
    int soluongHK = 0;
     
    // nhap danh sach hanh khach tu file
    soluongHK = docFile(arrayHK, fileName);
 
    while(true) {
        cout << "DANH SACH HANH KHACH THUOC CHUYEN BAY\n ";
        cout << "*************************MENU**************************\n";
        cout << "**  1. Them hanh khach.                              **\n";
        cout << "**  2. Hien thi danh sach hanh khach.                **\n";
        cout << "**  3. Ghi danh sach sinh vien vao file.             **\n";
        cout << "**  0. Thoat                                         **\n";
        cout << "*******************************************************\n";
        cout << "Nhap tuy chon: ";
        cin >> key;
        switch(key){
            case 1:
                cout << "\n1. Them hanh khach.";
                nhapHK(arrayHK, soluongHK);
                printf("\nThem hanh khach thanh cong!");
                soluongHK++;
                pressAnyKey();
                break;
                
            case 2:
                if(soluongHK > 0){
                    cout << "\n2. Hien thi danh sach hanh khach.";
                    showHK(arrayHK, soluongHK);
                }else{
                    cout << "\nDanh sach hành khách trong!";
                }
                pressAnyKey();
                break;
                
            case 3:
                if(soluongHK > 0){
                    cout << "\n3. Ghi danh sach hanh khach vao file.";
                    ghiFile(arrayHK, soluongHK, fileName);
                }else{
                    cout << "\nSanh sach hanh khach trong!";
                }
                printf("\nGhi danh sach hanh khach vao file %s thanh cong!", fileName);
                pressAnyKey();
                break;
            case 0:
                cout << "\nThoat chuong trinh!";
                getch();
                return 0;
            default:
                cout << "\nKhong co chuc nang nay!";
                cout << "\nHay chon chuc nang trong hop menu.";
                pressAnyKey();
                break;
        }
    }
}
  
void nhapThongTinSV(HK &hk) {
    cout << "\n Nhap ten: "; fflush(stdin); gets(hk.ten);
    cout << " Nhap gioi tinh: "; gets(hk.gioitinh);
    cout << " Nhap Chuyen Bay: "; cin >> hk.chuyenbay;
    cout << " Nhap CMND: "; cin >> hk.cmnd;
	cout << " Nhap so ve: "; cin >> hk.sove;
	
}
 
void nhapHK(HK a[], int n) {
    printLine(40);
    printf("\n Nhap sinh vien thu %d:", n + 1);
    nhapThongTinSV(a[n]);
    printLine(40);
}
 
void showHK(HK a[], int n) {
    printLine(100);
    cout <<"\n\STT\tCMND\tHo va ten\tGioi tinh\tChuyen bay";
    for(int i = 0; i < n; i++) {
        // in sinh vien thu i ra man hinh
        printf("\n %d", i + 1);
        printf("\t%d", a[i].cmnd);
        printf("\t%s", a[i].ten);
        printf("\t\t%s", a[i].gioitinh);
        printf("\t\t%d", a[i].chuyenbay);
    }
    printLine(100);
}

int docFile(HK a[], char fileName[]) {
    FILE * fp;
    int i = 0;
    fp = fopen (fileName, "r");
    cout << "Chuan bi doc file: "; puts(fileName);
    // doc thong tin hanh khach
    while (fscanf(fp, "%5d%30s%5s%5d\n", &a[i].cmnd, &a[i].ten, &a[i].gioitinh, &a[i].chuyenbay) != EOF )
	{
       i++;
       cout << " Doc ban ghi thu: " << i << endl;
    }
    cout << " So luong hanh khach co san trong file la: " << i << endl;
    cout << endl;
    fclose (fp);
    // tra ve so luong hanh khach duoc doc tu file
    return i;
}
 
void ghiFile(HK a[], int n, char fileName[]) {
    FILE * fp;
    fp = fopen (fileName,"w");
    for(int i = 0;i < n;i++){
        fprintf(fp, "%5d%30s%5s%5d\n", a[i].cmnd, a[i].ten,a[i].gioitinh,a[i].chuyenbay);
    }
    fclose (fp);
}
 
void printLine(int n) {
    cout << endl;
    for (int i = 0; i < n; i++) {
        cout << "_";
    }
    cout << endl;
}
 
void pressAnyKey() {
    cout << "\n\nBam phim bat ky de tiep tuc...";
    getch();
    system("cls");
}
