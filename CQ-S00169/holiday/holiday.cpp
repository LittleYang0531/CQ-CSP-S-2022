#include<bits/stdc++.h>
using namespace std;
long long read()
{
	long long x=0,f=1;
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
long long a[MAXN],ans;
long long n,m,k,w[MAXN][MAXN];
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
void solve(int x,int js,long long xans)
{
	if(x==1&&js!=4&&xans>0)
	return ;
	if(x==1&&js==4)
	{
		/*for(int i=1;i<=n;i++)
		cout<<f[i];
		cout<<endl<<xans<<endl;*/
		
		ans=max(ans,xans);
		return ;
	}
	for(int i=1;i<=n;i++)
	{
		if(!f[i]&&w[x][i]-1<=k)
		{
			//cout<<x<<' '<<i<<' '<<k<<endl;
			f[i]=1;
			solve(i,js+(i!=1),xans+a[x]);
			f[i]=0;
		}
	}
}
int main()
{
	freopen("holiday.in","r",stdin);
	freopen("holiday.out","w",stdout);
	n=read();
	m=read();
	k=read();
	for(int i=2;i<=n;i++) a[i]=read();
	for(int i=1;i<=n;i++)
	for(int j=1;j<=n;j++)
	w[i][j]=1e9,w[i][i]=0;
	for(int i=1;i<=m;i++)
	{
		int x,y;
		x=read(),y=read();
		w[y][x]=w[x][y]=1;
	}
	init();
	/*for(int i=1;i<=n;cout<<'\n',i++)
	for(int j=1;j<=n;j++)
	cout<<w[i][j]<<' ';*/
	solve(1,0,0);
	cout<<ans<<endl;
	return 0;
}
