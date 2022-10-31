#include<bits/stdc++.h>
#define ll long long
#define fi first
#define se second
#define pb push_back
#define ull unsigned long long
using namespace std;
const int N=2505;
const int M=10005;
int n,m,K,vis[N][N];
ll a[N];
vector<int>g[N];
vector<int>ve[N];
queue<pair<int,int>>q;
ull res;
bool cmp(int x,int y){
	return a[x]>a[y];
}
int main(){
	freopen("holiday.in","r",stdin);
	freopen("holiday.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>n>>m>>K;for(int i=2;i<=n;i++)cin>>a[i];
	for(int i=1;i<=m;i++){
		int u,v;cin>>u>>v,g[u].pb(v),g[v].pb(u);
	}
	for(int i=1;i<=n;i++){
		q.push(make_pair(i,0)),vis[i][i]=1;
		while(q.size()){
			int u=q.front().fi,w=q.front().se;q.pop();
			for(auto v:g[u]){
				if(!vis[i][v]&&w+1<=K+1){
					vis[i][v]=1,q.push(make_pair(v,w+1));
					if(i>1&&v!=1&&vis[1][v])ve[i].pb(v);
				}
			}
		}
		if(i>1){
			sort(ve[i].begin(),ve[i].end(),cmp);
			if(ve[i].size()>4)ve[i].resize(4);
		}	
	}
	for(int i=2;i<=n;i++){
		for(int j=2;j<=n;j++){
			if(i==j||!vis[i][j]||ve[i].size()==0||ve[j].size()==0||(ull)a[i]+a[j]+a[ve[i][0]]+a[ve[j][0]]<=res)continue;
			for(auto k:ve[i]){
				if(k==j)continue;
				for(auto l:ve[j]){
					if(l!=i&&l!=k){
//						cout<<i<<' '<<j<<' '<<k<<' '<<l<<' '<<a[i]+a[j]+a[k]+a[l]<<"\n";
						res=max(res,(ull)a[i]+a[j]+a[k]+a[l]);
					}
				}
			}
		}
	}cout<<res;
}
