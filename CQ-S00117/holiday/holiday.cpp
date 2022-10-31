#include<bits/stdc++.h>
using namespace std;
const int N=2000+5;
long long ans;
int n,m,k,g1,g2;
int bj[N];
long long f[N],vis[N][N];
void dfs(int now,long long sum,int cnt)
{
	if(cnt==4)
	{
		if(vis[now][1]<=k)
		ans=max(ans,sum);
		return;
	}
	for(int i=2;i<=n;i++)
	{
		if(bj[i]==0&&now!=i&&vis[now][i]<=k)
		{
			bj[i]=1;
			dfs(i,sum+f[i],cnt+1);
			bj[i]=0;
		}
	}
}
void fl()
{
	for(int g=1;g<=n;g++)
	{
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=n;j++)
			{
				if(vis[i][g]+vis[g][j]+1<=k)
				{
					vis[i][j]=min(vis[i][j],vis[i][g]+vis[g][j]+1);
				}
			}
		}
	}
	dfs(1,0,0);
	return;
}
int main()
{
	freopen("holiday.in","r",stdin);
	freopen("holiday.out","w",stdout);
	scanf("%d%d%d",&n,&m,&k);
	for(int i=2;i<=n;i++)
	{
		scanf("%lld",&f[i]);
	}
	memset(vis,0x3f,sizeof(vis));
	for(int i=1;i<=m;i++)
	{
		scanf("%d%d",&g1,&g2);
		vis[g1][g2]=0;
		vis[g2][g1]=0;
	}
	fl();
	printf("%lld",ans);
	return 0;
}
//	queue < D > d;
//	g3.cnt=1;
//	g3.name=1;
//	g3.sum=0;
//	d.push(g3);
//	while(!d.empty())
//	{
//		g3=d.front();
//		d.pop();
//		if(g3.cnt<=4)
//		{
//			for(int i=1;i<=n;i++)
//			{
//				if(i==g3.name)continue;
//				if(vis[g3.name][i]<=k&&bj[i]==0)
//				{
//					bj[i]=1;
//					g4.cnt=g3.cnt++;
//					g4.name=i;
//					g4.sum=g3.sum+f[i];
//					d.push(g4);
//				}
//			}
//		}
//		else
//		{
//			ans=max(ans,g3.sum);
//		}
//	}

