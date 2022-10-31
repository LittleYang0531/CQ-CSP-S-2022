#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=1e5+5,L=20,inf=1e9+5;
int n,m,q,a[N],sa[N],b[N];
int lg[N],fa[4][N][L+1],fb[2][N][L+1];
int main(){
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	scanf("%d%d%d",&n,&m,&q);
	for(int i=1;i<=n;i++)
	scanf("%d",a+i),sa[i]=sa[i-1]+(!a[i]);
	for(int i=1;i<=n;i++)
	fa[0][i][0]=a[i]>0?a[i]:inf,
	fa[1][i][0]=a[i]>0?a[i]:-inf,
	fa[2][i][0]=a[i]<0?a[i]:inf,
	fa[3][i][0]=a[i]<0?a[i]:-inf;
	for(int c=1;c<L;c++)
	for(int i=1;i+(1<<c)-1<=n;i++)
	fa[0][i][c]=min(fa[0][i][c-1],fa[0][i+(1<<(c-1))][c-1]),
	fa[1][i][c]=max(fa[1][i][c-1],fa[1][i+(1<<(c-1))][c-1]),
	fa[2][i][c]=min(fa[2][i][c-1],fa[2][i+(1<<(c-1))][c-1]),
	fa[3][i][c]=max(fa[3][i][c-1],fa[3][i+(1<<(c-1))][c-1]);
	for(int i=1;i<=m;i++)scanf("%d",b+i);
	for(int i=1;i<=m;i++)
	fb[0][i][0]=fb[1][i][0]=b[i];
	for(int c=1;c<L;c++)
	for(int i=1;i+(1<<c)-1<=m;i++)
	fb[0][i][c]=min(fb[0][i][c-1],fb[0][i+(1<<(c-1))][c-1]),
	fb[1][i][c]=max(fb[1][i][c-1],fb[1][i+(1<<(c-1))][c-1]);
	for(int i=2;i<=max(n,m);i++)lg[i]=lg[i>>1]+1;
	while(q--){
		int l1,r1,l2,r2;scanf("%d%d%d%d",&l1,&r1,&l2,&r2);
		int k1=lg[r1-l1+1],k2=lg[r2-l2+1];
		int mn=min(fb[0][l2][k2],fb[0][r2-(1<<k2)+1][k2]);
		int mx=max(fb[1][l2][k2],fb[1][r2-(1<<k2)+1][k2]);
		ll ans=(sa[r1]>sa[l1-1])?0:-1e18;
		if(mn<0){
			int v=min(fa[0][l1][k1],fa[0][r1-(1<<k1)+1][k1]);
			if(v!=inf)ans=max(ans,1ll*v*mn);
		}
		else{
			int v=max(fa[1][l1][k1],fa[1][r1-(1<<k1)+1][k1]);
			if(v!=-inf)ans=max(ans,1ll*v*mn);
		}
		if(mx>0){
			int v=max(fa[3][l1][k1],fa[3][r1-(1<<k1)+1][k1]);
			if(v!=-inf)ans=max(ans,1ll*v*mx);
		}
		else{
			int v=min(fa[2][l1][k1],fa[2][r1-(1<<k1)+1][k1]);
			if(v!=inf)ans=max(ans,1ll*v*mx);
		}
		printf("%lld\n",ans);
	}
	return 0;
}
