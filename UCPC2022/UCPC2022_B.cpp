#include <bits/stdc++.h>
using namespace std;

#define X first
#define Y second
typedef long long ll;
typedef pair<ll, ll> pll;

vector<pll> v;

ll CCW(pll A, pll B, pll C) 
{
	ll tmp = A.X * B.Y + B.X * C.Y + C.X * A.Y;
	tmp -= B.X * A.Y + C.X * B.Y + A.X * C.Y;

	if (tmp > 0) return 1; // 반시계
	else if (tmp == 0) return 0; // 일직선
	else if (tmp < 0) return -1; // 시계방향
}

bool solve(pll A, pll B, pll C, pll D)
{
	ll ans1 = CCW(A, B, C) * CCW(A, B, D);
	ll ans2 = CCW(C, D, A) * CCW(C, D, B);

	if (ans1 == 0 && ans2 == 0) // 평행 혹은 양 끝점이 접촉해 있을 때
	{
		// pair 대소비교. 첫번째 인자가 같다면 두번째 인자 비교
		if (A > B) swap(A, B);
		if (C > D) swap(C, D);
		
		if (A <= D && B >= C)
		{
			return true;
		}
		return false;
	}
	else 
	{
		// 교차 혹은 한 점이 선분 위에 있을 때(끝점 x)
		if (ans1 <= 0 && ans2 <= 0)
		{
			return true;
		}
		return false;
	}
}

ll N;
ll ans = 0;

typedef struct{
	ll sx;
	ll sy;
	ll ex;
	ll ey;
	ll weight;
}Line;

bool cmp(const Line& a, const Line& b) {
	return a.weight < b.weight;
}

vector<Line> vL;

int main()
{
	scanf("%lld",&N);
	for(int i=0;i<N;i++)
	{
		Line l;
		scanf("%lld %lld %lld %lld %lld",&l.sx,&l.sy,&l.ex,&l.ey,&l.weight);
		vL.push_back(l);
	}
	sort(vL.begin(),vL.end(),cmp);
	
	for(int i=0;i<N;i++)
	{
		for(int j=i+1;j<N;j++)
			if(solve(make_pair(vL[i].sx,vL[i].sy),make_pair(vL[i].ex,vL[i].ey),make_pair(vL[j].sx,vL[j].sy),make_pair(vL[j].ex,vL[j].ey)))
				ans += vL[i].weight;
		ans += vL[i].weight;
	}
	printf("%lld\n",ans);
	
	return 0;
}
