#include <bits/stdc++.h>
using namespace std;
#define il inline
#define mp make_pair
#define pb push_back
#define ptc putchar
#define R(i, l, r) for (int i = l; i <= r; ++i)
#define debug puts("---------------------------")
typedef pair <int, int> PII;
typedef long long ll;
namespace CYYH {
	template <typename T>
	il void read(T &x) {
		x = 0; T f = 1; char ch;
		while (!isdigit(ch = getchar())) f -= (ch == '-') << 1;
		while (isdigit(ch)) x = (x << 1) + (x << 3) + (ch & 15), ch = getchar(); x *= f;
	}
	template <typename T, typename ...L>
	il void read(T &x, L &...y) {read(x); read(y...);}
	template <typename T>
	il void write(T x) {
		if (x < 0) ptc('-'), x = -x;
		if (x > 9) write(x / 10);
		ptc(x % 10 + '0');
	}
	template <typename T, typename ...L>
	il void write(T x, L ...y) {write(x), ptc(' '); write(y...);}
}
using namespace CYYH;
#define int ll
const int N = 305;
int n, m, k, val[N], ans, cnt[N], dis[N][N];
vector <int> t[N];  // p[x] 表示i，j两点的合法公共点中的最大值
struct node {
	int x;
	bool operator < (const node &t) {
		return val[x] > val[t.x];
	}
	node(int X) {
		x = X;
	}
};
vector <node> p[N * N];
signed main() {
	freopen("holiday.in", "r", stdin);
	freopen("holiday.out", "w", stdout);
//	freopen("holiday4.in", "r", stdin);
	read(n, m, k); ++k;
	R(i, 2, n) read(val[i]);
	R(i, 1, n) {
		R(j, 1, n) {
			if (i == j) dis[i][j] = 0;
			else dis[i][j] = INT_MAX;
		}
	}
	int u, v;
	R(i, 1, m) {
		read(u, v);
		dis[u][v] = dis[v][u] = 1;
	}
	R(K, 1, n) {
		R(i, 1, n) {
			R(j, 1, n) {
				dis[i][j] = min(dis[i][K] + dis[K][j], dis[i][j]);
			}
		}
	}
	R(i, 1, n) {
		R(j, 1, n) {
//			cout << i << ' ' << j << ' ' << dis[i][j] << endl;
			if (i != j && dis[i][j] <= k) t[i].pb(j);
		}
	}
//	R(i, 1, n) {
//		cout << i << ": ";
//		for (auto v : t[i]) cout << v << ' ';
//		puts("");
//	}
	R(i, 1, n) {
		R(j, i + 1, n) {
//			memset(cnt, 0, sizeof cnt);
			int x = (i - 1) * n + j;
			for (auto v : t[i]) ++cnt[v];
			for (auto v : t[j]) ++cnt[v];
			R(i, 2, n) {
				if (cnt[i] == 2) {
					p[x].pb(node(i));
				}
				cnt[i] = 0;
			}
			sort(p[x].begin(), p[x].end());
//			cout << i << " " << j << ": ";
//			for (auto v:p[x]) cout << v.x << ' ';
//			puts("");
//			cout << i << ' ' << j << ' ' << p[x] << endl;
		}
	}
	for (auto t1 : t[1]) { // 枚举第一个点
		for (auto t2 : t[1]) { // 枚举第二个点
			if (t1 == t2) continue;
			for (auto t3 : t[t1]) {
				if (t3 == t1 || t3 == t2 || t3 == 1) continue;
				int x = (min(t2, t3) - 1) * n + max(t2, t3);
				for (int i = 0; i < p[x].size(); ++i) {
					int t4 = p[x][i].x;
					if (t4 == t3 || t4 == t2 || t4 == 1 || t4 == t1) continue;
					ans = max(ans, val[t1] + val[t2] + val[t3] + val[t4]);
					break;
				}
//				cout << t1 << ' ' << t2 << ' ' << t3 << ' ' << ans << endl;
			}
		}
	}
	write(ans);
	return 0;
}
