#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e5 + 5;
const ll inf = 0x3f3f3f3f3f3f;
int n,m,q,l1,r1,l2,r2;
bool st1,st2;
long long a[N],b[N];
struct Tree {
	ll Max,Min;
	ll cax,cmi;
} tr1[N << 2],tr2[N << 2];
inline void update(int p,Tree *tr) {
	tr[p].Max = max(tr[p + p].Max,tr[p + p + 1].Max);
	tr[p].Min = min(tr[p + p].Min,tr[p + p + 1].Min);
	tr[p].cax = min(tr[p + p].cax,tr[p + p + 1].cax);
	tr[p].cmi = max(tr[p + p].cmi,tr[p + p + 1].cmi);
}
void build(int p,int l,int r,Tree *tr,ll *c) {
	if (l == r) {
		tr[p].Max = c[l];
		tr[p].Min = c[l];
		if (c[l] <= 0) {
			tr[p].cmi = c[l];
			tr[p].cax = 1e18;
		}
		if (c[l] >= 0) {
			tr[p].cmi = -1e18;
			tr[p].cax = c[l];
		}
		return ;
	}
	int mid = (l + r) >> 1;
	build(p + p,l,mid,tr,c);
	build(p + p + 1,mid + 1,r,tr,c);
	update(p,tr);
}
ll queryMax(int p,int l,int r,int x,int y,Tree *tr) {
	if (x <= l && r <= y) return tr[p].Max;
	ll res = -inf;
	int mid = (l + r) >> 1;
	if (x <= mid) res = max(res,queryMax(p + p,l,mid,x,y,tr));
	if (mid < y) res = max(res,queryMax(p + p + 1,mid + 1,r,x,y,tr));
	return res;
}
ll queryMin(int p,int l,int r,int x,int y,Tree *tr) {
	if (x <= l && r <= y) return tr[p].Min;
	ll res = inf;
	int mid = (l + r) >> 1;
	if (x <= mid) res = min(res,queryMin(p + p,l,mid,x,y,tr));
	if (mid < y) res = min(res,queryMin(p + p + 1,mid + 1,r,x,y,tr));
	return res;
}
ll queryCmi(int p,int l,int r,int x,int y,Tree *tr) {
	if (x <= l && r <= y) return tr[p].cmi;
	ll res = -inf;
	int mid = (l + r) >> 1;
	if (x <= mid) res = max(res,queryCmi(p + p,l,mid,x,y,tr));
	if (mid < y) res = max(res,queryCmi(p + p + 1,mid + 1,r,x,y,tr));
	return res;
}
ll queryCax(int p,int l,int r,int x,int y,Tree *tr) {
	if (x <= l && r <= y) return tr[p].cax;
	ll res = inf;
	int mid = (l + r) >> 1;
	if (x <= mid) res = min(res,queryCax(p + p,l,mid,x,y,tr));
	if (mid < y) res = min(res,queryCax(p + p + 1,mid + 1,r,x,y,tr));
	return res;
}
int main() {
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	scanf("%d%d%d",&n,&m,&q);
	for (int i = 1; i <= n; i ++) scanf("%lld",&a[i]);
	for (int i = 1; i <= m; i ++) scanf("%lld",&b[i]);
	build(1,1,n,tr1,a);
	build(1,1,m,tr2,b);
	while (q --) {
		scanf("%d%d%d%d",&l1,&r1,&l2,&r2);
		long long ans = -1e18;
		ans = max(ans,queryMax(1,1,n,l1,r1,tr1) * queryMin(1,1,m,l2,r2,tr2));
		ans = max(ans,queryMin(1,1,n,l1,r1,tr1) * queryMax(1,1,m,l2,r2,tr2));
		if (queryCmi(1,1,n,l1,r1,tr1) > -1e18) ans = max(ans,queryCmi(1,1,n,l1,r1,tr1) * queryMax(1,1,m,l2,r2,tr2));
		if (queryCax(1,1,n,l1,r1,tr1) < 1e18) ans = max(ans,queryCax(1,1,n,l1,r1,tr1) * queryMin(1,1,m,l2,r2,tr2));
		printf("%lld\n",ans);
	}
	return 0;
}
