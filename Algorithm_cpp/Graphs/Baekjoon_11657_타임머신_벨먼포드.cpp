#include <bits/stdc++.h>
using namespace std;
#define INF 1e9

int N, M, info[6009][3];
long long dist[509];
bool negativeCycleChk = false;

int main()
{
	scanf("%d %d",&N,&M);
	for(int i=0;i<M;i++)	scanf(" %d %d %d",&info[i][0],&info[i][1],&info[i][2]);
	
	fill(dist+1,dist+N+1,INF);
	dist[1] = 0;
	
	for(int i=1;i<=N;i++)
		for(int j=0;j<M;j++)
		{
			if(dist[info[j][0]]!=INF && dist[info[j][1]]>dist[info[j][0]]+info[j][2])
			{
				dist[info[j][1]] = dist[info[j][0]]+info[j][2];
				if(i==N)	negativeCycleChk = true;
			}
		}
	
	if(negativeCycleChk)	printf("-1\n");
	else	for(int i=2;i<=N;i++)	printf("%lld\n",dist[i] != INF ? dist[i] : -1);
	
	return 0;
}
