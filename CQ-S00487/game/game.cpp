#include<bits/stdc++.h>
#define FOR(i,a,b) for(int i=(a); i<=(b); ++i)
#define ROF(i,a,b) for(int i=(a); i>=(b); --i)
#define pb push_back
#define ll long long
#define mid ((l+r)>>1)
#define modj(x) ((x)-=((x)>=MOD)?MOD:0)
using namespace std;
bool h1;
const ll N=1e5;
ll a[N+10],b[N+10];
struct SGT{
	ll T[N*4+10],T2[N*4+10];
	void init(ll po,ll l,ll r,ll z1,ll z2){
		T[po]=z1; T2[po]=z2;
		if(l==r) return;
		init(po<<1,l,mid,z1,z2); init((po<<1)|1,mid+1,r,z1,z2);
	}
	void add(ll po,ll l,ll r,ll qpo,ll z){
		if(l==r){
			T[po]=min(T[po],z),T2[po]=max(T2[po],z); return;	
		} 
		if(qpo<=mid) add(po<<1,l,mid,qpo,z);
		else add((po<<1)|1,mid+1,r,qpo,z);
		T[po]=min(T[po<<1],T[(po<<1)|1]);
		T2[po]=max(T2[po<<1],T2[(po<<1)|1]);
	}
	ll que(ll po,ll l,ll r,ll ql,ll qr,ll op){
		if(ql<=l&&r<=qr) return (op==0)?T[po]:T2[po];
		ll rt=(op==0)?1.1e9:-1.1e9;
		if(op==0){
			if(ql<=mid) rt=min(rt,que(po<<1,l,mid,ql,qr,op));
			if(qr>mid) rt=min(rt,que((po<<1)|1,mid+1,r,ql,qr,op));
		}
		else{
			if(ql<=mid) rt=max(rt,que(po<<1,l,mid,ql,qr,op));
			if(qr>mid) rt=max(rt,que((po<<1)|1,mid+1,r,ql,qr,op));
		}
		return rt;
	}
}tx1,tx2,ty;
bool H1;
inline char gc(){
	static char buf[100000],*p1=buf,*p2=buf;
	return p1==p2&&(p2=(p1=buf)+fread(buf,1,100000,stdin),p1==p2)?EOF:*p1++;
}
inline ll gt(){
	ll x=0,b=0; char c=gc();
	while(!isdigit(c)) b|=(c=='-'),c=gc();
	while(isdigit(c)) x=(x<<3)+(x<<1)+(c^48),c=gc();
	return b?-x:x;
}
inline void wr(ll x){
	if(x<0) putchar('-'),x=-x;
	if(x>9) wr(x/10);
	putchar(x%10+'0');
}
int main(){
//	cout<<(&H1-&h1)/1024/1024<<endl;
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	ll n=gt(),m=gt(),q=gt();
	FOR(i,1,n) a[i]=gt();
	FOR(i,1,m) b[i]=gt();
	tx1.init(1,1,n,1.1e9,-1.1e9); tx2.init(1,1,n,1.1e9,-1.1e9); ty.init(1,1,n,1.1e9,-1.1e9); 
	FOR(i,1,n){
		if(a[i]>=0) tx1.add(1,1,n,i,a[i]);
		if(a[i]<=0) tx2.add(1,1,n,i,a[i]);
	}
	FOR(i,1,m) ty.add(1,1,n,i,b[i]);
	FOR(i,1,q){
		ll l1=gt(),r1=gt(),l2=gt(),r2=gt(),ans=-2e18;
		ll minz=ty.que(1,1,n,l2,r2,0),maxz=ty.que(1,1,n,l2,r2,1);
		ll t1=tx1.que(1,1,n,l1,r1,1),t2=tx1.que(1,1,n,l1,r1,0),
		t3=tx2.que(1,1,n,l1,r1,1),t4=tx2.que(1,1,n,l1,r1,0);
		if(minz>=0){
			if(t1!=-1.1e9)ans=max(ans,minz*t1);	
		} 
		else{
			if(t2!=1.1e9) ans=max(ans,minz*t2);	
		} 
		if(maxz>=0){
			if(t3!=-1.1e9) ans=max(ans,maxz*t3);	
		} 
		else{
			if(t4!=1.1e9) ans=max(ans,maxz*t4);
		}
		wr(ans),putchar('\n');
	}
	return 0;
}

