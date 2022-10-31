#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,m,q,llg2[100005],a[100005],b[100005],f1[20][100005],f2[20][100005],g1[20][100005],g2[20][100005],mx[20][100005],mn[20][100005];
int ask1(int p,int l,int r) {
	int k=llg2[r-l+1];
	return p?max(mx[k][l],mx[k][r-(1<<k)+1]):min(mn[k][l],mn[k][r-(1<<k)+1]);
}
int ask2(int p,int l,int r) {
	int k=llg2[r-l+1];
	return p?max(f1[k][l],f1[k][r-(1<<k)+1]):min(f2[k][l],f2[k][r-(1<<k)+1]);
}
int ask3(int p,int l,int r) {
	int k=llg2[r-l+1];
	return p?max(g1[k][l],g1[k][r-(1<<k)+1]):min(g2[k][l],g2[k][r-(1<<k)+1]);
}
int main() {
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	scanf("%d%d%d",&n,&m,&q);
	for(int i=1;i<=n;i++)scanf("%d",a+i),f1[0][i]=-1,f2[0][i]=1<<30,g1[0][i]=-1<<30,g2[0][i]=1;
	for(int i=1;i<=m;i++)scanf("%d",b+i),mx[0][i]=mn[0][i]=b[i],llg2[i]=log2(i);
	for(int i=1;i<=n;i++) {
		if(a[i]>=0)f1[0][i]=f2[0][i]=a[i];
		else g1[0][i]=g2[0][i]=a[i];
	}
	for(int i=1;1<<i<=n;i++) {
		for(int j=1;j<=n-(1<<i)+1;j++) {
			mx[i][j]=max(mx[i-1][j],mx[i-1][j+(1<<i-1)]);
			mn[i][j]=min(mn[i-1][j],mn[i-1][j+(1<<i-1)]);
			f1[i][j]=max(f1[i-1][j],f1[i-1][j+(1<<i-1)]);
			f2[i][j]=min(f2[i-1][j],f2[i-1][j+(1<<i-1)]);
			g1[i][j]=max(g1[i-1][j],g1[i-1][j+(1<<i-1)]);
			g2[i][j]=min(g2[i-1][j],g2[i-1][j+(1<<i-1)]);
		}
	}
	while(q--) {
		int l1,l2,r1,r2;
		scanf("%d%d%d%d",&l1,&r1,&l2,&r2);
		ll ans=-1ll<<62,p=ask2(1,l1,r1),q=ask3(0,l1,r1),x=ask1(0,l2,r2),y=ask1(1,l2,r2);
		if(p!=-1)ans=max(ans,max(p*x,ask2(0,l1,r1)*x));
		if(q!=1)ans=max(ans,max(q*y,ask3(1,l1,r1)*y));
		printf("%lld\n",ans);
	}
	return 0;
}
