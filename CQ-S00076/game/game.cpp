#include <bits/stdc++.h>
using namespace std;
long long c[1001][1001],a[1001],b[1001],n,m,i,j,ans,cmp=1000000000000000000,x,y,k,u,g;
int main(){
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	scanf("%lld%lld%lld",&n,&m,&k);
	for(i=1;i<=n;i++) scanf("%lld",&a[i]);
	for(i=1;i<=m;i++) scanf("%lld",&b[i]);
	for(i=1;i<=n;i++)
		for(j=1;j<=m;j++)
			c[i][j]=a[i]*b[j];
	for(i=1;i<=k;i++){
		long long p,q;
		scanf("%lld%lld%lld%lld",&p,&q,&x,&y);
		ans=-1*cmp;
		for(j=p;j<=q;j++){
			u=cmp;
			for(g=x;g<=y;g++){
				u=min(u,c[j][g]);
			}
			ans=max(ans,u);
		}
		printf("%lld\n",ans);
	}
	return 0;
}
