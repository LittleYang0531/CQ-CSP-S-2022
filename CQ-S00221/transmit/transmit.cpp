#include<bits/stdc++.h>
using namespace std;
int n,m,zc,tmp=10000005;
long long t[2505];
bool r[2505][2505],vis[2505];
void dfs(int x,int y,int s){
	if(x==y){
		tmp=min(tmp,s);
		return ;
	}
	for(int i=1;i<=n;i++){
		if(r[x][i]&&!vis[i]){
			vis[i]=1;
			dfs(i,y,s+t[i]);
			vis[i]=0;
		}
	}
}
int main(){
	freopen("transmit.in","r",stdin);
	freopen("transmit.out","w",stdout);
	scanf("%d%d%d",&n,&m,&zc);
	for(int i=1;i<=n;i++)scanf("%lld",&t[i]);
	for(int i=1;i<n;i++){
		int x,y;
		scanf("%d%d",&x,&y);
		r[x][y]=1;
		r[y][x]=1;
	}
	for(int i=1;i<=m;i++){
		int x,y;
		scanf("%d%d",&x,&y);
		memset(vis,0,sizeof(vis));
		vis[x]=1;
		dfs(x,y,0);
		printf("%d\n",tmp);
		tmp=10000005;
	}
	return 0;
}
