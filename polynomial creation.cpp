//Program to Create Polynomial and display Polynomial
#include<iostream>
#include<conio.h>
using namespace std;
class polynode
{
	public:
	int coef;
	int pow;
	polynode *next;	
};
class poly
{
			public:
			polynode *head,*tail;
			void ini();
			void create();
			void append(polynode*);
			polynode *getnode();
			void display();
			poly poly_add(poly*);
};
void poly::ini()
{
	head=tail=NULL;
}
void poly::create()
{
	polynode *newnode;
	char ch;
	while(ch!='n')
	{
		newnode=getnode();
		if(head==NULL)
		{
			head=tail=newnode;
		}
		else
		append(newnode);
		cout<<"\nPress n to break or else to continue. ";
		cin>>ch;
	}
}
void poly::append(polynode *newnode)
{
	if(tail==NULL)
	{
		head=tail=newnode;
	}
	else
	{
		tail->next=newnode;
		tail=tail->next;
	}
}
polynode* poly::getnode()
{
	polynode *newnode;
	newnode=new polynode;
	cout<<"\nEnter the Coefficient and Exponent of term:- ";
	cin>>newnode->coef;
	cin>>newnode->pow;
	newnode->next=NULL;
	return newnode;
}
void poly::display()
{
	polynode *tmp=head;
	cout<<"\nPolynomial is:- ";
	while(tmp!=NULL)
	{
		cout<<tmp->coef<<"x^"<<tmp->pow<<" ";
		tmp=tmp->next;
	}
}
poly poly::poly_add(poly *p2)
{
	polynode *ptr1=head;
	polynode *ptr2=p2->head;
	poly c;
	polynode *newterm;
	while(ptr1!=NULL&&ptr2!=NULL)
	{
		newterm=new polynode;
		newterm->next=NULL;
		if(ptr1->coef==ptr2->coef)
		{
			newterm->coef=ptr1->coef+ptr2->coef;
			newterm->pow=ptr1->pow;
			c.append(newterm);
			ptr1=ptr1->next;
			ptr2=ptr2->next;
		}
		else
		if(ptr1->coef>ptr2->coef)
		{
			newterm->coef=ptr1->coef;
			newterm->pow=ptr1->pow;
			c.append(newterm);
			ptr1=ptr1->next;
		}
		else
		if(ptr2->coef>ptr1->coef)
		{
			newterm->coef=ptr2->coef;
			newterm->pow=ptr2->pow;
			c.append(newterm);
			ptr2=ptr2->next;
		}
	}
	return c;
}
void main()
{
	poly p1,p2,p3;
	p1.ini();
	p1.create();
	p1.display();
	cout<<"\nPolynomial 1 created.";
	p2.ini();
	p2.create();
	p2.display();
	cout<<"\nPolynomial 2 created.";
	p3=p1.poly_add(p2);
	p3.display();	
	getch();
}
