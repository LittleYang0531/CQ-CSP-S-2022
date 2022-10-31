#include<bits/stdc++.h>
#define ll long long
using namespace std;
inline int read(){
	int sss=0,www=1;
	char chh=getchar();
	while(chh<'0'||chh>'9'){
		if(chh=='-') www=-1;
		chh=getchar();
	}
	while(chh>='0'&&chh<='9'){
		sss=sss*10+chh-'0';
		chh=getchar();
	}
	return sss*www;
}
struct Segment_Tree{
	ll a[100005],treemax[400005],treemin[400005];
	void build(int p,int l,int r){
		if(l==r){
			treemax[p]=treemin[p]=a[l];
			return;
		}
		int mid=(l+r)>>1;
		build(p<<1,l,mid);
		build(p<<1|1,mid+1,r);
		treemax[p]=max(treemax[p<<1],treemax[p<<1|1]);
		treemin[p]=min(treemin[p<<1],treemin[p<<1|1]);
	}
	ll query_min(int p,int l,int r,int L,int R){
		if(L<=l&&r<=R) return treemin[p];
		int mid=(l+r)>>1;
		ll minn=2e9;
		if(L<=mid) minn=min(minn,query_min(p<<1,l,mid,L,R));
		if(mid<R) minn=min(minn,query_min(p<<1|1,mid+1,r,L,R));
		return minn;
	}
	ll query_max(int p,int l,int r,int L,int R){
		if(L<=l&&r<=R) return treemax[p];
		int mid=(l+r)>>1;
		ll maxn=-2e9;
		if(L<=mid) maxn=max(maxn,query_max(p<<1,l,mid,L,R));
		if(mid<R) maxn=max(maxn,query_max(p<<1|1,mid+1,r,L,R));
		return maxn;
	}
}A,B,C,D,E,F;
//C查询a中大于0的最小数字
//D查询a中小于0的最大数字 
int n,m,q;
ll a[100005],b[100005];
int suma[100005],sumb[100005];
int main(){
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	n=read(),m=read(),q=read();
	for(register int i=1;i<=n;i++){
		A.a[i]=a[i]=(ll)read();
		if(a[i]==0) suma[i]++;
	}
	for(register int i=1;i<=m;i++){
		B.a[i]=b[i]=(ll)read();
		if(b[i]==0) sumb[i]++;
	}
	for(register int i=1;i<=n;i++) suma[i]+=suma[i-1];
	for(register int i=1;i<=m;i++) sumb[i]+=sumb[i-1];
	for(register int i=1;i<=n;i++){
		if(a[i]==0){
			C.a[i]=2e9;
			D.a[i]=-2e9;
		}
		else if(a[i]<0){
			C.a[i]=2e9;
			D.a[i]=a[i];
		}
		else {
			C.a[i]=a[i];
			D.a[i]=-2e9;
		}
	}
	for(register int i=1;i<=m;i++){
		if(b[i]==0){
			E.a[i]=2e9;
			F.a[i]=-2e9;
		}
		else if(b[i]<0){
			E.a[i]=2e9;
			F.a[i]=b[i];
		}
		else {
			E.a[i]=b[i];
			F.a[i]=-2e9;
		}
	}
	//for(register int i=1;i<=n;i++) cout<<D.a[i]<<" "; puts("");
	A.build(1,1,n); B.build(1,1,m); C.build(1,1,n); D.build(1,1,n); E.build(1,1,m); F.build(1,1,m);
//	cout<<D.query_max(1,1,n,1,5)<<"\n";
	while(q--){
		int l1=read(),r1=read(),l2=read(),r2=read();
		ll a1=C.query_min(1,1,n,l1,r1);
		ll b1=E.query_min(1,1,m,l2,r2);//大于0的最小数字 
		ll b2=F.query_max(1,1,m,l2,r2);//小于0的最大数字 
		ll b3=(sumb[r2]-sumb[l2-1]>=1);//是否有0 
		ll b4=B.query_min(1,1,m,l2,r2);//B的最小值 
		ll b5=B.query_max(1,1,m,l2,r2);//B的最大值 
		ll ans=-2e18;
		if(a1!=2e9){
			ll tmp=2e18;
			if(b1!=2e9) tmp=min(tmp,a1*b1);
			if(b2!=-2e9) tmp=min(tmp,a1*b2);
			if(b3>0) tmp=min(tmp,0LL);
			tmp=min(tmp,a1*b4);
			tmp=min(tmp,a1*b5);
			ans=max(ans,tmp);
		}
		a1=D.query_max(1,1,n,l1,r1);
		if(a1!=-2e9){
			ll tmp=2e18;
			if(b1!=2e9) tmp=min(tmp,a1*b1);
			if(b2!=-2e9) tmp=min(tmp,a1*b2);
			if(b3>0) tmp=min(tmp,0LL);
			tmp=min(tmp,a1*b4);
			tmp=min(tmp,a1*b5);
			ans=max(ans,tmp);
		}
		a1=(suma[r1]-suma[l1-1]>=1);
		if(a1>=1) ans=max(ans,0LL);
		a1=A.query_min(1,1,n,l1,r1);
		ll tmp=2e18;
		if(b1!=2e9) tmp=min(tmp,a1*b1);
		if(b2!=-2e9) tmp=min(tmp,a1*b2);
		if(b3>0) tmp=min(tmp,0LL);
		tmp=min(tmp,a1*b4);
		tmp=min(tmp,a1*b5);
		ans=max(ans,tmp);
		a1=A.query_max(1,1,n,l1,r1);
		tmp=2e18;
		if(b1!=2e9) tmp=min(tmp,a1*b1);
		if(b2!=-2e9) tmp=min(tmp,a1*b2);
		if(b3>0) tmp=min(tmp,0LL);
		tmp=min(tmp,a1*b4);
		tmp=min(tmp,a1*b5);
		ans=max(ans,tmp);
		cout<<ans<<"\n";
	}
	return 0;
}
