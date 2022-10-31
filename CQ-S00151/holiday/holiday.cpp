#include<bits/stdc++.h>
using namespace std;
const int MAXN=2501;
const int MAXM=10005;
void read(int &x)
{
	x=0;
	short flag=1;
	char ch=getchar();
	while(ch<'0'||ch>'9')
	{
		if(ch=='-')	flag=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9')
	{
		x=(x<<1)+(x<<3)+(ch^48);
		ch=getchar();
	}
	x*=flag;
}
long long sc[MAXN];
int n,m,k;
int to[MAXM],nxt[MAXM],head[MAXM],tot,vis[MAXN],sum[MAXN][MAXN];
long long val[MAXM];
long long dis[MAXN][MAXN];
long long dp[MAXN][MAXN][5];
void add(int x,int y,long long w)
{
	to[++tot]=y,val[tot]=w;
	nxt[tot]=head[x],head[x]=tot;
}
priority_queue<pair<int,int> > que;
void Dijkstra(int s)
{
	for(int i=0;i<=n;i++)	dis[s][i]=-1,sum[s][i]=-1,vis[i]=0;
	dis[s][s]=0;
	que.push(make_pair(0,s));
	while(!que.empty())
	{
		int t=que.top().second;
		que.pop();
		if(vis[t])	continue;
		vis[t]=1;
		for(int i=head[t];i;i=nxt[i])
		{
			if(dis[s][to[i]]<val[i]&&sum[s][t]<k)
			{
				dis[s][to[i]]=val[i];
				sum[s][to[i]]=sum[s][t]+1;
				que.push(make_pair(dis[s][to[i]],to[i]));
			}
		}
	}
}
int main()
{
	freopen("holiday.in","r",stdin);
	freopen("holiday.out","w",stdout);
	read(n),read(m),read(k);
	for(int i=2;i<=n;i++)	scanf("%lld",&sc[i]);
	while(m--)
	{
		int from,to;
		read(from),read(to);
		add(from,to,sc[to]),add(to,from,sc[from]);
	}
	for(int i=1;i<=n;i++)	Dijkstra(i);
	long long maxx=-1;
	for(int i=2;i<=n;i++)
	{
		for(int j=2;j<=n;j++)
		{
			for(int w=2;w<=n;w++)
			{
				for(int l=2;l<=n;l++)
				{
					if(i==j||j==w||w==l||i==w||i==l||j==l)	continue;
					if(~dis[i][j]&&~dis[j][w]&&~dis[w][l]&&~dis[l][1]&&~dis[1][i])
						maxx=max(maxx,dis[1][i]+dis[i][j]+dis[j][w]+dis[w][l]+dis[l][1]);
				}
			}
		}
	}
	printf("%lld",maxx);
	return 0;
}
//belief2022
