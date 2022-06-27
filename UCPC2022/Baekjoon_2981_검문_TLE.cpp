#include <bits/stdc++.h>
using namespace std;
int N, temp, num[109];

int gcd(int a, int b)
{
	return b ? gcd(b, a%b) : a;
}

int gcdArr(int m)
{
	int a = num[0] - m;
	for(int i=1;i<N;i++)
	{
		a = gcd(a,num[i]-m);
	}
	return a;
}

int main()
{
	scanf("%d",&N);
	for(int i=0;i<N;i++)	scanf("%d",num+i);
	sort(num,num+N);
	set<int> s;
	for(int i=0;i<num[0];i++)
	{
		temp = gcdArr(i);
		if(temp!=1)	s.insert(temp);
	}
	
	for(set<int>::iterator itr = s.begin(); itr != s.end(); ++itr)	printf("%d ",*itr);
	return 0;
}
