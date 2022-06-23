#include<bits/stdc++.h>
using namespace std;
#define INF 987654321


int main()
{
	int V,E,s,u,v,w;
	scanf("%d %d",&V,&E);
	scanf("%d",&s);
	
	int d[V+1];
	for(int i=1;i<V+1;i++)	d[i]=INF;
	d[s]=0;
	vector<pair<int,int> > e[V+1];
	priority_queue<pair<int,int>,vector<pair<int,int> >,greater<pair<int,int> > > pq;
	
	for(int i=0;i<E;i++)
	{
		scanf("%d %d %d",&u,&v,&w);
		e[u].push_back(make_pair(v,w));
	}
	
	pq.push(make_pair(0,s));
	
	while(!pq.empty())
	{
		int x = pq.top().second;
		int costStoX = pq.top().first;
		pq.pop();
		for(int i=0;i<e[x].size();i++)
		{
			int y = e[x][i].first;
			int costXtoY = e[x][i].second;
			
			if(costStoX+costXtoY<d[y])
			{
				d[y] = costStoX + costXtoY;
				pq.push(make_pair(d[y],y));
			}
		}
	}
	
	for(int i=1;i<V+1;i++)
	{
		if(d[i]==INF)	printf("INF\n");
		else	printf("%d\n",d[i]);
	}
    
    return 0;

}

