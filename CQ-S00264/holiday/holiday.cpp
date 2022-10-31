#include <bits/stdc++.h>
using namespace std;
#define N 2500
#define M 10000
int n,m,k,tot=0;
int ver[M],head[N],net[M],edge[N],vv[N];
long long ans=0,temp=0;
int add(int x,int y){
	ver[++tot]=y,net[tot]=head[x],head[x]=tot;
}
void dfs(int x,int t,int v){
	if(v==4&&x==1){
		ans=max(ans,temp);
		return;
	}
	if(t>k)return;
	if(v>4)return;
	for(int i=head[x];i;i=net[i]){
		int y=ver[i];
		dfs(y,t+1,v);
		if(vv[y]==0&&y!=1){
			temp=temp+edge[y];
			vv[y]=1;
			dfs(y,0,v+1);
			vv[y]=0;
			temp=temp-edge[y];
		}
		
	}
}
int main(){
	freopen("holiday.in","r",stdin);
	freopen("holiday.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=2;i<=n;i++){
		cin>>edge[i];
	}
	for(int i=1;i<=m;i++){
		int x,y;
		scanf("%d%d",&x,&y);
		add(x,y);
		add(y,x);
	}
	dfs(1,0,0);
	cout<<ans;
}	



