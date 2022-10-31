#include<bits/stdc++.h>
#define inf 1e9+7
#pragma GCC optimize(3)
#define N 5009
#define M 100009
using namespace std;
int n,qq,k,x,y,he[N],cnt,p[N],s,t,got[N][N],vis[N],dis[N];
struct Edge{
	int ne,to;
}e[M];
void add(int u,int v){
	e[++cnt].ne=he[u];
	e[cnt].to=v;
	he[u]=cnt;
}
priority_queue<pair<int,int>,vector<pair<int,int> >,greater<pair<int,int> > >q;
void dijkstra(){
	for(int i=1;i<=n;i++){
		vis[i]=0,dis[i]=inf;
	}
	dis[s]=0;
	q.push(make_pair(0,s));
	while(!q.empty()){
		int u=q.top().second;
		q.pop();
		if(vis[u]){
			continue;
		}
		vis[u]=1;
		for(int i=he[u];i;i=e[i].ne){
			int v=e[i].to;
			if(dis[v]>dis[u]+1){
				dis[v]=dis[u]+1;
				q.push(make_pair(dis[v],v)); 
			}
		}
	}
}
int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	freopen("transmit.in","r",stdin);
	freopen("transmit.out","w",stdout);
	cin>>n>>qq>>k;
	for(int i=1;i<=n;i++){
		cin>>p[i];
	}
	for(int i=1;i<n;i++){
		cin>>x>>y;
		add(x,y);
		add(y,x);
	}
	for(int i=1;i<=n;i++){
		s=i;
		dijkstra();
		for(int j=1;j<=n;j++){
			got[i][j]=got[j][i]=dis[j];
		}
	}
	for(int i=1;i<=qq;i++){
		cin>>s>>t;
		if(got[s][t]<=k){
			cout<<p[s]+p[t]<<endl;
			continue;
		}
		int flag=inf;
		if(got[s][t]<=3){
			for(int i=1;i<=n;i++){
				if(got[s][i]<=k&&got[i][t]<=k){
					flag=min(flag,p[i]);
				}
			}
			cout<<p[s]+p[t]+flag<<endl;
			continue;
		}
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				if(got[s][i]<=k&&got[j][t]<=k&&got[i][j]<=k){
					flag=min(flag,p[i]+p[j]);
				}
			}
		}
		cout<<p[s]+p[t]+flag<<endl;
	}
	return 0;
}
