#include<iostream>
#include<algorithm>
#include<queue>
using namespace std;
long long n,m,q,cmp,a[100005],b[100005],l1,r1,l2,r2,ans,bmin=1e18,bmax=-1e18;
//int find(int l,int r,int a){
//	int mid;
//	while(l<r){
//		mid=(l+r)/2;
//		if()l=mid+1;
//		else r=mid;
//		
//	}
//	return l;
//}
int main(){
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	scanf("%lld%lld%lld",&n,&m,&q); 
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
	}
	for(int i=1;i<=m;i++){
		scanf("%lld",&b[i]);
	}
	while(q--){
		bmin=1e9;
		bmax=-1e9;
		ans=-1e9;
		scanf("%lld%lld%lld%lld",&l1,&r1,&l2,&r2); 
		for(int i=l2;i<=r2;i++){
			bmin=min(bmin,b[i]);
			bmax=max(bmax,b[i]);
		}
		for(int i=l1;i<=r1;i++){
			ans=max(ans,min(a[i]*bmin,a[i]*bmax));
//			cout<<min(a[i]*bmin,a[i]*bmax)<<" ";
		}
		printf("%lld\n",ans);
	} 
	return 0; 
} 
/*
3 2 2
0 1 -2
-3 4
1 3 1 2
2 3 2 2

*/
