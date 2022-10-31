#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=2505;
int n,m,k,L,R,stk[N],vis[N],dis[N];
vector<int>E[N],G[N];
ll s[N],ans;pair<ll,int>p[N][N];
void bfs(int s){
	for(stk[L=R=1]=s;L<=R;){
		int x=stk[L++];
		if(dis[x]==k)break;
		for(auto y:E[x])
		if(vis[y]^s){
			G[s].push_back(stk[++R]=y);
			dis[y]=dis[x]+1;vis[y]=s;
		}
	}
}
int main(){
	freopen("holiday.in","r",stdin);
	freopen("holiday.out","w",stdout);
	scanf("%d%d%d",&n,&m,&k);
	for(int i=2;i<=n;i++)
	scanf("%lld",s+i);
	for(int i=1;i<=m;i++){
		int x,y;
		scanf("%d%d",&x,&y);
		E[x].push_back(y);
		E[y].push_back(x);
	}
	for(int i=1;i<=n;i++)
	vis[i]=i,dis[i]=-1,bfs(i);
	for(auto a:G[1])
	for(auto b:G[a])
	if(b!=1)p[b][a]=make_pair(s[a]+s[b],a);
	for(int i=2;i<=n;i++)
	sort(p[i]+1,p[i]+1+n);
	for(int a=2;a<=n;a++)
	for(auto b:G[a])if(b!=1){
		for(int ta=n-2;ta<=n;ta++)
		for(int tb=n-2;tb<=n;tb++){
			int ka=p[a][ta].second,kb=p[b][tb].second;
			if(ka==b||kb==a||ka==kb)continue;
			if(!p[a][ta].first||!p[b][tb].first)continue;
			ans=max(ans,p[a][ta].first+p[b][tb].first);
		}
	}
	return printf("%lld\n",ans),0;
}
