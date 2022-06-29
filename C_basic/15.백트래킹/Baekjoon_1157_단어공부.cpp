#include <stdio.h>
#include <string.h>

int main()
{
	char s[1000009];
	int cnt[26], max = 0, cntMax = 0, idxMax;
	scanf("%s",s);
	int len = strlen(s);
	for(int i=0;i<len;i++)
	{
		if('A'<=s[i]&&s[i]<='Z')	cnt[s[i]-'A']++;
		if('a'<=s[i]&&s[i]<='z')	cnt[s[i]-'a']++;
	}
	
	for(int i=0;i<26;i++)
		if(cnt[i]>max)
		{
			max = cnt[i];
			idxMax = i;
		}
	for(int i=0;i<26;i++)
		if(cnt[i] == max)	cntMax++;
	
	if(cntMax>1)	printf("?\n");
	else	printf("%c\n",'A'+idxMax);
	return 0;
}
