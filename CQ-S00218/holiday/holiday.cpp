#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
#include<queue>
using namespace std;
namespace ljx_9420yy {

	const int maxn = 2505, maxm = 10005;
	int n, m, x, y, cnt[maxn][maxn], top[maxn], vis[maxn][maxn], k, map[maxn][maxm], op[maxn], sum;

	struct node{
		int w, id;
	};
	
	node a[maxn];

	bool cmp(node c, node b) {
		return c.w>b.w;
	}

	void len(int x, int y, int size) {
		cnt[x][y] = size;
		cnt[y][x] = size;
		for(int i=1; i<=top[x]; i++) {
			if(vis[x][i] == 0) {
				len(x, i, size+1);
				vis[x][i] = 1;
				vis[i][x] = 1;
			}
		}
	}

	int main() {
		cin>> n>> m>> k;
		for(int i=2; i<=n; i++) {
			cin>> x;
			a[i].w = x;
			a[i].id = i;
		}
		for(int i=1; i<=m; i++) {
			cin>> x>> y;
			map[x][++top[x]] = y;
		}
		for(int i=1; i<=n; i++) {
			len(i, i, 0);
		}
		sort(a+1, a+1+n, cmp);
		x = 1;
		for(int i=1; i<=4; i++) {
			int t = 1;
			while(cnt[x][a[t].id]>k && op[t] == 0)	t++;
			sum += a[t].w;
			op[t] = 1;
			x = a[t].id;
		}
		cout<< sum;
		return 0;
	}

}

int main() {
	freopen("holiday.in", "r", stdin);
	freopen("holiday.out", "w", stdout);
	ljx_9420yy::main();
	return 0;
}
