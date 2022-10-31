#include <algorithm>
#include <cstdio>
#include <iostream>
const int N = 1e5, LOGN = 17, inf = 0x3f3f3f3f;
const long long inf64 = 0x3f3f3f3f3f3f3f3f;
int n, m, q, a[N + 5], b[N + 5];
int log_w[N + 5];
int sta_pos_max[N + 5][LOGN + 1], sta_pos_min[N + 5][LOGN + 1], sta_neg_max[N + 5][LOGN + 1], sta_neg_min[N + 5][LOGN + 1], cnta[N + 5];
int stb_pos_max[N + 5][LOGN + 1], stb_pos_min[N + 5][LOGN + 1], stb_neg_max[N + 5][LOGN + 1], stb_neg_min[N + 5][LOGN + 1], cntb[N + 5];
inline void init() {
	log_w[0] = -1;
	for (int i = 1; i <= N; i++)
		log_w[i] = log_w[i >> 1] + 1;
	for (int i = 1; i <= n; i++) {
		if (a[i] > 0)
			sta_pos_max[i][0] = sta_pos_min[i][0] = a[i];
		else
			sta_pos_max[i][0] = -inf, sta_pos_min[i][0] = inf;
		if (a[i] < 0)
			sta_neg_max[i][0] = sta_neg_min[i][0] = a[i];
		else
			sta_neg_max[i][0] = -inf, sta_neg_min[i][0] = inf;
	}
	for (int i = 1; i <= n; i++) {
		if (b[i] > 0)
			stb_pos_max[i][0] = stb_pos_min[i][0] = b[i];
		else
			stb_pos_max[i][0] = -inf, stb_pos_min[i][0] = inf;
		if (b[i] < 0)
			stb_neg_max[i][0] = stb_neg_min[i][0] = b[i];
		else
			stb_neg_max[i][0] = -inf, stb_neg_min[i][0] = inf;
	}
	for (int j = 1; 1 << j <= n; j++) {
		for (int i = 1; i + (1 << j) - 1 <= n; i++) {
			sta_pos_max[i][j] = std::max(sta_pos_max[i][j - 1], sta_pos_max[i + (1 << j - 1)][j - 1]);
			sta_pos_min[i][j] = std::min(sta_pos_min[i][j - 1], sta_pos_min[i + (1 << j - 1)][j - 1]);
			sta_neg_max[i][j] = std::max(sta_neg_max[i][j - 1], sta_neg_max[i + (1 << j - 1)][j - 1]);
			sta_neg_min[i][j] = std::min(sta_neg_min[i][j - 1], sta_neg_min[i + (1 << j - 1)][j - 1]);
		}
	}
	for (int j = 1; 1 << j <= m; j++) {
		for (int i = 1; i + (1 << j) - 1 <= m; i++) {
			stb_pos_max[i][j] = std::max(stb_pos_max[i][j - 1], stb_pos_max[i + (1 << j - 1)][j - 1]);
			stb_pos_min[i][j] = std::min(stb_pos_min[i][j - 1], stb_pos_min[i + (1 << j - 1)][j - 1]);
			stb_neg_max[i][j] = std::max(stb_neg_max[i][j - 1], stb_neg_max[i + (1 << j - 1)][j - 1]);
			stb_neg_min[i][j] = std::min(stb_neg_min[i][j - 1], stb_neg_min[i + (1 << j - 1)][j - 1]);
		}
	}
	return;
}
inline int query_a_pos_max(const int &l, const int &r) {
	int p = log_w[r - l + 1];
	return std::max(sta_pos_max[l][p], sta_pos_max[r - (1 << p) + 1][p]);
}
inline int query_a_pos_min(const int &l, const int &r) {
	int p = log_w[r - l + 1];
	return std::min(sta_pos_min[l][p], sta_pos_min[r - (1 << p) + 1][p]);
}
inline int query_a_neg_max(const int &l, const int &r) {
	int p = log_w[r - l + 1];
	return std::max(sta_neg_max[l][p], sta_neg_max[r - (1 << p) + 1][p]);
}
inline int query_a_neg_min(const int &l, const int &r) {
	int p = log_w[r - l + 1];
	return std::min(sta_neg_min[l][p], sta_neg_min[r - (1 << p) + 1][p]);
}
inline int query_b_pos_max(const int &l, const int &r) {
	int p = log_w[r - l + 1];
	return std::max(stb_pos_max[l][p], stb_pos_max[r - (1 << p) + 1][p]);
}
inline int query_b_pos_min(const int &l, const int &r) {
	int p = log_w[r - l + 1];
	return std::min(stb_pos_min[l][p], stb_pos_min[r - (1 << p) + 1][p]);
}
inline int query_b_neg_max(const int &l, const int &r) {
	int p = log_w[r - l + 1];
	return std::max(stb_neg_max[l][p], stb_neg_max[r - (1 << p) + 1][p]);
}
inline int query_b_neg_min(const int &l, const int &r) {
	int p = log_w[r - l + 1];
	return std::min(stb_neg_min[l][p], stb_neg_min[r - (1 << p) + 1][p]);
}
int main() {
	freopen("game.in", "r", stdin);
	freopen("game.out", "w", stdout);
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	std::cout.tie(0);
	std::cin >> n >> m >> q;
	for (int i = 1; i <= n; i++)
		std::cin >> a[i], cnta[i] = cnta[i - 1] + (!a[i]);
	for (int i = 1; i <= m; i++)
		std::cin >> b[i], cntb[i] = cntb[i - 1] + (!b[i]);
	init();
	for (int i = 0; i < q; i++) {
		int u, v, x, y;
		std::cin >> u >> v >> x >> y;
		long long L, Q;
		bool a0 = cnta[v] - cnta[u - 1], b0 = cntb[y] - cntb[x - 1];
		long long ms = inf64, ms1 = inf64, ms2 = inf64, ms3 = inf64;
		if (query_a_pos_min(u, v) != inf && query_b_pos_min(x, y) != inf)
			ms = (long long)query_a_pos_min(u, v) * query_b_pos_min(x, y);
		if (query_a_pos_min(u, v) != inf && query_b_neg_min(x, y) != inf)
			ms = std::min((long long)query_a_pos_min(u, v) * query_b_neg_min(x, y), ms);

		if (query_a_pos_max(u, v) != -inf && query_b_neg_min(x, y) != inf)
			ms1 = (long long)query_a_pos_max(u, v) * query_b_neg_min(x, y);
		if (query_a_pos_max(u, v) != -inf && query_b_pos_min(x, y) != inf)
			ms1 = std::min((long long)query_a_pos_max(u, v) * query_b_pos_min(x, y), ms1);
		
		if (query_a_neg_max(u, v) != -inf && query_b_neg_max(x, y) != -inf)
			ms3 = (long long)query_a_neg_max(u, v) * query_b_neg_max(x, y);
		if (query_a_neg_max(u, v) != -inf && query_b_pos_max(x, y) != -inf)
			ms3 = std::min((long long)query_a_neg_max(u, v) * query_b_pos_max(x, y), ms3);
		
		if (query_a_neg_min(u, v) != inf && query_b_pos_max(x, y) != -inf)
			ms2 = (long long)query_a_neg_min(u, v) * query_b_pos_max(x, y);
		if (query_a_neg_min(u, v) != inf && query_b_neg_max(x, y) != -inf)
			ms2 = std::min((long long)query_a_neg_min(u, v) * query_b_neg_max(x, y), ms2);
		
		if (query_a_pos_min(u, v) != inf && b0)
			ms = std::min(ms, 0ll);
		if (query_a_pos_max(u, v) != -inf && b0)
			ms1 = std::min(ms1, 0ll);
		if (query_a_neg_max(u, v) != -inf && b0)
			ms3 = std::min(ms3, 0ll);
		if (query_a_neg_min(u, v) != inf && b0)
			ms2 = std::min(ms2, 0ll);
		ms = ms == inf64 ? -inf64 : ms;
		ms1 = ms1 == inf64 ? -inf64 : ms1;
		ms2 = ms2 == inf64 ? -inf64 : ms2;
		ms3 = ms3 == inf64 ? -inf64 : ms3;
		long long m0 = std::max(std::max(ms, ms1), std::max(ms2, ms3));
		if (a0 && m0 < 0)
			L = 0;
		else if (ms == m0)
			L = query_a_pos_min(u, v);
		else if (ms1 == m0)
			L = query_a_pos_max(u, v);
		else if (ms2 == m0)
			L = query_a_neg_min(u, v);
		else if (ms3 == m0)
			L = query_a_neg_max(u, v);

		ms = -inf64, ms1 = -inf64, ms2 = -inf64, ms3 = -inf64;
		if (query_b_pos_max(x, y) != -inf)
			ms = query_b_pos_max(x, y) * L;
		if (query_b_pos_min(x, y) != inf)
			ms1 = query_b_pos_min(x, y) * L;
		if (query_b_neg_min(x, y) != inf)
			ms3 = query_b_neg_min(x, y) * L;
		if (query_b_neg_max(x, y) != -inf)
			ms2 = query_b_neg_max(x, y) * L;
		ms = ms == -inf64 ? inf64 : ms;
		ms1 = ms1 == -inf64 ? inf64 : ms1;
		ms2 = ms2 == -inf64 ? inf64 : ms2;
		ms3 = ms3 == -inf64 ? inf64 : ms3;
		m0 = std::min(std::min(ms, ms1), std::min(ms2, ms3));
		if (b0 && m0 > 0)
			Q = 0;
		else if (ms == m0)
			Q = query_b_pos_max(x, y);
		else if (ms1 == m0)
			Q = query_b_pos_min(x, y);
		else if (ms2 == m0)
			Q = query_b_neg_max(x, y);
		else if (ms3 == m0)
			Q = query_b_neg_min(x, y);
		
		std::cout << L * Q << '\n';
	}
	return 0;
}
