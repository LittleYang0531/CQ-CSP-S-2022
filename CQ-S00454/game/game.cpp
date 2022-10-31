#include<bits/stdc++.h>
using namespace std;
long long n,m,k,l,a[1000001],b[1000001],l1,l3,l2,l4,aa,bb,s1,s2;
int main(){
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=1;i<=m;i++)cin>>b[i];
	for(int i=1;i<=k;i++){
		aa=-1000000000ll;
		bb=1000000000ll;
		s2=-1000000000000000000ll;
		cin>>l1>>l2>>l3>>l4;
		for(int j=l3;j<=l4;j++){
			aa=max(b[j],aa);
			bb=min(b[j],bb);
		}
		for(int j=l1;j<=l2;j++){
			if(a[j]>=0)s1=a[j]*bb;
			else s1=a[j]*aa;
			s2=max(s1,s2);
		}
		cout<<s2<<endl;
	}
}
