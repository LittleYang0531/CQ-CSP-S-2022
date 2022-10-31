#include<iostream>
#include<queue>
#include<vector>
#define int long long
using namespace std;
long long n,vis[2005],dis[2005],f[2005],m,q,k;
struct node{
	long long v,w;
	node(long long x,long long y){
		v=x;
		w=y;
	}
	operator <(const node &x)const{
		return w<x.w;
	}
};
vector <int> a[2005];
long long djstl(long long x,long long y){
	for(long long i=0;i<=n;i++){
		vis[i]=0;
		dis[i]=1e9;
	}
	dis[x]=f[x];
	priority_queue<node> q;
	q.push(node(x,f[x]));
	while(!q.empty()){
		long long u=q.top().v;q.pop();
		if(vis[u]==1)continue;
//		cout<<u<<" "<<dis[u]<<endl;
		vis[u]=1;
		for(long long i=0;i<a[u].size();i++){
			long long v=a[u][i];
			if(dis[v]>f[v]+dis[u]){
				dis[v]=f[v]+dis[u];
				q.push(node(v,dis[v]));
			}
		}
		
	}
	return dis[y];
}
 main(){
	freopen("transmit.in","r",stdin);
	freopen("transmit.out","w",stdout);
	scanf("%lld%lld%lld",&n,&q,&k);	
	for(long long i=1;i<=n;i++)scanf("%lld",&f[i]);
	
	for(long long i=1;i<=n-1;i++){
		long long u,v;
		scanf("%lld%lld",&u,&v);
		a[u].push_back(v);
		a[v].push_back(u);
	}
	for(long long i=1;i<=q;i++){
		long long u,v,sum=1;
		scanf("%lld%lld\n",&u,&v);
		cout<<djstl(u,v);
	}	
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
