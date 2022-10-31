#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cassert>
#define int long long
const int Q=100005;
const int INF=1ll<<60;
#define rg register int
#define cint const register int
//const int SZ=1<<21;
//char ibuf[SZ|5],*IP1=ibuf,*IP2=ibuf;
//inline char gc(){if(IP1==IP2)IP2=(IP1=ibuf)+fread(ibuf,1,SZ,stdin);return *IP1++;}
#define gc() getchar()
inline bool ig(const char c){return c>='0'&&c<='9';}
inline void read(rg&oi){rg res=0,f=1;char c;while(c=gc(),(!ig(c))&&(c^'-'));c^'-'?res=(c^48):f=-1;while(c=gc(),ig(c))res=res*10+(c^48);oi=f*res;}
inline void print(rg oi){if(oi<0)putchar('-'),oi=~oi+1;if(oi>9)print(oi/10);putchar(oi%10+'0');}
inline void write(cint oi,const char c){print(oi);putchar(c);}
inline int max(cint x,cint y){return x>y?x:y;}
inline int min(cint x,cint y){return x<y?x:y;}
int n,m,q,a[Q],b[Q],v[Q],lg[Q];
struct ST1{
	int f[20][Q];
	inline void init(cint*a,cint N){
		for(rg i=1;i<=N;++i)f[0][i]=a[i];
		for(rg j=1;j<=19;++j){
			for(rg i=1;i+(1<<j)-1<=N;++i){
				f[j][i]=max(f[j-1][i],f[j-1][i+(1<<(j-1))]);
			}
		}
	}
	inline int qry(cint l,cint r){
		cint p=lg[r-l+1];
		return max(f[p][l],f[p][r-(1<<p)+1]);
	}
};
struct ST2{
	int f[20][Q];
	inline void init(cint*a,cint N){
		for(rg i=1;i<=N;++i)f[0][i]=a[i];
		for(rg j=1;j<=19;++j){
			for(rg i=1;i+(1<<j)-1<=N;++i){
				f[j][i]=min(f[j-1][i],f[j-1][i+(1<<(j-1))]);
			}
		}
	}
	inline int qry(cint l,cint r){
		cint p=lg[r-l+1];
		return min(f[p][l],f[p][r-(1<<p)+1]);
	}
};
ST1 f[2][2];ST2 g[2][2];
int s[Q][2][3];
int s1[Q],s2[Q],c1,c2;
inline int qry(cint l1,cint r1,cint l2,cint r2){
	c1=c2=0;
	if(s[r1][0][0]-s[l1-1][0][0])s1[++c1]=0;
	if(s[r1][0][1]-s[l1-1][0][1])s1[++c1]=f[0][0].qry(l1,r1),s1[++c1]=g[0][0].qry(l1,r1);
	if(s[r1][0][2]-s[l1-1][0][2])s1[++c1]=f[0][1].qry(l1,r1),s1[++c1]=g[0][1].qry(l1,r1);
	
	if(s[r2][1][0]-s[l2-1][1][0])s2[++c2]=0;
	if(s[r2][1][1]-s[l2-1][1][1])s2[++c2]=f[1][0].qry(l2,r2),s2[++c2]=g[1][0].qry(l2,r2);
	if(s[r2][1][2]-s[l2-1][1][2])s2[++c2]=f[1][1].qry(l2,r2),s2[++c2]=g[1][1].qry(l2,r2);
	
	rg res=-INF;for(rg i=1;i<=c1;++i){rg v=INF;for(rg j=1;j<=c2;++j)v=min(v,s1[i]*s2[j]);res=max(res,v);}
	return res;
}
signed main(){
//	printf("%llu\n",sizeof(a)+sizeof(b)+sizeof(v)+sizeof(f)+sizeof(s));
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	read(n);read(m);read(q);cint N=max(n,m);
	lg[0]=-1;for(rg i=1;i<=N;++i)lg[i]=lg[i>>1]+1;
	for(rg i=1;i<=n;++i)read(a[i]);
	for(rg i=1;i<=m;++i)read(b[i]);
	
	for(rg i=1;i<=n;++i)s[i][0][0]=s[i-1][0][0]+(a[i]==0);
	for(rg i=1;i<=n;++i)s[i][0][1]=s[i-1][0][1]+(a[i]>0);
	for(rg i=1;i<=n;++i)s[i][0][2]=s[i-1][0][2]+(a[i]<0);
	
	for(rg i=1;i<=m;++i)s[i][1][0]=s[i-1][1][0]+(b[i]==0);
	for(rg i=1;i<=m;++i)s[i][1][1]=s[i-1][1][1]+(b[i]>0);
	for(rg i=1;i<=m;++i)s[i][1][2]=s[i-1][1][2]+(b[i]<0);
	
	for(rg i=1;i<=n;++i)v[i]=(a[i]>0?a[i]:0);f[0][0].init(v,n);
	for(rg i=1;i<=n;++i)v[i]=(a[i]>0?a[i]:INF);g[0][0].init(v,n);
	for(rg i=1;i<=n;++i)v[i]=(a[i]<0?a[i]:-INF);f[0][1].init(v,n);
	for(rg i=1;i<=n;++i)v[i]=(a[i]<0?a[i]:0);g[0][1].init(v,n);
	
	for(rg i=1;i<=m;++i)v[i]=(b[i]>0?b[i]:0);f[1][0].init(v,m);
	for(rg i=1;i<=m;++i)v[i]=(b[i]>0?b[i]:INF);g[1][0].init(v,m);
	for(rg i=1;i<=m;++i)v[i]=(b[i]<0?b[i]:-INF);f[1][1].init(v,m);
	for(rg i=1;i<=m;++i)v[i]=(b[i]<0?b[i]:0);g[1][1].init(v,m);
	
	for(rg L1,R1,L2,R2;q--;read(L1),read(R1),read(L2),read(R2),write(qry(L1,R1,L2,R2),'\n'));
	return 0;
}
