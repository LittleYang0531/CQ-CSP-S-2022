#include<algorithm>
#include<utility>
#include<cstdio>
#include<vector>
#include<queue>
namespace burningContract{
typedef std::pair<int,int> pii;
typedef long long ll;
ll read(){
	ll x=0,tp=1;
	char ch=getchar();
	while(ch>'9'||ch<'0'){
		if(ch=='-')tp=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9'){
		x=x*10+ch-48;
		ch=getchar();
	}
	return x*tp;
}
void print(ll x){
	if(x>9)print(x/10);
	putchar(x%10+48);
	return;
}
void write(ll x,char ch){
	if(x<0)putchar('-'),write(-x,ch);
	else print(x),putchar(ch);
	return;
}
const int maxn=2.5e3+5;
const int edgm=2e4+5;
struct edge{
	int to;
	int next;
}qxx[edgm];
int qxx_cnt,h[maxn];
void add(int x,int y){
	qxx[++qxx_cnt]=(edge){y,h[x]};
	h[x]=qxx_cnt;
	return;
}
void ad(int x,int y){
	add(x,y);
	add(y,x);
	return;
}
int n,m,k;
ll val[maxn];
bool can[maxn][maxn];
ll mx[maxn],smx[maxn],tmx[maxn];
int mid[maxn],sid[maxn],tid[maxn];
ll ans;
void go(int i,int j,int k,int l){
	if(!k||!l)return;
	if(i!=j&&i!=k&&i!=l&&j!=k&&j!=l&&k!=l)
		ans=std::max(ans,val[i]+val[j]+val[k]+val[l]);
	return;
}
std::queue<pii>qu;
int dis[maxn];
bool vis[maxn];
void dij(int s){
	for(int i=1;i<=n;i++)dis[i]=n+1,vis[i]=false;
	qu.push((pii){0,s});
	while(!qu.empty()){
		pii now=qu.front();
		qu.pop();
		if(vis[now.second])continue;
		can[s][now.second]=true;
		dis[now.second]=now.first;
		if(now.first==k)continue;
		for(int i=h[now.second];i;i=qxx[i].next){
			int v=qxx[i].to;
			if(dis[v]>dis[now.second]+1){
				dis[v]=dis[now.second]+1;
				qu.push((pii){dis[v],v});
			}
		}
	}
	return;
}
signed main(){
	freopen("holiday.in","r",stdin);
	freopen("holiday.out","w",stdout);
	scanf("%d%d%d",&n,&m,&k),k++;
	for(int i=2;i<=n;i++)scanf("%lld",val+i);
	for(int i=1;i<=m;i++){
		int x,y;
		scanf("%d%d",&x,&y);
		ad(x,y);
	}
	for(int i=1;i<=n;i++)dij(i);
//	for(int i=1;i<=n;i++)for(int j=1;j<=n;j++)printf("can[%d][%d]=%d\n",i,j,can[i][j]?1:0);
	for(int i=2;i<=n;i++)for(int j=2;j<=n;j++)if(i!=j){
		if(!can[1][j]||!can[j][i])continue;
		if(val[j]>=mx[i])tmx[i]=smx[i],tid[i]=sid[i],smx[i]=mx[i],sid[i]=mid[i],mx[i]=val[j],mid[i]=j;
		else if(val[j]>=smx[i])tmx[i]=smx[i],tid[i]=sid[i],smx[i]=val[j],sid[i]=j;
		else if(val[j]>tmx[i])tmx[i]=val[j],tid[i]=j;
	}
	for(int i=2;i<=n;i++)for(int j=2;j<=n;j++)if(i!=j){
		if(!can[i][j])continue;
		go(i,j,mid[i],mid[j]);
		go(i,j,mid[i],sid[j]);
		go(i,j,mid[i],tid[j]);
		go(i,j,sid[i],mid[j]);
		go(i,j,sid[i],sid[j]);
		go(i,j,sid[i],tid[j]);
		go(i,j,tid[i],mid[j]);
		go(i,j,tid[i],sid[j]);
		go(i,j,tid[i],tid[j]);
	}
	printf("%lld",ans);
	return 0;
}
//namespace burningContract
}
signed main(){return burningContract::main();}
