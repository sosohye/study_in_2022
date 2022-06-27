#include <bits/stdc++.h>
using namespace std;

int main()
{
	int N, M, A, B, C;	
	scanf("%d",&N);
	scanf("%d",&M);
	
	vector<pair<int,int> > v[N+1];
	priority_queue<pair<int,int>, vector<pair<int,int> >, greater<pair<int,int> > > pq;
	bool chk[N+1] = {false, };
	
	while(M--)
	{
		scanf("%d %d %d",&A,&B,&C);
		v[A].push_back(make_pair(C,B));
		v[B].push_back(make_pair(C,A));
	}
	
	int pos;
	long long sum = 0;
	pq.push(make_pair(0,1));
	for(int j=1;j<=N;j++)
	{
		while(!pq.empty())
		{
			pos = pq.top().second;
			if(!chk[pos])
			{
				sum += pq.top().first;
				break;
			}
			pq.pop();
		}
		chk[pos] = true;
		for(int i=0;i<v[pos].size();i++)	pq.push(v[pos][i]);
	}

	printf("%lld\n",sum); 
	return 0;
}
