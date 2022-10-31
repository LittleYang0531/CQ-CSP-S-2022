#include<bits/stdc++.h>
using namespace std;
int n,m,q,a[100005],b[100005];
int main(){
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	scanf("%d%d%d",&n,&m,&q);
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	for(int i=1;i<=m;i++)scanf("%d",&b[i]);
	while(q--){
		int l1,r1,l2,r2;
		scanf("%d%d%d%d",&l1,&r1,&l2,&r2);
		long long ans=-1e18-1;
		for(int i=l1;i<=r1;i++){
			long long minn=1e18+1;
			for(int j=l2;j<=r2;j++){
				minn=min(minn,1ll*a[i]*b[j]);
			}
			ans=max(ans,minn);
		}
		printf("%lld\n",ans);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
