#include<iostream>

#include<queue>

using namespace std;

int Graph[10][10];
void DFS(int start,int n,int v[]){
	cout<<start;
	v[start]=1;
	for(int i=1;i<=n;i++)
	{
		if(Graph[start][i]==1 &&(!v[i])){
			DFS(i,n,v);
		}
	}
}
void BFS(int s,int n){
	int visits[n];
	for(int i=1;i<=n;i++)
		visits[i]=0;
	int v;
	if(!visits[s]){
		queue<int>q;
		
		q.push(s);
		visits[s]=1;
	
		while(!q.empty())
		{	v=q.front();
			for(int i=1;i<=n;++i)
			{	if(Graph[v][i]==1 &&(visits[i]==0)){
					
					visits[i]=1;
					q.push(i);
				}	
			}
			q.pop();
			cout<<v<<" ";
		}
	}
}
			
	


int main()
{	
	
	//user input adjacency matrix
	int n;
	cout<<"Enter the number of nodes in graph="; 
	cin>>n;
	cout<<"enter the edge is present or not  if edge present--enter 1 else--enter 0"<<endl;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			
			cin>>Graph[i][j];
		}
	
	}
	int visits[n];
	for(int i=1;i<=n;i++)
	{
		visits[i]=0;
	}
	int source;
	cout<<"Enter the source=";
	cin>>source;
	BFS(source,n);
	
	

return 0;
}



































