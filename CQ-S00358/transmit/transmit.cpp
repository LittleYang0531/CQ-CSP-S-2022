#include<bits/stdc++.h>
#define INF 1e14
using namespace std;
void read(int &x)
{
	x=0;
	char s=getchar();
	int f=1;
	while(s<'0'||s>'9')
	{
		if(s=='-')
		{
			f*=-1;
		}
		s=getchar();
	}
	while(s>='0'&&s<='9')
	{
		x=(x*10)+(s-'0');
		s=getchar();
	}
	x*=f;
	return;
}
const int MAXN=2e5+5;
int n,q,k;
int a[MAXN];
int x,y;
int s,t;
vector<int>g[MAXN];
int dp[MAXN][25];
int dep[MAXN];
long long dis[MAXN];
void bfs(int root)
{
	queue<int>q;
	q.push(root);
	dep[root]=1;
	dis[root]=a[root];
	while(q.size())
	{
		int temp=q.front();
		q.pop();
		for(int i=0;i<g[temp].size();i++)
		{
			int v=g[temp][i];
			if(dep[v])
			{
				continue;
			}
			q.push(v);
			dep[v]=dep[temp]+1;
			dis[v]=dis[temp]+a[v];
			dp[v][0]=temp;
			for(int j=1;j<=20;j++)
			{
				dp[v][j]=dp[dp[v][j-1]][j-1];
			}
		 } 
	}
}
int LCA(int a,int b)
{
	if(dep[a]<dep[b])
	{
		swap(a,b);
	}
	for(int i=20;i>=0;i--)
	{
		if(dep[dp[a][i]]>=dep[b])
		{
			a=dp[a][i];
		}
	}
	if(a==b)
	{
		return a;
	}
	for(int i=20;i>=0;i--)
	{
		if(dp[a][i]!=dp[b][i])
		{
			a=dp[a][i];
			b=dp[b][i];
		}
	}
	return dp[a][0];
}
long long Dp[MAXN];
long long Query(int s,int t)
{
	int lx=LCA(s,t);
	vector<int>Sx,Tx;
	int Now=s;
	while(Now!=lx)
	{
		Sx.push_back(Now);
		Now=dp[Now][0];
	}
	Now=t;
	while(Now!=dp[lx][0])
	{
		Tx.push_back(Now);
		Now=dp[Now][0];
	}
	for(int i=Tx.size()-1;i>=0;i--)
	{
		Sx.push_back(Tx[i]);
	}
	memset(Dp,0x3f,sizeof(Dp));
	Dp[0]=a[Sx[0]];
	for(int i=1;i<Sx.size();i++)
	{
		for(int j=1;j<=k;j++)
		{
			if(i-j>=0)
			{
				Dp[i]=min(Dp[i],Dp[i-j]+a[Sx[i]]);
			}
		}
	}
	return Dp[Sx.size()-1];
}
int main()
{
	freopen("transmit.in","r",stdin);
	freopen("transmit.out","w",stdout);
	scanf("%d %d %d",&n,&q,&k);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
	}
	for(int i=1;i<n;i++)
	{
		scanf("%d %d",&x,&y);
		g[x].push_back(y);
		g[y].push_back(x); 
	}
	bfs(1);
	while(q--)
	{
		scanf("%d %d",&s,&t);
		if(k==1)
		{
			int la=LCA(s,t);
			printf("%lld\n",(long long)dis[s]+dis[t]-2*dis[la]+a[la]);
		 } 
		 else
		 {
		 	printf("%lld\n",Query(s,t));
		 }
		
	}
	return 0;
}
