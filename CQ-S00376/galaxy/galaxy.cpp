#include<bits/stdc++.h>
using namespace std;

#define re register
#define Re register
#define File(a) freopen(a".in", "r", stdin), freopen(a".out", "w", stdout)
#define i64 long long

const int N = 5e5 + 5, inf = 0x3f3f3f3f, P = 998244353;

int deg[N], cnt;
bool vis[N];
int first[N], nex[N], to[N], num;
unordered_map<int, int> mp[N];
inline void Add(int u, int v)
{
	nex[++num] = first[u];
	first[u] = num;
	to[num] = v;
	vis[num] = 1;
	mp[u][v] = num;
}

signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	File("galaxy");
	int n, m; cin >> n >> m;
	for (re int i = 1; i <= m; ++i)
	{
		int u, v; cin >> u >> v;
		++deg[u], Add(v, u);
	}
	
	for (re int i = 1; i <= n; ++i)
		cnt += (deg[i] == 1);
	
	int T; cin >> T;
	while (T--)
	{
		int op, u, v; cin >> op;
		if (op == 1)
		{
			cin >> u >> v;
			int id = mp[v].at(u);
			--deg[u], vis[id] = 0;
			if (!deg[u]) --cnt;
			else if (deg[u] == 1) ++cnt;
		}
		else if (op == 2)
		{
			cin >> u;
			for (re int i = first[u]; i; i = nex[i])
				if (vis[i])
				{
					vis[i] = 0, --deg[to[i]];
					if (!deg[to[i]]) --cnt;
					else if (deg[to[i]] == 1) ++cnt;
				}
					
		}
		else if (op == 3)
		{
			cin >> u >> v;
			int id = mp[v].at(u);
			++deg[u], vis[id] = 1;
			if (deg[u] == 2) --cnt;
			else if (deg[u] == 1) ++cnt;
		}
		else
		{
			cin >> u;
			for (re int i = first[u]; i; i = nex[i])
				if (!vis[i])
				{
					vis[i] = 1, ++deg[to[i]];
					if (deg[to[i]] == 2) --cnt;
					else if (deg[to[i]] == 1) ++cnt;
				}
		}
		if (cnt == n) cout << "YES\n";
		else cout << "NO\n";
	}
	
	return 0;
}
