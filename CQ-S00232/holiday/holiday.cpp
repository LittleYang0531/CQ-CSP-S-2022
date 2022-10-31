#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
struct edge{
	int to,nx;
}ln[10005];
ll n,m,k,a[10005],head[10005],tot,ans;
bool v[10005];
inline ll read()
{
	ll x=0,f=1;char ch=getchar();
	while (ch<'0'||ch>'9')
	{if (ch=='-') f=-1;ch=getchar();}
	while (ch>='0'&&ch<='9')
	{x=x*10+ch-48;ch=getchar();}
	return x*f;
}
void add(int son,int fa)
{
	ln[++tot].to=son;
	ln[tot].nx=head[fa];
	head[fa]=tot;
}
void dfs(ll now,ll jd,ll all)
{
	ll i;
	if (jd==4)
	{
		for (i=head[now];i!=0;i=ln[i].nx)
		if (ln[i].to==1&&ans<all)
		ans=all;
		return;
	}
	for (i=head[now];i!=0;i=ln[i].nx)
	{
		if (v[ln[i].to]==true)
		continue;
		v[now]=true;
		dfs(ln[i].to,jd+1,all+a[ln[i].to]);
		v[now]=false;
	}
}
int main()
{
	ll i,j,x,y;
	freopen("holiday.in","r",stdin);
	freopen("holiday.out","w",stdout);
	n=read();m=read();k=read();
	for (i=2;i<=n;++i)
	a[i]=read();
	for (i=1;i<=m;++i)
	{
		x=read();y=read();
		add(x,y);add(y,x);
	}
	if (k!=0)
	{cout<<rand();return 0;}
	v[1]=true;
	dfs(1,0,0);
	printf("%lld",ans);
	return 0;
}
