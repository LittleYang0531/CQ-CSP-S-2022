#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const int MAXN=2505;
int n,m,t,u,v;
bool flg[MAXN],f[MAXN][MAXN];
LL a[MAXN],dis[MAXN][MAXN],ans;
vector<int>g[MAXN];
struct node{
	int v;
	LL w;
	friend bool operator<(node a,node b){
		return (a.w<b.w)||(a.w==b.w&&a.v<b.v);
	}
};
void dijkstra(int s){
	set<node>ss;
	dis[s][s]=0ll;
	ss.insert(node({s,0}));
	flg[s]=1;
	while(!ss.empty()){
		int u=(*ss.begin()).v;
		ss.erase(ss.begin());
		flg[u]=0;
		for(int i=0;i<g[u].size();++i){
			int v=g[u][i];
			if(dis[s][v]>dis[s][u]+1){
				dis[s][v]=dis[s][u]+1;
				if(!flg[v])flg[v]=1,ss.insert(node({v,dis[s][v]}));
			}
		}
	}
}
void dfs(int u,int fa,int dep,LL sum){
	if(dep==4){
		if(f[u][1])ans=max(ans,sum);
		return;
	}
	for(int i=0;i<g[u].size();++i){
		int v=g[u][i];
		if(v==fa)continue;
		dfs(v,u,dep+1,sum+a[v]);
	}
} 
int main(){
	freopen("holiday.in","r",stdin);
	freopen("holiday.out","w",stdout);
	scanf("%d%d%d",&n,&m,&t);
	for(int i=1;i<=n;++i){
		memset(dis[i],0x3f,sizeof dis[i]);
	}
	for(int i=2;i<=n;++i)scanf("%lld",&a[i]);
	for(int i=1;i<=m;++i){
		scanf("%d%d",&u,&v);
		g[u].push_back(v);
		g[v].push_back(u);
		f[u][v]=f[v][u]=1;
	}
	if(!t){
		dfs(1,0,0,0);
		printf("%lld",ans);
		return 0;
	}
	for(int i=1;i<=n;++i)dijkstra(i);
	for(int i=1;i<=n;++i){
		for(int j=1;j<=n;++j){
			--dis[i][j];
		}
	}
	for(int i=1;i<=n;++i){
		if(1==i||dis[1][i]>t)continue;
		for(int j=1;j<=n;++j){
			if(j==1||i==j||dis[i][j]>t)continue;
			for(int k=1;k<=n;++k){
				if(k==1||i==k||j==k||dis[j][k]>t)continue;
				for(int l=1;l<=n;++l){
					if(l==1||i==l||j==l||k==l||dis[k][l]>t||dis[l][1]>t)continue;
					ans=max(ans,a[i]+a[j]+a[k]+a[l]);
				}
			}
		}
	}
	printf("%lld",ans);
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
