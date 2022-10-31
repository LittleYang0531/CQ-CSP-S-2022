#include <queue>
#include <cstdio>
#include <vector>
#include <cstring>
#include <iostream>
#include <algorithm>
#define LL long long
using namespace std;
const int MAXN = 3e3 + 5;
const LL INF = 1e18;

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

int n, m, k, cnt;
LL w[MAXN], val[MAXN], dis[MAXN][MAXN], dp[MAXN], init[MAXN][MAXN];
vector<int> G[MAXN], pos;
struct Edge {
  int v;
  LL e;
};
vector<Edge> D[MAXN];
bool vis[MAXN];
queue<int> que;

void dfs(int u, int step) {
  pos.push_back(u);
  if (step <= k) {
    dp[0] = w[pos[0]];
    // printf("--%d %d %d\n", pos[0], u, step);
    cnt = pos.size();
    for (int i = 1; i < cnt; i++) {
      dp[i] = INF;
      for (int j = 1; j <= k && i - j >= 0; j++) dp[i] = Min(dp[i], dp[i - j] + w[pos[i]]);
    }
    init[pos[0]][pos[cnt - 1]] = Min(init[pos[0]][pos[cnt - 1]], dp[cnt - 1]);
    if (step == k) {
      pos.pop_back();
      return;
    }
  }
  for (int v : G[u]) dfs(v, step + 1);
  pos.pop_back();
}

void spfa(int st) {

  memset(vis, 0, sizeof(vis));
  while (!que.empty()) que.pop();

  que.push(st), dis[st][st] = 0;

  while (!que.empty()) {
    int u = que.front(); que.pop();
    vis[u] = 0;
    // printf("%d %lld!!\n", u, dis[st][u]);
    for (int i = 0; i < (int)D[u].size(); i++) {
      int v = D[u][i].v; LL e = D[u][i].e;
      if (dis[st][v] > dis[st][u] + e - w[v]) {
        dis[st][v] = dis[st][u] + e - w[v];
        if (!vis[v]) vis[v] = 1, que.push(v);
      }
    }
  }

}

int main() {

  freopen("transmit.in", "r", stdin);
  freopen("transmit.out", "w", stdout);

  read(n), read(m), read(k);
  for (int i = 1; i <= n; i++) read(w[i]);
  for (int i = 1, u, v; i < n; i++) {
    read(u), read(v);
    G[u].push_back(v);
    G[v].push_back(u);
  }
  for (int i = 1; i <= n; i++) for (int j = 1; j <= n; j++) dis[i][j] = init[i][j] = INF;
  for (int i = 1; i <= n; i++) {
    pos.clear();
    dfs(i, 0);
    for (int j = 1; j <= n; j++) {
      D[i].push_back(Edge{j, init[i][j]});
      // if (init[i][j] == INF) printf("0 ");
      // else printf("%lld ", init[i][j]);
    }
    // printf("\n");
  }
  for (int i = 1; i <= n; i++) spfa(i);
  for (int cas = 1, s, t; cas <= m; cas++) {
    
    read(s), read(t);
    printf("%lld\n", dis[s][t] + w[t]);

  }

  return 0;
}