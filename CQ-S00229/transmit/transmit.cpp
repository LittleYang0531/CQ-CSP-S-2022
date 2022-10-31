#include<bits/stdc++.h>
using namespace std;
void laozhuma_file(){
	freopen("transmit.in","r",stdin);
	freopen("transmit.out","w",stdout);
}
#define MAXN 200000
int n,q,k,x,y;
long long v[MAXN+5];
int dep[MAXN+5],fa[MAXN+5];
vector<int>G[MAXN+5];
void dfs(int x,int father){
	int len=G[x].size();
	for(int i=0;i<len;i++){
		int u=G[x][i];
		if(u==father) continue;
		dep[u]=dep[x]+1;fa[u]=x;
		dfs(u,x);
	}return ;
}
int LCA(int x,int y){
	if(dep[x]<dep[y]) swap(x,y);
	while(dep[x]>dep[y]){
		x=fa[x];
	}
	while(x!=y){
		x=fa[x];
		y=fa[y];
	}return x;
}
int c[MAXN+5];
int d[MAXN+5];
long long dp[MAXN+5];
int main(){laozhuma_file();
	scanf("%d%d%d",&n,&q,&k);
	for(int i=1;i<=n;i++){
		scanf("%lld",&v[i]);
	}
	for(int i=1;i<n;i++){
		scanf("%d%d",&x,&y);
		G[x].push_back(y);
		G[y].push_back(x);
	}dfs(1,-114514);
	for(int i=1;i<=q;i++){
		scanf("%d%d",&x,&y);
		int lca=LCA(x,y);
		int xx=x,yy=y,len=0,len1=0;
		while(xx!=lca){
			c[++len]=xx;
			xx=fa[xx];
		} c[++len]=xx;
		while(yy!=lca){
			d[++len1]=yy;
			yy=fa[yy];
		}
		for(int i=len+1;i<=len+len1;i++){
			c[i]=d[len+len1-i+1];
		} len+=len1;
		dp[1]=v[c[1]];
		for(int i=2;i<=len;i++){
			dp[i]=LONG_LONG_MAX;
			for(int j=1;j<=k;j++){
				if(i-j<=0)continue;
				dp[i]=min(dp[i],dp[i-j]+1ll*v[c[i]]);
			}
		}
		printf("%lld\n",dp[len]);
	}
	return 0;
}

