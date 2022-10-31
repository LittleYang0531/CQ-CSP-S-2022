#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N=1e5+5;
const int inf=0x3f3f3f3f;
int qr(){
	int s=0,f=1;
	char ch=getchar();
	while(ch<'0' || ch>'9') (ch=='-'?f=-1:1),ch=getchar();
	while(ch>='0' && ch<='9') s=s*10+ch-'0',ch=getchar();
	return s*f;
}
void qw(LL x){
	if(x<0) putchar('-'),x=-x;
	if(x>9) qw(x/10),putchar(x%10+'0');
	else putchar(x+'0');
}
int n,m,q,a[N],b[N];
struct node{
	int l,r,have1,have2,have3,have4,have5,x1,x2,x4,x5;
	/*
	1:-min
	2:-max
	3:0
	4:min
	5:max
	*/
}t1[N<<2],t2[N<<2];
void pushup1(int p){
	//1
	if(t1[p<<1].have1 && t1[p<<1|1].have1) t1[p].have1=1,t1[p].x1=min(t1[p<<1].x1,t1[p<<1|1].x1);
	else if(t1[p<<1].have1) t1[p].have1=1,t1[p].x1=t1[p<<1].x1;
	else if(t1[p<<1|1].have1) t1[p].have1=1,t1[p].x1=t1[p<<1|1].x1;
	//2
	if(t1[p<<1].have2 && t1[p<<1|1].have2) t1[p].have2=1,t1[p].x2=max(t1[p<<1].x2,t1[p<<1|1].x2);
	else if(t1[p<<1].have2) t1[p].have2=1,t1[p].x2=t1[p<<1].x2;
	else if(t1[p<<1|1].have2) t1[p].have2=1,t1[p].x2=t1[p<<1|1].x2;
	//3
	if(t1[p<<1].have3 || t1[p<<1|1].have3) t1[p].have3=1;
	//4
	if(t1[p<<1].have4 && t1[p<<1|1].have4) t1[p].have4=1,t1[p].x4=min(t1[p<<1].x4,t1[p<<1|1].x4);
	else if(t1[p<<1].have4) t1[p].have4=1,t1[p].x4=t1[p<<1].x4;
	else if(t1[p<<1|1].have4) t1[p].have4=1,t1[p].x4=t1[p<<1|1].x4;
	//5
	if(t1[p<<1].have5 && t1[p<<1|1].have5) t1[p].have5=1,t1[p].x5=max(t1[p<<1].x5,t1[p<<1|1].x5);
	else if(t1[p<<1].have5) t1[p].have5=1,t1[p].x5=t1[p<<1].x5;
	else if(t1[p<<1|1].have5) t1[p].have5=1,t1[p].x5=t1[p<<1|1].x5;
}
void pushup2(int p){
	//1
	if(t2[p<<1].have1 && t2[p<<1|1].have1) t2[p].have1=1,t2[p].x1=min(t2[p<<1].x1,t2[p<<1|1].x1);
	else if(t2[p<<1].have1) t2[p].have1=1,t2[p].x1=t2[p<<1].x1;
	else if(t2[p<<1|1].have1) t2[p].have1=1,t2[p].x1=t2[p<<1|1].x1;
	//2
	if(t2[p<<1].have2 && t2[p<<1|1].have2) t2[p].have2=1,t2[p].x2=max(t2[p<<1].x2,t2[p<<1|1].x2);
	else if(t2[p<<1].have2) t2[p].have2=1,t2[p].x2=t2[p<<1].x2;
	else if(t2[p<<1|1].have2) t2[p].have2=1,t2[p].x2=t2[p<<1|1].x2;
	//3
	if(t2[p<<1].have3 || t2[p<<1|1].have3) t2[p].have3=1;
	//4
	if(t2[p<<1].have4 && t2[p<<1|1].have4) t2[p].have4=1,t2[p].x4=min(t2[p<<1].x4,t2[p<<1|1].x4);
	else if(t2[p<<1].have4) t2[p].have4=1,t2[p].x4=t2[p<<1].x4;
	else if(t2[p<<1|1].have4) t2[p].have4=1,t2[p].x4=t2[p<<1|1].x4;
	//5
	if(t2[p<<1].have5 && t2[p<<1|1].have5) t2[p].have5=1,t2[p].x5=max(t2[p<<1].x5,t2[p<<1|1].x5);
	else if(t2[p<<1].have5) t2[p].have5=1,t2[p].x5=t2[p<<1].x5;
	else if(t2[p<<1|1].have5) t2[p].have5=1,t2[p].x5=t2[p<<1|1].x5;
}
void build1(int p,int l,int r){
	t1[p]=((node){l,r,0,0,0,0,0,inf,-inf,inf,-inf});
	if(l==r){
		if(a[l]<0) t1[p].have1=t1[p].have2=1,t1[p].x1=t1[p].x2=a[l];
		else if(a[l]==0) t1[p].have3=1;
		if(a[l]>0) t1[p].have4=t1[p].have5=1,t1[p].x4=t1[p].x5=a[l];
		return ;
	}
	int mid=l+r>>1;
	build1(p<<1,l,mid),build1(p<<1|1,mid+1,r),pushup1(p);
}
void build2(int p,int l,int r){
	t2[p]=((node){l,r,0,0,0,0,0,inf,-inf,inf,-inf});
	if(l==r){
		if(b[l]<0) t2[p].have1=t2[p].have2=1,t2[p].x1=t2[p].x2=b[l];
		else if(b[l]==0) t2[p].have3=1;
		if(b[l]>0) t2[p].have4=t2[p].have5=1,t2[p].x4=t2[p].x5=b[l];
		return ;
	}
	int mid=l+r>>1;
	build2(p<<1,l,mid),build2(p<<1|1,mid+1,r),pushup2(p);
}
bool have1(int p,int l,int r,int ty){
	if(t1[p].l>=l && t1[p].r<=r){
		if(ty==1) return t1[p].have1;
		if(ty==2) return t1[p].have2;
		if(ty==3) return t1[p].have3;
		if(ty==4) return t1[p].have4;
		if(ty==5) return t1[p].have5;
	}
	int mid=t1[p].l+t1[p].r>>1;
	bool res=0;
	if(l<=mid) res=have1(p<<1,l,r,ty);
	if(r>mid) res|=have1(p<<1|1,l,r,ty);
	return res;
}
bool have2(int p,int l,int r,int ty){
	if(t2[p].l>=l && t2[p].r<=r){
		if(ty==1) return t2[p].have1;
		if(ty==2) return t2[p].have2;
		if(ty==3) return t2[p].have3;
		if(ty==4) return t2[p].have4;
		if(ty==5) return t2[p].have5;
	}
	int mid=t2[p].l+t2[p].r>>1;
	bool res=0;
	if(l<=mid) res=have2(p<<1,l,r,ty);
	if(r>mid) res|=have2(p<<1|1,l,r,ty);
	return res;
}
int ask1(int p,int l,int r,int ty){
	if(t1[p].l>=l && t1[p].r<=r){
		if(ty==1) return t1[p].x1;
		if(ty==2) return t1[p].x2;
		if(ty==4) return t1[p].x4;
		if(ty==5) return t1[p].x5;
	}
	int mid=t1[p].l+t1[p].r>>1,res;
	if(ty==1) res=inf;
	if(ty==2) res=-inf;
	if(ty==4) res=inf;
	if(ty==5) res=-inf;
	if(l<=mid) res=ask1(p<<1,l,r,ty);
	if(r>mid){
		if(ty==1) res=min(res,ask1(p<<1|1,l,r,ty));
		if(ty==2) res=max(res,ask1(p<<1|1,l,r,ty));
		if(ty==4) res=min(res,ask1(p<<1|1,l,r,ty));
		if(ty==5) res=max(res,ask1(p<<1|1,l,r,ty));
	}
	return res;
}
int ask2(int p,int l,int r,int ty){
	if(t2[p].l>=l && t2[p].r<=r){
		if(ty==1) return t2[p].x1;
		if(ty==2) return t2[p].x2;
		if(ty==4) return t2[p].x4;
		if(ty==5) return t2[p].x5;
	}
	int mid=t2[p].l+t2[p].r>>1,res;
	if(ty==1) res=inf;
	if(ty==2) res=-inf;
	if(ty==4) res=inf;
	if(ty==5) res=-inf;
	if(l<=mid) res=ask2(p<<1,l,r,ty);
	if(r>mid){
		if(ty==1) res=min(res,ask2(p<<1|1,l,r,ty));
		if(ty==2) res=max(res,ask2(p<<1|1,l,r,ty));
		if(ty==4) res=min(res,ask2(p<<1|1,l,r,ty));
		if(ty==5) res=max(res,ask2(p<<1|1,l,r,ty));
	}
	return res;
}
int main(){
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	n=qr(),m=qr(),q=qr();
	for(int i=1;i<=n;i++) a[i]=qr();
	for(int i=1;i<=m;i++) b[i]=qr();
	build1(1,1,n),build2(1,1,m);
	while(q--){
		int l1=qr(),r1=qr(),l2=qr(),r2=qr(),have11,have12,have13,have14,have15,have21,have22,have23,have24,have25,x11,x12,x13,x14,x15,x21,x22,x23,x24,x25;
		LL ans=-1000000000000000000;
		have11=have1(1,l1,r1,1);
		have12=have1(1,l1,r1,2);
		have13=have1(1,l1,r1,3);
		have14=have1(1,l1,r1,4);
		have15=have1(1,l1,r1,5);
		have21=have2(1,l2,r2,1);
		have22=have2(1,l2,r2,2);
		have23=have2(1,l2,r2,3);
		have24=have2(1,l2,r2,4);
		have25=have2(1,l2,r2,5);
		if(have11) x11=ask1(1,l1,r1,1);
		if(have12) x12=ask1(1,l1,r1,2);
		if(have13) x13=0;
		if(have14) x14=ask1(1,l1,r1,4);
		if(have15) x15=ask1(1,l1,r1,5);
		if(have21) x21=ask2(1,l2,r2,1);
		if(have22) x22=ask2(1,l2,r2,2);
		if(have23) x23=0;
		if(have24) x24=ask2(1,l2,r2,4);
		if(have25) x25=ask2(1,l2,r2,5);
//		printf("%d %d %d %d %d %d %d %d %d %d\n",have11,have12,have13,have14,have15,have21,have22,have23,have24,have25);
//		printf("%d %d %d %d %d %d %d %d %d %d\n",x11,x12,x13,x14,x15,x21,x22,x23,x24,x25);
		if(have11){
			if(have25) ans=max(ans,1ll*x11*x25);
			else if(!have25 && have23) ans=max(ans,0ll);
			else if(!have25 && !have23) ans=max(ans,1ll*x11*x22);
		}
		if(have12){
			if(have25) ans=max(ans,1ll*x12*x25);
			else if(!have25 && have23) ans=max(ans,0ll);
			else if(!have25 && !have23) ans=max(ans,1ll*x12*x22);
		}
		if(have13) ans=max(ans,0ll);
		if(have14){
			if(have21) ans=max(ans,1ll*x14*x21);
			else if(!have21 && have23) ans=max(ans,0ll);
			else if(!have21 && !have23) ans=max(ans,1ll*x14*x24);
		}
		if(have15){
			if(have21) ans=max(ans,1ll*x15*x21);
			else if(!have21 && have23) ans=max(ans,0ll);
			else if(!have21 && !have23) ans=max(ans,1ll*x15*x24);
		}
		qw(ans),putchar('\n');
	}
	return 0;
} 
/*
3 2 2
0 1 -2
-3 4
1 3 1 2
2 3 2 2

6 4 1
3 -1 -2 1 2 0
1 2 -1 -3
1 5 1 4
*/
