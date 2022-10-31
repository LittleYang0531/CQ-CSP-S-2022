#include<bits/stdc++.h>
using namespace std;
struct data{
	long long v,nex;
}a[100000];
long long first[1000000],cnt;
void add(long long u,long long v){
	a[++cnt]=data{v,first[u]};
	first[u]=cnt;
}
long long point[1000000];
long long n,q,k;
long long w[1000000];
bool vis[1000000];
void dfs(long long u){
	vis[u]=true;
	for(long long i=first[u];i;i=a[i].nex){
		long long v=a[i].v;
		if(vis[v])continue;
		w[v]=w[u]+point[v];
		dfs(v);
	}
}
int main(){
	freopen("transmit.in","r",stdin);
	freopen("transmit.out","w",stdout);
	cin>>n>>q>>k;
	for(long long i=1;i<=n;i++)cin>>point[i];
	for(long long i=1;i<n;i++){
		long long a,b;
		cin>>a>>b;
		add(a,b);
		add(b,a);
	}
	w[1]=0;
	dfs(1);
	while(q--){
		long long s,t;
		cin>>s>>t;
		cout<<w[s]+w[t]+point[1]<<"\n";
	}
	return 0;
}

