#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll n,m,k,vd[500005],c[500005],T,cnt1,t,wt,h1[500005],h[500005],cnt;
map<ll,int>q;
const ll hash=1000000;
struct node{
	ll to,next;
}ma[500005],mb[500005];
void add(ll a,ll b){ma[++cnt].to=b;ma[cnt].next=h[a];h[a]=cnt;mb[++cnt1].to=a;mb[cnt1].next=h1[b];h1[b]=cnt1;}
void solve(){
	ll a;
	scanf("%lld",&a);//cout<<"sb";
	if(a==1){
		ll x,y;
		scanf("%lld%lld",&x,&y);c[x]--;q[x*hash+y]=1;
		if(c[x]==1)wt--;else if(!c[x])wt++;
	}
	else if(a==2){
		ll x;
		scanf("%lld",&x);
			for(int i=h[x];i;i=ma[i].next){
				int to=ma[i].to;
				if(!q[x+ma[i].to*hash]){
					c[to]--;if(c[to]==1)wt--;if(c[to]==0)wt++;
				}
			}
		
		vd[x]=1;
	}
	else if(a==3){
		ll x,y;
		scanf("%lld%lld",&x,&y);
		c[x]++;q[x*hash+y]=0;
		if(c[x]==1)wt--;else if(c[x]==2)wt++;
	}
	else if(a==4){
		ll x;
		scanf("%lld",&x);
			for(int i=h[x];i;i=ma[i].next){
				int to=ma[i].to;
				if(q[x+ma[i].to*hash]){
					c[to]++;if(c[to]==1)wt--;if(c[to]==2)wt++;
				}
				
			}
		for(int i=h1[x];i;i=mb[i].next){
				int to=mb[i].to;
				//cout<<to<<endl;
				if(q[x*hash+mb[i].to]){
					
					c[x]++;if(c[x]==1)wt--;if(c[x]==2)wt++;
				}
				
			}
		
		
		vd[x]=0;
		
	}
	if(!wt)cout<<"Yes"<<endl;
	else cout<<"No"<<endl;
}
int main(){
	freopen("galaxy.in","r",stdin);
	freopen("galaxy.out","w",stdout);
	bool v[500005]={0};
	scanf("%lld%lld",&n,&m);
	for(int i=1;i<=m;++i){
		ll x,y;
		scanf("%lld%lld",&x,&y);
		add(y,x);
		c[x]++;
		
	}
	for(int i=1;i<=n;i++)if(!v[i]&&c[i]!=1)wt++;
	scanf("%lld",&T);
	while(T--){
		solve();
	}
	return 0;
}

