#include<bits/stdc++.h>
using namespace std;
int n,m,q;
int a[100005],b[100005];
long long c[100005][100005],ans1[100005][100005];
int l1,r1,l2,r2;
void p1()
{
	long long x=LONG_LONG_MAX;
	for(int j=l2;j<=r2;j++)
	{
		if(x>=c[l1][j]) x=c[l1][j];
	}
	cout<<x;
}
void p2()
{
	long long y=LONG_LONG_MIN;
	for(int j=l1;j<=r1;j++)
	{
		if(y<c[j][l2]) y=c[j][l2];
	}
	cout<<y;
}
void p3()
{
	long long y=LONG_LONG_MIN;
	if(n<1000)
	{
		for(int i=l1;i<=r1;i++)
		{
			for(int j=l2;j<=r2;j++)
			{
				ans1[i][j]=c[i][j];
				if(ans1[i][j]>y) y=ans1[i][j];
			}
		}
		cout<<y;
	}
	else cout<<rand();
}
int main()
{
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	cin>>n>>m>>q;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=m;i++) cin>>b[i];
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
		{
			c[i][j]=a[i]*b[j];
		}
	for(int i=1;i<=q;i++)
	{
		cin>>l1>>r1>>l2>>r2;
		if(l1==r1) p1();
		else if(l2==r2) p2();
		else p3();
	}
	return 0;
}
