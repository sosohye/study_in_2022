#include <bits/stdc++.h>
using namespace std;
#define ABS(x)	( ((x)<0)?-(x):(x) )

int main()
{
	int N, i1, i2, absMin=2000000000, ans1, ans2;
	scanf("%d",&N);
	int p[N];
	for(int i=0;i<N;i++)	scanf(" %d",p+i);
	sort(p,p+N);
	i1=0; i2=N-1;
	
	while(i1!=i2)
	{
		if(absMin>ABS(p[i1]+p[i2]))
		{
			absMin = ABS(p[i1]+p[i2]);
			ans1=i1;	ans2=i2;
		}
		
		if(p[i1]+p[i2]<0)
		{
			i1++;
		}
		else if(p[i1]+p[i2]==0)
		{
			printf("%d %d\n",p[i1],p[i2]);
			return 0;
		}
		else
		{
			i2--;
		}
	}
	
	printf("%d %d\n",p[ans1],p[ans2]);
	return 0;
}
