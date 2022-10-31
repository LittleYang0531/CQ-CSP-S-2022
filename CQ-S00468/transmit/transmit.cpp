#include<bits/stdc++.h>
using namespace std;
const int M=2e5+10;
struct G{
	int u,v;
}e[M];
int head[M],cnt;
void add(int u,int v){
	e[++cnt].v=v;
	e[cnt].u=head[u];
	head[u]=cnt;
}
int n,q,k;
int v[M];
int f[M][25],dep[M];
void dfs(int x,int fa){
	dep[x]=dep[fa]+1;
	f[x][0]=fa;
	for(int i=1;i<=20;i++)f[x][i]=f[f[x][i-1]][i-1];
	for(int p=head[x];p;p=e[p].u ){
		int v=e[p].v;
		if(v==fa)continue;
		dfs(v,x);
	}
}
int LCA(int x,int y){
	if(dep[x]<dep[y])swap(x,y);
	for(int i=20;i>=0;i--){
		if(dep[f[x][i]]>=dep[y])x=f[x][i];
		if(x==y)return x;
	}
	for(int i=20;i>=0;i--){
		if(f[x][i]!=f[y][i]){
			x=f[x][i];
			y=f[y][i];
		}
	}
	return f[x][0];
}
int main(){
	freopen("transmit.in","r",stdin);
	freopen("transmit.out","w",stdout);
	scanf("%d%d%d",&n,&q,&k);
	for(int i=1;i<=n;i++)scanf("%d",&v[i]);
	for(int i=1;i<n;i++){
		int x,y;
		scanf("%d%d",&x,&y);
		add(x,y);
		add(y,x);
	}
	dfs(1,0);
	
	while(q--){
		int s,t;
		scanf("%d%d",&s,&t);
		printf("%d\n",v[s]+v[t]-v[LCA(s,t)]+2);
	}
} 
