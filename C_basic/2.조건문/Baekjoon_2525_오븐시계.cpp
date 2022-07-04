#include <stdio.h>

int main()
{
	int H,M,T;
	scanf("%d %d",&H,&M);
	scanf("%d",&T);
	M+=T;
	while(M>59)
	{
		M-=60;
		H++;
	}
	while(H>23)	H-=24;
	
	printf("%d %d\n",H,M);
	return 0;
}
