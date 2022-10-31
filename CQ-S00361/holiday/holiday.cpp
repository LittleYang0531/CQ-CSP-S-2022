#include <bits/stdc++.h>
#define ri register int
#define ll long long
using namespace std;
const int Maxn=2500;
const int Inf=1e9;
queue<int>q;
vector<int>adj[Maxn+5];
int dis[Maxn+5][Maxn+5],mx[Maxn+5][Maxn+5],s[Maxn+5][Maxn+5],tot[Maxn+5],cnt[Maxn+5];
ll val[Maxn+5];
int n,m,K;
inline bool cmp(int a,int b) {
	return val[a]>val[b];
}
void bfs(int source,int dis[]) {
	for(ri i=1;i<=n;i++)dis[i]=Inf;
	q.push(source),dis[source]=0;
	while(!q.empty()) {
		int u=q.front();q.pop();
		for(ri v:adj[u]) {
			if(dis[v]>dis[u]+1) {
				dis[v]=dis[u]+1;
				q.push(v);
			}
		}
	}
}
int main() {
	freopen("holiday.in","r",stdin);
	freopen("holiday.out","w",stdout);
	scanf("%d%d%d",&n,&m,&K);
	++K;
	for(ri i=2;i<=n;i++)scanf("%lld",&val[i]);
	for(ri i=1;i<=m;i++) {
		int x,y;
		scanf("%d%d",&x,&y);
		adj[x].push_back(y);
		adj[y].push_back(x);
	}
	for(ri i=1;i<=n;i++) {
		bfs(i,dis[i]);
		for(ri j=2;j<=n;j++)
			if(j!=i&&dis[i][j]<=K)s[i][++tot[i]]=j;
	}
	for(ri i=1;i<=n;i++) {
		for(ri j=2;j<=n;j++) {
			if(dis[i][j]<=K&&dis[1][j]<=K&&j!=i) {
				mx[i][++cnt[i]]=j;
			}
		}
		sort(mx[i]+1,mx[i]+cnt[i]+1,cmp);
	}
	ll ans=0;
	for(ri i=1;i<=tot[1];i++) {
		int x=s[1][i];
		for(ri j=1;j<=tot[x];j++) {
			int y=s[x][j];
			if(x==y)continue;
			for(ri k=1;k<=tot[y];k++) {
				int z=s[y][k];
				if(x==z||y==z)continue;
				for(ri l=1;l<=cnt[z];l++) {
					int t=mx[z][l];
					if(t!=x&&t!=y) {
						ans=max(ans,val[x]+val[y]+val[z]+val[t]);
						break;
					}
				}
			}
		}
	}
	printf("%lld\n",ans);
	return 0;
}

