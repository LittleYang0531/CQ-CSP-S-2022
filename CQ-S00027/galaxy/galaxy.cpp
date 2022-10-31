#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,u,v,q,t,sum,ans,zxy[10005];
vector < int > a[1005];
bool jl[1005][1005],js[10005],pd;
inline int read()
{
	int x=0,f=1;
	char ch=getchar();
	while(ch<'0'||ch>'9')
	{
		if(ch=='-') f=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9')
	{
		x=(x<<1)+(x<<3)+(ch^48);
		ch=getchar();
	}
	return x*f;
}
void check(int cnt,int num)
{
	if(cnt==1&&num)
	{
		pd=true;
		return;
	}
	for(int g=0;g<a[cnt].size();++g)
	{
		if(a[cnt][g]!=sum&&(js[cnt]==false||a[cnt][g]==1))
		{
			js[cnt]=true;
			sum=a[cnt][g];
			check(a[cnt][g],num+1);
			js[cnt]=false;
		}
	}
	return;
}
bool work()
{
	for(int i=1;i<=n;++i)
	{
		if(zxy[i]!=1)
		return false;
	}
	return true;
}
signed main()
{
	freopen("galaxy.in","r",stdin);
	freopen("galaxy.out","w",stdout);
	n=read(),m=read();
	for(int i=1;i<=m;++i)
	{
		u=read(),v=read();
		zxy[u]++;
		a[u].push_back(v);
		jl[u][v]=true;
	}
	q=read();
	for(int i=1;i<=q;++i)
	{
		pd=false;
		t=read();
		if(t==1)
		{
			u=read(),v=read();
			zxy[u]--;
			jl[u][v]=false;
		}
		if(t==2)
		{
			u=read();
			for(int j=0;j<a[u].size();++j)
			{
				jl[u][j]=false;
			}
		}
		if(t==3)
		{
			u=read(),v=read();
			zxy[u]++;
			jl[u][v]=true;
		}
		if(t==4)
		{
			u=read();
			for(int j=0;j<a[u].size();++j)
			{
				jl[u][j]=true;
			}
		}
		sum=1;
		check(1,0);
		if(pd&&work())
			printf("YES\n");
		else
			printf("NO\n");
	}
	return 0;
}
