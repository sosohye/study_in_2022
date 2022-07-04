#include <bits/stdc++.h>
using namespace std;
#define MAX 201

int N, M, S, H, cnt;
vector<int> adj[MAX];
int cow[MAX], shed[MAX], visited[MAX];

bool dfs(int from)
{
    visited[from] = true;
    for(int i=0; i<adj[from].size(); i++)
	{
        int to = adj[from][i];
        if(shed[to] == -1 || (!visited[shed[to]] && dfs(shed[to])))
		{
            cow[from] = to, shed[to] = from;
            return true;
        }
    }
    return false;
}

int main()
{
	scanf("%d %d",&N,&M);
	for(int i=1;i<=N;i++)
	{
		scanf("%d",&S);
		while(S--)
		{
			scanf(" %d",&H);
			adj[i].push_back(H);
		}
	}
	
	int cnt = 0;
    fill(cow+1, cow+N+1, -1);
	fill(shed+1, shed+M+1, -1);
	
    for(int i=1; i<=N; i++)
        if(cow[i] == -1)
		{
            fill(visited+1, visited+N+1, false);
            if(dfs(i)) cnt++;
        }
    
    printf("%d\n",cnt);
	return 0;
}
