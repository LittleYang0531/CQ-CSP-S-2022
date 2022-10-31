#include<bits/stdc++.h>
#define N 200005
#define ll long long
using namespace std;
vector<ll> op1[N];
ll n,q,k,i,fath[N],tmp,a[N],dep[N],x,y,b[N],dp[N],t,c[N],j;
ll po[N],h1,t1;
pair<ll,ll> m1[N],m2[N],m3[N],m4[N],temp1,temp2;
stack<ll> op;
pair<pair<ll,ll>,pair<ll,ll> > cmp(pair<ll,ll> a,pair<ll,ll> b,pair<ll,ll> c){
	if(a.first>=c.first){
		b = a;
		a = c;
	}
	else if(b.first>c.first) b=c;
	return make_pair(a,b);
}
void dfs(ll x){
	m1[x].first = m2[x].first = m1[x].second = m2[x].second = LLONG_MAX;
	m3[x].first = m4[x].first = m3[x].second = m4[x].second = LLONG_MAX;
	for(ll i=0;i<op1[x].size();i++){
		if(op1[x][i]==fath[x]) continue;
		dep[op1[x][i]] = dep[x]+1;
		fath[op1[x][i]] = x;
		temp1 = m1[x],temp2 = m2[x];
		m1[x]=cmp(temp1,temp2,make_pair(a[op1[x][i]],op1[x][i])).first;
		m2[x]=cmp(temp1,temp2,make_pair(a[op1[x][i]],op1[x][i])).second;
		dfs(op1[x][i]);
		temp1 = m3[x],temp2 = m4[x];
		m3[x]=cmp(temp1,temp2,make_pair(m1[op1[x][i]].first,op1[x][i])).first;
		m4[x]=cmp(temp1,temp2,make_pair(m1[op1[x][i]].first,op1[x][i])).second;
	}
}
void solve(ll x,ll y){
	t=0;
	while(dep[x]>dep[y]) b[++t]=x,x=fath[x];
	while(dep[y]>dep[x]) op.push(y),y=fath[y];
	while(x!=y){
		b[++t] = x,op.push(y);
		x = fath[x],y = fath[y];
	}
	b[++t] = x;
	while(op.size()) b[++t]=op.top(),op.pop();
	return ;
}
int main(){
	freopen("transmit.in","r",stdin);
	freopen("transmit.out","w",stdout);
	ios::sync_with_stdio(false);
	cin>>n>>q>>k;
	for(i=1;i<=n;i++) cin>>a[i];
	dep[1] = 1;
	for(i=1;i<n;i++){
		cin>>x>>y;
		op1[x].push_back(y);
		op1[y].push_back(x);
	}
	dep[1]=1,dfs(1);
	while(q--){
		h1=1,t1=0;
		cin>>x>>y;
		solve(x,y);
		for(i=1;i<=t;i++) dp[i]=LLONG_MAX;
		dp[1] = a[b[1]];
		for(i=2;i<=t;i++){
			for(j=max(1ll,i-k);j<i;j++) dp[i]=min(dp[j]+a[b[i]],dp[i]);
		}
		cout<<dp[t]<<endl;
	}
	return 0;
}
