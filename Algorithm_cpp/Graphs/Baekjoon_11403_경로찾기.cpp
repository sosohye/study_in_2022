#include <bits/stdc++.h>
using namespace std;
int adj[109][109];

int main()
{
	int N;
	scanf("%d",&N);
	for(int i=1;i<=N;i++)
		for(int j=1;j<=N;j++)
			scanf(" %d",&adj[i][j]);
	
	for(int k = 1; k<= N; k++)
    	for(int i = 1; i <= N; i++)
        	for(int j = 1; j<=N; j++)
            	adj[i][j] = adj[i][j] || (adj[i][k]&&adj[k][j]) ? 1 : 0;
    
    for(int i=1;i<=N;i++)
    {
    	for(int j=1;j<=N;j++)
		{
			printf("%d ",adj[i][j]);
		}
		printf("\n");
	}

	return 0;
}
