#include <bits/stdc++.h>
using namespace std;

int main()
{
	int N, idx=0;
	long long cnt=0;
	scanf("%d",&N);
	int N2=N*N;
	int A[N];
	int B[N];
	int C[N];
	int D[N];
	vector<int> AB, CD;
	
	for(int i=0;i<N;i++)
	{
		scanf("%d %d %d %d",A+i,B+i,C+i,D+i);
	}
	
	for(int i=0;i<N;i++)
	{
		for(int j=0;j<N;j++)
		{
			AB.push_back(A[i]+B[j]);
			CD.push_back(C[i]+D[j]);
			idx++;
		}
	}
	sort(AB.begin(),AB.end());
	sort(CD.begin(),CD.end());
	
	int low, high;
	
	low = 0, high = N2-1;
	while(low<N2 && high>=0)
	{
		int s = AB[low] + CD[high];
		if(s==0)
		{
			int o = 0, t = 0;
			int temp = AB[low];
			while ((-CD[high] == temp) && high >= 0)
				o++, high--;
			while (AB[low]==temp && low<N2)
				t++, low++;
			cnt += (long long)o*t;
		}
		else if(s<0)	low++;
		else	high--;
	}
	
	printf("%lld\n",cnt);
	return 0;
}
