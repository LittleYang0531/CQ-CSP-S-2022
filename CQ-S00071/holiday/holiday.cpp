#include<bits/stdc++.h>
using namespace std;
struct op
{
	int v,w,ne;
}e[6500000];

int n,m,k;
long long a[2504];
int cnt=1,head[2504];
bool vis[2505][2502],vk[2505];
long long dp[2503][5],ans;

void add(int u, int v, int w)
{
	e[cnt]={v,w,head[u]};
	head[u]=cnt++;
}

void add1(int x, int y, int w)
{
	if(w>k+1||vis[x][y]) return;
	add(x,y,w);
	add(y,x,w);
	vis[x][y]=1;
	vis[y][x]=1;
	for(int i=head[y];i ;i=e[i].ne)
	{
		if(vis[e[i].v][x]) continue;
		add1(x,e[i].v,w+1);
	}
}

void dfs(int x, int w, long long tot)
{
	if(w==5) 
	{
		if(x==1) ans=max(ans,tot);
		return;
	}
//	printf("%d %lld\n",x,tot);
	vk[x]=1;	
	for(int i=head[x]; i; i=e[i].ne)
	{
		int v=e[i].v;
		if(vk[v]) continue;
		dfs(v,w+1,tot+a[v]);
		vk[v]=0;
	}
}

int main()
{
	freopen("holiday.in","r",stdin);
	freopen("holiday.out","w",stdout);
	scanf("%d%d%d",&n,&m,&k);
	for(int i=2; i<=n; i++)
		for(int j=1; j<=4; j++) dp[i][j]=-0x3f3f3f3f3f3f;
	for(int i=1; i<=n; i++) vis[i][i]=1;
	for(int i=2; i<=n; i++) scanf("%lld",&a[i]);
	int u,v;
	for(int i=1; i<=m; i++)
	{
		scanf("%d%d",&u,&v);
		add(u,v,1);
		add(v,u,1);
		vis[u][v]=1;
		vis[v][u]=1;
	}
	if(k>=1) for(int i=1; i<=n; i++)
	{
		for(int j=head[i]; j; j=e[j].ne)
		{
			if(e[j].w>1) continue;
			int v=e[j].v;
			for(int z=head[v]; z; z=e[z].ne)
			{
				if(vis[i][e[z].v]||e[z].w>1) continue;
//				if(i==1&&e[z].v==6) printf("%de\n",v);
				add1(i,e[z].v,2);
			}
		}
	} 
	for(int i=head[1]; i; i=e[i].ne)
	{
//		printf("%de",e[i].v);
		dfs(e[i].v,1,a[e[i].v]);
		vk[e[i].v]=0;
	}
	printf("%lld",ans);
	return 0;
}
