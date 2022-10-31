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
int n,k,q,w[MAXN][MAXN];
long long ans,v[MAXN];
bool f[MAXN];
void init()
{
	for(int k=1;k<=n;k++)
	{
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=n;j++)
			w[i][j]=min(w[i][k]+w[k][j],w[i][j]);
		}
	}
}
void solve(int x,int t,long long xans)
{
	if(x==t)
	{
		/*for(int i=1;i<=n;i++)
		cout<<f[i];
		cout<<endl<<xans<<endl;*/
		ans=min(ans,xans);
		return ;
	}
	for(int i=1;i<=n;i++)
	{
		if(!f[i]&&w[x][i]<=k)
		{
			f[i]=1;
			solve(i,t,xans+v[i]);
			f[i]=0;
		}
		
	}
}
int main()
{
	freopen("transmit.in","r",stdin);
	freopen("transmit.out","w",stdout);
	
	n=read();
	q=read();
	k=read();
	for(int i=1;i<=n;i++)
	v[i]=read();
	for(int i=1;i<=n;i++)
	for(int j=1;j<=n;j++)
	w[i][j]=1e9,w[i][i]=0;
	for(int i=1;i<n;i++)
	{
		int a,b;
		a=read(),b=read();
		w[b][a]=w[a][b]=1;
	}
	init();
	while(q--)
	{
		int s,t;
		s=read(),t=read();
		ans=1e9;
		f[s]=1;
		solve(s,t,v[s]);
		f[s]=0;
		cout<<ans<<endl;
	}
	
	return 0;
}
