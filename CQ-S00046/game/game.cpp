#include<iostream>
using namespace std;
int n,m,k;
long long a[100005],b[100005];
long long s,x;
long long ans;
int L1,R1,L2,R2;
int main(){
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1;i<=n;i++)
		scanf("%lld",&a[i]);
	for(int i=1;i<=m;i++)
		scanf("%lld",&b[i]);
	for(int i=1;i<=k;i++){
		scanf("%d%d%d%d",&L1,&R1,&L2,&R2);
		s=1e12;
		x=-s;
		ans=x;
		for(int j=L2;j<=R2;j++){
			s=min(s,b[j]);
			x=max(x,b[j]);
		}
		for(int j=L1;j<=R1;j++){
			long long as;
			if(a[j]<0)as=a[j]*x;
			else as=a[j]*s;
			ans=max(ans,as);
		}
		printf("%lld\n",ans);
	}
	return 0;
}

