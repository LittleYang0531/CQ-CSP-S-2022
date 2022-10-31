#include <bits/stdc++.h>
using namespace std;
int n, m, q, t, u, v, du[500005];
vector<int> g[500005], e[500005];
set< pair<int, int> > ch;
bool ANS, ans[500005], flag[500005];
void check(int now) {
	flag[now] = true;
	ans[now] = false;
	const int LEN = g[now].size();
	for(int i = 0; i < LEN; ++i) {
		if(!flag[g[now][i]]) check(g[now][i]);
		else ans[now] = true;
		ans[now] |= ans[g[now][i]];
	}
}
int main() {
	freopen("galaxy.in", "r", stdin);
	freopen("galaxy.out", "w", stdout);
	scanf("%d%d", &n, &m);
	while(m--) {
		scanf("%d%d", &u, &v);
		g[u].push_back(v);
		e[v].push_back(u);
		++du[u];
	}
	scanf("%d", &q);
	while(q--) {
		scanf("%d", &t);
		if(t == 1) {
			scanf("%d%d", &u, &v);
			ch.insert(make_pair(u, v));
			--du[u];
		}
		else if(t == 2) {
			scanf("%d", &u);
			const int LEN = e[u].size();
			for(int i = 0; i < LEN; ++i) {
				v = g[u][i];
				if(!ch.count(make_pair(v, u))) {
					ch.insert(make_pair(v, u));
					--du[v];
				}
			}
		}
		else if(t == 3) {
			scanf("%d%d", &u, &v);
			ch.erase(make_pair(u, v));
			++du[u];
		}
		else if(t == 4) {
			scanf("%d", &u);
			const int LEN = e[u].size();
			for(int i = 0; i < LEN; ++i) {
				v = g[u][i];
				if(ch.count(make_pair(v, u))) {
					ch.erase(make_pair(v, u));
					++du[v];
				}
			}
		}
		ANS = true;
		memset(flag, false, sizeof(flag));
		for(int i = 1; i <= n; ++i) {
			if(!flag[i]) check(i);
		}
		for(int i = 1; i <= n; ++i)
			if(!ans[i] || du[i] != 1) ANS = false;
		puts(ANS ? "YES" : "NO");
	}
	return 0;
}
