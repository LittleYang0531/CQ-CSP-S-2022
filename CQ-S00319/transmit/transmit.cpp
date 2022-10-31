#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
typedef long long ll;
const int N=2e5+10;
struct Gragh{
	int elast[N],idx;
	struct path{
		int en,nex;
	}a[N<<1];
	void add(int x,int y){
		a[++idx]=(path){y,elast[x]};
		elast[x]=idx;
	}
}G1,G2;
inline int read(){
	int x=0;
	bool flag=false;
	char ch=getchar();
	while(ch>'9'||ch<'0'){
		if(ch=='-')flag=true;
		ch=getchar();
	}
	while(ch<='9'&&ch>='0'){
		x=(x<<1)+(x<<3)+(ch^48);
		ch=getchar();
	}
	if(flag)return -x;
	return x;
}
int n,q,k;
ll dist[N];
int v[N];
void dfs(int u,int fa){
	dist[u]=dist[fa]+v[u];
	int y;
	for(int i=G1.elast[u];i;i=G1.a[i].nex){
		y=G1.a[i].en;
		if(y==fa)continue;
		dfs(y,u);
	}
}
bool map[N];
void dfs1(int sta,int p,int tmp){
	if(tmp>k)
		return;
	G2.add(sta,p);
	map[p]=1;
	for(int i=G1.elast[p];i;i=G1.a[i].nex){
		int q=G1.a[i].en;
		if(!map[q])
			dfs1(sta,q,tmp+1);
	}
}
struct point{
	int p;
	ll dis;
	bool operator<(const point &t)const{
		return dis<t.dis;
	}
};
struct priority{
	point c[N];
	int n;
	void clear(){n=0;}
	void push(point x){
		c[++n]=x;
		int d=n;
		while(d>1){
			if(c[d]<c[d>>1]){
				swap(c[d],c[d>>1]);
				d>>=1;
			}
			else
				break;
		}
	}
	void pop(){
		c[1]=c[n--];
		int d=1;
		while(d<<1<n){
			if(c[d<<1]<c[d]||c[d<<1|1]<c[d]){
				if(c[d<<1]<c[d<<1|1]){
					swap(c[d],c[d<<1]);
					d<<=1;
				}
				else{
					swap(c[d],c[d<<1|1]);
					d=d<<1|1;
				}
			}
			else break;
		}
		if(d<<1==n&&c[n]<c[d])
			swap(c[n],c[d]);
	}
	bool not_empty(){return n>0;}
	point top(){
		return c[1];
	}
}u;
ll dis[N];
bool vis[N];
void Dijkstra(int s,int t){
	u.clear();
	memset(dis,0x3f,sizeof dis);
	memset(vis,0,sizeof vis);
	u.push((point){s,v[s]});
	dis[s]=v[s];
	while(u.not_empty()){
		int x=u.top().p;
		u.pop();
		if(x==t)break;
		if(vis[x])continue;
		vis[x]=1;
		for(int i=G2.elast[x];i;i=G2.a[i].nex){
			int y=G2.a[i].en;
			if(dis[x]+v[y]<dis[y]){
				dis[y]=dis[x]+v[y];
				u.push((point){y,dis[y]});
			}
		}
	}
}
int main(){
	freopen("transmit.in","r",stdin);
	freopen("transmit.out","w",stdout);
	n=read(),q=read(),k=read();
	for(int i=1;i<=n;i++)
		v[i]=read();
	int x,y;
	for(int i=1;i<n;i++){
		x=read(),y=read();
		G1.add(x,y),G1.add(y,x);
	}
	if(k==1){
		dfs(1,0);
		while(q--){
			x=read(),y=read();
			printf("%lld\n",dist[x]+dist[y]-v[1]);
		}
		return 0;
	}
	for(int i=1;i<=n;i++){
		memset(map,0,sizeof map);
		dfs1(i,i,0);
	}
	while(q--){
		x=read(),y=read();
		Dijkstra(x,y);
		printf("%lld\n",dis[y]);
	}
	return 0;
} 
