#include <set>
#include <cstdio>

#define LL long long
#define uLL unsigned LL

LL rint() {
	LL x = 0, Fx = 1; char c = getchar();
	while (c < '0' || c > '9') { Fx ^= (c == '-'); c = getchar(); }
	while ('0' <= c && c <= '9') { x = (x << 3) + (x << 1) + (c ^ 48); c = getchar(); }
	return Fx ? x : -x;
}

const int MAX_n = 5e5;
const int MAX_m = 5e5;
const int MAX_q = 5e5;

int n, m, q, now;
int dp[MAX_n + 5];

std::set<int> s1[MAX_n + 5];
std::set<int> s2[MAX_n + 5];

int main() {
	freopen("galaxy.in", "r", stdin);
	freopen("galaxy.out", "w", stdout);
	n = rint(), m = rint();
	for (int i = 1, u, v; i <= m; i++) {
		u = rint(), v = rint();
		s1[v].insert(u);
		if (dp[u] == 1) --now;
		++dp[u];
		if (dp[u] == 1) ++now;
	}
	int t, u, v; q = rint();
	while (q--) {
		t = rint();
		if (t == 1) {
			u = rint(), v = rint();
			s1[v].erase(u);
			s2[v].insert(u);
			if (dp[u] == 1) --now;
			--dp[u];
			if (dp[u] == 1) ++now;
		} else if (t == 2) {
			u = rint();
			for (auto v : s1[u]) {
				s2[u].insert(v);
				if (dp[v] == 1) --now;
				--dp[v];
				if (dp[v] == 1) ++now;
			}
			s1[u].clear();
		} else if (t == 3) {
			u = rint(), v = rint();
			s2[v].erase(u);
			s1[v].insert(u);
			if (dp[u] == 1) --now;
			++dp[u];
			if (dp[u] == 1) ++now;
		} else if (t == 4) {
			u = rint();
			for (auto v : s2[u]) {
				s1[u].insert(v);
				if (dp[v] == 1) --now;
				++dp[v];
				if (dp[v] == 1) ++now;
			}
			s2[u].clear();
		}
		printf("%s\n", (now == n) ? "YES" : "NO");
	}
	return 0;
}

