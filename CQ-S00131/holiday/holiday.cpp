#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=2510;
int n,m,k;
ll w[N],ans;
bool fg[N];
vector<int>G[N];
void dfs(int cnt,int dis,ll val,int u){
//	cout<<u<<' '<<cnt<<' '<<dis<<' '<<val<<endl;
	if(cnt>4) return ;
	for(int i=0;i<(int)G[u].size();i++){
		int v=G[u][i];
		if(cnt==4&&v==1){
//			if(val>ans){
//				for(int i=1;i<=n;i++){
//					if(fg[i]) cout<<i<<" ";
//				}
//				cout<<'\n';
//			}
			ans=max(ans,val);
			return ;
		}
		if(!fg[v]&&v!=1){
			fg[v]=1;
			dfs(cnt+1,0,val+w[v],v);
			fg[v]=0;
		}
		if(dis<k) dfs(cnt,dis+1,val,v);
	}
}
int main(){
	freopen("holiday.in","r",stdin);
	freopen("holiday.out","w",stdout);
	scanf("%d%d%d",&n,&m,&k);
	for(int i=2;i<=n;i++) scanf("%lld",&w[i]);
	for(int i=1;i<=m;i++){
		int a,b;
		scanf("%d%d",&a,&b);
		G[a].push_back(b);
		G[b].push_back(a);
	}
	dfs(0,0,0,1);
	printf("%lld",ans);
	return 0;
}
