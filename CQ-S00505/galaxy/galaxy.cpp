#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <unordered_map>
#define ll long long
using namespace std;
const int MAXN = 5e5+5;
int n,m,q,op,cnt[MAXN],num;
ll x,y;
bool vis[MAXN];
vector <int> edge[MAXN],con[MAXN];
unordered_map<ll,bool> h;

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

inline bool dfs(ll pos)
{
	vis[pos] = true;
	for(int i = 0;i < edge[pos].size();i++)
	{
		if(vis[edge[pos][i]] == true)
			return false;
		if(h[1ll * pos * n + edge[pos][i]] && !dfs(edge[pos][i]))
			return false;
	}
	return true;
}

inline bool work()
{
	bool flag = false;
	memset(vis,false,sizeof(vis));
	for(int j = 1;j <= n;j++)
	{
		if(!vis[j])
		{
			flag = dfs(j);
			if(flag)
				break;
		}
	}
	if(!flag)
		return true;
	return false;
}

int main()
{
	freopen("galaxy.in","r",stdin);
	freopen("galaxy.out","w",stdout);
	read(n);
	read(m);
	for(int i = 1;i <= m;i++)
	{
		read(x);
		read(y);
		edge[x].push_back(y);
		con[y].push_back(x);
		h[1ll * x * n + y] = true;
		cnt[x]++;
		if(cnt[x] == 1)
			num++;
		if(cnt[x] == 2)
			num--;
	}
	read(q);
	for(int i = 1;i <= q;i++)
	{
		read(op);
		if(op == 1)
		{
			read(x);
			read(y);
			h[1ll * x * n + y] = false;
			cnt[x]--;
			if(cnt[x] == 1)
				num++;
			if(cnt[x] == 0)
				num--;
		}
		else if(op == 2)
		{
			read(x);
			for(int j = 0;j < con[x].size();j++)
			{
				int y = con[x][j];
				if(h[1ll * y * n + x] == false)
					continue;
				h[1ll * y * n + x] = false;
				cnt[y]--;
				if(cnt[y] == 1)
					num++;
				if(cnt[y] == 0)
					num--;
			}
		}
		else if(op == 3)
		{
			read(x);
			read(y);
			h[1ll * x * n + y] = true;
			cnt[x]++;
			if(cnt[x] == 1)
				num++;
			if(cnt[x] == 2)
				num--;
		}
		else
		{
			read(x);
			for(int j = 0;j < con[x].size();j++)
			{
				int y = con[x][j];
				if(h[1ll * y * n + x] == true)
					continue;
				h[1ll * y * n + x] = true;
				cnt[y]++;
				if(cnt[y] == 1)
					num++;
				if(cnt[y] == 2)
					num--;
			}
		}
		if(num == n && work())
			printf("YES\n");
		else
			printf("NO\n");
	}
	return 0;
}

