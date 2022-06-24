#include <bits/stdc++.h>
using namespace std;

long long N, x[100009];


long long f(long long x0)
{
	long long sum = 0;
	for(long long i=1;i<N;i++)	sum += abs(x0*i - x[i]);
	return sum;
}

int main()
{
	scanf("%lld",&N);
	for(int i=0;i<N;i++)	scanf(" %lld",x+i);
	
	long long lo = 0, hi = x[N-1];
    while(hi>lo){
        long long p = (lo + hi)/2; long long q = p+1;
        if(f(p) <= f(q)) hi = p;
        else lo = q;
    }
 
    
    printf("%lld\n", f(lo));
	return 0;
}
