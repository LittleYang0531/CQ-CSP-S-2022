#include<bits/stdc++.h>
using namespace std;
const int N=1e3+10;
int a[N],b[N];
int main() {
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	int n,m,q;
	scanf("%d%d%d",&n,&m,&q);
	for(int i=1; i<=n; i++) scanf("%d",&a[i]);
	for(int i=1; i<=m; i++) scanf("%d",&b[i]);
	int l1,r1,l2,r2;
	int minn=INT_MAX,maxn=-INT_MAX;
	for(int i=1; i<=q; i++) {
		scanf("%d%d%d%d",&l1,&r1,&l2,&r2);
		if(l1==r1) {
			for(int j=l2; j<=r2; j++) minn=min(minn,b[j]);
			long long ans=minn*a[l1];
			printf("%lld\n",ans);
		} else if(l2==r2) {
			for(int j=l1; j<=r1; j++) maxn=max(maxn,a[j]);
			long long ans=maxn*a[l2];
			printf("%lld\n",ans);
		} else {
			for(int j=l1; j<=r1; j++) maxn=max(maxn,a[j]);
			for(int j=l2; j<=r2; j++) minn=min(minn,b[j]);
			long long ans=maxn*minn;
			printf("%lld\n",ans);
		}
	}
	return 0;
}

