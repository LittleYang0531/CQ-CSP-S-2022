#include<bits/stdc++.h>
using namespace std;
#define ll long long
struct node{
	ll to,next;
}ma[25005];
ll h[25005],cnt,z[25008],n,m,k,v[25005],x,y,nnb;
bool vv[10005];
void add(ll a,ll b){ma[++cnt].to=b;ma[cnt].next=h[a];h[a]=cnt;}
ll dfs0(ll g,ll s,ll ans){
	ll love=ans;
	if(s>4)return 0;
	for(int i=h[g];i;i=ma[i].next){
		int n=ma[i].to;
		if(n==1&&s==4){
			//for(int i=0;i<4;i++)cout<<zys[i]<<" "<<hh[i]<<endl;
			//cout<<ans<<endl;
			nnb=max(nnb,ans);
			return ans;
		}
		if(v[n])continue;
		v[n]=1;
		ll gg=dfs0(n,s+1,ans+z[n]);
		love=max(love,gg);
		v[n]=0;
	}
	if(g==1&&s==0){
		return love;
	}
	else return 0;
}
int main(){
	freopen("holiday.in","r",stdin);
	freopen("holiday.out","w",stdout);
	scanf("%lld%lld%lld",&n,&m,&k);
	for(int i=2;i<=n;i++)scanf("%lld",&z[i]);
	for(int i=1;i<=m;++i){
		scanf("%lld%lld",&x,&y);
		add(x,y);add(y,x);
		if(x==1)vv[y]=1;
		if(y==1)vv[x]=1;
	}
	if(k==0){
		v[1]=1;
		dfs0(1,0,0);
		cout<<nnb;
	}
	return 0;
}

