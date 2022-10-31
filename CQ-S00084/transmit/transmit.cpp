#include<bits/stdc++.h>
#define int long long
#define pii pair<int,int>
#define fi first
#define se second
#define il inline
#define ct const
#define dl double
#define pk push_back
#define N 200010
using namespace std;
il int read(){
	int x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){
		if(ch=='-') f=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9'){
		x=(x<<1)+(x<<3)+(ch^48);
		ch=getchar();
	}
	return x*f;
}
il void write(int x){
	int cnt=0;char f[40];
	if(!x) putchar('0');
	if(x<0){
		x=-x;putchar('-');
	}
	while(x){
		f[cnt++]=x%10+'0';x/=10;
	}
	while(cnt) putchar(f[--cnt]);
	putchar('\n');
}
int head[N],nxt[N<<1],to[N<<1],t;
il void add(int u,int v){
	nxt[++t]=head[u];head[u]=t;to[t]=v;
	nxt[++t]=head[v];head[v]=t;to[t]=u;
}
int n,q,K,val[N],dis[N];
vector<int> e[N];
queue<int> Q;
struct node{
	int x,dis;
	il bool operator<(ct node &y)ct{
		return dis>y.dis;
	}
};
priority_queue<node> P;
il void bfs(int x){
	for(int i=1;i<=n;++i) dis[i]=1e18;
	dis[x]=0;Q.push(x);
	while(!Q.empty()){
		int y=Q.front();Q.pop();
		if(y!=x) e[x].pk(y);
		if(dis[y]==K) continue;
		for(int i=head[y];i;i=nxt[i])
			if(dis[to[i]]>dis[y]+1){
				dis[to[i]]=dis[y]+1;Q.push(to[i]);
			}
	}
}
bool vis[N];
il void dijstra(int s,int t){
	for(int i=1;i<=n;++i) dis[i]=1e18,vis[i]=0;
	while(!P.empty()) P.pop();
	dis[s]=val[s];P.push((node){s,0});
	while(!P.empty()){
		int x=P.top().x;P.pop();
		if(x==t) return;
		if(vis[x]) continue;
		vis[x]=1;
		for(auto i:e[x])
			if(dis[i]>dis[x]+val[i]){
				dis[i]=dis[x]+val[i];P.push((node){i,dis[i]});
			}
	}
}
signed main(){
	freopen("transmit.in","r",stdin);
	freopen("transmit.out","w",stdout);
	n=read();q=read();K=read();
	for(int i=1;i<=n;++i) val[i]=read();
	for(int i=1;i<n;++i) add(read(),read());
	for(int i=1;i<=n;++i) bfs(i);
	while(q--){
		int s=read(),t=read();
		dijstra(s,t);
		write(dis[t]);
	}
	return 0;
}

