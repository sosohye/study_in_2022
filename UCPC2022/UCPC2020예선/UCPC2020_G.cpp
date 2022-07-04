#include <bits/stdc++.h>
using namespace std;
#define INF 200001
int N,M,a, chk[INF], rumorFriends[INF], temp[INF], time;
vector<int> adj[INF];
queue<int> q;

void initTemp()
{
	for(int i=0;i<N;i++)	temp[i]=0;
}
int main()
{
	scanf("%d",&N);
	for(int i=1;i<=N;i++)
	{
		chk[i] = -1;
		while(1)
		{
			scanf("%d",&a);
			if(!a)	break;
			adj[i].push_back(a);
		}
	}
	scanf("%d",&M);
	
	for(int i=0;i<M;i++)
	{
		scanf(" %d",&a);
		q.push(a);
		chk[a] = 0;
	}
	
	while(!q.empty())
	{
		int pos = q.front(); q.pop();
		for(int i=0;i<adj[pos].size();i++)
		{
			int next = adj[pos][i];
			if(chk[next]==-1 && adj[next].size()<=2*rumorFriends[next])
			{
				chk[next] = chk[pos]+1;
				q.push(next);
			}
		}
	}
	
	for(int i=1;i<=N;i++)	printf("%d ",chk[i]);

	return 0;
}
