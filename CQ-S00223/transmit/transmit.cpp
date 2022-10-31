#include<cstdio>
#include<algorithm>
using namespace std;
const long long INF=1e15;
inline void read(int &hhh)
{
	int x=0;
	char c=getchar();
	while((c>'9'||c<'0')&&c!='-')	c=getchar();
	if(c!='-')	x=c^'0';
	char d=getchar();
	while(d>='0'&&d<='9')
	{
		x=(x<<1)+(x<<3)+(d^'0');
		d=getchar();
	}
	if(c!='-')	hhh=x;
	else	hhh=-x;
}
int n,q,k,v[200010],pu,pv;
int head[200010],nxt[400010],to[400010],cntot;
inline void addedge(int one,int ano)
{
	nxt[++cntot]=head[one];
	to[cntot]=ano;
	head[one]=cntot;
	nxt[++cntot]=head[ano];
	to[cntot]=one;
	head[ano]=cntot;
}
int fa[200010],siz[200010],son[200010],dep[200010],hb[200010],dfn[200010],ton[200010],cnt,mn[200010];
void dfs1(int x,int las)
{
	fa[x]=las;
	siz[x]=1;
	dep[x]=dep[las]+1;
	for(int i=head[x];i;i=nxt[i])
	{
		int y=to[i];
		if(y!=las)
		{
			dfs1(y,x);
			siz[x]+=siz[y];
			if(siz[y]>siz[son[x]])	son[x]=y;
		}
	}
}
void dfs2(int x,int las,bool heavy)
{
	if(heavy)	hb[x]=hb[las];
	else	hb[x]=x;
	dfn[x]=++cnt;
	ton[cnt]=x;
	if(son[x])
	{
		dfs2(son[x],x,1);
		for(int i=head[x];i;i=nxt[i])
		{
			int y=to[i];
			if(y!=las&&y!=son[x])	dfs2(y,x,0);
		}
	}
}
struct cube
{
	long long num[3][3];
}emp,nodes[800010],exnodes[800010],ONE;
inline cube times(cube one,cube ano)
{
	cube res=emp;
	if(k==1)	res.num[0][0]=one.num[0][0]+ano.num[0][0];
	else if(k==2)
	{
		res.num[0][0]=min(one.num[0][0]+ano.num[0][0],one.num[0][1]+ano.num[1][0]);
		res.num[0][1]=min(one.num[0][0]+ano.num[0][1],one.num[0][1]+ano.num[1][1]);
		res.num[1][0]=min(one.num[1][0]+ano.num[0][0],one.num[1][1]+ano.num[1][0]);
		res.num[1][1]=min(one.num[1][0]+ano.num[0][1],one.num[1][1]+ano.num[1][1]);
	}
	else
	{
		res.num[0][0]=min(min(one.num[0][0]+ano.num[0][0],one.num[0][1]+ano.num[1][0]),one.num[0][2]+ano.num[2][0]);
		res.num[0][1]=min(min(one.num[0][0]+ano.num[0][1],one.num[0][1]+ano.num[1][1]),one.num[0][2]+ano.num[2][1]);
		res.num[0][2]=min(min(one.num[0][0]+ano.num[0][2],one.num[0][1]+ano.num[1][2]),one.num[0][2]+ano.num[2][2]);
		res.num[1][0]=min(min(one.num[1][0]+ano.num[0][0],one.num[1][1]+ano.num[1][0]),one.num[1][2]+ano.num[2][0]);
		res.num[1][1]=min(min(one.num[1][0]+ano.num[0][1],one.num[1][1]+ano.num[1][1]),one.num[1][2]+ano.num[2][1]);
		res.num[1][2]=min(min(one.num[1][0]+ano.num[0][2],one.num[1][1]+ano.num[1][2]),one.num[1][2]+ano.num[2][2]);
		res.num[2][0]=min(min(one.num[2][0]+ano.num[0][0],one.num[2][1]+ano.num[1][0]),one.num[2][2]+ano.num[2][0]);
		res.num[2][1]=min(min(one.num[2][0]+ano.num[0][1],one.num[2][1]+ano.num[1][1]),one.num[2][2]+ano.num[2][1]);
		res.num[2][2]=min(min(one.num[2][0]+ano.num[0][2],one.num[2][1]+ano.num[1][2]),one.num[2][2]+ano.num[2][2]);
	}
	return res;
}
inline cube init(int val,int exval)
{
	if(k==1)
	{
		cube res;
		res.num[0][0]=val;
		return res;
	}
	else if(k==2)
	{
		cube res;
		res.num[0][0]=res.num[0][1]=val;
		res.num[1][0]=0;
		res.num[1][1]=INF;
		return res;
	}
	else
	{
		cube res;
		res.num[0][0]=res.num[0][1]=res.num[0][2]=val;
		res.num[1][0]=res.num[2][1]=0;
		res.num[1][1]=exval;
		res.num[1][2]=res.num[2][0]=res.num[2][2]=INF;
		return res;
	}
}
void build(int l,int r,int x)
{
	if(l^r)
	{
		int mid=(l+r)>>1;
		build(l,mid,x<<1);
		build(mid+1,r,x<<1|1);
		nodes[x]=times(nodes[x<<1],nodes[x<<1|1]);
		exnodes[x]=times(exnodes[x<<1|1],exnodes[x<<1]);
	}
	else	nodes[x]=exnodes[x]=init(v[ton[l]],mn[ton[l]]);
}
cube findy(int l,int r,int x,int fr,int ba)
{
	if(l>ba||r<fr)	return ONE;
	if(l>=fr&&r<=ba)	return nodes[x];
	else
	{
		int mid=(l+r)>>1;
		return times(findy(l,mid,x<<1,fr,ba),findy(mid+1,r,x<<1|1,fr,ba));
	}
}
cube exfindy(int l,int r,int x,int fr,int ba)
{
	if(l>ba||r<fr)	return ONE;
	if(l>=fr&&r<=ba)	return exnodes[x];
	else
	{
		int mid=(l+r)>>1;
		return times(exfindy(mid+1,r,x<<1|1,fr,ba),exfindy(l,mid,x<<1,fr,ba));
	}
}
inline long long solve(int x,int y)
{
	cube fir=ONE,sec=ONE;
	int fx=hb[x],fy=hb[y],orix=x;
	while(fx!=fy)
	{
		if(dep[fx]>=dep[fy])
		{
			fir=times(findy(1,n,1,dfn[fx],dfn[x]-(x==orix?1:0)),fir);
			x=fa[fx];
			fx=hb[x];
		}
		else
		{
			sec=times(sec,exfindy(1,n,1,dfn[fy],dfn[y]));
			y=fa[fy];
			fy=hb[y];
		}
	}
	if(dep[x]>=dep[y])	fir=times(findy(1,n,1,dfn[y],dfn[x]-(x==orix?1:0)),fir);
	else	sec=times(sec,exfindy(1,n,1,dfn[x]+(x==orix?1:0),dfn[y]));
	fir=times(sec,fir);
	return fir.num[0][0]+v[orix];
}
int main()
{
	freopen("transmit.in","r",stdin);
	freopen("transmit.out","w",stdout);
	read(n);
	read(q);
	read(k);
	for(int i=0;i<k;++i)
	{
		for(int j=0;j<k;++j)	emp.num[i][j]=INF;
	}
	ONE=emp;
	for(int i=0;i<k;++i)	ONE.num[i][i]=0;
	for(int i=1;i<=n;++i)
	{
		read(v[i]);
		mn[i]=1000000000;
	}
	for(int i=1;i<n;++i)
	{
		read(pu);
		read(pv);
		mn[pu]=min(mn[pu],v[pv]);
		mn[pv]=min(mn[pv],v[pu]);
		addedge(pu,pv);
	}
	dfs1(1,1);
	dfs2(1,1,0);
	build(1,n,1);
	for(int i=1;i<=q;++i)
	{
		read(pu);
		read(pv);
		printf("%lld\n",solve(pu,pv));
	}
	return 0;
}
