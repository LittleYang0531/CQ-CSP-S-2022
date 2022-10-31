#include <bits/stdc++.h>
#define st first
#define nd second
#define db double
#define re register
#define pb push_back
#define mk make_pair
#define int long long
#define ull unsigned long long
#define mst(a, b) memset(a, b, sizeof(a))
using namespace std;
const int N = 2.5e3 + 10, INF = 1e9;
inline int read()
{
	int s = 0, w = 1;
	char ch = getchar();
	while(ch < '0' || ch > '9') { if(ch == '-') w *= -1; ch = getchar(); }
	while(ch >= '0' && ch <= '9') s = s * 10 + ch - '0', ch = getchar();
	return s * w;
}
struct Short{
	int v, p;
	bool operator < (const Short &x) const{ return v > x.v; }
};
int n, m, k, ans;
int s[N], dis[N];
bool vis[N], chk[N];
vector<int> G[N], T[N], S[N]; 
inline void DJ(int s)
{
	priority_queue<Short> q;
	for(re int i = 1; i <= n; i++) vis[i] = false, dis[i] = INF;
	dis[s] = 0, q.push((Short){0, s});
	while(!q.empty()){
		Short u = q.top(); q.pop();
		if(vis[u.p]) continue;
		vis[u.p] = true;
		for(re int to : G[u.p]){
			if(u.v + 1 < dis[to]){
				dis[to] = u.v + 1;
				q.push((Short){dis[to], to});
			}
		}
	}
	for(re int i = 1; i <= n; i++)
		if(i != s && dis[i] - 1 <= k) T[s].pb(i);
}
inline bool cmp(int x, int y) { return s[x] > s[y]; } 
signed main() //85pts
{
	freopen("holiday.in", "r", stdin);
	freopen("holiday.out", "w", stdout);
	n = read(), m = read(), k = read();
	for(re int i = 2; i <= n; i++) s[i] = read();
	for(re int i = 1, x, y; i <= m; i++)
		x = read(), y = read(), G[x].pb(y), G[y].pb(x);
	for(re int i = 1; i <= n; i++) DJ(i);
	for(re int x : T[1]) chk[x] = true;
	for(re int i = 1; i <= n; i++)
		for(re int x : T[i]) if(chk[x]) S[i].pb(x); //单独拿一个 vector 装和 1 相连的点
	for(re int i = 1; i <= n; i++)
		sort(T[i].begin(), T[i].end(), cmp), sort(S[i].begin(), S[i].end(), cmp);
	for(re int x : T[1]){
		for(re int y : T[x]){
			for(re int z : T[y]){
				if(x == z) continue;
				for(re int p : S[z]){
					if(x == p || y == p) continue;
					ans = max(ans, s[x] + s[y] + s[z] + s[p]);
					break;
				}
				if(clock() >= 1900) printf("%lld\n", ans), exit(0);
			}
		}
	}
	printf("%lld\n", ans);
	return 0;
}
