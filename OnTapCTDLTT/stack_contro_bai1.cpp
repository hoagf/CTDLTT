#include <iostream>
using namespace std;
typedef int item;
struct Node{
	item data;
	Node *next;
};
struct Stack{
	Node *top;
};
void init(Stack &S)
{
	S.top = NULL;
}
int isEmpty(Stack S)
{
	return (S.top == NULL);
}
int doDai(Stack S)
{
	int j= 0; 
	Node *P = S.top;
	while(P!=NULL)
	{
		j++;
		P = P->next;
	}
	return j;
}
int isFull(Stack S)
{
	return(doDai(S)==100);
}
Node *make_Node(Node *P, item x)
{
	P = new Node;
	P->data = x;
	P->next = NULL;
	return P;
}
void push(Stack &S, item x)
{
	Node *P;
	P = make_Node(P, x);
	P->next = S.top;
	S.top = P;
	
}
void pop(Stack &S, item &x)
{
	x = S.top->data;
	S.top = S.top->next; 
}
void nhap(Stack &S)
{
	cout<<"Nhap gia tri (0 de dung): "<<endl;
	item x;
	do{
		cout<<"Nhap:";
		cin>>x;
		if(x!=0)
		push(S, x);
	}while(x!=0);
	
}
void xuat(Stack S)
{
	cout<<endl<<"Stack: "<<endl;
	Node *P = S.top;
	int i = doDai(S);
	do
	{
		cout<<"S["<<i<<"]="<<P->data<<endl;
		P =P->next;
		i--;
	}while(P!=NULL);
}
void them_Top(Stack &S)
{
	int x;
	cout<<"Them vao dinh: ";
	cin>>x;
	push(S, x);
	xuat(S);
}
void xoa_Top(Stack &S)
{
	int x;
	cout<<"Xoa dinh: "<<endl;
	pop(S, x);
	xuat(S);
}
void them_k(Stack &S, item x, int k)
{
	
	Stack Temp;
	init(Temp);
	 
	int i = doDai(S);
	while(i>=k)
	{
		item z;
		pop(S, z);
		push(Temp, z);
		i--;
	}
	push(S, x);
	i = doDai(Temp);
	while(i>0)
	{
		item z;
		pop(Temp, z);
		push(S, z);
		i--;
	}
	cout<<"Them k:"<<endl;
	xuat(S);
	
}
void xoa_k(Stack &S, int k)
{
	Stack Temp;
	init(Temp);
	
	int i = doDai(S);
	while(i>k)
	{
		item z;
		pop(S, z);
		push(Temp, z);
		i--;
	}
	item x;
	pop(S, x);
	i = doDai(Temp);
	while(i>0)
	{
		item z;
		pop(Temp, z);
		push(S, z);
		i--;
	}
	cout<<"Xoa k:"<<endl;
	xuat(S);
}
void thap_nhi()
{
	int thap;
	cout<<"Nhap so thap phan: ";
	cin>>thap;
	Stack nhi;
	init(nhi);
	
	item temp;
	do{
		temp = thap%2;
		push(nhi, temp);
		thap = (int) thap/2;
	}while(thap>0);
	
	Node *P;
	P = nhi.top;
	while(P!=NULL)
	{
		cout<<P->data;
		P = P->next;
	}
}
int main()
{
//	Stack S1;
//	init(S1);
//	nhap(S1);
//	xuat(S1);
//	them_Top(S1);
//	xoa_Top(S1);
//	item x = 191;
//	
//	them_k(S1, x, 3);
//	xoa_k(S1, 5);
	thap_nhi();
	return 0;
}
