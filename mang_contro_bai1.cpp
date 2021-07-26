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
	Node *P = L;
	while(P!=NULL)
	{
		cout<<P->data<<endl;
		P = P->next;
	}
}
int main()
{
	List L1;
	init(L1);
	nhap(L1);
	xuat(L1);
}
