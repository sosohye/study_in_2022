#include <bits/stdc++.h>
using namespace std;
#define X line[1]
#define Y line[0]
#define XY line[2]

int main()
{
	int m, q, d, l;
	long long ans = 0;
	vector<int> line[3];
	
	scanf("%d %d",&m,&q);
	while(q--)
	{
		scanf("%d %d",&d,&l);
		line[d/60].push_back(l);
	}
	
	
	sort(Y.begin(),Y.end());
	sort(X.begin(),X.end());
	sort(XY.begin(),XY.end());
	int sizeX = X.size();
	int sizeY = Y.size();
	int sizeXY = XY.size();
	
	printf("%d %d %d\n",sizeX,sizeY,sizeXY);
	
	ans += 1 + sizeX + sizeY + sizeXY;
	printf("%lld\n",ans);
	
	for(int i=0;i<sizeX;i++)
	{
		printf("case1: %d %d %d\n",i,( lower_bound(Y.begin(), Y.end(), m - X[i]) - Y.begin() ) + 1,sizeXY - ( upper_bound(XY.begin(), XY.end(), X[i]) - XY.begin()));
		if(m-X[i]>Y[0])	ans += ( lower_bound(Y.begin(), Y.end(), m - X[i]) - Y.begin() ) + 1;
		ans += sizeXY - ( upper_bound(XY.begin(), XY.end(), X[i]) - XY.begin() );
		printf("%lld\n",ans);
	}
	for(int i=0;i<sizeY;i++)
	{
		printf("case1: %d %d\n",i,sizeXY - ( upper_bound(XY.begin(), XY.end(), Y[i]) - XY.begin() ) );
		ans += sizeXY - ( upper_bound(XY.begin(), XY.end(), Y[i]) - XY.begin() );
		printf("%lld\n",ans);
	}
	
	ans += sizeX*sizeY*sizeXY;
	
	printf("%lld\n",ans);
	
	
	return 0;
}
