#include <bits/stdc++.h>
using namespace std;

int n, r, c;
int ans = 0;
void re(int x, int y, int size)
{
    if(c==x && r==y)
	{
        printf("%d\n",ans);
        return;
    }
    else if (c < x + size && r < y + size && c >= x && r >= y)
	{
        re(x, y, size / 2);
        re(x + size / 2, y, size / 2);
        re(x, y + size / 2, size / 2);
        re(x + size / 2, y + size / 2, size / 2);
    }
	else
	{
        ans += size * size;
    }
}
int main()
{
    scanf("%d %d %d",&n,&r,&c);
    re(0, 0, pow(2, n));
    return 0;
}

