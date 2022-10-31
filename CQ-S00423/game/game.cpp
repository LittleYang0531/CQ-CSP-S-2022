#include<stdio.h>
template<typename T>
inline T fmax(const T&x,const T&y){
	return x>y?x:y;
}
template<typename T>
inline T fmin(const T&x,const T&y){
	return x<y?x:y;
}
const int inf=0x3f3f3f3f;
int a[100005],b[100005];
struct A_tree{
	struct segment{
		int l,r;
		int zero,max,min,mmax,mmin;
		inline friend segment operator+(const segment&x,const segment&y){
			segment res;
			res.l=x.l;res.r=y.r;
			res.zero=x.zero|y.zero;
			res.max=fmax(x.max,y.max);
			res.mmax=fmax(x.mmax,y.mmax);
			res.min=fmin(x.min,y.min);
			res.mmin=fmin(x.mmin,y.mmin);
			return res;
		}
	}t[400005];
	void build(int p,int l,int r){
		t[p].l=l;t[p].r=r;
		if(l==r){
			if(a[l]<0)t[p].max=a[l];
			else t[p].max=-inf;
			if(a[l]>0)t[p].min=a[l];
			else t[p].min=inf;
			t[p].mmax=t[p].mmin=a[l];
			t[p].zero=!a[l];
			return;
		}
		int mid=l+r>>1;
		build(p<<1,l,mid);
		build(p<<1|1,mid+1,r);
		t[p]=t[p<<1]+t[p<<1|1];
	}
	segment ask(int p,int l,int r){
		if(t[p].l>=l&&t[p].r<=r)return t[p];
		int mid=t[p].l+t[p].r>>1;
		if(r<=mid)return ask(p<<1,l,r);
		if(l>mid)return ask(p<<1|1,l,r);
		return ask(p<<1,l,r)+ask(p<<1|1,l,r);
	}
	void query(int l,int r,int &z,int&x,int&y,int&p,int&q){
		segment res=ask(1,l,r);
		z=res.zero;
		x=res.max;
		y=res.min;
		p=res.mmax;
		q=res.mmin;
	}
}A;
struct B_tree{
	struct segment{
		int l,r;
		int max,min;
		inline friend segment operator+(const segment&x,const segment&y){
			segment res;
			res.l=x.l;res.r=y.r;
			res.max=fmax(x.max,y.max);
			res.min=fmin(x.min,y.min);
			return res;
		}
	}t[400005];
	void build(int p,int l,int r){
		t[p].l=l;t[p].r=r;
		if(l==r){
			t[p].max=t[p].min=b[l];
			return;
		}
		int mid=l+r>>1;
		build(p<<1,l,mid);
		build(p<<1|1,mid+1,r);
		t[p]=t[p<<1]+t[p<<1|1];
	}
	segment ask(int p,int l,int r){
		if(t[p].l>=l&&t[p].r<=r)return t[p];
		int mid=t[p].l+t[p].r>>1;
		if(r<=mid)return ask(p<<1,l,r);
		if(l>mid)return ask(p<<1|1,l,r);
		return ask(p<<1,l,r)+ask(p<<1|1,l,r);
	}
	void query(int l,int r,int&x,int&y){
		segment res=ask(1,l,r);
		x=res.max;
		y=res.min;
	}
}B;
int n,m,q;
long long res;
int main(){
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	scanf("%d%d%d",&n,&m,&q);
	for(int i=1;i<=n;scanf("%d",&a[i++]));
	for(int i=1;i<=m;scanf("%d",&b[i++]));
	A.build(1,1,n);
	B.build(1,1,m);
	for(int l1,r1,l2,r2,bmin,bmax,zero,amin,amax,ammin,ammax;q--;){
		scanf("%d%d%d%d",&l1,&r1,&l2,&r2);
		A.query(l1,r1,zero,amax,amin,ammax,ammin);
		B.query(l2,r2,bmax,bmin);
		res=1ll<<63;
		if(zero)res=0;
//		printf("%d %d %d %d: ",amin,amax,bmin,bmax);
		if(amin!=inf&&res<1ll*amin*bmin)res=1ll*amin*bmin;
		if(bmin>=0&&ammax>=0&&res<1ll*ammax*bmin)res=1ll*ammax*bmin;
		if(bmax<=0&&ammin<=0&&res<1ll*ammin*bmax)res=1ll*ammin*bmax;
		if(amax!=-inf&&res<1ll*amax*bmax)res=1ll*amax*bmax;
//		for(int i=l1;i<=r1;++i){
//			if(a[i]>0){
//				if(res<1ll*a[i]*bmin)res=1ll*a[i]*bmin;
//			}else if(a[i]<0){
//				if(res<1ll*a[i]*bmax)res=1ll*a[i]*bmax;
//			}
//		}
		printf("%lld\n",res);
	}
	return 0;
}
/*
6 4 5
3 -1 -2 1 2 0
1 2 -1 -3
1 6 1 4
1 5 1 4
1 4 1 2
2 6 3 4
2 5 2 3
*/
/*
L: +	Q:min
L: 0    Q:qwq
L: -    Q:max
*/
