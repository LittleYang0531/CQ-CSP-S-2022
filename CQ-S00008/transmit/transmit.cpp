#include<bits/stdc++.h>
using namespace std;
inline int read(){
	register int x=0,f=1;
	char ch=getchar();
	while(ch>'9'||ch<'0'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9')x=(x<<1)+(x<<3)+(ch^48),ch=getchar();
	return x*f;
}
int n,k,q,x,y;
long long ans;
bool vis[201];
int dis[201][201],v[201];
void dfs(int u,long long cnt){
	if(cnt>=ans)return;
	if(u==y){
		ans=min(ans,cnt);
		return;
	}
	for(int i=1;i<=n;i++)
		if(!vis[i]&&dis[u][i]<=k)
			vis[i]=1,dfs(i,cnt+v[i]),vis[i]=0;
	return;
}
int main(){
	freopen("transmit.in","r",stdin);
	freopen("transmit.out","w",stdout);
	n=read(),q=read(),k=read();
	for(int i=1;i<=n;i++)v[i]=read();
	memset(dis,63,sizeof(dis));
	for(int i=1,u,v;i<n;i++){
		u=read(),v=read();
		dis[u][v]=dis[v][u]=1;
	}
	for(int p=1;p<=n;p++){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++)
				dis[i][j]=min(dis[i][j],dis[i][p]+dis[p][j]);
		}
	}
	while(q--){
		x=read(),y=read();
		ans=1e18;
		int p=k;
		k=1;
		vis[x]=1;
		dfs(x,v[x]);
		vis[x]=0;
		k=p;
		vis[x]=1;
		dfs(x,v[x]);
		vis[x]=0;
		printf("%lld\n",ans);
	}
	return 0;
}

