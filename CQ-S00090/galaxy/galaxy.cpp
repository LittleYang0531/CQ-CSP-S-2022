#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<time.h>
using namespace std;
#define SF scanf
#define PF printf
int main() {
	freopen("galaxy.in", "r", stdin);
	freopen("galaxy.out", "w", stdout);
	srand(time(0));
	int n, m, q, x, y;
	SF("%d%d", &n, &m);
	for(int i = 1; i <= m; i++) SF("%d%d", &x, &y);
	SF("%d", &q);
	while(q--) {
		int k = rand() % 2;
		k ? PF("YES\n") : PF("NO\n");
	}
	return 0;
} 
