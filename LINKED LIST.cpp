//Program to illustrate LINKED LIST
#include<iostream>
#include<conio.h>
using namespace std;
class node
{
	public:
	int data;
	node *next;
};
class l_list
{
	private:
		node *top,*head;
		public:
			l_list();
			void create();
			void append(node*);
			node *getnode();
			void display();
			void insert_beg();
			void insert_des(int);
			void delete_l(int pos);
};
l_list::l_list()
{
	top=NULL;
}
void l_list::create()
{
	node *newnode;
	char ch;
	while(ch!='n')
	{
		newnode=getnode();
		if(top==NULL)
		{
			top=head=newnode;
		}
		else
		append(newnode);
		cout<<"\nPress n to break or else to continue: ";
		cin>>ch;
	}
}
void l_list::append(node *newnode)
{
	if(top==NULL)
	{
		top=head=newnode;
	}
	else
	{
		top->next=newnode;
		top=top->next;
	}
}
node* l_list::getnode()
{
	node *newnode;
	newnode=new node;
	cout<<"\nEnter data of node:- ";
	cin>>newnode->data;
	newnode->next=NULL;
	return newnode;
}
void l_list::insert_beg()
{
	node *newnode;
	newnode=getnode();
	newnode->next=head;
	head=newnode;
}
void l_list::insert_des(int pos)
{
	node *newnode;
	newnode=getnode();
	node *tmp=head;
	int flag=1,count=1;
	if(pos==1)
	{
		newnode->next=head;
		head=newnode;
		return;
	}
	while(count!=pos-1)
	{
		tmp=tmp->next;
		if(tmp==NULL)
		{
			flag=0;
			break;
		}
		count++;
	}
	if(flag==1)
	{
		newnode->next=tmp->next;
		tmp->next=newnode;
	}
	else
	cout<<"\nPosition not found.";
}
void l_list::delete_l(int pos)
{
	if(pos==1)
	{
		node *temp=head;
		head=head->next;
		delete temp;
	}
	else
	{
		node *curr=head;
		curr=curr->next;
		node *temp=head;
		int count=1,flag=1;
		while(count!=pos-1)
		{
			curr=curr->next;
			temp=temp->next;
			if(curr==NULL)
			{
				flag=0;
				break;
			}
			count++;
		}
		if(flag==1)
		{
			temp->next=curr->next;
			delete curr;
			return;
		}
		else
		cout<<"\nPosition not found.";
	}
}
void l_list::display()
{
	cout<<"\nLinked List are: "<<endl;
	node *temp=head;
	while(temp!=NULL)
	{
		cout<<temp->data<<" ";
		temp=temp->next;
	}
}
int main()
{
	int pos;
	l_list list1;
	list1.create();
	list1.display();
	l_list list2;
	list2.create();
	cout<<"list created";
	list2.display();
	//list.insert_beg();
	//list.display();
	//cout<<"\nYou have called desired postion list entry system. please enter position where new node to be inserted."<<endl;
	//cin>>pos;
	//list.insert_des(pos);
	//list.display();
	//cout<<"\nEnter position to delete node: ";
	//cin>>pos;
	//list.delete_l(pos);
	//list.display();
	return 0;
}
