#include <bits/stdc++.h>

#define int long long

const int N = 2e5 + 101;

int a[N], b[N];

int sum1z[N], sum1f[N], sum2z[N], sum2f[N];
int f1z_mx[N][25], f1z_mi[N][25], f1f_mx[N][25], f1f_mi[N][25];
int f2z_mx[N][25], f2z_mi[N][25], f2f_mx[N][25], f2f_mi[N][25];

int z1_mx(int l, int r) {
	int m = log2(r - l + 1);
	return std::max(f1z_mx[l][m], f1z_mx[r - (1 << m) + 1][m]);
}
int z1_mi(int l, int r) {
	int m = log2(r - l + 1);
	return std::min(f1z_mi[l][m], f1z_mi[r - (1 << m) + 1][m]);
}
int f1_mx(int l, int r) {
	int m = log2(r - l + 1);
	return std::max(f1f_mx[l][m], f1f_mx[r - (1 << m) + 1][m]);
}
int f1_mi(int l, int r) {
	int m = log2(r - l + 1);
	return std::min(f1f_mi[l][m], f1f_mi[r - (1 << m) + 1][m]);
}
int z2_mx(int l, int r) {
	int m = log2(r - l + 1);
	return std::max(f2z_mx[l][m], f2z_mx[r - (1 << m) + 1][m]);
}
int z2_mi(int l, int r) {
	int m = log2(r - l + 1);
	return std::min(f2z_mi[l][m], f2z_mi[r - (1 << m) + 1][m]);
}
int f2_mx(int l, int r) {
	int m = log2(r - l + 1);
	return std::max(f2f_mx[l][m], f2f_mx[r - (1 << m) + 1][m]);
}
int f2_mi(int l, int r) {
	int m = log2(r - l + 1);
	return std::min(f2f_mi[l][m], f2f_mi[r - (1 << m) + 1][m]);
}


signed main() {
	freopen("game.in", "r", stdin);
	freopen("game.out", "w", stdout);
	
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	
	int n, m, q;
	std::cin >> n >> m >> q;
	for (int i = 1; i <= n; ++i) std::cin >> a[i];
	for (int i = 1; i <= m; ++i) std::cin >> b[i];
	for (int i = 1; i <= n; ++i) {
		sum1z[i] += sum1z[i - 1] + (a[i] > 0);	// 正数量 
		sum1f[i] += sum1f[i - 1] + (a[i] < 0);	// 负数量 
		
		f1z_mx[i][0] = 0, f1z_mi[i][0] = 1e9 + 1;
		f1f_mx[i][0] = -1e9 - 1, f1f_mi[i][0] = 0;
		
		if (a[i] > 0) f1z_mx[i][0] = f1z_mi[i][0] = a[i];	// 正倍增 
		if (a[i] < 0) f1f_mx[i][0] = f1f_mi[i][0] = a[i];	// 负倍增 
	}
	for (int i = 1; i <= m; ++i) {
		sum2z[i] += sum2z[i - 1] + (b[i] > 0);
		sum2f[i] += sum2f[i - 1] + (b[i] < 0);
		
		f2z_mx[i][0] = 0, f2z_mi[i][0] = 1e9 + 1;
		f2f_mx[i][0] = -1e9 - 1, f2f_mi[i][0] = 0;
		
		if (b[i] > 0) f2z_mx[i][0] = f2z_mi[i][0] = b[i];
		if (b[i] < 0) f2f_mx[i][0] = f2f_mi[i][0] = b[i];
	}
	for (int i = 1; i <= 22; ++i) {
		for (int j = 1; j + (1 << i) - 1 <= n; ++j) {
			f1z_mx[j][i] = std::max(f1z_mx[j][i - 1], f1z_mx[j + (1 << (i - 1))][i - 1]);
			f1z_mi[j][i] = std::min(f1z_mi[j][i - 1], f1z_mi[j + (1 << (i - 1))][i - 1]);
			f1f_mx[j][i] = std::max(f1f_mx[j][i - 1], f1f_mx[j + (1 << (i - 1))][i - 1]);
			f1f_mi[j][i] = std::min(f1f_mi[j][i - 1], f1f_mi[j + (1 << (i - 1))][i - 1]);
		}
	}
	for (int i = 1; i <= 22; ++i) {
		for (int j = 1; j + (1 << i) - 1 <= m; ++j) {
			f2z_mx[j][i] = std::max(f2z_mx[j][i - 1], f2z_mx[j + (1 << (i - 1))][i - 1]);
			f2z_mi[j][i] = std::min(f2z_mi[j][i - 1], f2z_mi[j + (1 << (i - 1))][i - 1]);
			f2f_mx[j][i] = std::max(f2f_mx[j][i - 1], f2f_mx[j + (1 << (i - 1))][i - 1]);
			f2f_mi[j][i] = std::min(f2f_mi[j][i - 1], f2f_mi[j + (1 << (i - 1))][i - 1]);
		}
	}
	
	while (q--) {
		int l1, r1, l2, r2, ans; std::cin >> l1 >> r1 >> l2 >> r2;
		int z = sum2z[r2] - sum2z[l2 - 1], f = sum2f[r2] - sum2f[l2 - 1], len = r2 - l2 + 1;
		int x = sum1z[r1] - sum1z[l1 - 1], y = sum1f[r1] - sum1f[l1 - 1], siz = r1 - l1 + 1;
		if (z == len) {
			//std::cout << "1 ";
			if (x != 0) {
				ans = z1_mx(l1, r1) * z2_mi(l2, r2); std::cout << ans << '\n';
			}
			else if (x + y != siz) std::cout << "0\n";
			else {
				ans = f1_mx(l1, r1) * z2_mx(l2, r2); std::cout << ans << '\n';
			} 
		}
		else if (f == len) {
			//std::cout << "2 ";
			if (y != 0) {
				ans = f1_mi(l1, r1) * f2_mx(l2, r2); std::cout << ans << '\n';
			}
			else if (x + y != siz) std::cout << "0\n";
			else {
				ans = z1_mi(l1, r1) * f2_mi(l2, r2); std::cout << ans << '\n';
			}
		}
		else if (z + f == 0) std::cout << "0\n";
		else if (z != 0 && f != 0) {
			//std::cout << "4 ";
			if (x + y != siz) std::cout << "0\n";
			else {
				ans = std::max(z1_mi(l1, r1) * f2_mi(l2, r2), f1_mx(l1, r1) * z2_mx(l2, r2));
				std::cout << ans << '\n';
			}
		}
		else if (z != 0 && z + f != len) {
			//std::cout << "5 ";
			if (y != siz) std::cout << "0\n";
			else {
				ans = f1_mx(l1, r1) * z2_mx(l2, r2);
				std::cout << ans << '\n';
			}
		}
		else {
			//std::cout << "6 ";
			if (x != siz) std::cout << "0\n";
			else {
				ans = z1_mi(l1, r1) * f2_mi(l2, r2);
				std::cout << ans << '\n';
			}
		}
	}
	
	return 0;
}
