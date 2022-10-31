#include<iostream>
#include<algorithm>
#include<cstdio>
#define lll long long
using namespace std;
int lft1,lft2,rgh1,rgh2;
int n,m,q;
lll a[100005],b[100005];
int main(){
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	scanf("%d%d%d",&n,&m,&q);
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
	}
	for(int i=1;i<=m;i++){
		scanf("%lld",&b[i]);
	}
	lll ans,maxx,minn;
	for(int i=1;i<=q;i++){
		scanf("%d%d%d%d",&lft1,&rgh1,&lft2,&rgh2);
		if(lft1==rgh1){
			ans=a[lft1]*b[lft2];
			for(int i=lft2+1;i<=rgh2;i++){
				ans=min(ans,a[lft1]*b[i]);
			}
		}else if(lft2==rgh2){
			ans=a[lft1]*b[lft2];
			for(int i=lft1+1;i<=rgh1;i++){
				ans=max(ans,a[i]*b[lft2]);
			}
		}else{
			maxx=a[lft1];
			for(int i=lft1+1;i<=rgh1;i++){
				maxx=max(maxx,a[i]);
			}
			minn=b[lft2];
			for(int i=lft2+1;i<=rgh2;i++){
				minn=min(minn,b[i]);
			}
			ans=maxx*minn;
		}
		printf("%lld\n",ans);
	}

	return 0;
}

