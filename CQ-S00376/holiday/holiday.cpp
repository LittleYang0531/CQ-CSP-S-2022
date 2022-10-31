#include<bits/stdc++.h>
using namespace std;

#define re register
#define Re register
#define File(a) freopen(a".in", "r", stdin), freopen(a".out", "w", stdout)
#define i64 long long
#define ui64 unsigned long long

const int N = 2510, M = 1e4 + 4, inf = 0x3f3f3f3f, P = 998244353;

ui64 s[N];
int first[N], nex[M << 1], to[M << 1], num;
bool mp[N][N], vis[N];
inline void Add(int u, int v)
{
	nex[++num] = first[u];
	first[u] = num;
	to[num] = v;
}

queue<pair<int, int> > q;
pair<ui64, int> mx[2][N];

inline bool check(int a, int b, int c, int d)
{
	if (!c || !d) return 0;
	if (a == b || a == c || a == d) return 0;
	if (b == c || b == d) return 0;
	if (c == d) return 0;
	return 1;
}

signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	File("holiday");
	int n, m, K; cin >> n >> m >> K;
	for (Re int i = 2; i <= n; ++i) cin >> s[i];
	for (re int i = 1; i <= m; ++i)
	{
		int u, v; cin >> u >> v;
		Add(u, v), Add(v, u);
	}
	
	for (re int st = 1; st <= n; ++st)
	{
		for (Re int i = 1; i <= n; ++i) vis[i] = 0;
		q.emplace(0, st), vis[st] = 1;
		while (!q.empty())
		{
			int u = q.front().second, d = q.front().first; q.pop();
			mp[st][u] = 1;
			if (d > K) continue; 
			for (re int i = first[u]; i; i = nex[i])
				if (!vis[to[i]]) vis[to[i]] = 1, q.emplace(d + 1, to[i]);
		}
	}
	
//	for (re int i = 1; i <= n; ++i, cout << '\n')
//		for(re int j = 1; j <= n; ++j)
//			cout << mp[i][j] << ' ';
	
	for (re int i = 2; i <= n; ++i)	if (mp[1][i])
		for (re int j = 2; j <= n; ++j) if (i != j && mp[i][j])
		{
			pair<ui64, int> val = {s[i] + s[j], i};
			if (val > mx[0][j]) mx[1][j] = mx[0][j], mx[0][j] = val;
			else if(val > mx[1][j]) mx[1][j] = val;
		}
	
	ui64 ans = 0;
	for (re int i = 2; i <= n; ++i) if (mx[0][i].second)
		for (re int j = 2; j <= n; ++j)
			if (i != j && mp[i][j] && mx[0][j].second)
			{
				for (re int a = 0; a < 2; ++a)
					for (re int b = 0; b < 2; ++b)
						if (check(i, j, mx[a][i].second, mx[b][j].second))
							ans = max(ans, mx[a][i].first + mx[b][j].first);
			}
	
	cout << ans << '\n';
	
	return 0;
}
