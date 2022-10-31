#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e5+5;
const ll INF=1e18;
void readint(int &x){
	char s=getchar();
	x=0;int f=1;
	while(s<'0'||s>'9'){
		if(s=='-')	f=-1;
		s=getchar();
	}
	while(s>='0'&&s<='9'){
		x=x*10+s-'0';
		s=getchar();
	}
	x*=f;
}
void readll(ll &x){
	char s=getchar();
	x=0;ll f=1;
	while(s<'0'||s>'9'){
		if(s=='-')	f=-1;
		s=getchar();
	}
	while(s>='0'&&s<='9'){
		x=x*10+s-'0';
		s=getchar();
	}
	x*=f;
}
void print(ll x){
	if(x<0){
		putchar('-');
		print(-x);
		return ;
	}
	if(x>9)	print(x/10);
	putchar(x%10+'0');
}
ll a[2][N];
struct Node{
	ll pos_max,pos_min;
	ll neg_max,neg_min;
	bool zero;
}tr[2][N<<2];
void init(Node &u){
	u.pos_max=-INF;
		u.pos_min=INF;
		u.neg_max=-INF;
		u.neg_min=INF;
		u.zero=0;
}
Node pushup(int typ,Node ls,Node rs){
	Node u;
	u.pos_max=max(ls.pos_max,rs.pos_max);
	u.pos_min=min(ls.pos_min,rs.pos_min);
	u.neg_max=max(ls.neg_max,rs.neg_max);
	u.neg_min=min(ls.neg_min,rs.neg_min);
	u.zero=ls.zero||rs.zero;
	return u;
}
void build(int typ,int id,Node &u,int l,int r){
	if(l>=r){
		init(u);
		if(a[typ][l]>0)
			u.pos_max=u.pos_min=a[typ][l];
		if(a[typ][l]<0)
			u.neg_max=u.neg_min=a[typ][l];
		if(a[typ][l]==0)
			u.zero=1;
		return ;
	}
	int ls=id<<1,rs=ls+1,mid=(l+r)>>1;
	build(typ,ls,tr[typ][ls],l,mid);
	build(typ,rs,tr[typ][rs],mid+1,r);
	u=pushup(typ,tr[typ][ls],tr[typ][rs]);
}
Node query(int tp,int id,int l,int r,int lb,int rb){
	if(l>=lb&&r<=rb)
		return tr[tp][id];
	int ls=id<<1,rs=ls+1,mid=(l+r)>>1;
	Node u;init(u);
	if(mid>=lb)
		u=pushup(tp,u,query(tp,ls,l,mid,lb,rb));
	if(mid<rb)
		u=pushup(tp,u,query(tp,rs,mid+1,r,lb,rb));
	return u;
}
ll calc(ll val,Node y){
	ll tmp=INF;
	if(y.zero)	tmp=0;
	if(y.pos_max!=-INF)
		tmp=min(tmp,val*y.pos_max);
	if(y.pos_min!=INF)
		tmp=min(tmp,val*y.pos_min);
	if(y.neg_max!=-INF)
		tmp=min(tmp,val*y.neg_max);
	if(y.neg_min!=INF)
		tmp=min(tmp,val*y.neg_min);
	return tmp;
}
int main(){
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	int n,m,q;
	readint(n),readint(m),readint(q);
	for(int i=1;i<=n;++i)
		readll(a[0][i]);
	for(int i=1;i<=m;++i)
		readll(a[1][i]);
	build(0,1,tr[0][1],1,n);
	build(1,1,tr[1][1],1,m);
	while(q--){
		int l1,r1,l2,r2;
		readint(l1),readint(r1);
		readint(l2),readint(r2);
		Node x=query(0,1,1,n,l1,r1);
		Node y=query(1,1,1,m,l2,r2);
		ll res=-INF;
		if(x.zero)	res=0;
		if(x.pos_max!=-INF)
			res=max(res,calc(x.pos_max,y));
		if(x.pos_min!=INF)
			res=max(res,calc(x.pos_min,y));
		if(x.neg_max!=-INF)
			res=max(res,calc(x.neg_max,y));
		if(x.neg_min!=INF)
			res=max(res,calc(x.neg_min,y));
		print(res),puts("");
	}
	return 0;
}
