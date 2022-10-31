#include<stdio.h>
#include<queue>
#include<cstring>
#include<unordered_map>
std::unordered_map<int,int> h;
const int N=2505,M=2e4+5;
struct jie{int to,val,nxt;}a[M];
int n,m,k,head[N],cnt,dis[N][N],z[N],ans,pre[N];
bool vis[N][N];
void add(int x,int y,int z){
	cnt++;
	a[cnt].to=y;
	a[cnt].val=z;
	a[cnt].nxt=head[x];
	head[x]=cnt;
}
struct node{
	int id,val,time;
	bool operator < (const node &x) const{return val<x.val;}
};
void Dijkstra(int s){
	std::memset(dis,-0x3f,sizeof dis);
	std::priority_queue<node> q;
	dis[1][0]=0,q.push({s,dis[s][0],0});
	while(!q.empty()){
		node u=q.top();q.pop();
		if(u.time>8) continue;
		h[u.id]=1;
		for(int i=head[u.id];i;i=a[i].nxt){
			if(h[a[i].to]==true&&h.size()<5) continue;
			if(u.val+a[i].val>dis[a[i].to][u.time+1]) pre[a[i].to]=u.id,dis[a[i].to][u.time+1]=u.val+a[i].val,q.push({a[i].to,dis[a[i].to][u.time+1],u.time+1}),vis[u.id][a[i].to]=true;
		}
	}
}
int main(){
	freopen("holiday.in","r",stdin);
	freopen("holiday.out","w",stdout);
	scanf("%d%d%d",&n,&m,&k);
	for(int i=2;i<=n;i++) scanf("%d",&z[i]);
	int x,y;
	while(m--) scanf("%d%d",&x,&y),add(x,y,z[y]),add(y,x,z[x]);
	if(!k){
		Dijkstra(1);
		printf("%d",dis[1][8]);
	}
	return 0;
}
