#include <bits/stdc++.h>
using namespace std;


int main()
{
	int N, M, K, S, T, a, b, t;
	scanf("%d %d %d %d %d",&N, &M, &K, &S, &T);
	vector<tuple<int,int,int> > C;
	long long dp[N][K+1];
	
	for(int i=0;i<N;i++)
		for(int j=0;j<=K;j++)
			dp[i][j] = -1;
	
	while(M--)
	{
		scanf("%d %d %d",&a,&b,&t);
		C.push_back(make_tuple(a,b,t));
	}
	
	for(int i=0;i<C.size();i++)
	{
		if(get<0>(C[i])==S)
		{
			dp[get<0>(C[i])][0] = 0;
			dp[get<1>(C[i])][0] = dp[get<0>(C[i])][0] + get<2>(C[i]);
		}
		if(get<1>(C[i])==S)
		{
			dp[get<0>(C[i])][1] = 0;
		}
	}
	
	for(int k=1;k<=K;k++)
	{
		for(int i=0;i<C.size();i++)
		{
			if(dp[get<0>(C[i])][k] != -1)	dp[get<1>(C[i])][k] = max( dp[get<0>(C[i])][k] + get<2>(C[i]), dp[get<1>(C[i])][k] );
			if(dp[get<1>(C[i])][k-1] != -1)	dp[get<0>(C[i])][k] = max( dp[get<1>(C[i])][k-1], dp[get<0>(C[i])][k] );
		}
	}
	printf("%lld",dp[T][K]);
	
	return 0;
}
