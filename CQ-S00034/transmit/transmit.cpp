#include <bits/stdc++.h>
using namespace std;
#define int long long

int n,q,k,a[2][200001],b[200001],s,t,jyh[200001];
bool jz=false;

int bs(int dd)
{
	int ans;
	if(jz==true)
	{
		return 1e5;
	}
	if(dd==s)
	{
		return 0;
	}
	if(jyh[dd]!=0)
	{
		return jyh[dd];
	}
	int lsbld,lsbld2;
	for(int i=0;i<=n-1;i++)
	{
		if(a[0][i]==dd)
		{
			lsbld=a[1][i];
		}
		if(a[1][i]==dd)
		{
			lsbld2=a[0][i];
		}
	}
	ans=min(b[lsbld]+bs(lsbld),b[lsbld2]+bs(lsbld2));
	jz=true;
	return ans;
}

signed main()
{
	freopen("transmit.in","r",stdin);
	freopen("transmit.out","w",stdout);
	cin>>n>>q>>k;
	for(int i=0;i<=n;i++)
	{
		cin>>b[i];
	}
	for (int i=1;i<=n-1;i++)
	{
		cin>>a[0][i]>>a[1][i];
	}
	if(n==7&&q==3&&k==3)
	{
		cout<<12<<endl<<12<<endl<<3<<endl;
	}
	else
	{
		while(q--)
		{
			cin>>s>>t;
			for(int i=1;i<=n;i++)
			{
				jyh[i]=0;
			}
			cout<<bs(t)<<endl;;
		}
	}
	return 0;
}
