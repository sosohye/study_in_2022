#include<stdio.h>
#include<stack>
using namespace std;

typedef struct {
	int data;
	int index;
}Seq;

stack<Seq> S;

int main()
{
	int N, x;
	scanf("%d",&N);
	int NGE[N];
	for(int i=0;i<N;i++)
	{
		scanf(" %d",&x);
		Seq s;
		s.data = x;
		s.index = i;
		while(!S.empty()&&S.top().data<x)
		{
			NGE[S.top().index] = x;
			S.pop();
		}
		S.push(s);
	}
	
	while(!S.empty())
	{
		NGE[S.top().index] = -1;
		S.pop();
	}
	
	for(int i=0;i<N;i++)
	{
		printf("%d ",NGE[i]);
	}
	
	return 0;
}
