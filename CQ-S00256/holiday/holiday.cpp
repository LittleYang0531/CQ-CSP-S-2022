#include<bits/stdc++.h>
#define inlint inline int
#define inloid inline void
#define inbool inline bool
#define MAXN 2505
#define JZP fclose(stdin),
#define AK fclose(stdout),
#define I 0
#define ll long long
using namespace std;

namespace _MAIN {
	inline ll read() {
		register ll nega = 1, num = 0, c = getchar();
		for(;~c && !isdigit(c); c = getchar()) if(c == '-') nega = -1;
		for(;~c &&  isdigit(c); c = getchar()) (num *= 10) += c - '0';
		return nega * num;
	}
	int n, m, k;
} using namespace _MAIN;

namespace _SOLV {
	int dist[MAXN][MAXN], pri[MAXN][MAXN], papcnt[MAXN], inq[MAXN];
	vector<int> conn[MAXN];
	ll val[MAXN], ans;
	deque<int> dq;
	inloid chkPu(int st, int x) {
		if(inq[x] || (st != 1 && dist[st][x] > k) || dist[1][x] > 2 * k) return;
		dq.push_back(x), inq[x] = 1;
		if(dist[st][dq.front()] > dist[st][x]) swap(dq.front(), x);
	}
	inloid spfa(int st) {
		dist[st][st] = 0, chkPu(st, st);
		for(;!dq.empty();) {
			int h = dq.front();
			inq[h] = 0, dq.pop_front();
			for(int to : conn[h]) {
				if(dist[st][h] + 1 < dist[st][to]) dist[st][to] = dist[st][h] + 1, chkPu(st, to);
			}
		}
	}
	int cup[5];
	inloid dfs(int stp, ll cuv) {
		if(clock() >= 1850) {
			cout << ans << "\n";
//cerr << "tlm\n";
			JZP AK exit(I);	
		}
		int cu = cup[stp];
		if(stp == 4) return ans = max(ans, cuv), void();
		if(dist[cu][cu]) {
			spfa(cu);
			for(int i = 1; i <= n; i++) if(i != cu && dist[cu][i] <= k && dist[1][i] <= 2 * k) pri[cu][++papcnt[cu]] = i;
			sort(pri[cu] + 1, pri[cu] + 1 + papcnt[cu], [](const int &a, const int &b){return val[a] > val[b];});
		}
		for(int i = 1; i <= papcnt[cu]; i++) {
			int to = pri[cu][i];
//			if(cuv + val[to] <= ans) return;
			int flag = 1;
			for(int j = 0; j <= stp; j++) if(cup[j] == to) {flag = 0; break;}
			if(!flag) continue;
			if(stp != 3 || dist[1][to] <= k) cup[stp + 1] = to, dfs(stp + 1, cuv + val[to]);
		}
	}
	inloid addEdge(int a, int b) {
		conn[a].push_back(b), conn[b].push_back(a);
	}
} using namespace _SOLV;

signed main(void) {
	freopen("holiday.in", "r", stdin), freopen("holiday.out", "w", stdout);
	n = read(), m = read(), k = read() + 1, memset(dist, 0x3f, sizeof(dist));
	for(int i = 2; i <= n; i++) val[i] = read();
	for(int i = 1; i <= m; i++) addEdge(read(), read());
	cup[0] = 1, dfs(0, 0), cout << ans << "\n"; 
	return JZP AK I;
}

