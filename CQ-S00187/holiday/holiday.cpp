#include<bits/stdc++.h>
using namespace std;
int n,m,k,a[2501],nx[2501],sum1=0,sum2=0,pd[2501]={},x1=1,maxn=0,i=2,p;
struct l
{
	int x,y;
}b[10001];
int f(int x1,int p)
{
	int cs=0;
	if(x1==1&&cs==4)
		return sum2;
	if(x1==1&&cs!=4)
		return -1;
	if(x1!=1&&cs==4)
		return -1;
	if(pd[i]==0&&cs!=4&&i<=n)
	{
		pd[i]=1;
		x1=i;
		sum1+=a[i];
		cs++;
		for(int j=1;j<=m;j++)
		{
			if(b[j].x==i&&cs!=4&&b[j].y<i&&p>0)
			{
				for(int q=1;q<=m;q++)
				{
					if(q!=j&&b[q].x==b[j].y)
						return f(b[q].y,p-1);
				}
			}
			else
			if(b[j].y==i&&cs!=4&&b[j].x<i&&p>0)
			{
				for(int q=1;q<=m;q++)
				{
					if(q!=j&&b[q].y==b[j].x)
						return f(b[q].x,p-1);
				}
			}
			else
				return f(i+1,p);
		}
		pd[i]=0;
	} 
}
int main()
{
	freopen("holiday.in","r",stdin);
	freopen("holiday.out","w",stdout);
	cin>>n>>m>>k;
	p=k+1;
	for(int i=2;i<=n;i++)
		cin>>a[i];
	int u=0;
	for(int i=1;i<=m;i++)
	{
		cin>>b[i].x>>b[i].y;
		if(b[i].x==1)
			nx[++u]=b[i].y;
		if(b[i].y==1)
			nx[++u]=b[i].x;
	}
	for(int i=1;i<=u;i++)
	{
		maxn=max(f(nx[i],k),maxn);
	}
	cout<<maxn;
	return 0;
}
