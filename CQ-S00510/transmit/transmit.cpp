#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=2e5+5;
int rt[maxn][19];
int Log[maxn];
int n,q,k;
typedef long long ll;
ll val[maxn];
vector<int>G[maxn];
ll sum[maxn];
int dep[maxn];
void dfs(int u,int fa){
	sum[u]+=val[u];
	rt[u][0]=fa;
	dep[u]=dep[fa]+1;
	for(int i=1;i<=Log[dep[u]];i++){
		rt[u][i]=rt[rt[u][i-1]][i-1];
	}
	for(auto v:G[u]){
		if(v==fa)continue;
		sum[v]=sum[u];
		dfs(v,u);
	}
}
int LCA(int x,int y){
	if(dep[x]<dep[y])swap(x,y);
	while(dep[x]>dep[y])x=rt[x][Log[dep[x]-dep[y]]];
	if(x==y)return x;
	for(int i=18;i>=0;i--){
		if(rt[x][i]&&rt[y][i]&&rt[x][i]!=rt[y][i]){
			x=rt[x][i];
			y=rt[y][i];
		}
	}
	return rt[x][0];
}
int main(){
	freopen("transmit.in","r",stdin);
	freopen("transmit.out","w",stdout);
	Log[0]=-1;
	for(int i=1;i<maxn;i++)Log[i]=Log[i/2]+1;
	scanf("%d%d%d",&n,&q,&k);
	for(int i=1;i<=n;i++){
		scanf("%lld",&val[i]);
	}
	for(int i=1,u,v;i<n;i++){
		scanf("%d%d",&u,&v);
		G[u].push_back(v);
		G[v].push_back(u);
	}
	dfs(1,0); 
	while(q--){
		int u,v;
		scanf("%d%d",&u,&v);
		printf("%lld\n",sum[u]+sum[v]-2*sum[LCA(u,v)]+val[LCA(u,v)]);
	}
	return 0;
}
