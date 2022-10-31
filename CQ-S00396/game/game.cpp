#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,q,a[100005],b[100005],t1,t2,t3,t4;
struct ok{
	int mx,in;
}T[4][400005];
inline int read(){
	int x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){
		if(ch=='-') f=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9'){
		x=(x<<1)+(x<<3)+(ch^48);
		ch=getchar();
	}
	return x*f;
}
inline void write(int x){
	int O=0;char f[20];
	if(x<0) x=-x,putchar('-');
	if(!x) {putchar('0');return;}
	while(x) f[++O]=x%10,x/=10;
	while(O) putchar(f[O--]+'0');
}
inline void build(int k,int l,int r){
	if(l==r){
		T[0][k].mx=T[0][k].in=a[l];
		if(a[l]>=0) T[2][k].mx=T[2][k].in=a[l];
		else T[2][k].mx=T[2][k].in=1e17;
		if(a[l]<=0) T[3][k].mx=T[3][k].in=-a[l];
		else T[3][k].mx=T[3][k].in=1e17;
		return;
	}
	int mid=(l+r)>>1;
	build(k<<1,l,mid);build((k<<1)^1,mid+1,r);
	T[0][k].mx=max(T[0][k<<1].mx,T[0][(k<<1)^1].mx);
	T[0][k].in=min(T[0][k<<1].in,T[0][(k<<1)^1].in);
	T[2][k].mx=max(T[2][k<<1].mx,T[2][(k<<1)^1].mx);
	T[2][k].in=min(T[2][k<<1].in,T[2][(k<<1)^1].in);
	T[3][k].mx=max(T[3][k<<1].mx,T[3][(k<<1)^1].mx);
	T[3][k].in=min(T[3][k<<1].in,T[3][(k<<1)^1].in);
}
inline void build2(int k,int l,int r){
	if(l==r){
		T[1][k].mx=T[1][k].in=b[l];
		return;
	}
	int mid=(l+r)>>1;
	build2(k<<1,l,mid);build2((k<<1)^1,mid+1,r);
	T[1][k].mx=max(T[1][k<<1].mx,T[1][(k<<1)^1].mx);
	T[1][k].in=min(T[1][k<<1].in,T[1][(k<<1)^1].in);
}
inline int query(int k,int l,int r,int ll,int rr,int p){
	if(ll<=l&&rr>=r) return T[p][k].mx;
	int mid=(l+r)>>1,w=-1e18;
	if(ll<=mid) w=max(w,query(k<<1,l,mid,ll,rr,p));
	if(rr>mid) w=max(w,query((k<<1)^1,mid+1,r,ll,rr,p));
	return w;
}
inline int query2(int k,int l,int r,int ll,int rr,int p){
	if(ll<=l&&rr>=r) return T[p][k].in;
	int mid=(l+r)>>1,w=1e18;
	if(ll<=mid) w=min(w,query2(k<<1,l,mid,ll,rr,p));
	if(rr>mid) w=min(w,query2((k<<1)^1,mid+1,r,ll,rr,p));
	return w;
}
signed main(){
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	n=read(),m=read(),q=read();
	for(int i=1;i<=n;i++) a[i]=read();
	for(int i=1;i<=m;i++) b[i]=read();
	build(1,1,n);
	build2(1,1,m);
	for(int i=1;i<=q;i++){
		t1=read(),t2=read(),t3=read(),t4=read();
		int s1=query(1,1,m,t3,t4,1),s2=query2(1,1,m,t3,t4,1),ans;
		if(s1>0&&s2>0){
			int w=query(1,1,n,t1,t2,0);
			if(w>=0) ans=w*s2;
			else ans=w*s1;
			write(ans);
			putchar('\n');
		}
		else if(s1<0&&s2<0){
			int w=query2(1,1,n,t1,t2,0);
			if(w<=0) ans=w*s1;
			else ans=w*s2;
			write(ans);
			putchar('\n');
		}
		else{
			int q1=query2(1,1,n,t1,t2,2),q2=-query2(1,1,n,t1,t2,3);
			if(q1>=(int)1e10) q1=q2;
			if(q2<=(int)-1e10) q2=q1;
			ans=max(min(q1*s1,q1*s2),min(q2*s1,q2*s2));
			write(ans);
			putchar('\n');
		}
	}
	return 0;
}

