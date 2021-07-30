#include <iostream>
using namespace std;
struct Node{
	char data;
	Node *leftChild;
	Node *rightChild;
};
typedef Node *Cay;

void Make_Null(Cay *C)
{
	(*C) = NULL;
}
Node *CreateNode(char x)
{
	Node *P = new Node;
	P->data = x;
	P->leftChild = NULL;
	P->rightChild = NULL;
	return P;
}
int isNULL(Cay C)
{
	return (C == NULL);
}

//Cay LeftChild(Cay C)
//{
//	if(!isNULL(C))
//	{
//		return (C->leftChild);
//	}
//	else
//	return NULL;
//}
//
//Cay RightChild(Cay C)
//{
//	if(!isNULL(C))
//	{
//		return (C->rightChild);
//	}
//	else
//	return NULL;
//}
Node *NhapCay(Node *P, char x)
{
	cout<<"Node: ";
	cin>>x;
	if(x == '0')
	return NULL;
	
	P = CreateNode(x);
	cout<<"Con trai cua "<<x<<":";
	P->leftChild = NhapCay(P->leftChild, x);
	
	cout<<"Con phai cua "<<x<<":";
	P->rightChild = NhapCay(P->rightChild, x);
	return P;
	
}
void DuyetGiua(Cay C)
{
	if(C!=NULL)
	{
		DuyetGiua(C->leftChild);
		cout<<C->data<<" ";
		DuyetGiua(C->rightChild);
	}
}
void DuyetTruoc(Cay C)
{
	if(C!=NULL)
	{
		cout<<C->data<<" ";
		DuyetTruoc(C->leftChild);
		
		DuyetTruoc(C->rightChild);
	}
}
void DuyetSau(Cay C)
{
	if(C!=NULL)
	{
		DuyetSau(C->leftChild);
		
		DuyetSau(C->rightChild);
		cout<<C->data<<" ";
	}
}

int main()
{
	Cay C1;
	C1 = NULL;
	Node *P = NULL;
	char x;
	cout<<"Nhap 0 de chuyen sang nut khac hoac dung: "<<endl;
	C1 = NhapCay(P, x);
	cout<<endl<<"Duyet truoc: ";
	DuyetTruoc(C1);
	cout<<endl<<"Duyet giua: ";
	DuyetGiua(C1);
	cout<<endl<<"Duyet sau: ";
	DuyetSau(C1);
	

	return 0;
}
