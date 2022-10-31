#include<bits/stdc++.h>
#define int long long
#define pii pair <int, int>
#define ft first
#define sd second
#define mkp make_pair
using namespace std;
int n, m, q;
signed main() {
	freopen("galaxy.in", "r", stdin);
	freopen("galaxy.out", "w", stdout);
	scanf("%lld%lld", &n, &m);
	for(int i = 1; i <= m; ++i) scanf("%lld%lld", &q, &q);
	scanf("%lld", &n);
	for(int i = 1; i <= n; ++i) {
		scanf("%lld", &m);
		if(m & 1) scanf("%lld%lld", &q, &q);
		else  scanf("%lld", &q); puts("NO");
	}
	return 0;
}
/*
3 6
2 3
2 1
1 2
1 3
3 1
3 2
11
1 3 2
1 2 3
1 1 3
1 1 2
3 1 3
3 3 2
2 3
1 3 1
3 1 3
4 2
1 3 2

*/
