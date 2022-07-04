#include <bits/stdc++.h>
using namespace std;
int root[1000009];
int deg[1000009];

int Find(int x)
{
	return root[x] == x ? x : Find(root[x]);
}

void Union(int x, int y)
{
	x = Find(x);
	y = Find(y);
	if(deg[root[x]] < deg[root[y]])	root[x] = y;
	else if(deg[root[x]] > deg[root[y]])	root[y] = x;
	else
	{
		root[x] = y;
		deg[root[y]]++;
	}
}

int main()
{
	int n,m,t,a,b;
	scanf("%d %d",&n,&m);
	for(int i=0;i<=n;i++)	root[i]=i;
	
	while(m--)
	{
		scanf("%d %d %d",&t,&a,&b);
		if(t==0)	Union(a,b);
		else	Find(a) == Find(b) ? printf("YES\n") : printf("NO\n");
	}
	
	return 0;
}
