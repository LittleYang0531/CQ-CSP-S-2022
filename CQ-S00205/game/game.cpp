#include <bits/stdc++.h>
#define inf 4000000000000000000ll
#define ll long long
using namespace std;
int n,m,Q,l1,r1,l2,r2,M,RR,L,R;
ll a[1010],b[1010],c[1010][1010],fw[1010][40];
signed main(){
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	cin>>n>>m>>Q;
	for(int i=1;i<=n;i++)scanf("%lld",&a[i]);
	for(int i=1;i<=m;i++)scanf("%lld",&b[i]);
	for(int i=1;i<=n;i++)for(int j=1;j<=m;j++)c[i][j]=a[i]*b[j];
	M=m/30;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=M;j++){
			RR=j*30-30;ll mn=inf;
			for(int k=1;k<=30;k++){
				mn=min(mn,c[i][RR+k]);
			}
			fw[i][j]=mn;
		}
		for(int j=M*30+1;j<=m;j++) fw[i][M+1]=min(fw[i][M+1],c[i][j]);
	}
	for(;Q;Q--){
		scanf("%d%d%d%d",&l1,&r1,&l2,&r2);
		ll ans=-inf;
		L=l2/30+1,R=r2/30;
		if(L*30!=l2)L++;
		if(L>R){
			for(int i=l1;i<=r1;i++){
				ll mn=inf;
				for(int j=l2;j<=r2;j++) mn=min(mn,c[i][j]);
				ans=max(ans,mn);
			}
			printf("%lld\n",ans);
			continue;
		}
		for(int i=l1;i<=r1;i++){
			ll mn=inf;
			for(int j=l2;j<=L*30-30;j++)mn=min(mn,c[i][j]);
			for(int j=R*30+1;j<=r2;j++) mn=min(mn,c[i][j]);
			for(int j=L;j<=R;j++)mn=min(mn,fw[i][j]);
			ans=max(ans,mn);
		}
		printf("%lld\n",ans);
	}
	return 0;
}
