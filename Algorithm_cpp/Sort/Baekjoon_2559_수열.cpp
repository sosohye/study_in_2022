#include <bits/stdc++.h>
using namespace std;

int main()
{
	int N, K, sum=0, max;
	scanf("%d %d",&N,&K);
	int temp[N];
	
	for(int i=0;i<N;i++)
	{
		scanf(" %d",temp+i);
		if(i<K)
		{
			sum += temp[i];
			if(i==K-1)	max = sum;
		}
		else{
			sum += temp[i]-temp[i-K];
			if(sum>max)	max=sum;
		}
	}
	
	printf("%d\n",max);
	return 0;
}
