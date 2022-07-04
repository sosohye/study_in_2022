#include <bits/stdc++.h>
using namespace std;

int main()
{
	int N, Win = 0, P;
	scanf("%d",&N);
	while(N--)
	{
		scanf(" %d",&P);
		if(P&1)	P=(P+1)/2;
		else	P=P/2-1; 
		Win ^= P;
	}
	Win ? printf("koosaga\n") : printf("cubelover\n");
	return 0;
}
