#include<bits/stdc++.h>
using namespace std;
inline void read(int &x){
	x=0;
	bool f=0;
	char c=getchar();
	while(c<'0'||c>'9'){
		if(c=='-') f=1;
		c=getchar();
	}
	while(c>='0'&&c<='9'){
		x=(x<<1)+(x<<3)+(c^48);
		c=getchar();
	}
	if(f) x=-x;
	return ;
}
inline void read(long long &x){
	x=0;
	bool f=0;
	char c=getchar();
	while(c<'0'||c>'9'){
		if(c=='-') f=1;
		c=getchar();
	}
	while(c>='0'&&c<='9'){
		x=(x<<1ll)+(x<<3ll)+(c^48ll);
		c=getchar();
	}
	if(f) x=-x;
	return ;
}
inline void write(int x){
	if(x<0){
		putchar('-');
		x=-x;
	}
	if(x>9) write(x/10);
	putchar(x%10+48);
}
inline void write(long long x){
	if(x<0ll){
		putchar('-');
		x=-x;
	}
	if(x>9ll) write(x/10ll);
	putchar(x%10ll+48);
}
long long vis[200005];
vector<int> G[200005];
int dep[200005];
int fa[200005];
int n,q,k;
void dfs(int u,int dad){
	fa[u]=dad;
	dep[u]=dep[dad]+1;
	for(int i=0;i<(int)G[u].size();i++){
		int v=G[u][i];
		if(v!=dad) dfs(v,u);
	}
}
long long solve(int u,int v){
	vector<long long> v1,v2;
	long long dp[n];
	memset(dp,0x3f,sizeof(dp));
	while(u!=v){
		if(dep[u]>dep[v]){
			v1.push_back(vis[u]);
			u=fa[u];	
		}
		else{
			v2.push_back(vis[v]);
			v=fa[v];	
		}
	}
	v1.push_back(vis[u]);
	vector<long long> sum;
	for(int i=0;i<(int)v1.size();i++){
		sum.push_back(v1[i]);
	}
	for(int i=v2.size()-1;i>=0;i--){
		sum.push_back(v2[i]);
	}
	dp[0]=sum[0];
	for(int i=1;i<(int)sum.size();i++){
		for(int j=1;j<=k && i-j>=0;j++){
			dp[i]=min(dp[i],dp[i-j]+sum[i]);
		}
	}
	return dp[(int)sum.size()-1];
}
int main(){
	freopen("transmit.in","r",stdin);
	freopen("transmit.out","w",stdout);
	read(n),read(q),read(k);
	for(int i=1;i<=n;i++){
		read(vis[i]);
	}
	for(int i=1;i<n;i++){
		int a,b;
		read(a),read(b);
		G[a].push_back(b);
		G[b].push_back(a);
	}
	dfs(1,0);
	while(q--){
		int u,v;
		read(u),read(v);
		write(solve(u,v));
		putchar('\n');
	}
	return 0;
}

