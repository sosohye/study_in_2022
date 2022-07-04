#include <stdio.h>
long long D,G;
int i,N,s[300001],S[300001],E[300001];
main(){
	scanf("%d",&N);
	for(i=1;i<N;++i){
		scanf("%d %d",S+i,E+i);
		s[S[i]]++;s[E[i]]++;
	}
	for(i=1;i<=N;++i){
		if(i<N)	D += 1ll*(s[S[i]]-1)*(s[E[i]]-1);
		G += 1ll*s[i]*(s[i]-1)*(s[i]-2)/6;
	}
	printf("%s",D==3*G?"DUDUDUNGA":D>3*G?"D":"G");
}
