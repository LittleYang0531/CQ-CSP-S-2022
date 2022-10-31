#include<bits/stdc++.h>
using namespace std;
struct edge
{
	int to,next;
} a[500001];
int h[500001],cnt;
void add(int x,int y)
{
	a[++cnt].to = y;
	a[cnt].next = h[x];
	h[x]=cnt;
}
int vis[500001];
set<int> e[500001],e1[500001];
int cd[500001],rd[500001];
bool check(int x)
{
	for(auto u:e[x])
	{
		if(cd[u]>1)return 0;
		if(vis[u])return 1;
		vis[u]=1;
		return check(u);
	}
}
signed main()
{
	freopen("galaxy.in","r",stdin);
	freopen("galaxy.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n,m;
	cin >> n >> m;
	for(int i = 1;i <= m;i++)
	{
		int x,y;
		cin >> x >> y;
		e[x].insert(y);
		e1[y].insert(x);
		rd[y]++;
		cd[x]++;
	}
	int q;
	cin >> q;
	for(int i = 1;i <= q;i++)
	{
		int t,u,v;
		cin >> t >> u;
		if(t==1)
		{
			cin >> v;
			rd[v]--;
			cd[u]--;
			e[u].erase(v);
		}
		if(t==2)
		{
			for(auto x:e1[u])
			{
				if(e[x].find(u)!=e[x].end())cd[x]--;
				e[x].erase(u);
			}
		//	e1[]
		}
		if(t==3)
		{
			cin >> v;
			rd[v]++;
			cd[u]++;
			e[u].insert(v);
		}
		if(t==4)
		{
			for(auto x:e1[u])
			{
				if(!(e[x].find(u)!=e[x].end()))cd[x]++;
				e[x].insert(u);
			}
		}
		for(int i = 1;i <= n;i++)vis[i]=0;
		bool fl = 1;
		for(int i = 1;i <= n;i++)
		{
			if(!vis[i])fl&=check(i);
			if(!fl)
			{
				cout << "NO" << "\n";
				break;
			}
		}
		if(fl)cout << "YES" << "\n";
	}
	return 0;
}
/*
3 6
2 3
2 1
1 2
1 3
3 1
3 2
11
1 3 2
1 2 3
1 1 3
1 1 2
3 1 3
3 3 2
2 3
1 3 1
3 1 3
4 2
1 3 2
*/
