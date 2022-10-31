#include<bits/stdc++.h>
#define ll long long
#define maxn 100005
#define inf 0x7f7f7f7f
using namespace std;
int n,m,q,a[maxn],b[maxn],l1,l2,r1,r2;
int l[maxn],r[maxn],lll[maxn],h,hh,dcc,dzb;
int main(){
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	scanf("%lld%lld%lld",&n,&m,&q);
	for(int i=1;i<=n;++i)scanf("%lld",&a[i]);
	for(int i=1;i<=m;++i)scanf("%lld",&b[i]);
	for(int i=1;i<=n;++i)l[i]=l[i-1]+(a[i]>=0);
	for(int i=1;i<=m;++i)r[i]=r[i-1]+(b[i]>=0);
	for(int i=1;i<=n;++i)lll[i]=lll[i-1]+(a[i]==0);
	while(q--){
		scanf("%lld%lld%lld%lld",&l1,&r1,&l2,&r2);
		h=a[r1]-a[l1-1];
		hh=b[r2]-b[r2-1];
		if(hh!=r2-l2+1&&lll[r1]-lll[l1-1]>0){
			printf("0");
			continue;
		}
		else{dzb=inf;
			for(int i=l1;i<=r1;++i)dcc=max(dcc,a[i]);
			for(int i=l2;i<=r2;++i)dzb=min(dzb,a[i]);
			printf("%lld\n",dcc*dzb);
		}
	}
	return 0;
}
