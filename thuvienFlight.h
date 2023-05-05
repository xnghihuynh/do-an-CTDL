#pragma once
#include"ThuVienTime.h"
#include"Filetong.h"

//==THONG TIN 1 CBAY==//
struct flight 
{
	char MaChuyenBay[10];
	char SanBayDen[20];
	char SoHieuMB[15];
	DateTime ThoiGianDi;
	int TrangThai;
	int TongSoVe ;
	int TongSoVeDaBan ;
	//Ticket *TicketList;
};
 typedef struct flight Flight ;
//== DANH SACH CHUYEN BAY -- LKDON==/
struct flightnode
{
	Flight data;
	struct flightnode *pNext ;
};
typedef struct flightnode FlightNode ;

struct flightlist 
{
	FlightNode *pHead;
	FlightNode *pTail;
	int SoLuongChuyenBay;
};
typedef struct flightlist FlightList;

void InputFlight(Flight &F)
void KhoiTaoFlight(Flight &F); // khoi tao 1chuyen bay 
void KhoiTaoFlightList(FlightList &FL); // khoi tao ds cbay
FlightNode *CreatFlightNode (Flight Data) ; // tao node cbay
void InsertFristList(FlightList &FL, Flight Data ); // them 1cb vao dau dscb
void InsertLastList(FlightList &FL, Flight Data ); 
int FindIndexFlight(FlightList FL,const char *MaChuyenBayCanTim ); // tim vi tri theo mcb trong ds
int FindDestination(FlightList FL,const char *SanBayCanTim);  
FlightNode *FindFlight(FlightList FL, const char *MaChuyenBayCanTim); // tim mot cbay theo mcb trong ds
FlightNode *FindByOrdinal(FlightList FL, int ordinal ); // tim 1cb theo thu tu
void InputDateTime(DateTime &DT); //int ordinal); // nhap thong tin ngay gio cho doi tuongDatetime , ordinal la vitri khi nhap
bool DeleteFirst(FlightList &FL );
bool DeleteLast(FlightList &FL);
bool DeleteAfter(FlightList &FL, FlightNode *TempoFlight ); // xoa mot cbay sau mot cbay khac ( giua)
bool DeleteFollowIDFlight(FlightList &FL, const char *MaChuyenBayCanXoa); // xoa theo id
bool ClearFlightList(FlightList &FL); // xoa bo nho 
void StatusFlight(FlightList &FL); // tu dong cap nhat trang thai cbay
void TicketChairBoard(Flight F); // hien thi bang ghe ve cua 1 cbay
//void EffectTicketMenu (int index,int PreColor)// hieuung menu 
int ChooseTicket(Flight &F ); // chon 1 ve tu cbay
void ShowFlight(Flight F, int position ); // show 1cb
void ShowFlightList(FlightList FL ); // show ds cbay
void ShowFlightListPerPage(FlightList FL, int StartIndex); // show theo trang
void ChangePageManageFlightList(FlightList FL ); // doi trang khi quanly cbay
bool FlightDataIsEmpty(Flight F); // ktra dulieu cua chuyen bay rong or not
void InputFlight(FlightList &FL,bool EditedOrNot = false, bool DeleteOrNot=false); // nhap info cho 1 bay + them vao ds , xoa or sua maybay hien co
void MenuManageFlightList(FlightList &FL); // show menu quan ly
int CheckOut(Flight F , int x); // ktra ghe trencbay co san de dat or not




