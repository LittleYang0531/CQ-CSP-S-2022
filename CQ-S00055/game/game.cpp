#include<bits/stdc++.h>
using namespace std;
long long A[300],B[300],N,M,Q,L1,R1,L2,R2;
long long s[305][305];
int main(){
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	scanf("%lld%lld%lld",&N,&M,&Q);
	for(int i=1;i<=N;++i){
		scanf("%lld",&A[i]);
	}
	for(int i=1;i<=M;++i){
		scanf("%lld",&B[i]);
	}
	for(int i=1;i<=N;++i){
		for(int j=1;j<=M;++j){
			s[i][j]=A[i]*B[j];
		}
	}
	for(int i=1;i<=Q;++i){
		scanf("%lld%lld%lld%lld",&L1,&R1,&L2,&R2);
		long long Manx=-1000000000000000000,mini=0;
		for(int j=L1;j<=R1;++j){
			long long minx=1000000000000000000;
			for(int k=L2;k<=R2;++k){
				if(minx>s[j][k]){
					minx=s[j][k];
				}
			}
			if(Manx<minx){
				mini=j;
				Manx=minx;
			}
		}
		long long Ans=1000000000000000000;
		for(int j=L2;j<=R2;++j){
			Ans=min(s[mini][j],Ans);
		}
		printf("%lld\n",Ans);
	}
	return 0;
}
/*
3 2 2
0 1 -2
-3 4
1 3 1 2
2 3 2 2
6 4 5
3 -1 -2 1 2 0
1 2 -1 -3
1 6 1 4
1 5 1 4
1 4 1 2
2 6 3 4
2 5 2 3
Give me points!
Give me more points!
Give me!

*/
