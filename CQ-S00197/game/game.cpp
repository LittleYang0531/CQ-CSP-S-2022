#include<bits/stdc++.h>
#define int long long
#define rep(i,j,k) for(int i=j;i<=k;i++)
#define per(i,j,k) for(int i=j;i>=k;i--)
using namespace std;
inline int read(){
	char ch=' ';int x=0,f=1;
	while((ch<'0'||ch>'9')&&ch!='-'){ch=getchar();}
	if(ch=='-'){f=-1,ch=getchar();}
	while(ch>='0'&&ch<='9'){x=(x<<3)+(x<<1)+(ch^48),ch=getchar();}
	return x*f; 
}
const int N=1e5+5,T=N*4,inf=9e18;
int a[N],az[N],af[N],b[N],bz[N],bf[N];
int n,m,q;
#define ls (d<<1)
#define rs (d<<1|1)
#define mid ((l+r)>>1)
struct sgtree{
	vector<int>ori;
	int mx[T],mn[T],zmx[T],zmn[T],fmx[T],fmn[T];
	void pushup(int d){
		mx[d]=max(mx[ls],mx[rs]);
		mn[d]=min(mn[ls],mn[rs]);
		zmx[d]=max(zmx[ls],zmx[rs]);
		fmx[d]=max(fmx[ls],fmx[rs]);
		zmn[d]=min(zmn[ls],zmn[rs]);
		fmn[d]=min(fmn[ls],fmn[rs]);
	}
	void build(int d,int l,int r){
		if(l==r){
			mx[d]=mn[d]=ori[l];
			if(ori[l]>=0){
				zmx[d]=zmn[d]=ori[l];
			}
			else{
				zmx[d]=-inf,zmn[d]=inf;
			}
			if(ori[l]<=0){
				fmx[d]=fmn[d]=ori[l];
			}
			else{
				fmx[d]=-inf,fmn[d]=inf;
			}
			return;
		}
		build(ls,l,mid);
		build(rs,mid+1,r);
		pushup(d); 
	}
	int qmx(int d,int l,int r,int nl,int nr,int op){ 
		if(nl<=l&&r<=nr){
			if(op==1){
				return mx[d];
			}
			if(op==2){
				return zmx[d];
			}
			return fmx[d];
		}
		if(l>nr||nl>r){
			return -inf;
		}
		return max(qmx(ls,l,mid,nl,nr,op),qmx(rs,mid+1,r,nl,nr,op));
	}
	int qmn(int d,int l,int r,int nl,int nr,int op){
		if(nl<=l&&r<=nr){
			if(op==1){
				return mn[d];
			}
			if(op==2){
				return zmn[d];
			}
			return fmn[d];
		}
		if(l>nr||nl>r){
			return inf;
		}
		return min(qmn(ls,l,mid,nl,nr,op),qmn(rs,mid+1,r,nl,nr,op));
	}
};
sgtree A,B;
void solve(){
	int l1=read(),r1=read(),l2=read(),r2=read();
	int cntaz=az[r1]-az[l1-1],cntaf=af[r1]-af[l1-1],cntbz=bz[r2]-bz[l2-1],cntbf=bf[r2]-bf[l2-1];
	int ans=-inf;
	//分为选正数和选负数两种情况，这里定义正负都包括0 
	//选正数要看他有没有负数，如果有的话就选最小，没有就选最大
	//选负数要看他有没有正数，如果有的话就选最大，没有就选最小 
	if(cntaz>0){
		if(cntbf>0){
			ans=max(ans,A.qmn(1,1,n,l1,r1,2)*B.qmn(1,1,n,l2,r2,3));
		}
		else{
			ans=max(ans,A.qmx(1,1,n,l1,r1,2)*B.qmn(1,1,n,l2,r2,2));
		}
	}
//	cout<<A.qmn(1,1,n,l1,r1,2)<<' '<<B.qmn(1,1,n,l2,r2,3)<<' ';
//	cout<<A.qmx(1,1,n,l1,r1,2)<<endl;
	if(cntaf>0){
		if(cntbz>0){
			ans=max(ans,A.qmx(1,1,n,l1,r1,3)*B.qmx(1,1,n,l2,r2,2));
		}
		else{
			ans=max(ans,A.qmn(1,1,n,l1,r1,3)*B.qmx(1,1,n,l2,r2,3));
		}
	}
	cout<<ans<<endl;
}
signed main(){
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	n=read(),m=read(),q=read();
	A.ori.push_back(0);
	B.ori.push_back(0);
	rep(i,1,n){
		int x=read();
		A.ori.push_back(x); 
		az[i]=az[i-1],af[i]=af[i-1];
		if(x>=0){
			az[i]++;
		}
		if(x<=0){
			af[i]++;
		}
	}
	rep(i,1,m){
		int x=read();
		B.ori.push_back(x);
		bz[i]=bz[i-1],bf[i]=bf[i-1];
		if(x>=0){
			bz[i]++;
		}
		if(x<=0){
			bf[i]++;
		}
	}
	A.build(1,1,n);
	B.build(1,1,n);
//	cout<<A.qmx(1,1,n,2,2,3)<<endl;
	rep(i,1,q){
		solve();
	}
	return 0;
}
