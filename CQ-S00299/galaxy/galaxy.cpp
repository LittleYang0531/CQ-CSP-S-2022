#include<bits/stdc++.h>
using namespace std;
inline int read(){
	int sss=0,www=1;
	char chh=getchar();
	while(chh<'0'||chh>'9'){
		if(chh=='-') www=-1;
		chh=getchar();
	}
	while(chh>='0'&&chh<='9'){
		sss=sss*10+chh-'0';
		chh=getchar();
	}
	return sss*www;
}
int n,m,q;
int head[1005],to[100005],nxt[100005],tot=1;
int edge[500005][2]; bool used[500005];
int dfn[1005],low[1005],cnt=0;
int sta[1005],top=0; bool insta[1005];
int siz[1005];
bool inhuan[1005],vis[1005];
int deg[1005];
vector<int> e[1005];
void add(int u,int v){
	to[++tot]=v;
	nxt[tot]=head[u];
	head[u]=tot;
}
void Tarjan(int now){
	dfn[now]=low[now]=++cnt;
	sta[++top]=now; insta[now]=true;
	for(register int i=head[now];i;i=nxt[i]){
		int u=to[i];
		if(!dfn[u]){
			Tarjan(u);
			low[now]=min(low[now],low[u]);
		}
		else if(insta[u]) low[now]=min(low[now],dfn[u]);
	}
	if(dfn[now]==low[now]){
		while(sta[top]!=now){
			insta[sta[top]]=false;
			inhuan[sta[top--]]=true;	
		}
		top--; inhuan[now]=true; insta[now]=false;
	}
}
void bfs(int st){
	queue<int> q; q.push(st);
	while(!q.empty()){
		int x=q.front(); q.pop();
		for(auto u:e[x]){
			if(!vis[u]){
				vis[u]=true;
				q.push(u);
			}
		}
	}
}
bool check(){
	memset(head,-1,sizeof head); tot=1;
	memset(dfn,0,sizeof dfn);
	memset(low,0,sizeof low); cnt=0; top=0;
	memset(insta,false,sizeof insta);
	memset(deg,0,sizeof deg);
	memset(inhuan,false,sizeof inhuan);
	memset(vis,false,sizeof vis);
	for(register int i=1;i<=n;i++) e[i].clear();
	for(register int i=1;i<=m;i++){
		if(used[i]){
			add(edge[i][0],edge[i][1]);
			e[edge[i][1]].push_back(edge[i][0]);
			deg[edge[i][0]]++;
		}
	}
	for(register int i=1;i<=n;i++) if(deg[i]!=1) return false;
	for(register int i=1;i<=n;i++){
		if(!dfn[i]) Tarjan(i);
	}
	for(register int i=1;i<=n;i++){
		if(inhuan[i]&&!vis[i]){
			vis[i]=true;
			bfs(i);
		}
	}
	for(register int i=1;i<=n;i++) if(!vis[i]) return false;
	return true;
}
int main(){
	//动态维护基环森林 
	freopen("galaxy.in","r",stdin);
	freopen("galaxy.out","w",stdout);
	n=read(),m=read();
	for(register int i=1;i<=m;i++){
		edge[i][0]=read(),edge[i][1]=read();
		used[i]=true;
	}
	q=read();
	while(q--){
		int opt=read();
		if(opt==1){
			int u=read(),v=read();
			for(register int i=1;i<=m;i++){
				if(edge[i][0]==u&&edge[i][1]==v) used[i]=false;
			}
		}
		else if(opt==2){
			int u=read();
			for(register int i=1;i<=m;i++){
				if(edge[i][1]==u) used[i]=false;
			}
		}
		else if(opt==3){
			int u=read(),v=read();
			for(register int i=1;i<=m;i++){
				if(edge[i][0]==u&&edge[i][1]==v) used[i]=true;
			}
		}
		else {
			int u=read();
			for(register int i=1;i<=m;i++){
				if(edge[i][1]==u) used[i]=true;
			}
		}
		if(check()) puts("YES");
		else puts("NO");
	}
	return 0;
}
