#include<bits/stdc++.h>
using namespace std;
long long n,q,k,v[100000],s1,t1,a1,b1,sum=0;
int main()
{
	freopen("transmit.in","r",stdin);
	freopen("transmit.out","w",stdout);
    cin>>n>>q>>k;
    for(int i=0;i<n;i++)
        cin>>v[i];
    for(int i=0;i<n-1;i++)
        cout<<a1<<b1;
    for(int i=0;i<q;i++)
    {
    	cin>>s1>>t1;
    	sum=0;
    	for(int j=s1;j<=t1;j++)
    	    sum+=v[j];
    	cout<<sum<<endl;
	}
    return 0;
}
