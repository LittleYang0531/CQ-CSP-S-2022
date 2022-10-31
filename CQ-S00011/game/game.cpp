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
const int N = 1e5 + 5;
int n, m, q, a[N], b[N];
struct segment_tree {
	int mx[N << 2], mi[N << 2];
	void build(int l, int r, int id) {
		mi[id] = INT_MAX;
		mx[id] = INT_MIN;
		if (l == r) return ;
		int mid = l + r >> 1;
		build(l, mid, id << 1), build(mid + 1, r, id << 1 | 1);
	}
	void insert(int l, int r, int x, int k, int id) {
		if (l == r) {return mx[id] = k, mi[id] = k, void();}
		int mid = l + r >> 1;
		if (x <= mid) insert(l, mid, x, k, id << 1);
		else insert(mid + 1, r, x, k, id << 1 | 1);
		mx[id] = max(mx[id << 1], mx[id << 1 | 1]);
		mi[id] = min(mi[id << 1], mi[id << 1 | 1]);
//		cout << l << ' ' << r << ' ' << mi[id] << endl;
	}
	int query_max(int l, int r, int x, int y, int id) {
		if (l > y || r < x) return INT_MIN;
//		cout << l << ' ' << r << ' ' << mx[id] << endl;
		if (l >= x && r <= y) return mx[id];
		int mid = l + r >> 1;
		return max(query_max(l, mid, x, y, id << 1), query_max(mid + 1, r, x, y, id << 1 | 1));
	}
	int query_min(int l, int r, int x, int y, int id) {
		if (l > y || r < x) return INT_MAX;
//		cout << l << ' ' << r << ' ' << mi[id] << endl;
		if (l >= x && r <= y) return mi[id];
		int mid = l + r >> 1;
		return min(query_min(l, mid, x, y, id << 1), query_min(mid + 1, r, x, y, id << 1 | 1));
	}
} zhengjia, fujia, zhengyi, fuyi;
signed main() {
	freopen("game.in", "r", stdin);
	freopen("game.out", "w", stdout);
//	freopen("game4.in", "r", stdin);
//	freopen("my1.out", "w", stdout);
	read(n, m, q);
	zhengjia.build(1, n, 1), fujia.build(1, n, 1), zhengyi.build(1, m, 1), fuyi.build(1, m, 1);
	R(i, 1, n) {
		read(a[i]);
		if (a[i] >= 0) zhengjia.insert(1, n, i, a[i], 1);
		else fujia.insert(1, n, i, a[i], 1);
//	cout << fujia.query_min(1, n, 1, n, 1) << endl;
//		if (i == 2) return 0;
	}
	R(i, 1, m) {
		read(b[i]);
		if (b[i] >= 0) zhengyi.insert(1, m, i, b[i], 1);
		else fuyi.insert(1, m, i, b[i], 1);
	}
	/*
	1.甲只有正数 乙只有正数：max正甲乘min正乙
	2.甲只有负数 乙只有正数：max负甲乘max正乙
	3.甲只有正数 乙只有负数：min正甲乘min负乙
	4.甲只有负数 乙只有负数：min负甲乘max负乙
	5.甲有正数，负数 乙只有正数：max正甲乘min正乙
	6.甲有只正数 乙有正数，负数：min正甲乘min负乙
	7.甲有正负数 乙有正负数：max(min正甲乘min负乙,max负甲乘max正乙)
	*/
//	cout << fujia.query_min(1, n, 1, n, 1) << endl;
//	return 0;
//	int line = 0;
	while (q--) {
//		++line;
		int l1, r1, l2, r2;
		read(l1, r1, l2, r2);
//		if (line != 256) continue;
		int maxzj = zhengjia.query_max(1, n, l1, r1, 1), maxfj = fujia.query_max(1, n, l1, r1, 1), maxzy = zhengyi.query_max(1, m, l2, r2, 1), maxfy = fuyi.query_max(1, m, l2, r2, 1);
		int minzj = zhengjia.query_min(1, n, l1, r1, 1), minfj = fujia.query_min(1, n, l1, r1, 1), minzy = zhengyi.query_min(1, m, l2, r2, 1), minfy = fuyi.query_min(1, m, l2, r2, 1);
//		cout << maxzj << ' ' << minfj << ' ' << maxzy << ' ' << minfy << endl; 
		if (maxzj != INT_MIN && minfj == INT_MAX) { // 甲只有正数
			if (maxzy != INT_MIN && minfy == INT_MAX) { // 乙只有正数
				write(maxzj * minzy);
			}
			else if (maxzy == INT_MIN && minfy != INT_MAX) { // 乙只有负数
//				cout << maxfj << endl;
				write(minzj * minfy);
			}
			else if (maxzy != INT_MIN && minfy != INT_MAX) { // 乙都有
				write(minzj * minfy);
			}
		}
		else if (maxzj == INT_MIN && minfj != INT_MAX) { // 甲只有负数
			if (maxzy != INT_MIN && minfy == INT_MAX) { // 乙只有正数
				write(maxfj * maxzy);
			}
			else if (maxzy == INT_MIN && minfy != INT_MAX) { // 乙只有负数
				write(minfj * maxfy);
			}
			else if (maxzy != INT_MIN && minfy != INT_MAX) { // 乙都有
				write(maxfj * maxzy);
			}
		} 
		else if (maxzj != INT_MIN && minfj != INT_MIN) { // 甲都有
			if (maxzy != INT_MIN && minfy == INT_MAX) { // 乙只有正数
				write(maxzj * minzy);
			}
			else if (maxzy == INT_MIN && minfy != INT_MAX) { // 乙只有负数
				write(minfj * maxfy);
			}
			else if (maxzy != INT_MIN && minfy != INT_MAX) { // 乙都有
//				debug;
//				cout << minzj << ' ' << minfy << ' ' << maxfj << ' ' << maxzy << endl;
				write(max(minzj * minfy, maxfj * maxzy));
			}
		}
		ptc('\n');
//		return 0;
	}
	return 0;
}

