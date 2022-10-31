#include<bits/stdc++.h>
#define int long long
#define pii pair <int, int> 
#define ft first
#define sd second
#define mkp make_pair
#define ptc putchar
const int N = 3e3 + 10;
using namespace std;
int n, m, k, vis[N], d[N][N]; __int128 a[N], ans;
vector <int> e[N], p[N];
queue <int> q;
void read(__int128 &x) {
	char c = getchar();
	if(c < '0' || c > '9') return;
	x = (x << 1) + (x << 3) + c - '0';
	read(x);
}
void write(__int128 x) {
	string s;
	while(x) {
		s = char(x % 10 + '0') + s;
		x /= 10;
	} cout << s << '\n';
}
void bfs(int dis[], int s) {
	for(int i = 1; i <= n; ++i) vis[i] = 0;
	dis[s] = -1; vis[s] = 1; q.push(s);
	while(!q.empty()) {
		int x = q.front(); q.pop();
		for(int i = 0; i < (int)e[x].size(); ++i) {
			int sx = e[x][i];
			if(vis[sx]) continue;
			vis[sx] = 1; q.push(sx);
			dis[sx] = dis[x] + 1;
		}
	}
}
signed main() {
	freopen("holiday.in", "r", stdin);
	freopen("holiday.out", "w", stdout);
	scanf("%lld%lld%lld", &n, &m, &k); getchar();
	for(int i = 2; i <= n; ++i) read(a[i]);
	for(int i = 1; i <= m; ++i) {
		int u, v; scanf("%lld%lld", &u, &v);
		e[u].push_back(v);
		e[v].push_back(u);
	}
	for(int i = 1; i <= n; ++i) bfs(d[i], i);
	for(int A = 2; A <= n; ++A) {
		for(int B = 2; B <= n; ++B) {
			if(A == B) continue;
			for(int C = 2; C <= n; ++C) {
				if(A == C) continue;
				if(B == C) continue;
				for(int D = 2; D <= n; ++D) {
					if(A == D) continue;
					if(B == D) continue;
					if(C == D) continue;
					if(d[1][A] > k) continue; if(d[A][B] > k) continue;
					if(d[B][C] > k) continue; if(d[C][D] > k) continue;
					if(d[D][1] > k) continue;
					ans = max(a[A] + a[B] + a[C] + a[D], ans);
				}
			}
		}
	} write(ans);
	return 0;
}
/*
8 8 1
9 7 1 8 2 3 6
1 2
2 3
3 4
4 5
5 6
6 7
7 8
8 1

7 9 0
1 1 1 2 3 4
1 2
2 3
3 4
1 5
1 6
1 7
5 4
6 4
7 4

6 10 0
1 2 3 4 5
1 2
1 3
1 4
2 3
2 5
3 4
3 5
3 6
4 6
5 6

*/
