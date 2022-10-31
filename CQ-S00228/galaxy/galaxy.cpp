#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
const int N = 5e5 + 10;
int n, m, q;
int prt[N];
bool vis[N];
void Read() {
	scanf ("%d%d", &n, &m);
	for (int i = 1, u, v; i <= m; ++i) {
		prt[u]=v;
	}
	scanf ("%d", &q);
}
void Solve() {
	int t, u, v;
	while (q--) {
		scanf ("%d%d", &t, &u);
		if (t==1) {
			scanf ("%d", &v);
			while (prt[u]!=v) {
				vis[u]=1;
				u=prt[u];
			}
			vis[v]=1;
			puts("NO");
		}
		if (t==2) {
			for (int i=1; i<=n; ++i) {
				if (prt[i]==u) {
					vis[i]=1;
				}
			}
			puts("NO");
		}
		if (t==3) {
			scanf ("%d", &v);
			while (prt[u]!=v) {
				vis[u]=0;
				u=prt[u];
			}
			vis[v]=0;
			puts("YES");
		}
		else if (t==4) {
			puts("YES");
		}
	}
}
int main() {
	freopen("galaxy.in", "r", stdin);
	freopen("galaxy.out", "w", stdout);
	Read();
	Solve();
	return 0;
}

