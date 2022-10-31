#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7;
#define inf 1e9
#define ll long long
#define pii pair <int, int>
#define mp make_pair
inline int read() {
	int x = 0, f = 1;
	char ch = getchar();
	while(ch < '0' || ch > '9') {
		if(ch == '-') f = -f;
		ch = getchar();
	}
	while(ch >= '0' && ch <= '9') {
		x = x * 10 + (ch - '0');
		ch = getchar();
	}
	return x * f;
}
void write(ll x) {
	if(x < 0) putchar('-'), x = -x;
	if(x >= 10) write(x / 10);
	putchar(x % 10 + '0');
}
inline int Abs(int x) {
	if(x > 0) return x;
	return -x;
}
int n, m, Q;
int a[100005], b[100005];
int lg[100005];
int fbmn[100005][25], fbmx[100005][25];
int famn[100005][25], famx[100005][25];
int fapos[100005][25], faneg[100005][25];
void init() {
	for(int i = 2; i <= 100000; i++) lg[i] = lg[i >> 1] + 1;
	for(int i = 1; i <= n; i++) {
		famn[i][0] = famx[i][0] = a[i];
		fapos[i][0] = (a[i] >= 0 ? a[i] : inf);
		faneg[i][0] = (a[i] <= 0 ? -a[i] : inf);
	}
	for(int j = 1; j <= lg[n]; j++) {
		for(int i = 1; i + (1 << j) - 1 <= n; i++) {
			famn[i][j] = min(famn[i][j-1], famn[i+(1<<(j-1))][j-1]);
			famx[i][j] = max(famx[i][j-1], famx[i+(1<<(j-1))][j-1]);
			fapos[i][j] = min(fapos[i][j-1], fapos[i+(1<<(j-1))][j-1]);
			faneg[i][j] = min(faneg[i][j-1], faneg[i+(1<<(j-1))][j-1]);
		}
	}
	for(int i = 1; i <= m; i++) fbmn[i][0] = fbmx[i][0] = b[i];
	for(int j = 1; j <= lg[m]; j++) {
		for(int i = 1; i + (1 << j) - 1 <= m; i++) {
			fbmn[i][j] = min(fbmn[i][j-1], fbmn[i+(1<<(j-1))][j-1]);
			fbmx[i][j] = max(fbmx[i][j-1], fbmx[i+(1<<(j-1))][j-1]);
		}
	}
}
inline int get_fbmn(int l, int r) {
	int k = lg[r-l+1];
	return min(fbmn[l][k], fbmn[r-(1<<k)+1][k]);
}
inline int get_fbmx(int l, int r) {
	int k = lg[r-l+1];
	return max(fbmx[l][k], fbmx[r-(1<<k)+1][k]);
}
inline int get_famn(int l, int r) {
	int k = lg[r-l+1];
	return min(famn[l][k], famn[r-(1<<k)+1][k]);
}
inline int get_famx(int l, int r) {
	int k = lg[r-l+1];
	return max(famx[l][k], famx[r-(1<<k)+1][k]);
}
inline int get_fapos(int l, int r) {
	int k = lg[r-l+1];
	return min(fapos[l][k], fapos[r-(1<<k)+1][k]);
}
inline int get_faneg(int l, int r) {
	int k = lg[r-l+1];
	return min(faneg[l][k], faneg[r-(1<<k)+1][k]);
}
int main() {
	freopen("game.in", "r", stdin);
	freopen("game.out", "w", stdout);
	n = read(), m = read(), Q = read();
	for(int i = 1; i <= n; i++) a[i] = read();
	for(int i = 1; i <= m; i++) b[i] = read();
	init();
	while(Q--) {
		int l1 = read(), r1 = read(), l2 = read(), r2 = read();
		int bmn = get_fbmn(l2, r2), bmx = get_fbmx(l2, r2);
		if(bmn >= 0) {
			if(get_famx(l1, r1) >= 0) write(1ll * get_famx(l1, r1) * bmn), putchar('\n');
			else write(1ll * get_famx(l1, r1) * bmx), putchar('\n');
		}
		else if(bmx <= 0) {
			if(get_famn(l1, r1) <= 0) write(1ll * get_famn(l1, r1) * bmx), putchar('\n');
			else write(1ll * get_famn(l1, r1) * bmn), putchar('\n');
		}
		else {
			int pos = get_fapos(l1, r1), neg = -get_faneg(l1, r1);
			write(max(1ll * pos * bmn, 1ll * neg * bmx)), putchar('\n');
		}
	} 
	return 0;
}
/*
*/
