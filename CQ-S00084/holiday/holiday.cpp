#include<bits/stdc++.h>
#define int long long
#define pii pair<int,int>
#define fi first
#define se second
#define il inline
#define ct const
#define dl double
#define pk push_back
#define N 2510
#define M 10010
#define K 110
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
}
il void Max(int &a,int b){
	a=max(a,b);
}
int head[N],nxt[M<<1],to[M<<1],t;
il void add(int v,int u){
	nxt[++t]=head[u];head[u]=t;to[t]=v;
	nxt[++t]=head[v];head[v]=t;to[t]=u;
}
int n,m,k,val[N],dis[N][N],id[N],ans=-LONG_LONG_MAX;
vector<int> g[N];
bool vis[N];
il bool cmp(int u,int v){
	return val[u]>val[v];
}
queue<int> Q;
il void bfs(int x){
	Q.push(x);dis[x][x]=0;
	while(!Q.empty()){
		int y=Q.front();Q.pop();
		if(dis[x][y]==k+1) continue;
		for(int i=head[y];i;i=nxt[i])
			if(dis[x][to[i]]>dis[x][y]+1){
				dis[x][to[i]]=dis[x][y]+1;
				Q.push(to[i]);
			}
	}
}
signed main(){
	freopen("holiday.in","r",stdin);
	freopen("holiday.out","w",stdout);
	n=read();m=read();k=read();
	for(int i=2;i<=n;++i){
		val[i]=read();id[i]=i;
	}
	sort(id+2,id+1+n,cmp);
	while(m--) add(read(),read());
	memset(dis,0x3f,sizeof(dis));
	for(int i=1;i<=n;++i) bfs(i);
	for(int i=2;i<=n;++i){
		for(int j=2;j<=n;++j)
			if(id[j]!=i&&id[j]!=1&&dis[1][id[j]]<=k+1&&dis[i][id[j]]<=k+1)
				g[i].pk(id[j]);
	}
	vis[1]=1;
	for(int i=2;i<=n;++i){
		vis[i]=1;
		for(int j=i+1;j<=n;++j)
			if(dis[i][j]<=k+1){
				vis[j]=1;
				int res1=0,res2=0;
				for(auto h:g[i])
					if(!vis[h]){
						res1=h;break;
					}
				if(res1){
					vis[res1]=1;
					for(auto h:g[j])
						if(!vis[h]){
							res2=h;break;
						}
					if(res2) ans=max(ans,val[i]+val[j]+val[res1]+val[res2]);
					vis[res1]=0;
				}
				res1=res2=0;
				for(auto h:g[j])
					if(!vis[h]){
						res2=h;break;
					}
				if(res2){
					vis[res2]=1;
					for(auto h:g[i])
						if(!vis[h]){
							res1=h;break;
						}
					if(res1) ans=max(ans,val[i]+val[j]+val[res1]+val[res2]);
					vis[res2]=0;
				}
				vis[j]=0;
			}
		vis[i]=0;
	}
	write(ans);
	return 0;
}
