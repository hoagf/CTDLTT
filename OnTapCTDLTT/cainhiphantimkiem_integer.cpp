#include<iostream>
using namespace std;
struct Node{
	int data;
	Node *Left;
	Node *Right;
};

typedef Node *CayNP;

void make_null(CayNP &C)
{
	C= NULL;
	
}

Node *search2(CayNP C, int x)
{
	if(C == NULL)
	return NULL;
	else if(C->data == x)
	return C;
	else if(x>C->data)
	{
		search2(C->Right, x);
	}
	else if(x<C->data)
	{
		search2(C->Left,x);
	}
}
void Insert(CayNP &C, int x)
{
	if(search2(C, x)!=NULL)
	{
		cout<<"Da ton tai!"<<endl;
		return;
	}
	if(C ==NULL)
	{
		Node *P;
		P =new Node;
		P->data = x;
		P->Left = NULL;
		P->Right = NULL;
		C = P;
	}
	else if(x > C->data)
	{
		Insert(C->Right, x);
	}
	else if(x < C->data)
	{
		Insert(C->Left, x);
	}
	
	
}

void nhap(CayNP &C)
{
	cout<<"Nhap Cay nhi phan "<<endl;
	cout<<"Nhap 0 de dung: "<<endl;
	int x;
	do{
		cout<<"Nhap: ";
		cin>>x;
		if(x!=0)
		Insert(C, x);
	}while(x!=0);
}
void duyetTruoc(CayNP &C)
{
	if(C!=NULL)
	{
		cout<<C->data<<" ";
		duyetTruoc(C->Left);
		
		duyetTruoc(C->Right);
	}
	
}
void duyetGiua(CayNP &C)
{
	if(C!=NULL)
	{
		
		duyetGiua(C->Left);
		cout<<C->data<<" ";
		duyetGiua(C->Right);
	}
	
}
void duyetSau(CayNP &C)
{
	if(C!=NULL)
	{
		duyetSau(C->Left);
		duyetSau(C->Right);
		cout<<C->data<<" ";
	}
	
}
void duyet(CayNP C)
{
	cout<<endl<<"Duyet giua: ";
	duyetGiua(C);
	cout<<endl<<"Duyet truoc: ";
	duyetTruoc(C);
	cout<<endl<<"Duyet sau: ";
	duyetSau(C);
}
void themNode(CayNP &C)
{
	int x;
	do{
		cout<<endl<<"Them: ";
		cin>>x;
		if(x!=0)
		{
		Insert(C, x);
		duyet(C);
				}		
	}
	while(x!=0);
	
}
Node *Delete(Node *root, int x)
{
	if(root == NULL)
	return NULL;
	if(root->data == x)
	{
		if(root->Left == NULL && root->Right == NULL)
		return NULL;
		
		else if(root->Left ==NULL && root->Right!=NULL)
		{
			root = root->Right;
			return root;
			
		}
		else if(root->Left !=NULL && root->Right==NULL)
		{
			root = root->Left;
			return root;
		}
				
		else if(root->Left!=NULL & root->Right!=NULL)
		{
			Node *P = root->Right;
			while(P->Left!=NULL)
			{
				P = P->Left;
			}
			int temp = P->data;
			P->data = root->data;
			root->data = temp;
			
			root->Right = Delete(root->Right, P->data);
			return root;
		}
	}
	if(x < root->data)
	{
		root->Left = Delete(root->Left, x);
	}
	if(x > root->data)
	{
		root->Right = Delete(root->Right, x);
	}
	return root;
	
}
void Xoa(CayNP &C)
{
	int x;
	do{
	cout<<endl<<"Nhap node muon xoa: ";
	cin>>x;
	if(x!=0)
	{
		
		C = Delete(C, x);
		
	}
	duyet(C);
}while(x!=0);
}
int main()
{
	CayNP C1;
	make_null(C1);
	nhap(C1);
	duyet(C1);
	//themNode(C1);
//	Node *o = search2(C1, 28);
//	cout<<"hhh:"<<o->Left;
	Xoa(C1);
	
	
//	int tim;
//	cout<<endl<<"Tim kiem: "<<endl;
//	do{
//	cout<<"Nhap x: ";
//	cin>>tim;
//	if(search2(C1, tim))
//	cout<<"Tim thay "<<tim<<endl;
//	else
//	cout<<"Khong tim thay "<<tim<<endl;
//}while(tim!=0);
}
