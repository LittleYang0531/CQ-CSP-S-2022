#include <bits/stdc++.h>
#define ll long long
#define wr(x,ch) write(x),putchar(ch)
using namespace std;
ll read() {
	ll x=0;
	char c=getchar();
	bool f=0;
	while(!isdigit(c)) f|=c=='-',c=getchar();
	while(isdigit(c)) x=(x<<3)+(x<<1)+(c^48),c=getchar();
	return f?~(x-1):x;
}
void write(ll x) {
	if(x<0) putchar('-'),x=~(x-1);
	if(x>=10) write(x/10);
	putchar(x%10^48);
}
const ll N=2505,M=10005,inf=0x3f3f3f3f3f3f3f3f;
struct edge {
	ll to,nxt;
}e[M<<1];
struct node {
	ll u,dis;
	bool operator>(const node &p) const {
		return dis>p.dis;
	}
};
ll n,m,K,cnt,a[N],head[N],dp[5][N],dis[N][N],u,v,ans;
bitset<N> flag[5][N];
bool vis[N];
void add(int u,int v) {
	e[++cnt]=(edge){v,head[u]},head[u]=cnt;
}
void dij(int st) {
	priority_queue<node,vector<node>,greater<node> > qu;
	qu.push((node){st,0});
	for(int i=1;i<=n;i++) dis[st][i]=inf,vis[i]=0;
	dis[st][st]=0;
	while(qu.size()) {
		int top=qu.top().u;
		qu.pop();
		if(vis[top]) continue;
		vis[top]=1;
		for(int i=head[top],to=e[i].to;i;to=e[i=e[i].nxt].to) {
			if(dis[st][to]>dis[st][top]+1) 
				dis[st][to]=dis[st][top]+1,qu.push((node){to,dis[st][to]});
		}
	}
}
int main() {
	freopen("holiday.in","r",stdin);
	freopen("holiday.out","w",stdout);
//	freopen("holiday3.in","r",stdin);
//	freopen("holiday3.out","w",stdout);
	n=read(),m=read(),K=read();
	for(int i=2;i<=n;i++) a[i]=read();
	for(int i=1;i<=m;i++) u=read(),v=read(),add(u,v),add(v,u);
	for(int i=1;i<=n;i++) dij(i);
	for(int i=2;i<=n;i++) {
		if(dis[1][i]<=K+1) dp[1][i]=a[i],flag[1][i][i]=1;
		else dp[1][i]=-1;
	}
	for(int i=2;i<=4;i++) {
		for(int j=2;j<=n;j++) {
			int lst=0;
			for(int k=2;k<=n;k++) {
				if(dis[j][k]>K+1) continue;
				if(flag[i-1][k][j]==0&&dp[i-1][k]+a[j]>dp[i][j]&&dp[i-1][k]!=-1) {
					lst=k;
					dp[i][j]=dp[i-1][k]+a[j];
				}
			}
			if(lst==0) {
				dp[i][j]=-1;
				continue;
			}
			flag[i][j]=flag[i-1][lst],flag[i][j][j]=1;
		}
	}
	for(int i=2;i<=n;i++) if(dis[1][i]<=K+1) ans=max(ans,dp[4][i]);
	wr(ans,'\n');
	return 0;
}
/*
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

