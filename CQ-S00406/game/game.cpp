#include <bits/stdc++.h>

using namespace std;

const int MAX_N = 100000 + 5;

const int inf = 1e9+1;

int n,m,q,a[MAX_N],b[MAX_N],c[MAX_N];

//inline void query1(int l,int r,int s[],int &mx,int &mn){//s>=0
//	mx=-1e9-1,mn=1e9+1;
//	for(int i=l;i<=r;++i){
//		if(s[i]<0) continue;
//		mx=max(mx,s[i]);
//		mn=min(mn,s[i]);
//	}
//}
//
//inline void query2(int l,int r,int s[],int &mx,int &mn){//s<=0
//	mx=-1e9-1,mn=1e9+1;
//	for(int i=l;i<=r;++i){
//		if(s[i]>0) continue;
//		mx=max(mx,s[i]);
//		mn=min(mn,s[i]);
//	}
//}

struct SegmentTree{
	//1 : s>=0  0:s<=0
	int mx[MAX_N << 2][2],mn[MAX_N << 2][2];
//	int mxa1,mxa2,mna1,mna2;
//	int mxb1,mxb2,mnb1,mnb2;
	#define ls ((p) << 1 )
	#define rs ((p) << 1 | 1)
	
	inline void update(int p,int op){
		mx[p][op]=max(mx[ls][op],mx[rs][op]);
		mn[p][op]=min(mn[ls][op],mn[rs][op]);
	}
	
	void build(int p,int l,int r,int op){
		mx[p][op]=-inf,mn[p][op]=inf;
		if(l==r){
			if((c[l]>=0)==op){
				mx[p][op]=mn[p][op]=c[l];
			}
			else if(c[l]==0) mx[p][op]=mn[p][op]=c[l];
			return;
		}
		int mid=l+r>>1;
		build(ls,l,mid,op);
		build(rs,mid+1,r,op);
		update(p,op);
	}
	
	int querymax(int p,int l,int r,int L,int R,int op){
		if(L<=l && r<=R) return mx[p][op];
		int mid=l+r>>1;
		int res=-inf;
		if(L<=mid) res=max(res,querymax(ls,l,mid,L,R,op));
		if(mid<R) res=max(res,querymax(rs,mid+1,r,L,R,op));
		return res;
	}
	
	int querymin(int p,int l,int r,int L,int R,int op){
		if(L<=l && r<=R) return mn[p][op];
		int mid=l+r>>1;
		int res=inf;
		if(L<=mid) res=min(res,querymin(ls,l,mid,L,R,op));
		if(mid<R) res=min(res,querymin(rs,mid+1,r,L,R,op));
		return res;
	}
}A,B;

int main(){
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	scanf("%d%d%d",&n,&m,&q);
	for(int i=1;i<=n;++i) scanf("%d",&a[i]);
	for(int i=1;i<=m;++i) scanf("%d",&b[i]);
	for(int i=1;i<=n;++i) c[i]=a[i];
	A.build(1,1,n,0);
	A.build(1,1,n,1);
	for(int i=1;i<=n;++i) c[i]=0;
	for(int i=1;i<=m;++i) c[i]=b[i];
	B.build(1,1,m,0);
	B.build(1,1,m,1);
	long long ans=-1e18;
	while(q--){
		int l1,r1,l2,r2;
		scanf("%d%d%d%d",&l1,&r1,&l2,&r2);
		int mxa1,mxa2,mna1,mna2;
		int mxb1,mxb2,mnb1,mnb2;
//		query1(l1,r1,a,mxa1,mna1);
//		query1(l2,r2,b,mxb1,mnb1);
//		query2(l1,r1,a,mxa2,mna2);
//		query2(l2,r2,b,mxb2,mnb2);
		mxa1=A.querymax(1,1,n,l1,r1,1);
		mxa2=A.querymax(1,1,n,l1,r1,0);
		mna1=A.querymin(1,1,n,l1,r1,1);
		mna2=A.querymin(1,1,n,l1,r1,0);
		mxb1=B.querymax(1,1,m,l2,r2,1);
		mxb2=B.querymax(1,1,m,l2,r2,0);
		mnb1=B.querymin(1,1,m,l2,r2,1);
		mnb2=B.querymin(1,1,m,l2,r2,0);
//		printf("%d %d %d %d\n",mxa1,mna1,mxa2,mna2);
//		printf("%d %d %d %d\n",mxb1,mnb1,mxb2,mnb2);
		ans=-1e18;
		if(mna1!=inf && mnb2!=inf) ans=max(ans,1ll*mna1*mnb2);
		if(mxa2!=-inf && mxb1!=-inf) ans=max(ans,1ll*mxa2*mxb1);
		if(mxb2==-inf && mnb2==inf && mxb1!=-inf && mnb1!=inf){
			if(mxa1!=-inf) ans=max(ans,1ll*mxa1*mnb1);
			else if(mxa2!=-inf) ans=max(ans,1ll*mxa2*mxb1);
		}
		if(mxb1==-inf && mnb1==inf && mxb2!=-inf && mnb2!=inf){
			if(mna2!=inf) ans=max(ans,1ll*mna2*mxb2);
			else if(mna1!=inf) ans=max(ans,1ll*mna1*mnb2);
		}
		printf("%lld\n",ans);
	}
	return 0;
}
