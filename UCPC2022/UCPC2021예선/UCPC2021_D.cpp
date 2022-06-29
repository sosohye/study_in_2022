#include <bits/stdc++.h>
using namespace std;

int main()
{
	int N, mA = 0, cnt = 0;
	long long ans = 0;
	scanf("%d",&N);
	char color[N+9];
	scanf("%s",color);
	vector<int> v;
	int A[N];
	for(int i=0;i<N;i++)	scanf(" %d",A+i);
	
	char pColor = color[0];
	for(int i=0;i<=N;i++)
	{
		if(i==N)
		{
			v.push_back(mA);
			cnt++;
		}
		else if(pColor != color[i])
		{
			v.push_back(mA);
			mA = 0;
			mA = max(mA,A[i]);
			cnt++;
			pColor = color[i];
		}
		else	mA = max(mA,A[i]);
	}
	if(!v.empty())	v.pop_back();
	if(!v.empty())	v.erase(v.begin());
	sort(v.begin(),v.end());
	
	//for(int i=0;i<v.size();i++)	printf("%d ",v[i]);
	//printf("\n");
	
	cnt = (cnt-1)/2;
	for(int i=0;i<cnt;i++)
	{
		ans += v.back();
		v.pop_back();
	}
	printf("%lld\n",ans);
	return 0;
}
