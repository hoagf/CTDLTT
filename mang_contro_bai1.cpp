#include <iostream>
using namespace std;

typedef int item;
struct Node{
	int data;
	Node *next;
};
typedef Node *List;

void init(List &L)
{
	L= NULL;
}
int rong(List L)
{
	return (L==NULL);
}
int doDai(List L)
{
	Node *P = L;
	int i = 0;
	while(P!=NULL)
	{
		i++;
		P = P->next;
	}
	return i;	
}

Node *make_node(Node *P, item x)
{
	P = new Node;
	P->next = NULL;
	P->data = x;
}

void insert_first(List &L, item x)
{
	Node *P;
	P = make_node(P, x);
	P->next = L;
	L = P;
}
void insert_k(List &L, item x, int k)
{
	Node *P, *Q = L;
	int i = 1;
	if(k<1||k>doDai(L)+1)
	cout<<"Vi tri chen khong hop le"<<endl;
	else
	{
		P = make_node(P, x);
		if(k==1)
		insert_first(L, x);
		else
		{
			while(Q!=NULL && i != k -1)
			{
				i++;
				Q = Q->next;
			}
			
			P->next = Q->next;
			Q->next = P;
			
			
		}
	}
}
void del_first(List &L)
{
	L = L->next;
}
void del_k(List &L, int k)
{
	Node *P = L;
	int i = 1;
	if(i<1||i>doDai(L))
	{
		cout<<"Vi tri xoa khong hop le!"<<endl;
	}
	else
	{
		while(P!=NULL && i!= k-1)
		{
			P = P->next;
			i++;
		}
		P->next = P->next->next;
	}
	
}
void demAmDuong(List L)
{
	int am = 0;
	int duong = 0;
	Node *P = L;
	while(P!=NULL)
	{
		if(P->data<0)
		am++;
		else
		duong++;
		P = P->next;
	}
	cout<<"Co "<<am<<" so AM trong mang"<<endl;
	cout<<"Co "<<duong<<" so DUONG trong mang"<<endl;
	
}
void nhap(List &L)
{
	int i = 0;
	item x;
	do{
		i++;
		cout<<"Nhap phan tu thu "<<i<<":";
		cin>>x;
		if(x!=0)
		{
			insert_k(L, x, doDai(L)+1);
		}
	}while(x!=0);
}
void xuat(List L)
{
	int i = 1;
	Node *P = L;
	while(P!=NULL)
	{
		cout<<"L["<<i<<"]= "<<P->data<<endl;
		P = P->next;
		i++;
	}
}
void del_x(List &L, int x)
{
	Node *P = L;
	int i = 1;
	int dem = 0;
	
	while(i<=doDai(L))
	{
		if(P->data == x)
		{
			del_k(L, i);
			dem++;
			i--;
		}
	i++;
	P = P->next; 
	}
	cout<<"Da xoa "<<dem<<" phan tu bang "<<x<<" ra khoi danh sach!"<<endl;
}
int main()
{
	List L1;
	init(L1);
	nhap(L1);
	xuat(L1);
	
//	int k;
//	cout<<"Nhap vi tri muon xoa: ";
//	cin>>k;
//	del_k(L1, k);
//	xuat(L1);
//	demAmDuong(L1);
//	xuat(L1);
	
	del_x(L1, 5);
	xuat(L1);
}
