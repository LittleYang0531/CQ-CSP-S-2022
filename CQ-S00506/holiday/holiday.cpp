#include<bits/stdc++.h>
using namespace std;
int n,m,k,ans=-1,val[100001],vis[100001],b[100001],top;
vector<int> a[10001];
void dfs(register int dx,register int jd,register int sum,register int ds){
	if(jd>=4) {
		if(ds==4) 
			ans=max(ans,sum);
		return ;
	}
	vis[dx]=1;
	for(int i=0;i<a[dx].size();i++){
		if(!vis[a[dx][i]]) dfs(a[dx][i],jd+1,sum+val[a[dx][i]],ds+1);
		else dfs(a[dx][i],jd+1,sum,ds);
	}
	dx!=1?vis[dx]=0:0;
	return ;
}
int main(){
	freopen("holiday.in","r",stdin);
	freopen("holiday.out","w",stdout);	
	cin >>n >>m >>k;
	for(int i=2;i<=n;i++) cin >>val[i];
	for(int i=1;i<=m;i++){
		int x,y;
		scanf("%ld%ld",&x,&y);
		a[x].push_back(y);
		a[y].push_back(x);
	}
	dfs(1,0,0,0);
	cout <<ans;
	return 0;
}
/*
7 9 0 
1 1 1 2 3 4 
1 2 
2 3 
3 4 
1 5 
1 6 
1 7 
5 4 
6 4 
7 4
*/
