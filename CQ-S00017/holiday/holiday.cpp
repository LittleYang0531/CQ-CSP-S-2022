#include <queue>
#include <cstdio>
#include <vector>
#include <cstring>
#include <iostream>
#include <algorithm>
#define LL long long
using namespace std;
const int MAXN = 2505;

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

int n, m, k, dis[MAXN][MAXN];
LL a[MAXN], ans;
vector<int> G[MAXN];
bool vis[MAXN], pos[MAXN];
queue<int> que;
struct Node { int pos; LL val; } tmp[MAXN], maxl[MAXN][10];

void spfa(int st) {
  
  memset(vis, 0, sizeof(vis));
  memset(dis[st], 0x3f, sizeof(dis[st]));
  while (!que.empty()) que.pop();

  que.push(st), dis[st][st] = 0, vis[st] = 1;

  while (!que.empty()) {
    int u = que.front(); que.pop();
    vis[u] = 0;
    for (int v : G[u]) if (dis[st][v] > dis[st][u] + 1) {
      dis[st][v] = dis[st][u] + 1;
      if (!vis[v]) vis[v] = 1, que.push(v);
    }
  }

}

int main() {

  freopen("holiday.in", "r", stdin);
  freopen("holiday.out", "w", stdout);

  read(n), read(m), read(k);
  for (int i = 2; i <= n; i++) read(a[i]);
  for (int i = 1, u, v; i <= m; i++) {
    read(u), read(v);
    G[u].push_back(v);
    G[v].push_back(u);
  }

  for (int i = 1; i <= n; i++) spfa(i);
  for (int i = 2; i <= n; i++) if (dis[1][i] <= k + 1) pos[i] = 1;

  for (int i = 2; i <= n; i++) {
    for (int j = 2; j <= n; j++) {
      if (i != j && dis[j][i] <= k + 1 && dis[1][j] <= k + 1) tmp[j] = Node{j, a[i] + a[j]};
      else tmp[j] = Node{0, 0};
    }
    sort(tmp + 2, tmp + 1 + n, [](const Node& x, const Node& y) { return x.val > y.val; });
    for (int j = 1; j <= 4; j++) maxl[i][j] = tmp[j];
  }

  for (int i = 2; i <= n; i++) {
    for (int j = 2; j <= n; j++) if (i != j && dis[i][j] <= k + 1) {
      for (int p1 = 1; p1 <= 4; p1++) for (int p2 = 1; p2 <= 4; p2++) {

        if (maxl[i][p1].pos == 0 || maxl[j][p2].pos == 0) continue;

        if (maxl[i][p1].pos != j && maxl[i][p1].pos != maxl[j][p2].pos && i != maxl[j][p2].pos) {
          ans = Max(ans, maxl[i][p1].val + maxl[j][p2].val);
          // printf("%d %d %d %d\n", maxl[i][p1].pos, i, j, maxl[j][p2].pos);
        }

      }
    }
  }
  printf("%lld\n", ans);

  return 0;
}