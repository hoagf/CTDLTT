#include <iostream>
using namespace std;

typedef int item;
struct Stack{
	int top;
	item data[100];
};
void init (Stack &S)
{
	S.top = 0;
}

int isEmpty(Stack S)
{
	return (S.top == 0);
}
int isFull(Stack &S)
{
	return (S.top == 100);
}
void pop(Stack &S, int &x)
{
	if(!isEmpty(S))
	{
	x = S.data[S.top];
	S.top--;

	}
	else {
		cout<<"Khong co gi!!"<<endl;
	}
}
void push(Stack &S, int x)
{
	if(!isFull(S))
	{
	S.top++;
	S.data[S.top] = x;
	}else{
		cout<<"Mang day!!!"<<endl;
	}
	
}
void nhap(Stack &S)
{
	int x;
	do{
	cout<<"Nhap gia tri (0 de dung): ";
	cin>>x;
	if(x!=0)
	push(S, x);
}while(x!=0);
	
}
void xuat (Stack S)
{
	int i = S.top;
	cout<<endl<<"Stack:"<<endl;
	while(i>0)
	{
		cout<<"S["<<i<<"]= "<<S.data[i]<<endl;
		i--;
	}
}
void them_k(Stack &S, int z, int k)
{
	Stack Temp;
	init(Temp);
	for(int i = S.top; i>=k; i--)
	{
		int x;
		pop(S, x);
		push(Temp, x);
	}
	push(S, z);
	int j = Temp.top;
	while(j>0)
	{
		int x;
		pop(Temp, x);
		push(S, x);
		j--;
	}
}
void xoa_k(Stack &S, int k)
{
	Stack Temp;
	init(Temp);
	for(int i = S.top; i>k; i--)
	{
		int x;
		pop(S, x);
		push(Temp, x);
	}
	int z;
	pop(S, z);
	int j  = Temp.top;
	while(j>0)
	{
		int x;
		pop(Temp, x);
		push(S, x);
		j--;
	}
}
void thap_nhi()
{
	Stack S;
	init(S);
	int thap;
	cout<<"Thap phan: ";
	cin>>thap;
	

	while(thap>0){
		int temp;
		temp = thap%2;
		push(S, temp);
		thap = (int) thap/2;
	};
	
	cout<<"Nhi Phan: "<<endl;
	int j = S.top;
	while(j>0)
	{
		cout<<S.data[j];
		j--;
	};
}
int main()
{
	int x;
//	Stack S1;
//	init(S1);
//	nhap(S1);
//	xuat(S1);
	
//	cout<<"Them phan tu vao dinh:";
//	cin>>x;
//	push(S1, x);
//	xuat(S1);
//	cout<<"Xoa phan tu khoi dinh:"<<endl;
//	pop(S1, x);
//	xuat(S1);
	int k;
//	cout<<"Them phan tu x vao vi tri k:"<<endl;
//	cout<<"k = ";
//	cin>>k;
//	cout<<"x = ";
//	cin>>x;
//	them_k(S1, x, k);
//	xuat(S1);

//	cout<<"Xoa tai vi tri k: "<<endl;
//	cin>>k;
//	xoa_k(S1, k);
//	xuat(S1);

//	cout<<"Them dau:"<<endl;
//	cin>>x;
//	them_k(S1, x, 1);
//	xuat(S1);
//	cout<<"Xoa dau:"<<endl;
//	xoa_k(S1, 1);
//	xuat(S1);
	
	thap_nhi();
}
