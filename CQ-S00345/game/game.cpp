#include<bits/stdc++.h>
#define int long long
#define For(i,a,b) for(int i=a,i##end=b;i<=i##end;i++)
#define Rof(i,a,b) for(int i=a,i##end=b;i>=i##end;i--)
#define rep(i,  b) for(int i=1,i##end=b;i<=i##end;i++)
using namespace std;
const int N=2e5+9;
//char buf[(1<<21)+1],*p1,*p2;
//#define getchar() (p1==p2&&(p2=(p1=buf)+fread(buf,1,1<<21,stdin),p1==p2)?EOF:*p1++)
inline int max(int &a,int &b){return a<b?b:a;}
int read(){
	int f=0,x=0;
	char ch=getchar();
	while(!isdigit(ch)){f|=(ch=='-');ch=getchar();}
	while(isdigit(ch)){x=x*10+ch-'0';ch=getchar();}
	return f?-x:x;
}
int n,m,q;
int a[N],b[N];
int A[N][3],B[N][3];
struct tree{
	#define ls (p<<1)
	#define rs (p<<1|1)
	struct point{
		int mn1,mn2,mx1,mx2;
		void re(){mn1=1e9,mn2=1e9,mx1=-1e9,mx2=-1e9;}
		point operator+(const point&x)const{
			return point{min(mn1,x.mn1),min(mn2,x.mn2),max(mx1,x.mx1),max(mx2,x.mx2)};
		}
	}t[N<<2],ans;
	void build(int *a,int p,int l,int r){
		if(l==r){
			t[p].re();
			if(a[l]>0)t[p].mn1=t[p].mx1=a[l];
			if(a[l]<0)t[p].mn2=t[p].mx2=-a[l];
			return;
		}int mid=(l+r)>>1;
		build(a,ls,l,mid);
		build(a,rs,mid+1,r);
		t[p]=t[ls]+t[rs];
	}
	void get(int p,int l,int r,int nl,int nr){
		if(nl<=l&&r<=nr){ans=(ans+t[p]);return;}
		int mid=(l+r)>>1;
		if(mid>=nl)get(ls,l,mid,nl,nr);
		if(mid<nr)get(rs,mid+1,r,nl,nr);
	}
}T1,T2;
signed main(){
//	printf("%.5lf\n",(&pppp-&ppp)/1024.0/1024.0);
//	system("fc game.out game4.ans");return 0;
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	n=read(),m=read(),q=read();
	rep(i,n){
		a[i]=read();
		A[i][0]=A[i-1][0]+(a[i]<0);
		A[i][1]=A[i-1][1]+(a[i]==0);
		A[i][2]=A[i-1][2]+(a[i]>0);
	}T1.build(a,1,1,n);
	rep(i,m){
		b[i]=read();
		B[i][0]=B[i-1][0]+(b[i]<0);
		B[i][1]=B[i-1][1]+(b[i]==0);
		B[i][2]=B[i-1][2]+(b[i]>0);
	}T2.build(b,1,1,m);
	while(q--){
		int l1=read(),r1=read();
		int l2=read(),r2=read();
		int ans=-1e18,res=0;
		T1.ans.re();T1.get(1,1,n,l1,r1);
		T2.ans.re();T2.get(1,1,m,l2,r2);
		if(A[r1][0]-A[l1-1][0]){
			if(B[r2][2]-B[l2-1][2]){
				res=-T1.ans.mn2*T2.ans.mx1;
				ans=max(ans,res);
			}else if(B[r2][1]-B[l2-1][1]){
				res=0;
				ans=max(ans,res);
			}else if(B[r2][0]-B[l2-1][0]){
				res=T1.ans.mx2*T2.ans.mn2;
				ans=max(ans,res);
			}
		}
		if(A[r1][1]-A[l1-1][1])ans=max(ans,0ll);
		if(A[r1][2]-A[l1-1][2]){
			if(B[r2][0]-B[l2-1][0]){
				res=-T1.ans.mn1*T2.ans.mx2;
				ans=max(ans,res);
			}else if(B[r2][1]-B[l2-1][1]){
				res=0;
				ans=max(ans,res);
			}else if(B[r2][2]-B[l2-1][2]){
				res=T1.ans.mx1*T2.ans.mn1;
				ans=max(ans,res);
			}
		}printf("%lld\n",ans);
	}
	return 0;
}


