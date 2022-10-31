//No more time, No more chance.
#include <set>
#include <cstdio>
#include <vector>
#include <cstdlib>
int re(){
	char c;int w=1;
	while((c=getchar())<'0'||c>'9')if(c == '-')w=-1;
	int res = c-'0';
	while((c=getchar())>='0'&&c<='9')res = res*10+c-'0';
	return res*w;
}
namespace KamiyamaShiki{
	typedef long long ll;
	const int maxn = 5e5+5;
	int n,m,q;
	std :: vector <int> G[maxn],GT[maxn];
	namespace Subtask_1{
		int vis[1005][1005],in[1005],ot[1005];
		void Solve(){
			for(int u=1;u<=n;++u)
				for(int v:G[u])vis[u][v] = 1,++in[v],++ot[u];
			while(q--){
				int t,x,y;t = re();
				if(t == 1)x = re(),y = re(),vis[x][y] = 0,--in[y],--ot[x];
				if(t == 3)x = re(),y = re(),vis[x][y] = 1,++in[y],++ot[x];
				if(t == 2){
					x = re();
					for(int i=1;i<=n;++i)
						if(vis[i][x] == 1)
							vis[i][x] = 0,--ot[i],--in[x];
				}
				if(t == 4){
					x = re();
					for(int v:GT[x])
						if(vis[v][x] == 0)
							vis[v][x] = 1,++ot[v],++in[x];
				}
				int Flg = 1;
				for(int i=1;i<=n;++i)Flg &= (ot[i] == 1);
				puts(Flg?"YES":"NO");
			}
		}
	}
	namespace Subtask_2{
		int ot[maxn];
		std :: multiset<int> ots;
		std :: set <int> in[maxn];
		void ad(int x){ots.erase(ots.find(ot[x])),ots.insert(++ot[x]);}
		void mn(int x){ots.erase(ots.find(ot[x])),ots.insert(--ot[x]);}
		void Solve(){
			for(int u=1;u<=n;++u)	
				for(int v:G[u])
					in[v].insert(u),++ot[u];
			for(int u=1;u<=n;++u)ots.insert(ot[u]);
			while(q--){
				int t,x,y;t = re();
				if(t == 1){
					x = re(),y = re(),mn(x);
					in[y].erase(x);
				}
				if(t == 3){
					x = re(),y = re(),ad(x);
					in[y].insert(x);
				}
				if(t == 2){
					x = re();
					for(int v:in[x])mn(v);
					in[x].clear();
				}
				if(t == 4){
//					puts("我寄了。我寄了啊。我该怎么办啊。"),exit(0);
					for(int v:GT[x])	
						if(in[x].find(v) == in[x].end())
							in[x].insert(v),ad(v);
				}
				if(*ots.begin() == 1 && *--ots.end() == 1)puts("YES");else puts("NO");
			}
		}
	}
	int main(){
		freopen("galaxy.in","r",stdin);
		freopen("galaxy.out","w",stdout);
		n = re(),m = re();
		for(int i=1,x,y;i<=m;++i)
			x = re(),y = re(),G[x].push_back(y),GT[y].push_back(x);
		q = re();
		if(n <= 1000 && m <= 10000 && q <= 1000)Subtask_1::Solve();
		else Subtask_2::Solve();
		return 0;
	}
}
int main(){return KamiyamaShiki::main();}
/*
检查 Corner Case
检查快读（正负数，buf[1<<!6]）
nmq 不要写反。
对拍不要骗自己。
*/

