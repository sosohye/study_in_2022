#include <bits/stdc++.h>
using namespace std;

int main()
{
	int N,K,i,temp;
	scanf("%d %d",&N,&K);
	queue<int> q;
	for(i=1;i<N+1;i++)	q.push(i);
	printf("<");
	i=0;
	while(q.size())
	{
		i++;
		temp = q.front();
		q.pop();
		if(i%K)	q.push(temp);
		else if(i%K==0 && q.size()!=0)	printf("%d, ",temp);
		else	printf("%d>",temp);
	}
	return 0;
}
