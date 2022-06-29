#include <bits/stdc++.h>
using namespace std;
#define MAX 1000009 

int main()
{
	int N, A;
	vector<int> v = {MAX};
	scanf("%d",&N);
	while(N--)
	{
		scanf(" %d",&A);
		if(A>v.back())	v.push_back(A);
		else	v[lower_bound(v.begin(), v.end(), A)-v.begin()] = A;
	}
	printf("%d\n",v.size());
	return 0;
}
