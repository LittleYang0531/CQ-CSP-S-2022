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
inline int MAX(const long long &a,const long long &b){
	return a>b?a:b;
}
const int INF=0x3f3f3f3f;
long long a[2505];
int x[2505*2505],y[2505*2505];
int g[2505][2505],vis[2505];
vector<int> G[2505];
int main(){
	freopen("holiday.in","r",stdin);
	freopen("holiday.out","w",stdout);
	int n,m,k;
	read(n),read(m),read(k);
	for(int i=2;i<=n;i++) read(a[i]);
	for(int i=1;i<=m;i++){
		read(x[i]),read(y[i]);
		G[x[i]].push_back(y[i]);
		G[y[i]].push_back(x[i]);
	}
	m=0;
	for(int i=1;i<=n;i++){
		queue< pair<int,int> > q;
		for(int j=1;j<=n;j++){
			vis[j]=0;
		}
		for(int j=0;j<(int)G[i].size();j++){
			q.push(make_pair(0,G[i][j]));
		}
		while(!q.empty()){
			int to=q.front().first,rt=q.front().second;
			q.pop();
			if(vis[rt]) continue;
			vis[rt]=1;
			for(int j=0;j<(int)G[rt].size();j++){
				if(to+1<=k){
					q.push(make_pair(to+1,G[rt][j]));
				}
			}
		}
		for(int j=1;j<=n;j++){
			g[i][j]=vis[j];
			if(g[i][j] && i<j) x[++m]=i,y[m]=j;
		}
	}
	long long ans=0;
	for(int i=2;i<=n;i++){
		if(g[1][i]==0) continue;
		for(int j=i+1;j<=n;j++){
			if(g[1][j]==0) continue;
			for(int l=1;l<=m;l++){
				int sum1=x[l],sum2=y[l];
				if(g[i][sum1]==1 && g[j][sum2]==1){
					if(sum1!=sum2 && sum1!=i && sum1!=j && sum1!=1 && sum2!=i && sum2!=j && sum2!=1){
						ans=MAX(ans,a[sum1]+a[sum2]+a[i]+a[j]);
					}
				}
				if(g[j][sum1]==1 && g[i][sum2]==1){
					if(sum1!=sum2 && sum1!=i && sum1!=j && sum1!=1 && sum2!=i && sum2!=j && sum2!=1){
						ans=MAX(ans,a[sum1]+a[sum2]+a[i]+a[j]);
					}
				}
			}
		}
	}
	write(ans);
	return 0;
}

