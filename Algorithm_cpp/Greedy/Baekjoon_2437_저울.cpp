#include <bits/stdc++.h>
using namespace std;

int main()
{
	int N, ans = 1;
	scanf("%d",&N);
	int m[N];
	for(int i=0;i<N;i++)	scanf(" %d",m+i);
	sort(m,m+N);
	
	for(int i=0;i<N;i++)
	{
		if(m[i]>ans)
		{
			printf("%d\n",ans);
			return 0; 
		}
		ans += m[i];
	}
	
	printf("%d\n",ans);
	return 0;
}
