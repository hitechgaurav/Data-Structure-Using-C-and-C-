//program to calculate power of a number using recursion
#include<iostream>
#include<conio.h>
using namespace std;
int op;
int power(int num,int pow)
{
	if(pow!=0)
	{
		op=num*power(num,pow-1);
			return op;
	}
	else
	return 1;
}
int main()
{
	int x;
	cout<<"\nEnter a number whose power to be calculated:- ";
	cin>>x;
	cout<<"\nPOWER UPTO:- ";
	int lim;
	cin>>lim;
	int z=1;
	z*=power(x,lim);
	cout<<"\nPower is:- "<<z;
	return 0;
}
