#include<bits/stdc++.h>
#define File(s) freopen(s".in", "r", stdin), freopen(s".out", "w", stdout)
#define all(x) begin(x), end(x)
#define int long long

using namespace std;

bool mem1;

const int N = 1e5 + 5, LOG = 21, inf = 1e16;
int n, m, q, a[N], b[N];
int lg2[N];

struct ST {
	int len, mn[N][LOG], mx[N][LOG];
	void build() {
		for(int j = 1; j < LOG; ++j) {
			for(int i = 1; i + (1 << j) - 1 <= len; ++i) {
				mx[i][j] = max(mx[i][j - 1], mx[i + (1 << j - 1)][j - 1]);
				mn[i][j] = min(mn[i][j - 1], mn[i + (1 << j - 1)][j - 1]);
			}
		}
	}
	int askmax(int l, int r) {
		int k = lg2[r - l + 1];
		return max(mx[l][k], mx[r - (1 << k) + 1][k]);
	}
	int askmin(int l, int r) {
		int k = lg2[r - l + 1];
		return min(mn[l][k], mn[r - (1 << k) + 1][k]);
	}
} sta, stb, sta1, sta2;

bool mem2;

signed main() {
	File("game");
//	cerr << "Memory Cost: " << fixed << 1. * abs(&mem1 - &mem2) / 1024 / 1024 << "MB\n";
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m >> q;
	for(int i = 1; i <= n; ++i) {
		cin >> a[i];
		sta.mx[i][0] = sta.mn[i][0] = a[i];
		// sta1记录>=0的ai的最小值
		sta1.mn[i][0] = (a[i] >= 0 ? a[i] : inf);
		// sta2记录<=0的ai的最大值
		sta2.mx[i][0] = (a[i] <= 0 ? a[i] : -inf); 
	}
	for(int i = 1; i <= m; ++i) {
		cin >> b[i];
		stb.mx[i][0] = stb.mn[i][0] = b[i];
	}
	sta.len = sta1.len = sta2.len = n;
	stb.len = m;
	sta.build();
	sta1.build();
	sta2.build();
	stb.build();
	lg2[1] = 0;
	for(int i = 2; i <= max(n, m); ++i) {
		lg2[i] = lg2[i >> 1] + 1;
	}
	while(q--) {
		int l, r, L, R;
		cin >> l >> r >> L >> R;
		pair<int, int> rg1 = {sta.askmin(l, r), sta.askmax(l, r)};
		pair<int, int> rg2 = {stb.askmin(L, R), stb.askmax(L, R)};
		int ans;
		if(rg1.first >= 0 && rg2.first >= 0) {
			ans = rg1.second * rg2.first;
		} else if(rg1.first >= 0 && rg2.second <= 0) {
			ans = rg1.first * rg2.first;
		} else if(rg1.second <= 0 && rg2.first >= 0) {
			ans = rg1.second * rg2.second;
		} else if(rg1.second <= 0 && rg2.second <= 0) {
			ans = rg1.first * rg2.second;
		} else if(rg1.first >= 0) {
			ans = rg1.first * rg2.first;
		} else if(rg1.second <= 0) {
			ans = rg1.second * rg2.second;
		} else if(rg2.first >= 0) {
			ans = rg1.second * rg2.first;
		} else if(rg2.second <= 0) {
			ans = rg1.first * rg2.second;
		} else {
			ans = max(sta1.askmin(l, r) * rg2.first, sta2.askmax(l, r) * rg2.second);
		}
		cout << ans << "\n";
	}
	return 0;
}
/*

*/
