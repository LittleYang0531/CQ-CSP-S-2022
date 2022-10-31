#include<bits/stdc++.h>
using namespace std;
struct node{
	int next,to;
}a[20005];
int h[20005],cnt,n,m,k;
void add(int x,int y){
	a[++cnt].to=y;
	a[cnt].next=h[x];
	h[x]=cnt;
}
int dis[20005],sum=-1,ans;
bool vis[20005];
void dfs(int tot,int kk,int time){
	if(time==5){
		if(tot==1)sum=max(sum,ans);
		return;
	}
	for(int i=h[tot];i;i=a[i].next){
		//²»»»³µ
		int y=a[i].to;
		if(kk>0)dfs(y,kk-1,time); 
		if(vis[y])continue;
		vis[y]=1;
		int aa=ans;
		ans+=dis[y];
		dfs(y,k,time+1);
		ans=aa;
		vis[y]=0;	
	}
	return;
}
int main(){
	freopen("holiday.in","r",stdin);
	freopen("holiday.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=2;i<=n;i++){
		cin>>dis[i];
	}
	for(int i=1;i<=m;i++){
		int x,y;
		cin>>x>>y;
		add(x,y);
		add(y,x);
	}
	dfs(1,k,0);
	cout<<sum<<endl;
	return 0;
}
