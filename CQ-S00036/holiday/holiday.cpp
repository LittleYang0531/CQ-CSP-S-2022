#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,a[100001],m,k,num;
signed main(){
	freopen("holiday.in","r",stdin);
	freopen("holiday.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<n;i++)cin>>a[i];
	sort(a+1,a+n);
	num+=a[n-1]+a[n-2]+a[n-3]+a[n-4];
	cout<<num;
	return 0;
}
