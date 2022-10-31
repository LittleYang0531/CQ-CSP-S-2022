#include<bits/stdc++.h>
#define int long long
#define ls (lr<<1)
#define rs (lr<<1|1)
#define mid ((l+r)>>1)
using namespace std;
inline int read(){
	int x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9')x=(x<<3)+(x<<1)+(ch^48),ch=getchar();
	return x*f;
}
void write(int x){
	if(x<0) putchar('-'),x=-x;
	if(x>=10) write(x/10);
	putchar(x%10+'0');
}
const int N = 1e5+10,inf = 1e9;
struct node{
	int zx,zi,fx,fi;
}q1,q2;
int n,m,q;
int a[N],b[N];
node merge(node x,node y){
	return {max(x.zx,y.zx),min(x.zi,y.zi),max(x.fx,y.fx),min(x.fi,y.fi)};
}
namespace t1{
	node t[N<<2];
	node build(int l,int r,int lr){
		if(l==r){
			if(a[l]<0) return t[lr]={-1,inf,-a[l],-a[l]};
			return t[lr]={a[l],a[l],-1,inf};
		}
		return t[lr] = merge(build(l,mid,ls),build(mid+1,r,rs));
	}
	node query(int l,int r,int L,int R,int lr){
		if(l>=L and r<=R) return t[lr];
		if(mid>=L and mid<R) return merge(query(l,mid,L,R,ls),query(mid+1,r,L,R,rs));
		return mid>=L?query(l,mid,L,R,ls):query(mid+1,r,L,R,rs);
	}
}
namespace t2{
	node t[N<<2];
	node build(int l,int r,int lr){
		if(l==r){
			if(b[l]<0) return t[lr]={-1,inf,-b[l],-b[l]};
			return t[lr]={b[l],b[l],-1,inf};
		}
		return t[lr] = merge(build(l,mid,ls),build(mid+1,r,rs));
	}
	node query(int l,int r,int L,int R,int lr){
		if(l>=L and r<=R) return t[lr];
		if(mid>=L and mid<R) return merge(query(l,mid,L,R,ls),query(mid+1,r,L,R,rs));
		return mid>=L?query(l,mid,L,R,ls):query(mid+1,r,L,R,rs);
	}
}
void init(){t1::build(1,n,1),t2::build(1,m,1);}
int solve(node x,node y){
	int ans = -inf*inf,now1,now2;
	if(x.zx>0){
		now1 = now2 = inf*inf;
		if(y.zx>0) now1 = x.zx*y.zi,now2 = x.zi*y.zi;
		if(y.fx>0) now1 = -x.zx*y.fx,now2 = -x.zi*y.fx;
		ans = max(now1,now2);
	}
	if(x.fx>0){
		now1 = now2 = inf*inf;
		if(y.fx>0) now1 = x.fx*y.fi,now2 = x.fi*y.fi;
		if(y.zx>0) now1 = -x.fx*y.zx,now2 = -x.fi*y.zx;
		ans = max(ans,max(now1,now2));
	}
	return ans;
}
signed main(){
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	n = read(),m = read(),q = read();
	for(int i = 1;i<=n;i++) a[i] = read();
	for(int i = 1;i<=m;i++) b[i] = read();
	init();
	while(q--){
		int l1 = read(),r1 = read(),l2 = read(),r2 = read();
		write(solve(t1::query(1,n,l1,r1,1),t2::query(1,m,l2,r2,1))),putchar('\n');
	}
	return 0;
}

