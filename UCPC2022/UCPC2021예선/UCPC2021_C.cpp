#include <bits/stdc++.h>
using namespace std;
double a, d, k, dp[100000009], p = 1, e = 0;
bool wh = true;


double pow(double x, int n)
{
	if(n==0)	return 1;
	else if ((n%2)==0)	return pow(x*x,n/2);
	else	return x * pow(x*x,(n-1)/2);
}

int main()
{
	scanf("%lf %lf %lf",&a,&d,&k);
	k = (double)1 + k/(double)100;
	
	int i=1;
	while(wh)
	{
		dp[i] = d*pow(k,i-1)/(double)100;
		if(dp[i]>=(double)1)
		{
			dp[i] = 1;
			wh = false;
		}
		e += (double)i*dp[i]*p;
		p *= (1-dp[i]);
		i++;
	}
	
	printf("%.7lf\n",a*e);
	return 0;
}
