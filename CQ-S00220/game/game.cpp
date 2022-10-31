#include<iostream>
#include<cstdio>
using namespace std;
long long a[100005],b[100005];
int n,m,l1,l2,r1,r2,q;
int main()
{
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
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
		cin>>l1>>r1>>l2>>r2;
		long long max1=-1000000001,max2=-1000000001,min1=1000000001,min2=1000000001,xz=1000000001,df=1;
		int flag1=0,flag2=0;
		for(int j=l1;j<=r1;j++)
		{
			if(a[j]==0)
			{
				flag1=1;
			}
			if(a[j]>max1)
			{
				max1=a[j];
			}
			if(a[j]<min1)
			{
				min1=a[j];
			}
			if(a[j]>0&&a[j]<xz)
			{
				xz=a[j];
			}
			if(a[j]<0&&a[j]>df)
			{
				df=1;
			}
		}
		for(int j=l2;j<=r2;j++)
		{
			if(b[j]==0)
			{
				flag2=1;
			}
			if(b[j]>max2)
			{
				max2=b[j];
			}
			if(b[j]<min2)
			{
				min2=b[j];
			}
		}
		if(max1<0)
		{
			if(max2<0)
			{
				cout<<min2*max1<<endl;
				continue;
			}
			else if(min2>0)
			{
				cout<<min1*max2<<endl;
				continue;
			}
			else if(min2<=0&&max2>=0)
			{
				cout<<max2*min1<<endl;
				continue;
			}
		}
		else if(min1<=0&&max1>=0)
		{
			if(max2<0)
			{
				cout<<min1*max2<<endl;
				continue;
			}
			else if(max2>=0&&min2<=0)
			{
				if(flag1==1)
				{
					cout<<0<<endl;
					continue;
				}
				else
				{
					cout<<min(xz*min2,df*max2)<<endl;
					continue;
				}
			}
			else
			{
				cout<<min2*max1<<endl;
				continue;
			}
		}
		else if(min1>0)
		{
			if(max2<0)
			{
				cout<<min1*min2<<endl;
				continue;
			}
			else if(min2<=0&&max2>=0)
			{
				cout<<min2*min1<<endl;
				continue;
			}
			else 
			{
				cout<<min1*max2<<endl;
				continue;
			}
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

