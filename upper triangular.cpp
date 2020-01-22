#include<iostream>
#include<conio.h>
using namespace std;
int main()
{
	int row,tmp;
	cout<<"\nRow and column should be equal"<<endl;
	cout<<"\nEnter numbers of row or column: ";
	cin>>row;
	int a[row][row];
	tmp=row-1;
	for(int i=0;i<row;i++)
	{
		for(int j=0;j<row;j++)
		{
			cin>>a[i][j];
		}
	}
	cout<<"\nThe matrix you have entered is: "<<endl;
	for(int i=0;i<row;i++)
	{
		for(int j=0;j<row;j++)
		{
			cout<<a[i][j]<<" ";
		}
		cout<<"\n";
	}
	int flag;
	for(int k=0;k<=tmp;k++)
	{
		for(int t=0;t<=k;t++)
		{
			if(a[k][t]==0)
			{
				flag=1;
			}
			else
			flag=0;
		}
	}
	if(flag==1)
	{
		cout<<"\nThe matrix is upper traingular.";
	}
	else if(flag==0)
	cout<<"\nThe matrix is not upper traingular.";
	return 0;	
}
