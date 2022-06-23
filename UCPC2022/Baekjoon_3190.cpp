#include <bits/stdc++.h>
using namespace std;

int main()
{
	pair<int,int> dir[4] = { make_pair(0,1), make_pair(1,0), make_pair(0,-1), make_pair(-1,0) };
	int signal[109][2];
	int xHead=1, yHead=1, N, K, L, x, y, d=0, cnt=0, id=0;
	char c;
	int map[103][103];
	for(int i=1;i<101;i++)	for(int j=1;j<101;j++)	map[i][j]=0;
	scanf("%d",&N);
	map[1][1]=2;
	deque<pair<int,int> > dq;
	dq.push_front(make_pair(1,1));
	scanf("%d",&K);
	for(int i=0;i<K;i++)
	{
		scanf("%d %d",&x,&y);
		map[x][y]=1;
	}
	scanf("%d",&L);
	for(int i=0;i<L;i++)
	{
		scanf("%d %c",&signal[i][0],&c);
		if(c=='L')	signal[i][1] = 3;
		if(c=='D')	signal[i][1] = 1;
	}
	while(1)
	{
		xHead+=dir[d].first;
		yHead+=dir[d].second;
		//printf("%d %d\n",xHead,yHead);
		dq.push_front(make_pair(xHead,yHead));
		cnt++;
		if(xHead>N||yHead>N||xHead<1||yHead<1){
			printf("%d\n",cnt);
			//printf("%d %d\n",xHead,yHead);
			return 0;
		}
		if(map[xHead][yHead]==2){
			printf("%d\n",cnt);
			//printf("%d %d\n",xHead,yHead);
			return 0;
		}
		if(map[xHead][yHead]==0){
			map[dq.back().first][dq.back().second] = 0;
			dq.pop_back();
		}
		map[xHead][yHead]=2;
		if(cnt==signal[id][0])
		{
			d = (d+signal[id][1])%4;
			id++;
		}
	}

	return 0;
}
