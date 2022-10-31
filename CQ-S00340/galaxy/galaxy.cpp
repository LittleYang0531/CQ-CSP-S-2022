#include <bits/stdc++.h>
#define mkp make_pair
#define pb push_back
using namespace std;

inline int read() {
	int res = 0,f = 1;
	char ch = getchar();
	while (ch < '0' || ch > '9') {
		if (ch == '-') f = -1;
		ch = getchar();
	}
	while (ch >= '0' && ch <= '9') {
		res = res * 10 + (ch - '0');
		ch = getchar();
	}
	return res * f;
}
const int MAXN = 5e5 + 5,MAXM = 5e5 + 5;
struct Graph {
	int u,v,nxt;
	bool appe;
} gra[MAXM];
int head[MAXN],out[MAXN];
set <int> inc;
map <pair <int,int>,int> id;
vector <int> dxqwq[MAXN];
int n,m,q,idx;
inline void add(int u,int v) {
	gra[++ idx] = (Graph){u,v,head[u],true},head[u] = idx;
	id[mkp(u,v)] = idx,dxqwq[v].pb(idx);
}
inline void debug() {
	cerr << "Now out deg: ";
	for (int i = 1;i <= n; ++ i) cerr << out[i] << ' ';
	cerr << '\n';
}
int main(void) {
	freopen("galaxy.in","r",stdin);
	freopen("galaxy.out","w",stdout);
	n = read(),m = read();
	for (int i = 1;i <= m; ++ i) {
		int u = read(),v = read();
		add(u,v);
		out[u] ++;
	}
#define sz(a) (int)a.size()
	q = read();
	if (1ll * (long long)(n) * (long long)(q) <= (long long)1e7) {
		while (q --) {
			int opt = read(),u = read();
			if (opt == 1) {
				int v = read(),exlg = id[mkp(u,v)];
				if (gra[exlg].appe) out[u] --;
				gra[exlg].appe = false;
			} else if (opt == 2) {
				for (auto &item : dxqwq[u]) {
					int exlg = id[mkp(gra[item].u,gra[item].v)];
					if (gra[exlg].appe) out[gra[item].u] --;
					gra[exlg].appe = false;
				}
			} else if (opt == 3) {
				int v = read(),exlg = id[mkp(u,v)];
				if (!gra[exlg].appe) out[u] ++;
				gra[exlg].appe = true;
			} else {
				for (auto &item : dxqwq[u]) {
					int exlg = id[mkp(gra[item].u,gra[item].v)];
					if (!gra[exlg].appe) out[gra[item].u] ++;
					gra[exlg].appe = true;
				}
			}
	//		debug();
			bool ck = true;
			for (int i = 1;i <= n; ++ i) {
				if (out[i] != 1) {
					ck = false;
					break;
				}
			}
			puts(ck ? "YES" : "NO");
		}
	} else {
		bool fl = true;
		for (int i = 1;i <= n; ++ i) {
			if (out[i] != 1) {
				inc.insert(i);
				fl = false; 
			}
		}
		while (q --) {
			int opt = read(),u = read();
			if (opt == 1) {
				int v = read(),exlg = id[mkp(u,v)];
				if (gra[exlg].appe) out[u] --;
				if (out[u] == 1) inc.erase(u);
				else inc.insert(u);
				gra[exlg].appe = false;
			} else if (opt == 2) {
				for (auto &item : dxqwq[u]) {
					int exlg = id[mkp(gra[item].u,gra[item].v)];
					if (gra[exlg].appe) {
						out[gra[item].u] --;
						if (out[gra[item].u] == 1) inc.erase(gra[item].u);
						else inc.insert(gra[item].u);
					}
					gra[exlg].appe = false;
				}
			} else if (opt == 3) {
				int v = read(),exlg = id[mkp(u,v)];
				if (!gra[exlg].appe) out[u] ++;
				if (out[u] == 1) inc.erase(u);
				else inc.insert(u);
				gra[exlg].appe = true;
			} else {
				for (auto &item : dxqwq[u]) {
					int exlg = id[mkp(gra[item].u,gra[item].v)];
					if (!gra[exlg].appe) {
						out[gra[item].u] ++;
						if (out[gra[item].u] == 1) inc.erase(gra[item].u);
						else inc.insert(gra[item].u);
					}
					gra[exlg].appe = true;
				}
			}
	//		debug();
			puts(inc.empty() ? "YES" : "NO");
		}
	}
	
	return 0;
}

