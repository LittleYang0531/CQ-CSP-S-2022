#include<bits/stdc++.h>
#include<climits>
#define aSide OK[a][aNow] 
#define bSide OK[b][bNow] 
using namespace std;
//一个人只有站在了悬崖边上才会真正坚强起来
//sto duanyixiu orz
//sto cool_milo orz
//sto tanyulin orz
//注意long long
//注意 (x^1) 优先级
//注意freopen
const int N=2520,M=10010;
typedef long long LL;
typedef pair<int,int> PII;
int h[N],e[2*M],ne[2*M],idx;
int n,m,k;
LL w[N];
int dist[N][N];
bool vis[N];
bool ifOK[N];//距离a点的距离是否小于等于k+1
vector<int> OK[N];
vector<PII> group;
bool ansVis[N][N];
long long ans;


void add(int a,int b){
	e[idx]=b;
	ne[idx]=h[a];
	h[a]=idx++;
}

void dijkstra(int point){
	queue<PII > que;
//	vis[point]=true;
	dist[point][point]=0;
	que.push({0,point});
	while(!que.empty()){
		PII tmp=que.front();
		que.pop();
		int distance=tmp.first;
		int TP=tmp.second;
		if(vis[TP]) continue;
		vis[TP]=true;
		for(int i=h[TP];i!=-1;i=ne[i]){
			int j=e[i];
			if(dist[point][j]>distance+1){
				dist[point][j]=distance+1;
				if(!vis[j]) que.push({dist[point][j],j});
			}
		}
	}
	 
} 


bool cmp(int a,int b){
	return w[a]>w[b];
}

int main(){
	freopen("holiday.in","r",stdin);
	freopen("holiday.out","w",stdout);
	memset(h,-1,sizeof h);
	scanf("%d%d%d",&n,&m,&k);
	for(int i=2;i<=n;i++) scanf("%lld",&w[i]);
	for(int i=1;i<=m;i++){
		int a,b;
		scanf("%d%d",&a,&b);
		add(a,b);
		add(b,a);
	}
	for(int i=1;i<=n;i++) dist[1][i]=INT_MAX,vis[i]=false;
	dist[1][1]=0;
	dijkstra(1);
	
//	for(int i=1;i<=n;i++) printf("%d ",dist[1][i]);
//	puts("");
	
	for(int i=2;i<=n;i++) if(dist[1][i]<=k+1) ifOK[i]=true;
	
//	for(int i=1;i<=n;i++) printf("%d ",ifOK[i]);
//	puts("");
	for(int i=2;i<=n;i++){
		
//		printf("###%d\n",i);
		
		for(int j=1;j<=n;j++) dist[i][j]=INT_MAX,vis[j]=false;
		dist[i][i]=0;
		dijkstra(i);
		
//		for(int j=1;j<=n;j++) printf("%d ",dist[i][j]);
//		puts("");
		
		for(int j=1;j<=n;j++){
			if(i==j) continue;
			if(ifOK[j]&&dist[i][j]<=k+1) OK[i].push_back(j);
			if(dist[i][j]<=k+1) group.push_back({i,j});
		}
	}
	ans=LONG_LONG_MIN;
	for(int i=2;i<=n;i++){
		sort(OK[i].begin(),OK[i].end(),cmp);
	}
	for(int i=0;i<(int)group.size();i++){
		PII tmp=group[i];
		int a=tmp.first,b=tmp.second;
		if(a>b) swap(a,b);
		if(ansVis[a][b]) continue;
		ansVis[a][b]=true;
		if(OK[a].empty()||OK[b].empty()) continue;//没有 
		//a取最大值或b取最大值的时候
		//a最大
		int aNow=0,bNow=0;
		if(aSide==b){
			aNow++;
			if((int)OK[a].size()<=aNow) continue;
		}
		if(bSide==a){
			bNow++;
			if((int)OK[b].size()<=bNow) continue;
		}
		
		if(aSide==bSide){
			if((int)OK[b].size()>bNow+1){
				bNow++;
				ans=max(ans,w[bSide]+w[aSide]+w[a]+w[b]);
				bNow--;
			}
			if((int)OK[a].size()>aNow+1){
				aNow++;
				ans=max(ans,w[bSide]+w[aSide]+w[a]+w[b]);
			}
		}else{
			ans=max(ans,w[bSide]+w[aSide]+w[a]+w[b]);
		}
	}
	printf("%lld",ans);
	return 0;
}

