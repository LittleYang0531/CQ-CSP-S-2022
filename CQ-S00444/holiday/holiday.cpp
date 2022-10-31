#include<bits/stdc++.h>
using namespace std;
const int N=2505,M=10005;
const long long inf=0x3f3f3f3f3f3f3f3f;
int n,m,k,vis[N];
long long s[N],f[N][105][5],ans;
vector<int>e[N];
inline void TDP(int u,int prt)
{
	if(vis[u]==5) return;
	vis[u]++;
	for(auto v:e[u])
	{
		if(v==prt) continue;
		for(int i=0;i<=k;++i)
		for(int j=1;j<=4;++j)
		{
			f[v][0][j]=max(f[v][0][j],f[u][i][j-1]+s[v]);
			if(i) f[v][i][j]=max(f[v][i][j],f[u][i-1][j]);
		}
		TDP(v,u);
	}
}
inline void dfs(int u,int prt,long long sum,int num)
{
	vis[u]=1;
	if(num==4)
	{
		ans=max(ans,sum);
		return;
	}
	for(auto v:e[u])
	{
		if(v==prt) continue;
		if(!vis[v]&&v!=1)
		dfs(v,u,sum+s[v],num+1);
	}
}
int main()
{
	freopen("holiday.in","r",stdin);
	freopen("holiday.out","w",stdout);
	ios_base::sync_with_stdio(false);
	cin.tie(NULL),cout.tie(NULL);
	cin>>n>>m>>k;
	for(int i=2;i<=n;++i)
	cin>>s[i];
	for(int i=1;i<=m;++i)
	{
		int u,v;
		cin>>u>>v;
		e[u].push_back(v);
		e[v].push_back(u);
	}
	if(!k)
	{
		dfs(1,0,0,0);
		cout<<ans;
		return 0;
	}
	memset(f,-0x3f,sizeof f);
	f[1][0][0]=0;
	TDP(1,0);
	for(int i=1;i<=n;++i)
	for(int j=0;j<=k;++j)
	ans=max(ans,f[i][j][4]);
	cout<<ans;
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
-------
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
---------
8 7 0
2 3 4 5 6 7 8
1 2
2 3
3 4
4 5
5 6
6 7
7 8
*/
