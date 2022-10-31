//No more time, No more chance.
#include <queue>
#include <cstdio>
#include <vector>
#include <cstring>
#include <algorithm>
using std :: min;using std :: max;
namespace KamiyamaShiki{
	typedef long long ll;
	const int maxn = 2505;
	int n,m,k,dis[maxn][maxn];ll V[maxn],ans;
	std :: vector <int> G[maxn],vec[maxn];
	void bfs(int S,int *d){
		std :: queue<int> q;q.push(S),d[S] = 0;
		while(!q.empty()){
			int u = q.front();q.pop();
			for(int v:G[u])if(d[v] == 0x3f3f3f3f)d[v] = d[u]+1,q.push(v);
		}
	}
	int main(){
		freopen("holiday.in","r",stdin);
		freopen("holiday.out","w",stdout);
		scanf("%d %d %d",&n,&m,&k),++k;
		for(int i=2;i<=n;++i)scanf("%lld",&V[i]);
		for(int i=1,x,y;i<=m;++i)
			scanf("%d %d",&x,&y),G[x].push_back(y),G[y].push_back(x);
		memset(dis,0x3f,sizeof(dis));
		for(int i=1;i<=n;++i)bfs(i,dis[i]);
//		for(int i=1;i<=n;++i){
//			for(int j=1;j<=n;++j)
//				printf("%d%c",dis[i][j],"\n "[j<n]);
//		}
		for(int u=2;u<=n;++u)
			for(int v=2;v<=n;++v)
				if(u != v)
					if(dis[1][u] <= k && dis[u][v] <= k)
						vec[v].push_back(u);
		for(int i=2;i<=n;++i)std :: sort(vec[i].begin(),vec[i].end(),[](int x,int y){return V[x]>V[y];});
		for(int u=2;u<=n;++u)
			for(int v=2;v<=n;++v){
				if(u != v && dis[u][v] <= k){
					for(int i=0;i<=2&&i<vec[u].size();++i)
						for(int j=0;j<=2&&j<vec[v].size();++j)
							if(vec[u][i] != v && vec[v][j] != u && vec[u][i] != vec[v][j])
								ans = max(ans,V[u]+V[v]+V[vec[u][i]]+V[vec[v][j]]);
				}
			}
		printf("%lld\n",ans);
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

