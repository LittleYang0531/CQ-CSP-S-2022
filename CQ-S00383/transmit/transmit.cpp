#include<cstdio>
#include<vector>
#include<cstring>
using namespace std;
int n,q,k;
int a[200005],ta,b[200005],tb;
long long dp[200005];
int dis[200005],dad[200005],w[200005];
vector<int> G[200005];
long long min(long long a,long long b){return a<b?a:b;}
void dfs(int rt){
	for(int i=0;i<(int)G[rt].size();i++){
		int to=G[rt][i];
		if(to==dad[rt])continue;
		dad[to]=rt;
		dis[to]=dis[rt]+1;
		dfs(to);
	}
}
int main(){
	freopen("transmit.in","r",stdin);
	freopen("transmit.out","w",stdout);
	scanf("%d%d%d",&n,&q,&k);
	for(int i=1;i<=n;i++)scanf("%d",&w[i]);
	for(int i=1;i<n;i++){
		int a,b;
		scanf("%d%d",&a,&b);
		G[a].push_back(b);
		G[b].push_back(a);
	}
	dfs(1);
	while(q--){
		ta=tb=0;
		int u,v;
		scanf("%d%d",&u,&v);
		while(u!=v){
			if(dis[u]>dis[v])a[++ta]=w[u],u=dad[u];
			else b[++tb]=w[v],v=dad[v];
		}
		a[++ta]=w[u];
		for(int i=tb;i>=1;i--)a[++ta]=b[i];
		memset(dp,0x3f,sizeof(dp));
		dp[1]=a[1];
		for(int i=2;i<=ta;i++){
			for(int j=max(i-k,1);j<i;j++)dp[i]=min(dp[i],dp[j]);
			dp[i]+=a[i];
		}
		printf("%lld\n",dp[ta]);
	}
	return 0;
}
