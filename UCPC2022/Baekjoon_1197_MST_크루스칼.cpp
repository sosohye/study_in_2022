#include <bits/stdc++.h>
using namespace std;

int root[10009];
int deg[10009];

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
	int V, E, sum=0, A, B, C;
	vector<tuple<int,int,int> > v;	
	scanf("%d %d",&V,&E);
	for(int i=1;i<=V;i++)	root[i]=i;
	
	for(int i=0;i<E;i++)
	{
		scanf("%d %d %d",&A,&B,&C);
		v.push_back(make_tuple(C,A,B));
	}
	sort(v.begin(),v.end());
	
	for(int i=0;i<E;i++)
	{
		if(Find(get<1>(v[i])) != Find(get<2>(v[i])))
		{
			sum += get<0>(v[i]);
			Union(get<1>(v[i]),get<2>(v[i]));
		}
	}
	
	printf("%d\n",sum); 
	return 0;
}
