#include<bits/stdc++.h>
#define R register
#define rep(i,n) for(R int i=1;i<=(int)n;++i)
#define rep0(i,n) for(R int i=0;i<(int)n;++i)
const int maxbuf=1<<21;
char buf[maxbuf],*p1,*p2;
#define GC (p1==p2&&(p2=(p1=buf)+fread(buf,1,maxbuf,stdin),p1==p2)?EOF:*p1++)
inline int rint(void) {
	R int x=0,flag=0;
	char c=GC;
	while((c<'0'||c>'9')&&c!='-') {
		c=GC;
	}
	if(c=='-') {
		c=GC,flag=1;
	}
	while(c>='0'&&c<='9') {
		x=x*10+c-48,c=GC;
	}
	return flag?-x:x;
}
inline long long rll(void) {
	R long long x=0;
	R int flag=0;
	char c=GC;
	while((c<'0'||c>'9')&&c!='-') {
		c=GC;
	}
	if(c=='-') {
		c=GC,flag=1;
	}
	while(c>='0'&&c<='9') {
		x=x*10+c-48,c=GC;
	}
	return flag?-x:x;
}
const int maxlimit=1<<20;
char pbuf[maxbuf],*pp=pbuf;
inline void flu(void) {
	fwrite(pbuf,1,pp-pbuf,stdout),pp=pbuf;
	return ;
}
int top;
char sta[35];
inline void wrt(int x) {
	if(pp-pbuf>=maxlimit)flu();
	if(x==0)*pp++='0';
	else {
		if(x<0)x=-x,*pp++='-';
		top=0;
		do {
			sta[++top]=x%10+48,x/=10;
		} while(x);
		while(top)*pp++=sta[top--];
	}
	*pp++='\n';
	return ;
}
inline void wrt(long long x) {
//	printf("%lld\n",x);
//	return ;
	if(pp-pbuf>=maxlimit)flu();
	if(x==0)*pp++='0';
	else {
		if(x<0)x=-x,*pp++='-';
		top=0;
		do {
			sta[++top]=x%10+48,x/=10;
		} while(x);
		while(top)*pp++=sta[top--];
	}
	*pp++='\n';
	return ;
}
namespace fck_up {
	int n,m,q;
	const int maxn=1e5+5;
	int a[maxn],b[maxn],c[maxn];
	const int maxlog=25;
	int st[6][maxlog][maxn];
	int Lg[maxn];
	const int inf=0x3f3f3f3f;
	inline void initimax(int id,int*a,int n) {
		for(R int i=1; i<=n; ++i)st[id][0][i]=a[i];
		for(R int j=1; j<=Lg[n]; ++j) {
			for(R int i=1; i+(1<<j)-1<=n; ++i) {
				st[id][j][i]=std::max(st[id][j-1][i],st[id][j-1][i+(1<<j-1)]);
			}
		}
		return ;
	}
	inline void initimin(int id,int*a,int n) {
		for(R int i=1; i<=n; ++i)st[id][0][i]=a[i];
		for(R int j=1; j<=Lg[n]; ++j) {
			for(R int i=1; i+(1<<j)-1<=n; ++i) {
				st[id][j][i]=std::min(st[id][j-1][i],st[id][j-1][i+(1<<j-1)]);
			}
		}
		return ;
	}
	inline int querymax(int id,int l,int r) {
		R int p=Lg[r-l+1];
		return std::max(st[id][p][l],st[id][p][r-(1<<p)+1]);
	}
	inline int querymin(int id,int l,int r) {
		R int p=Lg[r-l+1];
		return std::min(st[id][p][l],st[id][p][r-(1<<p)+1]);
	}
	int a0[maxn],b0[maxn];
	int _main(void) {
		n=rint(),m=rint(),q=rint();
		rep(i,n)a[i]=rint(),a0[i]=(a[i]==0)+a0[i-1];
		rep(i,m)b[i]=rint(),b0[i]=(b[i]==0)+b0[i-1];
		const int N=std::max(n,m);
		for(R int i=2; i<=N; ++i)Lg[i]=Lg[i>>1]+1;
		//0:a max
		initimax(0,a,n);
		//1:a min
		initimin(1,a,n);
		//2:b max
		initimax(2,b,m);
		//3:b min
		initimin(3,b,m);
		//4:a zheng
		rep(i,n)c[i]=a[i]>=0?a[i]:inf;
		initimin(4,c,n);
		//5:a fu
		rep(i,n)c[i]=a[i]<=0?a[i]:-inf;
		initimax(5,c,n);
		while(q--) {
			R int l1=rint(),r1=rint();
			R int l2=rint(),r2=rint();
			R int minn=querymin(3,l2,r2),maxx=querymax(2,l2,r2),jud0=b0[r2]-b0[l2-1];
//			printf("b:%d %d %d %d ",l2,r2,minn,maxx);
//			for(R int i=l2; i<=r2; ++i)minn=std::min(minn,b[i]);
//			R int temp=-inf;
//			for(R int i=l1; i<=r1; ++i)temp=std::max(temp,a[i]);
//			printf("maxx:%d ",temp);
			if(minn>=0) {
				R long long ans=querymax(0,l1,r1);
				if(ans<=0)ans*=maxx;
				else ans*=minn;
				wrt(ans);
			} else if(maxx<=0) {
				R long long ans=querymin(1,l1,r1);
				if(ans<=0)ans*=maxx;
				else ans*=minn;
				wrt(ans);//102
			} else {
//				*pp++='s';
				R long long ans1=1ll*querymin(4,l1,r1)*minn;
				R long long ans2=1ll*querymax(5,l1,r1)*maxx;
				wrt(std::max(ans1,ans2));
			}
		}
		return flu(),0;
	}
}
int main() {
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	return fck_up::_main();
}

