#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
int n,T,k;
vector<int>vec[200005];
int fath[200005][21],dep[200005];
ll v[200005],f[200005];
void dfs(int now,int fa){
	fath[now][0]=fa;
	dep[now]=dep[fa]+1;
	for(int i=1;i<=20;i++){
		fath[now][i]=fath[fath[now][i-1]][i-1];
		if(fath[now][i]==0)break;
	}
	for(auto to:vec[now]){
		if(to==fa)continue;
		dfs(to,now);
	}
}
int lca(int x,int y){
	if(dep[x]<dep[y])swap(x,y);
	for(int i=20;i>=0;i--){
		if(dep[fath[x][i]]>=dep[y])x=fath[x][i];
	}
	if(x==y)return x;
	for(int i=20;i>=0;i--){
		if(fath[x][i]!=fath[y][i])x=fath[x][i],y=fath[y][i];
	}
	return fath[x][0];
}
int dis(int x,int y){
	int l=lca(x,y);
	return dep[x]+dep[y]-2*dep[l];
}
void dfs(int now,ll ans){
	if(f[now]<ans)return;
	f[now]=ans;
	for(int i=1;i<=n;i++){
		if(now!=i&&dis(now,i)<=k)dfs(i,ans+v[i]);
	}
}
int main(){
	freopen("transmit.in","r",stdin);
	freopen("transmit.out","w",stdout);
	scanf("%d%d%d",&n,&T,&k);
	for(int i=1;i<=n;i++)scanf("%lld",&v[i]);
	for(int i=2;i<=n;i++){
		int x,y;
		scanf("%d%d",&x,&y);
		vec[x].push_back(y);
		vec[y].push_back(x);
	}
	dfs(1,0);
	while(T--){
		int s,t;
		scanf("%d%d",&s,&t);
		for(int i=1;i<=n;i++)f[i]=1e18;
		dfs(s,v[s]);
		printf("%lld\n",f[t]);
	}
	return 0;
}
