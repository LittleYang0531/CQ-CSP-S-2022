#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=25e2+10,M=1e4+10;
struct node{
	int to,nxt;
}e[M<<1];
int head[N],cnt;
void add(int u,int v){
	e[++cnt].nxt=head[u];
	e[cnt].to=v;
	head[u]=cnt;
}
ll a[N];
int n,m,k,vis[25],d1[N];
ll ans;
void dfs(int p,int vv[],int cnt,int dis,ll s){
	if(cnt>4)return;
	if(dis==k+1)return;
	if(cnt==4){
		if(d1[p]-1<=k)ans=max(ans,s);
		return;
	}
	for(int i=head[p];i;i=e[i].nxt){
		int v=e[i].to;
		if(v==1)continue;
		if(!vv[v])vv[v]=1,dfs(v,vv,cnt+1,0,s+a[v]),vv[v]=0;
		dfs(v,vv,cnt,dis+1,s);
	}
}
void solve1(){
	dfs(1,vis,0,0,0);
	printf("%lld",ans);
}
int vv[N];
void dist(){
	queue<int>q;
	q.push(1);
	memset(d1,0x3f,sizeof(d1));
	d1[1]=0;
	while(!q.empty()){
		int x=q.front();
		q.pop();
		vv[x]=0;
		for(int i=head[x];i;i=e[i].nxt){
			int v=e[i].to;
			if(d1[v]>d1[x]+1){
				d1[v]=d1[x]+1;
				if(!vv[v]){
					vv[v]=1;
					q.push(v);
				}
			}
		}
	}
}
struct h{
	ll val;
	int id;
};
int Vis[N][N];
void solve2(){
	vector<h>c,c2;
	for(int i=head[1];i;i=e[i].nxt){
		int v=e[i].to;
		c.push_back((h){a[v],v});
	}
	for(int i=0;i<c.size();i++){
		int x=c[i].id;
		for(int j=head[x];j;j=e[j].nxt){
			int v=e[j].to;
			if(v!=1)
			c2.push_back((h){a[v]+a[x],v});
		}
	}
	ll ans=0;
	for(int i=0;i<c2.size();i++){
		for(int j=i+1;j<c2.size();j++){
			if(Vis[c2[i].id][c2[j].id])ans=max(ans,c2[i].val+c2[j].val);
		}
	}
	printf("%lld\n",ans);
}
int main(){
	freopen("holiday.in","r",stdin);
	freopen("holiday.out","w",stdout);
	scanf("%d%d%d",&n,&m,&k);
	for(int i=2;i<=n;i++){
		scanf("%lld",&a[i]);
	}
	for(int i=1;i<=m;i++){
		int x,y;
		scanf("%d%d",&x,&y);
		Vis[x][y]=Vis[y][x]=1;
		add(x,y),add(y,x);
	}
	dist();
	if(n<=20){
		solve1();
		return 0;
	}
	if(k==0){
		solve2();
	}
	return 0;
}
