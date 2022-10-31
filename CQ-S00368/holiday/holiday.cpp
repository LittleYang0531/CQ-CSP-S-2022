#include<bits/stdc++.h>
using namespace std;

const int MAXN=20005;

int N,M,K,ans;
int tot,a[5005],head[MAXN],to[MAXN],nxt[MAXN],vis[5005];
void add(int x,int y) {
	tot++;
	nxt[tot]=head[x];
	to[tot]=y;
	head[x]=tot;
}
void dfs(int x,int y,int s,int l){

	if(y==4){
		ans=max(ans,s);

		
		return ;
	}
	for(int i=head[x];i;i=nxt[i]){
		if(to[i]){
			if(l>K){
			
			return ;} 
			if(l==K){
			if(vis[to[i]]==1){
				
			return ;} 
			else{
			vis[to[i]]=1;
			dfs(to[i],y+1,s+a[to[i]],0);
			vis[to[i]]=0;
				}}
			if(l<K)
			{	
			if(vis[to[i]]==0){
				vis[to[i]]=1;
				dfs(to[i],y+1,s+a[to[i]],0);
				vis[to[i]]=0;
				dfs(to[i],y,s,l+1);
				}
			else{
				dfs(to[i],y,s,l+1);
			}
			}
		}
	}
}
int main() {

	freopen("holiday.in","r",stdin);
	freopen("holiday.out","w",stdout);
	memset(vis,0,sizeof vis);
	cin>>N>>M>>K;
	for(int i=2; i<=N; i++) {
		cin>>a[i];
	}
	vis[1]=1;
	for(int i=1; i<=M; i++) {
		int x,y;
		cin>>x>>y;
		add(x,y);
		add(y,x);
	}

	dfs(1,0,0,0);
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

