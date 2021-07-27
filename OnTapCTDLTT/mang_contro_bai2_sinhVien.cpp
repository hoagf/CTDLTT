#include<iostream>
using namespace std;

struct SinhVien{
	string hoTen;
	string Lop;
	string Sbd;
	float diemTb;
};
struct Node{
	SinhVien sv;
	Node *next;
};
typedef Node *List;

void init(List &L)
{
	L= NULL;
}
Node *make_node(Node *P, SinhVien x)
{
	P = new Node;
	P->sv = x;
	P->next = NULL;
	return P;
}
int doDai(List L)
{
	Node *P = L;
	int i = 0;
	while(P!=NULL)
	{
		i++;
		P= P->next;
	}
	return (i);
}
void insert_first(List &L, SinhVien x)
{
	Node *P;
	P = make_node(P, x);
	
	if(L==NULL)
	{
		L = P;
	}
	else
	{
		P->next=L;
		L=P;
	}
}
void insert_k(List &L, SinhVien x, int k)
{
	Node *P;
	P = make_node(P, x);
	Node *Q;
	
	if(k == 1)
	insert_first(L, x);
	else
	{
		Q = L;
		int i = 1;
		while(Q!=NULL && i<k-1)
		{
			Q=Q->next;
			i++;
		}
		P->next = Q->next;
		Q->next = P;
		
	}
}
void nhap(List &L)
{
	SinhVien x;
	int i = 1;
	do{
		
		cout<<"Nhap sinh vien "<<i<<":"<<endl;
		cout<<"Ho ten: ";
		fflush(stdin);
		getline(cin, x.hoTen);
		
		if(x.hoTen == "0")
		return;
		
		cout<<"Lop: ";
		fflush(stdin);
		getline(cin,x.Lop);
		
		cout<<"Sbd: ";
		fflush(stdin);
		getline(cin, x.Sbd);
		
		cout<<"Diem TB:";
		cin>>x.diemTb;
		
		insert_k(L, x, doDai(L)+1);
		i++;
		
		
		
	}while(true);
}
void xuat(List L)
{
	Node *P = L;
	int i = 1;
	cout<<"-----------Danh sach SV----------"<<endl;
	while(P!=NULL)
	{
		cout<<"--- Sinh vien thu "<<i<<":"<<endl;
		cout<<"Ho ten: "<<P->sv.hoTen<<endl;
		cout<<"Lop: "<<P->sv.Lop<<endl;
		cout<<"Sbd: "<<P->sv.Sbd<<endl;
		cout<<"Diem TB: "<<P->sv.diemTb<<endl;
		P=P->next;
		i++;
	}
}
int main()
{
	List L1;
	init(L1);
	nhap(L1);
	xuat(L1);
	return 1;
}
