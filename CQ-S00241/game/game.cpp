/* * 今天是 10 月 29 日
   * 是 枫原万叶 的生日
   * 生日快乐，万叶！
   * 跟所有的烦恼说拜拜，跟所有的快乐说嗨嗨（划掉
   * 同时，今天也是巫恋小姐和我们同机房的伙伴 JZB 的生日
   * 祝他们所有人生日快乐 XD
   */
#include <bits/stdc++.h>
using ll = long long;
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
// 这，，？？？ 
using namespace fastIO;
const int maxm = 19;
const int inf = 2e9;
const int maxn = 1e5 + 5;
int cnt[maxn];
int t[maxn][maxm][2];
int f[2][maxn][maxm][2];
int n, m, q, l1, r1, l2, r2, k;
int al, ar, bl, br, a0, tal, tar, tbl, tbr;
inline int min(int x, int y) {
	return x < y ? x : y;
}
inline ll max(ll x, ll y) {
	return x > y ? x : y;
}
inline bool lef(int l, int r) {
	return r < 0;
} 
inline bool mid(int l, int r) {
	return l < 0 && r >= 0;
}
inline bool rig(int l, int r) {
	return l >= 0;
}
int main() {
	freopen("game.in", "r", stdin);
	freopen("game.out", "w", stdout);
	read(n), read(m), read(q);
	for (int i = 1; i <= n; ++i) {
		read(f[0][i][0][0]);
		f[0][i][0][1] = f[0][i][0][0];
		cnt[i] = cnt[i - 1] + (f[0][i][0][0] == 0);
		if (f[0][i][0][0] > 0) {
			t[i][0][0] = f[0][i][0][0];
			t[i][0][1] = -inf;
		}
		else if (f[0][i][0][0] < 0) {
			t[i][0][1] = f[0][i][0][0];
			t[i][0][0] = inf;
		}
		else t[i][0][0] = inf, t[i][0][1] = inf;
	}
	for (int i = 1; i <= m; ++i) {
		read(f[1][i][0][0]);
		f[1][i][0][1] = f[1][i][0][0];
	}
	for (int j = 1; (1 << j) <= n; ++j) {
		for (int i = 1; i + (1 << j) - 1 <= n; ++i) {
			f[0][i][j][0] = min(f[0][i][j - 1][0],
								f[0][i + (1 << (j - 1))]
												[j - 1][0]);
			t[i][j][0] = min(t[i][j - 1][0],
								t[i + (1 << (j - 1))]
												[j - 1][0]);
			f[0][i][j][1] = max(f[0][i][j - 1][1],
								f[0][i + (1 << (j - 1))]
												[j - 1][1]);
			t[i][j][1] = max(t[i][j - 1][1],
								t[i + (1 << (j - 1))]
												[j - 1][1]);
		}
	}
	for (int j = 1; (1 << j) <= m; ++j) {
		for (int i = 1; i + (1 << j) - 1 <= m; ++i) {
			f[1][i][j][0] = min(f[1][i][j - 1][0],
								f[1][i + (1 << (j - 1))]
												[j - 1][0]);
			f[1][i][j][1] = max(f[1][i][j - 1][1],
								f[1][i + (1 << (j - 1))]
												[j - 1][1]);
		}
	}
	while (q--) {
		read(l1), read(r1);
		read(l2), read(r2);
		k = log(r1 - l1 + 1.0) / log(2.0);
		al = min(f[0][l1][k][0],
						f[0][r1 - (1 << k) + 1][k][0]);
		ar = max(f[0][l1][k][1],
						f[0][r1 - (1 << k) + 1][k][1]);
		k = log(r2 - l2 + 1.0) / log(2.0);
		bl = min(f[1][l2][k][0],
						f[1][r2 - (1 << k) + 1][k][0]);
		br = max(f[1][l2][k][1],
						f[1][r2 - (1 << k) + 1][k][1]);
		a0 = cnt[r1] - cnt[l1 - 1];
		if (mid(al, ar) && mid(bl, br)) {
			// 如果是可以避免的战斗…… 
			if (a0) print(0, '\n');
			// 那就保持沉默。
			else {
				k = log(r1 - l1 + 1.0) / log(2.0);
				tal = min(t[l1][k][0],
								t[r1 - (1 << k) + 1][k][0]);
				tar = max(t[l1][k][1],
								t[r1 - (1 << k) + 1][k][1]);
				k = log(r2 - l2 + 1.0) / log(2.0);
				print(max((1ll * tal) * bl,
							(1ll * tar) * br), '\n');
			}
		}
		else if (lef(al, ar) && mid(bl, br))
			print((1ll * ar) * br, '\n');
		else if (rig(al, ar) && mid(bl, br))
			print((1ll * al) * bl, '\n');
		else if (mid(al, ar) && lef(bl, br))
			print((1ll * al) * br, '\n');
		else if (lef(al, ar) && lef(bl, br))
			print((1ll * al) * br, '\n');
		else if (rig(al, ar) && lef(bl, br))
			print((1ll * al) * bl, '\n');
		else if (mid(al, ar) && rig(bl, br))
			print((1ll * ar) * bl, '\n');
		else if (lef(al, ar) && rig(bl, br))
			print((1ll * ar) * br, '\n');
		else print((1ll * ar) * bl, '\n');
	}
	return 0;
}
} // namespace XSC062
int main() {
	XSC062::main();
	return 0;
}

