#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=2510,M=1e4+10;
const ll inf=5e18;
int n,m,k;
int dis[N][N];
int h[N],e[2*N],ne[2*N],idx;
ll val[N];
int maxv[N][4];
ll ans;
void add(int a,int b)
{
	e[idx]=b;
	ne[idx]=h[a];
	h[a]=idx++;
}
void dj(int u)
{
	vector<int> q;
	q.push_back(u);
	dis[u][u]=0;
	while(!q.empty())
	{
		int t=q.back();
		q.pop_back();
		for(int i=h[t];i!=-1;i=ne[i])
		{
			int v=e[i];
			if(dis[u][t]+1<dis[u][v])
			{
				dis[u][v]=dis[u][t]+1;
				q.push_back(v);
			}
		}
	}
}
int main()
{
	freopen("holiday.in","r",stdin);
	freopen("holiday.out","w",stdout);
	memset(h,-1,sizeof h);
	memset(dis,0x3f3f3f3f,sizeof dis);
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1;i<n;i++)
		scanf("%lld",&val[i+1]);
	for(int i=1;i<=m;i++)
	{
		int u,v;
		scanf("%d%d",&u,&v);
		add(u,v),add(v,u);
	}
	for(int i=1;i<=n;i++)
		dj(i);
	for(int i=2;i<=n;i++)
		for(int j=2;j<=n;j++)
			if(dis[1][j]<=k+1&&i!=j&&dis[i][j]<=k+1)
			{
				if(val[j]>val[maxv[i][1]])maxv[i][3]=maxv[i][2],maxv[i][2]=maxv[i][1],maxv[i][1]=j;
				else if(val[j]>val[maxv[i][2]])maxv[i][3]=maxv[i][2],maxv[i][2]=j;
				else if(val[j]>val[maxv[i][3]])maxv[i][3]=j;
			}
	for(int i=2;i<=n;i++)
		for(int j=i+1;j<=n;j++)
		if(dis[i][j]<=k+1)
		{
			for(int k1=1;k1<=3;k1++)
				if(maxv[i][k1])
				{
					for(int k2=1;k2<=3;k2++)
						if(maxv[j][k2])
						{
							if(maxv[i][k1]!=maxv[j][k2]&&maxv[i][k1]!=j&&maxv[j][k2]!=i)
								ans=max(ans,val[i]+val[j]+val[maxv[i][k1]]+val[maxv[j][k2]]);
						}
				}
		}
	cout<<ans;
	return 0;
}
