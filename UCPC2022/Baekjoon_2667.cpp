#include <bits/stdc++.h>
using namespace std;
char arr[30][30];
int chk[30][30] = { 0, };
int moveX[4] = {1,0,-1,0};
int moveY[4] = {0,1,0,-1};
int s = 0;
int answer[1009];

int DFS(int x, int y)
{
	chk[x][y] = 1;
	s++;
	for(int i=0;i<4;i++)
	{
		int nextX = x + moveX[i];
		int nextY = y + moveY[i];
		
		if(arr[nextX][nextY] == '1' && !chk[nextX][nextY])	DFS(nextX,nextY);
	}
	return s;
}

int main()
{
	int N, cnt=0;
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
				s = 0;
				answer[cnt] = DFS(i,j);
				cnt++;
			}
		}
	}
	
	sort(answer,answer+cnt);
	printf("%d\n",cnt);
	for(int i=0;i<cnt;i++)	printf("%d\n",answer[i]);
	
	return 0;
}
