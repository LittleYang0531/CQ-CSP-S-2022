#include<cstdio>
#include<cstring>
#include<iostream>
using namespace std;
using ll=long long;
int d[2005][2005];
int v[2005];
ll ans;
bool vis[2005];
void dfs(int n,int x,int y,int k,ll c){
	if(ans<=c)return ;
	if(d[x][y]<=k){ans=c;return ;}
	for(int i=1;i<=n;++i)if(!vis[i]){
		if(d[x][i]>k)continue;
		vis[i]=1;dfs(n,i,y,k,c+v[i]);
		vis[i]=0;
	}
}
int main(){
	freopen("transmit.in","r",stdin);
	freopen("transmit.out","w",stdout);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int n,q,k;cin>>n>>q>>k;
	memset(d,0x3f,sizeof d);
	for(int i=1;i<=n;++i)cin>>v[i];
	for(int i=1;i<=n;++i)d[i][i]=0;
	for(int i=2;i<=n;++i){
		int x,y;cin>>x>>y;
		d[x][y]=d[y][x]=1;
	}
	for(int k=1;k<=n;++k)
		for(int i=1;i<=n;++i)if(i!=k)
			for(int j=1;j<=n;++j)if(i!=j&&j!=k)
				d[i][j]=min(d[i][j],d[i][k]+d[k][j]);
	while(q--){
		int x,y;cin>>x>>y;
		ans=1e18;vis[x]=vis[y]=1;
		dfs(n,x,y,k,v[x]+v[y]);
		vis[x]=vis[y]=0;
		cout<<ans<<'\n';
	}
	return 0;
}
