#include<bits/stdc++.h>
#define ll long long
const ll N=2550;
using namespace std;

ll n,m,k,a[N];
vector<ll>e1[N],e[N];
ll vis[N];
ll tmp1[N],tmp2[N],tmp3[N];

void bfs(ll sx){
	for(ll i=1;i<=n;++i)vis[i]=0;
	queue<ll>qx,qt;
	qx.push(sx);
	qt.push(-1);
	vis[sx]=1;
	while(!qx.empty()){
		ll x=qx.front(),t=qt.front();
		qx.pop(),qt.pop();
		if(t==k)continue;
		for(ll y:e1[x]){
			if(vis[y])continue;
			vis[y]=1;
			qx.push(y);
			qt.push(t+1);
		}
	}
	for(ll i=1;i<=n;++i){
		if(vis[i]&&i!=sx){
			e[sx].push_back(i);
		}
	}
}

void get(ll x,ll y){
	ll ans1=0,id1=0;
	ll ans2=0,id2=0;
	ll ans3=0,id3=0;
	for(ll i=1;i<=n;++i)vis[i]=0;
	for(ll i:e[x])++vis[i];
	for(ll i:e[y])++vis[i];
	for(ll i=1;i<=n;++i){
		if(vis[i]==2&&i!=x&&i!=y){
			if(a[i]>=ans1){
				ans3=ans2;
				id3=id2;
				ans2=ans1;
				id2=id1;
				ans1=a[i];
				id1=i;
			}else if(a[i]>=ans2){
				ans3=ans2;
				id3=id2;
				ans2=a[i];
				id2=i;
			}else if(a[i]>=ans3){
				ans3=a[i];
				id3=i;
			}
		}
	}
	tmp1[y]=id1;
	tmp2[y]=id2;
	tmp3[y]=id3;
}

ll get_tmp(ll x,ll a1,ll a2){
	if(tmp1[x]!=a1&&tmp1[x]!=a2)return tmp1[x];
	if(tmp2[x]!=a1&&tmp2[x]!=a2)return tmp2[x];
	return tmp3[x];
}

ll solve(ll x,ll y){
	ll t1=get_tmp(x,y,0);
	ll t2=get_tmp(y,x,t1);
	if(t1==0||t2==0||x==t2||y==t1||t1==t2)return 0;
	return a[t1]+a[x]+a[y]+a[t2];
}

int main(){
	freopen("holiday.in","r",stdin);
	freopen("holiday.out","w",stdout);
	
	scanf("%lld%lld%lld",&n,&m,&k);
	for(ll i=2;i<=n;++i){
		scanf("%lld",&a[i]);
	}
	for(ll i=1;i<=m;++i){
		ll x,y;
		scanf("%lld%lld",&x,&y);
		e1[x].push_back(y);
		e1[y].push_back(x);
	}
	for(ll i=1;i<=n;++i){
		bfs(i);
	}
	for(ll i=1;i<=n;++i){
		get(1,i);
	}
	ll ans=0;
	for(ll i=2;i<=n;++i){
		for(ll j:e[i]){
			ans=max(ans,solve(i,j));
		}
	}
	printf("%lld",ans);
	
	return 0;
}
