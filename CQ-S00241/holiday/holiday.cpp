/* * 今天是 10 月 29 日
   * 是 枫原万叶 的生日
   * 生日快乐，万叶！
   * 跟所有的烦恼说拜拜，跟所有的快乐说嗨嗨（划掉
   * 同时，今天也是巫恋小姐和我们同机房的伙伴 JZB 的生日
   * 祝他们所有人生日快乐 XD
   */
#include <bits/stdc++.h>
using ll = __int128;
// 完了
// 我 J 组 T2 输出没开 long long
// 哦哦原来我 #define int long long 了啊
// 那没事了 
namespace fastIO {
const int LEN = (1 << 20);
inline int nec(void) {
	static char buf[LEN], *p = buf, *e = buf;
	if (p == e) {
		e = buf + fread(buf, 1, LEN, stdin);
		if (e == buf)
			return EOF;
		p = buf;
	}
	return *p++;
}
inline bool read(int &x) {
	x = 0;
	bool f = 0;
	char ch = nec();
	while (ch < '0' || ch > '9') {
		if (ch == EOF)
			return 0;
		if (ch == '-')
			f = 1;
		ch = nec();
	}
	while (ch >= '0' && ch <= '9') {
		x = x * 10 + ch - '0';
		ch = nec();
	}
	if (f)
		x = -x;
	return 1;
}
inline bool read(ll &x) {
	x = 0;
	bool f = 0;
	char ch = nec();
	while (ch < '0' || ch > '9') {
		if (ch == EOF)
			return 0;
		if (ch == '-')
			f = 1;
		ch = nec();
	}
	while (ch >= '0' && ch <= '9') {
		x = x * 10 + ch - '0';
		ch = nec();
	}
	if (f)
		x = -x;
	return 1;
}
void print(ll x) {
	if (x < 0) {
		putchar('-');
		x = -x;
	}
	if (x >= 10)
		print(x / 10);
	putchar(x % 10 + '0');
	return;
}
inline void print(ll x, char ch) {
	print(x);
	putchar(ch);
	return;
}
} // namespace fastIO
namespace XSC062 {
#define mkp std::make_pair
using namespace fastIO;
const int maxn = 2505;
const ll infty = 1e20;
const int inf = 0x3f3f3f3f;
ll a[maxn];
bool vis[maxn];
bool r[maxn][7];
int n, m, k, x, y;
int dis[maxn][maxn];
std::vector<int> g[maxn], g2[maxn];
std::priority_queue<std::pair<int, int> > q;
// 隔壁的同志好像正在因为键盘不好使而暴躁
// 然后开始 哐 哐 哐 的锤键盘（（（ 
inline void Dijk(int s) {
	for (int i = 1; i <= n; ++i) {
		dis[s][i] = inf;
		vis[i] = 0;
	}
	dis[s][s] = 0;
	while (!q.empty())
		q.pop();
	q.push(mkp(0, s));
	while (!q.empty()) {
		int f = q.top().second;
		q.pop();
		if (vis[f])
			continue;
		vis[f] = 1;
		if (dis[s][f] > k)
			break;
		for (auto i : g[f]) {
			if (dis[s][i] > dis[s][f] + 1) {
				dis[s][i] = dis[s][f] + 1;
				q.push(mkp(-dis[s][i], i));
			}
		}
	}
	return;
}
inline void add(int x, int y) {
	g[x].push_back(y);
	return;
}
inline void add2(int x, int y) {
	g2[x].push_back(y);
	return;
}
inline ll max(ll x, ll y) {
	return x > y ? x : y;
}
// 摆 
ll DFS(int x, int u) {
	ll res = -infty;
	if (u == 5)
		return dis[x][1] <= k ? a[x] : -infty;
	if (!r[x][6 - u])
		return -infty;
	for (auto i : g2[x]) {
		if (vis[i])
			continue;
		vis[i] = 1;
		res = max(res, DFS(i, u + 1));
		vis[i] = 0;
	}
	return res + a[x];
}
int main() {
	freopen("holiday.in", "r", stdin);
	freopen("holiday.out", "w", stdout);
	read(n), read(m), read(k);
	++k;
	for (int i = 2; i <= n; ++i)
		read(a[i]);
	while (m--) {
		read(x), read(y);
		add(x, y), add(y, x);
	}
	for (int i = 1; i <= n; ++i) {
		Dijk(i);
		if (dis[i][1] <= k)
			r[i][1] = 1;
		for (int j = 2; j <= n; ++j) {
			if (dis[i][j] <= k)
				add2(i, j);
		}
	}
	for (int i = 2; i <= 5; ++i) {
		for (int j = 1; j <= n; ++j) {
			for (int l = 1; l <= n; ++l) {
				if (dis[j][l] <= k && r[l][i - 1]) {
					r[j][i] = 1;
					break;
				}
			}
		}
	}
	memset(vis, 0, sizeof (vis));
	print(DFS(1, 1));
	return 0;
}
} // namespace XSC062
int main() {
	XSC062::main();
	return 0;
}

