#include<bits/stdc++.h>
#define ll long long
using namespace std;
struct node{
	int next,to;
}a[20005];
int h[20005],cnt,n,k,q;
void add(int x,int y){
	a[++cnt].to=y;
	a[cnt].next=h[x];
	h[x]=cnt;
}
ll dis[20005],sum,ans,l,r;
bool vis[20005];
void dfs(int tot,int kk,int time){
	if(ans>sum)return;
	if(tot==r){
		sum=min(sum,ans);
		return;
	}
	if(time>=n)return;
	for(int i=h[tot];i;i=a[i].next){
		int y=a[i].to;
		if(kk>0)dfs(y,kk-1,time+1);
		
		if(vis[y])continue;
		vis[y]=1;
		ll aa=ans;
		ans+=dis[y];
		dfs(y,k,time+1);
		ans=aa;
		vis[y]=0;	
	}
	return;
}
int main(){
	freopen("transmit.in","r",stdin);
	freopen("transmit.out","w",stdout);
	cin>>n>>q>>k;
	for(int i=1;i<=n;i++){
		cin>>dis[i];
	}
	for(int i=1;i<=n-1;i++){
		int x,y;
		cin>>x>>y;
		add(x,y);
		add(y,x);
	}
	for(int i=1;i<=q;i++){
		cin>>l>>r;
		sum=1e15;
		ans=0;
		dfs(l,k,1);
		cout<<sum+dis[l]+dis[r]<<endl;
	}
	return 0;
}
