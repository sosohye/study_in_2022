#include <bits/stdc++.h>
using namespace std;

#define INF (1 << 30)
int n, x, y;
vector<pair<int, int> > v;
set<pair<int, int> > s;

int dist(pair<int, int> a, pair<int, int> b)
{
	return (a.first-b.first)*(a.first-b.first) + (a.second-b.second)*(a.second-b.second);
}

int main()
{
	scanf("%d",&n);
	
	for(int i=0;i<n;i++)
	{
		scanf("%d %d",&x,&y);
		v.push_back(make_pair(x,y));
	}
	sort(v.begin(),v.end());
	s.insert(v[0]);
	s.insert(v[1]);
	
	int minDist = dist(v[0],v[1]);
	int idx = 0;
	for(int i=2;i<n;i++)
	{
		while(idx<i)
		{
			int d = v[i].first - v[idx].first;
            if (d * d > minDist)	s.erase(v[idx]);
            idx++;
		}
		
		for (set<pair<int, int> >::iterator iter = s.begin(); iter != s.end(); iter++)
			minDist = min(minDist, dist(*iter, v[i]));
        s.insert(v[i]);
	}
	
	printf("%d\n",minDist);
	return 0;
}
