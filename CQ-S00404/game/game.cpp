/*
60 pts

线段树忘记怎么打了 QAQ ，不然就 A 了 
*/
#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e3+5,INF=1000000000000000000;
int n,m,q,a[N],b[N],minb[N][N],maxb[N][N];
int l1,r1,l2,r2;
signed main(){
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	scanf("%lld %lld %lld",&n,&m,&q);
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
	}
	for(int i=1;i<=m;i++){
		scanf("%lld",&b[i]);
		minb[i][i]=maxb[i][i]=b[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			minb[i][j]=min(minb[i][j-1],b[j]);
			maxb[i][j]=max(maxb[i][j-1],b[j]);
		}
	}
	while(q--){
		scanf("%lld %lld %lld %lld",&l1,&r1,&l2,&r2);
		int ans=-INF;
		for(int i=l1;i<=r1;i++){
			int minn=INF;
			if(a[i]>0){
				minn=a[i]*minb[l2][r2];
			}
			else{
				minn=a[i]*maxb[l2][r2];
			}
			ans=max(ans,minn);
		}
		printf("%lld\n",ans);
	}
	return 0;
}
