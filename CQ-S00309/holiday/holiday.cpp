#include<bits/stdc++.h>
using namespace std;
int read(){
	int x=0;char c=getchar();
	while(c>'9'||c<'0')c=getchar();
	while(c>='0'&&c<='9')x=(x<<1)+(x<<3)+(c^'0'),c=getchar();
	return x;
}
int n,m,k,cnt,h[2505],Id[2505];
struct P{
	int id;
	long long s;
	bool operator<(const P &t)const{return s>t.s;}
}a[2505];
struct edge{
	int v,nxt;
}e[20005];
void adde(int u,int v){
	e[++cnt].nxt=h[u];
	h[u]=cnt;
	e[cnt].v=v;
}
long long dis[2505][2505],ans,s[2505];
struct node{
	int x;
	long long k;
	bool operator<(const node &t)const{return k>t.k;}
}tmp;
priority_queue<node>q;
int vis[2505];
void D(){
	for(int Y=1;Y<=n;Y++){
		for(int i=Y;i<=n;i++)dis[Y][i]=4e18+5;
		dis[Y][Y]=0;
		while(!q.empty())q.pop();
		q.push(node({Y,0}));
		while(!q.empty()){
			tmp=q.top();
			q.pop();
			if(vis[tmp.x]==Y)continue;
			vis[tmp.x]=Y;
			for(int i=h[tmp.x];i;i=e[i].nxt){
				if(dis[Y][tmp.x]+1<dis[Y][e[i].v]){
					dis[Y][e[i].v]=dis[Y][tmp.x]+1;
					q.push(node({e[i].v,dis[Y][e[i].v]}));
				}
			}
		} 
	}
}
bool f[2505];
void dfs(int x,int num,long long cnt){
	if(num==4){
		if(dis[1][x]<=k)ans=max(ans,cnt);
		return;
	}
	for(int i=2;i<=n;i++){
		if(!f[Id[i]]){
			if(dis[x][Id[i]]<=k){
				f[Id[i]]=1;
				dfs(Id[i],num+1,cnt+a[i].s);
				f[Id[i]]=0;
			}
		}
	}
}
int main()
{
	freopen("holiday.in","r",stdin);
	freopen("holiday.out","w",stdout);
	n=read();m=read();k=read();
	for(int i=2;i<=n;i++)scanf("%lld",&a[i].s),a[i].id=i,s[i]=a[i].s;
	sort(a+2,a+n+1);
	Id[1]=1;
	for(int i=2;i<=n;i++)Id[i]=a[i].id;
	for(int i=1,u,v;i<=m;i++)u=read(),v=read(),adde(u,v),adde(v,u);
	D();
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++)if(i!=j)dis[i][j]--;
	}
	dfs(1,0,0LL);
	printf("%lld",ans);
	return 0;
}
