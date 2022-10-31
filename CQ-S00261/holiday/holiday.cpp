#include<bits/stdc++.h>
using namespace std;
int read()
{
	char ch;
	int t = 0,op = 1;
	ch = getchar();
	while(ch!='-'&&(ch>'9'||ch<'0'))
		ch = getchar();
	if(ch=='-')
		op = -1,ch = getchar();
	while(ch<='9'&&ch>='0')
		t = (t<<1)+(t<<3)+ch-48,ch = getchar();
	return t*op;
}
const int N = 2510;
int n,m,k,g[N],dp[N];
vector<int> a[N],vis;
bool ok(int x)
{
	for(int i = 0;i<vis.size()-1;++i)
		if(vis[i]==x)
			return 0;
	return 1;
}
void dfs(int d,int x,int y,int st)
{
	if(y>k)
	{
		if(dp[d]<dp[d-1]+g[x]&&ok(x)&&x!=1)
			dp[d] = dp[d-1]+g[x],vis[d] = x;
		return;
	}
	for(int i = 0;i<a[x].size();++i)
		dfs(d,a[x][i],y+1,st);
}
int main()
{
	freopen("holiday.in","r",stdin);
	freopen("holiday.out","w",stdout);
	n = read(),m = read(),k = read();
	for(int i = 2;i<=n;++i)
		g[i] = read();
	for(int i = 2;i<=m;++i)
	{
		int x,y;
		x = read(),y = read();
		a[x].push_back(y);
		a[y].push_back(x);
	}
	vis.push_back(0);
	for(int t = 1;t<=4;++t)
	{
		vis.push_back(0);
		dp[t] = dp[t-1];
		if(t>1)
			dfs(t,vis[t-1],1,vis[t-1]);
		else
			dfs(t,1,1,1);
	}
	printf("%d",dp[4]);
	return 0;
}

