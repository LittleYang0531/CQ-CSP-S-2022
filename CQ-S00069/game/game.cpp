#include <bits/stdc++.h>
using namespace std;
#define int long long
int n,m,q,a[9999999],b[9999999];
signed main()
{
//	freopen("game.in","r",stdin);
//	freopen("game.out","w",stdout);
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
		int ap,an,bp,bn,l1,l2,r1,r2,maa=0x9ffffff,mia=0,maa2=0x9ffffff,mia2=0,mab=0x9ffffff,mib=0,mab2=0x9ffffff,mib2=0;
		cin>>l1>>r1>>l2>>r2;
		for(int j=l1;j<=r1;j++)
		{
			if(a[j]>0) ap=1;
			else an=1;
			if(abs(maa)>abs(a[j])&&a[j]<=0) maa=a[j];
			if(abs(mia)<abs(a[j])&&a[j]<=0) mia=a[j];
			if(abs(maa2)>abs(a[j])&&a[j]>0) maa2=a[j];
			if(abs(mia2)<abs(a[j])&&a[j]>=0) mia2=a[j];
		}
		for(int j=l2;j<=r2;j++)
		{
			if(b[j]>0) bp=1;
			else bn=1;
			if(abs(mab)>abs(b[j])&&b[j]<=0) mab=b[j];
			if(abs(mib)<abs(b[j])&&b[j]<=0) mib=b[j];
			if(abs(mab2)>abs(b[j])&&b[j]>0) mab2=b[j];
			if(abs(mib2)<abs(b[j])&&b[j]>=0) mib2=b[j];
		}
//		cout<<maa<<" "<<mia<<" "<<maa2<<" "<<mia2<<endl;
//		cout<<mab<<" "<<mib<<" "<<mab2<<" "<<mib2<<endl;
		if(ap&&!an&&bp&&!bn) cout<<mia2*mab2<<endl;
		else if(!ap&&an&&bp&&!bn) cout<<maa*mab2<<endl;
		else if(ap&&!an&&!bp&&bn) cout<<mia2*mab<<endl;
		else if(!ap&&an&&!bp&&bn) cout<<mia*mab<<endl;
		else if(ap&&an&&!bp&&bn) cout<<mia*mab<<endl;
		else if(ap&&!an&&bp&&bn) cout<<maa2*mib<<endl;
		else if(!ap&&an&&bp&&bn) cout<<maa*mib2<<endl;
		else if(ap&&an&&bp&&!bn) cout<<mia2*mab2<<endl;
		else cout<<maa2*mib<<endl;
	}
 	return 0;
}

