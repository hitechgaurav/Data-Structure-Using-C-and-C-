//Selection Sort
#include<iostream>
#include<conio.h>
using namespace std;
void selsort(int[],int);
int main()
{
	int n;
	cout<<"\nEnter size of array: ";
	cin>>n;
	int *a=new int[n];
	cout<<"\nEnter array to be sorted: "<<endl;
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}
	selsort(a,n);
	cout<<"\nSorted array is: ";	
	for(int i=0;i<n;i++)
	{
		cout<<a[i]<<" ";
	}
	return 0;
}
void selsort(int a[],int n)
{
	int i,j,min_pos,tmp;
	for(i=0;i<n-1;i++)
	{
		min_pos=i;
		for(j=i+1;j<n;j++)
		{
			if(a[j]<a[min_pos])
			{
				min_pos=j;
			}
			{
				tmp=a[i];
				a[i]=a[min_pos];
				a[min_pos]=tmp;
			}
		}
	}
}
