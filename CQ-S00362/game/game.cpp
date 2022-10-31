#include<bits/stdc++.h>
using namespace std;
int n,m,q;
int l1,r1,l2,r2;
int tot;
int mn[900];
int a[900],b[900];
int main()
{
	//freopen("game.in","r",stdin);
	//freopen("game.out","w",stdout);
	cin>>n>>m>>q;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(int i=1;i<=m;i++)
	{
		cin>>b[i];
	}
	for(int i=1;i<=q;i++)
	{
		int Aa=8,Bb=8;//1为含负数，2为含0，3为含负数和0，4为不含负数 
		cin>>l1>>r1>>l2>>r2; 
		int big1=-999,small1=999,big2=-999,small2=999;
		int A0=0,B0=0;//0表示没有0 
		for(int j=l1;j<=r1;j++)
		{
			if(a[j]>big1) big1=a[j];
			if(a[j]<small1) small1=a[j];
			if(a[j]==0) A0=1;
		}
		for(int k=l2;k<=r2;k++)
		{
			if(b[k]>big2) big2=b[k];
			if(b[k]<small2) small2=b[k];
			if(b[k]==0) B0=1;
		}
		if(big1>0&&small1<0&&A0==1&&big2>0&&small2<0)
		{
			mn[i]=0;
		}
		if(big1>0&&small1<0&&big2>0&&small2>0) 
			mn[i]=big1*small2;
		if(big1>0&&small1<0&&A0==0&&big2>0&&small2<0&&B0==0)
		{
			int p=-999;
			for(int j=l1;j<=r1;j++)
			{
				if(a[j]<0&&a[j]>p) p=a[j];
			}
			mn[i]=p*big2;
		}
		if(big1>0&&small1<=0&&A0==0&&small2>0)
		{
			mn[i]=big1*small2;
		}
		if(big1>0&&small1<0&&A0==1&&big2<0)
		{
			mn[i]=big2*big1;
		}
	}
	for(int i=1;i<=q;i++)
	{
		cout<<mn[i]<<endl; 
	}
	
	return 0;
}
