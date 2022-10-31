#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll N=2e6+10,mod=1e9+7,INF=1e18;
ll n,m,q,A[N],B[N];
struct tree{
	ll M;
	ll maxn[N],mini[N];
	void push_up(ll rt){
		maxn[rt]=max(maxn[rt<<1],maxn[rt<<1|1]);
		mini[rt]=min(mini[rt<<1],mini[rt<<1|1]);
		return ;
	}
	void build(ll l,ll r,ll rt,ll* R){
		if(l==r){
			maxn[rt]=R[l];
			mini[rt]=R[l];
//			cout<<maxn[rt]<<' ';
			return;
		}
		
		ll mid=(l+r)>>1;
		build(l,mid,rt<<1,R);
		build(mid+1,r,rt<<1|1,R);
		push_up(rt);
		return;
	}
	ll get1(ll l,ll r,ll rt,ll L,ll R){
		ll res=INF;
		ll mid=(l+r)>>1;
		if(L<=l&&R>=r) return mini[rt];
		
		if(L<=mid) res=min(res,get1(l,mid,rt<<1,L,R));
		if(R>mid) res=min(res,get1(mid+1,r,rt<<1|1,L,R));
		return res;
	}
	ll get_min(ll l,ll r){
		return get1(1,M,1,l,r);
	}
	ll get2(ll l,ll r,ll rt,ll L,ll R){
		ll res=-INF;
		ll mid=(l+r)>>1;
		if(L<=l&&R>=r) return maxn[rt];
		if(L<=mid) res=max(res,get2(l,mid,rt<<1,L,R));
		if(R>mid) res=max(res,get2(mid+1,r,rt<<1|1,L,R));
		return res;
	}
	ll get_max(ll l,ll r){
		return get2(1,M,1,l,r);
	}
}a,b;
ll is_zero[N]={0};
int main(){
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	scanf("%d%d%d",&n,&m,&q);
	for(ll i=1;i<=n;i++){
		scanf("%lld",&A[i]);
		is_zero[i]=is_zero[i-1]+(A[i]==0);
	}
	for(ll i=1;i<=m;i++){
		scanf("%lld",&B[i]);
	}
	a.M=n;
	b.M=m;
	a.build(1,n,1,A);

	b.build(1,m,1,B);
//	return 0;
	//游戏策略
	//当L的区间有负数，而Q的区间只有负数时，L取最小负数，Q取最大负数
	//当L的区间无负数，而Q的区间只有负数时，L取最小数，Q取最大负数
	//当L的区间，而Q的区间只有正数时，L取最大数，Q取最小数
	//当L的区间，而Q的区间有正有负时，L有0取0，没0取两个最接近0的数进行比较，Q取最小数
	
//	cout<<a.get_max(2,3)<<endl;
	while(q--){
		ll l1,l2,r1,r2;
		scanf("%lld%lld%lld%lld",&l1,&r1,&l2,&r2);
		ll maxn=-INF;
		ll mi1=a.get_min(l1,r1),mi2=b.get_min(l2,r2),mx1=a.get_max(l1,r1),mx2=b.get_max(l2,r2);
		if(mx2<0){
			if(mi1>0){
				printf("%lld\n",mi1*mi2);
			} 
			else{
				printf("%lld\n",mi1*mx2);
			}
		}
		else if(mi2>0){
			if(mi1>0){
				printf("%lld\n",mx1*mi2);
			}
			else if(mx1<0){
				printf("%lld\n",mx1*mi2);
			}
			else{
				ll res=-INF;
				for(int i=l1;i<=r1;i++){
					ll tmp=INF;
					for(int j=l2;j<=r2;j++){
						tmp=min(tmp,A[i]*B[j]);
					}
					res=max(res,tmp);
				}
//				cout<<"E\n";
				printf("%lld\n",res);
			}
		}
		else{
			if(is_zero[r1]-is_zero[l1-1]>0){
				
				printf("0\n");
			}
			else{
				ll res=-INF;
				for(int i=l1;i<=r1;i++){
					ll tmp=INF;
					for(int j=l2;j<=r2;j++){
						tmp=min(tmp,A[i]*B[j]);
					}
					res=max(res,tmp);
				}
				printf("%lld\n",res);
			}
		}
	}
	
}
