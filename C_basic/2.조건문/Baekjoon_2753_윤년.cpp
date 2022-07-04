#include<stdio.h>

int isLeap(int N)
{
	return (N%4==0 && N%100) || N%400==0 ? 1 : 0;
}
int main()
{
	int N;
	scanf("%d",&N);
	printf("%d\n",isLeap(N));
	return 0;
} 
