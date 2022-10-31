#include<bits/stdc++.h>
using namespace std;
int n,m,k;
struct asd
{
	int nxt,to;
}e[1000000];
long long dis[1000000],ans;
int head[1000000],cnt;
void ad(int u,int v)
{
	e[++cnt].nxt=head[u];
	head[u]=cnt;
	e[cnt].to=v;
}
bool mark[100000];
void dfs(int u,int step,long long d)
{
	if(step==6)
	{
		if(u!=1)return;
		ans=max(ans,d);
		return;
	}
	for(int i=head[u];i;i=e[i].nxt)
	{
		int v=e[i].to;
		if(mark[v] or (v==1 and step!=5))continue;
		mark[v]=1;
		dfs(v,step+1,d+dis[v]);
		mark[v]=0;
	}
}
int main()
{
	freopen("holiday.in","r",stdin);
	freopen("holiday.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m>>k;
	for(int i=2;i<=n;i++)cin>>dis[i];
	for(int i=1;i<=m;i++)
	{
		int u,v;
		cin>>u>>v;
		ad(u,v);
		ad(v,u);
	}
	dfs(1,1,0);
	cout<<ans;
	return 0;
}
/*
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

*/
