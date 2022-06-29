#include <stdio.h> 
#include <string.h>
#define MAX 1000009

int main()
{
	int cnt = 0;
	char s[MAX];
	scanf("%[^\n]",s);
	int len = strlen(s);
	
	if (len == 1 && s[0] == ' ')
	{
      printf("0\n");
      return 0;
    }
    
	for(int i=1;i<len-1;i++)	if(s[i]==' ')	cnt++;
	
	printf("%d\n",cnt+1);
	return 0;
}
