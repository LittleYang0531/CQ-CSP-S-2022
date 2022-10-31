#include<bits/stdc++.h>
#include<vector>
using namespace std;
int n,m,k;
vector<int>ver[2505];
int s[2505];
int f[2505][2505];
long long ans=0;
void add(int x,int y){
	ver[x].push_back(y);
}
bool vis[2505];
void dfs(int node,int cur,long long sco){
	//cout<<2;
	if(cur==4){
		if(f[1][node]-1<=k&&!vis[node]){
			sco+=s[node];
			ans=max(ans,sco);
			
		}
		//cout<<1;
		return;
	}
	//bool flag=0;
	if(!vis[node]){
		vis[node]=1;
		sco+=s[node];
		//flag=1;
	}
	//for(int i=0;i<ver[node].size();i++){
	//	if(f[ver[node][i]][node]-1<k){
	//		dfs(ver[node][i],cur+1,sco);
			//else dfs(ver[node][i],cur,sco);
	//	}
	//}
	for(int i=1;i<=n;i++){
		if(f[i][node]-1<=k&&!vis[i]){
			dfs(i,cur+1,sco);
			//else dfs(ver[node][i],cur,sco);
		}
	}
	vis[node]=0;
	return;
}
int main(){
	freopen("holiday.in","r",stdin);
	freopen("holiday.out","w",stdout);
	//std::ios::sync_with_stdio(0);
	cin>>n>>m>>k;
	for(int i=2;i<=n;i++)cin>>s[i];
	for(int i=0;i<=n;i++)
		for(int j=0;j<=n;j++)
			if(i!=j)f[i][j]=0x3f3f3f3f;
	int x,y;
	for(int i=1;i<=m;i++){
		cin>>x>>y;
		add(x,y);
		add(y,x);
		f[x][y]=1;
		f[y][x]=1;
	}
	for(int k2=1;k2<=n;k2++){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				f[i][j]=min(f[i][j],f[i][k2]+f[k2][j]);
			}
		}
	}
	dfs(1,0,0);
	cout<<ans<<endl;
	return 0;
}
