#include"DateTime.h"
#include"thuvienFlight.h"
#include"Filetong.h"

// ham nay co ben Nghi roi nhung van viet 
void InputFlight(Flight &F) {
    cout << "Nhap ma chuyen bay: ";
    cin.ignore();
    cin.getline(F.MaChuyenBay, 10);

    cout << "Nhap san bay den: ";
    cin.getline(F.SanBayDen, 20);

    cout << "Nhap so hieu may bay: ";
    cin.getline(F.SoHieuMB, 15);

    cout << "Nhap thoi gian di:" << endl;
    InputDateAndTimeInfor(F.ThoiGianDi);
}

void KhoiTaoFlight(Flight &F)
{
	F.TongSoVe = 0;
	F.TongSoVeDaBan=0;
	//F.TicketList = new Ticket[100]; // cap phat mang dong
	F.TrangThai=2; // 1:huy, 2 con, 3 het , 4 hoan tat 
	
}
void KhoiTaoFlightList( FlightList &FL)
{
	FL.pHead= NULL;
	FL.pTail= NULL; 
	FL.SoLuongChuyenBay= -1 ; // chua xac dinh
}
// tao moi 1 flightnode chuyenbay
FlightNode *CreateFlightNode(Flight Data) 
{
	FlightNode *tempo = new FlightNode;
	if ( tempo== NULL)
	{
		return NULL ; 
	}
	tempo->data=Data;
	tempo->pNext = NULL ;
	return tempo; 
}
//them dau
void InsertFristList(FlightList &FL, Flight Data)
{
	FlightNode *tempo = CreateFlightNode(Data);
	tempo->pNext= FL.pHead;
	FL.pHead=tempo;
	FL.SoLuongChuyenBay++;
}
void InsertLastList(FlightList &FL, Flight Data)
{
	FlightNode *tempo = CreateFlightNode (Data);
	if (FL.pHead=NULL)
	{
		FL.pHead = FL.pTail=tempo;
	}
	else 
	{
		FL.pTail->pNext=tempo;
		FL.pTail=tempo;
	}
		FL.SoLuongChuyenBay++;
}
// tim so thu tu dua vao machuyenbay
int FindIndexFlight(FlightList FL, const char *MaChuyenBayCanTim)
{
	int index = 0;
	for ( FlightNode *search = FL.pHead;search != NULL;search = search->pNext)
		{
			// so sanh kh phan biet hoa thuong 
			if (_stricmp(search->data.MaChuyenBay,MaChuyenBayCanTim)==0)
			{
				return index;
			}
			index++;
		}
	return -1;
}
int FindDestination(FlightList FL,const char *SanBayCanTim)
{
	int index=0;
	for ( FlightNode *search=FL.pHead;search != NULL; search = search->pNext)
	{
		if (_stricmp(search->data.SanBayDen,SanBayCanTim)==0)
		{
			return index;
		}
		index++;
	}
	return -1;
}
FlightNode *FindFlight( FlightList FL, const char *MaChuyenBayCanTim)
{
	if( FL.pHead == NULL)
	{
		return NULL;
	}
	for ( FlightNode *search=FL.pHead;search != NULL; search = search->pNext)
		{
			if (_stricmp(search->data.MaChuyenBay,MaChuyenBayCanTim)==0)
			{
			return search; // true tra ve con tro tro den ptu do
			}
		}
	return NULL ;
}
void InputDateAndTimeInfor(DateTime &DT)
{
    int DTordinal = 0;
    while( true )
    {
        switch(DTordinal)
        {
            case 0:
                cout << "Nhap gio: ";
                cin >> DT.h;
                if (DT.h >= 0 && DT.h <= 23) DTordinal++;
                break;
            case 1:
                cout << "Nhap phut: ";
                cin >> DT.mi;
                if (DT.mi >= 0 && DT.mi <= 59) DTordinal++;
                break;
            case 2:
                cout << "Nhap ngay: ";
                cin >> DT.d;
                if (DT.d >= 1 && DT.d <= 31) DTordinal++;
                break;
            case 3:
                cout << "Nhap thang: ";
                cin >> DT.m;
                if (DT.m >= 1 && DT.m <= 12) DTordinal++;
                break;
            case 4:
                cout << "Nhap nam: ";
                cin >> DT.y;
                if (DT.y >= 1 && DT.y <= 9999) return;
        }
    }
}
// hieu chinh thoi gian
DateTime DT;
InputDateAndTimeInfor(DT);
	char choice;
	cout << "Ban co muon sua thoi gian khong? (y/n): ";
	cin >> choice;
	if (choice == 'y' || choice == 'Y')
		{
    	InputDateAndTimeInfor(DT);
		}

void DeleteFirst( FlightList &FL)
{
	if ( FL.pHead==NULL ){
		return false; 
	}
	FlightNode *tempo = FL.pHead;
	FL.pHead=FL.pHead->pNext;
	delete tempo;
	FL.SoLuongChuyenBay--;
	return true;
}
void DeleteLast(FlightList &FL)
{
	if (FL.pHead==NULL) {
		return false;
	}
	FlightNode *tempo = NULL;
	for (FlightNode *search = FL.pHead;FL.pHead!=NULL;search=search->pNext)
	{
		if (search = pTail)
		{
			tempo->pNext=NULL;
			FL.pTail= tempo;
			delete search;
			--FL.SoLuongChuyenBay;
			return true;
		}
		tempo=search;
	}
}
// xoa cai nut dung sau tempo 
bool DeleteAfter(FlightList &FL, FlightNode *TempoFlight)
{
	if ( TempoFlight == NULL || TempoFlight->pNext==NULL)
	{
		return false;
	}
	FlightNode *Xoa = TempoFlight->pNext;
	TempoFlight->pNext= Xoa->pNext;
	delete Xoa;
	FL.SoLuongChuyenBay--;
	return true;	
}
bool DeleteFollowIDFlight(FlightList &FL, const char *MaChuyenBayCanXoa)
{
	FlightNode *Clear = FindFlight(FL,MaChuyenBayCanXoa);
	if (Clear==NULL)
	return false ; 
	else if (Clear == FL.pHead)
	{
		return DeleteFirst(FL);
	}
	else if ( Clear == FL.pTail) 
		return DeleteLast(FL);
	else 
	{
		FlightNode *tmp = FL.pHead;
		while (true){
			if (tmp->pNext == Clear)
			{
				break;
			}
			tmp = tmp->pNext;
		}
		return DeleteAfter(FL,tmp);
	}
}
// giai phong bo nho
bool ClearFlightList(FlightList &FL) 
{
	if ( FL.pHead == NULL){
		return false ;
	}
	FlightNode *tmp ;
	while (FL.pHead!=NULL){
		tmp=FL.pHead;
		FL.pHead=FL.pHead->pNext;
		delete tmp;
	}
	return true ; 
	cout << "da don dep xong ";
}
// cap nhat trang thai cbay
void StatusFlight(FlightList &FL)
{
	for (FlightNode *search = FL.pHead; search != NULL; search = search->pNext)
	{
		if (TestValidDateTime(search->data.ThoiGianDi)== false )
			search->data.TrangThai= 4 ; 
			// 1 huy, 2 con, 3 het , 4 done;
	}
}

