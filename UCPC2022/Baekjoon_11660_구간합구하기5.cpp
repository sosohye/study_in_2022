#include <bits/stdc++.h>
using namespace std;
int arr[1100][1100] = {0,};
int prefixSum[1100][1100] = {0,};

int main()
{
	int N, M, x1, y1, x2, y2, ans;
	scanf("%d %d",&N,&M);
	for(int i=1;i<=N;i++)
	{
		for(int j=1;j<=N;j++)
		{
			scanf(" %d",&arr[i][j]);
			prefixSum[i][j] = arr[i][j] + prefixSum[i-1][j] + prefixSum[i][j-1] - prefixSum[i-1][j-1];
		}
	}
	for(int i=0;i<M;i++)
	{
		scanf("%d %d %d %d",&x1, &y1, &x2, &y2);
		ans = prefixSum[x2][y2] - prefixSum[x1-1][y2] - prefixSum[x2][y1-1] + prefixSum[x1-1][y1-1];
		printf("%d\n",ans);
	}
	
	return 0;
}
