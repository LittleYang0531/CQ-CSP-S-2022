#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const int MAXN=200005;
bool vis[MAXN];
int n,cnt,q,u,v,k,dep[MAXN],fa[MAXN][18],b[MAXN];
LL mn,s[MAXN][18],a[MAXN]; 
vector<int>g[MAXN];	
void bfs(){
	memset(dep,-1,sizeof dep);
	dep[1]=0;
	queue<int>q;
	q.push(1);
	while(!q.empty()){
		int u=q.front();
		q.pop();
		for(int i=0;i<g[u].size();++i){
			int v=g[u][i];
			if(~dep[v])continue;
			dep[v]=dep[u]+1;
			q.push(v);
		}
	}
}
LL S(int u,int v){
	if(dep[u]<dep[v])swap(u,v);
	int x=u,y=v;
	int k=dep[u]-dep[v];
	LL tot=0;
	for(int i=17;i>=0;--i){
		if(k>=(1<<i)){
			tot+=s[u][i];
			k-=(1<<i);
			u=fa[u][i];
		}
	}
	if(u==v)return tot+a[x];
	for(int i=17;i>=0;--i){
		if(fa[u][i]!=fa[v][i]){
			tot+=s[u][i];
			tot+=s[v][i];
			u=fa[u][i];
			v=fa[v][i];
		}
	}
	if(u==v)return tot;
	return tot+a[x]+a[y]+a[fa[u][0]];
}
int lca(int u,int v){
	if(dep[u]<dep[v])swap(u,v);
	int k=dep[u]-dep[v];
	for(int i=17;i>=0;--i){
		if(k>=(1<<i)){
			k-=(1<<i);
			u=fa[u][i];
		}
	}
	if(u==v)return u;
	for(int i=17;i>=0;--i){
		if(fa[u][i]!=fa[v][i]){
			u=fa[u][i];
			v=fa[v][i];
		}
	}
	if(u==v)return u;
	return fa[u][0];
}
void dfs(int u,int fat){
	fa[u][0]=fat;
	s[u][0]=a[fat];
	for(int i=0;i<g[u].size();++i){
		int v=g[u][i];
		if(v==fat)continue;
		dfs(v,u);
	}	
}
void make(){
	for(int i=1;i<=n;++i){
		for(int j=1;(1<<j)<=n;++j){
			fa[i][j]=fa[fa[i][j-1]][j-1];
			s[i][j]=s[fa[i][j-1]][j-1]+s[i][j-1];
		}
	}
} 
void DFS(int u,int T,LL sum){
	if(mn<sum)return; 
	if(u==T){
		mn=min(mn,sum);
		return;
	}
	vis[u]=1;
	for(int i=1;i<=n;++i){
		if((!vis[i])&&dep[u]+dep[i]-2*dep[lca(u,i)]<=k)DFS(i,T,sum+a[i]);	
	}
	vis[u]=0;
}
int main(){
	freopen("transmit.in","r",stdin);
	freopen("transmit.out","w",stdout);
	scanf("%d%d%d",&n,&q,&k);
	for(int i=1;i<=n;++i)scanf("%lld",&a[i]);	
	for(int i=1;i<n;++i){
		scanf("%d%d",&u,&v);
		g[u].push_back(v);
		g[v].push_back(u);
	}
	dfs(1,0);
	make();
	bfs();
//	cout<<sum(2,3);
	if(k==1){
		while(q--){
			scanf("%d%d",&u,&v);
			printf("%lld\n",S(u,v));
		}
	}
	else{
		while(q--){
			scanf("%d%d",&u,&v);
			mn=LONG_LONG_MAX;
			for(int i=1;i<=n;++i)vis[i]=0;
			DFS(u,v,a[u]);
			printf("%lld\n",mn);
		}
	}
	return 0;
}	
/*
7 5 1
1 2 3 4 5 6 7
1 6
1 7
2 6
4 6
5 7
3 7
*/
