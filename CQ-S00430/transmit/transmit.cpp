#include <cstdio>

#define LL long long
#define rep(i, j, k) for(int i = (j); i <= (k); i ++)
#define per(i, j, k) for(int i = (j); i >= (k); i --)

const int Maxn = 2e5;

int n, q, k;
int a[Maxn + 5];

int main () {
	freopen ("transmit.in", "r", stdin);
	freopen ("transmit.out", "w", stdout);
	
	scanf ("%d %d %d", &n, &q, &k);
	
	rep (i, 1, n) {
		scanf ("%d", &a[i]);		
	}
	rep (i, 1, n - 1) {
		int u, v;
		scanf ("%d %d\n", &u, &v);
	}
	
	rep (i, 1, q) {
		int u, v;
		scanf ("%d %d", &u, &v);
		printf ("%d\n", a[u] + a[v]);
	}
	return 0;
}

