#include <bits/stdc++.h>
#define int long long
using namespace std;
bool lmg;
int read() {
	int x(0),f(0);
	char ch=getchar();
	while(!isdigit(ch)) f|=(ch=='-'),ch=getchar();
	while(isdigit(ch)) x=x*10+ch-'0',ch=getchar();
	return f?-x:x;
}
const int N=2505,M=10005;
int n,m,K,ans;
int cur,hed[N],nxt[M<<1],to[M<<1];
void add(int x,int y) {
	to[++cur]=y,nxt[cur]=hed[x],hed[x]=cur;
	to[++cur]=x,nxt[cur]=hed[y],hed[y]=cur;
}
int a[N],dis[N][N];
bool vis[N];
queue<int> qu;
void bfs(int s) {
	for(int i=1;i<=n;++i) vis[i]=0;
	dis[s][s]=-1;
	vis[s]=1;
	qu.push(s);
	while(!qu.empty()) {
		int x=qu.front();
		qu.pop();
		for(int i=hed[x];i;i=nxt[i]) {
			if(vis[to[i]]) continue;
			vis[to[i]]=1;
			dis[s][to[i]]=dis[s][x]+1;
			qu.push(to[i]);
		}
	}
}
int b[N][N],len[N];
bool cmp(int x,int y) {return a[x]>a[y];}
bool oat;
signed main() {
//	cerr<<(&lmg-&oat)/1024.0/1024.0<<endl;
	freopen("holiday.in","r",stdin);
	freopen("holiday.out","w",stdout);
	n=read(),m=read(),K=read();
	for(int i=2;i<=n;++i) a[i]=read();
	for(int i=1;i<=m;++i) add(read(),read());
	memset(dis,0x3f,sizeof dis);
	for(int i=1;i<=n;++i) bfs(i);
//	for(int i=1;i<=n;++i)
//	for(int j=1;j<=n;++j)
//		cerr<<i<<" "<<j<<" "<<dis[i][j]<<endl;
	for(int i=2;i<=n;++i) {
		for(int j=2;j<=n;++j)
			if(i!=j&&dis[1][j]<=K&&dis[i][j]<=K) b[i][++len[i]]=j;
//		cerr<<i<<endl;
//		for(int j=1;j<=len[i];++j) cerr<<b[i][j]<<" ";
//		cerr<<endl;
		sort(b[i]+1,b[i]+1+len[i],cmp);
	}
	for(int i=2;i<=n;++i)
	for(int j=i+1;j<=n;++j) {
		if(dis[i][j]>K) continue;
		int ifi=0,ise=0,jfi=0,jse=0,idi=0,idj=0;
		for(int k=1;k<=len[i];++k) if(b[i][k]!=i&&b[i][k]!=j) {
			ifi=b[i][k];
			idi=k;
			break;
		}
		if(!idi) continue;
		for(int k=idi+1;k<=len[i];++k) if(b[i][k]!=i&&b[i][k]!=j) {
			ise=b[i][k];
			break;
		}
		for(int k=1;k<=len[j];++k) if(b[j][k]!=i&&b[j][k]!=j) {
			jfi=b[j][k];
			idj=k;
			break;
		}
		for(int k=idj+1;k<=len[j];++k) if(b[j][k]!=i&&b[j][k]!=j) {
			jse=b[j][k];
			break;
		}
		if(!idj) continue;
		if(ifi!=jfi) ans=max(ans,a[i]+a[j]+a[ifi]+a[jfi]);
		else {
			if(ise) ans=max(ans,a[i]+a[j]+a[ise]+a[jfi]);
			if(jse) ans=max(ans,a[i]+a[j]+a[ifi]+a[jse]);
		}
	}
	cout<<ans;
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

27
*/
