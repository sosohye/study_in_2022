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

pair<int, int> swap(pair<int, int> a)
{
	return make_pair(a.second, a.first);
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
	s.insert(swap(v[0]));
	s.insert(swap(v[1]));
	
	int minDist = dist(v[0],v[1]);
	int idx = 0;
	for(int i=2;i<n;i++)
	{
		while(idx<i)
		{
			int d = v[i].first - v[idx].first;
            if (d * d <= minDist)	break;
            else
			{
				s.erase(swap(v[idx]));
            	idx++;
			}
		}
		
        auto start = s.lower_bound(make_pair(v[i].second - int(sqrt(minDist)), -INF));
        auto end = s.upper_bound(make_pair(v[i].second + int(sqrt(minDist)), INF));
        for (auto it = start; it != end; it++)
            minDist = min(minDist, dist(make_pair(it->second, it->first), v[i]));
        s.insert(swap(v[i]));
	}
	
	printf("%d\n",minDist);
	return 0;
}
