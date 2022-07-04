#include <bits/stdc++.h>
using namespace std;

int main()
{
	int N,X,A;
	scanf("%d %d",&N,&X);
	while(N--)
	{
		scanf(" %d",&A);
		if(A<X)	printf("%d ",A);
	}
	return 0;
}
