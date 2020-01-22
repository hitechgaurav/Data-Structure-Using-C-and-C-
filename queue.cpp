#include<iostream>
#include<conio.h>
#include<malloc.h>
using namespace std;
struct node
{
	int data;
	node *next;
}*front,*rear,*tmp;
void start()
{
	front=rear=NULL;
}
void create()
{
	tmp=(struct node *)malloc(sizeof(node));
	cout<<"\nEnter data:- ";
	cin>>tmp->data;
	tmp->next=NULL;
	front=rear=tmp;
	char ch;
	while(ch!='n')
	{
		tmp=(struct node*)malloc(sizeof(node));
		cout<<"\nEnter next data:- ";
		cin>>tmp->data;
		tmp->next=NULL;
		rear->next=tmp;
		rear=rear->next;
		cout<<"\nPress n to break or else to continue:- ";
		cin>>ch;
	}
}
void display()
{
	struct node *h=front;
	if(rear==NULL)
	{
		cout<<"\nEmpty.";
		return;
	}
	else
	while(h!=NULL)
	{
		cout<<h->data<<" ";
		h=h->next;
	}
}
void insertq()
{
	tmp=(struct node*)malloc(sizeof(node));
	cout<<"\nEnter data to be inserted.";
	cin>>tmp->data;
	tmp->next=NULL;
	if(rear==NULL)
	{
		front=rear=tmp;
	}
	else
	{
		rear->next=tmp;
		rear=rear->next;
	}
}
void deleteq()
{
	if(rear==NULL)
	{
		cout<<"\nEmpty.";
		return;
	}
	else
	{
		cout<<"\nNode "<<front->data<<" dequeued.";
		front=front->next;
	}
}
int main()
{
	start();
	create();
	display();
	deleteq();
	cout<<endl;
	display();
	insertq();
	display();
	
}
