#include<bits/stdc++.h>
#define int long long
#define x first
#define y second
using namespace std;
typedef pair<int,int> pii;
const int N=2505;
int n;
int m,k;
int mx=0;
int a[N];
int ans=0;
bool st[N];
bool dis[N][N];
int h[N],idx=0;
struct Node{
	int to,ne;
}tr[N*2];
void add(int u,int v){
	tr[idx].to=v,tr[idx].ne=h[u],h[u]=idx++;
}
void dfs(int x,int u,int p){
	for(int i=h[u];i!=-1;i=tr[i].ne){
		int to=tr[i].to;
		if(st[to]) continue;
		st[to]=true;
		dis[x][to]=true;
		if(p+1<=k) dfs(x,to,p+1);
	}
}
void work(int u,int p,int s){
	if(p>4){
		ans=max(ans,s);
		return ;
	}
	if(s+(5-p)*mx<=ans) return ;
	if(p==4){
		for(int i=2;i<=n;i++){
			if(!st[i]&&dis[u][i]&&dis[i][1]) st[i]=true,work(i,p+1,s+a[i]),st[i]=false;
		}
	}else{
		for(int i=2;i<=n;i++) if(!st[i]&&dis[u][i]) st[i]=true,work(i,p+1,s+a[i]),st[i]=false;
	}
}
signed main(){
	freopen("holiday.in","r",stdin);
	freopen("holiday.out","w",stdout);
	memset(h,-1,sizeof h);
	memset(dis,false,sizeof dis);
	scanf("%lld%lld%lld",&n,&m,&k);
	for(int i=2;i<=n;i++) scanf("%lld",&a[i]),mx=max(mx,a[i]);
	while(m--){
		int u,v;
		scanf("%lld%lld",&u,&v);
		add(u,v),add(v,u);
	}
	for(int i=1;i<=n;i++){
		memset(st,false,sizeof st);
		st[i]=true;
		dfs(i,i,0);
	}
	memset(st,false,sizeof st);
	st[1]=true;
	work(1,1,0);
	printf("%lld\n",ans);
	return 0;
}/*
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
2 1 1 1 2 3 4
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
