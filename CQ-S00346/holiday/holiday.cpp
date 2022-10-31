#include<iostream>
#include<algorithm>
#include<cstdio>
#include<vector>
#define lll long long
using namespace std;
int n,m,k;
vector<int>e[2505];
lll w[2505];
int vis[2505];
lll maxx=(-999999LL);
void dfs(int nw,lll scr,int stp){
	if(stp==5&&nw!=1){
		return;
	}
	int x;
	for(int i=0;i<(int)e[nw].size();i++){
		x=e[nw][i];
		if(x==1&&stp==4){
			maxx=max(maxx,scr);
			return;
		}
		else if(!vis[x]){
			if(stp==4){
				return;
			}else{
				vis[x]=1;
				dfs(x,scr+w[x],stp+1);
				vis[x]=0;
			}
		}
	}
}
int main(){
	freopen("holiday.in","r",stdin);
	freopen("holiday.out","w",stdout);
	scanf("%d%d%d",&n,&m,&k);
	w[1]=0LL;
	for(int i=2;i<=n;i++){
		scanf("%lld",&w[i]);
	}
	int x,y;
	for(int i=1;i<=m;i++){
		scanf("%d%d",&x,&y);
		e[x].push_back(y);
		e[y].push_back(x);
	}
	vis[1]=1;
	dfs(1,0LL,0);
	cout<<maxx;
	
	
	return 0;
}
