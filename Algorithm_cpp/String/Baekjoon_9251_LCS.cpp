#include <bits/stdc++.h>
using namespace std;
char s1[1009], s2[1009];
int dp[1009][1009];

int main()
{
	int i, j;
	scanf("%s %s",s1+1,s2+1);
	for(i=1;s1[i];i++)
	{
		for(j=1;s2[j];j++)
		{
			if(s1[i]==s2[j])	dp[i][j] = dp[i-1][j-1] + 1;
			else dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
		}
	}
	printf("%d\n",dp[i-1][j-1]);
	return 0;
}
