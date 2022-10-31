#include<cstdio>
#include<queue>
#include<iostream>
#include<cstring>
#include<vector>
#include<algorithm>
using namespace std;
typedef long long ll;
struct e{
	int to,next;
	bool come;
}edge[20005];
struct node{
	ll val,id;
	bool operator<(const node &X)const{return X.val<val;}
};
ll n,m,k,p[2505],cnt=0,head[2505],tot,idx[2505];
ll dis[2505][2505],dp[2505][7],ans;
vector<int>cango[2505];
bool vis[2505];
void add_edge(int u,int v){
	edge[++cnt].to=v;
	edge[cnt].next=head[u];
	edge[cnt].come=false;
	head[u]=cnt;
}
void dijkstra(int s){
	priority_queue<node>q;
	for(int i=0;i<=n;i++) dis[s][i]=1e18;
	for(int i=0;i<=n;i++) vis[i]=false;
	dis[s][s]=-1; q.push((node){-1,s});
	while(!q.empty()){
		int u=q.top().id; q.pop();
		if(vis[u]) continue;
		vis[u]=true;
		for(int i=head[u];i;i=edge[i].next){
			int v=edge[i].to;
			if(dis[s][u]+1<dis[s][v]){
				dis[s][v]=dis[s][u]+1;
				q.push((node){dis[s][v],v});
			}
		}
	}
}
void work1(){
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(dis[i][j]<=k&&i!=j) cango[i].push_back(j);
		}
	}
	for(int i=0;i<cango[1].size();i++){
		for(int j=0;j<cango[1].size();j++){
			if(i==j) continue;
			int s1=cango[1][i],s2=cango[1][j];
			for(int g1=0;g1<cango[s1].size();g1++){
				for(int g2=0;g2<cango[s2].size();g2++){
					int s3=cango[s1][g1],s4=cango[s2][g2];
					if(s3==s2||s3==s1||s3==s4) continue;
					if(s4==s2||s4==s1) continue;
					if(dis[s3][s4]>k) continue;
					ans=max(ans,p[s1]+p[s2]+p[s3]+p[s4]);
				}
			}
		}
	}
	printf("%lld\n",ans);
}
void work2(){
	memset(dp,-1,sizeof -1);
	dp[1][0]=dp[1][1]=dp[1][2]=dp[1][3]=dp[1][4]=0;
	for(int i=2;i<=n;i++)
	  for(int j=1;j<=4;j++)
		for(int s=1;s<i;s++){
			if(dp[s][j-1]!=-1&&dis[s][i]<=k&&s!=i) dp[i][j]=max(dp[i][j],dp[s][j-1]+p[i]);
		}
	for(int i=2;i<=n;i++){
		if(dis[1][i]<=k) ans=max(ans,dp[i][4]);
	}
	printf("%lld\n",ans);
}
int main(){
	freopen("holiday.in","r",stdin);
	freopen("holiday.out","w",stdout);
	scanf("%lld%lld%lld",&n,&m,&k);
	for(int i=2;i<=n;i++) scanf("%lld",&p[i]);
	for(int i=1;i<=m;i++){
		int u,v; scanf("%d%d",&u,&v);
		add_edge(u,v); add_edge(v,u);
	}
	for(int i=1;i<=n;i++) dijkstra(i);
	if(n<=120) work1();
	else work2();
	return 0;
}
