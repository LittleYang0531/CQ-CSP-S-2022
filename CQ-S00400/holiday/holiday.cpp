#include<bits/stdc++.h>
#define int long long 
using namespace std;
struct edge{int next,to;}q[6250001];
int n,m,k,a[2501],h[2501],cnt,g[2501][2501],f[2501][6],sum,ans;
bool vis[2501];
inline void add(int x,int y){q[++cnt].next=h[x],q[cnt].to=y,h[x]=cnt;}
inline void dfs(int x,int fa,int step)
{
	if(sum<=f[x][step])return;
	if(step==5)
	{
		if(g[1][x]<=k)ans=max(ans,sum);
		return;
	}
	f[x][step]=sum;
	for(int i=h[x];i;i=q[i].next)if(q[i].to!=fa&&!vis[q[i].to])sum+=a[q[i].to],vis[q[i].to]^=1,dfs(q[i].to,x,step+1),sum-=a[q[i].to],vis[q[i].to]^=1;
}
inline void init()
{
	cin>>n>>m>>k,k++;
	for(int i=2;i<=n;i++)cin>>a[i];
	if(k==1)
	{
		for(int i=1;i<=m;i++)
		{
			int x,y;
			cin>>x>>y,add(x,y),add(y,x);
		}
		return;
	}
	for(int i=1;i<=n;i++)for(int j=1;j<=n;j++)if(i!=j)g[i][j]=0xfffffff;
	for(int i=1;i<=m;i++)
	{
		int x,y;
		cin>>x>>y,g[x][y]=g[y][x]=1;
	}
	for(int k=1;k<=n;k++)for(int i=1;i<=n;i++)for(int j=1;j<=n;j++)if(g[i][k]!=0xfffffff&&g[k][j]!=0xfffffff)g[i][j]=min(g[i][j],g[i][k]+g[k][j]);
	for(int i=1;i<=n;i++)for(int j=i+1;j<=n;j++)if(g[i][j]<=k)add(i,j),add(j,i);
}
inline void solve()
{
	vis[1]=1,f[1][1]=-1,dfs(1,0,1),cout<<ans;
}
signed main()
{
	freopen("holiday.in","r",stdin);
	freopen("holiday.out","w",stdout);
	ios::sync_with_stdio(false);cin.tie(0),cout.tie(0);
	init(),solve();
	return 0;
}
/*
input1:
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

output1:
27
*/
/*
input2:
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

output2:
7
*/
