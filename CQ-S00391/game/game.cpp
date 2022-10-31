#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const int MAXN=100001; 
int n,m,q,l1,r1,l2,r2;
int lg[MAXN];
LL ans,mx[MAXN][17],mn[MAXN][17],a[MAXN],b[MAXN];
LL getmax(int l,int r){
	int k=lg[r-l+1];
	return max(mx[l][k],mx[r-(1<<k)+1][k]);
}
LL getmin(int l,int r){
	int k=lg[r-l+1];
	return min(mn[l][k],mn[r-(1<<k)+1][k]);
}
int main(){
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	scanf("%d%d%d",&n,&m,&q);
	for(int i=1;i<=n;++i)scanf("%d",&a[i]);
	for(int i=1;i<=m;++i)scanf("%d",&b[i]),mx[i][0]=mn[i][0]=b[i];
	lg[1]=0;
	for(int i=2;i<=max(n,m);++i)lg[i]=lg[i>>1]+1;
	for(int j=1;(1<<j)<=m;++j){
		for(int i=1;i+(1<<j)-1<=m;++i){
			mx[i][j]=max(mx[i][j-1],mx[i+(1<<j-1)][j-1]);
			mn[i][j]=min(mn[i][j-1],mn[i+(1<<j-1)][j-1]);
		}
	}
	while(q--){
		scanf("%d%d%d%d",&l1,&r1,&l2,&r2);
		ans=LONG_LONG_MIN;
		for(int i=l1;i<=r1;++i){
			ans=max(ans,1ll*min(1ll*a[i]*getmax(l2,r2),1ll*a[i]*getmin(l2,r2)));
		}
		printf("%lld\n",ans);
	}
	return 0;
}
/*
3 2 2
0 1 -2
-3 4
1 3 1 2
2 3 2 2
*/
