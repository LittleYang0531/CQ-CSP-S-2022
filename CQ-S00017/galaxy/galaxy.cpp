#include <cstdio>
#include <vector>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
const int MAXN = 2e3 + 5;

template<typename T>
void read(T& x) {
  x = 0; int f = 1; char c = getchar(); while (c > '9' || c < '0') { if (c == '-') f = -f; c = getchar(); }
  while (c >= '0' && c <= '9') { x = (x << 3) + (x << 1) + (c ^ 48); c = getchar(); } x *= f;
}
template<typename T>
T Max(T x, T y) { return x > y ? x : y; }
template<typename T>
T Min(T x, T y) { return x < y ? x : y; }
template<typename T>
T Abs(T x) { return x < 0 ? -x : x; }

int n, m, q, cnt[MAXN];
bool ban[MAXN][MAXN], vis[MAXN];
vector<int> G[MAXN], reG[MAXN];

void dfs(int u) {
  vis[u] = 1;
  for (int v : G[u]) if (!ban[u][v]) {
    if (vis[v]) cnt[u]++;
    else {
      dfs(v);
      cnt[u] += cnt[v];
    }
  }
}

int main() {

  freopen("galaxy.in", "r", stdin);
  freopen("galaxy.out", "w", stdout);

  read(n), read(m);
  for (int i = 1, u, v; i <= m; i++) {
    read(u), read(v);
    G[u].push_back(v);
    reG[v].push_back(u);
  }

  read(q);
  for (int i = 1, t, u, v; i <= q; i++) {

    read(t);

    if (t == 1) {
      read(u), read(v);
      ban[u][v] = 1;
    }
    if (t == 2) {
      read(u);
      for (int v : reG[u]) {
        ban[v][u] = 1;
      }
    }
    if (t == 3) {
      read(u), read(v);
      ban[u][v] = 0;
    }
    if (t == 4) {
      read(u);
      for (int v : reG[u]) {
        ban[v][u] = 0;
      }
    }

    memset(vis, 0, sizeof(vis));
    memset(cnt, 0, sizeof(cnt));
    bool res = true;
    for (int j = 1; j <= n; j++) if (!vis[j]) dfs(j);
    for (int j = 1; j <= n; j++) if (cnt[j] != 1) { res = false; break; }

    if (res) printf("YES\n");
    else printf("NO\n");

  }

  return 0;
}