#include <iostream>
#include <cstdio>
#include <queue>
#include <cstring>
#include <algorithm>
using namespace std;
void fine(){
	freopen("holiday.in","r",stdin);
	freopen("holiday.out","w",stdout);
}
struct zjh{
	long long to,next;
}add[20005];
long long h[2505],cnt = 0,lzq[2505][2505],res[2505],n,m,kk,ans = -0x3f3f3f3f;
struct ycy{
	long long a,step;
};
bool vis[2505];
void addedge(long long a,long long b){
	add[++cnt].to = b;
	add[cnt].next = h[a];
	h[a] = cnt;
}
void bfs(long long u){
	queue <ycy> q;
	ycy b,v;
	b.a = u;
	b.step = 0;
	q.push(b);
	while(q.size()){
		v = q.front();
		for(long long i = h[v.a];i;i = add[i].next){
			if(!vis[add[i].to]){
				vis[add[i].to] = 1;
				lzq[u][add[i].to] = v.step;
				b.a = add[i].to;
				b.step = v.step+1;
				q.push(b);
			}
		}
		q.pop();
	}
}
long long wby[2505];
void dfs(long long u,long long step,long long deep){
//	cout<<u<<" "<<step<<" "<<deep<<" "<<prt<<endl;
	if(deep == 4){
		if(lzq[u][1] > kk) return ;
		ans = max(ans,step);
		return ;
	}
	for(long long i = 1;i<=n;i++){
		if(i == u||vis[i]||lzq[i][u] > kk||lzq[i][1] > (4-deep)*kk) continue;
		vis[i] = 1;
		dfs(i,step+res[i],deep+1);
		vis[i] = 0;
	}
}
int main(){
	fine();
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	long long a,b;
	cin>>n>>m>>kk;
	memset(lzq,0x3f,sizeof(lzq));
	for(long long i = 2;i<=n;i++){
		cin>>a;
		res[i] = a;
	}
	for(long long i = 1;i<=m;i++){
		cin>>a>>b;
		addedge(a,b);
		addedge(b,a);
	}
	for(long long i = 1;i<=n;i++){
		vis[i] = 1;
		bfs(i);
		memset(vis,0,sizeof(vis));
	}
	vis[1] = 1;
	dfs(1,0,0);
	cout<<ans;
	return 0;
}
/*
7 9 0
1 1 1 2 3 4
1 2
2 3
3 4
1 5
1 6
1 7
5 4
6 4
7 4
*/

