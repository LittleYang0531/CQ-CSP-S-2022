#include<bits/stdc++.h>
using namespace std;
typedef long long van;
template<typename T> inline
void read(T& x) {
	T f = 1, b = 0; char ch = getchar();
	while (!isdigit(ch)) {
		if (ch == '-') f = -1;
		ch = getchar();
	} while (isdigit(ch))
		b *= 10, b += ch - '0', ch = getchar();
	x = f * b; return;
}
template<typename T> inline
void print(T x, int jz = 10) {
	if (x == 0) return putchar('0'), void();
	if (x < 0) putchar('-'), x = -x;
	van st[129] = {0}, k = 0;
	while (x) st[++k] = x % jz, x /= jz;
	for (int i = k; i; i--) putchar(st[i] + '0');
} const van MaxN = 1e5 + 10;
van n, m, q;
van A[MaxN], B[MaxN];
struct SGT {
	van dat[MaxN << 2];
	// 0 => min, 1 => max
	void BuildTree(van* a, bool t, van p, van l, van r) {
		bool type = t; 
		if (l == r) return dat[p] = a[l], void();
		van mid = (l + r) >> 1;
		BuildTree(a, t, p * 2, l, mid);
		BuildTree(a, t, p * 2 + 1, mid + 1, r);
		dat[p] = type ? max(dat[p * 2], dat[p * 2 + 1]) : min(dat[p * 2], dat[p * 2 + 1]);
	}
	van QueryTree(van L, van R, bool t, van p, van l, van r) {
		if (L <= l && r <= R) return dat[p];
		van mid = (l + r) >> 1, ans = t ? -1e18 : 1e18;
		if (L <= mid) {
			van val = QueryTree(L, R, t, p * 2, l, mid);
			ans = t ? max(ans, val) : min(ans, val);
		}
		if (R > mid) {
			van val = QueryTree(L, R, t, p * 2 + 1, mid + 1, r);
			ans = t ? max(ans, val) : min(ans, val);
		}
		return ans;
	}
}T[2][3][2]; // 数组, 正负性, 性质 
van tmp[MaxN];
van val[2][3][2];
int main() {
	freopen("game.in", "r", stdin);
	freopen("game.out", "w", stdout);
	read(n), read(m), read(q);
	for (int i = 1; i <= n; i++) read(A[i]);
	for (int i = 1; i <= m; i++) read(B[i]);
	for (int i = 1; i <= n; i++) tmp[i] = A[i] > 0 ? A[i] : 1e18;
	T[0][0][0].BuildTree(tmp, 0, 1, 1, n);
	for (int i = 1; i <= n; i++) tmp[i] = A[i] > 0 ? A[i] : -1e18;
	T[0][0][1].BuildTree(tmp, 1, 1, 1, n);
	for (int i = 1; i <= n; i++) tmp[i] = A[i] == 0 ? A[i] : 1e18;
	T[0][1][0].BuildTree(tmp, 0, 1, 1, n);
	for (int i = 1; i <= n; i++) tmp[i] = A[i] < 0 ? A[i] : 1e18;
	T[0][2][0].BuildTree(tmp, 0, 1, 1, n);
	for (int i = 1; i <= n; i++) tmp[i] = A[i] < 0 ? A[i] : -1e18;
	T[0][2][1].BuildTree(tmp, 1, 1, 1, n);
	for (int i = 1; i <= m; i++) tmp[i] = B[i] > 0 ? B[i] : 1e18;
	T[1][0][0].BuildTree(tmp, 0, 1, 1, m);
	for (int i = 1; i <= m; i++) tmp[i] = B[i] > 0 ? B[i] : -1e18;
	T[1][0][1].BuildTree(tmp, 1, 1, 1, m);
	for (int i = 1; i <= m; i++) tmp[i] = B[i] == 0 ? B[i] : 1e18;
	T[1][1][0].BuildTree(tmp, 0, 1, 1, m);
	for (int i = 1; i <= m; i++) tmp[i] = B[i] < 0 ? B[i] : 1e18;
	T[1][2][0].BuildTree(tmp, 0, 1, 1, m);
	for (int i = 1; i <= m; i++) tmp[i] = B[i] < 0 ? B[i] : -1e18;
	T[1][2][1].BuildTree(tmp, 1, 1, 1, m);
	for (int i = 1; i <= q; i++) {
		van l1, r1, l2, r2; 
		read(l1), read(r1), read(l2), read(r2);
		van ans = -1e18;
		for (int k = 0; k < 3; k++) for (int l = 0; l < 2; l++)
			val[0][k][l] = T[0][k][l].QueryTree(l1, r1, l, 1, 1, n);
		for (int k = 0; k < 3; k++) for (int l = 0; l < 2; l++)
			val[1][k][l] = T[1][k][l].QueryTree(l2, r2, l, 1, 1, m);
//		for (int j = 0; j < 2; j++) {
//			for (int k = 0; k < 3; k++) {
//				for (int l = 0; l < 2; l++) cout << j << " " << k << " " << l << " " << val[j][k][l] << endl;			}
//		}
		// 如果自己有+的物品 
		if (val[0][0][0] != 1e18) {
			// 对方有-就拿+的最小值
			if (val[1][2][0] != 1e18) ans = max(ans, val[0][0][0] * val[1][2][0]);
			else if (val[1][1][0] != 1e18) ans = max(ans, 0ll); 
			else ans = max(ans, val[0][0][1] * val[1][0][0]);
		} 
		if (val[0][1][0] != 1e18) ans = max(ans, 0ll);
		if (val[0][2][0] != 1e18) {
			// 对方有+就拿-的最大值
			if (val[1][0][0] != 1e18) ans = max(ans, val[0][2][1] * val[1][0][1]); 
			else if (val[1][1][0] != 1e18) ans = max(ans, 0ll);
			else ans = max(ans, val[0][2][0] * val[1][2][1]);
		}
		print(ans), putchar('\n');
	}
	return 0;
}

