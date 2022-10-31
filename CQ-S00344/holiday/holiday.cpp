#include<bits/stdc++.h>
using namespace std;
inline long long read()
{
	long long res=0;
	char tmp=getchar();
	while(tmp>'9'||tmp<'0') tmp=getchar();
	while(tmp<='9'&&tmp>='0')
	{
		res=res*10+tmp-'0';
		tmp=getchar();
	}
	return res;
}
long long a[10005];
struct Edge
{
	long long to,next,dis;
}edge[10005];
long long n,m,k;
long long maxn=0;
long long head[10005],cedge;
bool vis[10005];
inline void add(long long x,long long y,long long dis)
{
	edge[++cedge].to=y;
	edge[cedge].next=head[x];
	edge[cedge].dis=dis;
	head[x]=cedge;
}
long long way[10],cway;
inline void dfsn(int k,int tot,long long sum)//不换乘情况 
{
	if(tot==5)
	{
		if(k==1)
		{
			maxn=max(maxn,sum);
//			for(int i=1;i<=cway;i++) cout<<way[i]<<" ";
//			cout<<endl;
		}
		return;
	}
	for(int i=head[k];i;i=edge[i].next)
	{
		if(vis[edge[i].to]) continue;
		vis[edge[i].to]=true;
		way[++cway]=edge[i].to;
		dfsn(edge[i].to,tot+1,sum+edge[i].dis);
		cway--;
		vis[edge[i].to]=false;
	}
}
inline bool cmp(long long x,long long y)
{
	return x>y;
}
int main()
{
	freopen("holiday.in","r",stdin);
	freopen("holiday.out","w",stdout);
	n=read();m=read();k=read();
	for(long long i=2;i<=n;i++) a[i]=read();
	for(long long i=1;i<=m;i++)
	{
		long long x,y;
		x=read();
		y=read();
		add(x,y,a[y]);
		add(y,x,a[x]);
	}
//	for(int i=1;i<m;i++)
	if(k==0)//没有转车机会
	{
		dfsn(1,0,0);
		printf("%lld",maxn);
		return 0;
	}
	sort(a+1,a+n+1,cmp);
	maxn=a[1]+a[2]+a[3]+a[4];
	printf("%lld",maxn);
	return 0;
}
