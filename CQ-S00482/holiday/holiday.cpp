#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=2e5+5;
struct E{
	int v,nxt;
}e[N<<2];
int head[N],cnt;
void add(int u,int v) {
	e[++cnt].v=v;
	e[cnt].nxt=head[u];
	head[u]=cnt;
}
int n,m,k,d[N],ans,vis[N];
int w[2500][2500],road[2500][2500];
void dfs(int u,int fa,int x,int sum) {
	if(x==4) {
		
		if(road[u][1])ans=max(ans,sum);
		return;
	} 
	for(int i=head[u];i;i=e[i].nxt) {
		int v=e[i].v;
		if(v==fa||vis[v]) continue;
		vis[v]=1;
		dfs(v,u,x+1,sum+d[v]);
		vis[v]=0;
	}
}
void solve1() {
	vis[1]=1;
	dfs(1,0,0,0);
	printf("%d",ans);
}
void pd(int u,int fa) {
	vis[u]=1;
	for(int i=head[u];i;i=e[i].nxt) {
		int v=e[i].v;
		if(v==fa||vis[v]) continue;
		pd(v,u);
	}
}
void solve2() {
	pd(1,0);
	for(int j=1;j<=4;j++) {
		int MAX=-1,id=0;
		for(int i=1;i<=n;i++) {
			if(vis[i]) {
				if(MAX<d[i]){
					MAX=d[i];
					id=i;
				}
			}
		}
		vis[id]=0,ans+=MAX;
	}
	printf("%d",ans);
}
void solve() {
	memset(w,0x3f3f3f3f,sizeof w);
	for(int i=1;i<=n;i++) {
		for(int j=i+1;j<=n;j++) {
			if(road[i][j]) w[i][j]=w[j][i]=0;
		}
	}
	for(int kk=1;kk<=n;kk++) {
		for(int i=1;i<=n;i++) {
			for(int j=i+1;j<=n;j++) {
				if(w[i][kk]!=0x3f3f3f3f&&w[kk][j]!=0x3f3f3f3f) {
					w[j][i]=w[i][j]=min(w[i][j],w[i][kk]+w[kk][j]+1);
				}
			}
		}	
	}
	memset(head,0,sizeof head);
	cnt=0;
	for(int i=1;i<=n;i++) {
		for(int j=i+1;j<=n;j++){
			if(w[i][j]<=k) {
				add(i,j);
				add(j,i);
			}
		}
	}
	solve1();
}
void solve_RP() {
	scanf("%d %d %d",&n,&m,&k);
	for(int i=2;i<=n;i++) scanf("%d",&d[i]);
	for(int i=1;i<=m;i++) {
		int u,v;
		scanf("%d%d",&u,&v);
		add(u,v);
		add(v,u);
		road[u][v]=road[v][u]=1;
	}
	if(k==0)
	solve1();
	else 
	if(m<=50&&k>=m-1)
	solve2();
	else 
	solve();
}
int main() {
	freopen("holiday.in","r",stdin);
	freopen("holiday.out","w",stdout);
	int T=1;
//	scanf("%d",&T);
	while(T--) {
		solve_RP();
	}
	return 0;
}
