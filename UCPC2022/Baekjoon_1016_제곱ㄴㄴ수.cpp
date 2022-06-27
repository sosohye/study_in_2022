#include <bits/stdc++.h>
using namespace std;

int main()
{
	long long m, M, temp, cnt = 0;
	scanf("%lld %lld",&m,&M);
	long long size = M - m + 1;
	bool chk[size] = {false};
	
	for(long long i=2;i*i<=M;i++)
	{
		long long i2 = i*i;
		long long temp = m/i2;
		if(m%i2)	temp++;
		while(temp*i2 <= M)
		{
			chk[temp*i2-m] = true;
			temp++;
		}
	}
	
	for(long long i=0;i<size;i++)	if(!chk[i])	cnt++;
	printf("%lld\n",cnt);
	
	return 0;
}
