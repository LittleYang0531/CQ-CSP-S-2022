#include<bits/stdc++.h>
#define INF 0x7fffffff
#define int long long
using namespace std;
const unsigned int N=1e5+15;
int n,m,q,c[N],d[N];
struct Segment_Tree{
	int l;
	int r;
	int maxval;
	int minval;
	int abslval;
	int absrval;
	bool zeroval;
}a[N*4],b[N*4];
inline void read(int &x){
	x=0;
	int y=1;
	char ch=getchar();
	while(!isdigit(ch)){
		if(ch=='-')
		y=-1;
		ch=getchar();
	}
	while(isdigit(ch)){
		x=(x<<1)+(x<<3)+(ch^48);
		ch=getchar();
	}
	x*=y;
}
inline void write(int x,bool wrap){
	if(x<0){
		x=-x;
		putchar('-');
	}
	if(x>9)
	write(x/10,false);
	putchar(x%10+48);
	if(wrap)
	printf("\n");
}
void pushup1(int x){
	a[x].maxval=max(a[x<<1].maxval,a[x<<1|1].maxval);
	a[x].minval=min(a[x<<1].minval,a[x<<1|1].minval);
	a[x].abslval=max(a[x<<1].abslval,a[x<<1|1].abslval);
	a[x].absrval=min(a[x<<1].absrval,a[x<<1|1].absrval);
	if(a[x<<1].zeroval||a[x<<1|1].zeroval)
	a[x].zeroval=true;
}
void pushup2(int x){
	b[x].maxval=max(b[x<<1].maxval,b[x<<1|1].maxval);
	b[x].minval=min(b[x<<1].minval,b[x<<1|1].minval);
	b[x].abslval=max(b[x<<1].abslval,b[x<<1|1].abslval);
	b[x].absrval=min(b[x<<1].absrval,b[x<<1|1].absrval);
	if(b[x<<1].zeroval||b[x<<1|1].zeroval)
	b[x].zeroval=true;
}
void build1(int x,int l,int r){
	a[x].l=l;
	a[x].r=r;
	if(l==r){
		a[x].maxval=a[x].minval=c[l];
		if(c[l]>0){
			a[x].absrval=c[l];
			a[x].abslval=-INF;
			a[x].zeroval=false;
		}
		if(c[l]<0){
			a[x].abslval=c[l];
			a[x].absrval=INF;
			a[x].zeroval=false;
		}
		if(c[l]==0){
			a[x].zeroval=true;
			a[x].abslval=-INF;
			a[x].absrval=INF;
		}
		return;
	}
	int mid=(l+r)>>1;
	build1(x<<1,l,mid);
	build1(x<<1|1,mid+1,r);
	pushup1(x);
	//printf("%lld -> %lld minval=%lld\n",l,r,a[x].minval);
}
void build2(int x,int l,int r){
	b[x].l=l;
	b[x].r=r;
	if(l==r){
		b[x].maxval=b[x].minval=d[l];
		if(d[l]>0){
			b[x].absrval=d[l];
			b[x].abslval=-INF;
			b[x].zeroval=false;
		}
		if(d[l]<0){
			b[x].abslval=d[l];
			b[x].absrval=INF;
			b[x].zeroval=false;
		}
		if(d[l]==0){
			b[x].zeroval=true;
			b[x].abslval=-INF;
			b[x].absrval=INF;
		}
		return;
	}
	int mid=(l+r)>>1;
	build2(x<<1,l,mid);
	build2(x<<1|1,mid+1,r);
	pushup2(x);
}
int query_max1(int x,int l,int r){
	//printf("querying.. max1 on node(%lld)  %lld -> %lld  target(%lld -> %lld)\n",x,a[x].l,a[x].r,l,r);
	if(l<=a[x].l&&r>=a[x].r)
	return a[x].maxval;
	int res=-INF;
	int mid=(a[x].l+a[x].r)>>1;
	if(l<=mid)
	res=max(res,query_max1(x<<1,l,r));
	if(r>mid)
	res=max(res,query_max1(x<<1|1,l,r));
	return res;
}
int query_max2(int x,int l,int r){
	if(l<=b[x].l&&r>=b[x].r)
	return b[x].maxval;
	int res=-INF;
	int mid=(b[x].l+b[x].r)>>1;
	if(l<=mid)
	res=max(res,query_max2(x<<1,l,r));
	if(r>mid)
	res=max(res,query_max2(x<<1|1,l,r));
	return res;
}
int query_min1(int x,int l,int r){
	//printf("querying.. min1 on node(%lld)  %lld -> %lld  target(%lld -> %lld)\n",x,a[x].l,a[x].r,l,r);
	if(l<=a[x].l&&r>=a[x].r)
	return a[x].minval;
	int res=INF;
	int mid=(a[x].l+a[x].r)>>1;
	if(l<=mid)
	res=min(res,query_min1(x<<1,l,r));
	if(r>mid)
	res=min(res,query_min1(x<<1|1,l,r));
	return res;
}
int query_min2(int x,int l,int r){
	if(l<=b[x].l&&r>=b[x].r)
	return b[x].minval;
	int res=INF;
	int mid=(b[x].l+b[x].r)>>1;
	if(l<=mid)
	res=min(res,query_min2(x<<1,l,r));
	if(r>mid)
	res=min(res,query_min2(x<<1|1,l,r));
	return res;
}
int query_absl1(int x,int l,int r){
	if(l<=a[x].l&&r>=a[x].r)
	return a[x].abslval;
	int res=-INF;
	int mid=(a[x].l+a[x].r)>>1;
	if(l<=mid)
	res=max(res,query_absl1(x<<1,l,r));
	if(r>mid)
	res=max(res,query_absl1(x<<1|1,l,r));
	return res;
}
int query_absl2(int x,int l,int r){
	if(l<=b[x].l&&r>=b[x].r)
	return b[x].abslval;
	int res=-INF;
	int mid=(b[x].l+b[x].r)>>1;
	if(l<=mid)
	res=max(res,query_absl2(x<<1,l,r));
	if(r>mid)
	res=max(res,query_absl2(x<<1|1,l,r));
	return res;
}
int query_absr1(int x,int l,int r){
	if(l<=a[x].l&&r>=a[x].r)
	return a[x].absrval;
	int res=INF;
	int mid=(a[x].l+a[x].r)>>1;
	if(l<=mid)
	res=min(res,query_absr1(x<<1,l,r));
	if(r>mid)
	res=min(res,query_absr1(x<<1|1,l,r));
	return res; 
}
int query_absr2(int x,int l,int r){
	if(l<=b[x].l&&r>=b[x].r)
	return b[x].absrval;
	int res=INF;
	int mid=(b[x].l+b[x].r)>>1;
	if(l<=mid)
	res=min(res,query_absr2(x<<1,l,r));
	if(r>mid)
	res=min(res,query_absr2(x<<1|1,l,r));
	return res; 
}
bool query_zero1(int x,int l,int r){
	if(l<=a[x].l&&r>=a[x].r)
	return a[x].zeroval;
	bool res=false;
	int mid=(a[x].l+a[x].r)>>1;
	if(l<=mid)
	res|=query_zero1(x<<1,l,r);
	if(r>mid)
	res|=query_zero1(x<<1|1,l,r);
	return res;
}
bool query_zero2(int x,int l,int r){
	if(l<=b[x].l&&r>=b[x].r)
	return b[x].zeroval;
	bool res=false;
	int mid=(b[x].l+b[x].r)>>1;
	if(l<=mid)
	res|=query_zero2(x<<1,l,r);
	if(r>mid)
	res|=query_zero2(x<<1|1,l,r);
	return res;
}
signed main(){
	//double start=clock();
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	read(n);
	read(m);
	read(q);
	for(register int i=1;i<=n;i++)
	read(c[i]);
	for(register int i=1;i<=m;i++)
	read(d[i]);
	build1(1,1,n);
	build2(1,1,m);
	for(register int i=1;i<=q;i++){
		int l1,r1,l2,r2;
		read(l1);
		read(r1);
		read(l2);
		read(r2);
		int max1,min1,absl1,absr1;
		int max2,min2,absl2,absr2;
		bool zero1,zero2;
		long long ans=0;
		max1=query_max1(1,l1,r1);
		//puts("mark1");
		min1=query_min1(1,l1,r1);
		//puts("mark2");
		absl1=query_absl1(1,l1,r1);
		//puts("mark3");
		absr1=query_absr1(1,l1,r1);
		//puts("mark4");
		zero1=query_zero1(1,l1,r1);
		//puts("mark5");
		max2=query_max2(1,l2,r2);
		//puts("mark6");
		min2=query_min2(1,l2,r2);
		//puts("mark7");
		//absl2=query_absl2(1,l2,r2);
		//puts("mark8");
		//absr2=query_absr2(1,l2,r2);
		//puts("mark9");
		//zero2=query_zero2(1,l2,r2);
		//puts("mark10");
		//if(i==102){
			//printf("for Tree A : max=%lld min=%lld absl=%lld absr=%lld\n",max1,min1,absl1,absr1);
			//printf("for Tree B : max=%lld min=%lld absl=%lld absr=%lld\n",max2,min2,absl2,absr2);
		//} 
		if(max2>0&&min2<0){//case 1
			if(((max2*absl1)>=(min2*absr1))&&(absl1!=-INF&&absr1!=INF)){
				ans=max2*absl1;
			}
			if(((max2*absl1)<(min2*absr1))&&(absl1!=-INF&&absr1!=INF)){
				ans=min2*absr1;;
			}
			if(absl1==-INF){
				ans=min2*absr1;
			}
			if(absr1==INF)
			ans=max2*absl1;
			if(zero1)
			ans=0;
			//puts("case1");
			write(ans,true);
			continue;
		}
		else if(max2>0&&min2>0){
			if(max1<0&&min1<0)
			ans=max2*max1;
			else
			ans=min2*max1;
			write(ans,true);
			continue;
		}
		else if(max2<0&&min2<0){
			if(max1>0&&min1>0)
			ans=min1*min2;
			else
			ans=min1*max2;
			write(ans,true);
			continue;
		}
		else if(min2==max2==0)
		ans=0;
		write(ans,true);
	}
	//double end=clock();
	//printf("time:%lf",end-start);
	return 0;
}
//1300ms
//but maybe 100pts
//xi wang neng guo
//Luogu ID:suyunqiaoKID
//I Will Always Love Xiao Ting!
