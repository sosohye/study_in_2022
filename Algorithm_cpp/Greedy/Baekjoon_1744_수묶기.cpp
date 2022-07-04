#include <bits/stdc++.h>
using namespace std;

int main()
{
	int N, A, B, sum = 0;
	scanf("%d",&N);
	priority_queue<int> plusPQ;
	priority_queue<int, vector<int>, greater<int> > minusPQ;
	
	while(N--)
	{
		scanf("%d",&A);
		if(A>0)	plusPQ.push(A);
		else	minusPQ.push(A);
	}
	
	while(plusPQ.size()>1)
	{
		A = plusPQ.top();	plusPQ.pop();
		B = plusPQ.top();	plusPQ.pop();
		if(A==1||B==1)	sum += A+B;
		else	sum += A*B;
	}
	if(!plusPQ.empty())	sum += plusPQ.top();
	
	while(minusPQ.size()>1)
	{
		A = minusPQ.top();	minusPQ.pop();
		B = minusPQ.top();	minusPQ.pop();
		sum += A*B;
	}
	if(!minusPQ.empty())	sum += minusPQ.top();
	
	printf("%d\n",sum);
	return 0;
}
