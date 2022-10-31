#include<bits/stdc++.h>
using namespace std;
int n,m,q;
bool e[1003][1003],vis[1003];
vector<int>edge[1003];
bool dfs(int id){
	vis[id]=1;
	int cnt=0;
	for(int i=1;i<=n;i++)cnt+=e[id][i];
	if(cnt!=1)return 0;
	for(int i=1;i<=n;i++)if(e[id][i])
	return (vis[i]?1:dfs(i));
}
int main(){
	freopen("galaxy.in","r",stdin);
	freopen("galaxy.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1,u,v;i<=m;i++){
		scanf("%d%d",&u,&v);
		e[u][v]=1;
		edge[v].emplace_back(u);
	}scanf("%d",&q);
	while(q--){
		int opt,u,v;
		scanf("%d",&opt);
		if(opt==1){
			scanf("%d%d",&u,&v);
			e[u][v]=0;
		}
		if(opt==2){
			scanf("%d",&u);
			for(int v:edge[u])e[v][u]=0;
		}
		if(opt==3){
			scanf("%d%d",&u,&v);
			e[u][v]=1;
		}
		if(opt==4){
			scanf("%d",&u);
			for(int v:edge[u])e[v][u]=1;
		}
		memset(vis,0,sizeof(vis));
		for(int i=1;i<=n;i++)if(!vis[i]&&!dfs(i))goto fail;
		puts("YES");continue;
		fail:puts("NO");
	}return 0;
}
