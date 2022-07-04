#include <stdio.h>

int main()
{
	int a,b,c,max;
	scanf("%d",&a);
	max=a;
	scanf("%d",&b);
	if(max<b)	max=b;
	scanf("%d",&c);
	if(max<c)	max=c;
	
	if(a==b&&b==c)	printf("%d\n",10000+1000*a);
	else if(a==b||b==c)	printf("%d\n",1000+100*b);
	else if(c==a)	printf("%d\n",1000+100*a);
	else	printf("%d\n",100*max);
	return 0;
} 
