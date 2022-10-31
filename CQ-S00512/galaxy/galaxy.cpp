#include <bits/stdc++.h>
#define IOS\
	ios::sync_with_stdio(false);\
	cin.tie(0), cout.tie(0);
using namespace std;

const int N = 1e5 + 3;

int n, m, x, y, opt, Q;
set<int> s[N];
vector<int> e[N];

int main() {
	freopen("galaxy.in", "r", stdin);
	freopen("galaxy.out", "w", stdout);
	IOS;
	cin >> n >> m;
	for (int i = 1; i <= m; i++) {
		cin >> x >> y;
		s[x].insert(y);
		e[y].push_back(x);
//		s[y].insert(x);
	}
	cin >> Q;
	while (Q--) {
		cin >> opt >> x;
		if (opt == 1) {
			cin >> y;
			s[x].erase(y);
		}
		else if (opt == 2) {
			for (int i = 1; i <= n; i++) {
				if (s[i].find(x) != s[i].end()) {
					s[i].erase(x);
				}
			}
		}
		else if (opt == 3) {
			cin >> y;
			s[x].insert(y);
		}
		else {
			for (auto u : e[x]) {
				if (s[u].find(x) == s[u].end()) {
					s[u].insert(x);
				}
			}
		}
		int flag = 1;
		for (int i = 1; i <= n; i++) {
			if (s[i].size() != 1) {
				flag = 0;
				break;
			}
		}
	/*	for (int i = 1; i <= n; i++) {
			cout << i << ":";
			for (auto x : s[i]) {
				cout << x << " ";
			}
			cout << '\n';
		}*/
		cout << (flag ? "YES\n" : "NO\n");
	}
	return 0;
}
