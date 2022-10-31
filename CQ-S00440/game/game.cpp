#include <bits/stdc++.h>
#define int long long
#define ls (x<<1)
#define rs (x<<1|1)
#define mid ((l+r)>>1)
using namespace std;
bool lmg;
int read() {
	int x(0),f(0);
	char ch=getchar();
	while(!isdigit(ch)) f|=(ch=='-'),ch=getchar();
	while(isdigit(ch)) x=x*10+ch-'0',ch=getchar();
	return f?-x:x;
}
const int N=100005,inf=9223372036854775807ll;
int n,m,q,a[N],b[N];
struct node {
	int pma,pmi,nma,nmi;
	bool ze;
};
node merge(node x,node y) {
	x.ze|=y.ze;
	if(y.pma>0) {
		if(x.pma>0) x.pma=max(x.pma,y.pma),x.pmi=min(x.pmi,y.pmi);
		else x.pma=y.pma,x.pmi=y.pmi;
	}
	if(y.nma<0) {
		if(x.nma<0) x.nma=min(x.nma,y.nma),x.nmi=max(x.nmi,y.nmi);
		else x.nma=y.nma,x.nmi=y.nmi;
	}
	return x;
}
//struct SGT {
//	node t[N<<2];
//	int id;
//	void build(int x,int l,int r) {
//		if(l==r) {
//			int v;
//			if(id==1) v=a[l];
//			else v=b[l];
//			if(v>0) t[x].ze=0,t[x].pma=t[x].pmi=v,t[x].nmi=t[x].nma=1;
//			else if(v<0) t[x].ze=0,t[x].pma=t[x].pmi=-1,t[x].nmi=t[x].nma=v;
//			else t[x].ze=1,t[x].pma=t[x].pmi=-1,t[x].nma=t[x].nmi=1;
//			return;
//		}
//		build(ls,l,mid);
//		build(rs,mid+1,r);
//		t[x]=merge(t[ls],t[rs]);
//	}
//	node query(int x,int l,int r,int L,int R) {
//		if(l==L&&r==R) return t[x];
//		if(R<=mid) return query(ls,l,mid,L,R);
//		if(L>mid) return query(rs,mid+1,r,L,R)
//		return merge(query(ls,l,mid,L,mid),query(rs,mid+1,r,mid+1,R));
//	}
//} t1,t2;
int lg[N],mul[N];
node t1[17][N],t2[17][N];
void init() {
	for(int i=2;i<=100000;++i) {
		lg[i]=lg[i-1];
		if((1<<(lg[i]+1))==i) ++lg[i];
	}
	for(int i=0;i<=17;++i) mul[i]=1<<i;
	for(int i=1;i<=n;++i) {
		int v=a[i];
		if(v>0) t1[0][i]=(node) {v,v,1,1,0};
		else if(v<0) t1[0][i]=(node) {-1,-1,v,v,0};
		else t1[0][i]=(node) {-1,-1,1,1,1};
	}
	for(int i=1;i<=m;++i) {
		int v=b[i];
		if(v>0) t2[0][i]=(node) {v,v,1,1,0};
		else if(v<0) t2[0][i]=(node) {-1,-1,v,v,0};
		else t2[0][i]=(node) {-1,-1,1,1,1};
	}
	for(int i=1;i<=lg[n];++i)
	for(int j=1;j+mul[i]-1<=n;++j)
		t1[i][j]=merge(t1[i-1][j],t1[i-1][j+mul[i-1]]);
	for(int i=1;i<=lg[m];++i)
	for(int j=1;j+mul[i]-1<=m;++j)
		t2[i][j]=merge(t2[i-1][j],t2[i-1][j+mul[i-1]]);
}
node ask1(int l,int r) {
	int i=lg[r-l+1];
	return merge(t1[i][l],t1[i][r-mul[i]+1]);
}
node ask2(int l,int r) {
	int i=lg[r-l+1];
	return merge(t2[i][l],t2[i][r-mul[i]+1]);
}
int calc(int x,node y) {
	if(x==0) return 0;
	else if(x>0) {
		if(y.nma<0) return x*y.nma;
		if(y.ze) return 0;
		return x*y.pmi;
	}
	else {
		if(y.pma>0) return x*y.pma;
		if(y.ze) return 0;
		return x*y.nmi;
	}
}
bool oat;
signed main() {
//	cerr<<(&lmg-&oat)/1024.0/1024.0<<endl;
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	n=read(),m=read(),q=read();
	for(int i=1;i<=n;++i) a[i]=read();
	for(int i=1;i<=m;++i) b[i]=read();
//	t1.id=1;
//	t1.build(1,1,n);
//	t2.id=2;
//	t2.build(1,1,m);
	init();
	while(q--) {
		int la=read(),ra=read(),lb=read(),rb=read(),ans=-inf;
		node x=ask1(la,ra),y=ask2(lb,rb);
//		cerr<<x.pma<<" "<<x.pmi<<" "<<x.nma<<" "<<x.nmi<<" "<<x.ze<<endl;
//		cerr<<y.pma<<" "<<y.pmi<<" "<<y.nma<<" "<<y.nmi<<" "<<y.ze<<endl;
//		cerr<<endl;
		if(x.ze) ans=0;
		if(x.pma>0) ans=max(ans,calc(x.pma,y))/*,cerr<<calc(x.pma,y)<<endl*/;
		if(x.pmi>0) ans=max(ans,calc(x.pmi,y))/*,cerr<<calc(x.pmi,y)<<endl*/;
		if(x.nma<0) ans=max(ans,calc(x.nma,y))/*,cerr<<calc(x.nma,y)<<endl*/;
		if(x.nmi<0) ans=max(ans,calc(x.nmi,y))/*,cerr<<calc(x.nmi,y)<<endl*/;
		printf("%lld\n",ans);
	}
	return 0;
}
/*
3 2 2
0 1 -2
-3 4
1 3 1 2
2 3 2 2

0
4
*/
