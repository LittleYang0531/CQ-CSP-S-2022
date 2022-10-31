#include <bits/stdc++.h>
#define ll long long
using namespace std;
const ll Maxn=1e3+7,Maxm=1e5+7;
ll n,m,C[Maxn][Maxn],q;
ll A[Maxn],B[Maxn],ans;
ll tree[Maxn<<2][Maxn];
inline void buildtree(ll node,ll l,ll r,ll N){
	if(l==r){
		tree[node][N]=A[N]*B[l];
		return ;
	}
	ll mid=l+r>>1;
	buildtree(node<<1,l,mid,N);
	buildtree(node<<1|1,mid+1,r,N);
	tree[node][N]=min(tree[node<<1][N],tree[node<<1|1][N]);
}
inline ll query(ll node,ll l,ll r,ll L,ll R,ll N){
	if(l>=L&&r<=R) return tree[node][N];
	ll mid=l+r>>1,ans=INT_MAX;
	if(L<=mid) ans=min(ans,query(node<<1,l,mid,L,R,N));
	if(R>mid) ans=min(ans,query(node<<1|1,mid+1,r,L,R,N));
	return ans;
}
ll Max[Maxm<<2],Min[Maxm<<2];
inline void buildtreeOfMax(ll node,ll l,ll r){
	if(l==r){
		Max[node]=A[l];
		return ;
	}
	ll mid=l+r>>1;
	buildtreeOfMax(node<<1,l,mid);
	buildtreeOfMax(node<<1|1,mid+1,r);
	Max[node]=max(Max[node<<1],Max[node<<1|1]);
}
inline void buildtreeOfMin(ll node,ll l,ll r){
	if(l==r){
		Min[node]=B[l];
		return ;
	}
	ll mid=l+r>>1;
	buildtreeOfMin(node<<1,l,mid);
	buildtreeOfMin(node<<1|1,mid+1,r);
	Min[node]=min(Min[node<<1],Min[node<<1|1]);
}
inline ll queryMax(ll node,ll l,ll r,ll L,ll R){
	if(l>=L&&r<=R) return Max[node];
	ll mid=l+r>>1,ans=-1e9;
	if(L<=mid) ans=max(ans,queryMax(node<<1,l,mid,L,R));
	if(R>mid)  ans=max(ans,queryMax(node<<1|1,mid+1,r,L,R));
	return ans;
}
inline ll queryMin(ll node,ll l,ll r,ll L,ll R){
	if(l>=L&&r<=R) return Min[node];
	ll mid=l+r>>1,ans=1e9;
	if(L<=mid) ans=min(ans,queryMin(node<<1,l,mid,L,R));
	if(R>mid)  ans=min(ans,queryMin(node<<1|1,mid+1,r,L,R));
	return ans;
}
int main(){
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	scanf("%lld%lld%lld",&n,&m,&q);
	for(ll i=1;i<=n;i++) scanf("%lld",&A[i]);
	for(ll j=1;j<=m;j++) scanf("%lld",&B[j]);
	if(n<=1002&&m<=1002){
		for(ll i=1;i<=n;i++) buildtree(1,1,m,i);
		while(q--){
			ll l1,l2,r1,r2;ans=-INT_MAX;
			scanf("%lld%lld%lld%lld",&l1,&r1,&l2,&r2);
			for(ll i=l1;i<=r1;i++){
				ll sum=query(1,1,m,l2,r2,i);
				ans=max(ans,sum);
			}
			printf("%lld\n",ans);
		}	
	}
	else{
		buildtreeOfMax(1,1,n);
		buildtreeOfMin(1,1,m);
		while(q--){
			ll l1,l2,r1,r2;
			scanf("%lld%lld%lld%lld",&l1,&r1,&l2,&r2);
			ans=queryMax(1,1,n,l1,r1)*queryMin(1,1,m,l2,r2);
			printf("%lld\n",ans);
		}
	}
	return 0;
}
/*
3 2 2
0 1 -2
-3 4
1 3 1 2
2 3 2 2

6 4 5
3 -1 -2 1 2 0
1 2 -1 -3
1 6 1 4
1 5 1 4
1 4 1 2
2 6 3 4
2 5 2 3

5 6 1
1 2 3 4 5
7 9 2 5 4 7
2 3 1 3

4
*/
