#include <bits/stdc++.h>
#define in(x) scanf("%lld",&x)
#define out(x) printf("%lld\n",x)
#define int long long
using namespace std ;
int n,q,k,res;
int v[200100],a[200100],b[200100];
int s[200100],t[200100];
bool vis[200100];
struct node{
	int x,y;
}edg[400100];
int head[400100],tot;
int mp[3510][3510];
void add(int x,int y){
	edg[++tot].x=y;
	edg[tot].y=head[x];
	head[x]=tot;
}
void dfs(int now,int x,int cnt,int sum){
	if(cnt>k) return ;
	if(sum>mp[now][x]) mp[now][x]=sum;
	if(cnt==k) return ;
	for(int i=head[x];i;i=edg[i].y) {
		int to=edg[i].x;
		dfs(now,to,cnt+1,v[to]);
	}
}
void DFS(int x,int y,int tim){
	if(x==y) {
		res=min(res,tim);
		return ;
	}
	vis[x]=1;
	for(int i=1;i<=n;i++){
		if(mp[x][i]!=-1&&!vis[i]){
			DFS(i,y,tim+mp[x][i]);
		}
	}
	vis[x]=false;
}
signed main(){
    freopen("transmit.in","r",stdin);
    freopen("transmit.out","w",stdout);
    in(n);
    in(q);
    in(k);
    for(int i=1;i<=n;i++) cin>>v[i];
    for(int i=1;i<=n-1;i++){
    	int a,b;
    	in(a);
    	in(b);
    	add(a,b);
    	add(b,a);
	} 
	for(int i=1;i<=n;i++) {
    	for(int j=1;j<=n;j++){
    		mp[i][j]=(long long)-1;
		}
	}
	for(int i=1;i<=n;i++) dfs(i,i,0,0);
    for(int i=1;i<=q;i++)  {
    	in(s[i]);
    	in(t[i]);
    	res=INT_MAX;
    	DFS(s[i],t[i],v[s[i]]);
    	out(res);
	}
	return false;
}
/*
7 3 3
1 2 3 4 5 6 7
1 2
1 3
2 4
2 5
3 6
3 7
4 7
5 6
1 2

10 10 3
835701672 912572995 368308854 156367225 251245604 788978650 385396264 960190423 51944511 479806606
2 1
3 2
4 2
5 3
6 3
7 2
8 7
9 1
10 9
1 7
1 5
2 1
1 9
10 5
3 10
2 9
10 2
1 4
4 7
*/
