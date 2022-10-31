#include<bits/stdc++.h>
using namespace std;
const int maxn=1e6+5;
typedef long long ll;
const ll inf=1e16;
inline ll read(){
	ll x=0,f=1;
	char c=getchar(); 
	while((c<'0'||c>'9')&&c!='-'){
		c=getchar();
	}
	if(c=='-'){
		f=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9'){
		x=x*10ll+c-48;
		c=getchar(); 
	} 
	return f*x;
}
struct Seg{
	#define ls 2*i
	#define rs 2*i+1
	ll c[maxn];
	ll fmn[maxn],fmx[maxn],zmn[maxn],zmx[maxn];
	void init(){
		fmn[0]=zmn[0]=inf;
		fmx[0]=zmx[0]=-inf;
	}
	inline void push_up(int i){
		fmn[i]=min(fmn[ls],fmn[rs]);
		fmx[i]=max(fmx[ls],fmx[rs]);
		zmn[i]=min(zmn[ls],zmn[rs]);
		zmx[i]=max(zmx[ls],zmx[rs]);
	}
	void build(int i,int l,int r){
		if(l==r){
			fmn[i]=zmn[i]=inf;
			fmx[i]=zmx[i]=-inf;
			if(c[l]==0)fmn[i]=fmx[i]=zmn[i]=zmx[i]=0;
			if(c[l]>0)zmn[i]=zmx[i]=c[l];
			if(c[l]<0)fmn[i]=fmx[i]=c[l];	
			return ;
		}
		int mid=(l+r)/2;
		build(ls,l,mid);
		build(rs,mid+1,r);
		push_up(i);
	} 
	ll queryfmn(int i,int l,int r,int u,int v){
		if(u<=l&&r<=v){
			return fmn[i];
		}
		int mid=(l+r)/2;
		ll ans=inf;
		if(u<=mid)ans=min(ans,queryfmn(ls,l,mid,u,v));
		if(mid+1<=v)ans=min(ans,queryfmn(rs,mid+1,r,u,v));
		return ans;
	}
	ll queryzmn(int i,int l,int r,int u,int v){
		if(u<=l&&r<=v){
			return zmn[i];
		}
		int mid=(l+r)/2;
		ll ans=inf;
		if(u<=mid)ans=min(ans,queryzmn(ls,l,mid,u,v));
		if(mid+1<=v)ans=min(ans,queryzmn(rs,mid+1,r,u,v));
		return ans;
	} 
	ll queryfmx(int i,int l,int r,int u,int v){
		if(u<=l&&r<=v){
			return fmx[i];
		}
		int mid=(l+r)/2;
		ll ans=-inf;
		if(u<=mid)ans=max(ans,queryfmx(ls,l,mid,u,v));
		if(mid+1<=v)ans=max(ans,queryfmx(rs,mid+1,r,u,v));
		return ans;
	}
	ll queryzmx(int i,int l,int r,int u,int v){
		if(u<=l&&r<=v){
			return zmx[i];
		}
		int mid=(l+r)/2;
		ll ans=-inf;
		if(u<=mid)ans=max(ans,queryzmx(ls,l,mid,u,v));
		if(mid+1<=v)ans=max(ans,queryzmx(rs,mid+1,r,u,v));
		return ans;
	}  
}A,B;
int n,m,q;
ll a[maxn],b[maxn];
ll az[maxn],bz[maxn];
ll af[maxn],bf[maxn];
int main(){ 
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	n=read();m=read();q=read();
	for(int i=1;i<=n;i++)a[i]=read(),az[i]=az[i-1]+(a[i]>=0),af[i]=af[i-1]+(a[i]<=0);
	for(int i=1;i<=m;i++)b[i]=read(),bz[i]=bz[i-1]+(b[i]>=0),bf[i]=bf[i-1]+(b[i]<=0);
	for(int i=1;i<=n;i++)A.c[i]=a[i];
	for(int i=1;i<=m;i++)B.c[i]=b[i];
	A.init();
	B.init();
	A.build(1,1,n);
	B.build(1,1,m);
	int al,ar,bl,br; 
	int s1,s2;
	while(q--){
		al=read();
		ar=read();
		bl=read();
		br=read();
		if((az[ar]-az[al-1])==(ar-al+1))s1=0;
		else if((af[ar]-af[al-1])==(ar-al+1))s1=1;
		else s1=2;
		if((bz[br]-bz[bl-1])==(br-bl+1))s2=0;
		else if((bf[br]-bf[bl-1])==(br-bl+1))s2=1;
		else s2=2;
		if(s1==0){
			if(s2==0){
				printf("%lld\n",A.queryzmx(1,1,n,al,ar)*B.queryzmn(1,1,m,bl,br));	
			}
			if(s2==1){
				printf("%lld\n",A.queryzmn(1,1,n,al,ar)*B.queryfmn(1,1,m,bl,br));
			}
			if(s2==2){ 
				printf("%lld\n",A.queryzmn(1,1,n,al,ar)*B.queryfmn(1,1,m,bl,br));
			}
		}
		if(s1==1){
			if(s2==0){
				printf("%lld\n",A.queryfmx(1,1,n,al,ar)*B.queryzmx(1,1,m,bl,br));	
			}
			if(s2==1){
				printf("%lld\n",A.queryfmn(1,1,n,al,ar)*B.queryfmx(1,1,m,bl,br));
			}
			if(s2==2){ 
				printf("%lld\n",A.queryfmx(1,1,n,al,ar)*B.queryzmx(1,1,m,bl,br));
			}	
		}
		if(s1==2){
			if(s2==0){
				printf("%lld\n",A.queryzmx(1,1,n,al,ar)*B.queryzmn(1,1,m,bl,br));	
			}
			if(s2==1){
				printf("%lld\n",A.queryfmn(1,1,n,al,ar)*B.queryfmx(1,1,m,bl,br));
			}
			if(s2==2){ 
				printf("%lld\n",max(A.queryfmx(1,1,n,al,ar)*B.queryzmx(1,1,m,bl,br),A.queryzmn(1,1,n,al,ar)*B.queryfmn(1,1,m,bl,br)));
			}
		}
	}
	return 0;
}
