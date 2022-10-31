#include<bits/stdc++.h>
using namespace std;
typedef long long van;
template<typename T> inline
void read(T& x) {
	T f = 1, b = 0; char ch = getchar();
	while (!isdigit(ch)) {
		if (ch == '-') f = -1;
		ch = getchar();
	} while (isdigit(ch))
		b *= 10, b += ch - '0', ch = getchar();
	x = f * b; return;
}
template<typename T> inline
void print(T x, int jz = 10) {
	if (x == 0) return putchar('0'), void();
	if (x < 0) putchar('-'), x = -x;
	van st[129] = {0}, k = 0;
	while (x) st[++k] = x % jz, x /= jz;
	for (int i = k; i; i--) putchar(st[i] + '0');
} const van MaxN = 2.5e3 + 10;
van n, m, k; vector<van> g[MaxN];
bitset<MaxN> exist[MaxN];
bool used[MaxN]; van dis[MaxN], s[MaxN];
van id[MaxN], id2[MaxN], ans;
void BFS(van st) {
	queue<van> q;
	q.push(st); exist[st][st] = 1;
	memset(dis, 0, sizeof dis);
	memset(used, 0, sizeof used);
	dis[st] = 0; used[st] = 1;
	while (!q.empty()) {
		van now = q.front(); q.pop();
		for (int i = 0; i < g[now].size(); i++) {
			van nxt = g[now][i];
			if (used[nxt]) continue;
			if (dis[now] + 1 > k + 1) continue;
			dis[nxt] = dis[now] + 1;
			exist[st][nxt] = 1; used[nxt] = 1;
			q.push(nxt); 
		}
	}
}
int main() {
	freopen("holiday.in", "r", stdin);
	freopen("holiday.out", "w", stdout);
	read(n), read(m), read(k);
	for (int i = 2; i <= n; i++) read(s[i]);
	for (int i = 1; i <= n; i++) id2[i] = i;
	sort(id2 + 2, id2 + n + 1, [](van a, van b){
		return s[a] > s[b];	
	});
	sort(s + 2, s + n + 1, greater<van>());
	for (int i = 1; i <= n; i++) id[id2[i]] = i;
	for (int i = 1; i <= m; i++) {
		van a, b; 
		read(a), read(b);
		a = id[a], b = id[b];
		g[a].push_back(b);
		g[b].push_back(a);
	}
	for (int i = 1; i <= n; i++) BFS(i);
	for (int i = 2; i <= n; i++) {
		for (int j = 2; j <= n; j++) {
			if (i == j) continue;
			if (exist[i][j] == 0 || exist[j][i] == 0) continue;
			bitset<MaxN> a, b;
			a = exist[i] & exist[1];
			b = exist[j] & exist[1];
			van wh1 = a._Find_first();
			while (wh1 == 1 || wh1 == i || wh1 == j) {
				a[wh1] = 0;
				wh1 = a._Find_first();
			}
			if (wh1 > n) continue;
			van wh2 = b._Find_first();
			while (wh2 == 1 || wh2 == i || wh2 == j || wh2 == wh1) {
				b[wh2] = 0;
				wh2 = b._Find_first();
			}
			if (wh2 > n) continue;
			van tmp = s[wh1] + s[wh2] + s[i] + s[j];
			ans = max(ans, tmp);
		}
	}
	print(ans);
	return 0;
}

