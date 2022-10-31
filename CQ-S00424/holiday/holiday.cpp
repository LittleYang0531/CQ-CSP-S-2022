// 德丽莎你好可爱德丽莎你好可爱德丽莎你好可爱德丽莎你好可爱德丽莎你好可爱
// 德丽莎的可爱在于德丽莎很可爱，德丽莎为什么很可爱呢？那是因为德丽莎很可爱！
// 没有力量的理想是空虚，没有理想的力量是戏言
#include <bits/stdc++.h>
#define int long long
using namespace std;
#define rep(i, l, r) for(int i = (l); i <= (r); i++)
#define repd(i, l, r) for(int i = (l); i >= (r); i--)
bool o1;
const int N = 2e5, inf = 2e18;
int n, m, k, a[N], num, nex[N], first[N], v[N];
void add(int from,int to) {
  nex[++num] = first[from];
  first[from] = num;
  v[num] = to;
}
int dep[N], vis[N], vib[N];
int mp[3000][3000];
void bfs(int s) {
  rep (i, 1, n)  dep[i] = inf, vis[i] = 0;
  queue <int> q;
  q.push(s);
  dep[s] = 0;
  while (!q.empty()) {
    int u = q.front();
    q.pop();
    if (vis[u])  continue;
    vis[u] = 1;
    for (int i = first[u]; i; i = nex[i]) {
      int to = v[i];
      if (dep[to] > dep[u] + 1) {
        dep[to] = dep[u] + 1;
        if (dep[to] <= k + 1)  q.push(to);
      }
    }
  }
  rep (i, 1, n)  if (dep[i] <= k + 1)  mp[s][i] = 1;
}
vector <int> ned[2600];
int cmp(int x,int y) {
  return a[x] > a[y];
}
void solve() {
  cin >> n >> m >> k;
  rep (i, 2, n)  cin >> a[i];
  rep (i, 1, m) {
    int x, y;
    cin >> x >> y;
    add(x, y);
    add(y, x);
  }
  rep (i, 1, n)  bfs(i);
  rep (i, 2, n)  if (mp[1][i] == 1)  vib[i] = 1;
  rep (i, 1, n) {
    rep (j, 1, n) {
      if (i == j)  continue;
      if (mp[i][j] == 1 && vib[j])  ned[i].push_back(j);
    }
  }
  rep (i, 1, n)  sort(ned[i].begin(), ned[i].end(), cmp);
  int ans = 0;
  rep (b, 2, n) {
    if (ned[b].size() == 0)  continue;
    rep (c, b + 1, n) {
      if (ned[c].size() == 0)  continue;
      if (mp[b][c] == 0)  continue;
      int cg = 0;
      for (int j = 0; j < (int)ned[b].size(); j++) {
        int x = ned[b][j];
        int ct = 0;
        for (int t = 0; t < (int)ned[c].size(); t++) {
          int y = ned[c][t];
          if (x != y && y != b && x != c && b != c && x != b && y != c) {
            ans = max(ans, a[x] + a[y] + a[b] + a[c]);
          }
          ++ ct;
          if (ct >= 3)  break;
        }
        ++ cg;
        if (cg >= 3)  break;
      }
    }
  }
  cout << ans << "\n";
}
/*
7 9 0
1 1 1 2 3 4
1 2
2 3
3 4
1 5
1 6
1 7
5 4
6 4
7 4

7
*/
bool o2;
#define LOCAL_DEFINE
signed main () {
#ifdef LOCAL_DEFINE
//  cerr << "Memory used :" << (double) 1.0 * (&o1 - &o2) / 1024 / 1024 << ".Mib\n";
  freopen("holiday.in", "r", stdin);
  freopen("holiday.out", "w", stdout);
#endif
  ios :: sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int T = 1;
  while (T--)  solve();
#ifdef LOCAL_DEFINE
//  cerr << "Time used : " << 1.0 * clock() / CLOCKS_PER_SEC << ".s\n";
#endif
  return 0;
}

