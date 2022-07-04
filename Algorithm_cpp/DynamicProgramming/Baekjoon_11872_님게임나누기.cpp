#include <bits/stdc++.h>
using namespace std;

int count(int n)
{
	int i;
	for(i=0;n!=0;i++) n&=(n-1);
	return i-1;
}

int main()
{
	int N, Win = 0, P, cnt = 0;
	scanf("%d",&N);
	while(N--)
	{
		scanf(" %d",&P);
		if (P % 4 == 0)	P--;
		else if (P % 4 == 3)	P++;
		Win ^= P;
	}
	if(cnt&1)	Win ? printf("cubelover\n") : printf("koosaga\n");
	else	Win ? printf("koosaga\n") : printf("cubelover\n");
	return 0;
}
