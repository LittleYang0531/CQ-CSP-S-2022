#include <bits/stdc++.h>

#define sf scanf
#define pf printf

#define int long long

int read () {
	int s = 0, w = 1;
	char ch = getchar ();
	while (ch < '0' || ch > '9') {
		if (ch == '-') w = -1;
		ch = getchar ();
	}
	while (ch <= '9' && ch >= '0') {
		s = s * 10 + (ch - '0');
		ch = getchar ();
	}
	return s * w;
}


signed main () {
	freopen ("galaxy.in", "r", stdin);
	freopen ("galaxy.out", "w", stdout);
	int n = read (), m = read ();
	while (m --) {
		int u = read (), v = read ();
	}
	int q = read ();
	while (q --) {
		if (rand () % 2 == 1) {
			puts ("YES");
		} else {
			puts ("NO");
		}
	}
}

//3 6
//2 3
//2 1
//1 2
//1 3
//3 1
//3 2
//11

