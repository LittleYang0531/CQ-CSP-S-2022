#include <bits/stdc++.h>
using namespace std;
int a[100005],b[100005];
int max1[100005][20],max2[100005][20];
int min1[100005][20],min2[100005][20];

int askmax1(int l,int r){int t=log2(r-l+1);return max(max1[l][t],max1[r-(1<<t)+1][t]);}
int askmax2(int l,int r){int t=log2(r-l+1);return max(max2[l][t],max2[r-(1<<t)+1][t]);}
int askmin1(int l,int r){int t=log2(r-l+1);return min(min1[l][t],min1[r-(1<<t)+1][t]);}
int askmin2(int l,int r){int t=log2(r-l+1);return min(min2[l][t],min2[r-(1<<t)+1][t]);}

int main()
{
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	int n,m,q;
	cin>>n>>m>>q;
	bool allgreterthan0=0;
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]),max1[i][0]=min1[i][0]=a[i],allgreterthan0=(a[i]>0);
	for(int i=1;i<=m;i++)
		scanf("%d",&b[i]),max2[i][0]=min2[i][0]=b[i],allgreterthan0=(b[i]>0);
	for(int j=1;j<=log2(n);j++)
		for(int i=1;i+(1<<j)-1<=n;i++)
		{
			max1[i][j]=max(max1[i][j-1],max1[i+(1<<(j-1))][j-1]);
			min1[i][j]=min(min1[i][j-1],min1[i+(1<<(j-1))][j-1]);
		}
	for(int j=1;j<=log2(m);j++)
		for(int i=1;i+(1<<j)-1<=m;i++)
		{
			max2[i][j]=max(max2[i][j-1],max2[i+(1<<(j-1))][j-1]);
			min2[i][j]=min(min2[i][j-1],min2[i+(1<<(j-1))][j-1]);
		}
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
	for(int i=1;i<=q;i++)
	{
		int l1,r1,l2,r2;
		scanf("%d%d%d%d",&l1,&r1,&l2,&r2);
		int t1=askmax1(l1,r1);
		int t2=askmax2(l2,r2);
		int t3=askmin1(l1,r1);
		int t4=askmin2(l2,r2);
		if(allgreterthan0)
		{
			cout<<1ll*t1*t4<<endl;
			continue;
		}
		if(l1==r1)
		{
			int x=a[l1];
			if(x>0)
				cout<<1ll*t4*x<<endl;
			else if(x==0)cout<<0<<endl;
			else cout<<1ll*x*t2<<endl;
			continue;
		}
		if(l2==r2)
		{
			int x=b[l2];
			if(x>0)
				cout<<1ll*t1*x<<endl;
			else if(x==0)cout<<0<<endl;
			else cout<<1ll*x*t3<<endl;
			continue;
		}
		cout<<0<<endl;
	}
	return 0;
}
