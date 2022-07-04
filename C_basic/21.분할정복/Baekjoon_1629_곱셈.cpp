#include <bits/stdc++.h>
using namespace std;
long long A,B,C;

long long int pow(long long x, long long m)
{
    if (m == 0)	return 1;
    long long int half = pow(x, m / 2);
    half %= C;
    if (m&1)	return (((half * half) % C) *x) %C ;
    return (half * half) % C;
}

int main()
{
	scanf("%lld %lld %lld",&A,&B,&C);
	A %= C;
	printf("%lld\n",pow(A,B)%C);
	return 0;
}
