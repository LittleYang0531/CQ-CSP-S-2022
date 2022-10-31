#include<bits/stdc++.h>
using namespace std;
const int INF=0x7fffffff/2;
int n,m,ned,cnt=0;
long long ans=0;
int vst[2505],h[2505],sz[2505];
long long a[2505];
int pri[2505][10],dis[2505][2505],vis[2505][2505];
long long val[2505][2505];
struct edge {
	int to,next,v;
}e[100005];
void addedge(int x,int y,int z) {
	cnt++;
	e[cnt].to=y;
	e[cnt].v=z;
	e[cnt].next=h[x];
	h[x]=cnt;
}
priority_queue< pair<int,int> > q;
void dij(int s) {
	for(int i=1;i<=n;i++) dis[s][i]=INF,vst[i]=0;
	dis[s][s]=0;q.push({-dis[s][s],s});
	while(!q.empty()) {
		int u=q.top().second;q.pop();
		if(vst[u]||dis[s][u]>ned+1) continue;
		vst[u]=0;
		for(int i=h[u];i;i=e[i].next) {
			int y=e[i].to;
			if(dis[s][y]>dis[s][u]+e[i].v) {
				dis[s][y]=dis[s][u]+e[i].v;
				q.push({-dis[s][y],y});
			}
		}
	}
}
priority_queue< pair<long long,int> > s[2505] ;
signed main() {
	freopen("holiday.in","r",stdin);
	freopen("holiday.out","w",stdout);
	scanf("%d%d%d",&n,&m,&ned);
	for(int i=2;i<=n;i++) scanf("%lld",&a[i]);
	for(int i=1;i<=m;i++) {
		int x,y;scanf("%d%d",&x,&y);
		addedge(x,y,1);addedge(y,x,1);
	}
	for(int i=1;i<=n;i++) dij(i);
	for(int i=1;i<=n;i++) {
		if(i==1) continue;
		for(int j=1;j<=n;j++) {
			if(j==1||j==i) continue;
			if(dis[1][i]<=ned+1&&dis[i][j]<=ned+1) {
				int fg=0;
				if(!s[j].empty()) {
					if(-s[j].top().first<a[i]+a[j]) s[j].pop(),sz[j]--,fg=1;
				}
				if(sz[j]<4||fg) {
					s[j].push({-(a[i]+a[j]),i});
					sz[j]++;
					val[j][i]=a[i]+a[j];
				}
			}
		}
	}
	for(int i=2;i<=n;i++) {
		for(int j=i+1;j<=n;j++) {
			if(dis[i][j]<=ned+1) vis[i][j]=vis[j][i]=1;
		}
	}
	for(int i=1;i<=n;i++) {
		for(int j=1;j<=sz[i];j++) {
			pri[i][j]=s[i].top().second;s[i].pop();
		}
	}
	for(int i=2;i<=n;i++) {
		for(int j=i+1;j<=n;j++) {
			if(i==j||dis[i][j]>ned+1||!vis[i][j]) continue;
			for(int p=1;p<=sz[i];p++) {
				int p1=pri[i][p];
				for(int q=1;q<=sz[j];q++) {
					int q1=pri[j][q];
//					cout<<p1<<" "<<i<<" "<<j<<" "<<q1<<endl; 
					if(p1==q1||p1==i||p1==j||q1==j||q1==i) continue;
					ans=max(ans,val[i][p1]+val[j][q1]);
				}
			}
		}
	}
	printf("%lld",ans);
	return 0;
}
