#include<cstdio>
#include<cmath>
#include<queue>
#include<cstring>
#include<algorithm>
using namespace std;
int n,Q,k,a[2505],cnt,head[20005],Ans,s,t;
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
void dfs(int x,int ans_){
	if(ans_>=Ans) return;
	if(x==t){
		Ans=min(Ans,ans_);
		return;
	}
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
	cnt=0;
	for(int i=1;i<=n;i++) if(vis[i]) b[++cnt]=i;
	for(int i=1;i<=cnt;i++){
		if(!F[b[i]]){
			F[b[i]]=1;
			dfs(b[i],ans_+a[b[i]]);
			F[b[i]]=0; 
		}
	}
}
int main()
{
	freopen("transmit.in","r",stdin);
	freopen("transmit.out","w",stdout);
	scanf("%d%d%d",&n,&Q,&k);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	for(int i=1;i<n;i++){
		int u,v;
		scanf("%d%d",&u,&v);
		add(u,v),add(v,u);
	}
	for(int i=1;i<=Q;i++){
		memset(F,0,sizeof(F));
		scanf("%d%d",&s,&t);
		F[s]=1,Ans=1e9;
		dfs(s,a[s]);
		printf("%d\n",Ans);
	}
	return 0;
}
