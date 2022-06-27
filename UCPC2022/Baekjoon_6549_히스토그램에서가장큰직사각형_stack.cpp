#include <bits/stdc++.h>
using namespace std;
long long n;
vector<long long> h;

long long sol() {
    stack<long long> s; 
    long long ret = 0;
    for(long long i = 1; i <= n+1; i++) {
        while(!s.empty() && h[s.top()] >= h[i]) {
            int tmp = s.top(); s.pop();
            int width = i - ((s.empty())? 0 : s.top()) - 1;
            ret = max(ret, h[tmp]*width );
        }
        s.push(i);
    }
    return ret;
}
 
int main() {
    while(1) {
       scanf("%lld",&n);
       if(n == 0)	break;
       h = vector<long long>(n+2);
       h[0] = h[n+1] = 0;
       for(long long i = 1; i <= n; i++) {
           scanf(" %lld",&h[i]);
       }
       printf("%lld\n",sol());
    }
    return 0;
}

