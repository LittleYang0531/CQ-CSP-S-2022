#include<bits/stdc++.h>
using namespace std;
long long n,m,q;
long long a[1005],b[1005];
long long c[1005][1005];
long long l1,r1,l2,r2;
long long minx,minmax;
int main(){
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	scanf("%lld%lld%lld",&n,&m,&q);
	for(long long i=1;i<=n;i++) scanf("%lld",&a[i]);
	for(long long i=1;i<=m;i++) scanf("%lld",&b[i]);
	for(long long i=1;i<=n;i++)
		for(long long j=1;j<=m;j++){
			if(a[i]>=0 && b[j]>=0) c[i][j]=a[i]*b[j];
			else if(a[i]>=0 && b[j]<0) c[i][j]=(-1)*a[i]*abs(b[j]);
			else if(a[i]<0 && b[j]>=0) c[i][j]=(-1)*abs(a[i])*b[j];
			else c[i][j]=abs(a[i])*abs(b[j]);
		}
			
	while(q--){
		scanf("%lld%lld%lld%lld",&l1,&r1,&l2,&r2);
//		minmax=c[l1][l2];
		for(long long i=l1;i<=r1;i++){
			minx=c[i][l2];
			for(long long j=l2;j<=r2;j++){
				minx=min(minx,c[i][j]);
			}
			if(i==l1) minmax=minx;
			else minmax=max(minmax,minx);
		}
		printf("%lld\n",minmax);
	}
	return 0;
}


