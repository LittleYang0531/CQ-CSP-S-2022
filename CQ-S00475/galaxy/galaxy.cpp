#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
using namespace std;

void read(int& num) {
	num = 0;
	int g = 1;
	char x = getchar();
	while (x < '0' || x > '9') g = (x == '-' ? -1 : g), x = getchar();
	while (x >= '0' && x <= '9') num = (num << 1) + (num << 3) + (x ^ 48), x = getchar();
	num *= g;
}

int n, m, in[500005], out[500005], T;
struct node {
	int id;
	bool th;
};
vector<node> G[500005];

int main() {
	freopen("galaxy.in", "r", stdin);
	freopen("galaxy.out", "w", stdout);
	read(n), read(m);
	for (int i = 1, u, v; i <= m; i++) {
		read(u), read(v);
		swap(u, v);
		G[u].push_back((node) {v, 1});
		out[u]++;
		in[v]++;
	}
	read(T);
	while (T--) {
		int ty, u, v;
		read(ty);
		if (ty == 1) {
			read(u), read(v);
			swap(u, v);
			out[u]--;
			in[v]--;
			for (int i = 0; i < G[u].size(); i++) {
				if (G[u][i].id == v) {
					G[u][i].th = 0;
					break;
				}
			}
		} else if (ty == 2) {
			read(u);
			for (int i = 0; i < G[u].size(); i++) {
				if (G[u][i].th) {
					G[u][i].th = 0;
					in[G[u][i].id]--;
				}
			}
			out[u] = 0;
		} else if (ty == 3) {
			read(u), read(v);
			swap(u, v);
			out[u]++;
			in[v]++;
			for (int i = 0; i < G[u].size(); i++) {
				if (G[u][i].id == v) {
					G[u][i].th = 1;
					break;
				}
			}
		} else {
			read(u);
			for (int i = 0; i < G[u].size(); i++) {
				if (!G[u][i].th) {
					G[u][i].th = 1;
					in[G[u][i].id]++;
				}
			}
			out[u] = G[u].size();
		}
		int sum = 0;
		bool f = 1;
		for (int i = 1; i <= n; i++) {
			if (in[i] != 1) {
				f = 0;
				break;
			}
			sum += out[i];
		}
		if (f && sum == n) printf("YES\n");
		else printf("NO\n");
	}
	return 0;
}
