#include<bits/stdc++.h>
using namespace std;
int n,m,k,a[2502],b[2502],x,y,ans=0;
long long s[2502];
int main()
{
	freopen("holiday.in","r",stdin);
	freopen("holiday.out","w",stdout);	
	cin>>n>>m>>k;
	for(int i=2;i<=n;i++) cin>>s[i];
	for(int i=1;i<=m;i++)
	{
		cin>>x>>y;
		a[x]++;
		b[y]++;
	}
	sort(s+1,s+n+1);
	for(int i=2;i<=n;i++)
	{
		swap(s[i],s[i+1]);
	}
	for(int i=1;i<=5;i++)
	{
		ans+=s[i];
	}
	cout<<ans;
	return 0;
}
