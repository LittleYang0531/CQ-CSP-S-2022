#include<bits/stdc++.h>
using namespace std;
long long n,q,k,a[200005];
long long f[200005][20],fa[200005][20],d[200005];
vector<int>g[200005];
void dfs(long long x,long long y){
	d[x]=d[y]+1;
	fa[x][0]=y;
	f[x][0]=a[x];
	for(long long i=1;i<=18;i++){
		fa[x][i]=fa[fa[x][i-1]][i-1];
		f[x][i]=f[fa[x][i-1]][i-1]+f[x][i-1];
	}
	for(long long i=0;i<g[x].size();i++){
		if(g[x][i]!=y){
			dfs(g[x][i],x);
		}
	}
}
int main(){
	freopen("transmit.in","r",stdin);
	freopen("transmit.out","w",stdout);
	scanf("%lld%lld%lld",&n,&q,&k);
	for(long long i=1;i<=n;i++)scanf("%lld",&a[i]);
	for(long long i=1,u,v;i<n;i++){
		scanf("%lld%lld",&u,&v);
		g[u].push_back(v);
		g[v].push_back(u);
	}
	dfs(1,0);
	for(long long j=1,x,y;j<=q;j++){
		scanf("%lld%lld",&x,&y);
		long long sum=0;
		if(d[x]<d[y])swap(x,y);
		for(long long i=18;i>=0;i--)if(d[fa[x][i]]>=d[y]){
			sum+=f[x][i];
			x=fa[x][i];
		}
		for(long long i=18;i>=0;i--)if(fa[x][i]!=fa[y][i]){
			sum+=f[x][i]+f[y][i];
			x=fa[x][i];
			y=fa[y][i];
		}
		if(x!=y){
			sum+=f[x][0]+f[y][0];
			x=fa[x][0];
			y=fa[y][0];
		}
		printf("%lld\n",sum+a[x]);
	}
	return 0;
}

