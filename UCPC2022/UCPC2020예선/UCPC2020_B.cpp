#include <bits/stdc++.h>
using namespace std;
char A[21][25] = {"1","-2","1-3","-2-4","1-3-5","-2-4-6","1-3-5-7","-2-4-6-8","1-3-5-7-9","1-3-5-7-10","-2-4-6-8-11","1-3-5-7-9-12","1-3-5-7-10-13","-2-4-6-8-11-14","1-3-5-7-9-12-15","1-3-5-7-10-13-16","-2-4-6-8-11-14-17","1-3-5-7-9-12-15-18","1-3-5-7-10-13-16-19","-2-4-6-8-11-14-17-20"};
char B[3][20] = {"1-3-5-7-9-12-15-1","1-3-5-7-10-13-16-","-2-4-6-8-11-14-17"};

int remainder(int x, int a, int b)
{
	int r = a%(x+1);
	for(int i=0;i<b;i++)	r = (r*10)%(x+1);
	return r;
}

int main()
{
	int T,a,b;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d %d",&a,&b);
		if((a<21&&b==0)||(a<3&&b==1))	printf("%s\n",A[a*(b==1?10:1)-1]);
		else
		{
			int x = ceil(log10(a)+b);
			printf("x = %d\n",x);
			int r = remainder(x, a, b);
			printf("r = %d\n",r);
			
			
			
		}
	}
	
	return 0;
}
