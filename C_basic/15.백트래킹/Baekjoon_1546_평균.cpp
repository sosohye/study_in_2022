#include <bits/stdc++.h>
using namespace std;

int main()
{
	int N, M = 0;
	double sum = 0;
	scanf("%d",&N);
	int score[N];
	for(int i=0;i<N;i++)
	{
		scanf(" %d",&score[i]);
		M = max(M,score[i]);
	}
	for(int i=0;i<N;i++)
		sum += (double)score[i]/(double)M*100;
	
	printf("%lf\n",sum/(double)N);
	return 0;
}
