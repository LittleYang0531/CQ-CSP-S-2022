#include<bits/stdc++.h>
using namespace std;
template<typename T> inline void ckmax(T &x, T y) { x = x > y ? x : y; }
template<typename T> inline void ckmin(T &x, T y) { x = x < y ? x : y; }
typedef long long ll;

const int N = 2505, M = 10005;
const ll INF = 5e18;
int n, m, k, dis[N], vis[N];
ll val[N];
vector<int> G[N], to[N], nx[N];
void bfs(int s) {
    queue<int> q;
    for (int i = 1; i <= n; ++i) {
        dis[i] = -1;
    }
    dis[s] = 0;
    q.push(s);
    while (!q.empty()) {
        int u = q.front(); q.pop();
        if (u != s && dis[u] <= k) to[s].push_back(u);
        if (dis[u] >= k) continue;
        for (int v : G[u]) {
            if (dis[v] == -1) {
                dis[v] = dis[u] + 1;
                q.push(v);
            }
        }
    }
}
int main() {
    freopen("holiday.in", "r", stdin);
    freopen("holiday.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> m >> k;
    ++k;
    for (int i = 2; i <= n; ++i) cin >> val[i];
    for (int i = 1, u, v; i <= m; ++i) {
        cin >> u >> v;
        G[u].push_back(v);
        G[v].push_back(u);
    }
    for (int i = 1; i <= n; ++i) {
        bfs(i);
    }
    for (int x : to[1]) vis[x] = 1;
    for (int i = 2; i <= n; ++i) {
        nx[i] = to[i];
        sort(to[i].begin(), to[i].end(), [&](int x, int y) {
            return val[x] * vis[x] > val[y] * vis[y];
        });
        while (to[i].size() && !vis[to[i].back()]) to[i].pop_back();
    }
    ll ans = -INF;
    for (int i = 2; i <= n; ++i) if (to[i].size()) {
        int x = to[i][0];
        for (int j : nx[i]) if (i != j && x != j && j != 1) {
            for (int y : to[j]) {
                if (y == 1 || y == i || y == x || y == j) continue;
                ckmax(ans, val[i] + val[j] + val[x] + val[y]);
                break;
            }
        }
    }
    cout << ans << '\n';
    return 0;
}
