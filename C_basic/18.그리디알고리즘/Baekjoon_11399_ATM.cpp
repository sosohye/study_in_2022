#include <bits/stdc++.h>
using namespace std;

int main()
{
	int N, sum = 0, ans = 0;
	scanf("%d",&N);
	int P[N];
	for(int i=0;i<N;i++)	scanf(" %d",P+i);
	sort(P,P+N);
	for(int i=0;i<N;i++)
	{
		sum += P[i];
		ans += sum;
	}
	printf("%d\n",ans);
	return 0;
}
