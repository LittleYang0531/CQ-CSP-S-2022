#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll M=500005;
ll n,m,q,f[M],a[M],b[M],h[M],cnt,maxn,minn;
bool vis[M];
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
		maxn=-9223372036854775807,minn=9223372036854775807;
		int l1,l2,r1,r2;
		cin>>l1>>r1>>l2>>r2;
		if(l1==r1)
		{
			for(int j=l2;j<=r2;j++)
			{
				if(minn>a[l1]*b[j])
				minn=a[l1]*b[j];
			}
			cout<<minn<<"\n";
			continue;
		}
		if(r2==l2)
		{
			for(int j=l1;j<=r1;j++)
			{
				if(maxn<a[j]*b[l2])
				maxn=a[j]*b[l2];
			}
			cout<<maxn<<"\n";
		}
	}
	return 0;
}
