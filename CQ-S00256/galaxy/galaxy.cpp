#include<bits/stdc++.h>
#define inlint inline int
#define inloid inline void
#define inbool inline bool
#define MAXN 500005
#define JZP fclose(stdin),
#define AK fclose(stdout),
#define I 0
#define pii pair<int, int>
using namespace std;

namespace _MAIN {
	inlint read() {
		register int nega = 1, num = 0, c = getchar();
		for(;~c && !isdigit(c); c = getchar()) if(c == '-') nega = -1;
		for(;~c &&  isdigit(c); c = getchar()) (num *= 10) += c - '0';
		return nega * num;
	}
	int n, m, q;
} using namespace _MAIN;

namespace _SOLV {
	map<pii, int> mp;
	int fr[MAXN], to[MAXN], acti[MAXN], in[MAXN], out[MAXN], cnt;
	vector<int> rev[MAXN];
	inloid add(int x) {
		out[x]++;
		if(out[x] == 1) cnt++;
		else if(out[x] == 2) cnt--;
	}
	inloid del(int x) {
		out[x]--;
		if(out[x] == 1) cnt++;
		else if(out[x] == 0) cnt--;
	}
	inloid addEdge(int a, int b, int id) {
		fr[id] = a, to[id] = b, rev[b].push_back(id), add(a), acti[id] = 1, mp[pii(a, b)] = id;
	}
	inloid dele(int ed) {
		if(acti[ed] == 1) del(fr[ed]), in[to[ed]]--;
		acti[ed] = 0;
	}
	inloid adde(int ed) {
		if(acti[ed] == 0) add(fr[ed]), in[to[ed]]++;
		acti[ed] = 1;
	}
	inloid delp(int po) {
		for(int ed : rev[po]) dele(ed);
	}
	inloid addp(int po) {
		for(int ed : rev[po]) adde(ed);
	}
} using namespace _SOLV;

signed main(void) {
	freopen("galaxy.in", "r", stdin), freopen("galaxy.out", "w", stdout);
	n = read(), m = read();
	for(int i = 1; i <= m; i++) {
		int a = read(), b = read();
		addEdge(a, b, i);
	}
	q = read();
	for(int i = 1; i <= q; i++) {
		int t = read();
		if(t == 1) {
			int a = read(), b = read();
			dele(mp[pii(a, b)]);
		} else if(t == 2) {
			delp(read());
		} else if(t == 3) {
			int a = read(), b = read();
			adde(mp[pii(a, b)]);
		} else {
			addp(read());
		}
		cout << (cnt == n ? "YES\n" : "NO\n");
	}
	return JZP AK I;
}

