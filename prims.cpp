#include<iostream>
#include<cstring>
#include<map>
using namespace std;

int main()
{
	int n,i,j,cost[10][10],min,visit[10],u,v,total=0,ne=1,pos;
	int s;
	
	map<int,string>m;

	cout<<"Enter number of cities";
	cin>>n;
	for(i=1;i<=n;i++)
	{	string city;
		cin>>city;
		m.insert(make_pair(i,city));
	}
	for(i=1;i<=n;i++)
		visit[i]=0;

	cout<<"Weighted Graph is==";
	
	
	
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=n;j++)
		{

			cin>>cost[i][j];
			if(cost[i][j]==0)
				cost[i][j]=999;
		}
	}

	cout<<"\nEnter the Source:";
	cin>>s;
		
	cout<<m[s];	
	visit[s]=1;

	while(ne<n)
	{
		min=999;
		for(i=1;i<=n;i++)
		{
			if(visit[i]==1)
			{

				for(j=1;j<=n;j++)

				{
					if(cost[i][j]<min && visit[j]==0)

					{
						min=cost[i][j]; //2

						u=i; //1

						v=j; //2
					}

				}
			}//end if
		}
		if(u!=v) //u=v=1 cycle
		{
			ne++;
			cout<<"\negde=="<<m[u]<<" to "<<m[v]<<"=="<<min;
			visit[u]=visit[v]=1;
			total+=min;
		}
		cout<<"\n Minimum cost="<<total;
	}
	return 0;
}
