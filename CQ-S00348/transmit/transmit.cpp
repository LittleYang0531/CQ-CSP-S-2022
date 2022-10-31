#include<bits/stdc++.h>
using namespace std;
#define int long long

const int Maxn=2e5+10;
int N,Q,K,v[Maxn],cnt,hed[Maxn],sum[Maxn];
int dep[Maxn],top[Maxn],siz[Maxn],fa[Maxn];
int son[Maxn];
int dist[2010][2010];
vector<int> num[2010];
bool Vis[2010];
struct DATA{
	int nxt,to;
}G[Maxn];
struct node{
	int x,n;
	bool operator <(const node &t)const{return n>t.n;}
};
priority_queue<node> Qu;

inline int read(){
	int ret=0,f=0; char ch=getchar();
	while(!isdigit(ch)) f=(ch=='-'),ch=getchar();
	while(isdigit(ch)) ret=(ret<<1)+(ret<<3)+(ch^48),ch=getchar();
	return f?-ret:ret;
}

inline void Swap(int &x,int &y){x^=y^=x^=y;}

void Addedge(int x,int y){
	G[++cnt].nxt=hed[x]; G[cnt].to=y; hed[x]=cnt;
}

void DFS1(int x,int p){
	dep[x]=dep[p]+1; sum[x]=sum[p]+v[x]; siz[x]=1; fa[x]=p;
	for(int y,i=hed[x];i;i=G[i].nxt){
		if((y=G[i].to)==p) continue;
		DFS1(y,x); siz[x]+=siz[y];
		if(siz[y]>siz[son[x]]) son[x]=y;
	}
}

void DFS2(int x,int t){
	top[x]=t;
	if(!son[x]) return;
	DFS2(son[x],t);
	for(int y,i=hed[x];i;i=G[i].nxt){
		if((y=G[i].to)==son[x]||y==fa[x]) continue;
		DFS2(y,y);
	}
}

int Get_lca(int x,int y){
	while(top[x]!=top[y]){
		if(dep[top[x]]<dep[top[y]]) Swap(x,y);
		x=fa[top[x]];
	}
	return dep[x]<dep[y]?x:y;
}

void Solve1(){
	DFS1(1,0); DFS2(1,1);
	while(Q--){
		int u=read(),v=read();
		int lca=Get_lca(u,v);
		printf("%lld\n",sum[u]+sum[v]-sum[lca]-sum[fa[lca]]);
	}
	exit(0);
}

void DFS(int x,int p,int dep,int id){
	if(x!=id) num[id].push_back(x);
	for(int y,i=hed[x];i;i=G[i].nxt){
		if((y=G[i].to)==p) continue;
		if(dep<K) DFS(y,x,dep+1,id);
	}
}

void Dijkstra(int S){
	memset(Vis,0,sizeof Vis);
	dist[S][S]=v[S]; Qu.push((node){S,v[S]});
	while(!Qu.empty()){
		int x=Qu.top().x; Qu.pop();
		Vis[x]=true;
		for(int y,i=hed[x];i;i=G[i].nxt){
			y=G[i].to;
			if(dist[S][y]>dist[S][x]+v[y]){
				dist[S][y]=dist[S][x]+v[y];
				if(!Vis[y]) Qu.push((node){y,dist[S][y]});
			}
		}
	}
}

signed main(){
	freopen("transmit.in","r",stdin);
	freopen("transmit.out","w",stdout);
	N=read(),Q=read(),K=read();
	for(int i=1;i<=N;++i) v[i]=read();
	for(int u,v,i=1;i<N;++i)
		u=read(),v=read(),Addedge(u,v),Addedge(v,u);
	if(K==1) Solve1();
	for(int i=1;i<=N;++i) DFS(i,0,0,i);
	cnt=0; memset(hed,0,sizeof hed);
	for(int i=1;i<=N;++i)
		for(int j=0;j<(int)num[i].size();++j) Addedge(i,num[i][j]);
	memset(dist,0x3f,sizeof dist);
	for(int i=1;i<=N;++i) Dijkstra(i);
	while(Q--){
		int u=read(),v=read();
		printf("%lld\n",dist[u][v]);
	}
	return 0;
}
