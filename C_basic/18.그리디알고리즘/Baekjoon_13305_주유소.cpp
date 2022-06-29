#include <bits/stdc++.h>
using namespace std;

int main()
{
	int N, minPrice = 1000000009, price;
	long long cost = 0;
	scanf("%d",&N);
	int d[N];
	for(int i=0;i<N-1;i++)	scanf(" %d",d+i);
	
	for(int i=0;i<N;i++)
	{
		scanf(" %d",&price);
		minPrice = min(minPrice,price);
		cost += 1LL*d[i]*minPrice;
	}
	printf("%lld\n",cost);
	return 0;
}
