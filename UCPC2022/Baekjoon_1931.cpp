#include <bits/stdc++.h>
using namespace std;

bool compare(const pair<int,int>& a, const pair<int,int>& b)
{
	if(a.second==b.second)	return a.first<b.first;
	return a.second<b.second;
}

int main()
{
	pair<int,int> data[100009];
	int N, time=0, cnt=0;
	scanf("%d",&N);
	for(int i=0;i<N;i++)	scanf("%d %d",&data[i].first,&data[i].second);
	sort(data, data+N, compare);
	
	for(int i=0;i<N;i++)
	{
		if(time<=data[i].first)
		{
			time = data[i].second;
			cnt++;
		}
	}
	printf("%d\n",cnt);
	return 0;
}
