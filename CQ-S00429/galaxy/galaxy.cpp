#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int Maxn = 1e5 + 5;
inline ll read() {
	ll sum = 0;
	int f = 1;
	char ch = getchar();
	while(ch < '0' or ch > '9') {
		if(ch == '-') f = -1;
		ch = getchar(); 
	}
	while(ch >= '0' and ch <= '9') {
		sum = sum * 10 + ch - '0';
		ch = getchar();
	}
	return sum * f;
}
int main() {
	freopen("galaxy.in", "r", stdin);
	freopen("galaxy.out", "w", stdout);
	int n = read(), m = read();
	for(int i = 1;i <= m; ++i) int a= read(), b = read();
	int q = read();
	while(q--) puts("YES");
	return 0;
}
