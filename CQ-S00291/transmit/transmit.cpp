#include <bits/stdc++.h>
#define ll long long
#define wr(x,ch) write(x),putchar(ch)
using namespace std;
ll read() {
	ll x=0;
	char c=getchar();
	bool f=0;
	while(!isdigit(c)) f|=c=='-',c=getchar();
	while(isdigit(c)) x=(x<<3)+(x<<1)+(c^48),c=getchar();
	return f?~(x-1):x;
}
void write(ll x) {
	if(x<0) putchar('-'),x=~(x-1);
	if(x>=10) write(x/10);
	putchar(x%10^48);
}
const ll N=200005,inf=50000000000;
ll s[2][2][30][N],fa[30][N],dep[N],k,a[N],head[N],n,cnt,lg[N],q,u,v,l,r;
struct edge {
	ll to,nxt;
}e[N<<1];
void add(ll u,ll v) {
	e[++cnt]=(edge){v,head[u]},head[u]=cnt;
}
void dfs1(int p) {
	dep[p]=dep[fa[0][p]]+1-(p==1);
	if(k==1) s[0][0][0][p]=a[fa[0][p]];
	else {
		s[0][0][0][p]=a[fa[0][p]];
		s[0][1][0][p]=0;
		s[1][0][0][p]=0;
		s[1][1][0][p]=a[p];
	}
	for(int i=1;(1<<i)<=dep[p];i++) 
		fa[i][p]=fa[i-1][fa[i-1][p]];
	for(int i=head[p],to=e[i].to;i;to=e[i=e[i].nxt].to) {
		if(to!=fa[0][p]) {
			fa[0][to]=p;
			dfs1(to);
		}
	}
}
void dfs2(int p) {
	for(int i=1;(1<<i)<=dep[p];i++) {
		if(k==1) {
			s[0][0][i][p]=s[0][0][i-1][p]+s[0][0][i-1][fa[i-1][p]];
		}else {
			s[0][0][i][p]=min(s[0][1][i-1][p]+s[1][0][i-1][fa[i-1][p]],
							  s[0][0][i-1][p]+s[0][0][i-1][fa[i-1][p]]);
			s[0][1][i][p]=min(s[0][1][i-1][p]+s[1][1][i-1][fa[i-1][p]],
							  s[0][0][i-1][p]+s[0][1][i-1][fa[i-1][p]]);
			s[1][0][i][p]=min(s[1][1][i-1][p]+s[1][0][i-1][fa[i-1][p]],
							  s[1][0][i-1][p]+s[0][0][i-1][fa[i-1][p]]);
			s[1][1][i][p]=min(s[1][1][i-1][p]+s[1][1][i-1][fa[i-1][p]],
							  s[1][0][i-1][p]+s[0][1][i-1][fa[i-1][p]]);
		}
	}
	for(int i=head[p],to=e[i].to;i;to=e[i=e[i].nxt].to) 
		if(to!=fa[0][p]) 
			dfs2(to);
}
void Swap(ll &x,ll &y) {
	x^=y^=x^=y;
}
ll getlca(ll x,ll y) {
	if(k==2) {
		ll u0=0,u1=a[fa[0][x]],v0=0,v1=a[fa[0][y]],u=x,v=y;
		while(dep[x]^dep[y]) {
			if(dep[x]<dep[y]) Swap(x,y),Swap(u0,v0),Swap(u1,v1);
			u1+=s[1][1][lg[dep[x]-dep[y]]][x];
			u0+=s[0][0][lg[dep[x]-dep[y]]][x];
			x=fa[lg[dep[y]-dep[x]]][x];
		}
		if(x==y) {
			return u0+a[v];
		}
		for(int i=lg[dep[x]];~i;i--) {
			if(fa[i][x]!=fa[i][y]) {
				u1+=s[1][1][i][x];
				u0+=s[0][0][i][x];
				v1+=s[1][1][i][y];
				v0+=s[0][0][i][y];
				x=fa[i][x];
				y=fa[i][y];
			}
		}
		return a[u]+a[v]+min(u0+v0,u1+v1-a[fa[0][x]]);
	}else {
		ll u0=0,v0=0,u=x,v=y;
		while(dep[x]^dep[y]) {
			if(dep[x]<dep[y]) Swap(x,y),Swap(u0,v0);
			u0+=s[0][0][lg[dep[x]-dep[y]]][x];
			x=fa[lg[dep[y]-dep[x]]][x];
		}
		if(x==y) {
			return u0+a[v];
		}
		for(int i=lg[dep[x]];~i;i--) {
			if(fa[i][x]!=fa[i][y]) {
				u0+=s[0][0][i][x];
				v0+=s[0][0][i][y];
				x=fa[i][x];
				y=fa[i][y];
			}
		}
		return a[u]+a[v]+u0+v0+a[fa[0][x]];
	}
}
struct node {
	ll u,dis;
	bool operator>(const node &p) const {
		return dis>p.dis;
	}
};
const int tmpN=2005;
ll dis[tmpN][tmpN],head2[tmpN],cnt2,fa2[tmpN];
bool vis[tmpN];
struct edge2 {
	ll to,nxt,w;
}e2[N<<1];
void add2(ll u,ll v) {
	e2[++cnt2]=(edge2){v,head2[u],a[v]},head2[u]=cnt2;
}
void dij(int st) {
	priority_queue<node,vector<node>,greater<node> > qu;
	qu.push((node){st,0});
	for(int i=1;i<=n;i++) dis[st][i]=inf,vis[i]=0;
	dis[st][st]=0;
	while(qu.size()) {
		int top=qu.top().u;
		qu.pop();
		if(vis[top]) continue;
		vis[top]=1;
		for(int i=head2[top],to=e2[i].to;i;to=e2[i=e2[i].nxt].to) {
			if(dis[st][to]>dis[st][top]+e2[i].w) 
				dis[st][to]=dis[st][top]+e2[i].w,qu.push((node){to,dis[st][to]});
		}
	}
}
void dfs(int p) {
	for(int i=head[p],to=e[i].to;i;to=e[i=e[i].nxt].to) {
		if(to!=fa2[p]) {
			fa2[to]=p;
			dfs(to);
		}
	}
}
int getlen(int x,int y) {
	if(x==y) return 0;
	if(fa2[x]==y||fa2[y]==x) return 1;
	if(fa2[x]==fa2[y]||fa2[fa2[x]]==y||fa2[fa2[y]]==x) return 2;
	if(fa2[fa2[fa2[x]]]==y||fa2[fa2[fa2[y]]]==x||fa2[fa2[x]]==fa2[y]||fa2[fa2[y]]==fa2[x]) return 3;
	return 5;
}
int main() {
	freopen("transmit.in","r",stdin);
	freopen("transmit.out","w",stdout);
//	freopen("transmit3.in","r",stdin);
//	freopen("transmit3.out","w",stdout);
	n=read(),q=read(),k=read();
	for(int i=1;i<=n;i++) a[i]=read();
	if(n<=2000&&q<=2000) {
		for(int i=1;i<n;i++) u=read(),v=read(),add(u,v),add(v,u);
		dfs(1);
		for(int i=1;i<=n;i++) {
			for(int j=1;j<=n;j++) {
				if(i==j) continue;
				if(getlen(i,j)<=k) add2(i,j);
			}
		}
		for(int i=1;i<=n;i++) dij(i);
//		for(int i=1;i<=n;i++) {
//			for(int j=1;j<=n;j++) {
//				printf("%3lld",dis[i][j]);
//			}
//			puts("");
//		}
		while(q--) {
			l=read(),r=read();
			wr(dis[l][r]+a[l],'\n');
		}
		return 0;
	}
	for(int i=1;i<n;i++) u=read(),v=read(),add(u,v),add(v,u);
	dfs1(1),dfs2(1);
	for(int i=1;i<=q;i++) {
		l=read(),r=read();
		wr(getlca(l,r),'\n');
	}
	return 0;
}
/*
#include <bits/stdc++.h>
#define ll long long
#define wr(x,ch) write(x),putchar(ch)
using namespace std;
ll read() {
	ll x=0;
	char c=getchar();
	bool f=0;
	while(!isdigit(c)) f|=c=='-',c=getchar();
	while(isdigit(c)) x=(x<<3)+(x<<1)+(c^48),c=getchar();
	return f?~(x-1):x;
}
void write(ll x) {
	if(x<0) putchar('-'),x=~(x-1);
	if(x>=10) write(x/10);
	putchar(x%10^48);
}
const ll N=200005,inf=50000000000;
ll s[3][3][30][N],fa[30][N],dep[N],k,a[N],head[N],n,cnt,lg[N],q,u,v,l,r;
struct edge {
	ll to,nxt;
}e[N<<1];
void add(ll u,ll v) {
	e[++cnt]=(edge){v,head[u]},head[u]=cnt;
}
void dfs1(int p) {
	dep[p]=dep[fa[0][p]]+1-(p==1);
	if(k==1) s[0][0][0][p]=a[fa[0][p]];
	else if(k==2) {
		s[0][0][0][p]=a[fa[0][p]];
		s[0][1][0][p]=0;
		s[1][0][0][p]=0;
		s[1][1][0][p]=a[p];
	}else {
		s[0][0][0][p]=a[fa[0][p]];
		s[0][1][0][p]=0;
		s[0][2][0][p]=N;
		s[1][0][0][p]=0;
		s[1][1][0][p]=N;
		s[1][2][0][p]=N;
		s[2][0][0][p]=N;
		s[2][1][0][p]=N;
		s[2][2][0][p]=N;
	}
	for(int i=1;(1<<i)<=dep[p];i++) 
		fa[i][p]=fa[i-1][fa[i-1][p]];
	for(int i=head[p],to=e[i].to;i;to=e[i=e[i].nxt].to) {
		if(to!=fa[0][p]) {
			fa[0][to]=p;
			dfs1(to);
		}
	}
}
void dfs2(int p) {
	for(int i=1;(1<<i)<=dep[p];i++) {
		if(k==1) {
			s[0][0][i][p]=s[0][0][i-1][p]+s[0][0][i-1][fa[i-1][p]];
		}else if(k==2) {
			s[0][0][i][p]=min(s[0][1][i-1][p]+s[1][0][i-1][fa[i-1][p]],
							  s[0][0][i-1][p]+s[0][0][i-1][fa[i-1][p]]);
			s[0][1][i][p]=min(s[0][1][i-1][p]+s[1][1][i-1][fa[i-1][p]],
							  s[0][0][i-1][p]+s[0][1][i-1][fa[i-1][p]]);
			s[1][0][i][p]=min(s[1][1][i-1][p]+s[1][0][i-1][fa[i-1][p]],
							  s[1][0][i-1][p]+s[0][0][i-1][fa[i-1][p]]);
			s[1][1][i][p]=min(s[1][1][i-1][p]+s[1][1][i-1][fa[i-1][p]],
							  s[1][0][i-1][p]+s[0][1][i-1][fa[i-1][p]]);
		}else if(k==3) {
			s[0][0][i][p]=min(s[0][1][i-1][p]+s[1][0][i-1][fa[i-1][p]],
						  min(s[0][0][i-1][p]+s[0][0][i-1][fa[i-1][p]],
						  	  s[0][2][i-1][p]+s[2][0][i-1][fa[i-1][p]]));
			s[0][1][i][p]=min(s[0][1][i-1][p]+s[1][1][i-1][fa[i-1][p]],
						  min(s[0][0][i-1][p]+s[0][1][i-1][fa[i-1][p]],
						  	  s[0][2][i-1][p]+s[2][1][i-1][fa[i-1][p]]));
			s[0][2][i][p]=min(s[0][1][i-1][p]+s[1][2][i-1][fa[i-1][p]],
						  min(s[0][0][i-1][p]+s[0][2][i-1][fa[i-1][p]],
						  	  s[0][2][i-1][p]+s[2][2][i-1][fa[i-1][p]]));
			s[1][0][i][p]=min(s[1][1][i-1][p]+s[1][0][i-1][fa[i-1][p]],
						  min(s[1][0][i-1][p]+s[0][0][i-1][fa[i-1][p]],
						  	  s[1][2][i-1][p]+s[2][0][i-1][fa[i-1][p]]));
			s[1][1][i][p]=min(s[1][1][i-1][p]+s[1][1][i-1][fa[i-1][p]],
						  min(s[1][0][i-1][p]+s[0][1][i-1][fa[i-1][p]],
						  	  s[1][2][i-1][p]+s[2][1][i-1][fa[i-1][p]]));
			s[1][2][i][p]=min(s[1][1][i-1][p]+s[1][2][i-1][fa[i-1][p]],
						  min(s[1][0][i-1][p]+s[0][2][i-1][fa[i-1][p]],
						  	  s[1][2][i-1][p]+s[2][2][i-1][fa[i-1][p]]));
			s[2][0][i][p]=min(s[2][1][i-1][p]+s[1][0][i-1][fa[i-1][p]],
						  min(s[2][0][i-1][p]+s[0][0][i-1][fa[i-1][p]],
						  	  s[2][2][i-1][p]+s[2][0][i-1][fa[i-1][p]]));
			s[2][1][i][p]=min(s[2][1][i-1][p]+s[1][1][i-1][fa[i-1][p]],
						  min(s[2][0][i-1][p]+s[0][1][i-1][fa[i-1][p]],
						  	  s[2][2][i-1][p]+s[2][1][i-1][fa[i-1][p]]));
			s[2][2][i][p]=min(s[2][1][i-1][p]+s[1][2][i-1][fa[i-1][p]],
						  min(s[2][0][i-1][p]+s[0][2][i-1][fa[i-1][p]],
						  	  s[2][2][i-1][p]+s[2][2][i-1][fa[i-1][p]]));
		}
	}
	for(int i=head[p],to=e[i].to;i;to=e[i=e[i].nxt].to) 
		if(to!=fa[0][p]) 
			dfs2(to);
}
void Swap(ll &x,ll &y) {
	x^=y^=x^=y;
}
ll getlca(ll x,ll y) {
	if(k==3) {
		ll u0=0,u1=a[fa[0][x]],u2=a[fa[1][x]],
		   v0=0,v1=a[fa[0][y]],v2=a[fa[1][y]],
		   u=x,v=y;
		while(dep[x]^dep[y]) {
			if(dep[x]<dep[y]) Swap(x,y),Swap(u0,v0),Swap(u1,v1),Swap(u2,v2);
			u2+=s[2][2][lg[dep[x]-dep[y]]][x];
			u1+=s[1][1][lg[dep[x]-dep[y]]][x];
			u0+=s[0][0][lg[dep[x]-dep[y]]][x];
			x=fa[lg[dep[y]-dep[x]]][x];
		}
		if(x==y) {
			return u0+a[v];
		}
		for(int i=lg[dep[x]];i;i--) {
			if(fa[i][x]!=fa[i][y]) {
				u2+=s[2][2][i][x];
				u1+=s[1][1][i][x];
				u0+=s[0][0][i][x];
				v2+=s[2][2][i][x];
				v1+=s[1][1][i][y];
				v0+=s[0][0][i][y];
				x=fa[i][x];
				y=fa[i][y];
			}
		}
		return a[u]+a[v]+min(min(u0+v1,u1+v0),min(u2+v2-a[fa[1][x]],u1+v1));
	}if(k==2) {
		ll u0=0,u1=a[fa[0][x]],v0=0,v1=a[fa[0][y]],u=x,v=y;
		while(dep[x]^dep[y]) {
			if(dep[x]<dep[y]) Swap(x,y),Swap(u0,v0),Swap(u1,v1);
			u1+=s[1][1][lg[dep[x]-dep[y]]][x];
			u0+=s[0][0][lg[dep[x]-dep[y]]][x];
			x=fa[lg[dep[y]-dep[x]]][x];
		}
		if(x==y) {
			return u0+a[v];
		}
		for(int i=lg[dep[x]];~i;i--) {
			if(fa[i][x]!=fa[i][y]) {
				u1+=s[1][1][i][x];
				u0+=s[0][0][i][x];
				v1+=s[1][1][i][y];
				v0+=s[0][0][i][y];
				x=fa[i][x];
				y=fa[i][y];
			}
		}
		return a[u]+a[v]+min(u0+v0,u1+v1-a[fa[0][x]]);
	}else {
		ll u0=0,v0=0,u=x,v=y;
		while(dep[x]^dep[y]) {
			if(dep[x]<dep[y]) Swap(x,y),Swap(u0,v0);
			u0+=s[0][0][lg[dep[x]-dep[y]]][x];
			x=fa[lg[dep[y]-dep[x]]][x];
		}
		if(x==y) {
			return u0+a[v];
		}
		for(int i=lg[dep[x]];~i;i--) {
			if(fa[i][x]!=fa[i][y]) {
				u0+=s[0][0][i][x];
				v0+=s[0][0][i][y];
				x=fa[i][x];
				y=fa[i][y];
			}
		}
		return a[u]+a[v]+u0+v0+a[fa[0][x]];
	}
}
struct node {
	ll u,dis;
	bool operator>(const node &p) const {
		return dis>p.dis;
	}
};
const int tmpN=2005;
ll dis[tmpN][tmpN],head2[tmpN],cnt2,fa2[tmpN];
bool vis[tmpN];
struct edge2 {
	ll to,nxt,w;
}e2[N<<1];
void add2(ll u,ll v) {
	e2[++cnt2]=(edge2){v,head2[u],a[v]},head2[u]=cnt2;
}
void dij(int st) {
	priority_queue<node,vector<node>,greater<node> > qu;
	qu.push((node){st,0});
	for(int i=1;i<=n;i++) dis[st][i]=inf,vis[i]=0;
	dis[st][st]=0;
	while(qu.size()) {
		int top=qu.top().u;
		qu.pop();
		if(vis[top]) continue;
		vis[top]=1;
		for(int i=head2[top],to=e2[i].to;i;to=e2[i=e2[i].nxt].to) {
			if(dis[st][to]>dis[st][top]+e2[i].w) 
				dis[st][to]=dis[st][top]+e2[i].w,qu.push((node){to,dis[st][to]});
		}
	}
}
void dfs(int p) {
	for(int i=head[p],to=e[i].to;i;to=e[i=e[i].nxt].to) {
		if(to!=fa2[p]) {
			fa2[to]=p;
			dfs(to);
		}
	}
}
int getlen(int x,int y) {
	if(x==y) return 0;
	if(fa2[x]==y||fa2[y]==x) return 1;
	if(fa2[x]==fa2[y]||fa2[fa2[x]]==y||fa2[fa2[y]]==x) return 2;
	if(fa2[fa2[fa2[x]]]==y||fa2[fa2[fa2[y]]]==x||fa2[fa2[x]]==fa2[y]||fa2[fa2[y]]==fa2[x]) return 3;
	return 5;
}
int main() {
//	freopen("transmit.in","r",stdin);
//	freopen("transmit.out","w",stdout);
	freopen("transmit4.in","r",stdin);
	freopen("transmit4.out","w",stdout);
	n=read(),q=read(),k=read();
	for(int i=1;i<=n;i++) a[i]=read();
	if(n<=2000&&q<=2000) {
		for(int i=1;i<n;i++) u=read(),v=read(),add(u,v),add(v,u);
		dfs(1);
		for(int i=1;i<=n;i++) {
			for(int j=1;j<=n;j++) {
				if(i==j) continue;
				if(getlen(i,j)<=k) add2(i,j);
			}
		}
		for(int i=1;i<=n;i++) dij(i);
//		for(int i=1;i<=n;i++) {
//			for(int j=1;j<=n;j++) {
//				printf("%3lld",dis[i][j]);
//			}
//			puts("");
//		}
		while(q--) {
			l=read(),r=read();
			wr(dis[l][r]+a[l],'\n');
		}
		return 0;
	}
	for(int i=1;i<n;i++) u=read(),v=read(),add(u,v),add(v,u);
	dfs1(1),dfs2(1);
	for(int i=1;i<=q;i++) {
		l=read(),r=read();
		wr(getlca(l,r),'\n');
	}
	return 0;
}

*/
