#include<bits/stdc++.h>
#define N 2505
#define ll long long
using namespace std;
struct node{
	ll x,y;
	bool operator<(const node& a)const{
		return a.y<y;
	}
}tmp,t2;
struct n1{ll m[4],x[4];}dp1[N],dp2[N];
vector<ll> op[N];
ll n,m,k,x,y,i,dp[N][N],vis[N],j,a[N],ans,l,p,l1,l2,t3;
ll maps1[N][N],maps2[N][N];
//priority_queue<node> cnt;
deque<ll> cnt;
void dijkstra(ll x){
	for(int i=1;i<=n;i++) vis[i]=0;
	/*tmp.x = x,tmp.y = 0;
	cnt.push(tmp);
	while(cnt.size()){
		tmp = cnt.top(),cnt.pop();
		if(dp[x][tmp.x]!=tmp.y||tmp.y==k+1) continue;
		vis[tmp.x] = 1;
		for(int i=0;i<op[tmp.x].size();i++){
			if(vis[op[tmp.x][i]]||dp[x][op[tmp.x][i]]<dp[x][tmp.x]+1) continue;
			dp[x][op[tmp.x][i]]=dp[x][tmp.x]+1;
			t2.x = op[tmp.x][i],t2.y = dp[x][op[tmp.x][i]];
			cnt.push(t2);
		}
	}*/
	cnt.push_back(x);
	while(cnt.size()){
		t3 = cnt.front(),cnt.pop_front();
		vis[t3] = 0;
		if(dp[x][t3]==k+1) continue;
		for(int i=0;i<op[t3].size();i++){
			if(dp[x][op[t3][i]]>dp[x][t3]+1){
				dp[x][op[t3][i]] = dp[x][t3]+1;
				if(!vis[op[t3][i]]) cnt.push_back(op[t3][i]),vis[op[t3][i]]=1;
			}
		}
	}
}
int main(){
	freopen("holiday.in","r",stdin);
	freopen("holiday.out","w",stdout);
	ios::sync_with_stdio(false);
	cin>>n>>m>>k;
	for(i=2;i<=n;i++) cin>>a[i];
	for(i=1;i<=m;i++){
		cin>>x>>y;
		op[x].push_back(y);
		op[y].push_back(x);
	}
	for(i=1;i<=n;i++) for(j=1;j<=n;j++) dp[i][j]=LLONG_MAX/2;
	for(i=1;i<=n;i++) dp[i][i]=0,dijkstra(i);
	for(i=2;i<=n;i++){
		if(dp[1][i]==LLONG_MAX/2) continue;
		for(j=2;j<=n;j++){
			if(i==j||dp[i][j]==LLONG_MAX/2) continue;
			maps1[i][j] = a[i]+a[j];
		}
	}
	for(i=2;i<=n;i++){
		for(j=2;j<=n;j++){
			if(i==j) continue;
			for(l=1;l<=3;l++){
				if(dp1[j].m[l]<maps1[i][j]){
					for(p=3;p>l;p--) dp1[j].m[p]=dp1[j].m[p-1],dp1[j].x[p]=dp1[j].x[p-1];
					dp1[j].m[l] = maps1[i][j],dp1[j].x[l] = i;
					break;
				}
			} 
		}
	}
	for(i=2;i<=n;i++){
		for(j=2;j<=n;j++){
			if(i==j||dp[i][j]==LLONG_MAX/2) continue;
			for(l1=1;l1<=3;l1++){
				for(l2=1;l2<=3;l2++){
					if(dp1[i].x[l1]==0||dp1[j].x[l2]==0) continue;
					if(dp1[i].x[l1]!=dp1[j].x[l2]&&dp1[i].x[l1]!=j&&dp1[j].x[l2]!=i){
						ans = max(ans,dp1[i].m[l1]+dp1[j].m[l2]);
					}
				}
			}
		}
	}
	cout<<ans<<endl;
	return 0;
} 
