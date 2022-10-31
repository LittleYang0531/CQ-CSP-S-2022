#include<bits/stdc++.h>
//预计：0
//时间复杂度O(m) 
#define ll long long
using namespace std;
const ll N=1e5+2,INF=1e18;
ll n,m,k,hd[N],to[N],cnt,nxt[N],ans,c[N],a[N],x,y,b[N],vis[N];
void add(ll x,ll y){
	to[++cnt]=y;
	nxt[cnt]=hd[x];
	hd[x]=cnt;
}
ll dfs(ll x,ll step,ll val){
//	cout<<"_"<<x<<" "<<step<<" "<<val<<'\n';
	vis[x]=1;
	if(step>5) return 0;
	if(x==1&&step==5) {
//		cout<<"ok";
		ans=max(ans,val);
		return 1;
	}
	for(ll i=hd[x];i;i=nxt[i]){
		ll y=to[i];
	//	if(vis[y])val+=a[y],step++;
		if(dfs(y,step+1,val+a[y])) {
			return 1;
		}
	//	val-=a[y],step--;
	}
	return 0;
}
int main(){
	freopen("holiday.in","r",stdin);
	freopen("holiday.out","w",stdout);
	scanf("%lld%lld%lld",&n,&m,&k);
	for(ll i=2;i<=n;i++){
		scanf("%lld",&a[i]);
		b[i]=a[i];
	}
	sort(b+1,b+1+n);
	for(ll i=1;i<=m;i++){
		scanf("%lld%lld",&x,&y);
		add(x,y),add(y,x);
	}
	if(k==0){
		dfs(1,0,0);
		printf("%lld",ans);
	}else{
		ll sum=b[n]+b[n-1]+b[n-2]+b[n-3];
		printf("%lld",sum);
	}
	return 0;
}
/*
7 9 0
1 1 1 2 3 4
1 2
2 3
3 4
1 5
1 6
1 7
5 4
6 4
7 4

*/
/*
7 9 0
2 3 4 5 6 7
1 2
1 3
2 4
2 5
3 6
3 7
4 5
4 7
5 6


*/
