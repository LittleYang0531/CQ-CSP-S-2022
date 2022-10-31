#include <bits/stdc++.h>
#define int long long
#define pii pair<int,int>
#define fi first
#define se second
using namespace std;
bool lmg;
int read() {
	int x(0),f(0);
	char ch=getchar();
	while(!isdigit(ch)) f|=(ch=='-'),ch=getchar();
	while(isdigit(ch)) x=x*10+ch-'0',ch=getchar();
	return f?-x:x;
}
const int N=200005;
int n,q,m,v[N],cur,hed[N],nxt[N<<1],to[N<<1];
void add(int x,int y) {
	to[++cur]=y,nxt[cur]=hed[x],hed[x]=cur;
	to[++cur]=x,nxt[cur]=hed[y],hed[y]=cur;
}
namespace k1 {
	int dis[N],fa[N],son[N],siz[N],top[N],dep[N];
	void dfs1(int x,int fat) {
		fa[x]=fat,dis[x]=v[x]+dis[fat],dep[x]=dep[fa[x]]+1;
		siz[x]=1;
		for(int i=hed[x];i;i=nxt[i]) {
			int y=to[i];
			if(y==fa[x]) continue;
			dfs1(y,x);
			siz[x]+=siz[y];
			if(siz[y]>siz[son[x]]) son[x]=y;
		}
	}
	void dfs2(int x,int topf) {
		top[x]=topf;
		if(!son[x]) return;
		dfs2(son[x],topf);
		for(int i=hed[x];i;i=nxt[i])
			if(to[i]!=fa[x]&&to[i]!=son[x]) dfs2(to[i],to[i]);
	}
	int lca(int x,int y) {
		while(top[x]!=top[y]) {
			if(dep[top[x]]<dep[top[y]]) swap(x,y);
			x=fa[top[x]];
		}
		return dep[x]<dep[y]?x:y;
	}
	int calc(int x,int y) {
		int l=lca(x,y);
		return dis[x]+dis[y]-2*dis[l]+v[l];
	}
	void _main() {
		dfs1(1,0);
		dfs2(1,1);
		while(q--) printf("%lld\n",calc(read(),read()));
		exit(0);
	}
}
const int NN=2005;
int dis[NN][NN],d[N];
bool vis[N];
vector<int> a[N];
queue<int> qu;
void bfs(int s) {
	for(int i=1;i<=n;++i) d[i]=4,vis[i]=0;
	d[s]=0;
	vis[s]=1;
	qu.push(s);
	while(!qu.empty()) {
		int x=qu.front();
		qu.pop();
		for(int i=hed[x],y;i;i=nxt[i]) {
			y=to[i];
			if(vis[y]) continue;
			vis[y]=1,d[y]=d[x]+1;
			a[s].push_back(y);
			if(d[y]<m) qu.push(y);
		}
	}
}
priority_queue<pii,vector<pii>,greater<pii> > pq;
void dijkstra(int s) {
	for(int i=1;i<=n;++i) vis[i]=0;
	dis[s][s]=v[s];
	pq.push(pii(dis[s][s],s));
	while(!pq.empty()) {
		int x=pq.top().se;
		pq.pop();
		if(vis[x]) continue;
//		cerr<<s<<" "<<x<<endl;
		vis[x]=1;
		for(int y:a[x])
			if(dis[s][y]>dis[s][x]+v[y]) {
				dis[s][y]=dis[s][x]+v[y];
				pq.push(pii(dis[s][y],y));
			}
	}
}
bool oat;
signed main() {
//	cerr<<(&lmg-&oat)/1024.0/1024.0<<endl;
	freopen("transmit.in","r",stdin);
	freopen("transmit.out","w",stdout);
	n=read(),q=read(),m=read();
	for(int i=1;i<=n;++i) v[i]=read();
	for(int i=1;i<n;++i) add(read(),read());
	if(m==1) k1::_main();
	for(int i=1;i<=n;++i) {
		bfs(i);
//		for(int j=1;j<=n;++j) cerr<<d[j]<<" ";
//		cerr<<endl;
//		for(int j:a[i]) cerr<<j<<" ";
//		cerr<<endl;
	}
	memset(dis,0x3f,sizeof dis);
	for(int i=1;i<=n;++i) dijkstra(i);
	while(q--) printf("%lld\n",dis[read()][read()]);
	return 0;
}
/*
7 3 3
1 2 3 4 5 6 7
1 2
1 3
2 4
2 5
3 6
3 7
4 7
5 6
1 2

12
12
3
*/
