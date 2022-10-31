#include<cstdio>
#include<algorithm>
using namespace std;
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
int n,m,q,a[100010],b[100010],opl,opr,pol,por,st[100010][17],ts[100010][17],lgs[100010],zera[100010];
long long ans;
inline int findbmx(int l,int r)
{
	int t=lgs[r-l+1];
	return max(st[l][t],st[r-(1<<t)+1][t]);
}
inline int findbmn(int l,int r)
{
	int t=lgs[r-l+1];
	return min(ts[l][t],ts[r-(1<<t)+1][t]);
}
const int INF=1e9+7;
int nodes[400010][2][2];//0 0:psmx,0 1:psmn,1 0:ngmx,1 1:ngmn 
void build(int l,int r,int x)
{
	if(l^r)
	{
		int mid=(l+r)>>1;
		build(l,mid,x<<1);
		build(mid+1,r,x<<1|1);
		nodes[x][0][0]=max(nodes[x<<1][0][0],nodes[x<<1|1][0][0]);
		nodes[x][0][1]=min(nodes[x<<1][0][1],nodes[x<<1|1][0][1]);
		nodes[x][1][0]=max(nodes[x<<1][1][0],nodes[x<<1|1][1][0]);
		nodes[x][1][1]=min(nodes[x<<1][1][1],nodes[x<<1|1][1][1]);
	}
	else
	{
		if(a[l]<0)
		{
			nodes[x][0][0]=-INF;
			nodes[x][0][1]=INF;
			nodes[x][1][0]=nodes[x][1][1]=a[l];
		}
		else if(a[l]>0)
		{
			nodes[x][1][0]=-INF;
			nodes[x][1][1]=INF;
			nodes[x][0][0]=nodes[x][0][1]=a[l];
		}
	}
}
int findy(int l,int r,int x,int fr,int ba,int id,int di)
{
	if(l>ba||r<fr)	return di?INF:-INF;
	if(l>=fr&&r<=ba)	return nodes[x][id][di];
	else
	{
		int mid=(l+r)>>1;
		return di?min(findy(l,mid,x<<1,fr,ba,id,di),findy(mid+1,r,x<<1|1,fr,ba,id,di)):max(findy(l,mid,x<<1,fr,ba,id,di),findy(mid+1,r,x<<1|1,fr,ba,id,di));
	}
}
int main()
{
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	read(n);
	read(m);
	read(q);
	for(int i=1;i<=n;++i)
	{
		read(a[i]);
		zera[i]=zera[i-1];
		if(!a[i])	++zera[i];
	}
	for(int i=1;i<=m;++i)	read(b[i]);
	for(int i=1;i<=m;++i)	st[i][0]=ts[i][0]=b[i];
	for(int i=2;i<=m;++i)	lgs[i]=lgs[i>>1]+1;
	for(int i=1,j=2;j<=m;++i,j<<=1)
	{
		for(int k=1;k+j-1<=m;++k)
		{
			st[k][i]=max(st[k][i-1],st[k+(j>>1)][i-1]);
			ts[k][i]=min(ts[k][i-1],ts[k+(j>>1)][i-1]);
		}
	}
	build(1,n,1);
	for(int i=1;i<=q;++i)
	{
		read(opl);
		read(opr);
		read(pol);
		read(por);
		ans=-(long long)INF*INF;
//		fprintf(stderr," %d %d %d %d %d %d\n",findbmn(pol,por),findbmx(pol,por),findy(1,n,1,opl,opr,0,0),findy(1,n,1,opl,opr,0,1),findy(1,n,1,opl,opr,1,0),findy(1,n,1,opl,opr,1,1));
		int cur=findbmn(pol,por);
		if(cur<0)
		{
			int ruc=findy(1,n,1,opl,opr,0,1);
			if(ruc!=INF)	ans=max(ans,(long long)cur*ruc);
		}
		else
		{
			int ruc=findy(1,n,1,opl,opr,0,0);
			if(ruc!=-INF)	ans=max(ans,(long long)cur*ruc);
		}
		cur=findbmx(pol,por);
		if(cur>0)
		{
			int ruc=findy(1,n,1,opl,opr,1,0);
			if(ruc!=-INF)	ans=max(ans,(long long)cur*ruc);
		}
		else
		{
			int ruc=findy(1,n,1,opl,opr,1,1);
			if(ruc!=INF)	ans=max(ans,(long long)cur*ruc);
		}
		if(zera[opr]-zera[opl-1])	ans=max(ans,0ll);
		printf("%lld\n",ans);
	}
	return 0;
}
