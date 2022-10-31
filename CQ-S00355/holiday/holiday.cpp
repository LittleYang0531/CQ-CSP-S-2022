#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> PII;
const int maxx=2505;
int n,m,k,ans,val[maxx];
queue<PII> dis[maxx];
vector<int> a[maxx]; 
bool vis[maxx];
void add(int x,int y){a[x].push_back(y);a[y].push_back(x);}
void dfs(int u,int now,int sum){
	if(now==4){
		ans=max(ans,sum);
		return;
	}
	int si=dis[u].size();
	while(si--){
		PII cos=dis[u].front();
		dis[u].pop();
		if(vis[cos.second])continue;
		vis[cos.second]=1;
		dfs(cos.second,now+1,sum+cos.first);
		dis[u].push(cos);
		vis[cos.second]=0;
	}
}
void dds(int rt,int u,int fa,int pre){
	if(pre==k+1)return;
	int si=a[u].size();
	for(int i=0;i<si;++i){
		int v=a[u][i];
		if(v==fa)continue;
		dis[rt].push({val[v],v});
		dds(rt,v,u,pre+1);
	}
}
int main(){
	freopen("holiday.in","r",stdin);
	freopen("holiday.out","w",stdout);
	scanf("%d%d%d",&n,&m,&k);
	for(int i=2;i<=n;++i)scanf("%d",&val[i]);
	for(int i=1;i<=m;++i){
		int x,y;
		scanf("%d%d",&x,&y);
		add(x,y);
	}
	for(int i=1;i<=n;++i)dds(i,i,i,0);
	dfs(1,0,0);
	printf("%d",ans);
}
