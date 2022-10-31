#include <bits/stdc++.h>
#define int long long
using namespace std;
const int MAXN=2505;
struct node{
	int u,dis;
	node(){}
	node(int a,int b){
		u=a;
		dis=b;
	}
	friend bool operator < (node a,node b){
		return a.dis>b.dis;
	}
};
int dis[MAXN],ans,dp[MAXN][MAXN],n,m,k,b[MAXN],cnt,c[MAXN],d[MAXN],xiang[MAXN];
bool vis[MAXN],vis2[MAXN],vis3[MAXN];
vector<node> G[MAXN];
priority_queue<node> q;
void dijkstra(int S){
	memset(dis,0x3f,sizeof(dis));
	memset(vis,0,sizeof(vis));
	dis[S]=0;
	q.push(node(S,dis[S]));
	while(!q.empty()){
		int u=q.top().u;
		q.pop();
		if(vis[u]) continue;
		int len=G[u].size();
		for(int i=0;i<len;i++){
			int v=G[u][i].u,w=G[u][i].dis;
			if(dis[u]+w<dis[v]){
				dis[v]=dis[u]+w;
				q.push(node(v,dis[v]));
			}
		}
	}
	for(int i=1;i<=n;i++){
		dp[S][i]=dis[i]-1;
		dp[i][S]=dp[S][i];
	}
}
int make(){
	int sum=0;
	for(int i=1;i<=4;i++){
		sum+=b[c[i]];
	}
	return sum;
}
void quan(int step){
	if(step==4){
		if(dp[c[step]][1]>k) return ;
		ans=max(ans,make());
		return ;
	}
	for(int i=2;i<=n;i++){
		if(!vis2[i]&&dp[c[step]][i]<=k){
			c[step+1]=i;
			vis2[i]=1;
			quan(step+1);
			vis2[i]=0;
		}
	}
}
signed main(){
	freopen("holiday.in","r",stdin);
	freopen("holiday.out","w",stdout);
	scanf("%lld %lld %lld",&n,&m,&k);
	for(int i=2;i<=n;i++){
		scanf("%lld",&b[i]);
	}
	for(int i=1;i<=m;i++){
		int a,b;
		scanf("%lld %lld",&a,&b);
		G[a].push_back(node(b,1));
		G[b].push_back(node(a,1));
	}
	for(int i=1;i<=n;i++){
		dijkstra(i);
	}
	c[0]=1;
	c[5]=1;
	int t=4,now=1;
	quan(0);
	printf("%lld\n",ans);
	return 0;
} 
/*
8 8 1
9 7 1 8 2 3 6
1 2
2 3
3 4
4 5
5 6
6 7
7 8
8 1
*/
