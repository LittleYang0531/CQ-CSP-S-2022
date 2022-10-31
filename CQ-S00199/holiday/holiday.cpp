#include<stdio.h>
const int inf=1000000000;
const long long infll=1000000000000000000;
struct node{
	int v;
	int nextn;
}b[5005];
int bn,lastn[2505];
int n,m,k;
int u,v;
long long a[2505];
int dis[2505][2505];
int que[2505],qb,qe;
long long f[2505][2505];
long long g[2505][2505];
long long h[2505][2505];
long long ans;
inline void in(int u,int v)
{
	++bn;
	b[bn].v=v;
	b[bn].nextn=lastn[u];
	lastn[u]=bn;
}
inline long long max(long long x,long long y)
{
	return x>y?x:y;
}
int main()
{
	freopen("holiday.in","r",stdin);
	freopen("holiday.out","w",stdout);
	scanf("%d%d%d",&n,&m,&k);
	++k;
	for(int i=2;i<=n;i++)
	{
		scanf("%lld",&a[i]);
	}
	for(int i=1;i<=m;i++)
	{
		scanf("%d%d",&u,&v);
		in(u,v);
		in(v,u);
	}
	for(int i=1;i<=n;i++)
	{
		qb=qe=1;
		que[1]=i;
		for(int j=1;j<=n;j++)
		{
			dis[i][j]=inf;
		}
		dis[i][i]=0;
		while(qe>=qb)
		{
			u=que[qb];
			++qb;
			for(int j=lastn[u];j>0;j=b[j].nextn)
			{
				if(dis[i][b[j].v]>=inf)
				{
					dis[i][b[j].v]=dis[i][u]+1;
					que[++qe]=b[j].v;
				}
			}
		}
	}
	ans=-infll;
	if(n<=0)
	{
		for(int j=2;j<=n;j++)
		{
			for(int l=2;l<=n;l++)
			{
				if(j==l||dis[j][l]>k||dis[1][j]>k)
				{
					continue;
				}
				for(int o=2;o<=n;o++)
				{
					if(j==o||l==o||dis[l][o]>k)
					{
						continue;
					}
					for(int p=2;p<=n;p++)
					{
						if(j==p||l==p||o==p||dis[o][p]>k||dis[1][p]>k)
						{
							continue;
						}
						ans=max(ans,a[j]+a[l]+a[o]+a[p]);
					}
				}
			}
		}
	}
	else
	{
		for(int i=1;i<=n;i<<=1)
		{
			for(int j=0;j<=n;j++)
			{
				for(int l=0;l<=n;l++)
				{
					f[j][l]=-infll;
					g[j][l]=-infll;
					h[j][l]=-infll;
				}
			}
			for(int j=2;j<=n;j++)
			{
				if(dis[1][j]<=k&&(j&i))
				{
					f[0][j]=a[j];
				}
			}
			for(int j=2;j<=n;j++)
			{
				for(int l=2;l<=n;l++)
				{
					if(j==l||dis[j][l]>k)
					{
						continue;
					}
					f[1][j]=max(f[1][j],f[0][l]+a[j]);
				}
			}
			for(int j=2;j<=n;j++)
			{
				if(dis[1][j]<=k&&(j&i))
				{
					continue;
				}
				for(int l=2;l<=n;l++)
				{
					if(j==l||dis[j][l]>k)
					{
						continue;
					}
					f[j][l]=max(f[j][l],f[1][l]+a[j]);
					g[j][l]=max(g[j-1][l],f[j][l]);
				}
			}
			for(int j=n;j>=2;j--)
			{
				for(int l=n;l>=2;l--)
				{
					h[j][l]=max(h[j+1][l],f[j][l]);
				}
			}
			for(int j=2;j<=n;j++)
			{
				if(dis[1][j]>k||(j&i))
				{
					continue;
				}
				for(int l=2;l<=n;l++)
				{
					if(j==l||dis[j][l]>k)
					{
						continue;
					}
					ans=max(ans,max(g[j-1][l],h[j+1][l])+a[j]);
				}
			}
			//------------------
			for(int j=0;j<=n;j++)
			{
				for(int l=0;l<=n;l++)
				{
					f[j][l]=-infll;
					g[j][l]=-infll;
					h[j][l]=-infll;
				}
			}
			for(int j=2;j<=n;j++)
			{
				if(dis[1][j]<=k&&!(j&i))
				{
					f[0][j]=a[j];
				}
			}
			for(int j=2;j<=n;j++)
			{
				for(int l=2;l<=n;l++)
				{
					if(j==l||dis[j][l]>k)
					{
						continue;
					}
					f[1][j]=max(f[1][j],f[0][l]+a[j]);
				}
			}
			for(int j=2;j<=n;j++)
			{
				if(dis[1][j]<=k&&!(j&i))
				{
					continue;
				}
				for(int l=2;l<=n;l++)
				{
					if(j==l||dis[j][l]>k)
					{
						continue;
					}
					f[j][l]=max(f[j][l],f[1][l]+a[j]);
					g[j][l]=max(g[j-1][l],f[j][l]);
				}
			}
			for(int j=n;j>=2;j--)
			{
				for(int l=n;l>=2;l--)
				{
					h[j][l]=max(h[j+1][l],f[j][l]);
				}
			}
			for(int j=2;j<=n;j++)
			{
				if(dis[1][j]>k||!(j&i))
				{
					continue;
				}
				for(int l=2;l<=n;l++)
				{
					if(j==l||dis[j][l]>k)
					{
						continue;
					}
					ans=max(ans,max(g[j-1][l],h[j+1][l])+a[j]);
				}
			}
		}
	}
	printf("%lld\n",ans);
	return 0;
}
/*
8 8 1
9 7 1 8 2 3 6
1 2
2 3
3 4
4 5
5 6
6 7
7 8
8 1

7 9 0
1 1 1 2 3 4
1 2
2 3
3 4
1 5
1 6
1 7
5 4
6 4
7 4
*/
