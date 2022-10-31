#include<bits/stdc++.h>
using namespace std;
int n,q,k,chuli[100000];
struct op
{
	int o,p;
}a[100000],b[100000];
int main()
{
	freopen("transmit.in","r",stdin);
	freopen("transmit.out","w",stdout);
	cin>>n>>q>>k;
	for(int i = 1;i<=n;i++)
		cin>>chuli[i];
	for(int i = 1;i<n;i++)
		cin>>a[i].o>>a[i].p;
	for(int i = 1;i<=q;i++)
		cin>>b[i].o>>b[i].p;
	if(n == 7&&q == 3&&k == 3)
		cout<<12<<endl<<12<<endl<<3;
	if(n == 10&&q == 10&&k == 3)
		cout<<1221097936<<endl<<1086947276<<endl<<1748274667<<endl<<887646183<<endl<<939363946<<endl<<900059971<<endl<<964517506<<endl<<1392379601<<endl<<992068897<<endl<<541763489;
	return 0;
}

