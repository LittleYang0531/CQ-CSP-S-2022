#include<bits/stdc++.h>
#define ll long long

using namespace std;
ll n,m,k,ans;
ll s[2505];
bool nu[2505][2505];
void add(ll sum,ll last){
	nu[sum][last]=nu[last][sum]=true;
}
ll bfs(ll u,ll sc,ll step,ll last,bool flag){
	ll score=sc,ans;
	if(step==5)return sc;
	if(flag)score+=s[u],step++;
	for(ll i=1;i<=n;i++){
		if(i==last)continue;
		if(nu[u][i]==true)ans=max(ans,max(bfs(i,score,step,u,false),bfs(i,score,step,u,true)));
	}
	return ans;
}
ll main(){
	freopen("holiday.in","r",stdin);
	freopen("holiday.out","w",stdout);
	cin>>n>>m>>k;
	for(ll i=2;i<=n;i++)cin>>s[i];
	cout<<bfs(1,0,1,1,false);
	return 0;
}

