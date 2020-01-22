//bubble sort
#include<iostream>
#include<conio.h>
using namespace std;
void bsort(int[],int);
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
	bsort(a,n);
	cout<<"\nSorted array is: ";	
	for(int i=0;i<n;i++)
	{
		cout<<a[i]<<" ";
	}
	return 0;
}
void bsort(int a[],int n)
{
	int i,j,tmp;
	for(i=1;i<n;i++)
	{
		for(j=0;j<n-1;j++)
		{
			if(a[j]>a[j+1])
			{
				tmp=a[i];
				a[i]=a[j];
				a[j]=tmp;
			}
		}
	}
}
