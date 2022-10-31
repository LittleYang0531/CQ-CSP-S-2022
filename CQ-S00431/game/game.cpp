#include<bits/stdc++.h>
#define int long long
using namespace std;
const int maxn=5e5+5;
int maxx1[maxn][50],n,m,q,zero1[maxn],a[maxn],b[maxn],maxx2[maxn][50],zero2[maxn],minn1[maxn][50],minn2[maxn][50],fsx[maxn],zsx[maxn]; 
void build(int k,int l,int r) {
	if(l==r) {
		if(a[l]==0)zero1[k]=1;
		if(a[l]>0)zsx[k]=a[l];
		else zsx[k]=1e9;
		if(a[l]<0)fsx[k]=a[l];
		else fsx[k]=-1e9;
		return;
	}
	int mid=(l+r)/2;
	build(k<<1,l,mid);
	build(k<<1|1,mid+1,r);
	zero1[k]=max(zero1[k<<1],zero1[k<<1|1]);
	zsx[k]=min(zsx[k<<1],zsx[k<<1|1]);
	fsx[k]=max(fsx[k<<1],fsx[k<<1|1]);
}
int fs1[maxn],zs1[maxn],fs2[maxn],zs2[maxn];
void build2(int k,int l,int r) {
	if(l==r) {
		if(b[l]==0)zero2[k]=1;
		return;
	}
	int mid=(l+r)/2;
	build2(k<<1,l,mid);
	build2(k<<1|1,mid+1,r);
	zero2[k]=max(zero2[k<<1],zero2[k<<1|1]);
}
int query2(int k,int l,int r,int x,int y) {//0
	if(x<=l&&y>=r)return zero1[k];
	int mid=(l+r)/2,res=0;
	if(x<=mid)res=max(res,query2(k<<1,l,mid,x,y));
	if(y>mid)res=max(res,query2(k<<1|1,mid+1,r,x,y));
	return res;
}

int query6(int k,int l,int r,int x,int y) {//0
	if(x<=l&&y>=r)return zero2[k];
	int mid=(l+r)/2,res=0;
	if(x<=mid)res=max(res,query6(k<<1,l,mid,x,y));
	if(y>mid)res=max(res,query6(k<<1|1,mid+1,r,x,y));
	return res;
}

int query1(int k,int l,int r,int x,int y) {
	if(x<=l&&y>=r)return fsx[k];
	int mid=(l+r)/2,res=-1e9;
	if(x<=mid)res=max(res,query1(k<<1,l,mid,x,y));
	if(y>mid)res=max(res,query1(k<<1|1,mid+1,r,x,y));
	return res;
}
int query3(int k,int l,int r,int x,int y) {
	if(x<=l&&y>=r)return zsx[k];
	int mid=(l+r)/2,res=1e9;
	if(x<=mid)res=min(res,query3(k<<1,l,mid,x,y));
	if(y>mid)res=min(res,query3(k<<1|1,mid+1,r,x,y));
	return res;
}
void st1() {
	for(int i=1;i<=n;i++) {
		maxx1[i][0]=a[i];
		minn1[i][0]=a[i];
	}
	int l=log2(n);
	for(int j=1;j<=l;j++) {
	    for(int i=1;i+(1<<j)-1<=n;i++) {
			maxx1[i][j]=max(maxx1[i][j-1],maxx1[i+(1<<(j-1))][j-1]);
			minn1[i][j]=min(minn1[i][j-1],minn1[i+(1<<(j-1))][j-1]); 
		}
	}
	return;
}
void st2() {
	for(int i=1;i<=m;i++) {
		maxx2[i][0]=b[i];
		minn2[i][0]=b[i];
	}
	int l=log2(m);
	for(int j=1;j<=l;j++) {
	    for(int i=1;i<=m;i++) {
			maxx2[i][j]=max(maxx2[i][j-1],maxx2[i+(1<<(j-1))][j-1]);
			minn2[i][j]=min(minn2[i][j-1],minn2[i+(1<<(j-1))][j-1]);  
	    }
	}
	return;
}
int cx1(int l,int r) {
	int ls=log2(r-l+1);
	return max(maxx1[l][ls],maxx1[r-(1<<ls)+1][ls]);
}
int cx2(int l,int r) {
	int ls=log2(r-l+1);
	return max(maxx2[l][ls],maxx2[r-(1<<ls)+1][ls]);
}
int cm1(int l,int r) {
	int ls=log2(r-l+1);
	return min(minn1[l][ls],minn1[r-(1<<ls)+1][ls]);
}
int cm2(int l,int r) {
	int ls=log2(r-l+1);
	return min(minn2[l][ls],minn2[r-(1<<ls)+1][ls]);
}
signed main() {
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	scanf("%lld%lld%lld",&n,&m,&q);
	for(int i=1;i<=n;i++) {
		scanf("%lld",&a[i]);
	}
	for(int i=1;i<=m;i++) {
		scanf("%lld",&b[i]);
	}
	build(1,1,n);
	build2(1,1,m);
	int l1,r1,l2,r2;
	int zb;
	for(int i=1;i<=n;i++) {
		if(a[i]<0)fs1[i]=fs1[i-1]+1,zs1[i]=zs1[i-1];
		else  {
			zs1[i]=zs1[i-1]+1,fs1[i]=fs1[i-1];
		}
	}
	for(int i=1;i<=m;i++) {
		if(b[i]<0)fs2[i]=fs2[i-1]+1,zs2[i]=zs2[i-1];
		else  {
			zs2[i]=zs2[i-1]+1,fs2[i]=fs2[i-1];
		} 
	}
	st1(),st2();
	int ans=0;
	while(q--) {
		scanf("%lld%lld%lld%lld",&l1,&r1,&l2,&r2);
		ans=0;
		int u1=cx1(l1,r1),u2=cm1(l1,r1);
		int s1=cx2(l2,r2),s2=cm2(l2,r2);
		int zl=query1(1,1,n,l1,r1),zr=query3(1,1,n,l1,r1);
		
		if(fs2[r2]-fs2[l2-1]==m&&fs1[r1]-fs1[l1-1]>0)zb=1;
	    else if(fs1[r1]-fs1[l1-1]==n&&zs2[r2]-zs2[l2-1]>0)zb=2;
	    else if(fs2[r2]-fs2[l2-1]==m&&zs1[r1]-zs1[l1-1]>0)zb=3;
	    else if(zs1[r1]-zs1[l1-1]==n&&fs2[r2]-fs2[l2-1]>0)zb=4;
	    else zb=5;
		if(zb==1) {
			ans=u2*s1;
		}
		else if(zb==2) {
			ans=u1*s1;
		}
		else if(zb==3) {
			ans=u1*s2;
		}
		else if(zb==4) {
			ans=s2*u2;
		}
		else if(zb==5) {
			ans=zl*s1;
			if(ans<zr*s2) {
				ans=zr*s2;
			}
		}
		if(query2(1,1,n,l1,r1)&&ans<0) {
			ans=0;
		}
		if(query6(1,1,m,l2,r2)&&ans>0) {
			ans=0;
		}
		printf("%lld\n",ans);
	}
	return 0;
}
