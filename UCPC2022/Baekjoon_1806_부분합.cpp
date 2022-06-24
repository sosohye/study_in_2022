#include <bits/stdc++.h>
using namespace std;

int main()
{
	int N,S;
	scanf("%d %d",&N,&S);
	
	int arr[N];
	for(int i=0;i<N;i++)	scanf(" %d",arr+i);
	
	int start = 0, end = 0, sum = arr[0], min = N, chk=0;
	while(end<N)
	{
		if(sum<S)
		{
			end++;
			if(end<N)	sum += arr[end];
		}
		else
		{
			if(end-start+1<min)	min = end-start+1;
			sum -= arr[start];
			start++;
			chk=1;
		}
	}
	
	if(chk)	printf("%d\n",min);
	else	printf("0\n");
	return 0;
}
