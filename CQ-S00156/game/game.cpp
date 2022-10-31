#include<bits/stdc++.h>
using namespace std;
int n,m,q;
int a[100005],b[100005];
int l,r,ll,rr;
int f=0,f1=0;
long long ans[100005];
int main()
{
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	cin>>n>>m>>q;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		if(a[i]<=0) f=1;
	}
	for(int i=1;i<=m;i++)
	{
		cin>>b[i];
		if(b[i]<=0) f1=1;
	}
	for(int i=1;i<=q;i++)
	{
		cin>>l>>r>>ll>>rr;
		int x=0,y=0;
		if(f==0&&f1==0)
		{
			x=l;
			y=ll;
		     for(int j=l;j<=r;j++)
		     {
		     	if(a[j]>a[x]) x=j;
			 }
			 for(int j=ll;j<=rr;j++)
			 {
			 	if(b[j]<b[y]) y=j;
			 }
		}
		else if(l==r||ll==rr)
		{
			x=l;
			y=ll;
			if(ll!=rr)
			{
				if(a[x]<0)
				for(int j=ll;j<=rr;j++)
				{
					if(b[y]<b[j]) y=j;
				}
				if(a[x]>0)
				for(int j=ll;j<=rr;j++)
				{
					if(b[y]>b[j]) y=j;
				}
			}
			if(l!=r)
			{
				if(b[y]<0)
				for(int j=l;j<=r;j++)
				{
					if(a[x]>a[j]) x=j;
				}
				if(b[y]>0)
				for(int j=l;j<=r;j++)
				{
					if(a[x]<a[j]) x=j;
				}
			}
		}
		ans[i]=a[x]*b[y];
	}
	for(int i=1;i<=q;i++)
	cout<<ans[i]<<endl;
	return 0;
}
