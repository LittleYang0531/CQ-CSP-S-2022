#include<bits/stdc++.h>
using namespace std;
const int maxn=1e3+5;
int n,m,k,v[maxn],w[maxn][maxn],a[maxn][maxn],visit[maxn];
void init() {
	for(int i=1;i<=n;i++) {
		for(int j=1;j<=n;j++) {
			a[i][j]=(i==j?0:1e9);
			w[i][j]=(i==j?0:1e9);
		}
	}
}
int ans=0;
void dfs(int x,int y,int z,int o) {
	if(y==4) {
		ans=max(ans,z);
		return;
	}
	for(int i=1;i<=n;i++) {
		if(x!=i&&x!=o) {
			if(w[x][i]-1<=k&&!visit[i]) {
				visit[i]=1;
				dfs(i,y+1,z+v[i],x);
				visit[i]=0;
			}
		}
	}
}
int main() {
//	freopen("holiday.in","r",stdin);
//	freopen("holiday.out","w",stdout);
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1;i<=n-1;i++) {
		scanf("%d",&v[i]);
	}
	int x,y;
	init();
	while(m--) {
		scanf("%d%d",&x,&y);
		a[x][y]=a[y][x]=1;
	}
	for(int k=1;k<=n;k++) {
		for(int i=1;i<=n;i++) {
			for(int j=1;j<=n;j++) {
				if(i!=j&&i!=k&&j!=k) {
					w[i][j]=min(a[i][k]+a[k+1][j],w[i][j]);
				}
			}
		}
	}
	dfs(1,0,0,0);
	printf("%d",ans);
	return 0;
} 
