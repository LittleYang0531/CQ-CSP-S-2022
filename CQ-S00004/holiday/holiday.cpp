#include<queue>
#include<cstdio>
#include<algorithm>
using namespace std;
const int N=100005*2;
int n,m,k,x,y;
long long int ans;
long long int a[2505];
int ver[N],Next[N],head[N],len;
long long int edge[N];
int dis[2505][2505],vis[2505];
void add(int x,int y,long long int z){
	ver[++len]=y,edge[len]=z,Next[len]=head[x],head[x]=len;
}
priority_queue<pair<int,int> > q;
long long int read(){
	long long int a=1,b=0;
	char ch=getchar();
	while(ch<'0'||ch>'9'){
		a=ch=='-'?-1:1,ch=getchar();
	}
	while(ch>='0'&&ch<='9'){
		b=(b<<1)+(b<<3)+ch-'0',ch=getchar();
	}
	return a*b;
}
void Dijkstra(int Begin){
	for(int i=1;i<=n;i++){
		dis[Begin][i]=0x3f3f3f3f,vis[i]=0;
	}
	dis[Begin][Begin]=-1,q.push(make_pair(1,Begin));
	while(!q.empty()){
		int xx=q.top().second;	
		q.pop();
		if(vis[xx]){
			continue;
		}
		vis[xx]=1;
		for(int i=head[xx];i;i=Next[i]){
			int yy=ver[i],zz=edge[i];
//			printf("[%d %d %d]\n",xx,yy,zz);
			if(dis[Begin][yy]>dis[Begin][xx]+zz){
				dis[Begin][yy]=dis[Begin][xx]+zz,q.push(make_pair(-dis[Begin][yy],yy));
			}
		}
	}
}
bool OK[2505];
void dfs(int num,long long int sum,int s){
//	printf("%d %d %d\n",num,sum,s);
	if(num==4){
		if(dis[s][1]<=k&&s!=1){
			ans=max(ans,sum);
		}
		return ;
	}
	for(int i=head[s];i;i=Next[i]){
//		printf("[[%d %d]]\n",i,ver[i]);
		if(!OK[ver[i]]){
			OK[ver[i]]=1,dfs(num+1,sum+edge[i],ver[i]),OK[ver[i]]=0;
		}
	}
}
int main(){
	freopen("holiday.in","r",stdin);
	freopen("holiday.out","w",stdout);
	n=read(),m=read(),k=read(); 
	for(int i=2;i<=n;i++){
		a[i]=read();
	}
	for(int i=1;i<=m;i++){
		x=read(),y=read(),add(x,y,1),add(y,x,1);
	}
	for(int i=1;i<=n;i++){
		Dijkstra(i);
	}
	len=0;
	for(int i=0;i<N;i++){
		edge[i]=Next[i]=ver[i]=head[i]=0;
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(i==j){
				continue;
			}
			if(dis[i][j]<=k){
				add(i,j,a[j]);
			}
		}
	}
	dfs(0,0,1);
	printf("%lld",ans);
	return 0;
}
