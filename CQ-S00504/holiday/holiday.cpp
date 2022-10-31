#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
long long n,m,k,f[2505],u,v,q[2505];
vector<long long> a[2505];
long long dfs(long long u,long long tp){
	if(tp==5&&u==1){
//		cout<<1;
		return 0;
	}
	if(tp==5&&u!=1)return -1e18;
	
	if(q[u]==1)return -1e18;
//	if(tp!=5&&u==1)return -1e18;
	
	q[u]=1;
	long long ans=-1e18;
	for(int i=0;i<a[u].size();i++){
		ans=max(ans,dfs(a[u][i],tp+1));		
//		cout<<ans;
	}
	q[u]=0;	
	return ans+f[u];
	
} 
int main(){
	freopen("holiday.in","r",stdin);
	freopen("holiday.out","w",stdout);
	scanf("%lld%lld%lld",&n,&m,&k);
		for(int i=2;i<=n;i++)
			scanf("%lld",&f[i]) ;
		for(int i=1;i<=m;i++){
			scanf("%lld%lld",&u,&v);
			a[u].push_back(v);
			a[v].push_back(u);
		}
//		cout<<endl<<endl;;
		 
		printf("%d",dfs(1,0));
//	for(int i=1;i<=n;i++){
//		for(int j=1;j<=4;j++)
//			cout<<ans1[i][j]<<" "; 
//			cout<<endl;
//	}
		
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
