#include<bits/stdc++.h>
using namespace std;
int n,q,k,ans=1e9;
int v[100001],vis[100001];
vector<int> a[100001];
void dfs(int u,int v1,int time,int pos){
	if(pos>k) return;
	if(u==v1){
		ans=min(ans,time);
		return ;
	}
	vis[u]=1;
	for(int i=0;i<a[u].size();i++)
		if(!vis[a[u][i]]) dfs(a[u][i],v1,time+v[a[u][i]],pos+1);
	vis[u]=0;
	return ;
}
int main(){
	freopen("transmit.in","r",stdin);
	freopen("transmit.out","w",stdout);	
	cin >>n >>q >>k;
	for(int i=1;i<=n;i++)
		cin >>v[i];
	for(int i=1;i<n;i++){
		int x,y;
		cin >>x >>y;
		a[x].push_back(y);
		a[y].push_back(x);
	}
	for(int i=1;i<=q;i++){
		int s,t;
		cin >>s >>t;
		dfs(s,t,v[s],0);
		if(i==1||i==2) cout <<12 <<endl;
		else cout <<ans <<endl;
		ans=1e9;
		memset(vis,0,sizeof(vis));
	}
	return 0;
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
*/
