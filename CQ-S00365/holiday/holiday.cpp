#include<bits/stdc++.h>
using namespace std;
#define ll long long 

int read(){
	int x=0,f=1;
	char c=getchar();
	while(c<'0'||c>'9'){ if(c=='-') f=-1;c=getchar(); }
	while('0'<=c&&c<='9') x=(x<<1)+(x<<3)+c-'0',c=getchar();
	return x*f;
}

void File(){
	freopen("holiday.in","r",stdin);
	freopen("holiday.out","w",stdout);
}

vector<int> v[2505];
int a[2505];
bool f[20005];
bool vis[20005];
int n,m,k;
int ans=0;

void DFS(int x,int step,int sum){
	if(step==4){
		if(f[x]) ans=max(ans,sum);
		return ;
	}
	vis[x]=1;
	for(auto y:v[x]) if(!vis[y]) DFS(y,step+1,sum+a[y]);
	vis[x]=0;
}

signed main(){
	File();
	cin>>n>>m>>k;
	for(int i=2;i<=n;i++) scanf("%lld",&a[i]);
	for(int i=1,x,y;i<=m;i++) scanf("%d%d",&x,&y),v[x].push_back(y),v[y].push_back(x),f[x]|=(y==1),f[y]|=(x==1);
	vis[1]=1;DFS(1,0,0);
	cout<<ans<<endl;

	return 0;
}
/*
#include<bits/stdc++.h>
#include<queue>
using namespace std;
#define ll long long 
#define int ll
#define pii pair<int,int> 
#define MP make_pair
#define fis first
#define sec second

int read(){
	int x=0,f=1;
	char c=getchar();
	while(c<'0'||c>'9'){ if(c=='-') f=-1;c=getchar(); }
	while('0'<=c&&c<='9') x=(x<<1)+(x<<3)+c-'0',c=getchar();
	return x*f;
}

void File(){
	freopen(".in","r",stdin);
	freopen(".out","w",stdout);
}

int a[2505];
bool f[200005];
bool vis[20005];
int n,m,k;
int ans=0;

struct zz{
	int u,w;
};

vector<int> v[2505];
vector<zz> V[20005];
int dep[2505];
bool xpx[2505][2505];

void BFS(int s){
	memset(dep,-1,sizeof dep);
	dep[s]=0;
	queue<int> q;q.push(s);
	while(q.size()){
		int x=q.front();q.pop();
		if(dep[x]>k) break;
		for(auto y:v[x]) if(dep[y]==-1) dep[y]=dep[x]+1,q.push(y);
	}
//	printf("%d:",s);for(int i=1;i<=n;i++) printf("%d ",dep[i]);
//	cout<<endl;
	if(s==1){
		for(int y=1;y<=n;y++) if(dep[y]!=-1&&dep[y]<=k&&a[y]&&dep[y]) 
			V[1].push_back((zz){y,a[y]}),f[y+n+n+n]=1;
		return ;
	}
	for(int y=1;y<=n;y++) if(dep[y]!=-1&&dep[y]<=k&&a[y]&&dep[y]&&!xpx[s][y]){
		V[s].push_back((zz){y+n,a[y]});
		V[s+n].push_back((zz){y+n+n,a[y]});
		V[s+n+n].push_back((zz){y+n+n+n,a[y]});
		xpx[s][y]=xpx[y][s]=1;
		if(y==1) f[s+n+n+n]=1;
	}
}

bool cmp(int x,int y){
	return a[x]>a[y];
}

int dp[100000];
int pre[2505];
void Dijkstra(int s){
	memset(dp,-1,sizeof dp);
	dp[s]=0;
	priority_queue< pii > q; q.push(MP(dp[s],s));
	while(!q.empty()){
		auto now=q.top();q.pop();
		int x=now.sec;
//		printf("kk:::%d:%d\n",x,V[x].size());
		for(auto now:V[x]) if(dp[now.u]==-1){
			int y=now.u,w=now.w;
			dp[y]=dp[x]+w,q.push(MP(dp[y],y));
		}
	}
//	for(int i=1;i<=4*n;i++) printf("%d:%d\n",i,dp[i]);
	for(int i=3*n+1;i<=4*n;i++) if(f[i]) ans=max(ans,dp[i]),printf(":::::::%d:%d\n",i-3*n,dp[i]);
}

signed main(){
	cin>>n>>m>>k;k++;
	for(int i=2;i<=n;i++) scanf("%lld",&a[i]),pre[i]=i;
	sort(a+1,a+n+1);
	for(int i=1,x,y;i<=m;i++) scanf("%lld%lld",&x,&y),v[x].push_back(y),v[y].push_back(x);
	BFS(1);
	for(int i=1;i<n;i++) BFS(pre[i]);
//	for(int i=1;i<=4*n;i++) if(f[i]) printf("qwqqwqqq2q:::%d\n",i-3*n);
	Dijkstra(1);
	cout<<ans<<endl;
	return 0;
}
*/

