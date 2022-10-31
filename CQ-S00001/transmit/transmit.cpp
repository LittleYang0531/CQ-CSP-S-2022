#include<bits/stdc++.h>
using namespace std;

const int maxn=2e5+5;

int a[maxn],dep[maxn],f[maxn][20];
long long dis[maxn];
vector<int> g[maxn];

void dfs(int x,int fa){
	dep[x]=dep[fa]+1;dis[x]=dis[fa]+a[x];
	f[x][0]=fa;
	for(int i=1;i<20;i++) f[x][i]=f[f[x][i-1]][i-1];
	for(int y:g[x]){
		if(y==fa) continue;
		dfs(y,x);
	}
	return ;
}

int lca(int x,int y){
	if(dep[x]<dep[y]) swap(x,y);
	for(int i=19;i>=0;i--) if(dep[f[x][i]]>=dep[y]) x=f[x][i];
	if(x==y) return x;
	for(int i=19;i>=0;i--) if(f[x][i]!=f[y][i]) x=f[x][i],y=f[y][i];
	return f[x][0];
}

int main(){
	freopen("transmit.in","r",stdin);
	freopen("transmit.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	int n,q,k;
	cin>>n>>q>>k;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1,u,v;i<n;i++) {
		cin>>u>>v;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	dfs(1,0);
	for(int i=1,u,v;i<=q;i++) {
		cin>>u>>v;
		if(k==1) {
			int d=lca(u,v);
			cout<<dis[u]+dis[v]-dis[d]-dis[f[d][0]]<<"\n";
		}else  cout<<"CSP-SÒ»µÈ½±£¡£¡£¡\n";
	}
	return 0;
}
