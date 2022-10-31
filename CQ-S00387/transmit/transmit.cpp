#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=2e5+5,inf=0x3f3f3f3f;
int n,m,k,x,y,q,head[N],to[2*N],nxt[2*N],e,fa[N],dep[N],X[N],Y[N];
long long A[N],dp[N];
void add_edge(int x,int y)
{
	to[++e]=y;
	nxt[e]=head[x];
	head[x]=e;
}
void dfs(int k,int f)
{
	fa[k]=f;
	dep[k]=dep[f]+1;
	for(int a=head[k];a>0;a=nxt[a])
	{
		int s=to[a];
		if(s==f) continue;
		dfs(s,k);
	}
}
int main()
{
	freopen("transmit.in","r",stdin);
	freopen("transmit.out","w",stdout);
	scanf("%d%d%d",&n,&q,&k);
	for(int a=1;a<=n;a++) scanf("%lld",&A[a]);
	for(int a=1;a<n;a++)
	{
		scanf("%d%d",&x,&y);
		add_edge(x,y);
		add_edge(y,x);
	}
	dfs(1,0);
	while(q--)
	{
		scanf("%d%d",&x,&y);
		int xx=x,yy=y;
		X[0]=Y[0]=0;
		X[++X[0]]=x;
		Y[++Y[0]]=y;
		while(xx!=yy)
		{
			if(dep[xx]<dep[yy])
			{
				yy=fa[yy];
				if(xx!=yy) Y[++Y[0]]=yy;
			}
			else
			{
				xx=fa[xx];
				if(xx!=yy) X[++X[0]]=xx;
			}
		}
		for(int a=Y[0];a>=1;a--) X[++X[0]]=Y[a];
		for(int a=1;a<=X[0];a++) cout<<X[a]<<" ";
		memset(dp,0x3f3f,sizeof(dp));
		dp[1]=A[X[1]];
		for(int a=2;a<=X[0];a++)
		{
			for(int b=1;b<=k&&a-b>=1;b++)
			{
				dp[a]=min(dp[a],dp[a-b]+A[X[a]]);
			}
		}
		printf("%lld\n",dp[X[0]]);
	}
}
