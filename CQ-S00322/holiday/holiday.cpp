#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=2503;
int n,m,k,vis[N],vis2[N],pre[2][N][5];
vector<int>vec[N];
unsigned long long val[N],dp[2][N];
void dfs(int u,unsigned long long bj,int kk,int bj2,int bj3){
	if(kk>k)return;
	vis[u]=1;
	if(u!=1&&u!=bj3){
		int flag=0;
		for(int i=0;i<bj2;i++){
			if(u==pre[0][bj3][i]){
				flag=1;
				break;
			}
		}
		if(!flag){
			if(bj+val[u]>dp[1][u]){
				dp[1][u]=bj+val[u];
				pre[1][u][bj2]=bj3;
				for(int i=0;i<bj2;i++){
					pre[1][u][i]=pre[0][bj3][i];
				}
			}
		}
	}
	for(int i=0;i<(int)vec[u].size();i++){
		int v=vec[u][i];
		if(vis[v])continue;
		dfs(v,bj,kk+1,bj2,bj3);
	}
}
int main(){
	freopen("holiday.in","r",stdin);
	freopen("holiday.out","w",stdout);
	scanf("%d%d%d",&n,&m,&k);
	for(int i=2;i<=n;i++){
		scanf("%llu",&val[i]);
	}
	int x,y;
	for(int i=1;i<=m;i++){
		scanf("%d%d",&x,&y);
		vec[x].push_back(y);
		vec[y].push_back(x);
	}
	dfs(1,0,-1,0,1);
	for(int i=2;i<=n;i++){
		vis2[i]=vis[i];
	}
	for(int i=1;i<=3;i++){
		for(int j=1;j<=n;j++){
			dp[0][j]=dp[1][j];
			dp[1][j]=0;
			for(int kk=0;kk<i;kk++){
				pre[0][j][kk]=pre[1][j][kk];
			}
		}
		for(int j=2;j<=n;j++){
			if(!dp[0][j])continue;
			for(int kk=1;kk<=n;kk++){
				vis[kk]=0;
			}
			dfs(j,dp[0][j],-1,i,j);
		}
	}
	unsigned long long ans=0;
	for(int i=2;i<=n;i++){
		if(vis2[i])ans=max(ans,dp[1][i]);
	}
	printf("%llu",ans);
	return 0;
}
