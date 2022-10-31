#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int read() {
	int x=0,f=1;
	char c=getchar();
	while(c<'0'||c>'9') {
		if(c=='-')f=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9')x=x*10+c-'0',c=getchar();
	return x*f;
}
namespace tokidosaya {
	const int maxn=2e5+5;
	struct edge {
		int next,to;
	} e[maxn*2];
	int h[maxn],cnt,n,m,k,f[maxn][19],lg2[maxn],d[maxn],mxd,mn[maxn],a[maxn],zc[maxn],zcnt;
	ll s[maxn],g[maxn];
	void addedge(int x,int y) {
		e[++cnt].next=h[x],e[cnt].to=y,h[x]=cnt;
	}
	void dfs(int u,int fa) {
		d[u]=d[fa]+1,f[u][0]=fa,s[u]=s[fa]+a[u],mn[u]=fa?a[fa]:1e9;
		for(int i=1; i<=lg2[d[u]]; i++)f[u][i]=f[f[u][i-1]][i-1];
		for(int i=h[u]; i; i=e[i].next) {
			int v=e[i].to;
			if(v==fa)continue;
			dfs(v,u),mn[u]=min(mn[u],a[v]);
		}
	}
	int lca(int x,int y) {
		if(d[x]<d[y])swap(x,y);
		while(d[x]>d[y])x=f[x][lg2[d[x]-d[y]]-1];
		if(x==y)return x;
		for(int i=lg2[d[x]]-1; ~i; i--)
			if(f[x][i]!=f[y][i])x=f[x][i],y=f[y][i];
		return f[x][0];
	}
	int main() {
		freopen("transmit.in","r",stdin);
		freopen("transmit.out","w",stdout);
		int x,y;
		n=read(),m=read(),k=read();
		for(int i=1; i<=n; i++)a[i]=read(),lg2[i]=lg2[i-1]+((1<<lg2[i-1])==i);
		for(int i=1; i<n; i++) {
			x=read(),y=read();
			addedge(x,y),addedge(y,x);
		}
		dfs(1,0);
		while(m--) {
			x=read(),y=read();
			int lc=lca(x,y);
			if(k==1) {
				printf("%lld\n",s[x]+s[y]-s[f[lc][0]]-s[lc]);
				continue;
			}
			zcnt=0;
			while(x!=lc)zc[zcnt++]=x,x=f[x][0];
			zc[zcnt++]=lc;
			vector<int> v;
			while(y!=lc)v.push_back(y),y=f[y][0];
			reverse(v.begin(),v.end());
			for(int i=0; i<v.size(); i++)zc[zcnt++]=v[i];
			v.clear(),v.shrink_to_fit();
			g[0]=a[zc[0]];
			for(int i=1; i<zcnt; i++) {
				g[i]=g[i-1];
				if(i>=2)g[i]=min(g[i],g[i-2]);
				if(k==3&&i>=3)g[i]=min(g[i],g[i-3]),g[i-2]=min(g[i-2],g[i-3]+mn[zc[i-1]]);
//				if(k==3) {
//					if(i>=3)g[i]=min(g[i],g[i-3]);
//					if(i>=4)g[i]=min(g[i],g[i-4]+mn[zc[i-2]]);
//				}
				g[i]+=a[zc[i]];
			}
			printf("%lld\n",g[zcnt-1]);
		}
		return 0;
	}
}
int main() {
	return tokidosaya::main();
}
/*
6 1 1
1 1 4 5 1 4
1 2
2 3
2 4
4 5
3 6
5 6
*/
