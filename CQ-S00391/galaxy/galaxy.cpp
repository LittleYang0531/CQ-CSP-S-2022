#include<bits/stdc++.h>
using namespace std;
const int MAXN=500005;
int n,m,q,u,v,opt,a[MAXN],cnt;
bool vis[MAXN],flg,O;
vector<int>g[MAXN],hs[MAXN];
stack<int>S;
void dfs(int u){
	if(flg)return;
	if(vis[u]){
		flg=1;
		return;
	}
	vis[u]=1;
	for(int i=0;i<g[u].size();++i){
		int v=g[u][i];
		dfs(v);
	}
	vis[u]=0;
}
int main(){
	freopen("galaxy.in","r",stdin);
	freopen("galaxy.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;++i){
		scanf("%d%d",&u,&v);
		g[u].push_back(v);
		hs[u].push_back(v);
	}
	scanf("%d",&q);
	while(q--){
		scanf("%d%d",&opt,&u);
	
		if(opt==1){
			scanf("%d",&v);
			cnt=0;
			for(int i=0;i<g[u].size();++i){
				if(g[u][i]!=v)a[++cnt]=g[u][i];
			}g[u].clear();
			for(int i=1;i<=cnt;++i)g[u].push_back(a[i]);
		}
		else if(opt==2)g[u].clear();
		else if(opt==3){
			scanf("%d",&v);g[u].push_back(v);
		}
		else if(opt==4){
			g[u].clear();
			for(int i=0;i<hs[u].size();++i)g[u].push_back(hs[u][i]);
		}	
		O=1;
//		print();
		for(int i=1;i<=n;++i){
			for(int j=1;j<=n;++j)vis[j]=0;
			flg=0;
			dfs(i);
			O&=flg;
			O&=(g[i].size()==1); 
		}
		if(!O)puts("NO");
		else puts("YES");
	}
	return 0;
}
