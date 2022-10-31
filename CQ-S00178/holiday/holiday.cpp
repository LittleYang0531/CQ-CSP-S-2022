#include <bits/stdc++.h>
using namespace std;
const int M=10005,N=2505,INF=0x3f3f3f3f;
typedef pair<int,int> PII;
struct node{
	int to,next,len;
}a[M];
int n,m,k;
int pre[M],b[N];
int idx=0,aa;
void add(int u,int v){
	idx++;
	a[idx].to=v;
	a[idx].next=pre[u];
	a[idx].len=1;
	pre[u]=idx;
}
int dis[N];
bool vis[N];
priority_queue<PII>heap;
bool dfs(int s,int t){
	memset(dis,0x3f,sizeof(dis));
	dis[s]=-1;
	queue<int>q;
	q.push(s);
	while(!q.empty()){
		int h=q.front();
		q.pop();
		if(h==t){
			return dis[t];
		}
		for(int i = pre[h];i;i=a[i].next){
			int to=a[i].to;
			if(dis[h]+a[i].len<dis[to]){
				dis[to]=dis[h]+a[i].len;
				if(!vis[to])q.push(to);
				vis[to]=true;
			}
		}	
	}
}
void bfs(int s,int ans,int d){
	if(d==4){
		if(dfs(s,1)<=k){
			aa=max(aa,ans);
		}
		return;
	}
	while(!heap.empty()){
		int ma=heap.top().first,h=heap.top().second;
		heap.pop();
		if(dfs(s,ma)<=k){
			ans+=ma;
			bfs(ma,ans,d+1);
		}
	}
}
int main(){
	freopen("holiday.in","r",stdin);
	freopen("holiday.out","w",stdout);
	scanf("%d%d%d",&n,&m,&k);
	for(int i = 2;i <=n;i++){
		scanf("%d",&b[i]);
	}
	int x,y;
	for(int i = 1;i <=m;i++){
		scanf("%d%d",&x,&y);
		add(x,y);
		add(y,x);
	}
	for(int i = 2;i<=n;i++){
		heap.push({b[i],i});
	}
	bfs(1,0,0);
	printf("%d",aa);
}
