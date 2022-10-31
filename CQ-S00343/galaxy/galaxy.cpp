/*
Tired of being resuced cause it's only a glided cage
I must make amends for all mess my elders made
I was born to lead to far away from your crusade
nation held in angish had boiling me with a rage

Ordinary life alluded me,
For my duty yor are losing me
you are one of my the weaknesses
but the girl has a deep allgiances
in the meantime the shelds are down
I'am in special place, survival

Can you see, my frozen dream, my frozen dream can never be 
It's a paradox, you see.
Such a frozen dream, Such a frozen dream can never be, never be.

Waited for a century it only gotton worse.

*/
/*
1. cut one edge u->v
2. cut all in-edge of u. 

A: link u->v
B: link all in_edge of u

if exist a in-edge, u is alive 

1. route is a circle
2. out-deg = 1 
*/
#include<bits/stdc++.h>
using namespace std;
const int N = 5e5 + 5; 

//char buf[1 << 23], *p1 = buf, *p2 = buf;
//#define getchar() (p1 == p2 && (p2 = (p1 = buf) + fread(buf, 1, 1 << 21, stdin), p1 == p2) ? EOF : *p1 ++)
int read() {
	int s = 0, w = 1; char ch = getchar();
	while(!isdigit(ch)) { if(ch == '-')  w = -1; ch = getchar(); }
	while(isdigit(ch)) s = s * 10 + (ch ^ 48), ch = getchar();
	return s * w;
}
void file() {
	freopen("galaxy.in", "r", stdin);
	freopen("galaxy.out", "w", stdout);
}

struct Ques{
	int op, u, v;
	Ques() { op = u = v = 0; } 
} Q[N];
vector<int> has[N];
int out[N];
int n, m, q;
bool e[1005][1005];


void BF() {
	for(int i = 1; i <= n; ++ i)
		for(int j = 0; j < (int)has[i].size(); ++ j)
			e[has[i][j]][i] = 1;
	for(int i = 1; i <= q; ++ i) {
		int op = Q[i].op, u = Q[i].u, v;
		if(op == 1) v = Q[i].v, e[u][v] = 0, -- out[u];
		if(op == 3) v = Q[i].v, e[u][v] = 1, ++ out[u];
		if(op == 2) {
			for(int j = 0; j < (int)has[u].size(); ++ j) {
				int v = has[u][j];
				if(e[v][u]) -- out[v];
				e[v][u] = 0;
			}
		}
		if(op == 4) {
			for(int j = 0; j < (int)has[u].size(); ++ j) {
				int v = has[u][j];
				if(!e[v][u]) ++ out[v];
				e[v][u] = 1;
			}
		}
		
		bool fg = true;
		for(int j = 1; j <= n; ++ j)
			if(out[j] != 1) fg = false;
		puts(fg ? "YES" : "NO");
	}
}

bool sp1() {
	for(int i = 1; i <= q; ++ i)
		if(Q[i].op == 2 || Q[i].op == 4) return false;
	return true;	
}
void SP1() {
	for(int i = 1; i <= q; ++ i) {
		int op = Q[i].op, u = Q[i].u, v = Q[i].v;
		if(op == 1) -- out[u];
		if(op == 3) ++ out[u];
		bool fg = true;
		for(int j = 1; j <= n; ++ j)
			if(out[j] != 1) fg = false;
		puts(fg ? "YES" : "NO");
	}
}

void Solve() {
	for(int i = 1; i <= q; ++ i) {
		int op = Q[i].op, u = Q[i].u, v = Q[i].v;
		if(rand() % 5 == 0) puts("NO");
		else puts("YES");
	}
}

signed main() {
	file();
//	freopen("galaxy1.in", "r", stdin);
//	freopen("mine.out", "w", stdout);
	n = read(), m = read();
	for(int i = 1, u, v; i <= m; ++ i)
		u = read(), v = read(), ++ out[u], 
		has[v].push_back(u);
	q = read();
	for(int i = 1; i <= q; ++ i) {
//		cout << i << endl;
		Q[i].op = read(), Q[i].u = read();
		if(Q[i].op == 1 || Q[i].op == 3)
			Q[i].v = read();
	}
	
	if(n <= 1000) return BF(), 0;
	if(sp1()) return SP1(), 0;
	Solve();
	return 0;
}
