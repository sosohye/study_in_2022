#include <bits/stdc++.h>
using namespace std;

int main()
{
	char s[55], num[9];
	int sum = 0;
	scanf("%s",s);
	int len = strlen(s);
	bool chkMinus = false;
	
	for(int i=0,j=0;i<=len;i++)
	{
		if(s[i]=='-')
		{
			if(chkMinus)	sum -= stoi(num);
			else	sum += stoi(num);
			j=0;
			memset(num, 0, sizeof(num));
			chkMinus = true;
		}
		else if(s[i]=='+' || i == len)
		{
			if(chkMinus)	sum -= stoi(num);
			else	sum += stoi(num);
			j=0;
			memset(num, 0, sizeof(num));
		}
		else
		{
			num[j++] = s[i];
		}
	}
	printf("%d\n",sum);
	return 0;
}
