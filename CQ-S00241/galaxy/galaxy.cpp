/* * 今天是 10 月 29 日
   * 是 枫原万叶 的生日
   * 生日快乐，万叶！
   * 跟所有的烦恼说拜拜，跟所有的快乐说嗨嗨（划掉
   * 同时，今天也是巫恋小姐和我们同机房的伙伴 JZB 的生日
   * 祝他们所有人生日快乐 XD
   */
#include <bits/stdc++.h>
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
void print(int x) {
	if (x < 0) {
		putchar('-');
		x = -x;
	}
	if (x >= 10)
		print(x / 10);
	putchar(x % 10 + '0');
	return;
}
inline void print(int x, char ch) {
	print(x);
	putchar(ch);
	return;
}
} // namespace fastIO
namespace XSC062 {
using namespace fastIO;
const int maxn = 1e3 + 5;
const int maxm = 1e4 + 5;
bool del[maxm];
int id[maxn][maxn];
int vis[maxn], p[maxn];
int n, m, q, x, y, t, tot, now;
std::vector<int> g[maxn], g2[maxn];
bool DFS(int x) {
	if (vis[x] == now || p[x] == tot) {
		p[x] = tot;
		return 1;
	}
	vis[x] = now;
	for (auto i : g[x]) {
		if (!del[id[x][i]] && DFS(i)) {
			p[x] = tot;
			return 1;
		}
	}
	return 0;
}
int main() {
	freopen("galaxy.in", "r", stdin);
	freopen("galaxy.out", "w", stdout);
	read(n), read(m);
	for (int i = 1; i <= m; ++i) {
		read(x), read(y);
		id[x][y] = i;
		g[x].push_back(y);
		g2[y].push_back(x);
	}
	read(q);
	while (q--) {
		read(t), read(x);
		if (t == 1) {
			read(y);
			del[id[x][y]] = 1;
		}
		else if (t == 2) {
			for (auto i : g2[x])
				del[id[i][x]] = 1;
		}
		else if (t == 3) {
			read(y);
			del[id[x][y]] = 0;
		}
		else {
			for (auto i : g2[x])
				del[id[i][x]] = 0;
		}
		++tot;
		for (int i = 1; i <= n; ++i) {
			int cnt = 0;
			for (auto j : g[i]) {
				if (!del[id[i][j]])
					++cnt;
			}
			++now;
			if (cnt != 1 || !DFS(i))
				goto NoSol;
		}
		puts("YES");
		continue;
		NoSol:
			puts("NO");
	}
	return 0;
}
} // namespace XSC062
int main() {
	XSC062::main();
	return 0;
}

