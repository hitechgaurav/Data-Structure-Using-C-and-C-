//binary search tree
#include<iostream>
#include<conio.h>
#include<malloc.h>
using namespace std;
struct tnode
{
	int data;
	tnode *lchild;
	tnode *rchild;
}*tmp;
struct tnode *root=(struct tnode*)malloc(sizeof(tnode));
void createbst(int x)
{
	tmp=(struct tnode*)malloc(sizeof(tnode));
	tmp->data=x;
	tmp->lchild=NULL;
	tmp->rchild=NULL;
	root=tmp;
}
struct tnode *insertbst(struct tnode *r,int x)
{
	tmp=(struct tnode*)malloc(sizeof(tnode));
	if(r==NULL)
	{
		cout<<"\nNull reached."<<endl;
		tmp->data=x;
		tmp->lchild=NULL;
		tmp->rchild=NULL;
		return tmp;
	}
	else
	if(x>r->data)
	{
		cout<<"\nInserting to right sub tree.";
		r->rchild=insertbst(r->rchild,x);
	}
	else
	if(x<r->data)
	{
		cout<<"\nInserting to lest sub tree.";
		r->lchild=insertbst(r->lchild,x);
	}
}
struct tnode *preorder(struct tnode *r)
{
	if(r==NULL)
	{
		return r;
	}
	cout<<r->data<<" ";
	preorder(r->lchild);
	preorder(r->rchild);
}
struct tnode *inorder(struct tnode *r)
{
	if(r==NULL)
	{
		return r;
	}
	inorder(r->lchild);
	cout<<r->data<<" ";
	inorder(r->rchild);
	
}
struct tnode *postorder(struct tnode *r)
{
	if(r==NULL)
	{
		return r;
	}
	postorder(r->lchild);
	postorder(r->rchild);
	cout<<r->data<<" ";
}
void delete_node(int deldata)
{
	struct tnode *t;
	struct tnode *r=root;
	struct tnode *parent;
	if(r==NULL)
	{
		cout<<"\nEmpty";
		return;
	}
	else
	while(r!=NULL)
	{
		if(r->data==deldata)
		{
			cout<<"\nDATA FOUND.";
			break;
		}
		else
		if(r->data<deldata)
		{
			parent=r;
			r=r->lchild;
		}
		else
		{
			parent=r;
			r=r->rchild;
		}
	}
	if(r->lchild==r->rchild==NULL)
	delete r;
	else
	if(r->lchild!=NULL&&r->rchild==NULL)
	{
		t=r->lchild;
		r=t;
		delete r;
	}
	else
	if(r->rchild!=NULL&&r->lchild==NULL)
	{
		t=r->rchild;
		r=t;
		delete r;
	}
	
}
int main()
{
	createbst(44);
	int arr[]={23,26,43,56,45,76,89,77,55,11};
	for(int i=0;i<10;i++)
	{
		insertbst(root,arr[i]);
	}	
	preorder(root);
	cout<<endl;
//	delete_node(89);
	preorder(root);
	inorder(root);
//	cout<<endl;
	postorder(root);
}
