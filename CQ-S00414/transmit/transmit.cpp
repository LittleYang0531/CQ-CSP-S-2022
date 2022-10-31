#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen("transmit.in","r",stdin);
	freopen("transmit.out","w",stdout);
	long long n,q,k;
	long long v[20002],a[20002],b[20002],s[20002],t[20002];
	cin>>n>>q>>k;
	for(int i=1;i<=n;i++)
	{
		cin>>v[i];
	}
	for(int i=1;i<n;i++)
	{
		cin>>a[i]>>b[i];
	}
	for(int i=1;i<=q;i++)
	{
		cin>>s[i]>>t[i];
	}
	//////////////读取数据完成
	

	fclose(stdin);
	fclose(stdout);
	return 0;
 } 
