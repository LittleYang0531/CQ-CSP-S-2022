#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxx=1e5+5;
const ll inf=1e9;
int n,m,q;
bool flag;
ll a[maxx],b[maxx];
int main(){
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	scanf("%d%d%d",&n,&m,&q);
	for(int i=1;i<=n;++i){
		scanf("%lld",&a[i]);
		if(a[i]<=0)flag=1;
	}
	for(int i=1;i<=m;++i){
		scanf("%lld",&b[i]);
		if(b[i]<=0)flag=1;
	}
	if(!flag){
		for(int kk=1;kk<=q;++kk){
			int l1,r1,l2,r2;
			scanf("%d%d%d%d",&l1,&r1,&l2,&r2);
			ll maxn=-1;
			for(int i=l1;i<=r1;++i)maxn=max(maxn,a[i]);
			ll minn=inf;
			for(int i=l2;i<=r2;++i)minn=min(minn,b[i]);
			printf("%lld\n",maxn*minn);
		}
	}
	else{
		for(int kk=1;kk<=q;++kk){
			int l1,r1,l2,r2;
			scanf("%d%d%d%d",&l1,&r1,&l2,&r2);
			ll ans=-inf;
			if(l1==r1&&a[l1]==0)puts("0");
			else if(l2==r2&&b[l2]==0)puts("0");
			else{
				for(int i=l1;i<=r1;++i){
					ll sum=inf;
					for(int j=l2;j<=r2;++j){
						sum=min(a[i]*b[j],sum);
					}
					ans=max(ans,sum);
				}
				printf("%lld\n",ans);
			}
		}
	}
}
