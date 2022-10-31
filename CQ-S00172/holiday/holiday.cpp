//你有没有听见孩子们的悲鸣！ 
//估分100 
#include<cstdio>
#include<cctype>
namespace SOLVE{
	typedef long long ll;
	inline ll read(){
		ll n(0);char s;while(!isdigit(s=getchar()));while(n=n*10+(s&15),isdigit(s=getchar()));return n;
	}
	const int M=2505;
	int n,m,k,ege,d[M],h[M];ll ans,s[M];bool g[M][M];int L,R,q[M];
	struct data{
		ll mx1,mx2,mx3,mx4;
		data():mx1(0),mx2(0),mx3(0),mx4(0){}
		inline void Insert(const ll&V){
			if(s[V]>s[mx1])mx4=mx3,mx3=mx2,mx2=mx1,mx1=V;
			else if(s[V]>s[mx2])mx4=mx3,mx3=mx2,mx2=V;
			else if(s[V]>s[mx3])mx4=mx3,mx3=V;
			else if(s[V]>s[mx4])mx4=V;
		}
	}t[M];
	struct Edge{
		int v,nx;
	}e[20005];
	inline void Add(const int&u,const int&v){
		e[++ege]=(Edge){v,h[u]};h[u]=ege;
		e[++ege]=(Edge){u,h[v]};h[v]=ege;
	}
	inline void BFS(int s){
		for(int u=1;u<=n;++u)d[u]=-1;d[q[L=R=1]=s]=0;
		while(L<=R){
			const int&u=q[L++];if(d[u]==k)continue;
			for(int v,E=h[u];E;E=e[E].nx)if(!~d[v=e[E].v])d[q[++R]=v]=d[u]+1;
		}
	}
	inline ll max(const ll&a,const ll&b){
		return a>b?a:b;
	}
	inline bool check(const int&a,const int&b,const int&c,const int&d){
		return a!=b&&a!=c&&a!=d&&b!=c&&b!=d&&c!=d;
	}
	inline void main(){
		n=read();m=read();k=read()+1;for(int u=2;u<=n;++u)s[u]=read();
		for(int u,v,i=1;i<=m;++i)u=read(),v=read(),Add(u,v);
		for(int u=1;u<=n;++u){
			BFS(u);for(int v=1;v<=n;++v)if(u!=v&&~d[v])g[u][v]=true;
		}
		for(int u=2;u<=n;++u)for(int v=2;v<=n;++v)if(u!=v&&g[1][v]&&g[v][u])t[u].Insert(v);
		for(int u=2;u<=n;++u)for(int v=u+1;v<=n;++v)if(g[u][v]){
			static int a[5],b[5];
			a[0]=t[u].mx1;a[1]=t[u].mx2;a[2]=t[u].mx3;a[3]=t[u].mx4;
			b[0]=t[v].mx1;b[1]=t[v].mx2;b[2]=t[v].mx3;b[3]=t[v].mx4;
			for(int i=0;a[i]&&i^4;++i)for(int j=0;b[j]&&j^4;++j){
				if(check(u,v,a[i],b[j]))ans=max(ans,s[u]+s[v]+s[a[i]]+s[b[j]]);
			}
		}
		printf("%lld",ans);
	}
}
int main(){
	freopen("holiday.in","r",stdin);
	freopen("holiday.out","w",stdout);
	SOLVE::main();
	return 0;
}
