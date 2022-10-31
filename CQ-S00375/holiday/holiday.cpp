#include<bits/stdc++.h>
#define ll long long
#define re register
using namespace std;
const int qwe=1e4+4,qw=2504;
struct node{
	int to,net;
}e[qwe<<1];int h[qw],cnt;
void add(int x,int y){
	e[++cnt].to=y;
	e[cnt].net=h[x];
	h[x]=cnt;
}
int n,m,k,a[qw];
vector<int>b[qw];//能与i到达 
int dis[qw];bool vis[qw];
struct node2{
	int val,id;
	bool operator<(const node2 &jk)const{
		return jk.val<val;
	}
};
priority_queue<node2>q;
void djstl(int fa){
	for(re int i=1;i<=n;++i)dis[i]=114514,vis[i]=0;
	dis[fa]=0;q.push((node2){0,fa});
	while(q.size()){
		node2 u=q.top();q.pop();
		if(vis[u.id]||u.val>=100)continue;
		vis[u.id]=1;
		for(int i=h[u.id];i;i=e[i].net){
			int v=e[i].to;
			if(dis[v]>dis[u.id]+1){
				dis[v]=dis[u.id]+1;
				q.push((node2){dis[v],v});
			}
		}
	}
}
int ans,viss[qw];
void dfs(int x,int cnt,int yu){
	if(yu==5&&x==1){
		ans=max(ans,cnt);
		return;
	}
	if(yu>=5)return;
	if(yu==4){
		if(b[x][0]==1&&viss[1]==0){
			viss[1]=1;	
			dfs(1,cnt,yu+1);
			viss[1]=0;
		}
		return;
	}
	for(int i=0;i<(int)b[x].size();++i){
		if(viss[b[x][i]]==0){
			viss[b[x][i]]=1;	
			dfs(b[x][i],cnt+a[b[x][i]],yu+1);
			viss[b[x][i]]=0;
		}
	}
}
int main(){
	freopen("holiday.in","r",stdin);
	freopen("holiday.out","w",stdout);
	scanf("%d%d%d",&n,&m,&k);
	a[1]=0;
	for(re int i=2;i<=n;++i)scanf("%d",&a[i]);
	int x,y;
	for(re int i=1;i<=m;++i){
		scanf("%d%d",&x,&y);
		add(x,y);add(y,x);
	}
	for(int i=1;i<=n;++i){
		djstl(i);
		for(int j=1;j<=n;++j)
			if(i!=j){
				if(dis[j]-1<=k){
					b[i].push_back(j);
				}
			}
	}
	dfs(1,0,0);
	printf("%d",ans);
	return 0;
}
