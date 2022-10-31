#include<bits/stdc++.h>
using namespace std;
int f[2505][2505];
int e[2505][2505];
int w[2505],mk[2505];
int dp[5][2005];
int n,m,K,ans,s[5];
//虽然但是DP写错了:(
//40pts没问题吧 
void dfs(int pos,int step,int sum){
	if(step>=5){
		if(f[s[4]][1]<=K){
			ans=max(ans,sum);
		}
	}
	else{
		for(int i=2;i<=n;i++){
			if(f[pos][i]<=K&&pos!=i&&!mk[i]){
				s[step]=i;
				mk[i]=1;
				dfs(i,step+1,sum+w[i]);
				mk[i]=0;
			}
		}
	}
}
int main(){
	#ifndef LOCAL
	freopen("holiday.in","r",stdin);
	freopen("holiday.out","w",stdout);
	#endif
	scanf("%d%d%d",&n,&m,&K);
	K++;
	for(int i=2;i<=n;i++)scanf("%d",&w[i]);
	memset(f,0x3f,sizeof f);
	for(int i=1;i<=n;i++)f[i][i]=0;
	for(int i=1;i<=m;i++){
		int u,v;
		scanf("%d%d",&u,&v);
		e[u][v]=e[v][u]=1;
		f[u][v]=f[v][u]=1;
	}
	for(int k=1;k<=n;k++){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				f[i][j]=min(f[i][j],f[i][k]+f[k][j]);
			}
		}
	}//O(n^3) Floyd
	if(n<=100){
		dfs(1,1,0);
		cout << ans;
		return 0;//保险起见，就100的话还是去爆搜 
	}
	for(int i=1;i<=n;i++){
		if(f[1][i]<=K)//状态初始化 
			dp[1][i]=w[i];
	}
	for(int i=2;i<=4;i++){
		for(int j=2;j<=n;j++){
			for(int k=j+1;k<=n;k++){
				if(f[j][k]<=K)//挑选最长的一条路线 
					dp[i][j]=max(dp[i-1][k],dp[i][j]);
			}
			dp[i][j]+=w[j];
		}
	}
	int Ans=0;
	for(int i=1;i<=n;i++){
		if(f[i][1]<=K)//必须能回去 
			Ans=max(Ans,dp[4][i]);
	}
	cout << Ans;
	return 0;
	//这DP错的:( 
	//ex1和ex2都对了 
	//为什么ex3输出3907啊啊啊啊啊 
	//我的70pts呜呜呜
	//只剩下40pts了 
}
