// 德丽莎你好可爱德丽莎你好可爱德丽莎你好可爱德丽莎你好可爱德丽莎你好可爱
// 德丽莎的可爱在于德丽莎很可爱，德丽莎为什么很可爱呢？那是因为德丽莎很可爱！
// 没有力量的理想是空虚，没有理想的力量是戏言
#include <bits/stdc++.h>
using namespace std;
#define rep(i, l, r) for(int i = (l); i <= (r); i++)
#define repd(i, l, r) for(int i = (l); i >= (r); i--)
bool o1;
const int N = 2e6;
int q, n, m, nex[N], first[N], v[N], num;
map < pair<int,int>, int> mp;
void add(int from,int to) {
  nex[++num] = first[from];
  first[from] = num;
  v[num] = to;
}
vector <int> ver[N];
int out[N], to[N], pos[N];
vector <int> qwq;
void solve() {
  cin >> n >> m;
  rep (i, 1, m) {
    int u, v;
    cin >> u >> v;
    mp[{u, v}] = 1;
    add(u, v);    
    ver[v].push_back(u);
    out[u] ++;
  }
  cin >> q;
  if (n <= 1000 && q <= 1000) {
    rep (i, 1, q) {
      int op;
      cin >> op;
      if (op == 1) {
        int u, v;
        cin >> u >> v;
        mp[{u, v}] = -1;
      } else if (op == 2) {
        int u;
        cin >> u;
        for (auto v : ver[u]) {
          mp[{v, u}] = -1;
        }
      } else if (op == 3) {
        int u, v;
        cin >> u >> v;
        mp[{u, v}] = 1;
      } else if (op == 4) {
        int u;
        cin >> u;
        for (auto v : ver[u]) {
          mp[{v, u}] = 1;
        }
      }
      int cnt = 0;
      rep (j, 1, n) {
        int now = 0;
        for (int k = first[j]; k; k = nex[k]) {
          int To = v[k];
          if (mp[{j, To}] == -1)  continue;
          ++now;
          to[j] = To;
          if (now > 1) {
            cnt = 1;
            break;
          }
        }
        if (now == 0)  cnt = 1;
        if (cnt == 1)  break;
        pos[j] = 0;
      }
      if (cnt != 0) {
        cout << "NO\n";
      } else {
        rep (j, 1, n) {
          for (int k = first[j]; k; k = nex[k]) {
            int To = v[k];
            if (mp[{j, To}] == -1)  continue;
            to[j] = To;
          }
          pos[j] = 0;
        }
        int ct = 0, fl = 0;
        rep (j, 1, n) {
          if (pos[j])  continue;
          int now = j;
          int gg = 0;
          ++ct;
          while (1) {
            if (pos[now] != 0)  break;
            pos[now] = ct;
            now = to[now];
            if (to[now] == 0) {  gg = 1;  break;  }
          }
          if (gg) {
            fl = 1;
            break;
          }
        }
        if (fl)  cout << "NO\n";
        else  cout << "YES\n";
      }
    }
    return;
  } else {
    int wa = 0;
    rep (i, 1, n) {
      if (out[i] != 1)  wa ++;
    }
    rep (i, 1, q) {
      int op;
      cin >> op;
      if (op == 1) {
        int u, v;
        cin >> u >> v;
        if (out[u] == 1)  wa ++;
        out[u] -- ;
        mp[{u, v}] = -1;
        if (out[u] == 1)  wa --;
      } else if (op == 2) {
        int u;
        cin >> u;
        for (auto v : ver[u]) {
          if (out[v] == 1)  wa ++;
          out[v] --;
          mp[{v, u}] = -1;
          if (out[v] == 1)  wa --;
        }
      } else if (op == 3) {
        int u, v;
        cin >> u >> v;
        if (out[u] == 1)  wa ++;
        mp[{u, v}] = 1;
        out[u] ++;
        if (out[u] == 1)  wa --;
      } else if (op == 4) {
        int u;
        cin >> u;
        for (auto v : ver[u]) {
          if (out[v] == 1)  wa ++;
          mp[{v, u}] = 1;
          out[v] ++;
          if (out[v] == 1)  wa --;
        }
      }
      if (wa != 0) {
        cout << "NO\n";
        continue;
      }
      int cnt = 0;
      rep (j, 1, n) {
        int now = 0;
        for (int k = first[j]; k; k = nex[k]) {
          int To = v[k];
          if (mp[{j, To}] == -1)  continue;
          ++now;
          to[j] = To;
          if (now > 1) {
            cnt = 1;
            break;
          }
        }
        if (now == 0)  cnt = 1;
        if (cnt == 1)  break;
        pos[j] = 0;
      }
      if (cnt != 0) {
        cout << "NO\n";
      } else {
        rep (j, 1, n) {
          for (int k = first[j]; k; k = nex[k]) {
            int To = v[k];
            if (mp[{j, To}] == -1)  continue;
            to[j] = To;
          }
          pos[j] = 0;
        }
        int ct = 0, fl = 0;
        rep (j, 1, n) {
          if (pos[j])  continue;
          int now = j;
          int gg = 0;
          ++ct;
          while (1) {
            if (pos[now] != 0)  break;
            pos[now] = ct;
            now = to[now];
            if (to[now] == 0) {  gg = 1;  break;  }
          }
          if (gg) {
            fl = 1;
            break;
          }
        }
        if (fl)  cout << "NO\n";
        else  cout << "YES\n";
      }
    }
  }
}
bool o2;
#define LOCAL_DEFINE
signed main () {
#ifdef LOCAL_DEFINE
//  cerr << "Memory used :" << (double) 1.0 * (&o1 - &o2) / 1024 / 1024 << ".Mib\n";
  freopen("galaxy.in", "r", stdin);
  freopen("galaxy.out", "w", stdout);
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

