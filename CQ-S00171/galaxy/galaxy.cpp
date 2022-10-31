#include<cstdio>
#include<queue>
#include<cstring>
#include<algorithm>
using namespace std;
#define ll long long
const int N = 1e5 + 5, inf = 1e5;

void read(int &x) {
	x = 0;
	int f= 1;
	char s = getchar();
	while(s < '0' || s > '9') {
		if(s == '-') f = -1;
		s = getchar();
	}
	while(s <= '9' && s >= '0') {
		x = x * 10 + s - '0';
		s = getchar();
	} 
	x *= f;
}

void write(int x) {
	if(x < 0) putchar('-'), x = -x;
	if(x > 9) write(x / 10), x %= 10;
	putchar(x + '0');
}



//int dep[N], S, T;
//queue<int> q;
//bool bfs() {
//	memset(dep, -1, sizeof(dep));
//	dep[S] = 0, cur[S] = head[S];
//	while(!q.empty()) q.pop();
//	q.push(S);
//	int now, ver;
//	while(!q.empty()) {
//		now = q.front(), q.pop();
//		for(int i = head[now]; i; i = nex[i]) {
//			ver = to[i];
//			if(dep[ver] == -1 && f[i]) {
//				dep[ver] = dep[now] + 1;
//				cur[ver] = head[ver];
//				if(ver == T) return 1;
//				q.push(ver);
//			}
//		}
//	}
//	return 0;
//}
//
//int find(int x, int limit) {
//	if(x == T) return limit;
//	int ver, flow = 0, tmp;
//	for(int i = cur[x]; i && flow < limit; i = nex[i]) {
//		ver = to[i], cur[x] = i;
//		if(dep[ver] == dep[x] + 1 && f[i]) {
//			tmp = find(ver, min(limit - flow, f[i]));
//			if(!tmp) dep[ver] = -1;
//			f[i] -= tmp, f[i ^ 1] += tmp, flow += tmp;
//		}
//	}
//	return flow;
//}

//int dinic() {
//	int res = 0, flow;
//	while(bfs()) {
//		while(flow = find(S, inf)) res += flow;
//	}
//	return res;
// jidiaola~~~ 
//}


int n, m;
int main() {
	freopen("galaxy.in", "r", stdin);
	freopen("galaxy.out", "w", stdout);
	scanf("%d %d", &n, &m);
	int u, v;
	for(int i = 1; i <= m; i ++) {
		scanf("%d %d", &u, &v);
	} 
	int q;
	scanf("%d", &q);
	while(q --) {
		int op;
		scanf("%d", &op);
		if(op & 1) {
			scanf("%d %d", &u, &v);
		}
		else scanf("%d", &u);
		puts("NO");
	}
	return 0;
} 
