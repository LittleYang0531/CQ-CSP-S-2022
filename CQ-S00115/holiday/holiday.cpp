#include<bits/stdc++.h>
template<typename G>inline void read(G&x) {G f=1;x=0;char ch=getchar();while((ch<'0'||ch>'9')&&ch!='-') ch=getchar();if(ch=='-') f=-1,ch=getchar();while(ch>='0'&&ch<='9') x=x*10+(ch^48),ch=getchar();x*=f;}
template<typename G>inline void write(G x) {if(x<0) putchar('-'),x=-x;if(x>=10) write(x/10);putchar('0'+x%10);}
using namespace std;
const int MAXN=3e3+5,MAXM=2e4+5;
int head[MAXN],nxt[MAXM],to[MAXM],cnt;
void add(int u,int v) {
	nxt[++cnt]=head[u],head[u]=cnt,to[cnt]=v;
	nxt[++cnt]=head[v],head[v]=cnt,to[cnt]=u;
}
int n,m,k,dis[MAXN][MAXN],u,v; 
long long a[MAXN],f[MAXN][3],g[MAXN][3],ans;
priority_queue<pair<int,int> > q;
void dijk(int x) {
	q.push(make_pair(0,x));
	while(!q.empty()) {
		pair<int,int> pii=q.top();q.pop();
		if(dis[x][pii.second]<=k) continue;
		dis[x][pii.second]=-pii.first;
		if(-pii.first>=k) continue;
		for(int i=head[pii.second];i;i=nxt[i]) {
			int tmp=to[i];
			if(dis[x][tmp]>k) q.push(make_pair(pii.first-1,tmp));
		}
	}
}
int main() {
	freopen("holiday.in","r",stdin);
	freopen("holiday.out","w",stdout);
	read(n),read(m),read(k);++k;
	memset(dis,63,sizeof(dis));
	for(int i=2;i<=n;++i) read(a[i]);
	for(int i=1;i<=m;++i) {
		read(u),read(v);
		add(u,v);
	}
	for(int i=1;i<=n;++i) dijk(i);
	g[1][0]=1;
	for(int i=1;i<=n;++i) {
		for(int j=1;j<=n;++j) {
			if(i!=j&&dis[1][j]<=k&&dis[j][i]<=k) {
				if(f[i][0]<a[j]) {
					f[i][2]=f[i][1],g[i][2]=g[i][1];
					f[i][1]=f[i][0],g[i][1]=g[i][0];
					f[i][0]=a[j],g[i][0]=j;
				}
				else if(f[i][1]<a[j]) {
					f[i][2]=f[i][1],g[i][2]=g[i][1];
					f[i][1]=a[j],g[i][1]=j;
				}
				else if(f[i][2]<a[j]) {
					f[i][2]=a[j],g[i][2]=j;
				}
			}
		}
	}
	for(int i=1;i<=n;++i) {
		for(int j=1;j<=n;++j) {
			if(i!=j&&dis[i][j]<=k) {
				int idx1=0,idx2=0;
				if(g[i][idx1]==j) ++idx1;
				if(g[j][idx2]==i) ++idx2;
				if(g[i][idx1]!=g[j][idx2]) {
					if(g[i][idx1]&&g[j][idx2]) ans=max(ans,f[i][idx1]+f[j][idx2]+a[i]+a[j]);
				}
				else {
					++idx1;
					if(g[i][idx1]&&g[j][idx2]) ans=max(ans,f[i][idx1]+f[j][idx2]+a[i]+a[j]);
					--idx1,++idx2;
					if(g[i][idx1]&&g[j][idx2]) ans=max(ans,f[i][idx1]+f[j][idx2]+a[i]+a[j]);
				}
			}
		}
	} 
	printf("%lld",ans);
	return 0;
}

