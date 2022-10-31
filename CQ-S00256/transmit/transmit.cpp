#include<bits/stdc++.h>
#define inlint inline int
#define inloid inline void
#define inbool inline bool
#define MAXN 200005
#define pii pair<int, ll>
#define JZP fclose(stdin),
#define AK fclose(stdout),
#define I 0
#define ll long long
using namespace std;

namespace _MAIN {
	inlint read() {
		register int nega = 1, num = 0, c = getchar();
		for(;~c && !isdigit(c); c = getchar()) if(c == '-') nega = -1;
		for(;~c &&  isdigit(c); c = getchar()) (num *= 10) += c - '0';
		return nega * num;
	}
	int n, q, k;
} using namespace _MAIN;

namespace _SOLV {
	int vis[MAXN], subvis[MAXN], val[MAXN];
	vector<pii> ngcon[MAXN];
	vector<int> conn[MAXN];
	inloid ngae(int a, int b, int v) {
		ngcon[a].push_back(pii(b, v));
	}
	inloid addEdge(int a, int b) {
		conn[a].push_back(b), conn[b].push_back(a);
	}
	inloid subdfs(int ro, int cu, int dep, ll cuv) {
		subvis[cu] = 1;
		if(dep) ngae(ro, cu, cuv);
		if(dep < k) 
			for(int to : conn[cu]) 
				if(!subvis[to]) subdfs(ro, to, dep + 1, val[to]);
		subvis[cu] = 0;
	}	
	inloid dfs(int cu, int fa) {
		subdfs(cu, cu, 0, 0);
		for(int to : conn[cu]) {
			if(to != fa) dfs(to, cu);
		}
	}
	int inq[MAXN];
	ll dis[MAXN];
	deque<int> dq;
	inloid chkPu(int cu) {
		if(inq[cu]) return;
		dq.push_back(cu);
		if(dis[dq.front()] > dis[dq.back()]) swap(dq.front(), dq.back());
	}
	inloid spfa(int st) {
		memset(dis, 0x3f, sizeof(dis)), dis[st] = val[st], chkPu(st);
		for(; !dq.empty();) {
			int h = dq.front();
			inq[h] = 0, dq.pop_front();
			for(pii ed : ngcon[h]) {
				int to = ed.first;
				ll v = ed.second;
				if(dis[h] + v < dis[to]) dis[to] = dis[h] + v, chkPu(to);
			}
		}
	}
} using namespace _SOLV;

signed main(void) {
	freopen("transmit.in", "r", stdin), freopen("transmit.out", "w", stdout);
	n = read(), q = read(), k = read();
	for(int i = 1; i <= n; i++) val[i] = read();
	for(int i = 1; i < n; i++) addEdge(read(), read());
	dfs(1, 0);
	for(int i = 1; i <= q; i++) {
		int a = read();
		spfa(a), cout << dis[read()] << "\n";
	}
	return JZP AK I;
}

