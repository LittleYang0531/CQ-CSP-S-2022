#include<cstdio>
#include<set>
#include<vector> 
using namespace std;
int n,m,q;
int cut,Head[500005],Next[500005],w[500005];
bool ff[500005];
void AddEdge(int u,int v){
	Next[++cut]=Head[u],Head[u]=cut,w[cut]=v,ff[cut]=0;
}
void Del(int u,int v){
	for(int i=Head[u];i;i=Next[i]){
		if(w[i]==v){
			ff[i]=1;
			return ;
		}
	}
}
void Add(int u,int v){
	for(int i=Head[u];i;i=Next[i]){
		if(w[i]==v&&ff[i]){
			ff[i]=0;
			return ;
		}
	}
}
void Del(int u){
	for(int i=Head[u];i;i=Next[i]) ff[i]=1;
}
void Add(int u){
	for(int i=Head[u];i;i=Next[i]) ff[i]=0;
}
bool f[500005];
vector<int> v[500005];
bool dfs(int t){
	f[t]=1;
	for(auto x:v[t])
		if(f[x]||dfs(x)){
//			f[t]=0;
			return 1;
		} 
//	f[t]=0;
	return 0;
}
bool fg(){
	for(int i=1;i<=n;i++) f[i]=0,v[i].clear();
	for(int i=1;i<=n;i++)
		for(int x=Head[i];x;x=Next[x]) if(ff[x]) v[w[x]].push_back(i);
	for(int i=1;i<+n;i++)
		if(v[i].size()!=1) return 0;
	for(int i=1;i<=n;i++) if((!f[i])&&(!dfs(i))) return 0;
	return 1;
}
int main(){
	freopen("galaxy.in","r",stdin);
	freopen("galaxy.out","w",stdout);
	scanf("%d %d",&n,&m);
	for(int i=1,u,v;i<=m;i++)
		scanf("%d %d",&u,&v),AddEdge(v,u);
	scanf("%d",&q);
	int t,u,v;
	while(q--){
//		for(int i=1;i<=n;i++)
//		for(int x=Head[i];x;x=Next[x]) printf("%d %d\n",i,w[x]);
		scanf("%d %d",&t,&u);
		if(t&1) scanf("%d",&v);
		if(t==1) Del(v,u);
		else if(t==2) Del(u);
		else if(t==3) Add(v,u);
		else if(t==4) Add(u);
//		printf("%d %d\n",fg(),lxcs());
		puts(fg()?"YES":"NO");
	}
	return 0;
} 
/*
*/

