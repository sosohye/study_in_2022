#include<stdio.h>
#include<limits.h>

int main()
{
	char C;
	printf("char �ڷ����� ������ %d~%d �����Դϴ�.\n",CHAR_MIN,CHAR_MAX);
	printf("char �ڷ����� ũ���  %d �Դϴ�.\n",sizeof(char));
	printf("\n");
	
	int I;
	printf("int �ڷ����� ������ %d~%d �����Դϴ�.\n",INT_MIN,INT_MAX);
	printf("int �ڷ����� ũ���  %d �Դϴ�.\n",sizeof(int));
	printf("\n");
	
	unsigned int UI;
	printf("unsigned int �ڷ����� ������ %u~%u �����Դϴ�.\n",0,UINT_MAX);
	printf("int �ڷ����� ũ���  %d �Դϴ�.\n",sizeof(unsigned int));
	printf("\n");
	
	long long  LL;
	printf("long long �ڷ����� ������ %lld~%lld �����Դϴ�.\n",LLONG_MIN,LLONG_MAX);
	printf("long long �ڷ����� ũ���  %d �Դϴ�.\n",sizeof(long long));
	printf("\n");
	
	float F;
	scanf("%f",&F);
	double D;
	scanf("%lf",&D);
	printf("float: %f, double: %f\n",F,D);
	printf("float: %f, double: %lf\n",F,D);
}
