#include <bits/stdc++.h>
using namespace std;
int col[20];
int N, cnt=0;

bool check(int level)
{
	for(int i = 0; i < level; i++)
        if(col[i] == col[level] || abs(col[level] - col[i]) == level - i)
            return false;
    return true;
}

void nqueen(int x)
{
    if(x == N)	cnt++;
    else
    {
        for(int i = 0; i < N; i++)
        {
            col[x] = i;
            if(check(x))	nqueen(x+1);
        }
    }
}

int main()
{
    scanf("%d",&N);
    nqueen(0);
    printf("%d\n",cnt);
    return 0;
}
