#include <bits/stdc++.h>
using namespace std;

bool cmp(pair<int, int> a, pair<int, int> b){
    if(a.second == b.second) 
        return a.first < b.first;
    else 
        return a.second < b.second;
}

int main()
{
	int n,d,h,o;
	int answer = 0;
	vector<pair<int, int> > v;
	priority_queue<int,vector<int>,greater<int> > pq;
	
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		scanf("%d %d",&h,&o);
		if(h<o)	v.push_back(make_pair(h,o));
		else	v.push_back(make_pair(o,h));
	}
	scanf("%d",&d);
	
	sort(v.begin(), v.end(), cmp);
	
	for(int i=0;i<v.size();i++)
	{
		int start = v[i].first;
		int end = v[i].second;
		
		if(end-start<=d)	pq.push(start);
		
		while(!pq.empty())
		{
			if(pq.top()+d<end)	pq.pop();
			else
			{
				answer = max(answer,(int)pq.size());
				break;
			}
		}
	}
	printf("%d\n",answer);
	return 0;
}
