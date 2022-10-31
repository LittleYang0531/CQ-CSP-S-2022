#include<bits/stdc++.h>
#define ll long long
#define N 500012
#define mkp make_pair
#define pb push_back
using namespace std;
ll read(){
	ll x=0,fl=1; char ch=getchar();
	while(ch<'0'||ch>'9'){ if(ch=='-')fl=-1; ch=getchar();}
	while(ch>='0'&&ch<='9'){ x=x*10+ch-'0'; ch=getchar();}
	return x*fl;
}
int n,m,q,a[N],b[N];
int ti[N],tx[N];
void pushup(int k){
	ti[k]=min(ti[k<<1],ti[k<<1|1]);
	tx[k]=max(tx[k<<1],tx[k<<1|1]);
}
void build(int k,int l,int r){
	if(l==r){
		ti[k]=tx[k]=b[l];
		return ;
	}
	int mid=(l+r)>>1;
	build(k<<1,l,mid);
	build(k<<1|1,mid+1,r);
	pushup(k);
}
int query_mx(int k,int l,int r,int L,int R){
	if(L<=l&&r<=R){
		return tx[k];
	}
	int mid=(l+r)>>1;
	int sz=-1e9;
	if(L<=mid) sz=max(sz,query_mx(k<<1,l,mid,L,R));
	if(R>mid) sz=max(sz,query_mx(k<<1|1,mid+1,r,L,R));
	return sz;
}
int query_mi(int k,int l,int r,int L,int R){
	if(L<=l&&r<=R){
		return ti[k];
	}
	int mid=(l+r)>>1;
	int sz=1e9;
	if(L<=mid) sz=min(sz,query_mi(k<<1,l,mid,L,R));
	if(R>mid) sz=min(sz,query_mi(k<<1|1,mid+1,r,L,R));
	return sz;
}

int t[N];
void up(int k){
	t[k]=max(t[k<<1],t[k<<1|1]);
}
void tbuild(int k,int l,int r){
	if(l==r){
		t[k]=a[l]; return ;
	}
	int mid=(l+r)>>1;
	tbuild(k<<1,l,mid);
	tbuild(k<<1|1,mid+1,r);
	up(k);
}
int query(int k,int l,int r,int L,int R){
	if(L<=l&&r<=R){
		return t[k];
	}
	int mid=(l+r)>>1;
	int sz=-1e9;
	if(L<=mid) sz=max(sz,query(k<<1,l,mid,L,R));
	if(R>mid) sz=max(sz,query(k<<1|1,mid+1,r,L,R));
	return sz;
}

int main(){
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	n=read(),m=read(),q=read();
	int flag=1;
	for(int i=1;i<=n;i++){
		a[i]=read();
		if(a[i]<0) flag=0;
	}
	for(int i=1;i<=m;i++){
		b[i]=read();
		if(b[i]<0) flag=0;
	}
	int l,r,L,R;
	build(1,1,m);
	if(flag&&n>1000&&m>1000){
		tbuild(1,1,n);
		while(q--){
			l=read(),r=read(),L=read(),R=read();
			printf("%lld\n",1ll*query(1,1,n,l,r)*query_mi(1,1,m,L,R));
		}
		return 0;
	}
	while(q--){
		l=read(),r=read(),L=read(),R=read();
		ll ans=-1e18;
		for(int i=l;i<=r;i++){
			if(a[i]>0) ans=max(ans,1ll*a[i]*query_mi(1,1,m,L,R));
			else if(a[i]==0) ans=max(ans,0ll);
			else{
				ll sz=min(1ll*a[i]*query_mx(1,1,m,L,R),1ll*a[i]*query_mi(1,1,m,L,R));
				ans=max(ans,sz);
			}
			/*ll sz=1e18+1;
			for(int j=L;j<=R;j++){
				sz=min(sz,1ll*a[i]*b[j]);
			}
			ans=max(ans,sz);*/
		}
		printf("%lld\n",ans);
	}
	
	return 0;
}
