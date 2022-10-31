#include<bits/stdc++.h>
using namespace std;
inline void read(int &x)
{
	int f=1;x=0;
	char c=getchar();
	if(c=='-') f=-1;
	while(c<'0'||c>'9') c=getchar();
	while(c>='0'&&c<='9') x=x*10+c-'0',c=getchar();
	x*=f;
}
inline void print(long long x)
{
	if(x<0) putchar('-'),x=-x;
	char c[100];int tot=0;
	do{c[++tot]=x%10+'0',x/=10;}while(x);
	while(tot) putchar(c[tot--]);
	putchar('\n');
}
typedef long long ll;
const int N=2e5+10;
const ll inf=1e18;
int n,q,k;
int val[N];
vector<int> son[N];
int fa[N][21],dep[N];
int now[N];
ll f[N];
ll sum[N],ans;
void dfs(int u,int f,int dp)
{
	dep[u]=dp;fa[u][0]=f;
	for(int i=1;i<=20;i++)
		fa[u][i]=fa[fa[u][i-1]][i-1];
	for(int i=0;i<son[u].size();i++)
	{
		int v=son[u][i];
		if(v==f) continue;
		dfs(v,u,dp+1);
	}
}
void dfs2(int u,int f,int dp)
{
	sum[u]=sum[f]+val[u];
	dep[u]=dp;fa[u][0]=f;
	for(int i=1;i<=20;i++)
		fa[u][i]=fa[fa[u][i-1]][i-1];
	for(int i=0;i<son[u].size();i++)
	{
		int v=son[u][i];
		if(v==f) continue;
		dfs(v,u,dp+1);
	} 
}
int lca(int x,int y)
{
	if(dep[x]<dep[y]) swap(x,y);
	for(int i=20;i>=0;i--)
		if(dep[fa[x][i]]>=dep[y])
			x=fa[x][i];
	if(x==y) return x;
	for(int i=20;i>=0;i--)
		if(fa[x][i]!=fa[y][i])
		{
			x=fa[x][i];
			y=fa[y][i];
		}
	return fa[x][0];
}
int main()
{
	freopen("transmit.in","r",stdin);
	freopen("transmit.out","w",stdout);
	read(n);read(q);read(k);
	for(int i=1;i<=n;i++) read(val[i]);
	for(int i=1;i<n;i++)
	{
		int u,v;
		read(u);read(v);
		son[u].push_back(v);
		son[v].push_back(u);
	}
	if(k==1)
	{
		dfs2(1,0,1);
		while(q--)
		{
			int s,t;
			read(s);read(t);
			int L=lca(s,t);
			ans=sum[s]-sum[fa[L][0]]+sum[t]-sum[L];
			print(ans);
		}
		return 0;
	}
	dfs(1,0,1);
	while(q--)
	{
		int s,t;
		read(s);read(t);
		int L=lca(s,t);
		int len=dep[s]-dep[L]+dep[t]-dep[L]+1;
		int x=s,y=t,tot1=1,tot2=len;
		while(x!=L)
		{
			now[tot1]=x;
			x=fa[x][0];
			tot1++;
		}
		now[tot1]=L;
		while(y!=L)
		{
			now[tot2]=y;
			y=fa[y][0];
			tot2--;
		}
		f[1]=val[s];
		for(int i=2;i<=len;i++)
		{
			f[i]=inf;
			for(int j=1;j<=k&&i-j>=1;j++)
				f[i]=min(f[i],f[i-j]);
			f[i]+=val[now[i]];
		}
		print(f[len]);
	}
	return 0;
}
