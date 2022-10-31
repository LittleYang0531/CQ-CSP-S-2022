#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll INF=1e9*1e9;
const ll maxn=1e5+10;
ll n,m,q,ans;
ll a[maxn],b[maxn];
ll tr1[maxn<<4],tr2[maxn<<4];
void add_a(ll l,ll r,ll rt,ll x,ll val){
	if(l==r){
		tr1[rt]=val;
		return ;
	}
	ll mid=(l+r)/2;
	if(x<=mid)add_a(l,mid,rt*2,x,val);
	else add_a(mid+1,r,rt*2+1,x,val);
	tr1[rt]=max(tr1[rt*2],tr1[rt*2+1]);
}
void add_b(ll l,ll r,ll rt,ll x,ll val){
	if(l==r){
		tr2[rt]=val;
		return ;
	}
	ll mid=(l+r)/2;
	if(x<=mid)add_b(l,mid,rt*2,x,val);
	else add_b(mid+1,r,rt*2+1,x,val);
	tr2[rt]=min(tr2[rt*2],tr2[rt*2+1]);
}
ll querya(ll l,ll r,ll rt,ll L,ll R){
	if(L<=l&&r<=R){
		return tr1[rt];
	}
	ll flag=-1;
	ll mid=(l+r)/2;
	if(L<=mid)flag=max(flag,querya(l,mid,rt*2,L,R));
	if(R>mid)flag=max(flag,querya(mid+1,r,rt*2+1,L,R));
	return flag;
}
ll queryb(ll l,ll r,ll rt,ll L,ll R){
	if(L<=l&&r<=R){
		return tr2[rt];
	}
	ll flag=INF+1;
	ll mid=(l+r)/2;
	if(L<=mid)flag=min(flag,queryb(l,mid,rt*2,L,R));
	if(R>mid)flag=min(flag,queryb(mid+1,r,rt*2+1,L,R));
	return flag;
}
void solve1(){
	for(int i=1;i<=8*m;i++)tr2[i]=INF;
	for(ll i=1;i<=n;i++)add_a(1,n,1,i,a[i]);
	for(ll i=1;i<=m;i++)add_b(1,m,1,i,b[i]);
	for(ll i=1;i<=q;i++){
		ll l1,r1,l2,r2;
		ans=0;
		scanf("%lld%lld%lld%lld",&l1,&r1,&l2,&r2);
		ans=ans+querya(1,n,1,l1,r1)*queryb(1,m,1,l2,r2);
		printf("%lld\n",ans);
	}
}
void solve2(){
	for(ll i=1;i<=q;i++){
		ans=0;
		ll l1,r1,l2,r2;
		scanf("%lld%lld%lld%lld",&l1,&r1,&l2,&r2);
		if(l1==r1){
			if(a[l1]>0){
				ll mn=INF;
				for(ll j=l2;j<=r2;j++)mn=min(mn,b[j]);
				ans=ans+a[l1]*mn;
			}
			if(a[l1]<0){
				ll mx=-INF;
				for(ll j=l2;j<=r2;j++)mx=max(mx,b[j]);
				ans=ans+a[l1]*mx;
			}
		}
		else{
			if(l2==r2){
				if(a[l2]>0){
					ll mx=-INF;
					for(ll j=l1;j<=r1;j++)mx=max(mx,a[j]);
					ans=ans+b[l2]*mx;
				}
				if(a[l2]<0){
					ll mn=INF;
					for(ll j=l1;j<=r1;j++)mn=max(mn,a[j]);
					ans=ans+b[l2]*mn;
				}
			}
			else{
				ll mx=-INF;
				for(int j=l1;j<=r1;j++){
					ll mn=INF;
					for(int k=l2;k<=r2;k++){
						mn=min(mn,a[j]*b[k]);
					}
					mx=max(mx,mn);
				}
				ans+=mx;
			}
		}
		printf("%lld\n",ans);
	}
}
int main(){
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	scanf("%lld%lld%lld",&n,&m,&q);
	for(ll i=1;i<=n;i++)scanf("%lld",&a[i]);
	for(ll i=1;i<=m;i++)scanf("%lld",&b[i]);
	ll flag=0;
	for(ll i=1;i<=n;i++)if(a[i]>0)flag++;
	for(ll i=1;i<=m;i++)if(b[i]>0)flag++;
	if(flag==n+m)solve1();
	else solve2();
	return 0;
}

