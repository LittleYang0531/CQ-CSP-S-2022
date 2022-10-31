#include<bits/stdc++.h>
using namespace std;
long long n,q,k,a[200005];
int main(){
	freopen("transmit.in","r",stdin);
	freopen("transmit.out","w",stdout);
	scanf("%lld %lld %lld",&n,&q,&k);
	for(int i=1;i<=n;i++)scanf("%lld",&a[i]);
	for(int i=1;i<n;i++){
		int u,v;
		scanf("%d %d",&u,&v);
	}
	while(q--){
		int x,y;
		scanf("%d %d",&x,&y);
		printf("%d\n",a[x]+a[y]);
	}
	return 0;
}
