#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N=2e5+5;
int n,q,k,val[N],f[N][20],dep[N];
LL dp[N],sum[N];
vector<int>G[N],res,res1;
void dfs(int pos,int fa){
	dep[pos]=dep[fa]+1,f[pos][0]=fa,sum[pos]=sum[fa]+val[pos];
	for(int i=1;i<=19;i++) f[pos][i]=f[f[pos][i-1]][i-1];
	for(int i=0;i<G[pos].size();i++){
		int to=G[pos][i];
		if(fa!=to) dfs(to,pos);
	}
}
void ddfs(int root,int pos,int dep){
	dp[pos]=min(dp[root]+val[pos],dp[pos]);
	if(dep==k) return ;
	for(int i=0;i<G[pos].size();i++){
		int to=G[pos][i];
		ddfs(root,to,dep+1);
	}
}
int LCA(int u,int v){
	if(dep[u]<dep[v]) swap(u,v);
	for(int i=19;~i;i--) if(dep[f[u][i]]>=dep[v]) u=f[u][i];
	if(u==v) return u;
	for(int i=19;~i;i--) if(f[u][i]^f[v][i]) u=f[u][i],v=f[v][i];
	return f[u][0];
}
void DP(int pos){
	ddfs(pos,pos,0);
	for(int i=0;i<G[pos].size();i++){
		int to=G[pos][i];
		if(to!=f[pos][0]) DP(to);
	}
}
int main(){
	freopen("transmit.in","r",stdin);
	freopen("transmit.out","w",stdout);
	scanf("%d %d %d",&n,&q,&k);
	for(int i=1;i<=n;i++) scanf("%d",&val[i]);
	for(int i=1;i<n;i++){
		int u,v;
		scanf("%d %d",&u,&v);
		G[u].push_back(v),G[v].push_back(u);
	}
	if(k==1 && n>200){
		dfs(1,0);
		while(q--){
			int u,v,lca;
			scanf("%d %d",&u,&v);
			lca=LCA(u,v);
			printf("%lld\n",sum[u]+sum[v]-sum[lca]);
		}
		return 0;
	}
	while(q--){
		int u,v;
		scanf("%d %d",&u,&v);
		memset(dp,0x3f3f3f3f,sizeof(dp));
		dp[u]=val[u];
		dfs(u,0),DP(u);
		printf("%lld\n",dp[v]);
	}
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


10 10 1
835701672 912572995 368308854 156367225 251245604 788978650 385396264 960190423 51944511 479806606
2 1
3 2
4 2
5 3
6 3
7 2
8 7
9 1
10 9
1 7
1 5
2 1
1 9
10 5
3 10
2 9
10 2
1 4
4 7
*/
