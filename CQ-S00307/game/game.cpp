#include<bits/stdc++.h>
#define ll i << 1
#define rr (i << 1) + 1
#define mid (tl + tr) / 2
using namespace std;
const int MAXN = 2e3;
int n,m,q,a[MAXN + 5],b[MAXN + 5],l1,l2,r1,r2;
bool vis[MAXN + 5];
long long tree[MAXN + 5][MAXN + 5],c[MAXN + 5][MAXN + 5],ans;
void build(int j,int i,int tl,int tr){
	if(tl == tr){
		tree[j][i] = c[j][tl];
		return;
	}
	build(j,ll,tl,mid);
	build(j,rr,mid + 1,tr);
	tree[j][i] = (long long)min(tree[j][ll],tree[j][rr]);
}
long long query(int j,int i,int tl,int tr,int l,int r){
	if(tl > r || tr < l)return 1e18;
	if(tl >= l && tr <= r)return tree[j][i];
	long long aa = query(j,ll,tl,mid,l,r);
	long long bb = query(j,rr,mid + 1,tr,l,r);
	long long ss = min(aa,bb);
	return ans;
}
signed main(){
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m >> q;
	for(int i = 1; i <= n; i++){
		cin >> a[i];
	}
	for(int i = 1; i <= m; i++){
		cin >> b[i];
	}
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= m; j++){
			c[i][j] = (long long)a[i] * b[j];
		}
	}
	for(int i = 1; i <= n; i++){
		build(i,1,1,m);
	}
	for(int i = 1; i <= q; i++){
		ans = -1e18;
		cin >> l1 >> r1 >> l2 >> r2;
		for(int j = l1; j <= r1; j++){
			long long cnt = query(j,1,1,m,l2,r2);
			ans = max(ans,cnt);
		}
		cout << ans << "\n";
	}
}
