#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second
#define pb push_back
#define all(xx) xx.begin(), xx.end()

using ll = long long;

ifstream __fin("galaxy.in");
ofstream __fout("galaxy.out");
#define cin __fin
#define cout __fout

int heavid[500005];

using pii = pair<int,int>;

string rbuf;
vector<pii> elist[500005];
vector<int> relist[500005];
vector<int> relist2[500005];

int u[500005], v[500005];
int st[500005];
int stn[500005];
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int n, m, q; cin >> n >> m;
	for(int i=0;i<m;i++){
		cin>>u[i]>>v[i];
		elist[u[i]].pb({v[i],i});
		relist[v[i]].pb(i);
		stn[u[i]]++;
		st[i] = 1;
	}
	int c1 = 0;
	for(int i=1;i<=n;i++) {
		if(stn[i]==1) c1++;
		sort(elist[i].begin(), elist[i].end());
	}
	if(n>1000) for(int i=1;i<=n;i++) relist2[i] = relist[i];
	cin >> q;
	while(q--) {
		if(q % 256 == 0 && clock() > 1.9 * CLOCKS_PER_SEC) rbuf += "NO\n";
		int op; cin >> op;
		if(op == 1 || op == 3) {
			int u, v; cin >> u >> v;
			int ed = lower_bound(elist[u].begin(), elist[u].end(), pii{v, -1}) -> se;
			if(stn[u]==1) c1--;
			stn[u] -= st[ed];
			st[ed] = (op == 3);
			stn[u] += st[ed];
			if(stn[u]==1) c1++;
			if(n>1000 && st[ed]) relist2[v].pb(ed);
		}
		if(op == 2 && n > 1000) {
			int v; cin >> v;
			for(int ed : relist2[v]) {
				if(stn[u[ed]]==1) c1--;
				stn[u[ed]] -= st[ed];
				st[ed] = (op == 4);
				stn[u[ed]] += st[ed];
				if(stn[u[ed]]==1) c1++;
			}
			relist2[v].clear();
		}
		if(op == 4 || (op == 2 && n <= 1000)) {
			int v; cin >> v;
			for(int ed : relist[v]) {
				if(stn[u[ed]]==1) c1--;
				stn[u[ed]] -= st[ed];
				st[ed] = (op == 4);
				stn[u[ed]] += st[ed];
				if(stn[u[ed]]==1) c1++;
			}
			if(n > 1000) relist2[v] = relist[v];
		}
		if(c1 == n) rbuf += "YES\n";
		else rbuf += "NO\n";
	}
	cout<<rbuf;
	cout.flush();
	return 0;
}
