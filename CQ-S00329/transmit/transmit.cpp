#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cassert>
#define int long long
const int Q=200005;
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
inline int min(cint x,cint y){return x<y?x:y;}
int n,m,K,a[Q];
int h[Q],ce;struct Edge{int to,nxt;}e[Q<<1];
inline void edge(cint x,cint y){e[++ce]=(Edge){y,h[x]};h[x]=ce;}
inline void gph(cint x,cint y){edge(x,y);edge(y,x);}
namespace sub12{
	inline void swap(rg&x,rg&y){cint t=x;x=y;y=t;}
	struct mat{
		int a[2][2];mat()=default;
		inline void setI(){
			for(rg i=0;i<K;++i)for(rg j=0;j<K;++j)a[i][j]=INF;
			for(rg i=0;i<K;++i)a[i][i]=0;
		}
		inline mat operator*(const mat&rhs)const{
			mat res;for(rg i=0;i<K;++i)for(rg j=0;j<K;++j)res.a[i][j]=INF;
			for(rg i=0;i<K;++i)for(rg k=0;k<K;++k)for(rg j=0;j<K;++j)res.a[i][j]=min(res.a[i][j],a[i][k]+rhs.a[k][j]);return res;
		}
	};
	mat B;
	inline void swap(mat&x,mat&y){const mat t=x;x=y;y=t;}
	namespace LCT{
		struct lct{int ch[2],fa,rev;mat f,g,v;}t[Q];
		inline void upd(cint x){
			t[x].f=t[t[x].ch[0]].f*t[x].v*t[t[x].ch[1]].f;
			t[x].g=t[t[x].ch[1]].g*t[x].v*t[t[x].ch[0]].g;
		}
		inline void psh(cint x){swap(t[x].ch[0],t[x].ch[1]);swap(t[x].f,t[x].g);t[x].rev^=1;}
		inline void spd(cint x){if(t[x].rev)psh(t[x].ch[0]),psh(t[x].ch[1]),t[x].rev=0;}
		inline bool isrt(cint x){cint fa=t[x].fa;return !fa||(t[fa].ch[0]^x&&t[fa].ch[1]^x);}
		inline bool islr(cint x){return t[t[x].fa].ch[0]^x;}
		inline void rot(cint x){
			cint y=t[x].fa,z=t[y].fa,l=islr(x),r=l^1;
			if(!isrt(y))t[z].ch[islr(y)]=x;t[x].fa=z;
			t[y].ch[l]=t[x].ch[r];t[t[x].ch[r]].fa=y;
			t[x].ch[r]=y;t[y].fa=x;upd(y);upd(x);
		}
		inline void spds(cint x){if(!isrt(x))spds(t[x].fa);spd(x);}
		inline void splay(cint x){spds(x);for(rg y=t[x].fa;!isrt(x);rot(x),y=t[x].fa)if(!isrt(y))rot((islr(x)^islr(y))?x:y);upd(x);}
		inline void acc(rg x){for(rg y=0;x;x=t[y=x].fa)splay(x),t[x].ch[1]=y,upd(x);}
		inline void mkrt(cint x){acc(x);splay(x);psh(x);}
		inline mat qry(cint x,cint y){mkrt(x);acc(y);splay(y);return t[y].f;}
	}
	inline mat set(cint x){
		mat res;for(rg i=0;i<K-1;++i){for(rg j=0;j<K;++j)res.a[i][j]=INF;res.a[i][i+1]=0;}
		for(rg i=0;i<K;++i)res.a[K-1][i]=a[x];return res;
	}
	inline void dfs(cint x,cint fa){
		LCT::t[x].f=LCT::t[x].g=LCT::t[x].v=set(x);LCT::t[x].fa=fa;
		for(rg i=h[x];i;i=e[i].nxt)if(e[i].to^fa)dfs(e[i].to,x);
	}
	inline int qry(cint x,cint y){return (LCT::qry(x,y)*B).a[K-1][0];}
	inline void solve(){
		for(rg i=0;i<K;++i)for(rg j=0;j<K;++j)B.a[i][j]=INF;B.a[0][0]=0;
		LCT::t[0].f.setI();LCT::t[0].g.setI();LCT::t[0].v.setI();dfs(1,0);
		for(rg x,y;m--;read(x),read(y),write(qry(x,y),'\n'));
	}
//	inline unsigned long long MEM(){
//		return sizeof(LCT::t);
//	}
}
namespace sub3{
	const int Q=400005;
	int prt[Q],RN;
	namespace HLD{
		int top[Q],sze[Q],dep[Q],son[Q];
		inline void dfs1(cint x,cint fa){
			sze[x]=1;prt[x]=fa;dep[x]=dep[fa]+1;
			for(rg i=h[x];i;i=e[i].nxt){
				cint y=e[i].to;if(y==fa)continue;dfs1(y,x);
				sze[x]+=sze[y];if(sze[son[x]]<sze[y])son[x]=y;
			}
		}
		inline void dfs2(cint x,cint rtt){
			top[x]=rtt;if(son[x])dfs2(son[x],rtt);
			for(rg i=h[x];i;i=e[i].nxt){
				cint y=e[i].to;if(y^prt[x]&&y^son[x])dfs2(y,y);
			}
		}
		inline int Glca(rg x,rg y){
			for(;top[x]^top[y];dep[top[x]]>dep[top[y]]?x=prt[top[x]]:y=prt[top[y]]);
			return dep[x]>dep[y]?y:x;
		}
		inline int Gdis(cint x,cint y){return dep[x]+dep[y]-(dep[Glca(x,y)]<<1);}
	}
	int s1[Q],s2[Q],s3[Q];
	inline void dfs(cint x,cint fa){
		for(rg i=h[x];i;i=e[i].nxt)if(e[i].to^fa)dfs(e[i].to,x);
		s1[x]=s2[x]=s3[x]=++n;a[n]=INF;
		for(rg i=h[x];i;i=e[i].nxt){
			cint y=e[i].to;if(y==fa)continue;
			if(a[s1[x]]>a[y])s3[x]=s2[x],s2[x]=s1[x],s1[x]=y;
			else if(a[s2[x]]>a[y])s3[x]=s2[x],s2[x]=y;
			else if(a[s3[x]]>a[y])s3[x]=y;
		}
	}
	int st[Q],tmp[Q],f[Q];
	inline int qry(cint x,cint y){
		cint lca=HLD::Glca(x,y);rg top=0,ct=0,lx=0,ly=0;
		for(rg p=x;p^lca;p=prt[lx=p]){st[++top]=p;if(s1[p]^lx)st[++top]=s1[p];else st[++top]=s2[p];}
		for(rg p=y;p^lca;p=prt[ly=p]){if(s1[p]^ly)tmp[++ct]=s1[p];else tmp[++ct]=s2[p];tmp[++ct]=p;}
		st[++top]=lca;rg S1=s1[lca],S2=s2[lca],S3=s3[lca];
		if(prt[lca]){
			cint v=prt[lca];if(a[S1]>a[v])S3=S2,S2=S1,S1=v;
			else if(a[S2]>a[v])S3=S2,S2=v;else if(a[S3]>a[v])S3=v;
		}
		if(S1^lx&&S1^ly)st[++top]=S1;else if(S2^lx&&S2^ly)st[++top]=S2;else st[++top]=S3;
		for(rg i=ct;i>=1;--i)st[++top]=tmp[i];f[1]=a[x];
//		for(rg i=1;i<=top;++i)write(st[i],' ');putchar('\n');
		for(rg i=2;i<=top;++i){
			f[i]=INF;if(st[i]>RN)continue;
			for(rg j=i-1;j>=i-6&&j>=1;--j)if(st[j]<=RN&&HLD::Gdis(st[i],st[j])<=3)f[i]=min(f[i],f[j]+a[st[i]]);
		}
		for(rg i=1;i<=top;++i)if(st[i]==y)return f[i];
	}
	inline void solve(){
		RN=n;HLD::dfs1(1,0);HLD::dfs2(1,1);dfs(1,0);
		for(rg x,y;m--;read(x),read(y),write(qry(x,y),'\n'));
	}
//	inline unsigned long long MEM(){
//		return sizeof(prt)+sizeof(HLD::top)+sizeof(HLD::sze)+sizeof(HLD::dep)
//		+sizeof(HLD::son)+sizeof(s1)+sizeof(s2)+sizeof(s3)+sizeof(st)+sizeof(f)+sizeof(tmp);
//	}
}
signed main(){
	freopen("transmit.in","r",stdin);
	freopen("transmit.out","w",stdout);
	read(n);read(m);read(K);
	for(rg i=1;i<=n;++i)read(a[i]);
	for(rg i=1,x,y;i<n;++i)read(x),read(y),gph(x,y);
	if(K<=2)sub12::solve();else sub3::solve();
	return 0;
}
/*
10 1 3
835701672 912572995 368308854 156367225 251245604 788978650 385396264 960190423 51944511 479806606
2 1
3 2
4 2
5 3
6 3
7 2
8 7
9 1
10 9

1 5

1086947276
*/
