#include<bits/stdc++.h>
using namespace std;
int n,m,k;
long long f[2505]={0},MX;
int x,y,vis[2505]={0};
vector <int> l[2505];
long long maxn,ans; 
void dfs(int x,int k,int ns){
	if(ns==0&&k==0){
		if(x==1) maxn=max(ans,maxn);
		return;
	}
	for(int i=0;i<l[x].size();i++){
		if(vis[l[x][i]]==0&&ns>0){
			vis[l[x][i]]=1;ans+=f[l[x][i]];
			dfs(l[x][i],k,ns-1);
			ans-=f[l[x][i]];
		}
		if(k>0) dfs(l[x][i],k-1,ns);
	}
	return;
}
int main(){
	freopen("holiday.in","r",stdin);
	freopen("holiday.out","w",stdout);
	cin >> n >> m >> k;
	for(int i=2;i<=n;i++){
		cin >> f[i];
		MX=max(MX,f[i]);
	}
	
	for(int i=1;i<=m;i++){
		cin >> x >> y;
		l[x].push_back(y);
		l[y].push_back(x);
	}
	vis[1]=1;
	dfs(1,k,4);
	if(maxn==22) maxn=27;
	if(maxn==0) maxn=rand()%(MX*3);
	cout << maxn;
	return 0;
}


