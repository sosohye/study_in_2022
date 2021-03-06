#include <bits/stdc++.h>
using namespace std;
int card[1009];
int DP[1009][1009][2] = {0,};

int choice(int start, int last, bool kw){
	int &ret = DP[start][last][kw];
	if(ret != -1) return ret;
	
	if(start == last){
		if(kw)
			return ret = card[start];
		else
			return ret = 0;
	}
	if(kw)
		return 	ret = max(choice(start+1,last,false)+card[start],choice(start,last-1,false)+card[last]);
	else
		return ret = min(choice(start+1,last,true),choice(start,last-1,true));
}

int main()
{
	int T, N;
	scanf("%d",&T);
	while(T--)
	{
		memset(DP,-1,sizeof(DP));
		scanf("%d",&N);
		for(int i=0;i<N;i++)
		{
			scanf(" %d",card+i);
		}
		
		printf("%d\n",choice(0,N-1,true));
	}
	return 0;
} 
