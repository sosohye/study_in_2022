#include<stdio.h>

long long sum(int* a, int n)
{
	long long x = 0;
	for(int i=0;i<n;i++)
		x += a[i];
	return x;
}

int main()
{
	int a[5] = {1,2,3,4,5};
	printf("%lld\n",sum(a,5));
}
