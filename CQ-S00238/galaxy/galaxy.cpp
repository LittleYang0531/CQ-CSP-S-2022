#include <bits/stdc++.h>
using namespace std;
typedef pair < long long, long long > PII;
long long n, m, q, d[1010], h[1010], cnt;
struct edge {long long to, next, rage;} e[20010];
inline void add(long long x, long long y)
{e[++cnt].to = y, e[cnt].next = h[x], h[x] = cnt;}
map < PII, long long > edgeid;
vector < long long > To[1010];
bool flag, vis[1010], ok;
long long read()
{
	long long ans = 0, bj = 1;
	char c = getchar();
	if(c == '-') bj = -1;
	while(c < '0' || c > '9')
	{
		c = getchar();
		if(c == '-') bj = -1;
	}
	while('0' <= c && c <= '9')
		ans = (ans << 1) + (ans << 3) + c - '0', c = getchar();
	return ans * bj;
}
void dfs(long long now)
{
	vis[now] = true;
	for(int i = h[now]; i; i = e[i].next)
	{
		long long to = e[i].to;
		if(e[i].rage == 1) continue;
		if(vis[to] == true) ok = true;
		if(ok) return ;
		dfs(to);
		if(ok) return ;
	}
}
int main()
{
	freopen("galaxy.in", "r", stdin);
	freopen("galaxy.out", "w", stdout);
	n = read(); m = read();
	for(int i = 1, x, y; i <= m; ++i)
	{
		x = read(); y = read();
		++d[x];
		add(x, y);
		To[y].push_back(x);
		edgeid[{x, y}] = cnt;
	}
	q = read();
	for(int js = 1; js <= q; ++js)
	{
		long long opt, u, v;
		opt = read();
		if(opt == 1)
		{
			u = read(); v = read();
			e[edgeid[{u, v}]].rage = 1;
			d[u]--;
		}
		if(opt == 2)
		{
			u = read();
			for(int i = 0; i < To[u].size(); ++i)
			{
				long long to = To[u][i];
				if(e[edgeid[{to, u}]].rage == 0)
				{
					e[edgeid[{to, u}]].rage = 1;
					d[to]--;
				}
			}
		}
		if(opt == 3)
		{
			u = read(); v = read();
			e[edgeid[{u, v}]].rage = 0;
			d[u]++;
		}
		if(opt == 4)
		{
			u = read();
			for(int i = 0; i < To[u].size(); ++i)
			{
				long long to = To[u][i];
				if(e[edgeid[{to, u}]].rage == 1)
				{
					e[edgeid[{to, u}]].rage = 0;
					d[to]--;
				}
			}
		}
		flag = true;
		for(int i = 1; i <= n; ++i)
		{
			if(d[i] != 1)
				flag = false;
		}
		if(flag == false)
		{
			printf("NO\n");
			continue;
		}
		for(int i = 1; i <= n; ++i)
			vis[i] = false;
		for(int i = 1; i <= n; ++i)
		{
			ok = false;
			dfs(i);
			if(ok == false)
			{
				flag = false;
				break;
			}
		}
		if(flag == false)
			printf("NO\n");
		else printf("YES\n");
	}
	return 0;
}
