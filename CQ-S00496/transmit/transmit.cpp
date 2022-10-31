#include<bits/stdc++.h>
#define int long long
using namespace std;
const int INF=9999999999999999ll;
vector<int> v[200005];
int n,Q,k;
int a[200005],d[200005],prt[200005],b[200005],c[200005],f[200005],sum[200005];
int p[200005][22];
void dfs(int s,int fa,int dep,int ds) {
	d[s]=dep+1,sum[s]=ds;
	for(int i=0;i<v[s].size();i++) {
		int y=v[s][i];
		if(y==fa) continue;
		prt[y]=s;
		dfs(y,s,dep+1,ds+a[y]);
	}
}
void st() {
	for(int i=1;i<=n;i++) p[i][0]=prt[i];
	for(int j=1;(1<<j)<=n;j++) {
		for(int i=1;i<=n;i++) {
			p[i][j]=p[p[i][j-1]][j-1];
		}
	}
}
int LCA(int x,int y){
	if(d[x]<d[y]) swap(x,y);
	int k=log(d[x])/log(2);
	for(int i=k;i>=0;i--) {
		if(d[x]-d[y]>=(1ll<<i)) x=p[x][i];
	}
	if(x==y) return x;
	for(int i=k;i>=0;i--) {
		if(p[x][i]!=p[y][i]) {
			x=p[x][i],y=p[y][i];
		}
	}
	return p[x][0];
}
void solve2() {
	for(int i=1;i<n;i++) {
		int x,y;scanf("%lld%lld",&x,&y);
		v[x].push_back(y),v[y].push_back(x);
	}
	dfs(1,0,0,a[1]);st();
	while(Q--) {
		int x,y;scanf("%lld%lld",&x,&y);
		if(d[x]<d[y]) swap(x,y);
		int lca=LCA(x,y);
		if(k==1) {
			printf("%lld\n",sum[x]+sum[y]-sum[lca]-sum[prt[lca]]);
			continue;
		}
		int g=x;
		b[0]=c[0]=0;
		while(g!=lca) b[++b[0]]=g,g=prt[g];
		b[++b[0]]=lca;
		g=y;
		while(g!=lca) c[++c[0]]=g,g=prt[g];
		for(int i=c[0];i>=1;i--) b[++b[0]]=c[i];
		f[1]=a[x];
		for(int i=2;i<=b[0];i++) {
			for(int j=1;j<=k;j++) if(i-j>=1) f[i]=f[i-j]+a[b[i]];
		}
		printf("%lld\n",f[b[0]]);
	}
}
int cnt=0;
int h[2005],vst[2005],dis[2005][2005];
struct edge {
	int to,next,v;
}e[6000005];
void addedge(int x,int y,int z) {
	cnt++;
	e[cnt].to=y;
	e[cnt].v=z;
	e[cnt].next=h[x];
	h[x]=cnt;
}
priority_queue< pair<int,int> > q;
void dij(int s) {
	for(int i=1;i<=n;i++) dis[s][i]=INF,vst[i]=0;
	dis[s][s]=0;q.push({-dis[s][s],s});
	while(!q.empty()) {
		int u=q.top().second;q.pop();
		if(vst[u]) continue;
		vst[u]=0;
		for(int i=h[u];i;i=e[i].next) {
			int y=e[i].to;
			if(dis[s][y]>dis[s][u]+e[i].v) {
				dis[s][y]=dis[s][u]+e[i].v;
				q.push({-dis[s][y],y});
			}
		}
	}
}
signed main() {
	freopen("transmit.in","r",stdin);
	freopen("transmit.out","w",stdout);
	scanf("%lld%lld%lld",&n,&Q,&k);
	for(int i=1;i<=n;i++) scanf("%lld",&a[i]);
	if(k==1||n>2000) return solve2(),0;
	for(int i=1;i<n;i++) {
		int x,y;scanf("%lld%lld",&x,&y);
		v[x].push_back(y),v[y].push_back(x);
	}
	dfs(1,0,0,a[1]);st();
	for(int i=1;i<=n;i++) {
		for(int j=1;j<=n;j++) {
			int lca=LCA(i,j);
//			cout<<i<<" "<<j<<" "<<lca<<" "; 
			if(d[i]+d[j]-d[lca]*2ll<=k) addedge(i,j,a[j]);
		}
	}
	for(int i=1;i<=n;i++) dij(i);
	while(Q--) {
		int x,y;scanf("%lld%lld",&x,&y);
		printf("%lld\n",min(dis[x][y]+a[x],dis[y][x]+a[y]));
	}
	return 0;
}
