#include<cstdio>
#include<vector>
#include<cstring>
#include<queue>
using namespace std;
int n,m,q,t,u,v,vis[500005],now,deg[500005];
bool tmp,t2;
struct node{
	int to;
	bool vis;
};
vector<node> g[500005];
queue<int> que;
int main(){
	freopen("galaxy.in","r",stdin);
	freopen("galaxy.out","w",stdout);
	scanf("%d %d",&n,&m);
	for(int i = 1;i <= m;i++){
		scanf("%d %d",&u,&v);
		g[u].push_back({v,true});
		deg[u]++;
	}
	scanf("%d",&q);
	for(int i = 1;i <= q;i++){
		scanf("%d %d",&t,&u);
		if(t == 1){
			scanf("%d",&v);
			for(int j = 0;j < g[u].size();j++){
				if(g[u][j].to == v){
					deg[u]--;
					g[u][j].vis = false;
					break;
				}
			}
		}
		else if(t == 2){
			for(int j = 0;j < g[u].size();j++){
				g[u][j].vis = false;
			}
			deg[u] = 0;
		}
		else if(t == 3){
			scanf("%d",&v);
			for(int j = 0;j < g[u].size();j++){
				if(g[u][j].to == v){
					deg[u]++;
					g[u][j].vis = true;
					break;
				}
			}
		}
		else{
			for(int j = 0;j < g[u].size();j++){
				g[u][j].vis = true;
			}
			deg[u] = g[u].size();
		}
		tmp = true;
		for(int j = 1;j <= n;j++){
			vis[j] = 0;
			if(deg[j] != 1){
				tmp = false;
				break;
			}
		}
		if(tmp){
			que.push(1);
			vis[1] = 1;
			t2 = false;
			while(!que.empty() && !t2){
				now = que.front();
				que.pop();
				for(int j = 0;j < g[now].size();j++){
					if(g[now][j].vis){
						if(vis[g[now][j].to] == 0){
							que.push(g[now][j].to);
							vis[g[now][j].to] = 1;
						}
						else{
							t2 = true;
							break;
						}
					}
				}
			}
			tmp = t2;
		}
		if(tmp){
			printf("YES\n");
		}
		else{
			printf("NO\n");
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
