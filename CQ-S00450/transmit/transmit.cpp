#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=2e5+10;
struct node{
	int to,nxt;
}e[N<<1];
int head[N],cnt;
void add(int u,int v){
	e[++cnt].nxt=head[u];
	e[cnt].to=v;
	head[u]=cnt;
}
ll w[N],dis[N];
int f[N][20],dep[N];
void dfs(int x,int fa){
	f[x][0]=fa;
	dep[x]=dep[fa]+1;
	for(int i=1;i<20;i++)f[x][i]=f[f[x][i-1]][i-1];
	for(int i=head[x];i;i=e[i].nxt){
		int v=e[i].to;
		if(v==fa)continue;
		dis[v]=dis[x]+w[v];
		dfs(v,x);
	}
}
int lca(int x,int y){
	if(dep[x]<dep[y])swap(x,y);
	for(int i=19;i>=0;i--){
		if(dep[f[x][i]]>=dep[y])x=f[x][i];
	}
	if(x==y)return x;
	for(int i=19;i>=0;i--){
		if(f[x][i]!=f[y][i])x=f[x][i],y=f[y][i];
	}
	return f[x][0];
}
void solve1(int Q){
	while(Q--){
		int x,y;
		scanf("%d%d",&x,&y);
		int l=lca(x,y);
		printf("%lld\n",dis[x]+dis[y]-2*dis[l]+w[l]);
	}
}
int main(){
	//离线？怎么做？
	//k=1就是求在树上的距离 
	freopen("transmit.in","r",stdin);
	freopen("transmit.out","w",stdout);
	int n,Q,K;
	scanf("%d%d%d",&n,&Q,&K);
	for(int i=1;i<=n;i++){
		scanf("%lld",&w[i]);
	}
	for(int i=1;i<n;i++){
		int x,y;
		scanf("%d%d",&x,&y);
		add(x,y),add(y,x);
	}
	dis[1]=w[1];
	dfs(1,0);
	if(K==1){
		solve1(Q);
		return 0;
	}
	
	return 0;
}
