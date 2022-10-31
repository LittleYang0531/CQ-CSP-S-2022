#include<cstdio>
#include<queue>
#include<iostream>
#include<cstring>
#include<vector>
#include<algorithm>
#define N 100005
using namespace std;
typedef long long ll;
struct sgtree{
	ll l,r,maxn,minn;
	#define l(id,x) tree[id][x].l
	#define r(id,x) tree[id][x].r
	#define maxn(id,x) tree[id][x].maxn
	#define minn(id,x) tree[id][x].minn
}tree[3][4*N];
ll n,m,q,a[3][N];
void build(ll op,ll x,ll l,ll r){
	l(op,x)=l,r(op,x)=r,maxn(op,x)=-1e18,minn(op,x)=1e18;
	if(l==r){maxn(op,x)=minn(op,x)=a[op][l];return;}
	ll mid=(l+r)>>1;
	build(op,x<<1,l,mid); build(op,x<<1|1,mid+1,r);
	maxn(op,x)=max(maxn(op,x<<1),maxn(op,x<<1|1));
	minn(op,x)=min(minn(op,x<<1),minn(op,x<<1|1));
}
ll query(ll op,ll x,ll l,ll r,ll ask){
	if(l<=l(op,x)&&r>=r(op,x)){
		if(ask==1) return maxn(op,x);
		else return minn(op,x);
	} 
	ll mid=(l(op,x)+r(op,x))>>1;
	ll mx=-1e18,mn=1e18;
	if(l<=mid){
		if(ask==1) mx=max(mx,query(op,x<<1,l,r,ask));
		else mn=min(mn,query(op,x<<1,l,r,ask));
	}
	if(r>mid){
		if(ask==1) mx=max(mx,query(op,x<<1|1,l,r,ask));
		else mn=min(mn,query(op,x<<1|1,l,r,ask));
	}
	if(ask==1) return mx;
	else return mn;
}
int main(){
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	scanf("%lld%lld%lld",&n,&m,&q);
	for(int i=1;i<=n;i++) scanf("%lld",&a[1][i]);
	for(int i=1;i<=m;i++) scanf("%lld",&a[2][i]);
	build(1,1,1,n); build(2,1,1,m);
	while(q--){
		ll l1,r1,l2,r2; scanf("%lld%lld%lld%lld",&l1,&r1,&l2,&r2);
		if(l1==r1){
			if(a[1][l1]==0){
				puts("0"); continue;
			}else if(a[1][l1]>0){
				ll x=query(2,1,l2,r2,2);
				printf("%lld\n",a[1][l1]*x);
				continue;
			}
			ll x=query(2,1,l2,r2,1);
			printf("%lld\n",a[1][l1]*x);
			continue;
		}
		if(l2==r2){
			if(a[2][l2]==0){
				puts("0"); continue;
			}else if(a[2][l2]>0){
				ll x=query(1,1,l1,r1,1);
				printf("%lld\n",a[2][l2]*x);
				continue;
			}
			ll x=query(1,1,l1,r1,2);
			printf("%lld\n",a[2][l2]*x);
			continue;
		}
		ll x=query(1,1,l1,r1,1);
		ll y=query(2,1,l2,r2,2);
		printf("%lld\n",x*y);
	}
	return 0;
}
