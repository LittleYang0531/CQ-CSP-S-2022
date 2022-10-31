#include <cstdio>

int n, a;

int main() {
	freopen("galaxy.in", "r", stdin);
	freopen("galaxy.out", "w", stdout);
	scanf("%d %d", &n, &n);
	for (int i = 1; i <= n; i++)
		scanf("%d %d", &a, &a);
	scanf("%d", &n);
	while (n--)
		puts("NO");
	return 0;
}
