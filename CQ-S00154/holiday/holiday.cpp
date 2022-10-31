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
inline void read1(long long &x)
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
const int N=2510,M=1e4+10;
int n,m,k;
ll s[N],ans;
int h[N],e[2*M],ne[2*M],idx;
bool vis[2*M];
int dis[N][N];
void add(int a,int b)
{
	e[idx]=b;
	ne[idx]=h[a];
	h[a]=idx++;
}
void dfs(int st,int u,int dp)
{
	if(dis[st][u]==-1 || dis[st][u]>dp)
		dis[st][u]=dp;
	for(int i=h[u];i!=-1;i=ne[i])
	{
		if(vis[i]) continue;
		vis[i]=1;
		dfs(st,e[i],dp+1);
		vis[i]=0;
	}
}
int main()
{
	freopen("holiday.in","r",stdin);
	freopen("holiday.out","w",stdout);
	memset(h,-1,sizeof h);
	memset(dis,-1,sizeof dis);
	read(n);read(m);read(k);
	for(int i=2;i<=n;i++) read1(s[i]);
	for(int i=1;i<=m;i++)
	{
		int u,v;
		read(u);read(v);
		add(u,v);add(v,u);
	}
	for(int i=1;i<=n;i++) dfs(i,i,0);
	for(int a=2;a<=n;a++)
	{
		if(dis[1][a]>k+1) continue;
		for(int b=2;b<=n;b++)
		{
			if(b==a) continue;
			if(dis[a][b]>k+1) continue;
			for(int c=2;c<=n;c++)
			{
				if(c==a||c==b) continue;
				if(dis[b][c]>k+1) continue;
				for(int d=2;d<=n;d++)
				{
					if(d==a||d==b||d==c) continue;
					if(dis[c][d]>k+1||dis[1][d]>k+1) continue;
					ans=max(ans,s[a]+s[b]+s[c]+s[d]);
				}
			}
		}
	}
	print(ans);
	return 0;
}
