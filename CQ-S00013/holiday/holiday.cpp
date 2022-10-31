#include<iostream>
#include<algorithm>
#include<cstring>
#include<cstdio>
#include<vector>
#include<queue>
using namespace std;
#define N 2512
#define LL long long
#define INF 0x3f3f3f3f
int n,m,K,dis[N],h[N],cnt=0;LL a[N];bool ca[N][N];
struct Edge{int to,next;}e[N<<3];
inline void AddEdge(int x,int y){e[++cnt]=(Edge){y,h[x]};h[x]=cnt;}
queue<int>q;
void bfs(int v0)
{
	int i,x,y;memset(dis,0x3f,sizeof(dis));q.push(v0);dis[v0]=0;
	while(!q.empty())
	{
		x=q.front();q.pop();
		for(i=h[x];i;i=e[i].next)if(dis[y=e[i].to]==INF){dis[y]=dis[x]+1;q.push(y);}
	}
	for(i=1;i<=n;i++)ca[v0][i]=(dis[i]<=(K+1));
}
vector<int>son[N];LL ans=0;
inline bool cmp(int x,int y){return a[x]>a[y];}
int main(){
	freopen("holiday.in","r",stdin);
	freopen("holiday.out","w",stdout);
	scanf("%d%d%d",&n,&m,&K);int i,j,x,y,u1,u2,z,w;
	for(i=2;i<=n;i++)scanf("%lld",&a[i]);
	for(i=1;i<=m;i++){scanf("%d%d",&x,&y);AddEdge(x,y);AddEdge(y,x);}
	for(i=1;i<=n;i++)bfs(i);
	for(x=2;x<=n;x++)
	for(y=2;y<=n;y++)if((y!=x)&&ca[x][y]&&ca[1][y])son[x].push_back(y);
	for(x=2;x<=n;x++)sort(son[x].begin(),son[x].end(),cmp);
	for(x=2;x<=n;x++)
	for(y=x+1;y<=n;y++)
	if(ca[x][y])
	{
		u1=min((int)son[x].size(),5);
		u2=min((int)son[y].size(),5);
		for(i=0;i<u1;i++)
		for(j=0;j<u2;j++)
		{
			z=son[x][i];w=son[y][j];
			if((z!=y)&&(w!=x)&&(z!=w))ans=max(ans,a[x]+a[y]+a[z]+a[w]);
		}
	}
	printf("%lld",ans);return 0;
}
