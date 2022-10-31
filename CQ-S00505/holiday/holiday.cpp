#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>
#define mp(x,y) make_pair(x,y)
#define ll long long
using namespace std;
const int MAXN = 2505;
const int INF = 2147483647;
int n,m,x,y,k,dis[MAXN];
bool vis[MAXN];
ll a[MAXN],dp[10][MAXN];
vector <int> edge[MAXN];

template <typename T>
inline void read(T &s)
{
	s = 0;
	bool w = false;
	char ch = getchar();
	while(ch < '0'||ch > '9')
	{
		if(ch == '-')
			w = true;
		ch = getchar();
	}
	while(ch >= '0'&&ch <= '9')
	{
		s = (s<<3) + (s<<1) + (ch^48);
		ch = getchar();
	}
	s = w ? -s:s;
	return;
}

inline void dijkstra(int s)
{
	for(int i = 1;i <= n;i++)
	{
		dis[i] = INF;
		vis[i] = false;
	}
	priority_queue <pair<int,int>,vector<pair<int,int> >,greater<pair<int,int> > > q;
	q.push(mp(0,s));
	dis[s] = 0;
	while(!q.empty())
	{
		int now = q.top().second;
		q.pop();
		if(vis[now] == true)
			continue;
		vis[now] = true;
		for(int i = 0;i < edge[now].size();i++)
		{
			int y = edge[now][i];
			if(dis[y] > dis[now] + 1)
			{
				dis[y] = dis[now] + 1;
				q.push(mp(dis[y],y));
			}
		}
	}
	return;
}

inline ll dfs(int pos,int fa,int le,int cnt)
{
	if(dis[pos] > cnt * k)
		return -1e18;
	if(cnt == 1)
		return 0;
	ll ans = 0;
	for(int i = 0;i < edge[pos].size();i++)
	{
		if(edge[pos][i] == fa || vis[edge[pos][i]])
			continue;
		if(le < k)
			ans = max(ans,dfs(edge[pos][i],pos,le+1,cnt));
		vis[edge[pos][i]] = true;
		ans = max(ans,dfs(edge[pos][i],pos,1,cnt-1) + a[edge[pos][i]]);
		vis[edge[pos][i]] = false;
	}
	return ans;
}

int main()
{
	freopen("holiday.in","r",stdin);
	freopen("holiday.out","w",stdout);
	read(n);
	read(m);
	read(k);
	k++;
	for(int i = 2;i <= n;i++)
		read(a[i]);
	for(int i = 1;i <= m;i++)
	{
		read(x);
		read(y);
		edge[x].push_back(y);
		edge[y].push_back(x);
	}
	dijkstra(1);
	for(int i = 1;i <= n;i++)
		vis[i] = false;
	printf("%lld\n",dfs(1,0,1,5));
	return 0;
}
