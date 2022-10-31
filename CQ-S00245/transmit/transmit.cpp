#include<bits/stdc++.h>
#define ll long long
#define int long long
#define pii pair<int,int>
#define fir first
#define sec second
using namespace std;

const int maxn=200005;
const int maxk=6;
const int inf=0x3f3f3f3f3f3f3f3f;

struct Query {
	int x,y,id;
};

int nd;
int rt;
int Min;
int n,q,k;
int v[maxn];
int fa[maxn];
int sz[maxn];
int ans[maxn];
int minv[maxn];
int minf[maxn];
int depth[maxn];
int f[maxn][maxk][maxk];
int g[maxn][maxk][maxk];
bool vis[maxn];
vector<int> all;
vector<int> vd[maxn];
vector<int> anc[maxn];
vector<int> tree[maxn];
vector<Query> qr[maxn];

void gets(int x) {
	vis[x]=true;
	sz[x]=1;
	for(int to:tree[x]) {
		if(vis[to]) {
			continue;
		}
		gets(to);
		sz[x]+=sz[to];
	}
	vis[x]=false;
}

void getr(int x,int S) {
	vis[x]=true;
	int Max=S-sz[x];
	for(int to:tree[x]) {
		if(vis[to]) {
			continue;
		}
		getr(to,S);
		Max=max(Max,sz[to]);
	}
	if(Max<Min) {
		Min=Max;
		rt=x;
	}
	vis[x]=false;
}

int getr(int x) {
	gets(x);
	Min=inf;
	getr(x,sz[x]);
	return rt;
}

namespace Tree {
	int fa[maxn];
	int depth[maxn];
	void calc(int x) {
		vis[x]=true;
		for(int to:tree[x]) {
			if(vis[to]) {
				continue;
			}
			to=getr(to);
			fa[to]=x;
			depth[to]=depth[x]+1;
			calc(to);
		}
	}
	int lca(int x,int y) {
		while(x!=y) {
			if(depth[x]<depth[y]) {
				swap(x,y);
			}
			x=fa[x];
		}
		return x;
	}
}

void getd(int x,int d) {
	vis[x]=true;
	depth[x]=d;
	all.push_back(x);
	vd[depth[x]].push_back(x);
	if(anc[x].size()<=k+1) {
		anc[x].push_back(x);
	}
	minv[x]=inf;
	for(int to:tree[x]) {
		if(vis[to]) {
			continue;
		}
		fa[to]=x;
		anc[to]=anc[x];
		minv[x]=min(minv[x],v[to]);
		getd(to,d+1);
	}
	vis[x]=false;
}

void getf(int x) {
	vis[x]=true;
	for(int i=0;i<=k;i++) {
		f[x][nd][0]=min(f[x][nd][0],f[x][nd][i]+v[x]);
	}
	for(int to:tree[x]) {
		if(vis[to]) {
			continue;
		}
		memset(f[to][nd],0x3f,sizeof(f[to][nd]));
		for(int i=0;i<=k;i++) {
			f[to][nd][i+1]=f[x][nd][i];
		}
		getf(to);
	}
	vis[x]=false;
} 

void calc(int x) {
	getd(x,0);
	for(int i=0;i<=k;i++) {
		nd=i;
		for(int x:vd[i]) {
			memset(f[x][i],0x3f,sizeof(f[x][i]));
			f[x][i][0]=v[x];
			getf(x);
		}
		for(int x:vd[i]) {
			vis[x]=true;
		}
	}
	for(Query q:qr[x]) {
		int &p=ans[q.id];
		p=inf;
		for(int x:anc[q.x]) {
			for(int y:anc[q.y]) {
				if(depth[x]+depth[y]<=k) {
					p=min(p,f[q.x][depth[x]][0]+f[q.y][depth[y]][0]);
				}
			}
		}
	}
	for(int x:all) {
		vis[x]=false;
		anc[x].clear();
		vd[depth[x]].clear();
	}
	all.clear();
	vis[x]=true;
	for(int to:tree[x]) {
		if(vis[to]) {
			continue;
		}
		calc(getr(to));
	}
}

namespace K3 {
	void getf(int x) {
		
	}
	void bfs(int x) {
		vector<int> clr;
		queue<int> q;
		q.push(x);
		while(q.size()) {
			int x=q.front();
			clr.push_back(x);
			q.pop();
			for(int i=0;i<=k;i++) {
				f[x][nd][0]=min(f[x][nd][0],f[x][nd][i]+v[x]);
			}
//			f[x][nd][0]=min(f[x][nd][0],f[fa[fa[fa[fa[x]]]]][nd][0]+minv[fa[fa[x]]]+v[x]);
			f[x][nd][0]=min(f[x][nd][0],minf[fa[fa[x]]]+v[x]);
			if(!vis[fa[x]]) {
				minf[fa[x]]=min(minf[fa[x]],f[x][nd][0]);
			}
			for(int to:tree[x]) {
				if(depth[to]<depth[x]||vis[to]) {
					continue;
				}
				memset(f[to][nd],0x3f,sizeof(f[to][nd]));
				for(int i=0;i<=k;i++) {
					f[to][nd][i+1]=f[x][nd][i];
				}
				q.push(to);
			}
		}
		for(int x:clr) {
			minf[x]=inf;
		}
	}
	void bfs2(int x) {
		vector<int> clr;
		clr.push_back(x);
		queue<int> q;
		for(int to:tree[x]) {
			if(depth[to]<depth[x]||vis[to]) {
				continue;
			}
			memset(g[to][nd],0x3f,sizeof(g[to][nd]));
			g[to][nd][0]=v[x]+v[to];
			minf[x]=min(minf[x],g[to][nd][0]);
			q.push(to);
		}
		int rt=x;
		while(q.size()) {
			int x=q.front();
			clr.push_back(x);
			q.pop();
			for(int i=0;i<=k;i++) {
				g[x][nd][0]=min(g[x][nd][0],g[x][nd][i]+v[x]);
			}
//			if(depth[x]-depth[rt]>4) {
//				g[x][nd][0]=min(g[x][nd][0],g[fa[fa[fa[fa[x]]]]][nd][0]+minv[fa[fa[x]]]+v[x]);
//			}
			g[x][nd][0]=min(g[x][nd][0],minf[fa[fa[x]]]+v[x]);
			if(!vis[fa[x]]) {
				minf[fa[x]]=min(minf[fa[x]],g[x][nd][0]);
			}
			for(int to:tree[x]) {
				if(depth[to]<depth[x]||vis[to]) {
					continue;
				}
				memset(g[to][nd],0x3f,sizeof(g[to][nd]));
				for(int i=0;i<=k;i++) {
					g[to][nd][i+1]=g[x][nd][i];
				}
				q.push(to);
			}
		}
		for(int x:clr) {
			minf[x]=inf;
		}
	}
	void calc(int x) {
		getd(x,0);
		for(int i=0;i<=k+1;i++) {
			nd=i;
			for(int x:vd[i]) {
				memset(f[x][i],0x3f,sizeof(f[x][i]));
				f[x][i][0]=v[x];
				bfs(x);
				memset(g[x][i],0x3f,sizeof(g[x][i]));
				g[x][i][0]=v[x];
				bfs2(x);
			}
			for(int x:vd[i]) {
				vis[x]=true;
			}
		}
		for(Query q:qr[x]) {
			int &p=ans[q.id];
			p=inf;
			for(int x:anc[q.x]) {
				for(int y:anc[q.y]) {
					if(depth[x]+depth[y]>k) {
						continue;
					}
					p=min(p,min(f[q.x][depth[x]][0],fa[x]&&x!=q.x?g[q.x][depth[x]][0]-v[x]+minv[fa[x]]:inf)+min(f[q.y][depth[y]][0],fa[y]&&y!=q.y?g[q.y][depth[y]][0]-v[y]+minv[fa[y]]:inf));
//					for(int tx=0;tx<=1;tx++) {
//						for(int ty=0;ty<=1;ty++) {
//							if(depth[x]-tx+depth[y]-ty>k) {
//								continue;
//							}
//							p=min(p,f[q.x][depth[x]][0]+(!tx?0:minv[fa[fa[x]]])+f[q.y][depth[y]][0]+(!ty?0:minv[fa[fa[y]]]));
//						}
//					}
				}
			}
		}
		for(int x:all) {
			fa[x]=0;
			vis[x]=false;
			anc[x].clear();
			vd[depth[x]].clear();
		}
		all.clear();
		vis[x]=true;
		for(int to:tree[x]) {
			if(vis[to]) {
				continue;
			}
			calc(getr(to));
		}
	}
}

namespace KK {
	const int maxn=5005;
int f[maxn][maxn];

void trans(int x,int i,int fa,int d,int p) {
	if(d>k) {
		return ;
	}
	f[i+1][x]=min(f[i+1][x],p+v[x]);
	for(int to:tree[x]) {
		if(to==fa) {
			continue;
		}
		trans(to,i,x,d+1,p);
	}
}

void solve() {
	for(int i=1;i<=q;i++) {
		int x,y;
		cin>>x>>y;
		memset(f,0x3f,sizeof(f));
		f[1][x]=v[x];
		ll ans=inf;
		for(int i=1;i<=n;i++) {
			for(int x=1;x<=n;x++) {
				trans(x,i,0,0,f[i][x]);
			}
			ans=min(ans,f[i+1][y]);
		}
		cout<<ans<<"\n";
	}
}
}
signed main() {
	freopen("transmit.in","r",stdin);
	freopen("transmit.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>n>>q>>k;
	for(int i=1;i<=n;i++) {
		cin>>v[i];
	}
	for(int i=1;i<=n-1;i++) {
		int x,y;
		cin>>x>>y;
		tree[x].push_back(y);
		tree[y].push_back(x);
	}
	if(k==3) {
		KK::solve();
		return 0;
	}
	Tree::calc(getr(1));
	for(int i=1;i<=q;i++) {
		int x,y;
		cin>>x>>y;
		qr[Tree::lca(x,y)].push_back({x,y,i});
	}
	memset(vis,0,sizeof(vis));
	memset(f,0x3f,sizeof(f));
	memset(g,0x3f,sizeof(g));
	memset(minv,0x3f,sizeof(minv));
	memset(minf,0x3f,sizeof(minv));
	vis[0]=true;
	
	if(k<=2) {
		calc(getr(1));
	}
	for(int i=1;i<=q;i++) {
		cout<<ans[i]<<"\n";
	}
	cerr<<clock()<<"\n";
}
