#include <bits/stdc++.h>
using namespace std;
int B[300009];

bool compare(const pair<int,int>& a, const pair<int,int>& b)
{
	if(a.second==b.second)	return a.first>b.first;
	return a.second>b.second;
}

int BinarySearch(int len, int target)
{
	int low = 0, high = len - 1;
    
    while(low <= high){
    	int mid = (low + high) / 2;
        
        if(target == B[mid])	return mid;
        
        if(target < B[mid]){
        	high = mid - 1;
        }
        else if(target > B[mid]){
        	low = mid + 1;
        }
    }
    return low;
}

int main()
{
	int N, K;
	scanf("%d %d",&N,&K);
	pair<int,int> J[N];
	for(int i=0;i<N;i++)	scanf("%d %d",&J[i].first,&J[i].second);
	for(int i=0;i<K;i++)	scanf("%d",B+i);
	sort(J,J+N,compare);
	sort(B,B+K);
	int maxB = B[K-1];
	int chk[K]={0,};
	long long sum=0;
	
	for(int i=0;i<N;i++)
	{
		if(J[i].first<=maxB)
		{
			int idx = BinarySearch(K,J[i].first), wh=1;
			//printf("%d %d\n",i,idx);
			while(wh)
			{
				if(idx>=K)	wh=0;
				else if(chk[idx]==0)
				{
					//printf("%d\n",J[i].second);
					sum += (long long)J[i].second;
					chk[idx]=1; wh=0;
				}
				else	idx++;
			}
		}
	}
	printf("%lld\n",sum);
	return 0;
}
