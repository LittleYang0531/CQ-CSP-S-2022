#include<bits/stdc++.h>
using namespace std;
void laozhuma_file(){
	freopen("holiday.in","r",stdin);
	freopen("holiday.out","w",stdout);
}
#define MAXN 2500
int n,m,k,Enderch,laozhuma;
long long ans;
int dis[MAXN+5][MAXN+5];
long long val[MAXN+5];
int pre[MAXN+5][10];
vector<int>G[MAXN+5];
bool vis[MAXN+5];
long long dp[MAXN+5][5];
void bfs(int s){
	memset(vis,0,sizeof(vis));vis[s]=1;
	queue<int>q;
	q.push(s);
	dis[s][s]=-1;
	while(!q.empty()){
		int x=q.front();q.pop();
		int len=G[x].size();
		for(int i=0;i<len;i++){
			int u=G[x][i];
			if(!vis[u]){
				vis[u]=1;
				dis[s][u]=dis[s][x]+1;
				q.push(u);
			}
		}
	}
}
int main(){laozhuma_file();
	scanf("%d%d%d",&n,&m,&k);
	val[1]=0;
	for(int i=2;i<=n;i++){
		scanf("%lld",&val[i]);
	}
	for(int i=1;i<=m;i++){
		scanf("%d%d",&Enderch,&laozhuma);
		G[Enderch].push_back(laozhuma);
		G[laozhuma].push_back(Enderch);
	} memset(dis,0x3f3f3f3f,sizeof(dis));
	for(int i=1;i<=n;i++){
		bfs(i);
	}
	for(int i=2;i<=n;i++){
		if(dis[1][i]<=k){
			dp[i][1]=val[i];
		}
	}
	for(int i=2;i<=n;i++){
		for(int j=2;j<=n;j++){
			if(i==j||dis[i][j]>k) continue;
			if(dp[j][1]+val[i]>dp[i][2]){
				dp[i][2]=dp[j][1]+val[i];
				pre[i][2]=j;
			}
		}
	}
	for(int i=2;i<=n;i++){
		for(int j=2;j<=n;j++){
			if(i==j||i==pre[j][2]||dis[i][j]>k) continue;
			if(dp[j][2]+val[i]>dp[i][3]){
				dp[i][3]=dp[j][2]+val[i];
				pre[i][3]=j;
			}
		}
	}
	for(int i=2;i<=n;i++){
		for(int j=2;j<=n;j++){
			if(i==j||i==pre[j][3]||i==pre[pre[j][3]][2]||dis[i][j]>k) continue;
			if(dp[j][3]+val[i]>dp[i][4]){
				dp[i][4]=dp[j][3]+val[i];
				pre[i][4]=j;
			}
		}
	}
	for(int i=2;i<=n;i++){
		if(dis[i][1]>k) continue;
		ans=max(ans,dp[i][4]);
	}printf("%lld",ans);
	return 0;
}

