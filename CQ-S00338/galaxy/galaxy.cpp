#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll n,m,q,u,v,t,a,b;
bool ffff;
struct ccd {
	ll cnt,u[1005];
} cd[50005];
bool f[1005][1005],ff[10005],fffff[1005][1005];
void dfs(ll x) {
	ff[x]=1;
	for(ll i=1; i<=n; i++){
		if(f[x][i]&&(ff[i]||fffff[x][i])){
			ffff=1;
			return;
		}
	}
	for(ll i=1; i<=n; i++){
		if(f[x][i]&&(!ff[i]||!fffff[x][i])){
			ff[i]=1;
			fffff[x][i]=1;
			dfs(i);
		}
	}
}
int main() {
    freopen("galaxy.in","r",stdin);
    freopen("galaxy.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for(ll i=1; i<=m; i++) {
		scanf("%lld%lld",&u,&v);
		f[u][v]=1;
		cd[v].u[++cd[u].cnt]=u;
	}
	scanf("%lld",&q);
	while(q--) {
		scanf("%lld%lld",&t,&a);
		if(t==1) {
			scanf("%lld",&b);
			f[a][b]=0;
		} else if(t==2)for(ll i=1; i<=n; i++)f[i][a]=0;
		else if(t==3) {
			scanf("%lld",&b);
			f[a][b]=1;
		} else for(ll i=1; i<=cd[a].cnt; i++)f[cd[a].u[i]][a]=1;
		bool fff=0;
		for(ll i=1,sum; i<=n; i++) {
			sum=0;
			for(ll j=1; j<=n&&sum<2; j++)sum+=f[i][j];
			if(sum!=1) {
				fff=1;
				break;
			}
		}
		if(!fff) {
			for(ll i=1; i<=n; i++) {
				memset(ff,0,sizeof(ff));
				ffff=0;
				dfs(i);
				if(!ffff){
					fff=1;
					break;
				}
			}
		}
		if(fff)printf("NO\n");
		else printf("YES\n");
	}
	return 0;
}

