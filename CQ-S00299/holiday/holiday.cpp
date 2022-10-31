#include<bits/stdc++.h>
#define int long long
#define ll long long
using namespace std;
inline int read(){
	int sss=0,www=1;
	char chh=getchar();
	while(chh<'0'||chh>'9'){
		if(chh=='-') www=-1;
		chh=getchar();
	}
	while(chh>='0'&&chh<='9'){
		sss=sss*10+chh-'0';
		chh=getchar();
	}
	return sss*www;
}
typedef pair<int,int> par;
int n,m,k;
int head[2505],to[200005],nxt[200005],tot=1;
ll a[2505];
bool vis[2505][2505];
set<par> dist[2505];
void add(int u,int v){
	to[++tot]=v;
	nxt[tot]=head[u];
	head[u]=tot;
}
void add_edge(int u,int v){
	add(u,v),add(v,u);
}
void bfs(int st,bool *dist){
	queue<par> q; q.push(par(st,0));
	while(!q.empty()){
		int x=q.front().first,dis=q.front().second; q.pop();
		if(dis==k+1) continue;
		for(register int i=head[x];i;i=nxt[i]){
			int u=to[i];
			if(!dist[u]){
				dist[u]=true;
				q.push(par(u,dis+1));
			}
		}
	}
}
signed main(){
	freopen("holiday.in","r",stdin);
	freopen("holiday.out","w",stdout);
	n=read(),m=read(),k=read();
	for(register int i=2;i<=n;i++) scanf("%lld",&a[i]);
	for(register int i=1;i<=m;i++) add_edge(read(),read());
	for(register int i=1;i<=n;i++) bfs(i,vis[i]);
	for(register int i=1;i<=n;i++) vis[i][i]=false;
	for(register int i=2;i<=n;i++){
		for(register int j=2;j<=n;j++){
			if(j==i) continue;
			if(vis[1][j]&&vis[j][i]){
				dist[i].insert(par(a[j],j));
				while(dist[i].size()>3) dist[i].erase(dist[i].begin());
			}
		}
	}
	ll ans=0;
	for(register int x=2;x<=n;x++){
		for(register int y=x+1;y<=n;y++){
			if(!vis[x][y]) continue;
			for(auto i:dist[x]){
				int u=i.second;
				for(auto j:dist[y]){
					int v=j.second;
					if(u==y||v==x||u==v) continue;
					ans=max(ans,a[x]+a[y]+a[u]+a[v]);
				}
			}
		}
	}
	cout<<ans;
	return 0;
}
