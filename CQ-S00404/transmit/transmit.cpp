/*
16 pts
*/
#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2005;
struct node{
	int id,val;
	friend bool operator<(node x,node y){
		return x.val>y.val;
	}
};
int n,q,k,a[N],u,v,dp[N][N],Dp[N],s,t,ans;
vector<node> g[N];
bool f[N],vis[N];
void dij(int s){
	memset(vis,0,sizeof vis);
	memset(Dp,0x3f,sizeof Dp);
	priority_queue<node> q;
	Dp[s]=0;
	q.push(node{s,0});
	while(!q.empty()){
		int x=q.top().id;
		q.pop();
		if(vis[x]){
			continue;
		}
		vis[x]=1;
		int l=g[x].size();
		for(int i=0;i<l;i++){
			int y=g[x][i].id,val=g[x][i].val;
			if(Dp[x]+val<Dp[y]){
				Dp[y]=Dp[x]+val;
				q.push(node{y,Dp[y]});
			}
		}
	}
}
void dfs(int x,int sum){
	if(sum>=ans){
		return;
	}
	if(x==t){
		ans=min(ans,sum);
		return;
	}
	for(int i=1;i<=n;i++){
		if(!f[i]){
			if(dp[x][i]<=k){
				f[i]=1;
				dfs(i,sum+a[i]);
				f[i]=0;
			}
		}
	}
}
signed main(){
	freopen("transmit.in","r",stdin);
	freopen("transmit.out","w",stdout);
	scanf("%lld %lld %lld",&n,&q,&k);
	if(n<=205){
		memset(dp,0x3f,sizeof dp);
		for(int i=1;i<=n;i++){
			scanf("%lld",&a[i]);
			dp[i][i]=0;
		}
		for(int i=1;i<n;i++){
			scanf("%lld %lld",&u,&v);
			dp[u][v]=dp[v][u]=1;
		}
		for(int k=1;k<=n;k++){
			for(int i=1;i<=n;i++){
				for(int j=1;j<=n;j++){
					if(dp[i][k]+dp[k][j]<=dp[i][j]){
						dp[i][j]=dp[i][k]+dp[k][j];
					}
				}
			}
		}
		while(q--){
			scanf("%lld %lld",&s,&t);
			ans=0x3f3f3f3f3f3f3f3f;
			dfs(s,a[s]);
			printf("%lld\n",ans);
		}		
	}
	else{
		for(int i=1;i<=n;i++){
			scanf("%lld",&a[i]);
		}
		for(int i=1;i<n;i++){
			scanf("%lld %lld",&u,&v);
			g[u].push_back(node{v,a[v]});
			g[v].push_back(node{u,a[u]});
		}
		while(q--){
			scanf("%lld %lld",&s,&t);
			dij(s);
			printf("%lld\n",Dp[t]+a[s]);
		}		
	}
	return 0;
}
