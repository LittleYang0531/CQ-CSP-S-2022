#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=2505,INF=0x3f3f3f3f;
int n,m,K,e[N][N],p[N],q[N];
ll a[N],mx1[N][N],mx2[N][N],mx3[N][N],ans;
int main()
{
	freopen("holiday.in","r",stdin);
	freopen("holiday.out","w",stdout);
	scanf("%d %d %d",&n,&m,&K),K++;
	if(n<=20&&m<=50)
	{
		for(int i=2;i<=n;i++) scanf("%lld",a+i);
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++) e[i][j]=i==j?0:INF;
		for(int i=1,x,y;i<=m;i++)
		{
			scanf("%d %d",&x,&y);
			e[x][y]=e[y][x]=1;
		}
		for(int k=1;k<=n;k++)
			for(int i=1;i<=n;i++)
				for(int j=1;j<=n;j++) e[i][j]=min(e[i][j],e[i][k]+e[k][j]);
		for(int i=2;i<=n;i++)
			for(int j=i+1;j<=n;j++)
				for(int k=j+1;k<=n;k++)
					for(int l=k+1;l<=n;l++)
					{
						if(e[1][i]<=K&&e[i][j]<=K&&e[j][k]<=K&&e[k][l]<=K&&e[l][1]<=K)
							ans=max(ans,a[i]+a[j]+a[k]+a[l]);
					}
		printf("%lld\n",ans);
		return 0;
	}
	for(int i=2;i<=n;i++) scanf("%lld",a+i);
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++) e[i][j]=i==j?0:INF;
	for(int i=1,x,y;i<=m;i++)
	{
		scanf("%d %d",&x,&y);
		e[x][y]=e[y][x]=1;
	}
	for(int k=1;k<=n;k++)
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++) e[i][j]=min(e[i][j],e[i][k]+e[k][j]);
	for(int i=2;i<=n;i++)
		for(int j=i+1;j<=n;j++)
		{
			p[0]=q[0]=0;
			for(int k=2;k<=n;k++)
				if(k!=i&&k!=j&&e[i][k]<=K) p[++p[0]]=k;
			for(int k=1;k<=p[0];k++)
				if(p[k]!=i&&p[k]!=j&&e[j][p[k]]<=K) q[++q[0]]=p[k];
			mx1[i][j]=mx2[i][j]=mx3[i][j]=-1;
			for(int k=1;k<=q[0];k++)
				if(mx1[i][j]==-1||a[mx1[i][j]]<a[q[k]]) mx2[i][j]=mx1[i][j],mx1[i][j]=q[k];
				else if(mx2[i][j]==-1||a[mx2[i][j]]<a[q[k]]) mx3[i][j]=mx2[i][j],mx2[i][j]=q[k];
				else if(mx3[i][j]==-1||a[mx3[i][j]]<a[q[k]]) mx3[i][j]=q[k];
		}
	for(int i=2;i<=n;i++)
		for(int j=i+1;j<=n;j++)
		{
			if(e[1][i]>K||e[1][j]>K) continue;
			for(int k=2;k<=n;k++)
			{
				if(k==i||k==j||e[i][k]>K) continue;
				int x=k,y=j,mx=-1;
				if(x>y) swap(x,y);
				if(mx1[x][y]==i||mx1[x][y]==j)
				{
					if(mx2[x][y]==i||mx2[x][y]==j) mx=mx3[x][y];
					else mx=mx2[x][y];
				}
				else mx=mx1[x][y];
				if(mx!=-1) ans=max(ans,a[i]+a[j]+a[k]+a[mx]);
			}
		}
	printf("%lld\n",ans);
	return 0;
}

