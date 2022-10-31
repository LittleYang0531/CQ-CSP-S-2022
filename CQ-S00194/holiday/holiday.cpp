#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=2505,M=1e5+5;
ll a[N];
vector <int> G[N];
int dis[N][N];
int pre[N][2];
bool vis[N];
bool chk(int x,int y,int z,int w){
	if(x==y)	return 0;
	if(x==z)	return 0;
	if(x==w)	return 0;
	if(y==z)	return 0;
	if(y==w)	return 0;
	if(z==w)	return 0;
	return 1;
}
int main(){
	freopen("holiday.in","r",stdin);
	freopen("holiday.out","w",stdout);
	int n,m,k;
	scanf("%d %d %d",&n,&m,&k);
	a[0]=-1e18;
	for(int i=2;i<=n;++i)
		scanf("%lld",&a[i]);
	for(int i=1;i<=m;++i){
		int u,v;
		scanf("%d %d",&u,&v);
		G[u].push_back(v),G[v].push_back(u);
	}
	memset(dis,0x3f,sizeof(dis));
	for(int i=1;i<=n;++i){
		queue <int> que;
		que.push(i);
		dis[i][i]=0;
		for(int j=1;j<=n;++j){
			if(que.empty())	break;
			int u=que.front();
			que.pop();
			for(int k=0;k<G[u].size();++k){
				int v=G[u][k];
				if(dis[i][v]<1e9)	continue;
				dis[i][v]=dis[i][u]+1;
				que.push(v);
			}
		}
	}
	for(int i=1;i<=n;++i)
		for(int j=2;j<=n;++j){
			if(i==j)	continue;
			if(dis[i][j]>k+1 || dis[1][j]>k+1)
				continue;
			if(a[j]>=a[pre[i][0]])
				pre[i][1]=pre[i][0],pre[i][0]=j;
			else if(a[j]>=a[pre[i][1]])
				pre[i][1]=j;
		}
	ll ans=0;
	for(int i=2;i<=n;++i)
		for(int j=2;j<=n;++j){
			if(dis[i][j]>k+1)	continue;
			if(chk(i,j,pre[i][0],pre[j][0]))
				ans=max(ans,a[i]+a[j]+a[pre[i][0]]+a[pre[j][0]]);
			if(chk(i,j,pre[i][0],pre[j][1]))
				ans=max(ans,a[i]+a[j]+a[pre[i][0]]+a[pre[j][1]]);
			if(chk(i,j,pre[i][1],pre[j][0]))
				ans=max(ans,a[i]+a[j]+a[pre[i][1]]+a[pre[j][0]]);
			if(chk(i,j,pre[i][1],pre[j][1]))
				ans=max(ans,a[i]+a[j]+a[pre[i][1]]+a[pre[j][1]]);
		}
	printf("%lld",ans);
	return 0;
}
