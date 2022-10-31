#include<bits/stdc++.h>
#define ll long long
ll n,m,q,a[1000001],b[1000001];
using namespace std;
int main()
{
  freopen("game.in","r",stdin);
  freopen("game.out","w",stdout);
	cin>>n>>m>>q;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=1;i<=m;i++)cin>>b[i];
	for(int i=1;i<=q;i++)
	{
		ll l1=0,r1=0,l2=0,r2=0,q=0,l=0;
		cin>>l1>>r1>>l2>>r2;
		l=max(a[l1],a[r1]);
		q=min(b[l2],b[r2]);
		cout<<l*q;
	}
	return 0;
}

