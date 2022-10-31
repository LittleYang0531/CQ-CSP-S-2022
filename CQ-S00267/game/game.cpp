#include<bits/stdc++.h>
#define gc getchar()
typedef long long ll;
using namespace std;
inline ll read(){
	char s=gc;
	ll op=1;
	while(s<'0'||s>'9'){
		if(s=='-')op=-1;
		s=gc;
	}
	ll v=0;
	while('0'<=s&&s<='9'){
		v=(v<<1)+(v<<3)+s-'0';
		s=gc;
	}
	if(op==1)return v;
	return -v;
}
ll a[100005],b[100005];
struct Segment{
	struct node{
		int l,r;
		ll mx,mn;
	}Tree[400005];
	inline void ztree(int p,int l,int r){
		Tree[p].l=l,Tree[p].r=r,Tree[p].mx=-1e18,Tree[p].mn=1e18;
		if(l==r)return;
		int mid=(l+r)>>1;
		ztree(p<<1,l,mid);
		ztree(p<<1|1,mid+1,r);
	}
	inline void update(int p,int l,ll v){
		if(Tree[p].l==Tree[p].r){
			Tree[p].mx=Tree[p].mn=v;
			return;
		}
		int mid=(Tree[p].l+Tree[p].r)>>1;
		if(l<=mid)update(p*2,l,v);
		else update(p*2+1,l,v);
		Tree[p].mx=max(Tree[p<<1].mx,Tree[p<<1|1].mx);
		Tree[p].mn=min(Tree[p<<1].mn,Tree[p<<1|1].mn);
	}
	inline ll Getmax(int p,int l,int r){
		if(l<=Tree[p].l&&Tree[p].r<=r)return Tree[p].mx;
		int mid=(Tree[p].l+Tree[p].r)>>1;
		ll c=-1e18;
		if(l<=mid)c=max(c,Getmax(p<<1,l,r));
		if(r>mid)c=max(c,Getmax(p<<1|1,l,r));
		return c;
	}
	inline ll Getmin(int p,int l,int r){
		if(l<=Tree[p].l&&Tree[p].r<=r)return Tree[p].mn;
		int mid=(Tree[p].l+Tree[p].r)>>1;
		ll c=1e18;
		if(l<=mid)c=min(c,Getmin(p<<1,l,r));
		if(r>mid)c=min(c,Getmin(p<<1|1,l,r));
		return c;
	}
}s1,s2,s3;
int n,m,T;
int main(){
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
//	scanf("%d%d%d",&n,&m,&T);
	n=read(),m=read(),T=read();
//	for(int i=1;i<=n;i++)scanf("%lld",&a[i]);
//	for(int i=1;i<=m;i++)scanf("%lld",&b[i]);
	for(int i=1;i<=n;i++)a[i]=read();
	for(int i=1;i<=m;i++)b[i]=read();
	s1.ztree(1,1,m);
	s2.ztree(1,1,n);
	s3.ztree(1,1,n);
	for(int i=1;i<=n;i++){
		if(a[i]<=0)s3.update(1,i,a[i]);
		else s2.update(1,i,a[i]);
	}
	for(int i=1;i<=m;i++)s1.update(1,i,b[i]);
	while(T--){
		int l1,l2,r1,r2;
//		scanf("%d%d%d%d",&l1,&r1,&l2,&r2);
		l1=read(),r1=read(),l2=read(),r2=read();
		ll mx1=s1.Getmax(1,l2,r2),mn1=s1.Getmin(1,l2,r2),ans=-1e18;
		if(mx1<0){
			ll mn=s3.Getmin(1,l1,r1);
			if(mn!=1e18)ans=max(ans,mn*mx1);
		}
		else{
			ll mx=s3.Getmax(1,l1,r1);
			if(mx!=-1e18)ans=max(ans,mx*mx1);
		}
		if(mn1<0){
			ll mn=s2.Getmin(1,l1,r1);
			if(mn!=1e18)ans=max(ans,mn*mn1);
		}
		else{
			ll mx=s2.Getmax(1,l1,r1);
			if(mx!=-1e18)ans=max(ans,mx*mn1);
		}
		printf("%lld\n",ans);
	}
	return 0;
}
