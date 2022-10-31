#include<bits/stdc++.h>
using namespace std;
const int N=2500;
int n,m,k;
long long value[N+5];
vector<int>edge[N+5];
int dis[N+5][N+5];
bool vis[N+5];
vector<pair<long long,int>>go[N+5];
void bfs(int root)
{
	memset(dis[root],0x3f,sizeof(dis[root]));
	memset(vis,0,sizeof(vis));
	queue<int>que;
	que.push(root);
	dis[root][root]=-1;
	while(!que.empty())
	{
		int x=que.front();
		que.pop();
		if(vis[x])continue;
		vis[x]=true;
		for(auto y:edge[x])
		{
			if(dis[root][y]==0x3f3f3f3f)
			{
				dis[root][y]=dis[root][x]+1;
				que.push(y);
			}
		}
	}
}
long long calc(int b,int c)
{
	long long ans=0;
	for(int i=min(3,int(go[b].size())-1);i>=0;--i)
	{
		for(int j=min(3,int(go[c].size())-1);j>=0;--j)
		{
			if(go[b][i].second!=c&&go[b][i].second!=go[c][j].second&&go[c][j].second!=b)
			{
				ans=max(ans,value[b]+value[c]+go[b][i].first+go[c][j].first);
//				if(ans==8)
//				{
//					cout<<go[b][i].second<<' '<<b<<' '<<c<<' '<<go[c][j].second<<'\n';
//					exit(0);
//				}
			}
		}
	}
	return ans;
}
int main()
{
	freopen("holiday.in","r",stdin);
	freopen("holiday.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>n>>m>>k;
	for(int i=2;i<=n;++i)cin>>value[i];
	for(int i=1;i<=m;++i)
	{
		int x,y;
		cin>>x>>y;
		edge[x].push_back(y);
		edge[y].push_back(x);
	}
	for(int i=1;i<=n;++i)
		bfs(i);
	for(int a=2;a<=n;++a)
	{
		for(int b=2;b<=n;++b)
		{
			if(a==b)continue;
			assert(dis[a][b]==dis[b][a]);
			if(dis[1][a]>k||dis[a][b]>k)continue;
			go[b].push_back(make_pair(value[a],a));
		}
	}
	for(int b=2;b<=n;++b)sort(go[b].begin(),go[b].end(),greater<pair<long long,int>>());
	long long answer=0;
	for(int b=2;b<=n;++b)
	{
		if(go[b].empty())continue;
		for(int c=2;c<=n;++c)
		{
			if(b==c)continue;
			if(go[c].empty())continue;
			if(dis[b][c]>k)continue;
			answer=max(answer,calc(b,c));
		}
	}
	cout<<answer;
	return 0;
}
