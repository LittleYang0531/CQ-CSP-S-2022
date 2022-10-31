#include<bits/stdc++.h>
#define ll long long
#define N 500012
#define mkp make_pair
#define pb push_back
using namespace std;
ll read(){
	ll x=0,fl=1; char ch=getchar();
	while(ch<'0'||ch>'9'){ if(ch=='-')fl=-1; ch=getchar();}
	while(ch>='0'&&ch<='9'){ x=x*10+ch-'0'; ch=getchar();}
	return x*fl;
}
int n,m,k,inf=0x3f3f3f3f;
int head[N],to[N],nxt[N],tot;
int dis[N],vis[N];
vector<int> e[N];
ll f[N][5];
int pre[N][5];
ll a[N],ans;

void add(int u,int v){
	nxt[++tot]=head[u];
	to[tot]=v;
	head[u]=tot;
}
priority_queue<pair<int,int>> q;
void dij(int s){
	memset(dis,inf,sizeof(dis));
	memset(vis,0,sizeof(vis));
	dis[s]=0;
	q.push(mkp(0,s));
	while(!q.empty()){
		int u=q.top().second;
		q.pop();
		if(vis[u]) continue;
		vis[u]=1;
		for(int i=head[u];i;i=nxt[i]){
			int v=to[i];
			if(dis[v]>dis[u]+1){
				dis[v]=dis[u]+1;
				if(dis[v]>k+1) continue; 
				q.push(mkp(-dis[v],v));
			}
		}
	}
}
int check(int pri,int prj,int i,int j,ll si,ll sj){
	if(!si||!sj||pri==j||prj==i||pri==prj) return 0;
	else return 1;
}

int main(){
	freopen("holiday.in","r",stdin);
	freopen("holiday.out","w",stdout);
	n=read(),m=read(),k=read();
	for(int i=2;i<=n;i++){
		a[i]=read();
	}
	int u,v;
	for(int i=1;i<=m;i++){
		u=read(),v=read();
		add(u,v); add(v,u);
	}
	for(int i=1;i<=n;i++){
		dij(i);
		for(int j=i+1;j<=n;j++){
			if(dis[j]<=k+1){
				e[i].pb(j); e[j].pb(i);
			}
		}
	}
	for(auto v:e[1]){
		for(auto p:e[v]){
			int x=1,fl=0;
			for(;x<=4;x++){
				if(a[v]>f[p][x]){ fl=1; break;}
			}
			if(!fl) continue;
			for(int i=4;i>x;i--){
				f[p][i]=f[p][i-1],pre[p][i]=pre[p][i-1];
			}
			f[p][x]=a[v],pre[p][x]=v;
		}
	}
	for(int u=2;u<=n;u++){
		for(auto v:e[u]){
			if(v<=u) continue;
			for(int i=1;i<=4;i++){
				for(int j=1;j<=4;j++){
					if(check(pre[u][i],pre[v][j],u,v,f[u][i],f[v][j])){
						ans=max(ans,f[u][i]+f[v][j]+a[u]+a[v]);
					}
				}
			}
		}
	}
	printf("%lld",ans);
	
	return 0;
}
