#include <bits/stdc++.h>
using namespace std;

int main()
{
	int N, Win = 0, cnt = 0;
	scanf("%d",&N);
	int P[N];
	for(int i=0;i<N;i++)
	{
		scanf(" %d",P+i);
		Win ^= P[i];
	}
	for(int i=0;i<N;i++)	if(P[i]>=(Win^P[i]))	cnt++;
	
	printf("%d\n",Win ? cnt : 0);
	return 0;
}
