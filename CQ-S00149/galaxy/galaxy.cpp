#include<bits/stdc++.h>
using namespace std;
int n,m,q;
struct node{
	int next,to;
}e[1000001];
int h[500001],cnt,vis[1001][1001],mp[1001][1001],cd[500001],sumcd1;//出度为1的点的个数 
void Addedge(int x,int y){
	e[++cnt].next=h[x];
	e[cnt].to=y;
	h[x]=cnt;
}
int dfn[500001],low[500001],scc,sign,sum[500001],instack[500001],stk[500001],top;
void Eunuch(int u){
	dfn[u]=low[u]=++sign;
	stk[++top]=u;
	instack[u]=1;
	for(int i=h[u];i;i=e[i].next){
		int v=e[i].to;
		if(!dfn[v]){
			Eunuch(v);
			low[u]=min(low[u],low[v]);
		}
		else if(instack[v])low[u]=min(low[u],dfn[v]);
	}
	if(dfn[u]==low[u]){
		int y;
		++scc;
		flag:
		y=stk[top--];
		++sum[scc];
		instack[y]=0;
		if(y!=u)goto flag;
	}
}
int main(){
	freopen("galaxy.in","r",stdin);
	freopen("galaxy.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;++i){
		int u,v;
		scanf("%d%d",&u,&v);
		Addedge(u,v);
		++cd[u];
		if(cd[u]==1)++sumcd1;
		if(cd[u]==2)--sumcd1;
		vis[u][v]=1;
		mp[u][v]=1;
	}//保证每个强联通分量大小大于等于2，每个点的出度必须是1 
	scanf("%d",&q);
	if(n<=1e3){
		while(q--){
			int op,u,v;
			scanf("%d",&op);
			if(!(op^1)){
				scanf("%d%d",&u,&v);
				vis[u][v]=0;
				--cd[u];
				if(cd[u]==1)++sumcd1;
				if(cd[u]==0)--sumcd1;
			}
			if(!(op^2)){
				scanf("%d",&v);
				for(u=1;u<=n;++u){
					if(vis[u][v]){
						vis[u][v]=0;
						--cd[u];
						if(cd[u]==1)++sumcd1;
						if(cd[u]==0)--sumcd1;
					}
				}
			}
			if(!(op^3)){
				scanf("%d%d",&u,&v);
				vis[u][v]=1;
				++cd[u];
				if(cd[u]==1)++sumcd1;
				if(cd[u]==2)--sumcd1;
			}
			if(!(op^4)){
				scanf("%d",&v);
				for(u=1;u<=n;++u){
					if(!vis[u][v]&&mp[u][v]){
						vis[u][v]=1;
						++cd[u];
						if(cd[u]==1)++sumcd1;
						if(cd[u]==2)--sumcd1;
					}
				}
			}
			if(sumcd1!=n){
				printf("NO\n");
				continue;
			}
			for(int i=1;i<=n;++i){
				dfn[i]=instack[i]=sum[i]=0;
			}
			sign=top=scc=0;
			for(int i=1;i<=n;++i){
				if(!dfn[i])Eunuch(i);
			}
			int flag=1;
			for(int i=1;i<=scc;++i){
				if(sum[i]<=2)flag=0;
			}
			if(flag){
			printf("YES\n");
			}
			else printf("NO\n");
		}
		return 0;
	}
	while(q--)printf("NO\n");
	return 0;
}

