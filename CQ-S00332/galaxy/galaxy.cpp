#include <bits/stdc++.h>
using namespace std;

const int N = 5e5 + 10; 
typedef long long LL;

bool vis[N];
int head[N], poi[N], nx[N], num[N][2], tot;

void add_edge(int u, int v) {
	++tot;
	poi[tot] = v;
	nx[tot] = head[u];
	head[u] = tot;
}

void read(int &x) {
	x = 0;
	char c = getchar();
	while(c < '0' || c > '9') {
		c = getchar();
	} 
	while(c >= '0' && c <= '9') {
		x = x * 10 + c - '0';
		c = getchar();
	}
}

bool check(int n) {
	for(int i = 1; i <= n; ++i) {
		num[i][0] = num[i][1] = 0;
	}
	for(int i = 1; i <= n; ++i) {
		for(int j = head[i]; j; j = nx[j]) {
			if(!vis[j]) {
				++num[i][0], ++num[poi[j]][1];
			}
		}
	}
	int add1 = 0, add2 = 0, add3 = 0;
	for(int i = 1; i <= n; ++i) {
		if(num[i][0] != 1) {
			return false;
		}
		if(num[i][1] != 1) {
			if(num[i][1] == 0) {
				++add1;
			} else if(num[i][1] == 2) {
				++add2;
			} else {
				++add3;
			}
		}
	}
	if((add1 == 1 && add2 == 1 && !add3) || (!add1 && !add2 && !add3)) {
		return true;
	} else {
		return false;
	}
}

int main() {
	freopen("galaxy.in", "r", stdin);
	freopen("galaxy.out", "w", stdout);
	int n, m, q, opt, a, b;
	read(n), read(m);
	for(int i = 1; i <= m; ++i) {
		read(a), read(b);
		add_edge(a, b);
	}
	read(q);
	for(int i = 1; i <= q; ++i) {
		read(opt), read(a);
		if(opt == 2) {
			for(int j = 1; j <= tot; ++j) {
				if(poi[j] == a) {
					vis[j] = true;
				}
			}
		} else if(opt == 4) {
			for(int j = 1; j <= tot; ++j) {
				if(poi[j] == a) {
					vis[j] = false;
				}
			}
		} else {
			read(b);
			for(int j = head[a]; j; j = nx[j]) {
				if(poi[j] == b) {
					if(opt == 1) {
						vis[j] = true;
					} else {
						vis[j] = false;
					}
					break;
				}
			}
		}
		if(check(n)) {
			puts("YES");
		} else {
			puts("NO");
		}
	}
	return 0;
}
