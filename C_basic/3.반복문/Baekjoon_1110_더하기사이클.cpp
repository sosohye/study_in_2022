#include <bits/stdc++.h>
using namespace std;

int sum(int n)
{
	 
	return (n%10)*10 + (n/10 + n%10)%10;
}

int main()
{
	int N, tempN, cnt = 1;
	scanf("%d",&N);
	tempN = sum(N);
	while(N!=tempN)
	{
		tempN = sum(tempN);
		cnt++;
	}
	printf("%d\n",cnt);
	return 0;
}
