#include<stdio.h>
#include<limits.h>

int main()
{
	char C;
	printf("char 자료형의 범위는 %d~%d 까지입니다.\n",CHAR_MIN,CHAR_MAX);
	printf("char 자료형의 크기는  %d 입니다.\n",sizeof(char));
	printf("\n");
	
	int I;
	printf("int 자료형의 범위는 %d~%d 까지입니다.\n",INT_MIN,INT_MAX);
	printf("int 자료형의 크기는  %d 입니다.\n",sizeof(int));
	printf("\n");
	
	unsigned int UI;
	printf("unsigned int 자료형의 범위는 %u~%u 까지입니다.\n",0,UINT_MAX);
	printf("int 자료형의 크기는  %d 입니다.\n",sizeof(unsigned int));
	printf("\n");
	
	long long  LL;
	printf("long long 자료형의 범위는 %lld~%lld 까지입니다.\n",LLONG_MIN,LLONG_MAX);
	printf("long long 자료형의 크기는  %d 입니다.\n",sizeof(long long));
	printf("\n");
	
	float F;
	scanf("%f",&F);
	double D;
	scanf("%lf",&D);
	printf("float: %f, double: %f\n",F,D);
	printf("float: %f, double: %lf\n",F,D);
}
