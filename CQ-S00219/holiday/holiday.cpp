#include<bits/stdc++.h>
using namespace std;
long long n,m,k,a[2505],v[2505],ans=-1;
vector<int>b[2505];
void dfs(int now,int num,long long sum,int t){
	if(num>k)return;
	if(t==4&&now==1){
		ans=max(ans,sum);
		return;
	}
	for(int i=0;i<b[now].size();i++){
		if(v[b[now][i]]==0){
			v[b[now][i]]=1;
			dfs(b[now][i],0,sum+a[b[now][i]],t+1);
			v[b[now][i]]=0;
		}dfs(b[now][i],num+1,sum,t);
	}
}
int main(){
	freopen("holiday.in","r",stdin);
	freopen("holiday.out","w",stdout);
	scanf("%lld %lld %lld",&n,&m,&k);
	for(int i=2;i<=n;i++)scanf("%lld",&a[i]);
	for(int i=1;i<=m;i++){
		int u,v;
		scanf("%d %d",&u,&v);
		b[u].push_back(v);
		b[v].push_back(u);
	}
	dfs(1,0,0,0);
	printf("%lld",ans);
	return 0;
}/*
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
