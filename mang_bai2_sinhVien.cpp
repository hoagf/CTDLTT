#include <iostream>
#include <string>

using namespace std;

struct SinhVien{
	string hoTen;
	string Lop;
	float diemTb; 
};
struct List{
	int count;
	SinhVien mang [100];
};

void init(List &L)
{
	L.count = 0;
}
void nhap(List &L)
{
	cout<<"Nhap so luong sinh vien:";
	cin>>L.count;
	
	for(int i=0; i<L.count; i++)
	{
		cout<<"--Sinh vien thu "<<i<<"--"<<endl;
		cout<<"Ho ten: ";
		fflush(stdin);
		getline(cin, L.mang[i].hoTen);
		cout<<"Lop: ";
		getline(cin, L.mang[i].Lop);
		cout<<"Diem TB: ";
		cin>>L.mang[i].diemTb;
		
	}
}
void xuat(List L)
{
	cout<<"--Danh sach SV--"<<endl;
	for(int i =0 ; i<L.count; i++)
	{
		cout<<endl;
		cout<<"Sinh vien "<<i<<":"<<endl;
		cout<<"Ho ten: "<<L.mang[i].hoTen<<endl;
		cout<<"Lop: "<<L.mang[i].Lop<<endl;
		cout<<"Diem TB: "<<L.mang[i].diemTb<<endl;
		cout<<endl;
	}
	
}
void them(List &L, int k)
{
	SinhVien x;
		cout<<"Ho ten: ";
		fflush(stdin);
		getline(cin, x.hoTen);
		cout<<"Lop: ";
		getline(cin, x.Lop);
		cout<<"Diem TB: ";
		cin>>x.diemTb;
	L.count++;
	for(int i = L.count-1; i>k; i--)
	{
		L.mang[i] = L.mang[i-1];
	}
	L.mang[k]= x;
}
void loaibo(List &L)
{
	for(int i = 0; i<L.count; i++)
	{
		if(L.mang[i].diemTb<5)
		{
			for(int j = i; j<L.count;j++)
			{
				L.mang[j] = L.mang[j+1];
			}
			L.count--;
		}
	}
}

int main()
{
	List L1;
	init(L1);
	nhap(L1);
	xuat(L1);
//	int k;
//	cout<<"Nhap vi tri muon them: ";
//	cin>>k;
//	them(L1, k);
//	xuat(L1);
	loaibo(L1);
	xuat(L1);
	return 0;
}
