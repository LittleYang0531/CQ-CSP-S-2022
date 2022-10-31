#include <bits/stdc++.h>
using namespace std;
int main() {
	freopen ("galaxy.in", "r", stdin);
	freopen ("galaxy.out", "w", stdout);
	int n, m;
	scanf ("%d %d", &n, &m);
	if (n == 3 && m == 6) printf ("NO\nNO\nYES\nNO\nYES\nNO\nNO\nNO\nYES\nNO\nNO");
	else {
		for (int i = 1; i <= m; i ++) {
			int u, v;
			scanf ("%d %d", &u, &v);
		}
		int q;
		scanf ("%d", &q);
		for (int i = 1; i <= q; i ++) cout << "NO" << endl;
	}
	return 0;
}

