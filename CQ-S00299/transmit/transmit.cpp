#include<bits/stdc++.h>
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
int n,q,k;
ll v[200005];
int head[200005],to[400005],nxt[400005],tot=1;
void add(int u,int v){
	to[++tot]=v;
	nxt[tot]=head[u];
	head[u]=tot;
}
void add_edge(int u,int v){
	add(u,v),add(v,u);
}
namespace solve1{
	int fa[200005][20],Log[200005],depth[200005];
	ll dist[200005];
	void init_depth(int now,int father){
		fa[now][0]=father; depth[now]=depth[father]+1;
		dist[now]=dist[father]+v[now];
		for(register int i=1;i<=Log[depth[now]];i++)
			fa[now][i]=fa[fa[now][i-1]][i-1];
		for(register int i=head[now];i;i=nxt[i]){
			int u=to[i]; if(u==father) continue;
			init_depth(u,now);
		}
	}
	int LCA(int x,int y){
		if(depth[x]<depth[y]) swap(x,y);
		while(depth[x]>depth[y])
			x=fa[x][Log[depth[x]-depth[y]]-1];
		if(x==y) return x;
		for(register int i=Log[depth[x]-1];i>=0;i--){
			if(fa[x][i]!=fa[y][i]){
				x=fa[x][i];
				y=fa[y][i];
			}
		}
		return fa[x][0];
	}
	void main(){
		for(register int i=1;i<=n;i++) Log[i]=Log[i>>1]+1;
		init_depth(1,0);
		while(q--){
			int x=read(),y=read();
			int lca=LCA(x,y);
			cout<<dist[x]+dist[y]-dist[lca]-dist[fa[lca][0]]<<"\n";
		}
	}
}
namespace solve2{
	ll dist[205][205];
	ll dis[205][205]; bool vis[205][205];
	void main(){
		memset(dist,0x3f,sizeof dist);
		for(register int x=1;x<=n;x++){
			for(register int i=head[x];i;i=nxt[i]){
				int u=to[i];
				dist[x][u]=1;
			}
		}
		for(register int k=1;k<=n;k++){
			for(register int i=1;i<=n;i++){
				for(register int j=1;j<=n;j++){
					dist[i][j]=min(dist[i][j],dist[i][k]+dist[k][j]);
				}
			}
		}
		memset(dis,0x3f,sizeof dis);
		for(register int i=1;i<=n;i++){
			for(register int j=1;j<=n;j++){
				if(dist[i][j]<=k) dis[i][j]=v[j];
			}
		}
		for(register int k=1;k<=n;k++){
			for(register int i=1;i<=n;i++){
				for(register int j=1;j<=n;j++){
					dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
				}
			}
		}
		while(q--){
			int x=read(),y=read();
			cout<<dis[x][y]+v[x]<<"\n";
		}
	}
}
int main(){
	freopen("transmit.in","r",stdin);
	freopen("transmit.out","w",stdout);
	n=read(),q=read(),k=read();
	for(register int i=1;i<=n;i++) v[i]=(ll)read();
	for(register int i=1;i<n;i++) add_edge(read(),read());
	if(k==1) solve1::main();
	else solve2::main();
	return 0;
}
