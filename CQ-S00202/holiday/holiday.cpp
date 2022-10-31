#include <bits/stdc++.h>
using namespace std;

int mmap[2505][2505];
int val[2505];
int n, m, k, ans = -1;

bool ch[4];

int dfs(int num, vector<int> c) {
	if (num == 4) {
		if (mmap[1][c[0]]-1 <= k && mmap[c[0]][c[1]]-1 <= k && mmap[c[1]][c[2]]-1 <= k && mmap[c[2]][c[3]]-1 <= k && mmap[c[3]][1]-1 <= k) {
			ans = max(ans, val[c[0]]+val[c[1]]+val[c[2]]+val[c[3]]);
//			cout << c[0] << " " << c[1] << " " << c[2] << " " << c[3] << " " << val[c[0]]+val[c[1]]+val[c[2]]+val[c[3]] << endl;
		}
	}
	for (int i = 2; i <= n; i++) {
		if (ch[i] == 0) {
			ch[i] = 1;
			vector<int> t = c;
			t.push_back(i);
			dfs(num+1, t);
			ch[i] = 0;
		}
	}
}

int main(){
	freopen("holiday.in", "r", stdin);
	freopen("holiday.out", "w", stdout);
	scanf("%d %d %d", &n, &m, &k);
	for (int i = 2; i <= n; i++) {
		scanf("%d", &val[i]);
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			mmap[i][j] = INT_MAX/3;
		}
	}
	for (int i = 1; i <= m; i++) {
		int x, y;
		scanf("%d %d", &x, &y);
		mmap[x][y] = 1;
		mmap[y][x] = 1;
	}
	for (int k = 1; k <= n; k++) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				mmap[i][j] = min(mmap[i][j], mmap[i][k]+mmap[k][j]);
			}
		}
	}
	vector<int> c;
	dfs(0, c);
	printf("%d\n", ans);
	return 0;
}
