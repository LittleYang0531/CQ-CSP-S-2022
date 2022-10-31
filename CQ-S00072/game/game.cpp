#include<bits/stdc++.h>
#define MAXN (long long)1e18
using namespace std;
long long n,m,q;
long long a[100005],b[100005];
bool flag=0;
long long l1,r1,l2,r2;
int main()
{
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	cin>>n>>m>>q;
	for(int i=1;i<=n;++i){
		scanf("%lld",&a[i]);
		if(a[i]<0){
			flag=1;
		}
	}
	for(int i=1;i<=m;++i){
		scanf("%lld",&b[i]);
		if(b[i]<0){
			flag=1;
		}
	}
	if(flag==0){
		while(q--){
			scanf("%lld%lld%lld%lld",&l1,&r1,&l2,&r2);
			long long maxa=0,minb=MAXN;
			for(int i=l1;i<=r1;++i){
				maxa=max(maxa,a[i]);
			}
			for(int i=l2;i<=r2;++i){
				minb=min(minb,b[i]);
			}
			printf("%lld\n",maxa*minb);
		}
		return 0;
	}
	while(q--){
		scanf("%lld%lld%lld%lld",&l1,&r1,&l2,&r2);
		long long ans=-MAXN;
		for(int i=l1;i<=r1;++i){
			long long minn=MAXN;
			for(int j=l2;j<=r2;++j){
				minn=min(minn,a[i]*b[j]);
			}
			ans=max(minn,ans);
		}
		printf("%lld\n",ans);
	}
	return 0;
}
