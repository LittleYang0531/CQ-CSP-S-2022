#include<iostream>
#include<cstdio>
#include<vector>
using namespace std;
#define N 200012
#define LL long long
#define INF 0x3f3f3f3f
#define IN1 0x3f3f3f3f3f3f3f3fll
inline int re()
{
	char ch=getchar();int x=0;bool fl=false;while((ch<'0')||('9'<ch))fl|=(ch=='-'),ch=getchar();
	while(('0'<=ch)&&(ch<='9'))x=x*10+(ch^'0'),ch=getchar();return fl?(-x):x;
}
int n,Q,K,a[N],h[N],cnt=1,mi[N];
struct Edge{int to,next;}e[N<<1];
inline void AddEdge(int x,int y){e[++cnt]=(Edge){y,h[x]};h[x]=cnt;}
int cor,siz[N],mxc[N];bool vis[N];LL ans[N];
struct Que{int x,y,d;};vector<Que>alq;
LL f[3][N],g[N];
void Fin(int x,int prt,int all)
{
	int i,y;siz[x]=1;mxc[x]=0;f[0][x]=f[1][x]=f[2][x]=g[x]=IN1;
	for(i=h[x];i;i=e[i].next)if(((y=e[i].to)!=prt)&&(!vis[y])){Fin(y,x,all);siz[x]+=siz[y];mxc[x]=max(mxc[x],siz[y]);}
	mxc[x]=max(mxc[x],all-siz[x]);if(mxc[x]<mxc[cor])cor=x;
}
vector<Que>tmp[N];int fa[N],cm;
inline void cmin(LL &x,LL v){x=min(x,v);}
void dfs1(int x,int prt)
{
	fa[x]=prt;int i,y;
	cmin(f[cm][x],f[cm][fa[x]]+a[x]);
	if(K>1)cmin(f[cm][x],f[cm][fa[fa[x]]]+a[x]);
	if(K>2)
	{
		g[x]=IN1;
		cmin(f[cm][x],f[cm][fa[fa[fa[x]]]]+a[x]);
		cmin(f[cm][x],g[fa[fa[x]]]+a[x]);
		cmin(g[x],mi[x]+f[cm][x]);
		cmin(g[x],mi[x]+f[cm][fa[x]]);
		cmin(g[x],mi[x]+f[cm][fa[fa[x]]]);
		cmin(g[x],mi[x]+g[fa[x]]);
	}
	for(i=h[x];i;i=e[i].next)if((!vis[y=e[i].to])&&(y!=prt))dfs1(y,x);
}
int rt[N];
void dfs2(int x,int prt,int rr){rt[x]=rr;int i,y;for(i=h[x];i;i=e[i].next)if(((y=e[i].to)!=prt)&&(!vis[y]))dfs2(y,x,rr);}
void dfs(int x,int all,vector<Que>q)
{
	if(all<=1)return;cor=0;Fin(x,0,all);swap(x,cor);
	int i,j,y,z,v,u;Que p;
	cm=0;f[0][x]=a[x];dfs1(x,0);
	cm=1;g[x]=mi[x];for(i=h[x];i;i=e[i].next)if(!vis[y=e[i].to]){f[1][y]=a[y];dfs1(y,x);}g[x]=IN1;
	cm=2;for(i=h[x];i;i=e[i].next)if(!vis[y=e[i].to]){g[y]=mi[y];for(j=h[y];j;j=e[j].next)if(((z=e[j].to)!=x)&&(!vis[z])){f[2][z]=a[z];dfs1(z,y);}}
	rt[x]=x;for(i=h[x];i;i=e[i].next)if(!vis[y=e[i].to])dfs2(y,x,y);
	for(i=0,u=q.size();i<u;i++)
	{
		p=q[i];y=p.x;z=p.y;
		if(rt[y]==rt[z]){tmp[rt[y]].push_back(p);continue;}
		ans[p.d]=f[0][y]+f[0][z]-a[x];
		if(K==1)continue;
		cmin(ans[p.d],f[1][y]+f[1][z]);
		if(K==2)continue;
		cmin(ans[p.d],f[1][y]+f[2][z]);
		cmin(ans[p.d],f[2][y]+f[1][z]);
	}
	vis[x]=1;
	for(i=h[x];i;i=e[i].next)if(!vis[y=e[i].to])q=tmp[y],tmp[y].clear(),dfs(y,(siz[y]>siz[x])?(all-siz[x]):siz[y],q);
}
int main(){
	freopen("transmit.in","r",stdin);
	freopen("transmit.out","w",stdout);
	mxc[0]=INF;g[0]=f[0][0]=f[1][0]=f[2][0]=IN1;
	n=re();Q=re();K=re();int i,x,y;
	for(i=1;i<=n;i++)a[i]=re(),mi[i]=INF;
	for(i=1;i<n;i++)x=re(),y=re(),AddEdge(x,y),AddEdge(y,x),mi[y]=min(mi[y],a[x]),mi[x]=min(mi[x],a[y]);
	for(i=1;i<=Q;i++){x=re(),y=re();if(x==y){ans[i]=a[x];continue;}alq.push_back((Que){x,y,i});}
	dfs(1,n,alq);for(i=1;i<=Q;i++)printf("%lld\n",ans[i]);return 0;
}
