#include <bits/stdc++.h>
using namespace std;
char arr[30][30];
int chk[30][30] = { 0, };
int moveX[4] = {1,0,-1,0};
int moveY[4] = {0,1,0,-1};
int answer[1009];
int N, cnt=0;

bool isVaild(int x,int y)
{
	return x>=0 && y>=0 && x<N && y<N;
}

int BFS(int x, int y)
{
	int s = 0;
	queue<pair<int,int> > q;
	q.push(make_pair(x,y));
	chk[x][y] = 1;
	s++;
	
	int x0, y0, x1, y1;
	while(!q.empty())
	{
		x0 = q.front().first;
		y0 = q.front().second;
		//printf("%d %d\n",x0,y0);
		q.pop();
		for(int i=0;i<4;i++)
		{
			x1 = x0 + moveX[i];
			y1 = y0 + moveY[i];
			if(!chk[x1][y1] && isVaild(x1,y1) && arr[x1][y1] == '1')
			{
				q.push(make_pair(x1,y1));
				chk[x1][y1] = 1;
				s++;
			}
		}
	}
	
	return s;
}

int main()
{
	scanf("%d",&N);
	for(int i=0;i<N;i++)
	{
		scanf("%s",&arr[i][0]);
	}
	for(int i=0;i<N;i++)
	{
		for(int j=0;j<N;j++)
		{
			if(arr[i][j] == '1' && !chk[i][j])
			{
				answer[cnt] = BFS(i,j);
				cnt++;
			}
		}
	}
	
	sort(answer,answer+cnt);
	printf("%d\n",cnt);
	for(int i=0;i<cnt;i++)	printf("%d\n",answer[i]);
	
	return 0;
}
