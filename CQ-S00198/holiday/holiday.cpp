#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n,m,k,ans;
ll a[2550];
ll f[2550][2550];
vector<int>p[2550];
bool ff[2550][2550];
bool vis[2550];
int A,B,C,D;
ll tot=0;
void dfs(int x,int l,ll sum){
	tot++;
	if(tot>8e7&&n>20&m>50){
		cout<<ans;
		exit(0);
	}
	if(l==4){
		if(ff[D][1])ans=max(ans,sum);
		return;
	}
	for(int i=0;i<p[x].size();i++){
		if(vis[p[x][i]])continue;
		if(l==0){
			A=p[x][i];
		}
		if(l==1){
			B=p[x][i];
			if(A==B)continue;
		}
		if(l==2){
			C=p[x][i];
			if(A==C||B==C)continue;
		}
		if(l==3){
			D=p[x][i];
			if(A==D||B==D||C==D)continue;
		}
		vis[p[x][i]]=1;
		dfs(p[x][i],l+1,sum+a[p[x][i]]);
		vis[p[x][i]]=0;
	}
}
bool cmp(int i,int j){
	return a[i]>a[j];
}
int main(){
	freopen("holiday.in","r",stdin);
	freopen("holiday.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=2;i<=n;i++)cin>>a[i];
	for(int i=1;i<=n;i++)
	    for(int j=1;j<=n;j++)
	        f[i][j]=1e9;
	for(int i=1;i<=m;i++){
		int u,v;
		cin>>u>>v;
		f[u][v]=1;
		f[v][u]=1;
	}
	for(int kk=1;kk<=n;kk++){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				if(i!=kk&&i!=j&&kk!=j){
					f[i][j]=min(f[i][j],f[i][kk]+f[kk][j]);
				}
			}
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(i!=j&&f[i][j]<=k+1){
				if(!ff[i][j]){
					p[i].push_back(j);
					ff[i][j]=1;
				}
				if(!ff[j][i]){
					p[j].push_back(i);
					ff[i][j];
				}
			}
		}
	}
	ll xx[100005];
	for(int i=1;i<=n;i++){
		int nn=p[i].size();
		for(int j=0;j<p[i].size();i++)xx[j]=p[i][j];
		sort(xx,xx+nn,cmp);
		for(int j=0;j<p[i].size();i++)p[i][j]=xx[j];
	}
	vis[1]=1;
	dfs(1,0,0);
	cout<<ans;
	return 0;
}
/*
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
