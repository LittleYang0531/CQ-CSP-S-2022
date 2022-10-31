#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=2e3+5;
ll a[N];
vector <int> G[N];
ll dp[N][5];
int n,Q,k;
void dfs(int u,int fa){
	for(int i=0;i<G[u].size();++i){
		int v=G[u][i];
		if(v==fa)	continue;
		for(int i=0;i<k;++i)
			dp[v][i+1]=min(dp[v][i+1],dp[u][i]),
			dp[v][0]=min(dp[v][0],dp[u][i]+a[v]);
		dfs(v,u);
	}
}
int main(){
	freopen("transmit.in","r",stdin);
	freopen("transmit.out","w",stdout);
	scanf("%d %d %d",&n,&Q,&k);
	for(int i=1;i<=n;++i)
		scanf("%lld",&a[i]);
	for(int i=1;i<n;++i){
		int u,v;
		scanf("%d %d",&u,&v);
		G[u].push_back(v);
		G[v].push_back(u);
	}
	while(Q--){
		int s,t;
		scanf("%d %d",&s,&t);
		memset(dp,0x3f,sizeof(dp));
		dp[s][0]=a[s];
		for(int i=1;i<=n;++i)	dfs(i,-1);
		for(int i=1;i<=n;++i)	dfs(i,-1);
		printf("%lld\n",dp[t][0]);
	}
	return 0;
}
