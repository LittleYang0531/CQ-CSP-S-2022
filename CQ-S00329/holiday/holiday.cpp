#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cassert>
#define int long long
const int Q=2505;
const int P=10005;
const int INF=1<<30;
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
int n,m,K,a[Q];
int h[Q],ce;struct Edge{int to,nxt;}e[P<<1];
inline void edge(cint x,cint y){e[++ce]=(Edge){y,h[x]};h[x]=ce;}
inline void gph(cint x,cint y){edge(x,y);edge(y,x);}
int q[Q],dis[Q];
bool vst[Q],g[Q][Q];
inline void calc(cint s){
	for(rg i=1;i<=n;++i)dis[i]=INF,vst[i]=0;
	rg l,r;q[l=r=1]=s;vst[s]=1;dis[s]=0;
	for(;l<=r;){
		cint x=q[l++];g[s][x]=1;if(dis[x]==K+1)continue;
		for(rg i=h[x];i;i=e[i].nxt){
			cint y=e[i].to;if(vst[y])continue;
			vst[y]=1;dis[y]=dis[x]+1;q[++r]=y;
		}
	}
}
int f[Q][3];
inline void upd(cint x,cint y){
	if(!f[x][0]||a[f[x][0]]<a[y])f[x][2]=f[x][1],f[x][1]=f[x][0],f[x][0]=y;
	else if(!f[x][1]||a[f[x][1]]<a[y])f[x][2]=f[x][1],f[x][1]=y;
	else if(!f[x][2]||a[f[x][2]]<a[y])f[x][2]=y;
}
int res;
inline bool upd(cint A,cint B,cint C,cint D){
	if(!A||!D)return 0;if(A==C||A==D||B==D)return 0;
	if(!g[1][A]||!g[A][B]||!g[B][C]||!g[C][D]||!g[D][1])return 0;
	res=max(res,a[A]+a[B]+a[C]+a[D]);return 1;
}
signed main(){
//	printf("%llu\n",sizeof(a)+sizeof(h)+sizeof(e)+sizeof(q)+sizeof(dis)+sizeof(vst)+sizeof(g)+sizeof(f));
	freopen("holiday.in","r",stdin);
	freopen("holiday.out","w",stdout);
	read(n);read(m);read(K);
	for(rg i=2;i<=n;++i)read(a[i]);
	for(rg i=1,x,y;i<=m;++i)read(x),read(y),gph(x,y);
	for(rg i=1;i<=n;++i)calc(i);
	for(rg i=2;i<=n;++i){
		f[i][0]=f[i][1]=f[i][2]=0;
		for(rg j=2;j<=n;++j)if(g[i][j]&&g[1][j]&&i!=j)upd(i,j);
	}
	for(rg i=2;i<=n;++i){
		for(rg j=i+1;j<=n;++j){
			for(rg k=0;k<3;++k){
				for(rg l=0;l<3;++l){
					if(upd(f[i][k],i,j,f[j][l]))break;
				}
			}
		}
	}
	write(res,'\n');
	return 0;
}
