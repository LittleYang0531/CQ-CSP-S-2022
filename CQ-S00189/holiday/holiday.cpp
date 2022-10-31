#include<bits/stdc++.h>
using namespace std;
int n,m,k;
long long s[2509],ma=-1,b=0;
vector<int>a[2509];
int vis[2509];
void dfs(int x,long long sum,int cs,int p) {
	if(cs==5&&x==1) {
		ma=max(ma,sum);
		return ;
	}
	if(cs==5)return ;
	for(int i=0; i<a[x].size(); i++) {
		if(!vis[a[x][i]]) {
			vis[a[x][i]]=1;
			dfs(a[x][i],sum+s[a[x][i]],cs+1,0);
			vis[a[x][i]]=0;
		}if(p<k)
			{
				dfs(a[x][i],sum,cs,p+1);
			}
	}
}
int main() {
	freopen("holiday.in","r",stdin);
	freopen("holiday.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=2; i<=n; i++) {
		scanf("%lld",&s[i]);
	}
	for(int i=1; i<=m; i++) {
		int u,v;
		scanf("%d%d",&u,&v);
		a[u].push_back(v);
		a[v].push_back(u);
	}
	dfs(1,0,0,0);
	cout<<ma;
	return 0;
}

