#include<bits/stdc++.h>
using namespace std;
long long n,m,k;
long a[100000],x[100000],y[100000],xy[10000][10000]={};
int fun(int s)
{
	int fi=s;
	for(int i=s;i-s<=k&&i<n;i++)
		if(a[i]>a[fi])
			fi=i;
    return fi;
}
int main()
{
	freopen("holiday.in","r",stdin);
	freopen("holiday.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<n;i++)
	   cin>>a[i];
	for(int i=1;i<=m;i++)
	{
		cin>>x[i]>>y[i];
		xy[i][i]=xy[i][i]=1;
	}
	if(k>=n)
	{
		int sum=0;
		sort(a,a+n);
		sum+=a[n-2]+a[n-3]+a[n-4]+a[n-5];
		cout<<sum;
		return 0;
	}
	return 0;
}
