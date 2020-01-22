//PROGRAM TO DESCRIBE DOUBLY LINKED LIST
#include<iostream>
#include<conio.h>
using namespace std;
class node
{
	public:
	int data;
	node *prev;
	node *next;
};
class d_list
{
	private:
		node *head,*tail;
	public:
		d_list();
		void create();
		node *getnode();
		void append(node *);
		void insert_des(int pos);
		void delete_des(int pos);
		void display();
		void display_back();
};
d_list::d_list()
{
	head=tail=NULL;
}
void d_list::create()
{
	char ch;
	node *newnode;
	while(ch!='n')
	{
		newnode=getnode();
		if(head==NULL)
		{
			head=tail=newnode;
		}
		else
		{
			append(newnode);
		}
		cout<<"\nPress n to break or else to continue: ";
		cin>>ch;
	}
}
node* d_list::getnode()
{
	node *newnode;
	newnode=new node;
	cout<<"\nEnter data of node: ";
	cin>>newnode->data;
	newnode->prev=NULL;
	newnode->next=NULL;
	return newnode;
}
void d_list::append(node *newnode)
{
	if(tail==NULL)
	{
		head=tail=newnode;
	}
	else
	tail->next=newnode;
	newnode->prev=tail;
	tail=tail->next;
}
void d_list::insert_des(int pos)
{
	node *newnode;
	newnode=getnode();
	if(pos==1)
	{
		newnode->next=head;
		head->prev=newnode;
		head=newnode;
	}
	else
	{
		node *tmp=head;
		int count=1,flag=1;
		while(count!=pos-1)
		{
			tmp=tmp->next;
			if(tmp==NULL)
			{
				flag=2;
				break;
			}
			count++;
		}
		if(flag==1)
		{
			newnode->next=tmp->next;
			(tmp->next)->prev=newnode;
			tmp->next=newnode;
			newnode->prev=tmp;
		}
		else
		if(flag=0)
		{
			cout<<"\nPosition not found";
			return;
		}
	}
}
void d_list::delete_des(int pos)
{
	if(pos==1)
	{
		node *tmp=head;
		head=head->next;
		delete tmp;
		return;
	}
	else
	{
		int count=1,flag=1;
		node *tmp=head;
		node *curr=head;
		curr=curr->next;
		while(count!=pos-1)
		{
			curr=curr->next;
			tmp=tmp->next;
			if(curr==NULL)
			{
				flag=0;
				break;
			}
			count++;
		}
		if(flag==1)
		{
			tmp->next=curr->next;
			(curr->next)->prev=tmp;
			delete curr;
		}
	}
}
void d_list::display()
{
	node *temp=head;
	while(temp!=NULL)
	{
		cout<<temp->data<<" ";
		temp=temp->next;
	}
}
void d_list::display_back()
{
	node *temp=tail;
	while(temp!=NULL)
	{
		cout<<temp->data<<" ";
		temp=temp->prev;
	}	
}
int main()
{
	d_list obj;
	obj.create();
	obj.display();
	cout<<endl;
	obj.display_back();
	int  pos;
	cout<<"\nEnter position to enter new node: ";
	cin>>pos;
	obj.insert_des(pos);
	obj.display();
	cout<<endl;
	obj.display_back();
	cout<<"\nEnter position: ";
	cin>>pos;
	obj.delete_des(pos);
	obj.display();
	cout<<endl;
	obj.display_back();
	return 0;
}
