#include <bits/stdc++.h>
using namespace std;
const int N = 2505, INF = 0x3f3f3f3f;

int n, m, k, f[N][N];
vector<int> p[N];
long long a[N], ans;
bitset<N> vis, exist;

void dfs(int now, int last, long long v) {
	if (now == 5) {
		if (f[last][1] - 1 <= k) ans = max(ans, v);
		return;
	}
	for (int i = 2; i <= n; i++)
		if (!vis[i] && f[i][last] - 1 <= k) {
			vis[i] = 1;
			dfs(now + 1, i, v + a[i]);
			vis[i] = 0;
		}
}

void dfs2(int now, int last, long long v) {
	if (now == 5) {
		if (exist[last]) ans = max(ans, v);
		return;
	}
	for (auto x : p[last])
		if (!vis[x]) {
			vis[x] = 1;
			dfs2(now + 1, x, v + a[x]);
			vis[x] = 0;
		}
}
int main() {
	freopen("holiday.in", "r", stdin);
	freopen("holiday.out", "w", stdout);
	cin >> n >> m >> k;
	for (int i = 2; i <= n; i++) cin >> a[i];
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			f[i][j] = INF;
	while (m--) {
		int x, y;
		cin >> x >> y;
		if (!k) {
			p[x].push_back(y), p[y].push_back(x);
			if (x == 1) exist[y] = 1;
			if (y == 1) exist[x] = 1;
		}
		f[x][y] = f[y][x] = 1;
	}
	if (!k) {
		dfs2(1, 1, 0);
		cout << ans << endl;
		return 0;
	}
	for (int l = 1; l <= n; l++)
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= n; j++)
				f[i][j] = min(f[i][j], f[i][l] + f[l][j]);
	dfs(1, 1, 0);
	cout << ans << endl;
	// 延续一下去年传统，祝大家以梦为马，不负韶华（） 
	return 0;
}
/*
4vrv'( my (e'vvc4 @f pF@ p( f@^^@w(.
p^$4@ug4 mpny @f u( k#^^v) p^^ $4v e'r@b^vm(, # g@$ p $#ny, e'@@r e'@#n$.
#( w4p$ # c4@(v wr@ng? @r pm # n@$ (ue'e'@(v) $@ ^vprn #$ $4r@ug4@u$?

# p#n'$ kn@w p$ ^vp($ (@ fpr, vvvn f@rvvvr.

#f # )#)n'$, mpybv # cpn bv 4pe'e'#vr. Bu$ w4@ kn@w(?
$4v ^p($ $#mv # g@$ $4v f#r($ e'^pcv #( ...... Wv^^ # cpn'$ vvvn rvmvmbvr #$.
If you're interested in what I wrote, go to note.ms/nobody, please.
wrote 2022/10/29 14:23 by nobody
edited 2022/10/29 17:44 by nobody
*/
