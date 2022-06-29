#include<stdio.h>

int main()
{
	int A, B;
	scanf("%d",&A);
	scanf("%d",&B);
	int B1 = B%10;
	int B2 = B%100/10;
	int B3 = B/100;
	printf("%d\n%d\n%d\n%d\n",A*B1,A*B2,A*B3,A*B);
	return 0;
}
