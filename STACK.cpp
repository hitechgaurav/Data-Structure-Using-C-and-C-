//PROGRAM TO DESCRIBE STACK
#include<iostream>
#include<conio.h>
using namespace std;
class node
{
	public:
	int data;
	node *next;
};
class stack
{
	private:
	node *head,*top;
	public:
	stack();
	void create();
	node *getnode();
	void insert();
	void append(node*);
	void delete_s();
	void display();
};
stack::stack()
{
	head=top=NULL;
}
void stack::create()
{
	char ch;
	node *newnode;
	while(ch!='n')
	{
		newnode=getnode();
		if(top==NULL)
		{
			head=top=newnode;
		}
		else
		append(newnode);
		cout<<"\nPress n to break or else to continue: ";
		cin>>ch;
	}
}
void stack::append(node *newnode)
{
	if(top==NULL)
	{
		head=top=newnode;
	}
	else
	{
		top->next=newnode;
		top=top->next;
	}
}
void stack::insert()
{
	node *newnode;
	newnode=getnode();
	append(newnode);
}
node* stack::getnode()
{
	node *newnode;
	newnode=new node;
	cout<<"\nEnter data to new node: ";
	cin>>newnode->data;
	newnode->next=NULL;
	return newnode;
}
void stack::delete_s()
{
	if(top==NULL)
	{
		cout<<"\nEmpty.";
		return;
	}
	else
	{
		node *tmp=top;
		top=top->next;
		delete tmp;
	}
}
void stack::display()
{
	node *trav=head;
	while(trav!=NULL)
	{
		cout<<trav->data<<" ";
		trav=trav->next;
	}
}
int main()
{
	stack s;
	s.create();
	s.display();
	s.insert();
	s.display();
	s.delete_s();
	cout<<endl;
	s.display();
	return 0;
}
