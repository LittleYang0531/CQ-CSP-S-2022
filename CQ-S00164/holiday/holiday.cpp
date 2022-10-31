#include<bits/stdc++.h>
using namespace std;

#define ll long long

int n,m,k;
ll a[100000];
int firstt[100000];
ll dis[100000];
ll f[2510][2510];
bool vis[2510][2510];
struct node{
	int to,next;
	ll val;
}s[100000];
struct node2{
	int x,y;
}c[100000];
int cnt=0;
ll ans=0;

bool cmp(node2 a,node2 b){
	if(a.x==b.x){
		return a.y<b.y;
	}
	return a.x<b.x;
}

void add(int x,int y){
	s[++cnt].to=y;
	s[cnt].val=a[y];
	s[cnt].next=firstt[x];
	firstt[x]=cnt; 
}

void dij(int ss){
	for(int i=1;i<=n;i++){
		dis[i]=-1e18-1;
	}
	dis[ss]=0;
	queue<int> q;
	q.push(ss);
	while(!q.empty()){
		int x=q.front();
		q.pop();
		for(int i=firstt[x];i!=0;i=s[i].next){
			if(dis[s[i].to]>dis[x]+s[i].val){
				dis[s[i].to]=dis[x]+s[i].val;
				q.push(s[i].to);
			}
		}
	}
}

void dfs(int x,int ss,ll sum){
	if(x>n){
		if(ss==5){
			if(c[x-1].y==1){
				ans=max(ans,sum);
			}
		}
		return ;
	}
	if(c[x].x==c[x-1].y||x==1){
		dfs(x+1,ss+1,sum+a[c[x].y]);
	}
	dfs(x+1,ss,sum);
	return ;
}

int main(){
	freopen("holiday.in","r",stdin);
	freopen("holiday.out","w",stdout);
	scanf("%d%d%d",&n,&m,&k);
	for(int i=2;i<=n;i++){
		scanf("%lld",&a[i]);
	}
	for(int i=1;i<=m;i++){
		int x,y;
		scanf("%d%d",&x,&y);
		add(x,y);
		add(y,x);
	}
	if(k==0){
		int sum=0;
		for(int i=1;i<=n;i++){
			dij(i);
			for(int j=1;j<=n;j++){
				f[i][j]=dis[j];
				if(f[i][j]==a[j]){
					c[++sum].x=i,c[sum].y=j;
				}
			}
		}
		sort(c+1,c+1+n,cmp);
		dfs(1,0,0);
		printf("%lld",ans);
	}
	return 0;
}
/*
8 8 0
9 7 1 8 2 3 6
1 2
2 3
3 4
4 5
5 6
6 7
7 8
8 1

*/

