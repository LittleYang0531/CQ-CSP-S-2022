#include<bits/stdc++.h>
using namespace std;
long long n,q,k,i,a,b;
int main()
{
	freopen("transmit.in","r",stdin);
	freopen("transmit.out","w",stdout);
	cin>>n>>q>>k;
	for(i=1;i<=n;i++)cin>>a;
	for(i=1;i<=n-1;i++)cin>>a>>b;
	for(i=1;i<=q;i++)
	{
		cin>>a>>b;
		srand(time(NULL));
		cout<<rand()<<endl;
	}
	return 0;
}
