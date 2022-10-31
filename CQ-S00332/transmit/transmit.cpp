#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 10, MAXN = 2010, M = 1e7 + 10;
typedef long long LL;

bool vis[N];
LL dis[N];
int p[N << 1], nxt[N << 1], h[N], vl[N];
int poi[M], nx[M], head[N], fa[N], dep[N], q[N], tot, add; 
struct node {
	int pos;
	LL val;
	node() {}
	node(int P, LL V) {
		pos = P, val = V;
	}
	bool operator < (const node &x) const {
		return val > x.val;
	}
};
priority_queue <node> qu;

void add_e(int u, int v) {
	++add;
	p[add] = v;
	nxt[add] = h[u];
	h[u] = add;
}

void add_edge(int u, int v) {
	++tot;
	poi[tot] = v;
	nx[tot] = head[u];
	head[u] = tot;
}

void read(int &x) {
	x = 0;
	char c = getchar();
	while(c < '0' || c > '9') {
		c = getchar();
	} 
	while(c >= '0' && c <= '9') {
		x = x * 10 + c - '0';
		c = getchar();
	}
}

void print(LL x) {
	if(x <= 9) {
		putchar(x + '0');
		return;
	} 
	print(x / 10);
	putchar(x % 10 + '0');
}

void dfs(int u) {
	for(int i = h[u]; i; i = nxt[i]) {
		int v = poi[i];
	}
}

void dijkstra(int a, int b) {
	qu.push(node(a, dis[a]));
	while(!qu.empty()) {
		node t = qu.top();
		qu.pop();
		int u = t.pos;
		if(!vis[u]) {
			vis[u] = true;
			if(u == b) {
				while(!qu.empty()) {
					qu.pop();
				}
				return;
			}
			for(int i = head[u]; i; i = nx[i]) {
				int v = poi[i];
				if(dis[u] + vl[v] < dis[v]) {
					dis[v] = dis[u] + vl[v];
					qu.push(node(v, dis[v]));
				}
			}
		}
	}
}

int main() {
	freopen("transmit.in", "r", stdin);
	freopen("transmit.out", "w", stdout);
	int n, qs, k, a, b;
	read(n), read(qs), read(k);
	for(int i = 1; i <= n; ++i) {
		read(vl[i]);
	}
	for(int i = 1; i < n; ++i) {
		read(a), read(b);
		add_e(a, b);
		add_e(b, a);
	}
//	if(k == 1) {
//		
//	} else {
		for(int i = 1; i <= n; ++i) {
			int l = 1, r = 1;
			q[1] = i;
			while(l <= r) {
				int u = q[l++];
				if(dis[u] == k) {
					break;
				}
				for(int j = h[u]; j; j = nxt[j]) {
					int v = p[j];
					if(!vis[v]) {
						vis[v] = true;
						add_edge(i, v);
						dis[v] = dis[u] + 1;
						q[++r] = v;
					}
				}
			}
			while(r) {
				vis[q[r]] = false;
				dis[q[r]] = 0;
				--r;
			}
		}
		for(int i = 1; i <= qs; ++i) {
			read(a), read(b);
			for(int j = 1; j <= n; ++j) {
				dis[j] = 1e18, vis[j] = false;
			}
			dis[a] = vl[a];
			dijkstra(a, b);
			print(dis[b]);
			puts("");
		}
//	}
	return 0;
}
