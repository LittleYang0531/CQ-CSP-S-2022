#include<bits/stdc++.h>
using namespace std;
const int MAXN = 5e5 + 5 , MAXM = 1e6 + 5;
#define ll long long
template<typename item> 
void read(item &x) {
	x = 0;
	int f = 1;
	char c = getchar();
	while(c < '0' || c > '9') {
		if (c == '-') f = -1;
		c = getchar();
	}
	while(c >= '0' && c <= '9') {
		x = (x << 1) + (x << 3) + (c ^ 48);
		c = getchar();
	}
	x *= f;
}
int n , m , q , head[MAXN] , cnt , t , u , v , tot[MAXN] , U[MAXN] , V[MAXN];
bool vis[MAXN] , used[MAXN];
struct node{
	int to , nxt;
}a[MAXM];
void add(int u , int v) {
	a[++ cnt].to = v;
	a[cnt].nxt = head[u];
	head[u] = cnt;
}
bool dfs(int now) {
	used[now] = 1;
	bool f = 0;
	for (int i = head[now] ; i ; i = a[i].nxt) {
		int v = a[i].to;
		if (used[v]) return 1;
		used[v] = 1;
		f |= dfs(v);
		used[v] = 0;
	}
	return f;
}
int main() {
	freopen("galaxy.in" , "r" , stdin);
	freopen("galaxy.out" , "w" , stdout);
	read(n);read(m);
	for (int i = 1 ; i <= m ; i ++) {
		read(U[i]);read(V[i]);
		add(U[i] , V[i]);
	} 
	read(q);
	while(q --) {
		bool flag = 1;
		read(t);
		if (t == 1) {
			read(u);read(v);
			for (int i = 1 ; i <= m ; i ++) {
				if (U[i] == u && V[i] == v) vis[i] = 1;
			}
		} else if (t == 2) {
			read(u);
			for (int i = 1 ; i <= cnt ; i ++) {
				if (V[i] == u) vis[i] = 1;
			}
		} else if (t == 3) {
			read(u);read(v);
			for (int i = 1 ; i <= cnt ; i ++) {
				if (U[i] == u && V[i] == v) vis[i] = 0;
			}
		} else {
			read(u);
			for (int i = 1 ; i <= cnt ; i ++) {
				if (V[i] == u) vis[i] = 0;
			}
		}
		for (int i = 1 ; i <= cnt ; i ++) tot[i] = 0;
		for (int i = 1 ; i <= cnt ; i ++) {
			tot[U[i]] += (!vis[i]);
		}
		for (int i = 1 ; i <= n ; i ++) {
			used[i] = 0;
			if (tot[i] != 1) flag = 0;
		}
		if (!flag) {
			puts("NO");
			continue;
		}
		for (int i = 1 ; i <= n ; i ++) {
			if (!dfs(i)) {
				flag = 0;
				break;
			}
		}
		if (flag) puts("YES");
		else puts("NO");
	}
	return 0;
}
