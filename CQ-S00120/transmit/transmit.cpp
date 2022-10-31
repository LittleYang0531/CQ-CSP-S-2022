#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,q,k;
vector<int> G[200010];
int dep[2010],fa[2010][20],v[2010],put[2010];
ll dp[2010];
void dfs(int rt,int dad){
	dep[rt]=dep[dad]+1;
	fa[rt][0]=dad;
	for(int i=1;i<=11;i++)fa[rt][i]=fa[fa[rt][i-1]][i-1];
	for(int to:G[rt])if(to!=dad)dfs(to,rt);
}
int lca(int x,int y){
	if(dep[x]<dep[y])swap(x,y);
	for(int i=11;i>=0;i--)
	if(dep[fa[x][i]]>=dep[y])x=fa[x][i];
	if(x==y)return x;
	for(int i=11;i>=0;i--)
	if(fa[x][i]!=fa[y][i])x=fa[x][i],y=fa[y][i];
	return fa[x][0];
}
int main(){
	scanf("%d%d%d",&n,&q,&k);
	for(int i=1;i<=n;i++)scanf("%d",&v[i]);
	for(int i=1;i<n;i++){
		int x,y;
		scanf("%d%d",&x,&y);
		G[x].push_back(y);
		G[y].push_back(x);
	}
	dfs(1,0);
	for(int i=1;i<=q;i++){
		memset(dp,0x3f,sizeof(dp));
		int x,y;
		scanf("%d%d",&x,&y);
		int lc=lca(x,y),tot=0;
		int dis=dep[x]+dep[y]-dep[lc]*2+1;
		while(x!=lc){
			put[++tot]=x;
			x=fa[x][0];
		}
		put[++tot]=lc;
		for(int i=dis;i>=tot+1;i--){
			put[i]=y;
			y=fa[y][0];
		}
		dp[1]=v[put[1]];dp[2]=dp[1]+v[put[2]];
		for(int i=3;i<=dis;i++)
		for(int j=1;j<=k;j++)dp[i]=min(dp[i],dp[i-j]+v[put[i]]);
		printf("%lld\n",dp[dis]);
	}
	return 0;
}
