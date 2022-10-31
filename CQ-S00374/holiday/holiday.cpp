#include<cstdio>
#include<vector>
#include<cstring>
using namespace std;
const int N=2505,M=10005;
int n,m,k,d[N][N],f[3][N];
long long val[N];
int ehd[N],etl[N],cnt;
struct edge{int to,nxt;}e[M<<1];
void add(int u,int v){
	cnt++;
	if(!ehd[u])ehd[u]=cnt;
	e[etl[u]].nxt=cnt,etl[u]=cnt,e[cnt].to=v;
}
int q[2][N],hd,tl;
bool vst[N];
void bfs(int x){
	for(int i=1;i<=n;i++)vst[i]=0;
	hd=tl=0,q[0][++tl]=x,q[1][tl]=0,d[x][x]=0,vst[x]=1;
	while(hd<tl){
		hd++;
		int u=q[0][hd],w=q[1][hd];
		for(int i=ehd[u];i;i=e[i].nxt){
			int v=e[i].to;
			if(!vst[v])d[x][v]=w+1,q[0][++tl]=v,q[1][tl]=w+1,vst[v]=1;
		}
	}
}
int main(){
	freopen("holiday.in","r",stdin);
	freopen("holiday.out","w",stdout);
	scanf("%d %d %d",&n,&m,&k),k++;
	for(int i=2;i<=n;i++)scanf("%lld",&val[i]);
	for(int i=1,u,v;i<=m;i++)scanf("%d %d",&u,&v),add(u,v),add(v,u);
	memset(d,0x3f,sizeof(d));
	for(int i=1;i<=n;i++)bfs(i);
//	for(int i=1;i<=n;i++){
//		for(int j=1;j<=n;j++)printf("%d ",d[i][j]);
//		printf("\n");
//	}
	for(int u=2;u<=n;u++){
		for(int v=2;v<=n;v++){
			if(u!=v&&d[u][v]<=k&&d[1][v]<=k){
				if(val[v]>=val[f[0][u]])
					f[2][u]=f[1][u],f[1][u]=f[0][u],f[0][u]=v;
				else if(val[v]>=val[f[1][u]])
					f[2][u]=f[1][u],f[1][u]=v;
				else f[2][u]=v;
			}
		}
	}
//	for(int i=2;i<=n;i++){
//		for(int j=0;j<=2;j++)printf("%d ",f[j][i]);
//		printf("\n");
//	}
	long long ans=0;
	for(int u=2;u<=n;u++){
		for(int v=2;v<=n;v++){
			if(u==v||d[u][v]>k)continue;
			for(int i=0;i<=2;i++){
				int x=f[i][u];
				if(!x||x==v)continue;
				for(int j=0;j<=2;j++){
					int y=f[j][v];
					if(!y||y==u||y==x)continue;
					ans=max(ans,val[u]+val[v]+val[x]+val[y]);
				}
			}
		}
	}
	printf("%lld",ans);
	return 0;
}
