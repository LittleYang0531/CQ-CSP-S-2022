#include<bits/stdc++.h>
using namespace std;
const int N = 2505;
int n,m,k,ans,x,y;
int sco[N],mapp[N][N];
bool flag[N];
inline void dfs(int u,int s,int sum)
{
	if(sum == 4)
	{
		if(mapp[u][1] <= k+1)
			ans = max(ans,s);
		return;
	}
	for(register int i = 2;i <= n;i ++)
	{
		if(flag[i] || mapp[u][i] > k+1)continue;
		flag[i] = 1;
		dfs(i,s+sco[i],sum+1);
		flag[i] = 0;
	}
}
vector<vector<int> > g(N);
inline void dfss(int u,int s,int sum)
{
	if(sum == 5)
	{
		if(u == 1)ans = max(ans,s);
		return;
	}
	for(register int i = 0;i < g[u].size();i ++)
	{
		if(flag[g[u][i]])continue;
		flag[g[u][i]] = 1;
		dfss(g[u][i],s+sco[g[u][i]],sum+1);
		flag[g[u][i]] = 0;
	}	
}
int main()
{
	freopen("holiday.in","r",stdin);
	freopen("holiday.out","w",stdout);
	memset(mapp,0x3f,sizeof(mapp));
	scanf("%d%d%d",&n,&m,&k);
	mapp[1][1] = 0;
	for(register int i = 2;i <= n;i ++)
	{
		scanf("%d",&sco[i]);
		mapp[i][i] = 0;
	}
	for(register int i = 1;i <= m;i ++)
	{
		scanf("%d%d",&x,&y);
		mapp[x][y] = mapp[y][x] = 1;
		g[x].push_back(y);
		g[y].push_back(x);
	}
	for(register int k = 1;k <= n;k ++)
		for(register int i = 1;i <= n;i ++)
			for(register int j = 1;j <= n;j ++)
				if(mapp[i][k]+mapp[k][j] < mapp[i][j])mapp[i][j] = mapp[i][k]+mapp[k][j];
	if(k == 0)dfss(1,0,0);
	else dfs(1,0,0);
	printf("%d",ans);
	return 0;
}
