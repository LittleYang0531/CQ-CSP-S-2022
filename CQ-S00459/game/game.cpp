#include<bits/stdc++.h>
#define ll long long
const ll N=1e5+10;
const ll inf=0x3f3f3f3f3f3f3f3f;
using namespace std;

ll n,m,q,a[N],b[N];
ll maxa[2*N][20],mina[2*N][20];
ll maxb[2*N][20],minb[2*N][20];
ll spmax[2*N][20],spmin[2*N][20];

void init(){
	for(ll i=n;i;--i)maxa[i][0]=mina[i][0]=a[i];
	for(ll i=m;i;--i)maxb[i][0]=minb[i][0]=b[i];
	for(ll i=n;i;--i){
		for(ll j=1;j<=17;++j){
			maxa[i][j]=max(maxa[i][j-1],maxa[i+(1<<(j-1))][j-1]);
			mina[i][j]=min(mina[i][j-1],mina[i+(1<<(j-1))][j-1]);
		}
	}
	for(ll i=m;i;--i){
		for(ll j=1;j<=17;++j){
			maxb[i][j]=max(maxb[i][j-1],maxb[i+(1<<(j-1))][j-1]);
			minb[i][j]=min(minb[i][j-1],minb[i+(1<<(j-1))][j-1]);
		}
	}
	
	for(ll i=n;i;--i){
		if(a[i]<=0)spmax[i][0]=a[i];
		else spmax[i][0]=-inf;
		if(a[i]>=0)spmin[i][0]=a[i];
		else spmin[i][0]=inf;
	}
	for(ll i=n;i;--i){
		for(ll j=1;j<=17;++j){
			spmax[i][j]=max(spmax[i][j-1],spmax[i+(1<<(j-1))][j-1]);
			spmin[i][j]=min(spmin[i][j-1],spmin[i+(1<<(j-1))][j-1]);
		}
	}
}

ll getmaxa(ll x,ll y){
	++y;
	ll ans=-inf;
	for(ll i=17;i>=0;--i){
		if(x+(1<<i)<=y){
			ans=max(ans,maxa[x][i]);
			x+=(1<<i);
		}
	}
	return ans;
}

ll getmina(ll x,ll y){
	++y;
	ll ans=inf;
	for(ll i=17;i>=0;--i){
		if(x+(1<<i)<=y){
			ans=min(ans,mina[x][i]);
			x+=(1<<i);
		}
	}
	return ans;
}

ll getmaxb(ll x,ll y){
	++y;
	ll ans=-inf;
	for(ll i=17;i>=0;--i){
		if(x+(1<<i)<=y){
			ans=max(ans,maxb[x][i]);
			x+=(1<<i);
		}
	}
	return ans;
}

ll getminb(ll x,ll y){
	++y;
	ll ans=inf;
	for(ll i=17;i>=0;--i){
		if(x+(1<<i)<=y){
			ans=min(ans,minb[x][i]);
			x+=(1<<i);
		}
	}
	return ans;
}

ll getspmax(ll x,ll y){
	++y;
	ll ans=-inf;
	for(ll i=17;i>=0;--i){
		if(x+(1<<i)<=y){
			ans=max(ans,spmax[x][i]);
			x+=(1<<i);
		}
	}
	return ans;
}

ll getspmin(ll x,ll y){
	++y;
	ll ans=inf;
	for(ll i=17;i>=0;--i){
		if(x+(1<<i)<=y){
			ans=min(ans,spmin[x][i]);
			x+=(1<<i);
		}
	}
	return ans;
}

int main(){
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	
	scanf("%lld%lld%lld",&n,&m,&q);
	for(ll i=1;i<=n;++i){
		scanf("%lld",&a[i]);
	}
	for(ll i=1;i<=m;++i){
		scanf("%lld",&b[i]);
	}
	init();
	while(q--){
		ll l1,r1,l2,r2;
		scanf("%lld%lld%lld%lld",&l1,&r1,&l2,&r2);
		ll _maxa=getmaxa(l1,r1);
		ll _mina=getmina(l1,r1);
		ll _maxb=getmaxb(l2,r2);
		ll _minb=getminb(l2,r2);
		ll _spmax=getspmax(l1,r1);
		ll _spmin=getspmin(l1,r1);
		ll ans=0;
		if(_minb>=0){
			if(_maxa>0)ans=_maxa*_minb;
			else ans=_maxa*_maxb;
		}else if(_maxb<=0){
			if(_mina<0)ans=_mina*_maxb;
			else ans=_mina*_minb;
		}else{
			if(_mina>=0)ans=_mina*_minb;
			else if(_maxa<=0)ans=_maxa*_maxb;
			else ans=max(_spmin*_minb,_spmax*_maxb);
		}
		printf("%lld\n",ans);
	}
	
	return 0;
}
