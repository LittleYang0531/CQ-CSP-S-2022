#include<bits/stdc++.h>
#define int long long
using namespace std;
inline int read(){
	int x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9')x=(x<<3)+(x<<1)+(ch^48),ch=getchar();
	return x*f;
}
void write(int x){
	if(x<0) putchar('-'),x=-x;
	if(x>=10) write(x/10);
	putchar(x%10+'0');
}
const int N = 2e5+10,M = 2e3+10,inf = 1e18;
int n,m,q,cnt;
int a[N],hed[N],nex[N<<1],to[N<<1],dep[N];
void add(int u,int v){
	nex[++cnt]=hed[u],hed[u]=cnt,to[cnt]=v;
	nex[++cnt]=hed[v],hed[v]=cnt,to[cnt]=u;
}
namespace st1{
	int cnt1,cnt2;
	int dp[N],fa[N],s[N],t[N];
	void dfs(int x,int f){
		fa[x] = f,dep[x] = dep[f]+1;
		for(int i=hed[x];i;i=nex[i])
			if(to[i]^f) dfs(to[i],x);
	}
	void update(int i){
		dp[s[i]] = inf;
		for(int j = 1;j<=m and i-j;j++) dp[s[i]] = min(dp[s[i]],dp[s[i-j]]);
		if(m==3 and i>4){
			int mi = inf;
			for(int k = hed[s[i-2]];k;k=nex[k])
			if(to[k]^s[i-3]) mi = min(mi,dp[to[k]]);
			dp[s[i]] = min(dp[s[i]],mi);
		}
		dp[s[i]] += a[s[i]];
	}
	void solve(){
		dfs(1,0);
		while(q--){
			int x = read(),y = read();
			cnt1 = cnt2 = 0;
			while(x^y)
				if(dep[x]>dep[y]) s[++cnt1]=x,x=fa[x];
				else t[++cnt2]=y,y=fa[y];
			s[++cnt1]=x;
			for(int i = cnt2;i;i--) s[++cnt1]=t[i];
			dp[s[1]] = a[s[1]];
			for(int i = 2;i<=cnt1;i++){
				int now = s[i];
				update(i);
				if(m==3 and i>=4){
					for(int j=hed[s[i-1]];j;j=nex[j])
						if(to[j]!=now and to[j]!=s[i-2]) s[i]=to[j],update(i);
				}
				s[i] = now;
			}
			write(dp[s[cnt1]]),putchar('\n');
		}
	}
}
namespace st2{
	int d[N],f[18][N];
	void dfs(int x,int fa){
		d[x] = d[fa]+a[x],f[0][x] = fa,dep[x] = dep[fa]+1;
		for(int i = 1;i<18;i++) f[i][x]=f[i-1][f[i-1][x]];
		for(int i=hed[x];i;i=nex[i])
			if(to[i]^fa) dfs(to[i],x);
	}
	int lca(int x,int y){
		if(dep[x]<dep[y]) swap(x,y);
		for(int i = 17;i+1;i--) if(dep[f[i][x]]>=dep[y]) x=f[i][x];
		if(x==y) return x;
		for(int i = 17;i+1;i--) if(f[i][x]^f[i][y]) x=f[i][x],y=f[i][y];
		return f[0][x];
	}
	void solve(){
		dfs(1,0);
		while(q--){
			int x = read(),y = read(),lc = lca(x,y);
			write(d[x]+d[y]-d[lc]-d[f[0][lc]]),putchar('\n');
		}
	}
}
signed main(){
	freopen("transmit.in","r",stdin);
	freopen("transmit.out","w",stdout);
	n = read(),q = read(),m = read();
	for(int i = 1;i<=n;i++) a[i] = read();
	for(int i = 1;i<n;i++) add(read(),read());
	if(n<M) st1::solve(),exit(0);
	if(m==1) st2::solve(),exit(0);
	st1::solve();
	return 0;
}

