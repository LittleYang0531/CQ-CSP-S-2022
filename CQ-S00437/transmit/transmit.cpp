#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,q,k,d[200005],a[200005],fa[20][200005];
ll s[200005],f[4][200005],g[4][200005];
vector<int>e[200005];
void dfs(int x,int p) {
	d[x]=d[p]+1,s[x]=s[p]+a[x],fa[0][x]=p;
	for(auto y:e[x])if(y!=p)dfs(y,x);
}
int lca(int x,int y) {
	if(d[x]<d[y])swap(x,y);
	for(int i=19;~i;i--)if(d[x]-d[y]>=1<<i)x=fa[i][x];
	if(x==y)return x;
	for(int i=19;~i;i--)if(fa[i][x]&&fa[i][x]!=fa[i][y])x=fa[i][x],y=fa[i][y];
	return fa[0][x];
}
vector<int>find(int x,int z) {
	vector<int>c;
	for(;x!=z;x=fa[0][x])c.push_back(x);
	return c;
}
int main() {
	freopen("transmit.in","r",stdin);
	freopen("transmit.out","w",stdout);
	scanf("%d%d%d",&n,&q,&k);
	for(int i=1;i<=n;i++)scanf("%d",a+i),g[0][i]=a[i],g[1][i]=g[2][i]=1ll<<60;
	for(int i=1,x,y;i<n;i++)scanf("%d%d",&x,&y),e[x].push_back(y),e[y].push_back(x);
	dfs(1,0);
	for(int i=1;1<<i<=n;i++)for(int j=1;j<=n;j++)fa[i][j]=fa[i-1][fa[i-1][j]];
	for(int i=1;i<=n;i++)for(int j=1,x=fa[0][i];x&&j<k;j++,x=fa[0][x])g[j][x]=min(g[j][x],1ll*a[i]),g[j][i]=min(g[j][i],1ll*a[x]);
	while(q--) {
		int x,y;
		scanf("%d%d",&x,&y);
		int z=lca(x,y);
		if(k==1)printf("%lld\n",s[x]+s[y]-s[z]-s[fa[0][z]]);
		else {
			vector<int>p=find(x,z),q=find(y,z);
			reverse(q.begin(),q.end());
			p.push_back(z);for(auto x:q)p.push_back(x);
			for(int i=0;i<p.size();i++)for(int j=0;j<=k;j++)f[j][i]=1ll<<60;
			f[k][0]=a[x];
			for(int i=1;i<p.size();i++) {
				for(int t=1;t<=k;t++) {
					for(int j=1;j<=t&&i-j>=0;j++) 
						for(int l=0;l+j<=t;l++)f[k-l][i]=min(f[k-l][i],f[t][i-j]+g[l][p[i]]);
				}
			}
			printf("%lld\n",f[k][p.size()-1]);
		}
	}
	return 0;
}
