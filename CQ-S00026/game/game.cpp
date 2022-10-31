#include<bits/stdc++.h>
using namespace std;
long long A[100005],B[100005],n,m,q;
long long mp[10005][10005];
int main(){
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	scanf("%lld%lld%lld",&n,&m,&q);
	for(int i=1;i<=n;i++){   
		scanf("%lld",&A[i]); 
	}
	for(int i=1;i<=m;i++){
		scanf("%lld",&B[i]);
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			mp[i][j]=A[i]*B[j];
		}
	}
	for(int i=1;i<=q;i++){
		long long l1,r1,l2,r2;
		scanf("%lld%lld%lld%lld",&l1,&r1,&l2,&r2);
		long long min_max=mp[l1][l2],mn[100005],iai=l1;
		for(int l=l1;l<=r1;l++){
			mn[l]=mp[l][l2];
			for(int l_=l2;l_<=r2;l_++){
				if(mn[l]>=mp[l][l_]){
					mn[l]=mp[l][l_];
				}
			}
		}
		for(int l=l1;l<=r1;l++){
			if(min_max<=mn[l]){
				min_max=mn[l];
				iai=l;
			}
		}
		long long max_min=mp[l1][l2],mx[100005],aii=l2;
		for(int l=l2;l<=r2;l++){
			mx[l]=mp[l1][l];
			for(int l_=l1;l_<=r1;l_++){
				if(mx[l]<=mp[l_][l]){
					mx[l]=mp[l_][l];
				}
			}
		}
		for(int l=l2;l<=r2;l++){
			if(max_min>=mx[l]){
				max_min=mx[l];
				aii=l;
			}
		}
		printf("%lld\n",mp[iai][aii]);
	}
	return 0;
}
