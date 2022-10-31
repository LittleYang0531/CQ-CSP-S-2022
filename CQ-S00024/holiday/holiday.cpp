#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,k,dp[2510][4],ans,val[2510],x,y;
vector<int> to[2510],dis[2510];
map<int,int> vis;
int read(){
	int s=0;
	char ch=getchar(),last=' ';
	while(ch<'0'||ch>'9')
		last=ch,ch=getchar();
	while(ch>='0'&&ch<='9')
		s=(s<<1)+(s<<3)+(ch^48),ch=getchar();
	return last=='-'?-s:s;
}
void dfs1(int top,int u,int f,int dep){
	if(dep>k)
		return;
	vis[u]=top;
	for(auto v:to[u])
		if(vis[v]!=top){
			dis[top].push_back(v);
			dfs1(top,v,u,dep+1);
		}
}
void dfs2(int u,int f,int cnt,int va){
	if(cnt==4){
		for(auto v:dis[u])
			if(v==1)
				ans=max(ans,va);
		return;
	}
	vis[u]=-1;
	for(auto v:dis[u])
		if(v!=f&&vis[v]!=-1)
			dfs2(v,u,cnt+1,va+val[v]);
	vis[u]=0;
}
signed main(){
	freopen("holiday.in","r",stdin);
	freopen("holiday.out","w",stdout);
	n=read(),m=read(),k=read();
	for(int i=2;i<=n;i++)
		val[i]=read();
	for(int i=1;i<=m;i++){
		x=read(),y=read();
		to[x].push_back(y);
		to[y].push_back(x);
	}
	for(int i=1;i<=n;i++)
		dfs1(i,i,0,0);
	dfs2(1,0,0,0);
	printf("%lld\n",ans);
    return 0;
}

