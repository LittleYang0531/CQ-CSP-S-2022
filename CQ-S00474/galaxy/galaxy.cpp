#include<bits/stdc++.h>
#define N 500005
#define reg register
using namespace std;
struct A{
	int ne,v;
}a[N];
int n,m,q,cnt,head[N],dfn[N],low[N],tot,c[N];
int st[N],top,Siz,siz[N];
bool vis[N],ok[N];
vector<int> e[N];
map<pair<int,int>,int> h;
inline void add(int u,int v){
	cnt++;
	a[cnt].v=v;
	a[cnt].ne=head[u];
	head[u]=cnt;
}
inline void tarjan(int x){
	st[++top]=x;
	dfn[x]=low[x]=++tot;
	vis[x]=1;
	for(reg int i=head[x];i;i=a[i].ne){
		int v=a[i].v;
		if(!h[make_pair(x,v)])continue;
		if(!dfn[v]){
			tarjan(v);
			low[x]=min(low[x],low[v]);
		}else if(vis[v]){
			low[x]=min(low[x],dfn[v]);
		}
	}
	if(dfn[x]==low[x]){
		Siz++;
		int y=-1;
		while(x!=y){
			siz[Siz]++;
			y=st[top--];
			c[y]=Siz;
			vis[y]=0;
		}
	}
}
inline bool dfs(int x,int fa){
	if(ok[x]||siz[c[x]]>1){
		ok[x]=1;
		return 1;
	}
	bool fg=0;
	for(reg int i=head[x];i;i=a[i].ne){
		int v=a[i].v;
		if(v==fa||!h[make_pair(x,v)])continue;
		if(dfs(v,x)){
			ok[x]=1;
			fg=1;
			break;
		}
	}
	return fg;
}
int main(){
	freopen("galaxy.in","r",stdin);
	freopen("galaxy.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(reg int i=1;i<=m;i++){
		int x,y;
		scanf("%d%d",&x,&y);
		add(x,y);
		e[y].push_back(x);
		h[make_pair(x,y)]++;
	}
	scanf("%d",&q);
	for(reg int P=1;P<=q;P++){
		int op,x,y;
		scanf("%d",&op);
		if(op==1){
			scanf("%d%d",&x,&y);
			h[make_pair(x,y)]--;
		}else if(op==2){
			scanf("%d",&x);
			for(reg int i=0;i<(int)e[x].size();i++){
				int from=e[x][i];
				h[make_pair(from,x)]=0;
			}
		}else if(op==3){
			scanf("%d%d",&x,&y);
			h[make_pair(x,y)]++;
		}else{
			scanf("%d",&x);
			for(reg int i=0;i<(int)e[x].size();i++){
				int from=e[x][i];
				h[make_pair(from,x)]=0;
			}
			for(reg int i=0;i<(int)e[x].size();i++){
				int from=e[x][i];
				h[make_pair(from,x)]++;
			}
		}
		for(reg int i=1;i<=n;i++){
			c[i]=dfn[i]=low[i]=vis[i]=siz[i]=ok[i]=0;
		}
		tot=top=Siz=0;
		for(reg int i=1;i<=n;i++){
			if(!dfn[i])tarjan(i);
		}
		int ans=1;
		for(reg int x=1;x<=n;x++){
			if(!dfs(x,0)){
				ans=0;
				break;
			}
			int fg=1,num=0;
			for(reg int i=head[x];i;i=a[i].ne){
				int v=a[i].v;
				num+=h[make_pair(x,v)];
				if(num>1){
					fg=0;
					break;
				}
			}
			if(!fg){
				ans=0;
				break;
			}
		}
		if(ans)printf("YES\n");
		else printf("NO\n");
	}
	return 0;
}
