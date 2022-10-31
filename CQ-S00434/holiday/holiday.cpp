#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <vector>
#include <string.h>
#include <queue>
#include <climits>
using namespace std;
typedef pair<int,long long> pii;
int n,m,k;
pii a[3000];		//a.first:该点的序数,a.second:该点的分数 
long long ans;
bool cmp(pii x,pii y){
	return x.second > y.second;
}
bool flag,adj[3000][3000],visdes[3000],vischeck[3000];	//visdes:该目的地是否已作为要访问的目的地  vischeck:check时该点是否被走过 
bool check(int u,int v,int step){	//从u走到v 
		if(step > k+1)	return false;
		if(u == v)	return true;
		for(int i=1;i<=n;i++){
			if(adj[u][i]){
				vischeck[i] = 1;
				bool flag = check(i,v,step+1);
				vischeck[i] = 0;
				if(flag)	return true;
			}
		}
		return false;
}
void dfs(int d,long long pre,int cnt){	//pre是当前得分,cnt是已经访问了的目标景点个数
	if(flag)	return; 
	if(cnt == 4){
		if(check(d,1,0))	ans = pre,flag = 1;
		return;
	}
	for(int i=1;i<=n;i++){		//i是想去的贪心目标点 
		if(a[i].first == 1)	continue;	//家不是景点 
		if(!visdes[a[i].first]){	 
			if(check(d,a[i].first,0)){		//还要看访不访问的了
				visdes[a[i].first] = 1;
				dfs(a[i].first,pre+a[i].second,cnt+1);
				visdes[a[i].first] = 0;
			}
		}
	}
}
int main(){
	freopen("holiday.in","r",stdin);
	freopen("holiday.out","w",stdout);
	
	scanf("%d%d%d",&n,&m,&k);
	for(int i=2;i<=n;i++){
		scanf("%lld",&a[i].second);
		a[i].first = i;
	}
	a[1].first = 1,a[1].second = 0;
	sort(a+1,a+1+n,cmp);
	for(int i=1;i<=m;i++){
		int x,y;
		scanf("%d %d",&x,&y);
		adj[x][y] = 1;
		adj[y][x] = 1;
	}
	dfs(1,0,0);
	printf("%lld",ans);
} 
