#include<bits/stdc++.h>
#define int long long 
using namespace std;
int a[100005];
int u,v,f[100005];
int n,m,k,nxt[10005],head[10005],to[10005],dis[2501][2501],tot;
bool book[10005];
void add(int a,int b){nxt[++tot]=a,to[tot]=b;}
int q[100005];
int zhan,tl,hd;
bool cnm[100005];
void dij(int zaa){
	tl=2,hd=1;
	q[1]=zaa;
	book[zaa]=1;
	dis[zaa][zaa]=-1;
	for(int i=1;i<=n;i++){
		if(dis[zaa][i]==0) q[tl]=i,tl++;
	}
	tl--;
	while(tl>=hd){
		int s=q[hd];
		for(int i=1;i<=tot;i++){
			if(dis[zaa][to[i]]>dis[zaa][nxt[i]]+1){
				dis[zaa][to[i]]=dis[zaa][nxt[i]]+1;
				tl++;
				q[tl]=nxt[i];
			}
		}
		hd++;
	}
}
int dp[2501][2501];
int ponjk[100005],maxxx;
void dfs(int num,int sum,int cs){
	if(cs==5){
		if(dis[num][1]<=k){
			maxxx=max(maxxx,sum);
		}
		return;
	}
	for(int i=2;i<=n;i++){
		if(dis[num][i]<=k&&cnm[i]==0){
			cnm[i]=1;
			dfs(i,sum+a[i],cs+1);
			cnm[i]=0;
		}
	}
}
signed main(){
	freopen("holiday.in","r",stdin);
	freopen("holiday.out","w",stdout);
	memset(head,-1,sizeof head);
	cin>>n>>m>>k;
	for(int i=2;i<=n;i++)
		cin>>a[i];
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++)
			dis[i][j]=1e+8;
		f[i]=i;
	}
	for(int i=1;i<=m;i++){
		cin>>u>>v;
		add(u,v);
		add(v,u);
		dis[u][v]=0;
		dis[v][u]=0;
	}
	if(k==0){
		dfs(1,0,1);
	}
	else{
		for(int i=1;i<=n;i++){
			dij(i);
		}
		dfs(1,0,1);
	} 
	
	dfs(1,0,1);
	cout<<maxxx;
	//cout<<"fuck CCF";
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
*/
