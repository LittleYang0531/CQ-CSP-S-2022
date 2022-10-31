#include<cstdio>
#include<cmath>
#include<queue>
#include<cstring>
#include<algorithm>
using namespace std;
int n,m,k,a[2505],cnt,head[20005],Ans;
struct edge{
	int next,to;
}e[20005];
void add(int u,int v){
	e[++cnt].to=v;
	e[cnt].next=head[u];
	head[u]=cnt;
}
bool vis[2505],F[2505];
int dis[2505];
void dfs(int x,int sum,int ans_){
	memset(vis,0,sizeof(vis));
	int b[2505],cnt;
	queue<int > Q;
	Q.push(x);
	dis[x]=0;
	vis[x]=1;
	while(!Q.empty()){
		int u=Q.front();
		Q.pop();
		if(dis[u]==k+1) continue;
		for(int i=head[u];i;i=e[i].next){
			int v=e[i].to;
			vis[v]=1;
			dis[v]=dis[u]+1;
			Q.push(v);
		}
	}
	if(sum==4){
		if(vis[1]==1){
			Ans=max(Ans,ans_);
		}
		return;
	}
	cnt=0;
	for(int i=1;i<=n;i++) if(vis[i]) b[++cnt]=i;
	for(int i=1;i<=cnt;i++){
		if(!F[b[i]]){
			F[b[i]]=1;
			dfs(b[i],sum+1,ans_+a[b[i]]);
			F[b[i]]=0; 
		}
	}
}
int main()
{
	freopen("holiday.in","r",stdin);
	freopen("holiday.out","w",stdout);
	scanf("%d%d%d",&n,&m,&k);
	for(int i=2;i<=n;i++){
		scanf("%d",&a[i]);
	}
	for(int i=1;i<=m;i++){
		int u,v;
		scanf("%d%d",&u,&v);
		add(u,v),add(v,u);
	}
	F[1]=1;
	dfs(1,0,0);
	printf("%d",Ans);
	return 0;
}
