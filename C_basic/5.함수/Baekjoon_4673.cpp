#include<stdio.h>
int isSelf[10009];

int d(int n)
{
	int sum = n;
	while(n>0)
	{
		sum += n%10;
		n /= 10;
	}
	return sum;
}

int main()
{
	int ans = 1;
	for(int i=1;i<10000;i++)
		isSelf[d(ans)]++;
	for(int i=1;i<=10000;i++)	if(!isSelf[i])	printf("%d\n",i);
	return 0;
}
