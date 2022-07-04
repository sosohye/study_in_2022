#include <bits/stdc++.h>
using namespace std;
int visited[32009] = {0,};
stack<int> s;
vector<int> student[32009];

void DFS (int v)
{  
  visited[v] = 1;
  
  s.push(v);
  if(student[v].size())
  	for(int i=0;i<student[v].size();i++)
	  	if(!visited[student[v][i]])
		  	DFS(student[v][i]);
  
  printf("%d ",s.top());
  s.pop();
}

void topologicalSort(int N)
{
  for (int i = 1; i <= N; i++)	if(!visited[i])	DFS(i);
}


int main()
{
	int N, M, A ,B;
	scanf("%d %d",&N,&M);
	
	for(int i=0;i<M;i++)
	{
		scanf("%d %d",&A,&B);
		student[B].push_back(A);
	}
	topologicalSort(N);
	
	return 0;
}
