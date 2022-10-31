#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int,int> PII;
int n,m,k,head[2510],vis[2510],dis[2510],cnt;
LL v[2510],ans;
struct node{
	int to,next;
}e[10010*2];
void add(int u,int v){
	e[++cnt].to=v,e[cnt].next=head[u],head[u]=cnt;
}
priority_queue<PII,vector<PII>,greater<PII> > Q;
void dij(int s){
	memset(dis,0x3f,sizeof(dis));
	vis[s]=1,dis[s]=0;
	Q.push(make_pair(dis[s],s));
	while(!Q.empty()){
		int u=Q.top().second;
		Q.pop();
		for(int i=head[u];i;i=e[i].next){
			int v=e[i].to;
			if(vis[v]==1)continue;
			vis[v]=1;
			if(dis[v]>dis[u]+1){
				dis[v]=dis[u]+1;
				Q.push(make_pair(dis[v],v));
			}
		}
	}
}
void dfs(int u,LL score,int len,int point){
	if(point==4){
		if(dis[u]<=k+1){
			ans=max(ans,score);
		}
		return;
	}
	for(int i=head[u];i;i=e[i].next){
		int to=e[i].to;
		if(vis[to]==0&&len<=k&&to!=1)vis[to]=1,dfs(to,score+v[to],0,point+1),vis[to]=0;
		if(len<=k)dfs(to,score,len+1,point);
	}
}
int main(){
	freopen("holiday.in","r",stdin);
	freopen("holiday.out","w",stdout);
	scanf("%d%d%d",&n,&m,&k);
	for(int i=2;i<=n;++i){
		scanf("%lld",&v[i]);
	}
	for(int i=1;i<=m;++i){
		int u,v;
		scanf("%d%d",&u,&v);
		add(u,v),add(v,u);
	}
	dij(1);
	memset(vis,0,sizeof(vis));
	dfs(1,0,0,0);
	printf("%lld\n",ans);
	return 0;
}
