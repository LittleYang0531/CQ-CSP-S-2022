#include <bits/stdc++.h>
#define lson op, l, mid, id << 1
#define rson op, mid +1, r, id << 1 | 1
using namespace std;
typedef long long ll;
const int N= 2e5+5;
const ll inf = 2e18;
int n, m, q, allzh = 1;
ll a[2][N];
struct node {
	ll mxup=-inf, mxdn=-inf, miup=inf, midn=inf, zr=0;
	// -inf,-inf,inf,inf
	friend node operator+(node x, node y){
		node z;
		z.mxup=max(x.mxup,y.mxup);
		z.mxdn=max(x.mxdn,y.mxdn);
		z.miup=min(x.miup,y.miup);
		z.midn=min(x.midn,y.midn);
		z.zr=x.zr|y.zr;
		return z;
	}
} c[2][N<<2];
void build(int op, int l,int r,int id) {
	if (l== r){
		if(a[op][l]>0ll){
			c[op][id].mxup=c[op][id].miup=a[op][l];
			c[op][id].mxdn=-inf,c[op][id].midn=inf;
			c[op][id].zr=0ll;
		} 
		else if(a[op][l]<0ll){
			c[op][id].mxup=-inf,c[op][id].miup=inf;
			c[op][id].mxdn=c[op][id].midn=a[op][l];
			c[op][id].zr=0ll;
		} else{
			c[op][id].mxdn=-inf,c[op][id].midn=inf;
			c[op][id].mxup=-inf,c[op][id].miup=inf;
			c[op][id].zr=1ll;
		}
		return;
	}
	int mid = l+ r >> 1;
	build(lson),build(rson);
	c[op][id]=c[op][id<<1]+c[op][id<<1|1];
}
node query(int op,int l,int r,int id, int L,int R) {
	if (L<=l&&r<=R) {
		return c[op][id];
	}
	int mid= (l + r)>>1;
//	printf("%d-%d\n",l,r);
	if (R <=mid)return query(lson,L,R);
	if (L>mid) return query(rson,L,R);
	return query(lson,L,R)+query(rson,L,R);
}
inline void bf() {
//	printf("bf\n");
	for(int cs = 1;  cs <= q;cs++){
		int l1,r1,l2,r2;
		scanf("%d%d%d%d",&l1,&r1,&l2,&r2);
		node nd0=query(0, 1, n, 1, l1, r1);
		node nd1=query(1, 1, m, 1,l2,r2);
		printf("%lld\n", nd0.mxup*nd1.miup);
	};
}
int main() {
	freopen("game1.in","r",stdin);
	freopen("game.out","w",stdout);
	scanf("%d%d%d", &n, &m, &q);
	for (int i = 1; i <= n; i++) {
		scanf("%lld",&a[0][i]);
		allzh &= (a[0][i] > 0ll);
	}
	for(int i = 1; i <= m; i++) {
		scanf("%lld",&a[1][i]);
		allzh &= (a[1][i] > 0ll);
	}
	build(0,1,n,1);
	build(1,1,m,1);
//	printf("allzh = %d\n",allzh);
//	return 0;
	if (allzh) {
		bf(); return 0;
	}
	
	
	for(int cs = 1;  cs <= q;cs++){
		int l1,r1,l2,r2;
		scanf("%d%d%d%d",&l1,&r1,&l2,&r2);
		if ((l1 != r1 &&l2 != r2) || (l1 == r1)) {
			node nd=query(1, 1, m, 1,l2,r2);
			
			//	printf("fdfsdfsd\n");
			ll ans=-inf;
			for (int i = l1; i <= r1; i++) {
				if (a[0][i]>0ll){
					if(nd.midn!=inf)ans=max(ans,nd.midn*a[0][i]);
					else if(nd.zr)ans=max(ans,0ll);
					else
					ans=max(ans,nd.miup*a[0][i]);
				}else if (a[0][i]<0){
					if(nd.mxup!=-inf)ans=max(ans,nd.mxup*a[0][i]);
						
					else if (nd.zr) ans=max(ans,0ll);
					else
					ans=max(ans,nd.mxdn*a[0][i]);
				}else{
					ans=max(ans,0ll);
				}
			}
			printf("%lld\n",ans);
		} else {
			// l2 == r2
			ll ans = -inf;
			node nd = query(0, 1, n, 1, l1, r1);
			for (int i = l2; i <= r2; i++) {
				if (a[1][i]>0ll){
					if (nd.mxup!=-inf)ans=max(ans,a[1][i]*nd.mxup);
					else if (nd.zr) ans = max(ans, 0ll);
					else ans=max(ans, a[1][i]*nd.mxdn);
				}else if (a[1][i]<0){
					if (nd.midn!=inf)ans=max(ans,a[1][i]*nd.midn);
					else if(nd.zr)ans=max(ans, 0ll);
					else ans =max(ans,a[1][i]*nd.miup);
				}else{
					ans=max(ans, 0ll);
				}
			}
			printf("%lld\n",ans);
		}
	}
	return 0;
}
