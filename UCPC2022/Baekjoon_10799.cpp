#include <bits/stdc++.h>
using namespace std;

int main()
{
	int i=0,cnt=0,sum=0;
	char str[100009];
	scanf("%s",str);
	while(str[i])
	{
		if(str[i]=='(')
		{
			cnt++;
		}
		else
		{
			cnt--;
			if(str[i-1]=='(')	sum += cnt;
			else sum++;
		}
		i++;
	}
	printf("%d\n",sum);
	
	return 0;
	
}
