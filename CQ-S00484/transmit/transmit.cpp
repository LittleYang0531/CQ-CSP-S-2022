#include<bits/stdc++.h>
#define ll long long
#define pb push_back
#define mp make_pair
#define pii pair<int,int>

using namespace std;
const ll N=2e3+10,inf=1e9;

vector<ll>g[N];
ll n,t,az,v[N],x,y,dis[N][N],ans[N];
priority_queue<pii,vector<pii>,greater<pii> >q;

int main(){
	
	freopen("transmit.in","r",stdin);
	freopen("transmit.out","w",stdout);
	
	cin>>n>>t>>az;
	for(int i=1;i<=n;i++)cin>>v[i];
	for(int i=1;i<=n-1;i++){cin>>x>>y;g[x].pb(y);g[y].pb(x);}
	
	for(int i=1;i<=n;i++)for(int j=1;j<=n;j++)if(i!=j)dis[i][j]=inf;
	for(int i=1;i<=n;i++){
		q.push(mp(0,i));
		while(!q.empty()){
			x=q.top().second;q.pop();
			for(int j=0;j<g[x].size();j++)
				if(dis[i][x]+1<dis[i][g[x][j]]){
					dis[i][g[x][j]]=dis[i][x]+1;
					q.push(mp(dis[i][g[x][j]],g[x][j]));
				}
		}
	}
	for(int i=1;i<=n;i++)for(int j=i+1;j<=n;j++)if(dis[i][j]<az)g[i].pb(j),g[j].pb(i);
	
	while(t--){
		cin>>x>>y;
		for(int i=1;i<=n;i++)ans[i]=inf;ans[x]=v[x];q.push(mp(v[x],x));
		while(!q.empty()){
			x=q.top().second;q.pop();
			for(int i=0;i<g[x].size();i++)
				if(ans[x]+v[g[x][i]]<ans[g[x][i]]){
					ans[g[x][i]]=ans[x]+v[g[x][i]];
					q.push(mp(ans[g[x][i]],g[x][i]));
				}
		}
		cout<<ans[y]<<"\n";
	}
		
	return 0;
}
//(/>w<)/fw
