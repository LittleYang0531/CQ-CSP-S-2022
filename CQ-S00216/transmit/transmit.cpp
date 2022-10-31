#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int MAXN = 2e5 + 5;
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
int n , q , k , cnt , head[MAXN] , s , t , ans;
bool vis[MAXN];
struct node{
	int to , nxt;
}a[MAXN];
void add(int u , int v) {
	a[++ cnt].to = v;
	a[cnt].nxt = head[u];
	head[u] = cnt;
}
ll v[MAXN];
void dfs(int now , int used , int sum) {
	if (sum > ans) return;
	if (now == t) {
		ans = sum;
		return;
	}
	for (int i = 1 ; i <= n ; i ++) {
		if (!vis[i]) {
			vis[i] = 1;
			dfs(i , 0 , sum + v[i]);
			vis[i] = 0;
		}
	}
	if (used < k) {
		for (int i = head[now] ; i ; i = a[i].nxt) {
			int V = a[i].to;
			if (!vis[V]) {
				vis[V] = 1;
				dfs(V , used + 1 , sum);
				vis[V] = 0;
			}
		}
	}

}
int main() {
	freopen("transmit.in" , "r" , stdin);
	freopen("transmit.out" , "w" , stdout);
	read(n);read(q);read(k);
	for (int i = 1 ; i <= n ; i ++) read(v[i]);
	for (int i = 1 , U , V ; i < n ; i ++) {
		read(U);read(V);
		add(U , V);
		add(V , U);
	}
	while(q --) {
		read(s);read(t);
		ans = 0x3f3f3f3f;
		dfs(s , 0 , 0);
		printf("%d\n", ans + v[s] + v[t]);
	}
	return 0;
}


