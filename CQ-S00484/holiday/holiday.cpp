#include<bits/stdc++.h>
#define ll long long
#define mp make_pair
#define pb push_back
#define pii pair<ll,ll>

using namespace std;
const int N=2510,M=1e4,inf=1e9;

vector<ll>g[N];
ll n,m,az,x,y,v[N],dis[N][N],ans=0;
priority_queue<pii,vector<pii>,greater<pii> >q;

int main(){
	
	freopen("holiday.in","r",stdin);
	freopen("holiday.out","w",stdout);
	
	cin>>n>>m>>az;az++;for(int i=2;i<=n;i++)cin>>v[i];
	for(int i=1;i<=m;i++){cin>>x>>y;g[x].pb(y);g[y].pb(x);}
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
		
	for(int a=2;a<=n;a++){
		if(dis[1][a]>az)continue;
		for(int b=2;b<=n;b++){
			if(a==b||dis[a][b]>az)continue;
			for(int c=2;c<=n;c++){
				if(a==c||b==c||dis[b][c]>az)continue;
				for(int d=2;d<=n;d++){
					if(a==d||b==d||c==d||dis[c][d]>az||dis[d][1]>az)continue;
					ans=max(ans,v[a]+v[b]+v[c]+v[d]);
				}
			}
		}
	}
		
	cout<<ans;
	return 0;
}
//(/>w<)/fw
