#include <bits/stdc++.h>
using namespace std;
int m[129][129];
int w_cnt = 0, b_cnt = 0, n; 

void div_conq(int x, int y, int N)
{
	int tmp_cnt = 0;
	for (int i = x; i < x + N; i++)
	{
		for (int j = y; j < y + N; j++)
		{
			if (m[i][j])	tmp_cnt++;
		}
	}
	if (!tmp_cnt) w_cnt++;
	else if (tmp_cnt == N * N) b_cnt++;
	else
	{
		div_conq(x, y, N / 2);
		div_conq(x, y + N / 2, N / 2);
		div_conq(x + N / 2, y, N / 2);
		div_conq(x + N / 2, y + N / 2, N / 2);
	}
	return;
}

int main()
{
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			scanf("%d", &m[i][j]);
	div_conq(0, 0, n);
	printf("%d\n", w_cnt);
	printf("%d\n", b_cnt);
	return 0;
}
