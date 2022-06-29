#include <bits/stdc++.h>
using namespace std;

int main()
{
	int N, K, cnt = 0;
	scanf("%d %d",&N,&K);
	int A[N];
	for(int i=0;i<N;i++)	scanf("%d",A+i);
	for(int i=N-1;i>=0;i--)
	{
		int num = K/A[i];
		cnt += num;
		K -= num*A[i];
	}
	printf("%d\n",cnt);
	return 0;
}
