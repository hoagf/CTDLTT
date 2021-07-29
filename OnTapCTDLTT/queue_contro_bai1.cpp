#include <iostream>
using namespace std;
struct Node{
	int data;
	Node *next;
};
struct Queue{
	Node *font, *rear;
};
int doDai(Queue &Q)
{
	int i = 0;
	Node *P = Q.font;
	while(P!=NULL)
	{
		i++;
		P =P->next;
	}
	return i;
}
int isNull(Queue &Q)
{
	return (doDai(Q)==0);
}
int isFull(Queue &Q)
{
	return(doDai(Q)>=100);
}
void init(Queue &Q)
{
	Q.font = Q.rear = NULL;
}
Node *make_Node( int x)
{
	Node *P;
	P = new Node;
	P->data = x;
	P->next = NULL;
}

void Insert_Queue(Queue &Q, int x)
{
	Node *P;
	P = make_Node(x);
	if(!isFull(Q))
	{
		if(isNull(Q))
		{
			Q.font = Q.rear = P;
		}
		else
		{
			Q.rear->next = P;
			Q.rear = P;
		}
	}
	else{
		cout<<"Is Full"<<endl;
	}
}
void De_Queue(Queue &Q, int &x)
{
	if(isNull(Q))
	cout<<"Is Null"<<endl;
	else
	{
		x = Q.font->data;
		Q.font=Q.font->next;
	}	
}
void nhap (Queue &Q)
{
	cout<<"Nhap gia tri:"<<endl;
	int x;
	do{
	cout<<"Nhap: ";
	cin>>x;
	if(x!=0)
	{
		Insert_Queue(Q, x);
	}
}while(x!=0);
	
}
void xuat(Queue Q)
{
	Node *P;
	P = Q.font;
	int i = 0;
	cout<<endl<<"Queue:"<<endl;
	while(P!=NULL)
	{
		cout<<"Q["<<i<<"]="<<P->data<<endl;
		i++;
		P= P->next;
	};
}
void them_k(Queue &Q)
{
	int x, k;
	int i = 0;
	Node *P;
	P = Q.font;
	Queue TG;
	init(TG);
	int temp;
	
	do{
	cout<<"Nhap vi tri muon them: ";
	cin>>k;
	}while(k<0||k>doDai(Q));
	cout<<"Nhap gia tri: ";
	cin>>x;
	while(i<k)
	{

		De_Queue(Q, temp);
		Insert_Queue(TG, temp);	
		i++;	
		P = P->next;
	}
	Insert_Queue(TG, x);
	
	while(P!=NULL)
	{
		De_Queue(Q, temp);
		Insert_Queue(TG, temp);	
		i++;	
		P = P->next;
	}
	
	init(Q);
	P = TG.font;
	while(P!=NULL)
	{
		De_Queue(TG, temp);
		Insert_Queue(Q, temp);	
		P=P->next;
	}
	xuat(Q);
	
}
void xoa_k(Queue &Q)
{
	int k;
	do{
	cout<<"Nhap vi tri muon xoa:";
	cin>>k;
}while(k<0||k>doDai(Q));
	Node *P = Q.font;
	Queue TG;
	init(TG);
	int i = 0;
	int temp;
	while(i<k)
	{
		De_Queue(Q, temp);
		Insert_Queue(TG, temp);
		i++;
		P = P->next;
	}
	De_Queue(Q, temp);
	P =P->next;
	while(P != NULL)
	{
		De_Queue(Q, temp);
		Insert_Queue(TG, temp);
		P = P->next;
	}

	init(Q);
	P = TG.font;
	while(P!=NULL)
	{
		De_Queue(TG, temp);
		Insert_Queue(Q, temp);
		P = P->next;
	}
	xuat(Q);
}
int main()
{
	Queue Q1;
	init(Q1);
	nhap(Q1);
	xuat(Q1);
	them_k(Q1);
	xoa_k(Q1);

	return 0;
}
