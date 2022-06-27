#include <bits/stdc++.h>
using namespace std;

bool compare(const pair<int,int>& a, const pair<int,int>& b)
{
	if(a.first==b.first)	return a.second<b.second;
	return a.first<b.first;
}

int main()
{
	int N, K;
	scanf("%d %d",&N,&K);
	
	pair<int,int> J[N];
	int B[K];
	for(int i=0;i<N;i++)	scanf("%d %d",&J[i].first,&J[i].second);
	for(int i=0;i<K;i++)	scanf("%d",B+i);
	sort(J,J+N,compare);
	sort(B,B+K);
	
	int idx = 0;
	long long sum = 0;
	priority_queue<int> pq;
	for(int i=0;i<K;i++)
	{
		while(J[idx].first<=B[i] && idx<N)	pq.push(J[idx++].second);
		if(!pq.empty())
		{
			sum += (long long)pq.top();
			pq.pop();
		}
	}
	
	printf("%lld\n",sum);
	return 0;
}
