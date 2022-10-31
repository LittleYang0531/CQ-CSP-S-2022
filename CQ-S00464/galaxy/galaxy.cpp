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
void write(int x) {
	if(x < 0) putchar('-'), x = -x;
	if(x >= 10) write(x / 10);
	putchar(x % 10 + '0');
}
vector <int> G[500005];
unordered_map <int, int> M[500005];
int du[500005], tag[500005], s[500005], ss[500005];
struct st {
	int op, x, y;
}p[500005];
int main() {
	freopen("galaxy.in", "r", stdin);
	freopen("galaxy.out", "w", stdout);
	int n = read(), m = read(), all = m;
	for(int i = 1; i <= m; i++) {
		int u = read(), v = read();
		G[v].push_back(u);
		du[u]++, s[v]++, ss[v]++;
		M[u][v] = 1;
	}
	int Q = read();
	int fl = 1;
	for(int i = 1; i <= Q; i++) {
		p[i].op = read(), p[i].x = read();
		if(p[i].op == 1 || p[i].op == 3) p[i].y = read();
		fl &= (p[i].op != 4);
	}
	if(n <= 1000 && m <= 10000 && Q <= 1000) {
		int wro = 0;
		for(int i = 1; i <= n; i++) wro += (du[i] != 1);
		for(int i = 1; i <= Q; i++) {
			if(p[i].op == 1) {
				wro -= (du[p[i].x] != 1);
				du[p[i].x]--, all--;
				wro += (du[p[i].x] != 1);
				M[p[i].x][p[i].y] = 0;
			}
			if(p[i].op == 3) {
				wro -= (du[p[i].x] != 1);
				du[p[i].x]++, all++;
				wro += (du[p[i].x] != 1);
				M[p[i].x][p[i].y] = 1;
			}
			if(p[i].op == 2) {
				for(auto y : G[p[i].x]) {
					if(M[y][p[i].x]) {
						wro -= (du[y] != 1);
						du[y]--, all--;
						wro += (du[y] != 1);
						M[y][p[i].x] = 0;
					} 
				}
			}
			if(p[i].op == 4) {
				for(auto y : G[p[i].x]) {
					if(!M[y][p[i].x]) {
						wro -= (du[y] != 1);
						du[y]++, all++;
						wro += (du[y] != 1);
						M[y][p[i].x] = 1;
					} 
				}
			}
			if(!wro) puts("YES");
			else puts("NO");
		}
		return 0;
	}
	if(fl) {
		int wro = 0;
		for(int i = 1; i <= n; i++) wro += (du[i] != 1);
		for(int i = 1; i <= Q; i++) {
			if(p[i].op == 1) {
				wro -= (du[p[i].x] != 1);
				du[p[i].x]--, all--;
				wro += (du[p[i].x] != 1);
				M[p[i].x][p[i].y] = 0;
			}
			if(p[i].op == 3) {
				G[p[i].y].push_back(p[i].x);
				wro -= (du[p[i].x] != 1);
				du[p[i].x]++, all++;
				wro += (du[p[i].x] != 1);
				M[p[i].x][p[i].y] = 1;
			}
			if(p[i].op == 2) {
				for(auto y : G[p[i].x]) {
					if(M[y][p[i].x]) {
						wro -= (du[y] != 1);
						du[y]--, all--;
						wro += (du[y] != 1);
						M[y][p[i].x] = 0;
					} 
				}
				G[p[i].x].clear();
			}
			if(!wro) puts("YES");
			else puts("NO");
		}
		return 0;
	}
	for(int i = 1; i <= Q; i++) {
		if(p[i].op == 1) {
			du[p[i].x]--, all--;
			s[p[i].y]--;
		}
		if(p[i].op == 3) {
			du[p[i].x]++, all++;
			s[p[i].y]++;
		}
		if(p[i].op == 2) {
			all -= s[p[i].x];
			s[p[i].x] = 0; 
		}
		if(p[i].op == 4) {
			all += ss[p[i].x] - s[p[i].x];
			s[p[i].x] = ss[p[i].x];
		}
		if(all == n) puts("YES");
		else puts("NO");
	}
	return 0;
}
/*
可以发动反攻的时机是内向基环森林，即每一个点的出边为 1 
考虑操作对应什么
t = 1 断边
t = 3 加边
t = 2 断掉终点为 u 的所有边
t = 4 加上终点为 u 的所有边
没有 4 可以简单维护
首先合法必要条件为边数 = n
被暴力摧毁的边我们可以暴力修复，如果不合法，一定存在点没有出边。
好难，不过 60 可以暴力，剩下可以乱搞，写完冲 t4 

还是不会。。。
有没有一种可能，我用 2 去清除 3，4 去清除 1 
或许我去维护较少的一方就是对的，。。。
根本没法处理 

。。。 翻车了。。。 
*/
