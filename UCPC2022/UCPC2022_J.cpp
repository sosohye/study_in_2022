#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

bool isSquare(double n) {
    if( n - round(n) < 0.00000000000000000000001) return true;
    return false;
}

int main()
{
	int N;
	scanf("%d",&N);
	ll arr[N];
	ll sortArr[N];
	for(int i=0;i<N;i++)
	{
		scanf(" %lld",arr+i);
		sortArr[i] = arr[i];
	}
	sort(sortArr,sortArr+N);
	for(int i=0;i<N;i++)
	{
		if(!isSquare(sqrt(sortArr[i])*sqrt(arr[i])))
		{
			printf("NO\n");
			return 0;
		}
	}
	printf("YES\n");
	return 0;
}
