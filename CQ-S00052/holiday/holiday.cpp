#include<bits/stdc++.h>
using namespace std;
int a[2505][2505],t[2505],f[2505];
int h[2505],maxn;
int n,m,k;
int g;
int dpa(int xy,int ks,int total)
{
	if(ks==5)
	{
		for(int i=1;i<=t[xy];i++)
		{
			if(a[xy][i]==1)
			{
				maxn=max(maxn,total);
				return total;
			}
		}
		return 0;
	}
	for(int i=1;i<=t[xy];i++)
	{
		if(h[a[xy][i]]!=1)
		{
			h[a[xy][i]]=1;
			dpa(a[xy][i],ks+1,total+f[a[xy][i]]);
			h[a[xy][i]]=0;
		}
	}
}
int findn(int xy,int ks)
{
	if(k<ks-2)
	{
		return 0;
	}
	if(xy==1)
	{
		g=1;
		return 1;
	}
	for(int i=1;i<=t[xy];i++)
	{
		findn(a[xy][i],ks+1);
	}
}
int dpb(int xy,int ks,int total,int kn)
{
	if(k<kn-1)
	{
		return 0;
	}
	if(ks==5)
	{
		g=0;
		findn(xy,1);
		if(g==1)
		{
			maxn=max(maxn,total);
			return total;
		}
		return 0;
	}
	for(int i=1;i<=t[xy];i++)
	{
		dpb(a[xy][i],ks,total,kn+1);
		if(h[a[xy][i]]==0)
		{
		    h[a[xy][i]]=1;
		    dpb(a[xy][i],ks+1,total+f[a[xy][i]],1);
		    h[a[xy][i]]=0;
	    }
	}
}
int main()
{
	freopen("holiday.in","r",stdin);
	freopen("holiday.out","w",stdout);
	cin>>n>>m>>k;
	h[1]=1;
	for(int i=2;i<=n;i++)
	{
		cin>>f[i];
	}
	for(int i=1;i<=m;i++)
	{
		int x,y;
		cin>>x>>y;
		t[x]++;
		a[x][t[x]]=y;
		t[y]++;
		a[y][t[y]]=x;
	}
	if(k==0)
	{
		dpa(1,1,0);
		cout<<maxn;
	}
	if(k!=0)
	{
		dpb(1,1,0,1);
		cout<<maxn;
	}
	return 0;
}
