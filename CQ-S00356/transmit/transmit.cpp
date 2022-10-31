#include<bits/stdc++.h>
using namespace std;
int n,q,k,u,v,Min=1e9;
int s[2505];
int tot,had[2505],to[10005],nxt[10005];
bool vis[2505];
void add(int u,int v) {
	nxt[++tot]=had[u];
	had[u]=tot;
	to[tot]=v;
}
void dfs(int now,int sum,int zc){
	if(now==v){
		Min=min(Min,sum);
		return ;
	}
	for(int i=1;i<=n;i++){
		
	}
}
int main() {
	freopen("transmit.in","r",stdin);
	freopen("transmit.out","W",stdout);
	cin>>n>>q>>k;
	for(int i=1;i<=n;i++) cin>>s[i];
	for(int i=1;i<=n-1;i++) {
		cin>>u>>v;
		add(u,v);
		add(v,u);
	}
    while(q--){
    	cin>>u>>v;
    	dfs(u,0,0);
	}
    sort(s+1,s+n+1);
    int sum=0;
    srand(time(0));
    for(int i=1;i<=rand()%10;i++){
    	sum+=s[i];
	}
	cout<<sum;
	return 0;
}
