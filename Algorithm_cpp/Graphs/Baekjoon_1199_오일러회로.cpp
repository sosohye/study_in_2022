#include <bits/stdc++.h>
using namespace std;
int N, adjMtx[1009][1009], idx;
stack<pair<int, int>> v[1010];
vector<int> chk;

void dfs(int u){
    while(1){
        while(!v[u].empty() && chk[v[u].top().second]) v[u].pop();
        if(v[u].empty()) break;

        int x = v[u].top().first;
		int y = v[u].top().second;
		v[u].pop();
        chk[y] = 1;
		dfs(x);
    }

    printf("%d ",u);
}
int main()
{
	scanf("%d",&N);
	for(int i=1;i<=N;i++)
	{
		for(int j=1;j<=N;j++)
		{
			scanf(" %d",&adjMtx[i][j]);
		}
	}
	
    for(int i=1;i<=N;i++){
    	for(int j=i+1;j<=N;j++){
    		while(adjMtx[i][j]){
    			adjMtx[i][j]--, idx++;
    			v[i].push(make_pair(j,idx));
				v[j].push(make_pair(i,idx));
    		}
    	}
    }
    chk.resize(idx + 1);

    for(int i=1;i<=N;i++) if(v[i].size()%2) return !printf("-1");

    dfs(1);
	return 0;
}
