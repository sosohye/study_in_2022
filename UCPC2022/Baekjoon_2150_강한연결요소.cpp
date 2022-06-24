#include <bits/stdc++.h>
using namespace std;

int id, d[10001];
bool finished[10001];
vector<int> a[10001];
vector<vector<int> > SCC;
stack<int> s;

int SCCdfs(int x)
{
	d[x] = ++id;
	s.push(x);
	
	int parent = d[x];
	for(int i=0;i<a[x].size();i++)
	{
		int y = a[x][i];
		if(d[y]==0)	parent = min(parent, SCCdfs(y));
		else if (!finished[y])	parent = min(parent, d[y]);
	}
	
	if(parent == d[x])
	{
		vector<int> scc;
		while(1)
		{
			int temp = s.top();
			scc.push_back(temp);
			finished[temp] = true;
			s.pop();
			if(temp==x) break;
		}
		SCC.push_back(scc);
	}
	return parent;
}

int main()
{
	int V, E, A, B;
	scanf("%d %d",&V,&E);
	for(int i=0;i<E;i++)
	{
		scanf("%d %d",&A,&B);
		a[A].push_back(B);
	}
	for(int i=1;i<=V;i++)	if(!d[i])	SCCdfs(i);
	
	A = SCC.size();
	printf("%d\n",A);
	
	for(int i=0;i<A;i++)
	{
		sort(SCC[i].begin(),SCC[i].end());
	}
	sort(SCC.begin(),SCC.end());
	
	for(int i=0;i<A;i++)
	{
		B = SCC[i].size();
		for(int j=0;j<B;j++)	printf("%d ",SCC[i][j]);
		printf("-1\n");
	}
	
	return 0;
}
