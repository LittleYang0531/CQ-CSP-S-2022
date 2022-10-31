#include<cstdio>
#include<vector>
#include<iostream>
#include<cstring>
#include<algorithm>
#include<queue>
#define PII pair<int,int>
#define N 2505
#define M 10005
#define ll long long
#define INF_INT 0x3f3f3f3f
using namespace std;
char c;
int flag=1;
inline void rd(int &x){
	x=0;
	flag=1;
	c=getchar();
	while((c<'0'||c>'9')&&c!='-')c=getchar();
	if(c=='-')c=getchar(),flag=-1;
	while(c>='0'&&c<='9'){
		x=(x<<1)+(x<<3)+c-48;
		c=getchar();
	}
	x*=flag;
}
struct edge{
	int to,nxt;
}e[M*2];
int n,m,K,cnt,x,y;
int h[N];
ll a[N],sum[N],f[10][N],pd[10][N];
ll ans;
int g[N][N],d[N][N];
bool vis[N],bj[N];
priority_queue< PII >q;
vector<int>v[N];
inline void add(int x,int y){
	e[++cnt].to=y;
	e[cnt].nxt=h[x];
	h[x]=cnt;
}
void dij(int v0){
	for(int i=1;i<=n;i++)d[v0][i]=INF_INT;
	memset(vis,0,sizeof(vis));
	q.push(make_pair(0,v0));
	d[v0][v0]=0;
	while(!q.empty()){
		x=q.top().second;
		q.pop();
		if(vis[x])continue;
		vis[x]=1;
		for(int i=h[x];i;i=e[i].nxt){
			y=e[i].to;
			if(d[v0][y]>=d[v0][x]+1&&d[v0][x]+1<=K){
				d[v0][y]=d[v0][x]+1;
//				v[v0].push_back(y);
				q.push(make_pair(-d[v0][y],y));
			}
		}
	}
}
void dfs(int kk,int v0,ll sum){
	if(kk==5){
		if(d[v0][1]<=K&&sum>ans)
			ans=sum;
		return ;
	}
	for(int i=2;i<=n;i++){
		if(d[v0][i]<=K&&!bj[i]){
			bj[i]=1;
			dfs(kk+1,i,sum+a[i]);
			bj[i]=0;
		}
	}
}
int main(){
	freopen("holiday.in","r",stdin);
	freopen("holiday.out","w",stdout);
	cin>>n>>m>>K;
	K++;
	for(int i=2;i<=n;i++)
		scanf("%lld",&a[i]);
//	memset(f,0x3f,sizeof(f));
	for(int i=1;i<=m;i++){
		rd(x),rd(y);
		add(x,y),add(y,x);
	}
	for(int i=1;i<=n;i++)
		dij(i);
//	for(int i=1;i<=n;i++){
//		for(int j=1;j<=n;j++){
//			printf("%d,%d %d\n",i,j,d[i][j]);
//		}
//		puts("");
//	}
//	for(int i=1;i<=4;i++){
//		for(int j=1;j<=n;j++)
//			cout<<f[i][j]<<" ";
//		puts("");
//	}
	dfs(1,1,0);	
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
