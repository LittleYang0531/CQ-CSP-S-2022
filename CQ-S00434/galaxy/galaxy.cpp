#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <vector>
#include <string.h>
#include <queue>
#include <climits>
using namespace std;
const int maxn = 10005;		//混点分(我太弱了~) 
int n,m,q,t,mem[maxn];					//mem:用于记忆化checkft 
bool adj[maxn][maxn],sta[maxn][maxn],vis[maxn];	//adj:是否存在该虫洞,sta:该虫洞是否被摧毁,vis:checkft用 
bool checkgo(){				//是否可以实现连续穿梭 
	int cnt;
	for(int i=1;i<=n;i++){
		cnt=0;
		for(int j=1;j<=n;j++){
			if(j == i)	continue;
			if(adj[i][j] == 1 && sta[i][j] == 1)	cnt++;
			if(cnt > 1)	return false;
		}
		if(cnt == 0)	return false;
	}
	return true;
}
bool checkft(int d){			//是否可以反击 
	if(mem[d] == 1) return true;
	if(mem[d] == 0)	return false;	
	for(int i=1;i<=n;i++){
		if(adj[d][i] && sta[d][i]){
			if(vis[i])	return true;
			vis[i] = 1;
			mem[d] = checkft(i);
			vis[i] = 0;
		}
	}
	return false;
}
int main(){
	freopen("galaxy.in","r",stdin);
	freopen("galaxy.out","w",stdout);
	
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++){
		int tmpu,tmpv;
		scanf("%d%d",&tmpu,&tmpv);
		adj[tmpu][tmpv] = 1;
		sta[tmpu][tmpv] = 1;
	}
	scanf("%d",&q);
	while(q--){
		memset(mem,-1,sizeof(mem));
		scanf("%d",&t);
		if(t == 1){
			int u,v;
			scanf("%d%d",&u,&v);
			sta[u][v] = 0;
		}
		else if(t == 2){
			int u;
			scanf("%d",&u);
			for(int i=1;i<=n;i++){
				if(adj[i][u] == 1 && sta[i][u] == 1)	sta[i][u] = 0;
			}
		}
		else if(t == 3){
			int u,v;
			scanf("%d%d",&u,&v);
			sta[u][v] = 1;
		}
		else{
			int u;
			scanf("%d",&u);
			for(int i=1;i<=n;i++){
				if(adj[i][u] == 1 && sta[i][u] == 0)	sta[i][u] = 1;
			}
		}
		bool flag = 0;
		if(checkgo()){
			for(int i=1;i<=n;i++){
				memset(vis,0,sizeof(vis));
				if(!checkft(i)){
					flag = 0;
					break;
				}
			}
			flag = 1;
		}
		if(!flag)	printf("NO\n");
		else	printf("YES\n");
	}
}
