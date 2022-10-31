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

const int inf = 1e5 + 5;

struct Tree {
	int tree1[inf << 2], tree2[inf << 2], tree3[inf << 2], tree4[inf << 2], a[inf];
	void make_tree(int l, int r, int k) {
		if (l == r) {
			tree1[k] = tree2[k] = a[l];
			tree3[k] = 0x3f3f3f3f;
			tree4[k] = -0x3f3f3f3f;
			if (a[l] >= 0) tree3[k] = a[l];
			if (a[l] <= 0) tree4[k] = a[l];
			return;
		}
		int mid = l + r >> 1;
		make_tree(l, mid, k << 1);
		make_tree(mid + 1, r, k << 1 | 1);
		tree1[k] = max(tree1[k << 1], tree1[k << 1 | 1]);
		tree2[k] = min(tree2[k << 1], tree2[k << 1 | 1]);
		tree3[k] = 0x3f3f3f3f;
		if (tree3[k << 1] < 0 || tree3[k << 1 | 1] < 0) {
			if (tree3[k << 1] >= 0) tree3[k] = tree3[k << 1];
			if (tree3[k << 1 | 1] >= 0) tree3[k] = tree3[k << 1];
		} else tree3[k] = min(tree3[k << 1], tree3[k << 1 | 1]);
		tree4[k] = -0x3f3f3f3f;
		if (tree4[k << 1] > 0 || tree4[k << 1 | 1] > 0) {
			if (tree4[k << 1] <= 0) tree4[k] = tree4[k << 1];
			if (tree4[k << 1 | 1] <= 0) tree4[k] = tree4[k << 1];
		} else tree4[k] = max(tree4[k << 1], tree4[k << 1 | 1]);
	}
	int ask_max(int l, int r, int k, int al, int ar) {
		if (l >= al && r <= ar) return tree1[k];
		int mid = l + r >> 1, ans = -0x3f3f3f3f;
		if (mid >= al) ans = max(ans, ask_max(l, mid, k << 1, al, ar));
		if (mid < ar) ans = max(ans, ask_max(mid + 1, r, k << 1 | 1, al, ar));
		return ans;
	}
	int ask_min(int l, int r, int k, int al, int ar) {
		if (l >= al && r <= ar) return tree2[k];
		int mid = l + r >> 1, ans = 0x3f3f3f3f;
		if (mid >= al) ans = min(ans, ask_min(l, mid, k << 1, al, ar));
		if (mid < ar) ans = min(ans, ask_min(mid + 1, r, k << 1 | 1, al, ar));
		return ans;
	}
	int ask_near1(int l, int r, int k, int al, int ar) {
		if (l >= al && r <= ar) return tree3[k];
		int mid = l + r >> 1, ans = 0x3f3f3f3f;
		if (mid >= al) ans = min(ask_near1(l, mid, k << 1, al, ar), ans);
		if (mid < ar) ans = min(ask_near1(mid + 1, r, k << 1 | 1, al, ar), ans);
		return ans;
	}
	
	int ask_near2(int l, int r, int k, int al, int ar) {
		if (l >= al && r <= ar) return tree4[k];
		int mid = l + r >> 1, ans = -0x3f3f3f3f;
		if (mid >= al) ans = max(ask_near2(l, mid, k << 1, al, ar), ans);
		if (mid < ar) ans = max(ask_near2(mid + 1, r, k << 1 | 1, al, ar), ans);
		return ans;
	}
};

int n, m, q;
ll ans;
Tree A, B;

int main() {
	freopen("game.in", "r", stdin);
	freopen("game.out", "w", stdout);
	read(n, m, q);
	for (int i = 1; i <= n; ++i) read(A.a[i]);
	for (int i = 1; i <= m; ++i) read(B.a[i]);
	A.make_tree(1, n, 1), B.make_tree(1, m, 1);
	while (q--) {
		ans = LONG_LONG_MIN;
		int l1, r1, l2, r2;
		read(l1, r1, l2, r2);
		int Aa[4] = {}, Bb[4] = {};
		Aa[0] = A.ask_max(1, n, 1, l1, r1);
		Aa[1] = A.ask_min(1, n, 1, l1, r1);
		Aa[2] = A.ask_near1(1, n, 1, l1, r1);
		Aa[3] = A.ask_near2(1, n, 1, l1, r1);
		Bb[0] = B.ask_max(1, m, 1, l2, r2);
		Bb[1] = B.ask_min(1, m, 1, l2, r2);
		Bb[2] = B.ask_near1(1, m, 1, l2, r2);
		Bb[3] = B.ask_near2(1, m, 1, l2, r2);
		for (int i = 0; i < 4; ++i) {
			if (abs(Aa[i]) == 0x3f3f3f3f) continue;
			ll minn = LONG_LONG_MAX;
			for (int j = 0; j < 4; ++j) {
				if (abs(Bb[j]) == 0x3f3f3f3f) continue;
				minn = min(minn, (ll) Aa[i] * Bb[j]);
			}
			ans = max(ans, minn);
		}
		write(ans, '\n');
	}
	return 0;
}
