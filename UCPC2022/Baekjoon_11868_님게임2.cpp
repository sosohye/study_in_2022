#include <bits/stdc++.h>
using namespace std;

int main()
{
	int N, Win = 0, P;
	scanf("%d",&N);
	while(N--)
	{
		scanf(" %d",&P);
		Win ^= P;
	}
	Win ? printf("koosaga\n") : printf("cubelover\n");
	return 0;
}
