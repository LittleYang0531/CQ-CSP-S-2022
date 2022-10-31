#include<bits/stdc++.h>
using namespace std;
int f[2501][2501],head[10001],a[10001];
int n,m,p,i,j,ans,cnt;
struct eve
{
	int to,nxt;
} es[100001];
bool arr[10001],mp[2501][2501];
void add(int x,int y)
{
	es[++cnt].nxt=head[x];
	head[x]=cnt;
	es[cnt].to=y;
}
void dfs(int nr,int k,int s)
{
	if(k==4)
	{
		ans=max(ans,s);
		return;
	}
	for(int i=head[nr];i;i=es[i].nxt)
	{
		int v=es[i].to;
		if(arr[v]||(k==3&&!mp[v][1]))continue;
		arr[v]=1;
		dfs(v,k+1,s+a[v]);
		arr[v]=0;
	}
}
int main()
{
	int x,y,k;
	freopen("holiday.in","r",stdin);
	freopen("holiday.out","w",stdout);
	scanf("%d%d%d",&n,&m,&p);
	for(i=1;i<=n;i++)
		for(j=1;j<=n;j++) f[i][j]=0x7f7f;
	for(i=2;i<=n;i++) scanf("%d",&a[i]);
	for(i=1;i<=m;i++)
	{
		scanf("%d%d",&x,&y);
		f[x][y]=f[y][x]=0;
		mp[x][y]=mp[y][x]=1;
	}
	if(p)
		for(k=1;k<=n;k++)
			for(i=1;i<=n;i++)
				for(j=1;j<=n;j++) f[i][j]=min(f[i][j],f[i][k]+f[k][j]+1);
	for(i=1;i<=n;i++)
		for(j=1;j<=n;j++)
			if(f[i][j]<=p)
			{
				add(i,j);add(j,i);
				mp[i][j]=mp[j][i]=1;
			}
	dfs(1,0,0);
	printf("%d",ans);
	return 0;
}
