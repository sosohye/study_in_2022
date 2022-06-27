#include <bits/stdc++.h>
using namespace std;

int main()
{
	int N, Win = 0, P, flag = 0;
	scanf("%d",&N);
	while(N--)
	{
		scanf(" %d",&P);
		Win ^= P;
		flag |= Win>1;
	}
	
	if(flag)	Win ? printf("koosaga\n") : printf("cubelover\n");
	else	Win ? printf("cubelover\n") : printf("koosaga\n");
	return 0;
}
