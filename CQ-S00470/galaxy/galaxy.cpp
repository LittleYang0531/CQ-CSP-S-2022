#include<bits/stdc++.h>
#define maxm 500005
using namespace std;

// expect 60pts
// sto xiaomimxl rntianbowen rqheyuxiang rqnkdcc zmz gjy fyz kkksc03 nodgd bnuhzy alpc103 root ajhuhe nkrqtest067 lty2000 wjy2000 orz

int n, m, head[maxm], nxt[maxm], to[maxm], cnt, q, nowcnt;
bool ena[maxm], vis[maxm];

void add(int u, int v) {
	nxt[++cnt] = head[u];
	head[u] = cnt;
	to[cnt] = v;
	ena[cnt] = true;
	++nowcnt;
}

bool contin() {
	for (int u = 1; u <= n; u++) {
		int cnt = 0;
		for (int i = head[u]; i; i = nxt[i]) {
			if (!ena[i]) continue;
			cnt++;
			if (cnt > 1) return false;
		}
	}
	return true;
}

int main() {
	freopen("galaxy.in", "r", stdin);
	freopen("galaxy.out", "w", stdout);
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= m; i++) {
		int c1, c2;
		scanf("%d%d", &c1, &c2);
		add(c1, c2);
	}
	scanf("%d", &q);
	for (int i = 1; i <= q; i++) {
		int t, u, v;
		scanf("%d%d", &t, &u);
		if (t == 1) {
			scanf("%d", &v);
			for (int i = head[u]; i; i = nxt[i]) {
				int p = to[i];
				if (p == v) {
					ena[i] = false;
					--nowcnt;
					break;
				}
			}
		}
		if (t == 2) {
			for (int i = 1; i <= m; i++) {
				int p = to[i];
				if (p == u && ena[i]) {
					ena[i] = false;
					--nowcnt;
				}
			}
		}
		if (t == 3) {
			scanf("%d", &v);
			for (int i = head[u]; i; i = nxt[i]) {
				int p = to[i];
				if (p == v) {
					ena[i] = true;
					++nowcnt;
					break;
				}
			}
		}
		if (t == 4) {
			for (int i = 1; i <= m; i++) {
				int p = to[i];
				if (p == u && !ena[i]) {
					ena[i] = true;
					++nowcnt;
				}
			}
		}
//		cout << "adfjdasi" << nowcnt << " " << contin() << endl;
		if (nowcnt == n && contin()) printf("YES\n");
		else printf("NO\n");
	}
	return 0;
}

