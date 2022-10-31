#include<cstdio>
#include<vector>
#include<cstring>
using namespace std;
const int N=2e5+5,M=20;
const long long inf=0x3f3f3f3f3f3f3f3f;
int n,q,k,val[N];
int d[N],fa[M][N],LG[N];
long long s[N];
vector<int>e[N];
struct query{int u,v,w;}p[N];
void dfs(int u){
	s[u]+=val[u];
	for(int v:e[u]){
		if(v!=fa[0][u])fa[0][v]=u,s[v]=s[u],d[v]=d[u]+1,dfs(v);
	}
}
int LCA(int u,int v){
	if(d[u]<d[v])swap(u,v);
	for(int i=LG[n];~i;i--){
		if(d[u]-(1<<i)>=d[v])u=fa[i][u];
	}
	if(u==v)return u;
	for(int i=LG[n];~i;i--){
		if(fa[i][u]!=fa[i][v])u=fa[i][u],v=fa[i][v];
	}
	return fa[0][u];
}
long long dp[2][2][M][N];
void init(){
	for(int i=1;i<=n;i++){
		dp[0][0][0][i]=val[i];
		dp[0][1][0][i]=dp[1][0][0][i]=dp[1][1][0][i]=inf;
		dp[0][0][1][i]=val[i]+val[fa[0][i]];
		dp[0][1][1][i]=val[i];
		dp[1][0][1][i]=val[fa[0][i]];
		dp[1][1][1][i]=inf;
	}
	for(int i=2;i<=LG[n];i++){
		for(int j=1;j<=n;j++){
			for(int u=0;u<2;u++){
				for(int v=0;v<2;v++){
					dp[u][v][i][j]=min(min(
						dp[u][0][i-1][j]+dp[0][v][i-1][j],
						dp[u][0][i-1][j]+dp[1][v][i-1][j]),
						dp[u][1][i-1][j]+dp[0][v][i-1][j]);
				}
			}
		}
	}
}
long long ask(int u,int v){
	if(d[u]<d[v])swap(u,v);
	long long x[2][2][2],y=0;
	memset(x,0x3f,sizeof(x)),x[y][0][0]=0;
	for(int i=LG[n];~i;i--){
		if(d[u]-(1<<i)>=d[v]){
			if(i==0){
				x[y^1][0][0]=min(x[y][0][0],x[y][1][0])+val[u]+val[fa[0][u]];
				x[y^1][1][0]=min(x[y][0][0],x[y][0][1])+val[u];
				y^=1;
			}else{
				x[y^1][0][0]=min(
					x[y][0][0]+min(dp[0][0][i][u],dp[0][1][i][u]),
					x[y][1][0]+min(dp[1][0][i][u],dp[1][1][i][u]));
				x[y^1][1][0]=min(
					x[y][0][0]+dp[0][0][i][u],
					x[y][1][0]+dp[1][0][i][u]);
				y^=1;
			}
			u=fa[i][u];
		}
	}
	if(u==v)return min(x[y][0][0],x[y][1][0])+val[v];
	for(int i=LG[n];~i;i--){
		if(fa[i][u]!=fa[i][v]){
			if(i==0){
				x[y^1][0][0]=min(min(min(x[y][0][0],x[y][0][1]),x[y][1][0]),
					x[y][1][1])+val[u]+val[v]+val[fa[0][u]]+val[fa[0][v]];
				x[y^1][0][1]=min(x[y][0][0],x[y][1][0])
					+val[u]+val[v]+val[fa[0][u]];
				x[y^1][1][0]=min(x[y][0][0],x[y][0][1])
					+val[u]+val[v]+val[fa[0][v]];
				x[y^1][1][1]=x[y][0][0]+val[u]+val[v];
				y^=1;
			}else{
				for(int j=0;j<2;j++){
					x[y^1][0][j]=min(
						x[y][0][j]+min(dp[0][0][i][u],dp[0][1][i][u]),
						x[y][1][j]+min(dp[1][0][i][u],dp[1][1][i][u]));
					x[y^1][1][j]=min(
						x[y][0][j]+dp[0][0][i][u],
						x[y][1][j]+dp[1][0][i][u]);
				}
				y^=1;
				for(int j=0;j<2;j++){
					x[y^1][j][0]=min(
						x[y][j][0]+min(dp[0][0][i][v],dp[0][1][i][v]),
						x[y][j][1]+min(dp[1][0][i][v],dp[1][1][i][v]));
					x[y^1][j][1]=min(
						x[y][j][0]+dp[0][0][i][v],
						x[y][j][1]+dp[1][0][i][v]);
				}
				y^=1;
			}
//			printf("%d %d %d\n",u,v,i);
//			for(int i=0;i<2;i++){
//				for(int j=0;j<2;j++)printf("%lld ",x[y][i][j]);
//			}
//			printf("\n");
			u=fa[i][u],v=fa[i][v];
		}
	}
	return min(min(min(x[y][0][0],
		x[y][0][1]+min(val[fa[0][u]],val[v])),
		x[y][1][0]+min(val[fa[0][u]],val[u])),
		x[y][1][1]+val[fa[0][u]]);
}
int main(){
	freopen("transmit.in","r",stdin);
	freopen("transmit.out","w",stdout);
	scanf("%d %d %d",&n,&q,&k);
	for(int i=1;i<=n;i++)scanf("%d",&val[i]);
	for(int i=1,u,v;i<n;i++){
		scanf("%d %d",&u,&v),e[u].push_back(v),e[v].push_back(u);
	}
	dfs(1);
	for(int i=1;i<=n;i++)LG[i]=LG[i>>1]+1;
	for(int i=1;i<=LG[n];i++){
		for(int j=1;j<=n;j++)fa[i][j]=fa[i-1][fa[i-1][j]];
	}
	if(k==1){
		while(q--){
			int u,v,w;
			scanf("%d %d",&u,&v),w=LCA(u,v);
			printf("%lld\n",s[u]+s[v]-s[w]-s[fa[0][w]]);
		}
	}else if(k==2){
		init();
		while(q--){
			int u,v;
			scanf("%d %d",&u,&v);
			printf("%lld\n",ask(u,v));
		}
	}
	return 0;
}
