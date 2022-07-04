#include<stdio.h>
#include<stdlib.h>
#include<queue>
using namespace std;
queue<int> Q;

int main()
{
	int N,k,cnt=0;
	scanf("%d %d",&N,&k);
	for(int i=0;i<N;i++)	Q.push(i+1);
	printf("<");
	while(!Q.empty())
	{
		cnt++;
		int x = Q.front();
		Q.pop();
		if(cnt%k)
		{
			Q.push(x);
		}
		else
		{
			if(Q.size())	printf("%d, ",x);
			else	printf("%d",x);
		}
	}
	printf(">");
	return 0;
}

