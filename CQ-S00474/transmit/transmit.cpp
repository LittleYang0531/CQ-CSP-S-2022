#include<bits/stdc++.h>
#define N 400005
#define int long long
using namespace std;
struct A{
	int ne,v;
}a[N];
int n,q,w[N],k,cnt,head[N],ans;
bool vis[N];
vector<int> e[N];
void add(int u,int v){
	cnt++;
	a[cnt].v=v;
	a[cnt].ne=head[u];
	head[u]=cnt;
}
void dfs(int x,int fa,int now,int from){
	if(now>k)return ;
	if(x!=from){
		e[from].push_back(x);
	}
	for(int i=head[x];i;i=a[i].ne){
		int v=a[i].v;
		if(v==fa)continue;
		dfs(v,x,now+1,from);
	}
}
void solve(int to,int x,int fa,int len){
	if(x==to){
		ans=min(ans,len);
		return ;
	}
	if(len>=ans)return ;
	for(int i=0;i<(int)e[x].size();i++){
		int v=e[x][i];
		if(vis[v])continue;
		vis[v]=1;
		solve(to,v,x,len+w[v]);
		vis[v]=0;
	}
}
signed main(){
	freopen("transmit.in","r",stdin);
	freopen("transmit.out","w",stdout);
	scanf("%lld%lld%lld",&n,&q,&k);
	for(int i=1;i<=n;i++)scanf("%lld",&w[i]);
	for(int i=1;i<n;i++){
		int x,y;
		scanf("%lld%lld",&x,&y);
		add(x,y);
		add(y,x);
	}
	for(int i=1;i<=n;i++){
		dfs(i,0,0,i);
	}
	for(int i=1;i<=q;i++){
		int x,y;
		scanf("%lld%lld",&x,&y);
		ans=0x3f3f3f3f3f3f3f3f;
		solve(y,x,0,w[x]);
		printf("%lld\n",ans);
	}
	return 0;
}
