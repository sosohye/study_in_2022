#include <bits/stdc++.h>
using namespace std;
int N, temp, num[109], diff[109];
set<int> s;

int gcd(int a, int b)
{
	return b ? gcd(b, a%b) : a;
}

int gcdOfDiff()
{
	int a = diff[0];
	for(int i=1;i<N;i++)
	{
		a = gcd(a,diff[i]);
	}
	return a;
}

void divisor(int n)
{
	for(int i=1;i*i<=n;i++)
		if(n%i==0)
		{
			s.insert(i);
			s.insert(n/i);
		}
}

int main()
{
	scanf("%d",&N);
	for(int i=0;i<N;i++)	scanf("%d",num+i);
	sort(num,num+N);
	for(int i=1;i<N;i++)	diff[i] = num[i] - num[i-1];
	
	divisor(gcdOfDiff());
	set<int>::iterator iter = s.find(1);
	s.erase(iter);
	for(iter = s.begin(); iter != s.end(); iter++)	printf("%d ",*iter);
	return 0;
}
