#include<bits/stdc++.h>
#define N 200005
using namespace std;
int n,q,m,top[N],son[N],hs[N],d[N],fa[3][N],V[N],P[N],s[N];
long long dis[N],f[2][N];
vector<int>v[N];
map<pair<int,int>,long long>M;
void dfs(int u) {
	son[u]=1,fa[1][u]=fa[0][fa[0][u]],fa[2][u]=fa[0][fa[1][u]];
	for(auto i:v[u]) if(i!=fa[0][u]) {
			fa[0][i]=u,d[i]=d[u]+1,dfs(i),son[u]+=son[i];
			if(son[i]>son[hs[u]]) hs[u]=i;
		}
}
void DFS(int u,int p) {
	if(u==fa[0][p]) return;
	DFS(fa[0][u],p),s[++s[0]]=u;
}
void Dfs(int u) {
	top[u]=hs[fa[0][u]]==u?top[fa[0][u]]:u,dis[u]+=V[u];
	for(auto i:v[u]) if(i!=fa[0][u]) dis[i]=dis[u],Dfs(i);
}
inline int lca(int x,int y) {
	while(top[x]!=top[y]) {
		if(d[top[x]]<d[top[y]]) swap(x,y);
		x=fa[0][top[x]];
	}
	return d[x]<d[y]?x:y;
}
inline int read() {
	int x=0;
	char ch=getchar();
	while(ch<'0'||ch>'9') ch=getchar();
	while(ch>='0'&&ch<='9') x=x*10+(ch^48),ch=getchar();
	return x;
}
inline void print(long long x) {
	if(x>9) print(x/10);
	putchar(x%10^48);
}
int main() {
	freopen("transmit.in","r",stdin);
	freopen("transmit.out","w",stdout);
	n=read(),q=read(),m=read(),memset(P,0x3f,sizeof(P)),f[1][1]=1e18;
	for(int i=1; i<=n; i++) V[i]=read();
	for(int x,y,i=1; i<n; i++) {
		x=read(),y=read(),v[x].push_back(y),v[y].push_back(x);
	}
	for(int i=1; i<=n; i++) for(auto j:v[i]) P[i]=min(P[i],V[j]);
	dfs(1),Dfs(1);
	for(int x,y,LCA,i=1; i<=q; i++) {
		LCA=lca(x=read(),y=read());
		if(x>y) swap(x,y);
		if(!M[make_pair(x,y)]) {
			if(m==1) M[make_pair(x,y)]=dis[x]+dis[y]-2*dis[LCA]+V[LCA];
			else {
				s[0]=0;
				for(int j=x; j!=LCA; j=fa[0][j]) s[++s[0]]=j;
				DFS(y,LCA),f[0][1]=V[s[1]];
				for(int j=2; j<=s[0]; j++) {
					f[0][j]=f[1][j]=1e18;
					for(int k=1; k<=m&&k<j; k++) {
						f[0][j]=min(f[0][j],f[0][j-k]);
						if(k<m) {
							f[0][j]=min(f[0][j],f[1][j-k]);
							f[1][j]=min(f[1][j],f[0][j-k]);
						}
						if(k<m-1) f[1][j]=min(f[1][j],f[1][j-k]);
					}
					f[0][j]+=V[s[j]],f[1][j]+=P[s[j]];
				}
				M[make_pair(x,y)]=f[0][s[0]];
			}
		}
		print(M[make_pair(x,y)]),putchar('\n');
	}
	return 0;
}
