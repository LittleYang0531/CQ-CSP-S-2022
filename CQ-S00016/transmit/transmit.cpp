#include<bits/stdc++.h>
using namespace std; 
const int N=205,M=200005;
inline int read(){int f=0;char c=getchar();while(!isdigit(c))c=getchar();while(isdigit(c))f=(f<<3)+(f<<1)+c-'0',c=getchar();return f;}
void write(int x){if(x>=10)write(x/10);putchar(x%10+'0');return;}
int n,q,k,f[N][N],fa[M][22],dep[M];
vector<int>G[M];
long long a[M],g[N][N],pre[M];
void dfs(int p,int lst) {
	fa[p][0]=lst,dep[p]=dep[lst]+1,pre[p]=pre[lst]+a[p];
	for (int i=1;i<=21;i++) fa[p][i]=fa[fa[p][i-1]][i-1];
	int siz=G[p].size();
	for (int i=0;i<siz;i++) {
		int x=G[p][i];
		if (x!=lst) dfs(x,p);
	}
}
inline int lca(int x,int y) {
	if (dep[x]<dep[y]) swap(x,y);
	for (int i=21;i>=0;i--) {
		if (dep[fa[x][i]]>=dep[y]) x=fa[x][i];
	}
	if (x==y) return x;
	for (int i=21;i>=0;i--) {
		if (fa[x][i]!=fa[y][i]) x=fa[x][i],y=fa[y][i];
	}
	return fa[x][0];
}
int main() {
	freopen("transmit.in","r",stdin);
	freopen("transmit.out","w",stdout);
	scanf("%d %d %d",&n,&q,&k);
	memset(f,63,sizeof f);
	memset(g,63,sizeof g);
	for (int i=1;i<=n;i++) scanf("%lld",&a[i]),f[i][i]=0;
	for (int i=1;i<n;i++) {
		int x,y;
		scanf("%d %d",&x,&y);
		f[x][y]=f[y][x]=1;
		G[x].push_back(y),G[y].push_back(x);
	}
	dfs(1,0);
	if (n<=200) {
		for (int i=1;i<=n;i++) {
			for (int j=1;j<=n;j++) {
				for (int k=1;k<=n;k++) {
					f[j][k]=min(f[j][k],f[j][i]+f[i][k]);
				}
			}
		}
		for (int i=1;i<=n;i++) {
			for (int j=1;j<=n;j++) {
				if (f[i][j]<=k) g[i][j]=a[i]+a[j];
			}
		}
		for (int i=1;i<=n;i++) {
			for (int j=1;j<=n;j++) {
				for (int k=1;k<=n;k++) {
					g[j][k]=min(g[j][k],g[j][i]+g[i][k]-a[i]);
				}
			}
		}
		for (int i=1;i<=q;i++) {
			int x,y;
			scanf("%d %d",&x,&y);
			printf("%lld\n",g[x][y]);
		}	
	} else {
		for (int i=1;i<=q;i++) {
			int x,y;
			scanf("%d %d",&x,&y);
			int res=lca(x,y);
			printf("%lld\n",pre[x]+pre[y]-2*pre[res]+a[res]);	
		}
	}
	return 0;
}
