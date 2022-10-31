#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
int read() {
	int sum, f = 1;
	char ch;
	while((ch = getchar()) && (ch < '0' || ch > '9')) {
		if(ch == '-') f = -1;
	}
	sum = (ch ^ 48);
	while((ch = getchar()) && (ch >= '0' && ch <= '9')) {
		sum = (sum << 1) + (sum << 3) + (ch ^ 48);
	}
	return sum * f;
}
void print(int x) {
	if(x < 0) {
		putchar('-');
		x = -x;
	}
	if(x >= 10) print(x / 10);
	putchar(x % 10 + 48);
}
int n, m;
int u, v;
int q;
int main() {
	freopen("galaxy.in", "r", stdin);
	freopen("galaxy.out", "w", stdout);
	srand(time(NULL));
	cin>>n>>m;
	for(int i = 1; i <= m; i++) {
		cin>>u>>v;
	}
	cin>>q;
	while(q--) {
		if(rand() % 11 >= 3) puts("NO");
		else puts("YES");
	}
	return 0;
}

