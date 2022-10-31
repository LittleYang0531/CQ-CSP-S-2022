//No more time, No more chance.
#include <cstdio>
#include <vector>
#include <cstring>
#include <algorithm>
using std :: min;using std :: max;
int re(){
	char c;int w=1;
	while((c=getchar())<'0'||c>'9')if(c == '-')w=-1;
	int res = c-'0';
	while((c=getchar())>='0'&&c<='9')res = res*10+c-'0';
	return res*w;
}
namespace KamiyamaShiki{
	typedef long long ll;
	const int maxn = 2e5+5,inf = 1e9;const ll Inf = 1e18;
	int n,q,k,v[maxn];std :: vector <int> G[maxn];
	namespace Subtask_1{//16
		int fa[maxn],dep[maxn],siz[maxn],son[maxn],top[maxn];ll Dep[maxn];
		void dfs1(int u,int F){
			siz[u] = 1,fa[u] = F,dep[u] = dep[F] + 1,Dep[u] = Dep[F] + v[u];
			for(int v:G[u])if(v != F)dfs1(v,u),siz[u] += siz[v],(siz[son[u]]<siz[v]?son[u]=v:0);
		}
		void dfs2(int u,int T){
			top[u] = T;if(son[u])dfs2(son[u],T);
			for(int v:G[u])if(v != fa[u] && v != son[u])dfs2(v,v);
		}
		int LCA(int x,int y){
			while(top[x]^top[y]){
				if(dep[top[x]]<dep[top[y]])x^=y^=x^=y;
				x = fa[top[x]];
			}return dep[x]<dep[y]?x:y;
		}
		ll DIS(int x,int y){int lca = LCA(x,y);return Dep[x]+Dep[y]-Dep[lca]-Dep[fa[lca]];}
		void Solve(){
			dfs1(1,0),dfs2(1,1);
			for(int i=1,x,y;i<=q;++i)scanf("%d %d",&x,&y),printf("%lld\n",DIS(x,y));
		}
	}
	namespace Subtask_2{//40
		struct vec{ll x,y;vec(ll X=0,ll Y=0):x(X),y(Y){};};
		struct mat{ll a,b,c,d;mat(ll A=0,ll B=0,ll C=0,ll D=0):a(A),b(B),c(C),d(D){};};
		vec operator *(vec a,mat b){return vec(min(a.x+b.a,a.y+b.c),min(a.x+b.b,a.y+b.d));}
		mat operator *(mat a,mat b){
			mat r;
			r.a = min(a.a+b.a,a.b+b.c);
			r.b = min(a.a+b.b,a.b+b.d);
			r.c = min(a.c+b.a,a.d+b.c);
			r.d = min(a.c+b.b,a.d+b.d);
			return r;
		}
		int dep[maxn],Log[maxn],fa[maxn][18];mat jpu[maxn][18],jpd[maxn][18];
		void dfs1(int u,int F){
			fa[u][0] = F,dep[u] = dep[F] + 1;
			for(int v:G[u])if(v != F)dfs1(v,u);
		}
		void gtab(){
			for(int i=2;i<=n;++i)Log[i] = Log[i>>1] + 1;
			for(int i=1;i<=n;++i)jpu[i][0] = jpd[i][0] = mat(v[i],0,v[i],Inf);
			for(int i=1;i<=Log[n];++i)
				for(int j=1;j<=n;++j){
					fa[j][i] = fa[fa[j][i-1]][i-1];
					jpu[j][i] = jpu[j][i-1]*jpu[fa[j][i-1]][i-1];
					jpd[j][i] = jpd[fa[j][i-1]][i-1]*jpd[j][i-1];
				}
		}
		int LCA(int x,int y){
			if(dep[x]<dep[y])x ^= y ^= x ^= y;
			while(dep[x]^dep[y])x = fa[x][Log[dep[x]-dep[y]]];
			if(x == y)return x;
			for(int i=Log[dep[x]];~i;--i)
				if(fa[x][i]^fa[y][i])
					x = fa[x][i],y = fa[y][i];
			return fa[x][0];
		}
		mat JPU(int x,int k){
			mat r(0,Inf,Inf,0);
			while(k)r = r*jpu[x][Log[k]],x = fa[x][Log[k]],k -= (1<<Log[k]);
			return r;
		}
		struct pair{int x,y;};
		mat JPD(int x,int k){
			mat r(0,Inf,Inf,0);
			std :: vector <pair> t;
			while(k)t.push_back({x,Log[k]}),x = fa[x][Log[k]],k -= (1<<Log[k]);
			std :: reverse(t.begin(),t.end());
			for(auto p:t)r = r*jpd[p.x][p.y];return r;
		}
		void Solve(){
			//卡常什么的还是先省省吧。 
			dfs1(1,0),gtab();
			for(int i=1,x,y,lca;i<=q;++i){
				x = re(),y = re(),lca = LCA(x,y);
				if(x == lca){
					vec t(v[x],Inf);mat trs = JPD(y,dep[y]-dep[x]);
					printf("%lld\n",(t*trs).x);
				}
				else if(y == lca){
					vec t(v[x],Inf);mat trs = JPU(fa[x][0],dep[x]-dep[y]);
					printf("%lld\n",(t*trs).x);
				}
				else{
					vec t(v[x],Inf);
					mat trs = JPU(fa[x][0],dep[x]-dep[lca])*JPD(y,dep[y]-dep[lca]);
					printf("%lld\n",(t*trs).x);
				}
			}
		}
	}
	namespace Subtask_3{//32
		//需要一个猫树，一个书剖。还有一大堆屎山。这里先打暴力。 
		int fa[maxn],dep[maxn],siz[maxn],son[maxn],top[maxn];ll Dep[maxn];
		void dfs1(int u,int F){
			siz[u] = 1,fa[u] = F,dep[u] = dep[F] + 1,Dep[u] = Dep[F] + v[u];
			for(int v:G[u])if(v != F)dfs1(v,u),siz[u] += siz[v],(siz[son[u]]<siz[v]?son[u]=v:0);
		}
		void dfs2(int u,int T){
			top[u] = T;if(son[u])dfs2(son[u],T);
			for(int v:G[u])if(v != fa[u] && v != son[u])dfs2(v,v);
		}
		int mn[maxn][3];//儿子的权值前 3 小。
		void dfs3(int u,int F){
			mn[u][0] = mn[u][1] = mn[u][2] = 1e9;
			for(int w:G[u])if(w != F){
				dfs3(w,u);
				if(v[w]<=mn[u][0])
					mn[u][2] = mn[u][1],mn[u][1] = mn[u][0],mn[u][0] = v[w];
				else if(v[w]<=mn[u][1])mn[u][2] = mn[u][1],mn[u][1] = v[w];
				else if(v[w]<=mn[u][2])mn[u][2] = v[w];
			}
		} 
		int GET(int u,int sn){return mn[u][0]==v[sn]?mn[u][1]:mn[u][0];}
		int GET2(int u,int x,int y){
			//u = 1 没有 fa 需要特判。强行 v[0] = 1e9 即可。豪放点。 
			int r; v[0] = 1e9;
			if(mn[u][0]!=min(v[x],v[y]))r = mn[u][0];
			else if(mn[u][1]!=max(v[x],v[y]))r = mn[u][1];
			else r = mn[u][2];return min(r,v[fa[u]]);
		}
		struct pair{int x,v;};
		std :: vector <pair> rot;
		int LCA(int x,int y){
			while(top[x]^top[y]){
				if(dep[top[x]]<dep[top[y]])x^=y^=x^=y;
				x = fa[top[x]];
			}return dep[x]<dep[y]?x:y;
		}
		//这 tm 好像可以直接写一遍 BFS 解决。我真是 nm 傻B。 
		//屁。 还有 12 不要了是不是？？？？我是shab 
		void gr(int x,int y){
			int lca = LCA(x,y);rot.clear();
//			printf("%d %d %d\n",lca,x,y);
			//1e9 表示 N/A 
			if(x == lca){
				int p = y;while(p^fa[x])rot.push_back({p,inf}),p = fa[p];
				std :: reverse(rot.begin(),rot.end());
				for(int i=0;i<rot.size()-1;++i)
					rot[i].v = GET(rot[i].x,rot[i+1].x);
			}else if(y == lca){
				int p = x;while(p^fa[y])rot.push_back({p,inf}),p = fa[p];
				for(int i=1;i<rot.size();++i)
					rot[i].v = GET(rot[i].x,rot[i-1].x);					
			}else{
				std::vector<pair> xs,ys;int p;
				p = x;while(p^lca)xs.push_back({p,inf}),p = fa[p];
				p = y;while(p^lca)ys.push_back({p,inf}),p = fa[p];
				std :: reverse(ys.begin(),ys.end());
				for(int i=1;i<xs.size();++i)xs[i].v = GET(xs[i].x,xs[i-1].x);
				for(int i=0;i<ys.size()-1;++i)ys[i].v = GET(ys[i].x,ys[i+1].x);
				for(auto p:xs)rot.push_back(p);
				rot.push_back({lca,GET2(lca,xs.back().x,ys.front().x)});
				for(auto p:ys)rot.push_back(p); 
//				puts("SDFSDFSD");
			}
//			fprintf(stderr,"siz:%d\n",rot.size());
//			for(auto p:rot)fprintf(stderr,"%d %d %d\n",p.x,v[p.x],p.v);
		}
		struct Mat{ll a[4][4];Mat(){memset(a,0x3f,sizeof(a));}};
		struct Vec{
			ll a[4];Vec(){memset(a,0x3f,sizeof(a));}
			Vec operator *(Mat &b){
				Vec r;
				for(int j=0;j<4;++j)
					for(int k=0;k<4;++k)
						r.a[j] = min(r.a[j],a[k]+b.a[k][j]);
				return r;
			}
		};
		ll sol(){
			Vec now;Mat Trs;
			now.a[0] = v[rot[0].x];
			for(int i=1;i<rot.size();++i){
				Trs.a[0][0] = Trs.a[1][0] = Trs.a[2][0] = Trs.a[3][0] = v[rot[i].x];
				Trs.a[0][1] = 0,Trs.a[2][2] = Trs.a[3][2] = rot[i-1].v,Trs.a[1][3] = 0;
				now = now*Trs;
			}
			return now.a[0];
		}
		void Solve(){
			dfs1(1,0),dfs2(1,1),dfs3(1,0);
			for(int i=1,x,y;i<=q;++i)x = re(),y = re(),gr(x,y),printf("%lld\n",sol());
		}
	}
	int main(){
		freopen("transmit.in","r",stdin);
		freopen("transmit.out","w",stdout);
		n = re(),q = re(),k = re();
		for(int i=1;i<=n;++i)v[i] = re();
		for(int i=1,x,y;i<n;++i)x = re(),y = re(),G[x].push_back(y),G[y].push_back(x);
		if(k == 1)Subtask_1::Solve();
		if(k == 2)Subtask_2::Solve();
		if(k == 3)Subtask_3::Solve();
		return 0;
	}
}
int main(){return KamiyamaShiki::main();}
/*
检查 Corner Case
检查快读（正负数，buf[1<<!6]）
nmq 不要写反。
对拍不要骗自己。
KamiyamaShiki 是神山识。 
1145141919810
1145141919810
T3 不会。 T3 不会。 T3 不会。 
寄了。这下是彻底寄了。
寄了。这下是彻底寄了。
寄了。这下是彻底寄了。
不管怎么被加油都是会寄的吧。
我什么时候才会做的来 T3 呢？
我什么时候才能随随便便就把 T4 的最后 12pts 敲出来呢？
菜啊。菜啊。菜啊。  
*/

