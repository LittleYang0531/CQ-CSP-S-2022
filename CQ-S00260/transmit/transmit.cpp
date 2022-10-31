#include<iostream> 
#include<cstdio>
#include<map>
#include<vector> 
#include<algorithm>
#include<queue>
using namespace std;
int tot,dep[100005],head[1000005],nxt[1000005],ver[100005],val[1000005],n,m,k,f[500005][20],d[1000005],dp[100005];
void add(int u,int v){
	nxt[++tot]=head[u],ver[head[u]=tot]=v;
	return ;
}
void bfs(){
	queue<int>q;
	q.push(1);
	dep[1]=1;
	while(!q.empty()){
		int u=q.front();
		q.pop();
		for(int i=head[u];i;i=nxt[i]){
			int v=ver[i];
			if(!dep[v]){
				dep[v]=dep[u]+1;
				f[v][0]=u;
				for(int i=1;i<=18;i++)f[v][i]=f[f[v][i-1]][i-1];
				q.push(v);
			}
		}
	}
	return ;
}
int LCA(int x,int y){
	if(dep[x]>dep[y])swap(x,y);
	for(int i=18;i>=0;--i)if(dep[f[y][i]]>dep[x])y=f[y][i];
	if(x==y)return x;
	for(int i=18;i>=0;--i)if(f[y][i]!=f[x][i])x=f[x][i],y=f[y][i];
	return f[x][0];
}
int main(){
	freopen("transmit.in","r",stdin);
	freopen("transmit.out","w",stdout);
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1;i<=n;i++)scanf("%d",&val[i]);
	for(int i=1;i<n;i++){
		int u,v;
		scanf("%d%d",&u,&v);
		add(u,v);
		add(v,u);
	}
	while(m--){
		int u,v;
		scanf("%d%d",&u,&v);
		int s=LCA(u,v);
		int num=0;
		int mx=dep[u]+dep[v]-2*dep[s]+2,sk=dep[u]+dep[v]-2-2*dep[s]+(s==u)+(s==v);
		while(u!=s)d[++num]=u,u=f[u][0];
		while(v!=s)d[mx--]=v,v=f[v][0];
		for(int i=1;i<=sk;i++){
			dp[i]=0x3f3f3f3f;
		}
		dp[1]=0;
		for(int i=2;i<=sk;i++){
			for(int j=i-1;j>=max(1,i-k);--j){
				dp[i]=min(dp[j]+val[d[i]],dp[i]);
			}
		}
		printf("%d\n",dp[sk]);
	}
	return 0;
}
