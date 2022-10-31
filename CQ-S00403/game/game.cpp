#include<bits/stdc++.h>
//Ô¤¼Æ£º 75·Ö 
#define ll long long
using namespace std;
const ll N=1e5+2,INF=1e18,T=32;
ll n,m,q,a[N],b[N],l1,l2,r1,r2,t;
bool f1,f2;
ll fx[N][T],fn[N][T];
void pre(){
	for(ll i=1;i<=n;i++){
		fx[i][0]=a[i];
	}
	for(ll i=1;i<=m;i++){
		fn[i][0]=b[i];
	}
	for(ll j=1;j<=t;j++){
		for(ll i=1;i+(1<<j)-1<=n;i++){
			fx[i][j]=max(fx[i][j-1],fx[i+(1<<(j-1))][j-1]);
		//	cout<<i<<" "<<j<<" "<<fx[i][j]<<'\n';
		}
	}
	for(ll j=1;j<=t;j++){
		for(ll i=1;i+(1<<j)-1<=m;i++){
			fn[i][j]=min(fn[i][j-1],fn[i+(1<<(j-1))][j-1]);
		//	cout<<i<<" "<<j<<" "<<fn[i][j]<<'\n';
		}
	}
}
ll st1(ll l,ll r){
	ll k=log(r-l+1)/log(2);
	return max(fx[l][k],fx[r-(1<<(k))+1][k]);
}
ll st2(ll l,ll r){
	ll k=log(r-l+1)/log(2);
	return min(fn[l][k],fn[r-(1<<(k))+1][k]);
}
ll C(ll x,ll y){
	return a[x]*b[y];
}
int main(){
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	scanf("%lld%lld%lld",&n,&m,&q);
	t=log(max(n,m))/log(2)+1;
	for(ll i=1;i<=n;i++){
		scanf("%lld",&a[i]);
		if(a[i]<=0) f1=1;
	}
	for(ll i=1;i<=m;i++){
		scanf("%lld",&b[i]);
		if(b[i]<=0) f2=1;
	}
	pre();
	if(!f1&&!f2){
	//	cout<<"in.\n";
		for(ll i=1;i<=q;i++){
		scanf("%lld%lld%lld%lld",&l1,&r1,&l2,&r2);
			if(l1==r1){
				printf("%lld\n",a[l1]*st2(l2,r2));
				continue;
			}else if(l2==r2){
				printf("%lld\n",b[l2]*st1(l1,r1));
				continue;
			}
			ll A=st1(l1,r1);
			ll B=st2(l2,r2);
		//	cout<<A<<" "<<B<<"\n";
			printf("%lld\n",A*B);
		}
	}
	for(ll i=1;i<=q;i++){
		scanf("%lld%lld%lld%lld",&l1,&r1,&l2,&r2);
		if(l1==r1){
		//	cout<<a[l1]<<" "<<st2(l2,r2)<<'\n';
			printf("%lld\n",a[l1]*st2(l2,r2));
			continue;
		}else if(l2==r2){
			printf("%lld\n",b[l2]*st1(l1,r1));
			continue;
		}
		ll mx=-INF;
		for(ll i=l1;i<=r1;i++){
			ll mn=INF;
			for(ll j=l2;j<=r2;j++){
	//			printf("(%d,%d)=%d\n",i,j,C(i,j));
				mn=min(mn,C(i,j));
			}
			mx=max(mn,mx);
		}
		printf("%lld\n",mx);
	}
	return 0;
}
/*
5 6 3
1 2 3 4 5
1 1 4 5 1 4
1 5 2 6
3 3 1 6
1 5 3 3
*/
/*
7 8 3
1 5 8 2 6 -5 -6
1 9 -9 2 3 -2 8 6
2 5 3 7
*/
/*
3 2 2
0 1 -2
-3 4
1 3 1 2
2 3 2 2
*/
/*
6 4 5
3 -1 -2 1 2 0
1 2 -1 -3
1 6 1 4
1 5 1 4
1 4 1 2
2 6 3 4
2 5 2 3
*/
