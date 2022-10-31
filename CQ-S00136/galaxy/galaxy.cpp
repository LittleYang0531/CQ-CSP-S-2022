#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
int n,m,q,t,cnt,tot,flag,first[N*2],vis[2*N],d[N],sum[N];//边,点,从点出去 
int dfn[N],low[N],st[N],top,num,vs[N],s,cc[2*N],c[N],pos[N*2],ok[N*2],cnt1;
struct Node{
	int u,v,ne;
}e[N*2];
vector<int> b[N];//进入某点 
vector<int> scc[N*2];

void add(int u,int v){
	e[++cnt].v=v;
	e[cnt].u=u;
	e[cnt].ne=first[u];
	first[u]=cnt;
}

void tarjan(int x){
	dfn[x]=low[x]=++num;
	st[++top]=x;vs[x]=1;
	for(int i=first[x];i;i=e[i].ne){
		if(!vis[i]) continue;
		int v=e[i].v;
		if(!dfn[v]){
			tarjan(v);
			low[x]=min(low[x],low[v]);
		}else if(vs[v]) low[x]=min(low[x],dfn[v]);
	}
	if(low[x]==dfn[x]){
		int y;
		s++;
		scc[s].clear();
		cc[s]=0;
		do{
			y=st[top--];
			vs[y]=0;
			cc[s]++;
			c[y]=s;
			scc[s].push_back(y);
		}while(y!=x);
	}
}

void dfs(int x,int id){
	pos[x]=id;
	if(cc[x]>1) ok[id]=1;
	for(int i=first[x];i;i=e[i].ne){
		int v=e[i].v;
		if(pos[v]!=0) continue;
		dfs(v,id);
	}
}

int main(){
	freopen("galaxy.in","r",stdin);
	freopen("galaxy.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) d[i]=1;
	for(int i=1,u,v;i<=m;i++){
		cin>>u>>v;
		add(u,v);
		b[v].push_back(i);
		vis[i]=1;
		sum[u]++;
	}
	cin>>q;
	int u,v;
	while(q--){
		cin>>t;
		if(t==1){
			cin>>u>>v;
			sum[u]--;
			for(int j=first[u];j;j=e[j].ne){
				if(e[j].v==v){
					vis[j]=0;
					break;
				}
			}
		}
		if(t==2){
			cin>>u;
			d[u]=0;
			for(int j=0;j<(int)b[u].size();j++){
				if(vis[b[u][j]]==1){
					vis[b[u][j]]=0;
					sum[e[b[u][j]].u]--;
				}
			}
		}
		if(t==3){
			cin>>u>>v;
			d[v]=1;
			sum[u]++;
			for(int j=first[u];j;j=e[j].ne){
				if(e[j].v==v){
					vis[j]=1;
					break;
				}
			}
		}
		if(t==4){
			cin>>u;
			d[u]=1;
			for(int j=0;j<(int)b[u].size();j++){
				if(!vis[b[u][j]]){
					sum[e[b[u][j]].u]++;
					vis[b[u][j]]=1;
				}
			}
		}
		flag=1;
		for(int i=1;i<=n;i++){
			if(sum[i]!=1||d[i]==0){
				flag=0;
				break;
			}
		}
		if(!flag){
			printf("NO\n");
			continue;
		}
		s=n;top=num=tot=0;
		for(int i=1;i<=n;i++)
			vs[i]=dfn[i]=low[i]=c[i]=0;
		for(int i=1;i<=2*n;i++) pos[i]=0,ok[i]=0;
		for(int i=1;i<=n;i++)
			if(!dfn[i]) tarjan(i);
		cnt1=cnt;
		for(int i=1;i<=cnt;i++)
			if(c[e[i].u]!=c[e[i].v])
				add(c[e[i].u],c[e[i].v]);
		for(int i=n+1;i<=s;i++)
			if(!pos[i]) dfs(i,++tot);
		for(int i=1;i<=tot;i++){
			if(!ok[i]){
				flag=0;
				break;
			}
		}
		if(flag) printf("YES\n");
		else printf("NO\n");
		cnt=cnt1;
	}
	return 0;
}
