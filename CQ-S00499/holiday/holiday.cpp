#include <bits/stdc++.h>
#define int long long 
using namespace std ;
const int N=2510;
const int M=2e4+10;
int n,m,k,tot,Sum;
int a[N],head[M];
int mp[N][N],res;
struct node{
	int x,y;
}edg[M];
void add(int x,int y){
	edg[++tot].x=y;
	edg[tot].y=head[x];
	head[x]=tot;
}
void dfs(int now,int x,int cnt,int sum){
	if(cnt>k+1) return ;
	if(sum>mp[now][x]) mp[now][x]=sum;
	if(sum>mp[x][now]) mp[x][now]=sum;
	if(cnt==k+1) return ;
	for(int i=head[x];i;i=edg[i].y) {
		int to=edg[i].x;
		dfs(now,to,cnt+1,a[to]);
	}
}
bool vis[N];
void DFS(int x,int cnt,int sum){
	if(cnt==4) {
		if(!mp[x][1]) return ;
		res=max(res,sum);
		return ;
	}
	vis[x]=1;
	for(int i=x+1;i<=n;i++) {
		if(mp[x][i]!=-1&&!vis[i]) {
			DFS(i,cnt+1,sum+mp[x][i]);
		}
	} 
	vis[x]=0;
}
signed main(){
    freopen("holiday.in","r",stdin);
    freopen("holiday.out","w",stdout);
    scanf("%lld%lld%lld",&n,&m,&k);
    for(int i=1;i<=n;i++) {
    	for(int j=1;j<=n;j++){
    		mp[i][j]=(long long)-1;
		}
	}
    for(int i=2;i<=n;i++) scanf("%lld",&a[i]);
    for(int i=1;i<=m;i++) {
    	int x,y;
    	scanf("%lld%lld",&x,&y);
    	add(min(x,y),max(y,x));
	}
	for(int i=1;i<=n;i++) dfs(i,i,0,0);
	DFS(1,0,0);
	printf("%lld",res);
	return false;
}
/*
8 8 1
9 7 1 8 2 3 6
1 2
2 3
3 4
4 5
5 6
6 7
7 8
8 1

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
