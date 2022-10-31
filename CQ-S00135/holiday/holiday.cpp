#include<bits/stdc++.h>
#define ll unsigned long long
#pragma GCC optimize(3)
#define N 2509
#define M 20009
#define inf 1e9+7
using namespace std;
int n,m,k,s,x,y,he[N],cnt,dis[N],score[N],vis[N],got[N][N],f[N][2],ans,p[N][2];
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
	freopen("holiday.in","r",stdin);
	freopen("holiday.out","w",stdout);
	cin>>n>>m>>k;
	k++;
	for(int i=2;i<=n;i++){
		cin>>score[i];
	}
	for(int i=1;i<=m;i++){
		cin>>x>>y;
		add(x,y);
		add(y,x);
	}
	for(int i=1;i<=n;i++){
		s=i;
		dijkstra();
		for(int j=1;j<=n;j++){
			if(dis[j]<=k){
				got[i][j]=got[j][i]=1;
			}
		}
	}
	for(int i=2;i<=n;i++){
		for(int j=2;j<=n;j++){
			if(i==j){
				continue;
			}
			if(got[1][i]&&got[i][j]){
				if(score[i]+score[j]>=f[j][1]){
					f[j][0]=f[j][1];
					p[j][0]=p[j][1];
					f[j][1]=score[i]+score[j];
					p[j][1]=i;
				}
				else if(score[i]+score[j]>f[j][0]){
					f[j][0]=score[i]+score[j];
					p[j][0]=i;
				}
			}
		}
	}
	for(int i=2;i<=n;i++){
		for(int j=2;j<=n;j++){
			if(i==j){
				continue;
			}
			if(!got[i][j]){
				continue;
			}
			if(p[i][1]!=p[j][1]&&p[i][1]!=j&&p[j][1]!=i){
				ans=max(ans,f[i][1]+f[j][1]);
			}
			else if(p[i][1]!=j&&p[j][0]!=i){
				ans=max(ans,f[i][1]+f[j][0]);
			}
			else if(p[i][0]!=j&&p[j][1]!=i){
				ans=max(ans,f[i][0]+f[j][1]);
			}
		}
	}
	cout<<ans;
	return 0;
}
