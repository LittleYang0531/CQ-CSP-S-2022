#include<map>
#include<queue>
#include<cstdio>
using namespace std;
const int N=200005;
int n,m,K,x,y;
int a[N];
int ver[N],edge[N],Next[N],head[N],len;
map<pair<int,int>,long long int> dis;
int vis[N];
void add(int x,int y,int z){
	ver[++len]=y,edge[len]=z,Next[len]=head[x],head[x]=len;
}
bool flag[N];
map<pair<int,int>,int> Find;
int len_Find[N];
bool flag_Find[N][2];
priority_queue<pair<int,int> > q;
void Do(int XX,int k,int s){
//	printf("{%d %d %d}\n",XX,k,s);
	if(k==0){
//		flag_Find[x][1]=1;
		
		return ;
	}
	for(int i=head[XX];i;i=Next[i]){
		
		if(flag_Find[ver[i]][1]==0){
			flag_Find[ver[i]][1]=1;
			Find[make_pair(s,++len_Find[s])]=ver[i];
			Do(ver[i],k-1,s);
			flag_Find[ver[i]][1]=0;
		}
	}
}
void Dijkstra(int Begin,int k){
	for(int i=1;i<=n;i++){
		dis[make_pair(Begin,i)]=1000000000000000,vis[i]=0;
	}
	dis[make_pair(Begin,Begin)]=a[Begin],q.push(make_pair(1,Begin));
	while(!q.empty()){
		int xx=q.top().second;
		q.pop();
		if(vis[xx]){
			continue;
		}
		vis[xx]=1;
		if(flag_Find[xx][0]==0){
			flag_Find[xx][0]=1;
			for(int i=1;i<=N;i++){
				flag_Find[xx][1]=0;
			}
			Do(xx,K,xx);
		}
		for(int i=1;i<=len_Find[xx];i++){
//			printf("[%d %d]\n",xx,Find[make_pair(xx,i)]);
			int yy=Find[make_pair(xx,i)],zz=a[Find[make_pair(xx,i)]];
			if(dis[make_pair(Begin,yy)]>dis[make_pair(Begin,xx)]+zz){
				dis[make_pair(Begin,yy)]=dis[make_pair(Begin,xx)]+zz,q.push(make_pair(-dis[make_pair(Begin,yy)],yy));
			}
		}
	}
}
int main(){
	freopen("transmit.in","r",stdin);
	freopen("transmit.out","w",stdout);
	scanf("%d%d%d",&n,&m,&K);
		for(int i=1;i<=n;i++){
			scanf("%d",&a[i]);
		}
		for(int i=1;i<n;i++){
			scanf("%d%d",&x,&y);
			add(x,y,a[y]),add(y,x,a[x]);
		}
		for(int i=1;i<=m;i++){
			scanf("%d%d",&x,&y);
			if(flag[x]==0){
				flag[x]=1;
				Dijkstra(x,0);
			}
			printf("%lld\n",dis[make_pair(x,y)]);
		}
	return 0;
}
