#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll N=1e5+5,INF=1e10;
ll n,m,q;
ll a[N],b[N];
ll st1[N][20],st11[N][20],st2[N][20],st22[N][20],fg1[N][20],fg2[N][20],tt,t1;
ll stt1[N][20],stt11[N][20];
bool flag=false;
ll get1(ll l,ll r){
	ll k=log2(r-l+1);
	return max(st1[l][k],st1[r-(1<<k)+1][k]);
}
ll get11(ll l,ll r){
	ll k=log2(r-l+1);
	return min(st11[l][k],st11[r-(1<<k)+1][k]);
}
ll get2(ll l,ll r){
	ll k=log2(r-l+1);
	return min(st2[l][k],st2[r-(1<<k)+1][k]);
}
ll get22(ll l,ll r){
	ll k=log2(r-l+1);
	return max(st22[l][k],st22[r-(1<<k)+1][k]);
}
ll get_fg1(ll l,ll r){
	ll k=log2(r-l+1);
	return max(fg1[l][k],fg1[r-(1<<k)+1][k]);
}
ll get_fg2(ll l,ll r){
	ll k=log2(r-l+1);
	return max(fg2[l][k],fg2[r-(1<<k)+1][k]);
}
ll find_(ll l,ll r){
	ll k=log2(r-l+1);
//	cout<<"___ "<<l<<" "<<r<<" "<<max(stt1[l][k],stt1[r-(1<<k)+1][k])<<endl;
	return max(stt1[l][k],stt1[r-(1<<k)+1][k]);
}
ll find_1(ll l,ll r){
	ll k=log2(r-l+1);
//	cout<<"__1 "<<l<<" "<<r<<" "<<min(stt11[l][k],stt11[r-(1<<k)+1][k])<<endl;
	return min(stt11[l][k],stt11[r-(1<<k)+1][k]);
}
int main(){
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	scanf("%lld%lld%lld",&n,&m,&q),tt=log2(n),t1=log2(m);
//	cout<<tt<<endl;
	for(ll i=1;i<=n;++i){	
		scanf("%lld",&a[i]);
	}
	for(ll i=1;i<=m;++i){
		scanf("%lld",&b[i]);
	}
	
	for(ll i=1;i<=n;++i){
		st1[i][0]=st11[i][0]=a[i],fg1[i][0]=(!a[i]);
		if(a[i]<0) stt1[i][0]=a[i];
		else stt1[i][0]=-INF;
		if(a[i]>0) stt11[i][0]=a[i];
		else stt11[i][0]=INF;
	}
	for(ll i=1;i<=m;++i) st2[i][0]=st22[i][0]=b[i],fg2[i][0]=(!b[i]);
	for(ll j=1;j<=tt;++j)
		for(ll i=1;i<=n-(1<<j-1);++i)
			st1[i][j]=max(st1[i][j-1],st1[i+(1<<j-1)][j-1]),
			st11[i][j]=min(st11[i][j-1],st11[i+(1<<j-1)][j-1]),
			fg1[i][j]=max(fg1[i][j-1],fg1[i+(1<<j-1)][j-1]),
			stt1[i][j]=max(stt1[i][j-1],stt1[i+(1<<j-1)][j-1]),
			stt11[i][j]=min(stt11[i][j-1],stt11[i+(1<<j-1)][j-1]);
	for(ll j=1;j<=t1;++j)
		for(ll i=1;i<=m-(1<<j-1);++i)
			st2[i][j]=min(st2[i][j-1],st2[i+(1<<j-1)][j-1]),
			st22[i][j]=max(st22[i][j-1],st22[i+(1<<j-1)][j-1]),
			fg2[i][j]=max(fg2[i][j-1],fg2[i+(1<<j-1)][j-1]);
	
	ll l1,r1,l2,r2;
	while(q--){
		
		scanf("%lld%lld%lld%lld",&l1,&r1,&l2,&r2);
		if(l1==r1){
			if(a[l1]<0) printf("%lld\n",a[l1]*get22(l2,r2));
			else printf("%lld\n",a[l1]*get2(l2,r2));
			continue;
		}
		if(l2==r2){
			if(b[l2]<0) printf("%lld\n",b[l2]*get11(l1,r1));
			else printf("%lld\n",b[l2]*get1(l1,r1));
			continue;
		}
		if(get11(l1,r1)>0){
			if(get2(l2,r2)>0) printf("%lld\n",get1(l1,r1)*get2(l2,r2));
			else printf("%lld\n",get11(l1,r1)*get2(l2,r2));
			continue;
		}
		if(get1(l1,r1)<0){
			if(get22(l2,r2)<0) printf("%lld\n",get11(l1,r1)*get22(l2,r2));
			else printf("%lld\n",get1(l1,r1)*get22(l2,r2));
			continue;
		}
		if(get2(l2,r2)>0){
			printf("%lld\n",get1(l1,r1)*get2(l2,r2));
			continue;
		}
		if(get22(l2,r2)<0){
			printf("%lld\n",get11(l1,r1)*get22(l2,r2));
			continue;
		}
		if(get_fg1(l1,r1)||get_fg2(l2,r2)){
			printf("0\n");
			continue;
		}
//		cout<<11111111111<<endl;
		printf("%lld\n",max(get22(l2,r2)*find_(l1,r1),get2(l2,r2)*find_1(l1,r1)));
//		cout<<"----- "<<get22(l2,r2)<<" "<<get2(l2,r2)<<endl;
	}
	return 0;
}

