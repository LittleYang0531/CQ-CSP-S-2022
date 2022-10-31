#include<bits/stdc++.h>
#define int long long
using namespace std;
const int maxn=2e5+5;
int n,T,k,val[maxn],p[maxn],f[maxn][25],d[maxn][25],dep[maxn],q,w,top,dp[maxn],ans,cnt,t[maxn],Bf,dn;
struct node{int to,ne;}a[maxn<<1];
void add(int x,int y)
{
	a[++top].to=y;
	a[top].ne=p[x];
	p[x]=top;
}
void dfs(int x,int dad)
{
	dep[x]=dep[dad]+1;
	for(int i=p[x];i;i=a[i].ne)
	if(a[i].to!=dad)
	{
		f[a[i].to][0]=x;
		d[a[i].to][0]=val[a[i].to];
		dfs(a[i].to,x);
	}
}
void sq()
{
	for(int i=1;i<=20;i++)
	for(int j=1;j<=n;j++)
	{
		f[j][i]=f[f[j][i-1]][i-1];
		d[j][i]=d[j][i-1]+d[f[j][i-1]][i-1];
//		printf("%lld %lld %lld\n",j,i,d[j][i]);
	}
}
int LCA(int x,int y)
{
	if(dep[x]<dep[y])swap(x,y);
	for(int i=20;~i;i--)if(dep[f[x][i]]>=dep[y])ans+=d[x][i],x=f[x][i];
	for(int i=20;~i;i--)if(f[x][i]!=f[y][i])ans+=d[x][i]+d[y][i],x=f[x][i],y=f[y][i];
	ans+=val[x];
	if(x!=y)ans+=val[y]+val[f[x][0]];
	return x==y?x:f[x][0];
}
void doge(int x,int y)
{
	cnt=0;
	while(x!=Bf)t[++cnt]=x,x=f[x][0];
	t[++cnt]=x;
	cnt+=dep[y]-dep[Bf];dn=cnt;
	while(y!=Bf)t[cnt--]=y,y=f[y][0];
	dp[1]=val[t[1]];
	for(int i=2;i<=dn;i++)
	{
		dp[i]=1e16;
		for(int j=max(i-k,1ll);j<i;j++)dp[i]=min(dp[i],dp[j]+val[t[i]]);
	}
	ans=dp[dn];
}
signed main()
{
	freopen("transmit.in","r",stdin);
	freopen("transmit.out","w",stdout);
	scanf("%lld%lld%lld",&n,&T,&k);
	for(int i=1;i<=n;i++)scanf("%lld",&val[i]);
	for(int i=1;i<n;i++)
	{
		scanf("%lld%lld",&q,&w);
		add(q,w);add(w,q);
	}
	dfs(1,0);
	sq();
	while(T--)
	{
		ans=0;
		scanf("%lld%lld",&q,&w);
		Bf=LCA(q,w);
		if(k!=1)doge(q,w);
		printf("%lld\n",ans);
	}
	return 0;
}