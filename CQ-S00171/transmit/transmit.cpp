/*

树。

树形dp ?

a - b 的路径唯一，能选出的点也就可以确定。
*/
#include<cstdio>
#include<queue>
#include<cstring>
#include<vector>
#include<algorithm>
using namespace std;
#define ll long long
const int N = 2e5 + 5;

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

int tot, head[N], nex[N << 1], to[N << 1], f[N << 1];
void add(int x, int y) {
	to[++tot] = y, nex[tot] = head[x], head[x] = tot;
}
int n, Q, k;
ll val[N], dp[N][4], ans[N];

struct node {
	int v, id;
	node() {};
	node(int x, int y) {
		v = x, id = y;
	}
};

vector<node> G[N];

ll query(int x, int y) {
	ll res = dp[x][0];
	for(int i = 1; i <= y; i ++) res = min(res, dp[x][i]);
	return res;
} 

int num, cnt;
bool tag[N];
void DP(int x, int f) {
	int ver;
	for(int i = head[x]; i; i = nex[i]) {
		ver = to[i];
		if(ver == f) continue;
		dp[ver][0] = min(query(x, k - 1) + val[ver], dp[ver][0]);
		for(int j = 1; j <= k; j ++) {
			dp[ver][j] = min(dp[x][j - 1], dp[ver][j]);
			dp[ver][j] = min(dp[ver][j], dp[ver][j - 1]);
		}
		DP(ver, x);
	}
	if(tag[x]) cnt ++;
	if(cnt == num) return;
}

int main() {
	freopen("transmit.in", "r", stdin);
	freopen("transmit.out", "w", stdout);
	
	read(n), read(Q), read(k);
	for(int i = 1; i <= n; i ++) scanf("%lld", &val[i]);
	
	int u, v;
	for(int i = 1; i < n; i ++) {
		read(u), read(v);
		add(u, v), add(v, u);
	}
	
	for(int i = 1; i <= Q; i ++) {
		read(u), read(v);
		G[u].push_back(node(v, i));
	}
	
	for(int i = 1; i <= n; i ++) {
		if(!G[i].size()) continue;
		num = G[i].size();
		cnt = 0;
		memset(dp, 0x3f, sizeof(dp));
		for(int j = 0; j < G[i].size(); j ++) tag[G[i][j].id] = 1;
		dp[i][0] = val[i];
		DP(i, 0);
		for(int j = 0; j < G[i].size(); j ++) {
			ans[G[i][j].id] = dp[G[i][j].v][0];
			//for(int h = 2; h <= k; h ++) ans[G[i][j].id] = min(ans[G[i][j].id], dp[G[i][j].v][h] + val[G[i][j].v]);
			tag[G[i][j].id] = 0;
		}
	}
	for(int i = 1; i <= Q; i ++) printf("%lld\n", ans[i]);
	
	return 0;
} 

/*

7 3 3
1 2 3 4 5 6 7
1 2
1 3
2 4
2 5
3 6
3 7
4 7
5 6
1 2

为什么过不了样例？！！！！！为什么？！！！！！ 

阿西，大样例杀穿我。。 
*/
