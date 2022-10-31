#include<bits/stdc++.h>
#define LL long long
using namespace std;
const LL inf=1000000009;
inline int read(){
	bool SF=false;int XF=0;char CH=getchar();
	for(;CH<'0'||CH>'9';CH=getchar()) if(CH=='-') SF=true;
	for(;CH>='0'&&CH<='9';CH=getchar()) XF=(XF<<3)+(XF<<1)+(CH-'0');
	if(SF) XF=-XF; return XF;
}
inline LL readl(){
	bool SF=false;LL XF=0;char CH=getchar();
	for(;CH<'0'||CH>'9';CH=getchar()) if(CH=='-') SF=true;
	for(;CH>='0'&&CH<='9';CH=getchar()) XF=(XF<<3)+(XF<<1)+(CH-'0');
	if(SF) XF=-XF; return XF;
}
int N,M,Q;
LL a[100005],b[100005];
struct Tl{
	int l,r;
	LL zmaxn,zminn;
	LL fmaxn,fminn;
	Tl(){
		zmaxn=-inf;
		zminn=inf;
		fminn=inf;
		fmaxn=-inf;
	}
}tl[300005];
inline void buildl(int l,int r,int m){
	tl[m].l=l;
	tl[m].r=r;;
	if(l>=r){
		if(a[l]>0){
			tl[m].zmaxn=tl[m].zminn=a[l];
		}
		else{
			if(a[l]<0){
				tl[m].fmaxn=tl[m].fminn=a[l];
			}
			else{
				tl[m].zmaxn=tl[m].zminn=tl[m].fmaxn=tl[m].fminn=0;
			}
		}
		return;
	}
	int mid=(l+r)/2;
	buildl(l,mid,m*2);
	buildl(mid+1,r,m*2+1);
	tl[m].zmaxn=tl[m*2].zmaxn;
	if(tl[m*2+1].zmaxn!=-inf){
		tl[m].zmaxn=max(tl[m].zmaxn,tl[m*2+1].zmaxn);
	}
	
	tl[m].zminn=tl[m*2].zminn;
	if(tl[m*2+1].zminn!=inf){
		tl[m].zminn=min(tl[m].zminn,tl[m*2+1].zminn);
	}
	
	
	tl[m].fmaxn=tl[m*2].fmaxn;
	if(tl[m*2+1].fmaxn!=-inf){
		tl[m].fmaxn=max(tl[m].fmaxn,tl[m*2+1].fmaxn);
	}
	
	tl[m].fminn=tl[m*2].fminn;
	if(tl[m*2+1].fminn!=inf){
		tl[m].fminn=min(tl[m].fminn,tl[m*2+1].fminn);
	}
}
inline LL finlzx(int l,int r,int m){
	int nl=tl[m].l;
	int nr=tl[m].r;
	if(nl==l&&nr==r){
		return tl[m].zminn;
	}
	int mid=(nl+nr)/2;
	if(mid>=r){
		return finlzx(l,r,m*2);
	}
	if(mid<l){
		return finlzx(l,r,m*2+1);
	}
	return min(finlzx(l,mid,m*2),finlzx(mid+1,r,m*2+1));
}
inline LL finlzd(int l,int r,int m){
	int nl=tl[m].l;
	int nr=tl[m].r;
	if(nl==l&&nr==r){
		return tl[m].zmaxn;
	}
	int mid=(nl+nr)/2;
	if(mid>=r){
		return finlzd(l,r,m*2);
	}
	if(mid<l){
		return finlzd(l,r,m*2+1);
	}
	return max(finlzd(l,mid,m*2),finlzd(mid+1,r,m*2+1));
}
inline LL finlfx(int l,int r,int m){
	int nl=tl[m].l;
	int nr=tl[m].r;
	if(nl==l&&nr==r){
		return tl[m].fminn;
	}
	int mid=(nl+nr)/2;
	if(mid>=r){
		return finlfx(l,r,m*2);
	}
	if(mid<l){
		return finlfx(l,r,m*2+1);
	}
	return min(finlfx(l,mid,m*2),finlfx(mid+1,r,m*2+1));
}
inline LL finlfd(int l,int r,int m){
	int nl=tl[m].l;
	int nr=tl[m].r;
	if(nl==l&&nr==r){
		return tl[m].fmaxn;
	}
	int mid=(nl+nr)/2;
	if(mid>=r){
		return finlfd(l,r,m*2);
	}
	if(mid<l){
		return finlfd(l,r,m*2+1);
	}
	return max(finlfd(l,mid,m*2),finlfd(mid+1,r,m*2+1));
}
struct T{
	int l,r;
	LL maxn,minn;
}tq[300005];
inline void build(int l,int r,int m){
	tq[m].l=l;
	tq[m].r=r;
	if(l>=r){
		tq[m].minn=tq[m].maxn=b[l];
		return;
	}
	int mid=(l+r)/2;
	build(l,mid,m*2);
	build(mid+1,r,m*2+1);
	tq[m].maxn=max(tq[m*2].maxn,tq[m*2+1].maxn);
	tq[m].minn=min(tq[m*2].minn,tq[m*2+1].minn);
}
inline LL finx(int l,int r,int m){
	int nl=tq[m].l;
	int nr=tq[m].r;
	if(nl==l&&nr==r){
		return tq[m].minn;
	}
	int mid=(nl+nr)/2;
	if(mid>=r){
		return finx(l,r,m*2);
	}
	if(mid<l){
		return finx(l,r,m*2+1);
	}
	return min(finx(l,mid,m*2),finx(mid+1,r,m*2+1));
}
inline LL finda(int l,int r,int m){
	int nl=tq[m].l;
	int nr=tq[m].r;
	if(nl==l&&nr==r){
		return tq[m].maxn;
	}
	int mid=(nl+nr)/2;
	if(mid>=r){
		return finda(l,r,m*2);
	}
	if(mid<l){
		return finda(l,r,m*2+1);
	}
	return max(finda(l,mid,m*2),finda(mid+1,r,m*2+1));
}
int main(){
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);	
	N=read();
	M=read();
	Q=read();
	for(int i=1;i<=N;i++){
		a[i]=readl();
	}
	for(int i=1;i<=M;i++){
		b[i]=readl();
	}
	buildl(1,N,1);
	build(1,M,1);
	int l1,r1,l2,r2;
	LL rt=0,qx,qd;
	LL nnn=0;
	for(int i=1;i<=Q;i++){
		rt=-inf*inf;
		l1=read(),r1=read(),l2=read(),r2=read();
		qx=finx(l2,r2,1);
		qd=finda(l2,r2,1);
		if(qx>=0){
			nnn=finlzd(l1,r1,1);
			if(nnn!=inf&&nnn!=-inf)
				rt=max(rt,qx*nnn);
		}
		else{
			nnn=finlzx(l1,r1,1);
			if(nnn!=inf&&nnn!=-inf)
				rt=max(rt,qx*nnn);
		}
		if(qd>=0){
			nnn=finlfd(l1,r1,1);
			if(nnn!=inf&&nnn!=-inf)
				rt=max(rt,qd*nnn);
		}
		else{
			nnn=finlfx(l1,r1,1);
			if(nnn!=inf&&nnn!=-inf)
				rt=max(rt,qd*nnn);
		}
		printf("%lld\n",rt);
	}
	return 0;
}
