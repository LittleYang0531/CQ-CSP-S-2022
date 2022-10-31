#include<iostream>
#include<iomanip>
#include<cmath>
#include<cstring>
#include<algorithm>
#include<cstdio>
#include<queue>
using namespace std;
#define int long long
#define md(a) a=(a%mod+mod)%mod
#define file(a) freopen(#a".in","r",stdin);freopen(#a".out","w",stdout)
const int N=2505;
int n,m,ned,val[N],g[N][N],ans,vst[N],cl[N][N],V[N][N];
int f[N][N][12],Lg[N];
vector<int>v[N],nxt[N];queue<int>q;
void bfs(int s)
{
	for(int i=1;i<=n;i++)vst[i]=0;
	q.push(s),vst[s]=1,g[s][s]=0;
	while(!q.empty())
	{
		int x=q.front();q.pop();
		for(int y:v[x])
		{
			if(vst[y])continue;
			g[s][y]=g[s][x]+1,q.push(y),vst[y]=1;
		}
	}
}
int ask(int p,int l,int r)
{
	if(l>r)return -1e18;
	int nmax=Lg[r-l+1];
	return max(f[p][l][nmax],f[p][r-(1<<nmax)+1][nmax]);
}
int calc(int b,int c)
{
	int ans=-4e18;
	for(int a=1;a<=n;a++)
	{
		if(a==b||a==c)continue;
		int dat=V[a][b];
		int ud[3]={a,b,c};
		sort(ud,ud+3);
		int mx=max(ask(c,1,ud[0]-1),ask(c,ud[0]+1,ud[1]-1));
		mx=max(mx,ask(c,ud[1]+1,ud[2]-1));
		mx=max(mx,ask(c,ud[2]+1,n));
		dat+=mx,ans=max(ans,dat);
	}
	return ans;
}
signed main()
{
	freopen("holiday.in","r",stdin);
	freopen("holiday.out","w",stdout);
	scanf("%lld%lld%lld",&n,&m,&ned);
	for(int i=2;i<=n;i++)scanf("%lld",&val[i]),Lg[i]=(int)(log2(i));
	for(int i=1;i<=m;i++)
	{
		int x,y;scanf("%lld%lld",&x,&y);
		v[x].push_back(y),v[y].push_back(x);
	}
	for(int i=1;i<=n;i++)bfs(i);
	for(int i=1;i<=n;i++)for(int j=1;j<=n;j++)if(i!=j&&g[i][j]<=ned+1)nxt[i].push_back(j);
	for(int x:nxt[1])for(int y:nxt[x])cl[x][y]=1;
	for(int i=1;i<=n;i++)for(int j=1;j<=n;j++)V[i][j]=-1e18;
	for(int i=1;i<=n;i++)for(int j=2;j<=n;j++)if(cl[i][j])V[i][j]=val[i]+val[j];
	for(int p=1;p<=n;p++)
	{
		for(int i=1;i<=n;i++)f[p][i][0]=V[i][p];
		for(int j=1;(1<<j)<=n;j++)
		{
			for(int i=1;i+(1<<j)-1<=n;i++)f[p][i][j]=max(f[p][i][j-1],f[p][i+(1<<j-1)][j-1]);
		}
	}
	for(int b=1;b<=n;b++)
	{
		for(int c:nxt[b])ans=max(ans,calc(b,c));
	}
	cout<<ans;
	return 0;
}
