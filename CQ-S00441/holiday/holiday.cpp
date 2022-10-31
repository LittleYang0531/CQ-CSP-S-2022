#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
int read() {
	int sum, f = 1;
	char ch;
	while((ch = getchar()) && (ch < '0' || ch > '9')) {
		if(ch == '-') f = -1;
	}
	sum = (ch ^ 48);
	while((ch = getchar()) && (ch >= '0' && ch <= '9')) {
		sum = (sum << 1) + (sum << 3) + (ch ^ 48);
	}
	return sum * f;
}
void print(int x) {
	if(x < 0) {
		putchar('-');
		x = -x;
	}
	if(x >= 10) print(x / 10);
	putchar(x % 10 + 48); 
}
struct node {
	int x, stp;
};
int n, m, k;
int val[2505];
bool vis[2505][2505];//从i出发不转车超过k次，能否到达j 
bool flg[2505][2505];
vector<int> w[2505];
vector<int> p[2505];
ll ans;
void bfs(int x) {
	queue<node> q;
	q.push(node({x, 0}));
	while(!q.empty()) {
		node dx = q.front();
		q.pop();
		if(vis[x][dx.x]) continue;
		vis[x][dx.x] = true;
		for(int i = 0; i < w[dx.x].size(); i++) {
			int dy = w[dx.x][i];
			if(dx.stp + 1 <= k + 1) {
				q.push(node({dy, dx.stp + 1}));
			}
		}
	}
}
struct edgo {
	int x, dep;
	ll stp;
	bool vis[2505];
	bool operator <(const edgo &t) const {
		return stp < t.stp; 
	}
} t1;
void BFS() {
	priority_queue<edgo> q;
	q.push(edgo({1, 0, 0}));
	while(!q.empty()) {
		edgo x = q.top();
		q.pop();
		if(x.dep == 4) {
			if(vis[x.x][1]) {
				cout<<x.stp;
				return;	
			}
			continue;
		}
		for(int i = 0; i < p[x.x].size(); i++){
			int dx = p[x.x][i];
			t1 = x;
			if(x.vis[dx] || flg[dx][x.dep + 1] || dx == 1) continue;
			flg[dx][x.dep + 1] = true;
			t1.x = dx;
			t1.dep = x.dep + 1;
			t1.stp = x.stp + val[dx];
			t1.vis[dx] = true;
			q.push(t1);
		}
	}
}
int main() {
	freopen("holiday.in", "r", stdin);
	freopen("holiday.out", "w", stdout);
	cin>>n>>m>>k;
	for(int i = 2; i <= n; i++) {
		scanf("%d", &val[i]);
	}
	for(int i = 1; i <= m; i++) {
		int u, v;
		scanf("%d %d", &u, &v);
		w[u].push_back(v);
		w[v].push_back(u);
	}
	for(int i = 1; i <= n; i++) {
		bfs(i);
	}
	for(int i = 1; i <= n; i++) {
		for(int j = 1; j <= n; j++) {
			if(vis[i][j] && i != j) {
				p[i].push_back(j);
			}
		}
	}
	BFS();
	return 0;
} 
