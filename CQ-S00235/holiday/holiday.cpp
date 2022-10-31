#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mod=998244353,N=2500,V=1e9;
int n,m,K,dis[N+5][N+5],is[N+5][N+5],mxp[N+5],sep[N+5],thp[N+5];
ll a[N+5],mxv[N+5],sev[N+5],thv[N+5];
vector<int> g[N+5];
void BFS(int s,int dis[]){
	fill(dis+1,dis+n+1,V);
	queue<int> q;
	dis[s]=0,q.push(s);
	while(!q.empty()){
		int x=q.front();
		q.pop();
		for(int y:g[x]){
			if(dis[y]>dis[x]+1){
				dis[y]=dis[x]+1;
				q.push(y);
			}
		}
	}
}
ll ans=0;
void Check(int x,int y,int z,int w){
	if(x==y||x==z||x==w||y==z||y==w||z==w||!x||!y||!z||!w)return ;
	ans=max(ans,a[x]+a[y]+a[z]+a[w]);
}
int main(){
	freopen("holiday.in","r",stdin);
	freopen("holiday.out","w",stdout);
	scanf("%d%d%d",&n,&m,&K);
	for(int i=2;i<=n;i++)scanf("%lld",&a[i]);
	for(int i=1,x,y;i<=m;i++){
		scanf("%d%d",&x,&y);
		g[x].push_back(y),g[y].push_back(x);
	}
	for(int i=1;i<=n;i++)BFS(i,dis[i]);
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(i!=j&&dis[i][j]<=K+1)is[i][j]=1;
		}
	}
	for(int i=2;i<=n;i++){
		for(int j=2;j<=n;j++){
			if(is[1][i]&&is[i][j]){
				if(a[i]>mxv[j]){
					thv[j]=sev[j];
					thp[j]=sep[j];
					sev[j]=mxv[j];
					sep[j]=mxp[j];
					mxv[j]=a[i];
					mxp[j]=i;
				}
				else if(a[i]>sev[j]){
					thv[j]=sev[j];
					thp[j]=sep[j];
					sev[j]=a[i];
					sep[j]=i;
				}
				else if(a[i]>thv[j]){
					thv[j]=a[i];
					thp[j]=i;
				}
			}
		}
	}
	for(int i=2;i<=n;i++){
		for(int j=2;j<=n;j++){
			if(is[i][j]){
				Check(mxp[i],i,j,mxp[j]);
				Check(mxp[i],i,j,sep[j]);
				Check(mxp[i],i,j,thp[j]);
				Check(sep[i],i,j,mxp[j]);
				Check(sep[i],i,j,sep[j]);
				Check(sep[i],i,j,thp[j]);
				Check(thp[i],i,j,mxp[j]);
				Check(thp[i],i,j,sep[j]);
				Check(thp[i],i,j,thp[j]);
			}
		}
	}
	cout<<ans;
}
