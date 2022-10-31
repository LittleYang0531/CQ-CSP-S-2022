#include<bits/stdc++.h>
#define pii pair<int,int>
#define val first
#define id second
using namespace std;
const int N = 2e3+23,M = N * N;
const int inf = 1e9+7;
int n,q,k;
int v[N],f[N][N];
int h[M],e[M],ne[M],tot=1;
int h1[M],e1[M],ne1[M],tot1=1;
void add(int u,int v){e[tot]=v,ne[tot]=h[u],h[u]=tot++;}
void add1(int u,int v){e1[tot1]=v,ne1[tot1]=h1[u],h1[u]=tot1++;}
bitset<N>vis;
void dfs(int u,int root){
	vis[u]=1;
	for(int i=h1[u];i;i=ne1[i])
		if(!vis[e1[i]])add(root,e1[i]),dfs(e1[i],root);
}
void Dij(int root){
	priority_queue<pii,vector<pii>,greater<pii> >que;
	vis.reset();
	que.push({v[root],root});
	vis[root]=1;
	while(!que.empty()){
		pii t=que.top();que.pop();
		for(int i=h[t.id];i;i=ne[i])
			if(!vis[e[i]])
				f[root][e[i]]=t.val+v[e[i]],
				vis[e[i]]=1,
				que.push({f[root][e[i]],e[i]});
	}
}
signed main(){
	#ifndef SNOWIO
		freopen("transmit.in","r",stdin);
		freopen("transmit.out","w",stdout);
	#endif
	scanf("%d%d%d",&n,&q,&k);
	for(int i=1;i<=n;i++)
		scanf("%d",v+i),f[i][i]=v[i];
	for(int i=1,u,v;i<n;i++)
		scanf("%d%d",&u,&v),add1(u,v),add1(v,u);
	for(int i=1;i<=n;i++)
		vis.reset(),dfs(i,i);
	for(int i=1;i<=n;i++)
		Dij(i);
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			cout<<f[i][j]<<" \n"[j==n];
	while(q--){
		int u,v;
		scanf("%d%d",&u,&v);
		printf("%d\n",f[u][v]);
	}
	return 0;
}