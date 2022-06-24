#include <bits/stdc++.h>
using namespace std;
int card[1009];
int DP[1009][1009][2] = {0,};

int choice(int start, int last, bool knwoo){
	int &ret = DP[start][last][knwoo];
	if(ret != -1) return ret;
	
	if(start == last){
		if(knwoo)
			return ret = card[start];
		else
			return ret = 0;
	}
	// 근우 차례에서는 왼쪽, 오른쪽 중 하나 '취하고' 게임 진행 했을 때 '최대'값.
	if(knwoo)
		return 	ret = max(choice(start+1,last,false)+card[start],choice(start,last-1,false)+card[last]);
	// 명우 차례에서는 왼쪽, 오른쪽 중 하나를 '없애고' 게임 진행 했을 때 '최소'값
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
