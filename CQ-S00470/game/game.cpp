#include<bits/stdc++.h>
using namespace std;

// expect 30pts
// sto xiaomimxl rntianbowen rqheyuxiang rqnkdcc zmz gjy fyz kkksc03 nodgd bnuhzy alpc103 root ajhuhe nkrqtest067 lty2000 wjy2000 orz

long long a[100005], b[100005], n, m, q;

int main() {
	freopen("game.in", "r", stdin);
	freopen("game.out", "w", stdout);
	cin >> n >> m >> q;
	for (long long i = 1; i <= n; i++) cin >> a[i];
	for (long long i = 1; i <= m; i++) cin >> b[i];
	for (long long x = 1; x <= q; x++) {
		long long l1, r1, l2, r2;
		bool p1 = false, n1 = false, o1 = false, p2 = false, n2 = false, o2 = false;
		cin >> l1 >> r1 >> l2 >> r2;
		if (l1 == r1) {
			long long tans = 1e18;
			for (int i = l2; i <= r2; i++) {
				tans = min(tans, a[l1] * b[i]);
			}
			cout << tans << endl;
		}
		else if (l2 == r2) {
			long long tans = -1e18;
			for (int i = l1; i <= r1; i++) {
				tans = max(tans, b[l2] * a[i]);
			}
			cout << tans << endl;
		}
		else {
			for (long long i = l1; i <= r1; i++) {
				if (a[i] > 0) p1 = true;
				if (a[i] == 0) o1 = true;
				if (a[i] < 0) n1 = true;
			}
			for (long long i = l2; i <= r2; i++) {
				if (b[i] > 0) p2 = true;
				if (b[i] == 0) o2 = true;
				if (b[i] < 0) n2 = true;
			}
			if (p1 && n1 && o1 && p2 && n2) cout << 0 << endl;
			else if (p1 && n1 && p2 && n2) {
				long long mn = 1e18, mind = -1;
				for (long long i = l1; i <= r1; i++) {
					if (abs(a[i]) < mn) {
						mn = abs(a[i]);
						mind = i;
					}
				}
				long long xind = -1;
				mn = -1e18;
				for (long long i = l2; i <= r2; i++) {
					if (abs(b[i]) > mn && b[i] * a[mind] < 0) {
						mn = abs(b[i]);
						xind = i;
					}
				}
				cout << a[mind] * b[xind] << endl;
			}
			else if (p1 && n2) {
				long long mx = -1e18, mi = 1e18;
				for (long long i = l1; i <= r1; i++) mi = min(mi, a[i]);
				for (long long i = l2; i <= r2; i++) mx = min(mx, b[i]);
				if (o1) cout << 0 << endl;
				else cout << mx * mi << endl;
			}
			else if (p1 && p2) {
				long long mx = -1e18, mi = 1e18;
				for (long long i = l1; i <= r1; i++) mx = max(mx, a[i]);
				for (long long i = l2; i <= r2; i++) mi = min(mi, b[i]);
				if (o2) cout << 0 << endl;
				else cout << mx * mi << endl;
			}
			else cout << 0 << endl;
		}
	}
	return 0;
}

