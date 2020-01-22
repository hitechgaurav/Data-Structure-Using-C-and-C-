//binary search
#include<iostream>
#include<conio.h>
using namespace std;
int bsearch(int[],int,int);
int main()
{
	int size;
	cout<<"\nEnter size of an array: ";
	cin>>size;
	int  *arr=new int[size];
	cout<<"\nEnter the array in sorted manner: ";
	for(int i=0;i<size;i++)
	{
		cin>>arr[i];
	}
	cout<<"\nEnter element to search: ";
	int elem;
	cin>>elem;
	int pos=bsearch(arr,size,elem);
	if(pos==-1)
	{
		cout<<"\nElement not found.";
	}
	else
	cout<<"\nElement found at "<<pos+1<<"th position.";
	return 0;
}
int bsearch(int a[],int size,int key)
{
	int lo=0,hi=size-1,mid;
	while(lo<=hi)
	{
		mid=(lo+hi)/2;
		if(a[mid]==key)
		{
			return mid;
		}
		else if(a[mid]<key)
		{
			lo=mid+1;
		}
		else if(a[mid]>key)
		{
			hi=mid-1;
		}
	}
	return -1;
}
