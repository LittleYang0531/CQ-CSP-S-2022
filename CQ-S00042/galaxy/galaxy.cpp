//特殊性质骗分 
#include<bits/stdc++.h>
#define int long long
using namespace std;
const int MAXN=500005;
vector<int>G[MAXN];
bool vis[MAXN];
int n,m,q;
bool check(int x)
{
	int cnt=0;
	for(int i=1;i<=n;i++)
	{
		if(cnt>1) return false;
		if(G[x][i]) cnt++;
	}
	if(cnt==1) return true;
}
bool dfs(int x)
{
	for(int i=1;i<=n;i++)
	{
		if(i==x) continue;
		if(G[x][i])
		{
			if(vis[i]) return true;
			else
			{
				vis[i]=true;
				return dfs(i);
			}
		}
	}
}
void solve()
{
	scanf("%lld%lld",&n,&m);
	while(m--)
	{
		int u,v;
		scanf("%lld%lld",&u,&v);
		G[u].push_back(v);
	}
	scanf("%lld",&q);
	while(q--)
	{
		int t;
		scanf("%lld",&t);
		if(t==1)
		{
			int u,v;
			scanf("%lld%lld",&u,&v);
			G[u][v]=0;
			bool flag=false;
			for(int i=1;i<=n;i++)
			{
				if(!(dfs(i)&&check(i)))
				{
					flag=true;
					break;
				}
			}
			if(!flag) puts("YES");
			else puts("NO");
		}
		else
		{
			int u;
			scanf("%lld",&u);
			bool flag=false;
			for(int i=1;i<=n;i++)
			{
				if(!(dfs(i)&&check(i)))
				{
					flag=true;
					break;
				}
			}
			if(!flag) puts("YES");
			else puts("NO");
		}
	}
} 
signed main()
{
	freopen("galaxy.in","r",stdin);
	freopen("galaxy.out","w",stdout);
	solve();
	return 0;
}
