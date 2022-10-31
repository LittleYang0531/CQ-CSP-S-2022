#include<bits/stdc++.h>
using namespace std;
#define maxn 305
const long long maxm=1e5+5;
struct node{
	long long v,Next;
}e[maxm*2];
bool vis[maxn];
long long idx,n,m,ans,Maxdis,head[maxn],dis[maxn],dp[maxn][4],value[maxn],Map[maxn][maxn],TLE;
void Astar(long long u,long long chose,long long dis,long long cos);
void add(long long u,long long v);
int main(){
	freopen("holiday.in","r",stdin);
	freopen("holiday.out","w",stdout);
srand(time(0));
	scanf("%lld%lld%lld",&n,&m,&Maxdis);
	if(n<=300){
		for(long long i=2;i<=n;i++)scanf("%lld",&value[i]);
		for(long long i=1;i<=n;i++){
			for(long long j=1;j<=n;j++){
				Map[i][j]=2e9;
			}
		}
		for(long long i=1,x,y;i<=m;i++){
			scanf("%lld%lld",&x,&y);
			Map[x][y]=Map[y][x]=1;
		}
		for(long long k=1;k<=n;k++){
			for(long long i=1;i<=n;i++){
				for(long long j=1;j<=n;j++){
					if(Map[i][k]+Map[k][j]<Map[i][j])Map[i][j]=Map[i][k]+Map[k][j];
				}
			}
		}
		for(long long i=2;i<=n;i++){
			if(Map[1][i]>Maxdis+1)continue;
			for(long long j=i+1;j<=n;j++){
				if(Map[j][1]>Maxdis+1)continue;
				for(long long k=2;k<=n;k++){
					if(Map[i][k]>Maxdis+1||k==i||k==j)continue;
					for(long long l=2;l<=n;l++){
						if(Map[k][l]>Maxdis+1||Map[l][j]>Maxdis+1||l==i||l==j||l==k)continue;
						ans=max(ans,value[i]+value[j]+value[k]+value[l]);
					}
				}
			}
		}printf("%lld",ans);
	}else{
		memset(head,-1,sizeof head);
		for(long long i=2;i<=n;i++)scanf("%lld",&value[i]);
		for(long long i=1,x,y;i<=m;i++){
			scanf("%lld%lld",&x,&y);
			add(x,y);add(y,x);
		}
		queue<long long> q;q.push(1);
		while(!q.empty()){
			long long u=q.front();q.pop();
			for(long long i=head[u];i!=-1;i=e[i].Next){
				long long v=e[i].v;
				if(dis[v]==0&&v!=1)dis[v]=dis[u]+1,q.push(v);
			}
		}Astar(1,0,0,0);
		printf("%lld",ans);
	}
	return 0;
}
void Astar(long long u,long long chose,long long dist,long long cos){TLE++;
if(TLE>=1e8){
	printf("%lld",ans);exit(0);
}
	if((5-chose)*(Maxdis+1)<dis[u])return;
	if(dist>Maxdis+1)return;
	if(chose==4){
		ans=max(ans,cos);return;
	}
	for(long long i=head[u];i!=-1;i=e[i].Next){TLE++;
		long long v=e[i].v;
		if(vis[v]==1)continue;
		if(rand()%2==0)Astar(v,chose,dist+1,cos);
		if(vis[v]==0&&v!=1){
			vis[v]=1;Astar(v,chose+1,dist+1,cos+value[v]);vis[v]=0;
		}
	}
}
void add(long long u,long long v){
	e[idx].v=v,e[idx].Next=head[u];
	head[u]=idx++;
}
