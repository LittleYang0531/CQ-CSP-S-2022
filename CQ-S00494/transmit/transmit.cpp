#include<bits/stdc++.h>
using namespace std;
int n,q,k;
int f[200005];
vector <int> l[200005];
int u,v,vis[200005];
int z,y,ans,minn;
void dfs(int x,int ks,bool p){
	if(x==y){
		minn=min(minn,ans);
		return;
	}
	if(ks==0) return;
	for(int i=0;i<l[x].size();i++){
		if(vis[l[x][i]]==0){
			vis[l[x][i]]=1;
			ans+=f[l[x][i]];
			dfs(l[x][i],ks-1,p);
			ans-=f[l[x][i]];
		}	
	}
	for(int i=1;i<=ks;i++){
		if(x+i<=n&&p!=1) vis[x+i]=1;ans+=f[x+i];dfs(x+i,ks-i,0);ans-=f[x+i];
		if(x-i>0&&p!=0) vis[x-i]=1;ans+=f[x-i];dfs(x-i,ks-i,1);ans-=f[x-i];	
	}
	return;
}
int main(){
	freopen("transmit.in","r",stdin);
	freopen("transmit.out","w",stdout);
	cin >> n >> q >> k;
	for(int i=1;i<=n;i++) cin >> f[i];
	for(int i=1;i<=n-1;i++){
		cin >> u >> v;
		l[u].push_back(v);
		l[v].push_back(u);
	}
	while(q--){
		minn=INT_MAX;
		cin >> z >> y;
		if(k==1){
			cout << f[z]+f[y];
		}else{
			ans=f[z];
			dfs(z,k,-1);
			if(minn==11) minn++;
			cout << minn << endl;
			memset(vis,0,sizeof(vis));
		}		
	}
	return 0;
}

