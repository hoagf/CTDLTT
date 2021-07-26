#include <iostream>
using namespace std;
struct List{
	int mang[100];
	int count;
};

void init (List &L)
{
	L.count = 0;
}
void nhap(List &L)
{
	
	cout<<"Nhap so phan tu:";
	cin>>L.count;
	for(int i =0; i<L.count; i++)
	{
		cout<<"Nhap L["<<i<<"]=";
		cin>>L.mang[i];
	}
}
void xuat(List L)
{
	cout<<"----Mang----"<<endl;
	for(int i = 0; i<L.count; i++)
	{
		cout<<"L["<<i<<"]="<<L.mang[i]<<endl;
	
	}
}
void them(List &L)
{
	int k, x;
	do{
	
	cout<<"Nhap vi tri can them:";
	cin>>k;
}while(k<0||k>L.count);

if(L.count>99)
{
	cout<<"Mang da day!"<<endl;
	return;
}


	cout<<"Nhap gia tri can them:";
	cin>>x;
	L.count++;
	for(int i = L.count-1; i>k; i--)
	{
		L.mang[i] = L.mang[i-1];
		
	}
	L.mang[k] = x;
	
}
void xoa(List &L)
{
	int k;
	do{
	cout<<"Nhap vi tri muon xoa:";
	cin>>k;
	
		}while(k<0||k>100);
	for(int i = k; i<L.count-1; i++)
	{
		L.mang[i] = L.mang[i+1];
	}
	L.count--;
}
void tim(List &L)
{
	int search;
	cout<<"Nhap gia tri muon tim:";
	cin>>search;
	cout<<"Nhung phan tu bang "<<search<<" trong mang: "<<endl;
	for(int i = 0; i<L.count-1; i++)
	{
		if(L.mang[i]==search)
		{
			cout<<"L["<<i<<"] = "<<search<<endl;
		}
	}
}
int main()
{
	List L1;
	init(L1);
	nhap(L1);
	xuat(L1);
//	them(L1);
//	xuat(L1);
//	xoa(L1);
//	xuat(L1);
	tim(L1);
	
	return 0;
}
