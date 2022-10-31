#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=200005;
struct edge {int to,Next;}e[N<<1];
int n,q,k,h[N],cnt,a[N],prt[N],p[N][30],dep[N],c[N],d[N],aa[N];
ll sum[N],f[N];
void Addedge(int x,int y) {e[++cnt]=(edge){y,h[x]},h[x]=cnt;}
void dfs(int x)
{
	dep[x]=dep[prt[x]]+1;
	sum[x]=sum[prt[x]]+a[x];
	for(int i=h[x];i;i=e[i].Next)
	{
		int y=e[i].to;
		if(y==prt[x]) continue;
		prt[y]=x;
		dfs(y);
	}
}
int LCA(int x,int y)
{
	if(dep[x]<dep[y]) swap(x,y);
	int l=log2(dep[x]);
	for(int i=l;i>=0;i--)
		if(dep[x]-dep[y]>=(1<<i)) x=p[x][i];
	if(x==y) return y;
	for(int i=l;i>=0;i--)
		if(p[x][i]!=p[y][i]) x=p[x][i],y=p[y][i];
	return p[x][0];
}
void work1(int x,int y)
{
	c[++c[0]]=a[x];
	if(x==y) return;
	work1(prt[x],y);
}
void work2(int x,int y)
{
	if(x==y) return;
	d[++d[0]]=a[x];
	work2(prt[x],y);
}
int main()
{
	freopen("transmit.in","r",stdin);
	freopen("transmit.out","w",stdout);
	scanf("%d %d %d",&n,&q,&k);
	for(int i=1;i<=n;i++) scanf("%d",a+i);
	for(int i=1,x,y;i<n;i++)
	{
		scanf("%d %d",&x,&y);
		Addedge(x,y);
		Addedge(y,x);
	}
	dfs(1);
	for(int i=1;i<=n;i++) p[i][0]=prt[i];
	for(int j=1;1<<j<=n;j++)
		for(int i=1;i<=n;i++) p[i][j]=p[p[i][j-1]][j-1];
	if(k==1)
	{
		int x,y;
		while(q--)
		{
			scanf("%d %d",&x,&y);
			int lca=LCA(x,y);
			printf("%lld\n",sum[x]+sum[y]-2*sum[lca]+a[lca]);
		}
		return 0;
	}
	else if(n<=10&&q<=10)
	{
		int x,y,lca;
		ll ans=0;
		while(q--)
		{
			ans=1e18;
			scanf("%d %d",&x,&y);
			for(int s=0;s<(1<<n);s++)
			{
				if((s&(1<<x-1))||(s&(1<<y-1))) continue;
				aa[aa[0]=1]=x;
				for(int i=0;i<n;i++)
					if(i+1!=x&&i+1!=y&&(s&(1<<i))) aa[++aa[0]]=i+1;
				aa[++aa[0]]=y;
				sort(aa+2,aa+aa[0]);
				do
				{
					bool ok=1;
					ll res=0;
					for(int i=1;i<aa[0];i++)
					{
						lca=LCA(aa[i],aa[i+1]);
						if(dep[aa[i]]+dep[aa[i+1]]-2*dep[lca]>k) {ok=0; break;}
						res+=a[aa[i]];
					}
					if(ok) ans=min(ans,res+a[aa[aa[0]]]);
				}
				while(next_permutation(aa+2,aa+aa[0]));
			}
			printf("%lld\n",ans);
		}
		return 0;
	}
	int x,y;
	ll ans=0;
	while(q--)
	{
		ans=0;
		scanf("%d %d",&x,&y);
		int lca=LCA(x,y);
		c[0]=d[0]=0;
		work1(x,lca);
		work2(y,lca);
		reverse(d+1,d+1+d[0]);
		for(int i=1;i<=d[0];i++) c[++c[0]]=d[i],f[i]=0;
		f[1]=c[1];
		for(int i=2;i<=c[0];i++)
		{
			f[i]=1e18;
			for(int j=max(1,i-k);j<i;j++) f[i]=min(f[i],f[j]);
			f[i]+=c[i];
		}
		printf("%lld\n",f[c[0]]);
	}
	return 0;
}
