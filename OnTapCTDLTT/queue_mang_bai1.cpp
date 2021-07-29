#include <iostream>
using namespace std;

struct Queue{
	int front, rear;
	int data[100];
	int count;
};

void init(Queue &Q)
{
	Q.count = 0;
	Q.front = 0;
	Q.rear = -1;
}
int isFull(Queue Q)
{
	return (Q.count >= 100);
}

int isEmpty(Queue Q)
{
	return (Q.count = 0);
}

void Insert_Queue(Queue &Q, int x)
{
	if(!isFull(Q))
	{
		if(Q.rear!= 99)
			Q.rear++;
		else 
			Q.rear = 0;
		Q.data[Q.rear] = x;
		Q.count++;
		
	}else cout<<"Mang da day!"<<endl;
}
void De_Queue(Queue &Q, int &x)
{
	if(!isEmpty(Q))
	{
		x = Q.data[Q.front];
		if(Q.front!= 99)
		Q.front = Q.front+1;
		else
		Q.front = 0;
		Q.count--;
	}
}

void nhap(Queue &Q)
{
	cout<<"Nhap gia tri (0 de dung): "<<endl;
	int x;
	do{
		cout<<"Nhap: ";
		cin>>x;
		if(x!=0)
		Insert_Queue(Q, x);
		
	}while(x!=0);
}
void xuat(Queue Q)
{
	cout<<endl<<"Queue"<<endl;
	for(int i = Q.front; i<=Q.rear; i++)
	{
		cout<<"Q["<<i<<"]: "<<Q.data[i]<<endl;
	}
}
void them_k(Queue &Q, int x, int k)
{
	Queue TG;
	init(TG);
	int z;
	for(int i =Q.front; i<k; i++)
	{
		De_Queue(Q, z);
		Insert_Queue(TG, z);
	}
	Insert_Queue(TG, x);
	for(int i =k; i<=Q.rear; i++)
	{
		De_Queue(Q, z);
		Insert_Queue(TG, z);
	}
	init(Q);
	for(int i = TG.front; i<=TG.rear; i++)
	{
		De_Queue(TG, z);
		Insert_Queue(Q, z);
	}
	xuat(Q);
}
void xoa_k(Queue &Q, int k)
{
	Queue TG;
	init (TG);
	
	int z;
	for(int i = Q.front; i<k; i++)
	{
		De_Queue(Q, z);
		Insert_Queue(TG, z);	
	}
	De_Queue(Q, z);
	for(int i = k+1; i<=Q.rear; i++)
	{
		De_Queue(Q, z);
		Insert_Queue(TG, z);	
	}
	init(Q);
	for(int i = TG.front; i<=TG.rear; i++)
	{
		De_Queue(TG, z);
		Insert_Queue(Q, z);
	}
	xuat(Q);
}
void xoa_cuoi(Queue &Q)
{
	cout<<"Xoa cuoi:"<<endl;
	int k = Q.rear;
	xoa_k(Q, k);
	
}

int main()
{
	Queue Q1;
	init(Q1);
	nhap(Q1);
	xuat(Q1);
	int k, x;
//	do {
//		cout<<"Nhap vi tri muon them: ";
//		cin>>k;
//		
//	}
//	while(k<Q1.front || k>Q1.rear);..
	cout<<"Nhap gia tri:";
	cin>>x;
//	them_k(Q1, x, k);
//	
//	do {
//		cout<<"Nhap vi tri muon xoa: ";
//		cin>>k;
//		
//	}
//	while(k<Q1.front || k>Q1.rear);
//	xoa_k(Q1, k);
//	xoa_cuoi(Q1);
	cout<<"Them dau: "<<endl;
	them_k(Q1, x, Q1.front);
	return 0;
}
