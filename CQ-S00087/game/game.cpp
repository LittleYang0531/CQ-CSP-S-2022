#include<cstdio>
#include<iostream>
using namespace std;
using ll=long long;
const int Maxn=1e5+5;
int a[Maxn],b[Maxn];
struct segtree{
	int l,r;
	int minv;
	int maxv;
}tr[Maxn<<2];
inline int ls(int x){return x<<1;}
inline int rs(int x){return x<<1|1;}
inline void pushup(int x){
	tr[x].maxv=max(tr[ls(x)].maxv,tr[rs(x)].maxv);
	tr[x].minv=min(tr[ls(x)].minv,tr[rs(x)].minv);
}
void build(int x,int L,int R){
	tr[x].l=L,tr[x].r=R;
	if(L==R){
		tr[x].maxv=b[L];
		tr[x].minv=b[L];
		return ;
	}
	int mid=(L+R)>>1;
	build(ls(x),L,mid);
	build(rs(x),mid+1,R);
	pushup(x);
}
int query_max(int x,int ql,int qr){
	if(ql<=tr[x].l&&tr[x].r<=qr)
		return tr[x].maxv;
	int mid=(tr[x].l+tr[x].r)>>1;
	if(qr<=mid)return query_max(ls(x),ql,qr);
	if(ql> mid)return query_max(rs(x),ql,qr);
	return max(query_max(ls(x),ql,qr),query_max(rs(x),ql,qr));
}
int query_min(int x,int ql,int qr){
	if(ql<=tr[x].l&&tr[x].r<=qr)
		return tr[x].minv;
	int mid=(tr[x].l+tr[x].r)>>1;
	if(qr<=mid)return query_min(ls(x),ql,qr);
	if(ql> mid)return query_min(rs(x),ql,qr);
	return min(query_min(ls(x),ql,qr),query_min(rs(x),ql,qr));
}
int main(){
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int n,m,q;cin>>n>>m>>q;
	for(int i=1;i<=n;++i)cin>>a[i];
	for(int i=1;i<=m;++i)cin>>b[i];
	build(1,1,m);
	while(q--){
		int l1,r1,l2,r2;
		cin>>l1>>r1>>l2>>r2;
		ll ans=-1e18;
		for(int i=l1;i<=r1;++i){
			if(a[i]==0)ans=max(ans,0ll);
			if(a[i]>0)ans=max(ans,1ll*a[i]*query_min(1,l2,r2));
			if(a[i]<0)ans=max(ans,1ll*a[i]*query_max(1,l2,r2));
		}
		cout<<ans<<'\n';
	}
	return 0;
}
