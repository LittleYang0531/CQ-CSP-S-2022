#include<bits/stdc++.h>
using namespace std;
const int N = 1e3+13;
const int M = 1e4+14;
int n,m,q;
bool f[N][N];
int h[M],e[M],ne[M],tot=1;
int h1[M],e1[M],ne1[M],tot1=1;
bitset<N>vis;
bool ok;
void add(int u,int v){e[tot]=v,ne[tot]=h[u],h[u]=tot++;}
void add1(int u,int v){f[u][v]=1,e1[tot1]=v,ne1[tot1]=h1[u],h1[u]=tot1++;}
void dfs(int u){
	if(vis[u])return void(ok=1);
	vis[u]=1;
	for(int i=h1[u];i;i=ne1[i])
		if(f[u][e1[i]])dfs(e1[i]);
}
signed main(){
	#ifndef SNOWIO
		freopen("galaxy.in","r",stdin);
		freopen("galaxy.out","w",stdout);
	#endif
	scanf("%d%d",&n,&m);
	for(int i=1,u,v;i<=m;i++)
		scanf("%d%d",&u,&v),add(v,u),add1(u,v);
	scanf("%d",&q);
	while(q--){
		int t,u,v;
		scanf("%d%d",&t,&u);
		if(t==1){
			scanf("%d",&v);
			f[u][v]=0;
		}
		if(t==2){
			for(int i=h[u];i;i=ne[i])
				f[e[i]][u]=0;
		}
		if(t==3){
			scanf("%d",&v);
			f[u][v]=1;
		}
		if(t==4){
			for(int i=h[u];i;i=ne[i])
				f[e[i]][u]=1;
		}
		ok=1,vis.reset();
		for(int i=1;i<=n&&ok;i++){
			int sum=0;
			for(int j=h1[i];j&&sum<2;j=ne1[j])
				if(f[i][e1[j]])sum++;
			if(sum>1)ok=0;
		}
		for(int i=1;i<=n&&ok;i++)
			ok=0,dfs(i);
		if(ok)printf("YES\n");
		else printf("NO\n");
	}
	return 0;
}