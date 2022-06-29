#include <bits/stdc++.h>
using namespace std;

const int MAX = 17, N = 100009; //ceil(log_2(n))
int parent[N][MAX];
int depth[N];
vector<int> adj[N];
int n,m;

void dfs(int cur)
{
	for(int next:adj[cur])
	{
		if(depth[next]==-1)
		{
			parent[next][0] = cur;
			depth[next] = depth[cur] + 1;
			dfs(next);
		}
	}
	return;
}

int LCA(int u,int v)
{
	if(depth[u]<depth[v])	swap(u,v);
	
	int diff = depth[u] - depth[v];
	
	for(int i=0;diff!=0;++i)
	{
		if(diff&1)	u = parent[u][i];
		diff /= 2;
	}
	
	if(u!=v)
	{
		for(int i=MAX-1;i>=0;--i)
		{
			if(parent[u][i]!=-1&&parent[u][i]!=parent[v][i])
			{
				u = parent[u][i];
				v = parent[v][i];
			}
		}
		u = parent[u][0];
	}
	return u;
}

int main()
{
	scanf("%d",&n);
	fill(depth,depth+n+1,-1);
	memset(parent,-1,sizeof(parent));
	depth[1] = 0;
	
	for(int i=0;i<n-1;i++)
	{
		int from, to;
		scanf("%d %d",&from,&to);
		adj[from].push_back(to);
		adj[to].push_back(from);
	}
	
	dfs(1);
	
	for(int k=1;k<MAX;k++)
		for(int cur=1;cur<=n;cur++)
			if(parent[cur][k-1]!=-1)	parent[cur][k] = parent[parent[cur][k-1]][k-1];
	
	scanf("%d",&m);
	while(m--)
	{
		int u,v;
		scanf("%d %d",&u,&v);
		printf("%d\n",LCA(u,v));
	}
	
	return 0;
}
