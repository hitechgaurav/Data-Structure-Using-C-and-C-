#include<iostream>
#include<conio.h>
using namespace std;
long int moves;
void toh(int disk,char a,char b,char c)
{
	moves++;
	if(disk==1)
	{
		cout<<"Move from "<<a<<"to"<<c<<endl;
		return;
	}
	else
	{	
		toh(disk-1,a,c,b);
		cout<<"Move from "<<a<<"to"<<c<<endl;
		toh(disk-1,b,a,c);
	}
}
int main()
{
	int disk;
	cout<<"\nEnter number of disks:- ";
	cin>>disk;
	toh(disk,'A','B','C');
	cout<<"\nNumber of required moves are:- "<<moves;
	return 0;
}
