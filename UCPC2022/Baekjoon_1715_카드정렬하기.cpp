#include <bits/stdc++.h>
using namespace std;

int main()
{
   int N,data1,data2;
   priority_queue<int,vector<int>,greater<int> > pq;
   scanf("%d",&N);
   for(int i=0;i<N;i++)
   {
		scanf("%d",&data1);
		pq.push(data1);
   }
   long long sum=0;
   
   while(pq.size()>1)
   {
		data1=pq.top();
		pq.pop();
		data2=pq.top();
		pq.pop();
		pq.push(data1+data2);
		//printf("%d %d\n",data1, data2);
		sum += (long long)(data1+data2);
   }
   printf("%lld\n",sum);
   return 0;
}
