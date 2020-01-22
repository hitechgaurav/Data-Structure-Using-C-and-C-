//PROGRAM TO INTRODUCE GRAPH
#include<iostream>
#include<conio.h>
#define max 10
using namespace std;
class graphnode
{
	public:
		int vertex;
		graphnode *next;
		graphnode()
		{
			vertex=0;
			next=NULL;
		}
};
class graph
{
	public:
		int visited[max];
		graphnode *head[max];
		void create();
		graph();
		void display(int);
};
graph::graph()
{
	for(int i=0;i<max;i++)
	{
		head[i]=NULL;
	}
}
void graph::create()
{
	int n1,vertex,i,j,done=0;
	int n;
		cout<<"\nEnter number of nodes to construct a graph: ";
		cin>>n;
	graphnode *curr,*prev;
	for(i=0;i<n;i++)
	{
		if(!(head[i]=new graphnode))
		{
			cout<<"\nInsuuficient memory.";
			exit(0);
		}
		else
		{
			head[i]->vertex=(i+1);
			cout<<"\nEnter number of nodes adjacent to "<<i+1<<" :";
			cin>>n1;
			prev=head[i];
			for(j=0;j<n1;j++)
			{
				if(!(curr=new graphnode))
				{
					cout<<"\nError.";
					exit(0);
				}
				else
				{
					do
					{
						cout<<"\nEnter vertex value: ";
						cin>>vertex;
						if(vertex>n&&vertex<1)
						{
							cout<<"\nError. Vertex out of range.";
						}
						else
						curr->vertex=vertex;
						prev->next=curr;
						prev=curr;
						done=1;
					}
					while(done=0);
				}
			}
		}
	}
}
void graph::display(int v)
{
	graphnode *curr=head[1];
	while(curr!=NULL){
	cout<<curr->vertex<<" ";
	curr=curr->next;
}
}
int main()
{
	graph object;
	object.create();
	object.display(1);
	return 0;
}
