#include <bits/stdc++.h>
using namespace std;
int DP[109][100009] = {0,};

int main()
{
	int N, K, W, V;
	scanf("%d %d",&N,&K);
	
	for(int i=1;i<=N;i++)
	{
		scanf("%d %d",&W,&V);
		for(int j=1;j<=K;j++)
		{
			if(j >= W)	DP[i][j] = max(DP[i-1][j],DP[i-1][j-W]+V);
			else	DP[i][j] = DP[i-1][j];
		}
	}
	
	printf("%d\n",DP[N][K]);
	return 0;
}
