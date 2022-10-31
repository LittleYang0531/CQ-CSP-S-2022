#include<bits/stdc++.h>
using namespace std;
long long n,m,q,a[100005],b[100005],l,r,l1,r1,bs,bs1,zd,zd1,zx,zx1,ans,ans1,m2,m1;
int main()
{
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	cin>>n>>m>>q;
	for(int i=1;i<=n;i++)
	cin>>a[i];
	for(int i=1;i<=m;i++)
	cin>>b[i];
	for(int i=1;i<=q;i++)
	{
		bs=bs1=-1e9-5;
		zd=zd1=-1e9-5;
		zx=zx1=1e9+5;
		ans=ans1=0;
		cin>>l>>r>>l1>>r1;
		for(int j=l1;j<=r1;j++)
		{
			if(abs(0-b[j])<abs(0-bs1))
			bs1=b[j];
			zd1=max(b[j],zd1);
			zx1=min(b[j],zx1);
		}
		for(int j=l;j<=r;j++)
		{
			if(abs(0-a[j])<abs(0-bs))
			bs=a[j];
			else if(abs(0-a[j])==abs(0-bs) && bs!=0 && bs!=a[j]){
				m2=max(a[j]*zx1,a[j]*zd1);
				m1=max(bs*zx1,bs*zd1);
				if(m2>m1)
				bs=a[j];
			}
			zd=max(a[j],zd);
			zx=min(zx,a[j]);
		}
		if(zd1<0)
		ans=zx;
		else if(zx1>0)
		ans=zd; else ans=bs;
		ans1=min(ans*zx1,min(ans*zd1,ans*bs1));
		cout<<ans1<<endl;	
	}
	return 0;
}
