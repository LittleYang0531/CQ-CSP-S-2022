#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second
#define pb push_back
#define all(xx) xx.begin(), xx.end()

using ll = long long;

ifstream __fin("game.in");
ofstream __fout("game.out");
#define cin __fin
#define cout __fout

struct seginfo {
	int ag0mi, ag0mx, al0mi, al0mx, ae0c, bmi, bmx;
	seginfo operator+(const seginfo & o) const {
		return {min(ag0mi, o.ag0mi), max(ag0mx, o.ag0mx), 
		        min(al0mi, o.al0mi), max(al0mx, o.al0mx), ae0c + o.ae0c,
		        min(bmi, o.bmi), max(bmx, o.bmx)};
	}
};

int a[100005], b[100005];
seginfo seg[100005<<2];
const int INF = 1000000005;
void bild(int idx, int l, int r) {
	if(r-l==1) {
		seg[idx].ag0mi = INF, seg[idx].ag0mx = -INF;
		seg[idx].al0mi = INF, seg[idx].al0mx = -INF, seg[idx].ae0c = 0;
		seg[idx].bmi = b[l], seg[idx].bmx = b[l];
		if(a[l] > 0) seg[idx].ag0mi = seg[idx].ag0mx = a[l];
		if(a[l] < 0) seg[idx].al0mi = seg[idx].al0mx = a[l];
		if(a[l] == 0) seg[idx].ae0c = 1;
		return;
	}
	bild(idx*2, l, (l+r)/2);
	bild(idx*2+1, (l+r)/2, r);
	seg[idx] = seg[idx*2] + seg[idx*2+1];
}

seginfo qry(int idx, int l, int r, int L, int R) {
	if(L <= l && r <= R) return seg[idx];
	if(R <= l || r <= L) return {INF, -INF, INF, -INF, 0, INF, -INF};
	return qry(idx*2, l, (l+r)/2, L, R) + qry(idx*2+1, (l+r)/2, r, L, R);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int n, m, q; cin >> n >> m >> q;
	for(int i=0;i<n;i++) cin >> a[i];
	for(int i=0;i<m;i++) cin >> b[i];
	int mx = max(n,m);
	bild(1, 0, mx);
	for(int i=0;i<q;i++){
		int l1,r1,l2,r2;
		cin>>l1>>r1>>l2>>r2;
		seginfo bee = qry(1, 0, mx, l1-1, r1);
		seginfo bee2 = qry(1, 0, mx, l2-1, r2);
		ll ans = - 1ll * INF * INF;
		if(bee.ag0mi != INF)
			ans = max(ans, 1ll * bee2.bmi * bee.ag0mi);
		if(bee.ag0mx != -INF)
			ans = max(ans, 1ll * bee2.bmi * bee.ag0mx);
		if(bee.al0mi != INF)
			ans = max(ans, 1ll * bee2.bmx * bee.al0mi);
		if(bee.al0mx != -INF)
			ans = max(ans, 1ll * bee2.bmx * bee.al0mx);
		if(bee.ae0c) ans = max(ans, 0ll);
		cout << ans << '\n';
	}
	return 0;
}
