#include <bits/stdc++.h>
#define ri register int
#define ll long long
using namespace std;
const int Maxn=1e5;
const int Inf=1e9+1;
int st[8][Maxn+5][20],log_2[Maxn+5];
int a[Maxn+5],b[Maxn+5];
int suma[Maxn+5][2],sumb[Maxn+5][2];
int n,m,q;
inline int query(int op,int l,int r) {
	int t=log_2[r-l+1];
	if(op&1) {
		return min(st[op][l][t],st[op][r-(1<<t)+1][t]);
	}
	else {
		return max(st[op][l][t],st[op][r-(1<<t)+1][t]);
	}
}
void build() {
	log_2[0]=-1;
	for(ri i=1;i<=max(n,m);i++)log_2[i]=log_2[i>>1]+1;
	for(ri i=1;i<=n;i++) {
		st[0][i][0]=a[i]>=0?a[i]:-Inf;
		st[1][i][0]=a[i]>=0?a[i]:Inf;
		st[2][i][0]=a[i]<=0?a[i]:-Inf;
		st[3][i][0]=a[i]<=0?a[i]:Inf;
	}
	for(ri i=1;i<=m;i++) {
		st[4][i][0]=b[i]>=0?b[i]:-Inf;
		st[5][i][0]=b[i]>=0?b[i]:Inf;
		st[6][i][0]=b[i]<=0?b[i]:-Inf;
		st[7][i][0]=b[i]<=0?b[i]:Inf;
	}
	for(ri j=1;j<=log_2[n];j++)
		for(ri i=1;i<=n-(1<<j)+1;i++) {
			for(ri k=0;k<4;k++) {
				if(k&1) {
					st[k][i][j]=min(st[k][i][j-1],st[k][i+(1<<j-1)][j-1]);
				}
				else {
					st[k][i][j]=max(st[k][i][j-1],st[k][i+(1<<j-1)][j-1]);
				}
			}
		}
	for(ri j=1;j<=log_2[m];j++)
		for(ri i=1;i<=m-(1<<j)+1;i++) {
			for(ri k=4;k<8;k++) {
				if(k&1) {
					st[k][i][j]=min(st[k][i][j-1],st[k][i+(1<<j-1)][j-1]);
				}
				else {
					st[k][i][j]=max(st[k][i][j-1],st[k][i+(1<<j-1)][j-1]);
				}
			}
		}
}
int main() {
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	scanf("%d%d%d",&n,&m,&q);
	for(ri i=1;i<=n;i++)scanf("%d",&a[i]);
	for(ri i=1;i<=m;i++)scanf("%d",&b[i]);
	for(ri i=1;i<=n;i++) {
		suma[i][0]=suma[i-1][0]+(a[i]>=0);
		suma[i][1]=suma[i-1][1]+(a[i]<=0);
	}
	for(ri i=1;i<=m;i++) {
		sumb[i][0]=sumb[i-1][0]+(b[i]>=0);
		sumb[i][1]=sumb[i-1][1]+(b[i]<=0);
	}
	build();
	while(q--) {
		int l1,r1,l2,r2;
		scanf("%d%d%d%d",&l1,&r1,&l2,&r2);
		ll ans=-1e18;
		if(suma[r1][0]-suma[l1-1][0]) {
			if(sumb[r2][1]-sumb[l2-1][1]) {
				ans=max(ans,1ll*query(1,l1,r1)*query(7,l2,r2));
			}
			else {
				ans=max(ans,1ll*query(0,l1,r1)*query(5,l2,r2));
			}
		}
		if(suma[r1][1]-suma[l1-1][1]) {
			if(sumb[r2][0]-sumb[l2-1][0]) {
				ans=max(ans,1ll*query(2,l1,r1)*query(4,l2,r2));
			}
			else {
				ans=max(ans,1ll*query(3,l1,r1)*query(6,l2,r2));
			}
		}
		//if(suma[r1][1]-suma[l1-1][1]&&ans<0)ans=0;
		//if(sumb[r2][1]-sumb[l2-1][1]&&ans>0)ans=0;
		printf("%lld\n",ans);
	}
	return 0;
}

