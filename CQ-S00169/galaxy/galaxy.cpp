#include<bits/stdc++.h>
using namespace std;
int read()
{
	int x=0,f=1;
	char c=getchar();
	while(!isdigit(c))
	{
		if(c=='-')
		f=-1;
		c=getchar();
	}
	while(isdigit(c))	
		x=x*10+c-'0',c=getchar();
	return x*f;
}
const int MAXN=2505;
int n,m,q,ans,a[MAXN];
int head[MAXN<<1],to[MAXN<<1],nxt[MAXN<<1],tot;
bool f[MAXN],r[MAXN];
bool sol[MAXN];
inline void add(int x,int y)
{
	to[++tot]=y;
	nxt[tot]=head[x];
	head[x]=tot;
}
inline void upd(int x,int y)
{
	for(int i=head[x];i;i=nxt[i])
	if(to[i]==y)
	r[i]=0;
	
}
inline void dt(int x,int y)
{
	for(int i=head[x];i;i=nxt[i])
	if(to[i]==y)
	r[i]=1;
}
bool solve()
{
	int cnt[MAXN];
	for(int i=1;i<=n;i++)
	{
		cnt[i]=0;
		for(int j=head[i];i;i=nxt[i])
		{
		if(f[to[i]]||r[i])
		continue;
		cnt[i]++;
		if(cnt[i]>1)
		return 0;
		}
	}
	return 1;
}
bool solve2(int x)
{
	if(sol[x])
	return 1;
	sol[x]=1;
	bool ok=0;
	for(int i=head[x];i;i=nxt[i])
	{
		ok=solve2(to[i]);
		if(ok)
		return 1;
	}
	return 0;
}
bool solve1()
{
	for(int i=1;i<=n;i++)
	{
		memset(sol,false,sizeof sol);
	if(!solve2(i)) 
	return 0;
	}
	return 1;
}
int main()
{
	freopen("galaxy.in","r",stdin);
	freopen("galaxy.out","w",stdout);
	
	n=read();
	m=read();
	for(int i=1;i<=m;i++)
	{
		int x,y;
		x=read(),y=read();
		add(x,y);
	}
	q=read();
	while(q--)
	{
		int op,x,y;
		op=read();
		x=read();
		if(op==1)
		{
			y=read();
			dt(x,y);
		}
		if(op==2)
		{
			f[x]=1;
		}
		if(op==3)
		{
			y=read();
			upd(x,y);
		}
		if(op==4)
		{
			f[x]=0;
		}
		if(solve()&&solve1())
		cout<<"YES"<<endl;
		else
		cout<<"NO"<<endl;
	}
	
	//cout<<ans<<endl;
	return 0;
}
