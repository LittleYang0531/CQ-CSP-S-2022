#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define debug(x) cerr << #x << "=" << x << endl
using namespace std;

namespace True_False {
	// gcd
	template <class T>
	T gcd(T x, T y) {
		if (!y) return x;
		return gcd(y, x % y);
	}
	// read
	template <class T>
	void read(T& x) {
		x = 0; static char ch; static bool some;
		some = 0;
		while ((ch = getchar()) < '0' || ch > '9') some = ch == '-';
		while (ch >= '0' && ch <= '9')
			x = (x << 3) + (x << 1) + (ch ^ 48), ch = getchar();
		if (some) x = -x;
	}
	template <class T, class... Args>
	void read(T& x, Args& ...args) { read(x), read(args...); }
	// write
	template <class T>
	void fwrite(T x) {
		if (x > 9) fwrite(x / 10);
		putchar(x % 10 + 48);
	}
	template <class T>
	void write(T x) {
		if (x < 0) putchar('-'), x = -x;
		fwrite(x);
	}
	void write(char x) { putchar(x); }
	template <class T, class... Args>
	void write(T x, Args ...args) { write(x), write(args...); }
}
using namespace True_False;

const int inf = 2505;

int n, m, k;
ll a[inf], ans;
vector<int> e[inf];
int road[inf][inf];
int maxn[inf][inf];

struct node { int pos, tot; };

queue<node> q;

void bfs(const int x) {
	while (!q.empty()) q.pop();
	q.push({x, 0});
	while (!q.empty()) {
		node t = q.front(); q.pop();
		if (~road[x][t.pos]) continue;
		road[x][t.pos] = t.tot;
		for (int i : e[t.pos]) q.push({i, t.tot + 1});
	}
	return;
}

inline bool cmp(int x, int y) {
	return a[x] > a[y];
}

void Update(int x, int y, int z, int w) {
	ans = max(ans, a[x] + a[y] + a[z] + a[w]);
}

int main() {
	freopen("holiday.in", "r", stdin);
	freopen("holiday.out", "w", stdout);
	memset(road, -1, sizeof road);
	read(n, m, k);
	for (int i = 2; i <= n; ++i) read(a[i]);
	for (int i = 1, u, v; i <= m; ++i) {
		read(u, v);
		e[u].push_back(v);
		e[v].push_back(u);
	}
	for (int i = 1; i <= n; ++i) bfs(i);
	for (int i = 2; i <= n; ++i) {
		for (int j = 2; j <= n; ++j) {
			if (i == j) continue;
			if (road[1][j] > k + 1) continue;
			if (road[j][i] > k + 1) continue;
			maxn[i][j] = j;
		}
		stable_sort(maxn[i] + 1, maxn[i] + 1 + n, cmp);
	}
	for (int i = 2; i <= n; ++i) {
		for (int j = 2; j <= n; ++j) {
			if (i == j || road[i][j] > k + 1) continue;
			for (int di = 1; di <= 3; ++di) {
				for (int dj = 1; dj <= 3; ++dj) {
					if (maxn[i][di] == j) continue;
					if (maxn[j][dj] == i) continue;
					if (maxn[i][di] == maxn[j][dj]) continue;
					if (!a[maxn[i][di]]) break;
					if (!a[maxn[j][dj]]) break;
					Update(i, j, maxn[i][di], maxn[j][dj]);
				}
			}
		}
	}
	write(ans);
	return 0;
}
