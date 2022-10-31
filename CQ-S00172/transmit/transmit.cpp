//你有没有想过，朋友不再是朋友，家园不再是家园！
//树剖DDP。。。。。。太怪了哥。。。。。。 
//他妈这题写了我90min，真分崩离析了 
//估分100 
#include<cstdio>
#include<cctype>
namespace SOLVE{
	typedef long long ll;
	inline int read(){
		int n(0);char s;while(!isdigit(s=getchar()));while(n=n*10+(s&15),isdigit(s=getchar()));return n;
	}
	inline void write(ll n){
		static char s[20];int top(0);while(s[++top]=n%10^48,n/=10);while(putchar(s[top]),--top);putchar(10);
	}
	const int M=2e5+5;const ll INF=1e18;
	int n,q,k,ege,dfc,h[M],w[M];int f[M],d[M],sz[M],son[M],top[M],dfn[M];
	int mx1[M],mx2[M],mx3[M];
	struct Edge{
		int v,nx;
	}e[M<<1];
	inline void Add(const int&u,const int&v){
		e[++ege]=(Edge){v,h[u]};h[u]=ege;
		e[++ege]=(Edge){u,h[v]};h[v]=ege;
	}
	inline ll min(const ll&a,const ll&b){
		return a>b?b:a;
	}
	template<int S>
	struct Matrix{
		ll f[S][S];
		Matrix(){
			for(int i=0;i^S;++i)for(int j=0;j^S;++j)f[i][j]=INF;
		}
		inline ll*operator[](const int&x){
			return f[x];
		}
		inline Matrix operator*(Matrix g){
			Matrix<S>ans=Matrix<S>();
			for(int i=0;i^S;++i)for(int j=0;j^S;++j)for(int k=0;k^S;++k)ans[i][j]=min(ans[i][j],f[i][k]+g[k][j]);
			return ans;
		}
	};
	template<int S>
	struct Vector{
		ll f[S];
		Vector(){
			for(int i=0;i^S;++i)f[i]=INF;
		}
		inline ll&operator[](const int&x){
			return f[x];
		}
		inline Vector operator*(Matrix<S>g){
			Vector<S>ans=Vector<S>();
			for(int i=0;i^S;++i)for(int j=0;j^S;++j)ans[j]=min(ans[j],f[i]+g[i][j]);
			return ans;
		}
	};
	inline void DFS1(const int&u){
		sz[u]=1;d[u]=d[f[u]]+1;
		for(int v,E=h[u];E;E=e[E].nx)if((v=e[E].v)^f[u])f[v]=u,DFS1(v),sz[u]+=sz[v],sz[v]>sz[son[u]]&&(son[u]=v);
	}
	inline void DFS2(const int&u,const int&tp){
		dfn[u]=++dfc;top[u]=tp;if(!son[u])return;DFS2(son[u],tp);
		for(int E=h[u];E;E=e[E].nx)if(e[E].v^son[u]&&e[E].v^f[u])DFS2(e[E].v,e[E].v);
	}
	inline int LCA(int u,int v){
		while(top[u]^top[v])d[top[u]]>d[top[v]]?u=f[top[u]]:v=f[top[v]];return d[u]>d[v]?v:u;
	}
	namespace SOL1{
		ll S[M];
		inline void DFS(const int&u){
			S[u]=S[f[u]]+w[u];for(int E=h[u];E;E=e[E].nx)if(e[E].v^f[u])DFS(e[E].v);
		}
		inline ll Qry(int s,int t){
			const int&lca=LCA(s,t);return S[s]+S[t]-S[lca]-S[f[lca]];
		}
		inline void Solve(){
			DFS(1);
			while(q--){
				int s,t;s=read();t=read();write(Qry(s,t));
			}
		}
	}
	namespace SOL2{
		Matrix<2>p1[M<<2],p2[M<<2],a[M];Vector<2>ans;
		inline Matrix<2>tr(const int&w){
			Matrix<2>ans;ans[0][0]=ans[1][0]=w;ans[0][1]=0;return ans;
		}
		inline void Build(const int&u,const int&L=1,const int&R=n){
			if(L==R)return void(p1[u]=p2[u]=a[L]);
			const int&mid=L+R>>1;Build(u<<1,L,mid);Build(u<<1|1,mid+1,R);
			p1[u]=p1[u<<1]*p1[u<<1|1];p2[u]=p2[u<<1|1]*p2[u<<1];
		}
		inline void Q1(const int&u,const int&l,const int&r,const int&L=1,const int&R=n){
			if(l>R||L>r)return;if(l<=L&&R<=r)return void(ans=ans*p1[u]);
			const int&mid=L+R>>1;Q1(u<<1,l,r,L,mid);Q1(u<<1|1,l,r,mid+1,R);
		}
		inline void Q2(const int&u,const int&l,const int&r,const int&L=1,const int&R=n){
			if(l>R||L>r)return;if(l<=L&&R<=r)return void(ans=ans*p2[u]);
			const int&mid=L+R>>1;Q2(u<<1|1,l,r,mid+1,R);Q2(u<<1,l,r,L,mid);
		}
		inline ll Qry(int s,int t){
			if(d[s]<d[t])s^=t^=s^=t;
			static int len,u[M],v[M];ans[0]=w[s];ans[1]=INF;len=0;s=f[s];
			while(top[s]^top[t]){
				if(d[top[s]]>d[top[t]])Q2(1,dfn[top[s]],dfn[s]),s=f[top[s]];
				else ++len,u[len]=top[t],v[len]=t,t=f[top[t]];
			}
			if(d[s]>d[t])Q2(1,dfn[t],dfn[s]);else Q1(1,dfn[s],dfn[t]);
			for(int i=len;i>=1;--i)Q1(1,dfn[u[i]],dfn[v[i]]);return ans[0];
		}
		inline void Solve(){
			for(int u=1;u<=n;++u)a[dfn[u]]=tr(w[u]);Build(1);
			while(q--){
				int s,t;s=read();t=read();write(Qry(s,t));
			}
		}
	}
	namespace SOL3{
		Matrix<3>p1[M<<2],p2[M<<2],a[M];Vector<3>ans;
		inline Matrix<3>tr1(const int&w,const int&x){
			Matrix<3>ans;ans[0][0]=ans[1][0]=ans[2][0]=w;ans[0][1]=ans[1][2]=0;ans[1][1]=x;return ans;
		}
		inline Matrix<3>tr2(const int&w){
			Matrix<3>ans;ans[0][0]=ans[1][0]=ans[2][0]=w;ans[0][1]=ans[1][2]=0;return ans;
		}
		inline void Build(const int&u,const int&L=1,const int&R=n){
			if(L==R)return void(p1[u]=p2[u]=a[L]);
			const int&mid=L+R>>1;Build(u<<1,L,mid);Build(u<<1|1,mid+1,R);
			p1[u]=p1[u<<1]*p1[u<<1|1];p2[u]=p2[u<<1|1]*p2[u<<1];
		}
		inline void Q1(const int&u,const int&l,const int&r,const int&L=1,const int&R=n){
			if(l>R||L>r)return;if(l<=L&&R<=r)return void(ans=ans*p1[u]);
			const int&mid=L+R>>1;Q1(u<<1,l,r,L,mid);Q1(u<<1|1,l,r,mid+1,R);
		}
		inline void Q2(const int&u,const int&l,const int&r,const int&L=1,const int&R=n){
			if(l>R||L>r)return;if(l<=L&&R<=r)return void(ans=ans*p2[u]);
			const int&mid=L+R>>1;Q2(u<<1|1,l,r,mid+1,R);Q2(u<<1,l,r,L,mid);
		}
		inline int Get(const int&u,const int&x,const int&y){
			if(mx1[u]!=x&&mx1[u]!=y)return w[mx1[u]];
			if(mx2[u]!=x&&mx2[u]!=y)return w[mx2[u]];
			return w[mx3[u]];
		}
		inline ll Qry(int s,int t){
			if(d[s]<d[t])s^=t^=s^=t;
			static int len,u[M],v[M];int V,lst(s);ans[0]=w[s];ans[1]=ans[2]=INF;len=0;s=f[s];
			while(top[s]^top[t]){
				if(d[top[s]]>d[top[t]]){
					V=Get(s,lst,f[s]);if(V)ans=ans*tr1(w[s],V);else ans=ans*tr2(w[s]);
					if(s!=top[s])Q2(1,dfn[top[s]],dfn[f[s]]);lst=top[s];s=f[top[s]];
				}
				else++len,u[len]=top[t],v[len]=t,t=f[top[t]];
			}
			u[len+1]=v[len+1]=0;
			if(d[s]>d[t]){
				if(s!=t){
					V=Get(s,lst,f[s]);if(V)ans=ans*tr1(w[s],V);else ans=ans*tr2(w[s]);
				}
				if(dfn[s]-1>=dfn[t]+1)Q2(1,dfn[t]+1,dfn[s]-1);
				if(s==t){
					V=Get(s,lst,u[len]);if(V)ans=ans*tr1(w[s],V);else ans=ans*tr2(w[s]);
				}
				else{
					V=Get(t,son[t],u[len]);if(V)ans=ans*tr1(w[t],V);else ans=ans*tr2(w[t]);
				}
			}
			else{
				if(s==t){
					V=Get(s,lst,u[len]);if(V)ans=ans*tr1(w[s],V);else ans=ans*tr2(w[s]);
				}
				else{
					V=Get(s,son[s],lst);if(V)ans=ans*tr1(w[s],V);else ans=ans*tr2(w[s]);
				}
				if(dfn[s]+1<=dfn[t]-1)Q1(1,dfn[s]+1,dfn[t]-1);
				if(s!=t){
					V=Get(t,u[len],f[t]);if(V)ans=ans*tr1(w[t],V);else ans=ans*tr2(w[t]);
				}
			}
			for(int i=len;i>=1;--i){
				if(u[i]!=v[i])Q1(1,dfn[u[i]],dfn[f[v[i]]]);
				V=Get(v[i],f[v[i]],u[i-1]);if(V)ans=ans*tr1(w[v[i]],V);else ans=ans*tr2(w[v[i]]);
			}
			return ans[0];
		}
		inline void Solve(){
			for(int V,u=1;u<=n;++u){
				V=Get(u,f[u],son[u]);if(V)a[dfn[u]]=tr1(w[u],V);else a[dfn[u]]=tr2(w[u]);
			}
			Build(1);
			while(q--){
				int s,t;s=read();t=read();write(Qry(s,t));
			}
		}
	}
	inline void main(){
		w[0]=1e9+1;n=read();q=read();k=read();for(int u=1;u<=n;++u)w[u]=read();
		for(int u,v,i=1;i<n;++i)u=read(),v=read(),Add(u,v);DFS1(1);DFS2(1,1);
		for(int u=1;u<=n;++u)for(int v,E=h[u];E;E=e[E].nx){
			v=e[E].v;
			if(w[v]<w[mx1[u]])mx3[u]=mx2[u],mx2[u]=mx1[u],mx1[u]=v;
			else if(w[v]<w[mx2[u]])mx3[u]=mx2[u],mx2[u]=v;
			else if(w[v]<w[mx3[u]])mx3[u]=v;
		}
		if(k==1)return SOL1::Solve();if(k==2)return SOL2::Solve();if(k==3)return SOL3::Solve();
	}
}
int main(){
	freopen("transmit.in","r",stdin);
	freopen("transmit.out","w",stdout);
	SOLVE::main();
	return 0;
}
