#include <bits/stdc++.h>
using namespace std;

#define MAX 502
#define INF 1e9

int N, M , ans, Capacity, T, H, Sour, Sink;
int c[MAX][MAX], f[MAX][MAX], d[MAX]; // c: capacity of Edge, f: flow,
vector<int>	a[MAX]; // a: adj list of Graph

void maxFlow(int start, int end)
{
	while(1)
	{
		fill(d,d+MAX,-1);
		queue<int> q;
		q.push(start);
		while(!q.empty())
		{
			int x = q.front();
			q.pop();
			for(int i=0;i<a[x].size();i++)
			{
				int y = a[x][i];
				if(c[x][y] - f[x][y] > 0 && d[y] == -1)
				{
					q.push(y);
					d[y] = x;
					if(y == end)	break;
				}
			}
			if(d[end] != -1)	break;
		}
		if(d[end] == -1)	break;
		int flow = INF;
		for(int i=end;i!=start;i=d[i])
		{
			flow = min(flow, c[d[i]][i] - f[d[i]][i]);
		}
		for(int i=end;i!=start;i=d[i])
		{
			f[d[i]][i] += flow;
			f[i][d[i]] -= flow;
		}
		ans += flow;
	}
}

int main()
{
	scanf("%d %d",&N,&M);
	while(M--)
	{
		scanf("%d %d %d",&T, &H, &Capacity);
		if(T!=H && Capacity)
		{
			a[T].push_back(H);
			a[H].push_back(T);
			c[T][H] += Capacity;
			c[H][T] += Capacity;
		}
		
	}
	scanf("%d %d",&Sour,&Sink);
	maxFlow(Sour,Sink);
	
	printf("%d\n",ans);
	return 0;
}
