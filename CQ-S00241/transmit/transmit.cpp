/* * 今天是 10 月 29 日
   * 是 枫原万叶 的生日
   * 生日快乐，万叶！
   * 跟所有的烦恼说拜拜，跟所有的快乐说嗨嗨（划掉
   * 同时，今天也是巫恋小姐和我们同机房的伙伴 JZB 的生日
   * 祝他们所有人生日快乐 XD
   */

// 不知道为什么今年不想整活了
// 下周就是期中，奇人大赏做不做得了也只能看运气了
// 而且好像还答应过家长这次 CSP 打完了就 AFO 来着……？

 
// 但这些都不是最重要的！
// 现在只要专心把比赛打完（其实就是把分骗完），回了家写作文
// 然后 我现在就要看明日方舟：黎明前奏 :D b

#include <bits/stdc++.h>
#define int long long
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
#define mkp std::make_pair
using namespace fastIO;
const int inf = 1e18;
const int maxn = 2e3 + 5;
struct _ {
	int v, w;
	_() {}
	_(int v1, int w1) {
		v = v1, w = w1;
	}
};
int a[maxn];
bool vis[maxn];
int n, m, k, x, y;
int dis[maxn][maxn];
int dis2[maxn][maxn];
std::vector<_> g2[maxn];
std::vector<int> g[maxn];
std::priority_queue<std::pair<int, int> > q;
// 虽然但是
// 一个 Dij 可以养活两个暴力
// 两道题目可以带来 140 分收益
// 三吨重的 Nefelibata 可以在 GM 的注视下 kill me
// 四个考试科目可以让我想寄就寄
// 五个很押韵的句子请祝福我 1= 有戏
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
		if (dis[s][f] > k) // woc 为啥连这句都不用删啊 
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
inline void Dijk2(int s) {
	for (int i = 1; i <= n; ++i) {
		dis2[s][i] = inf;
		vis[i] = 0;
	}
	dis2[s][s] = 0;
	while (!q.empty())
		q.pop();
	q.push(mkp(0, s));
	while (!q.empty()) {
		int f = q.top().second;
		q.pop();
		if (vis[f])
			continue;
		vis[f] = 1;
		for (auto i : g2[f]) {
			if (dis2[s][i.v] > dis2[s][f] + i.w) {
				dis2[s][i.v] = dis2[s][f] + i.w;
				q.push(mkp(-dis2[s][i.v], i.v));
			}
		}
	}
	return;
}
inline void add(int x, int y) {
	g[x].push_back(y);
	return;
}
inline void add2(int x, int y, int w) {
	g2[x].push_back(_(y, w));
	return;
}
int main() {
	freopen("transmit.in", "r", stdin);
	freopen("transmit.out", "w", stdout);
	read(n), read(m), read(k);
	for (int i = 1; i <= n; ++i)
		read(a[i]);
	for (int i = 1; i < n; ++i) {
		read(x), read(y);
		add(x, y), add(y, x);
	}
	for (int i = 1; i <= n; ++i) {
		Dijk(i);
		for (int j = 1; j <= n; ++j) {
			if (i == j)
				continue;
			if (dis[i][j] <= k)
				add2(i, j, a[j]); // 甚至连这都不用改？？？ 
		}
	}
	for (int i = 1; i <= n; ++i)
		Dijk2(i);
	while (m--) {
		read(x), read(y);
		print(a[x] + dis2[x][y], '\n');
	}
	return 0;
}
} // namespace XSC062
// 拣尽寒枝不肯栖…… 
#undef int
int main() {
	XSC062::main();
	return 0;
}

