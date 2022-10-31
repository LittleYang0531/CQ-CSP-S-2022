// 德丽莎你好可爱德丽莎你好可爱德丽莎你好可爱德丽莎你好可爱德丽莎你好可爱
// 德丽莎的可爱在于德丽莎很可爱，德丽莎为什么很可爱呢？那是因为德丽莎很可爱！
// 没有力量的理想是空虚，没有理想的力量是戏言
#include <bits/stdc++.h>
#define int long long
using namespace std;
#define rep(i, l, r) for(int i = (l); i <= (r); i++)
#define repd(i, l, r) for(int i = (l); i >= (r); i--)
bool o1;
const int N = 2e6, inf = 1e16;
int n, q, k, a[N], num, nex[N], first[N], v[N];
void add(int from,int to) {
  nex[++num] = first[from];
  first[from] = num;
  v[num] = to;
}
int dep[N], siz[N], ff[N], son[N], top[N], dis[N];
void dfs(int x,int fa) {
  ff[x] = fa;
  siz[x] = 1;
  dep[x] = dep[fa] + 1;
  dis[x] = dis[fa] + a[x];
  for (int i = first[x]; i; i = nex[i]) {
    int to = v[i];
    if (to == fa)  continue;
    dfs(to, x);
    if (siz[to] > siz[son[x]])  son[x] = to;
    siz[x] += siz[to];
  }
}
void dfs2(int now,int x) {
  top[now] = x;
  if (son[now])  dfs2(son[now], x);
  for (int i = first[now]; i; i = nex[i]) {
    int to = v[i];
    if (to == ff[now] || to == son[now])  continue;
    dfs2(to, to);
  }
}
int LCA(int x,int y) {
  while (top[x] != top[y]) {
    if (dep[top[x]] <= dep[top[y]])  y = ff[top[y]];
    else  x = ff[top[x]];
  }
  return dep[x] < dep[y] ? x : y;
}
int b[N], cnt, dp[N];
namespace PITILESS {
  vector <int> ver[N];
  int cmp(int x,int y) {
    return a[x] < a[y];
  }
  int f[N], vis[N];
  int bd(int x,int y) {
    rep (i, 1, n)  f[i] = inf, vis[i] = 0;
    priority_queue < pair<int,int> > dq;
    f[x] = 0;
    dq.push({0, x});
    while (!dq.empty()) {
      int u = dq.top().second;
      dq.pop();
      if (vis[u])  continue;
      vis[u] = 1;
      for (auto to : ver[u]) {
        if (f[to] > f[u] + a[u]) {
          f[to] = f[u] + a[u];
          dq.push({-f[to], to});
        }
      }
    }
    return f[y] + a[y];
  }
  void work() {
    dfs(1, 0);
    dfs2(1, 1);
    rep (i, 1, n) {
      rep (j, 1, n) {
        if (i == j)  continue;
        int lca = LCA(i, j);
        int nowd = dep[i] + dep[j] - 2 * dep[lca];
        if (nowd <= k) {
          ver[i].push_back(j);
        }
      }
    }
    rep (i, 1, n)  sort(ver[i].begin(), ver[i].end(), cmp);
    rep (i, 1, q) {
      int x, y;
      cin >> x >> y;
      cout << bd(x, y) << "\n";
    }
  }
}
void solve() {
  cin >> n >> q >> k;
  rep (i, 1, n)  cin >> a[i];
  rep (i, 1, n - 1) {
    int a, b;
    cin >> a >> b;
    add(a, b);
    add(b, a);
  }
  if (k == 1) {
    dfs(1, 0);
    dfs2(1, 1);
    rep (i, 1, q) {
      int x, y;
      cin >> x >> y;
      int lca = LCA(x, y);
      int ans = dis[x] + dis[y] - dis[lca] * 2 + a[lca];
      cout << ans << "\n";
    }
    return;
  }
  if (n <= 2000 && q <= 2000) {
    if (k == 2) {
      dfs(1, 0);
      dfs2(1, 1);
      rep (i, 1, q) {
        int x, y;
        cin >> x >> y;
        int lca = LCA(x, y);
        int xx = x;
        while (xx != lca)  b[++cnt] = xx, xx = ff[xx];
        b[++cnt] = lca;
        int now = cnt;
        int yy = y;
        while (yy != lca)  b[++cnt] = yy, yy = ff[yy];      
        sort(b + now + 1, b + cnt + 1);
        rep (j, 1, cnt)  dp[j] = inf;
        dp[1] = 0; 
  //      rep (j, 1, cnt)  cout << b[j] << " ";
  //      cout << " :qwqw\n";
  //      rep (j, 1, cnt)  cout << a[b[j]] << " ";
  //      cout << ":QAQ\n";
        rep (j, 1, cnt - 1) 
          rep (t, 1, k) 
            dp[j + t] = min(dp[j + t], dp[j] + a[b[j]]);
        cout << dp[cnt] + a[b[cnt]] << "\n";
        cnt = 0;
      }
      return;
    }
    if (k == 3) {
      PITILESS :: work();
      return;
    }
    return;
  }
  if (k == 2) {
    dfs(1, 0);
    dfs2(1, 1);
    rep (i, 1, q) {
      int x, y;
      cin >> x >> y;
      int lca = LCA(x, y);
      int xx = x;
      while (xx != lca)  b[++cnt] = xx, xx = ff[xx];
      b[++cnt] = lca;
      int now = cnt;
      int yy = y;
      while (yy != lca)  b[++cnt] = yy, yy = ff[yy];      
      sort(b + now + 1, b + cnt + 1);
      rep (j, 1, cnt)  dp[j] = inf;
      dp[1] = 0; 
      rep (j, 1, cnt - 1) 
        rep (t, 1, k) 
          dp[j + t] = min(dp[j + t], dp[j] + a[b[j]]);
      cout << dp[cnt] + a[b[cnt]] << "\n";
      cnt = 0;
    }
    return;
  } else {
    PITILESS :: work();
    
  }
}
bool o2;
#define LOCAL_DEFINE
signed main () {
#ifdef LOCAL_DEFINE
//  cerr << "Memory used :" << (double) 1.0 * (&o1 - &o2) / 1024 / 1024 << ".Mib\n";
  freopen("transmit.in", "r", stdin);
  freopen("transmit.out", "w", stdout);
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

