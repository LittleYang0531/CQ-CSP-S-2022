#include<bits/stdc++.h>
using namespace std;
int n,m,k;
int v[20005],elast[2505],nxt[20005],tot;
void add(int x,int y) {
	v[++tot]=y;
	nxt[tot]=elast[x];
	elast[x]=tot;
}
int dis[2505][2505],vis[2505];
void dj(int x) {
	for(int i=1;i<=n;i++) vis[i]=0,dis[x][i]=(1e9);
	dis[x][x]=0;
	queue<int> q;
	q.push(x);
	while(!q.empty()) {
		int tp=q.front();q.pop();
		if(vis[tp]) continue;
		vis[tp]=1;
		for(int i=elast[tp];i;i=nxt[i]) {
			int y=v[i];
			if(dis[x][y]>dis[x][tp]+1&&dis[x][tp]+1<=k+1) {
				dis[x][y]=dis[x][tp]+1;
				if(!vis[y]) q.push(y);
			}
		}
	}
}
long long a[2505],f[2505][2505],ans;
struct dog {long long x;int id;};
vector<dog> kt[2505];
int main() {
	freopen("holiday.in","r",stdin);
	freopen("holiday.out","w",stdout);
	scanf("%d%d%d",&n,&m,&k);
	for(int i=2;i<=n;i++) scanf("%lld",&a[i]);
	for(int i=1;i<=m;i++) {
		int x,y;
		scanf("%d%d",&x,&y);
		add(x,y);
		add(y,x);
	}
	for(int i=1;i<=n;i++) dj(i);
	for(int i=1;i<=n;i++)
		if(dis[1][i]!=1e9&&i!=1)
			for(int j=1;j<=n;j++)
				if(dis[i][j]!=1e9&&j!=i&&j!=1){
					kt[j].push_back(dog{a[i]+a[j],i});
				}
	for(int i=1;i<=n;i++) {
		for(int k=0;k<3;k++) {
			dog maxn=dog{0,0};
			int id=0;
			for(int j=k;j<kt[i].size();j++)
				if(kt[i][j].x>maxn.x) maxn=kt[i][j],id=j;
			if(kt[i].size()>k) swap(kt[i][k],kt[i][id]);
		}
	}
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			if(dis[i][j]!=1e9&&j!=i) {
				for(int k=0;k<3&&k<kt[i].size();k++)
					for(int l=0;l<3&&l<kt[j].size();l++)
						if(kt[i][k].id!=kt[j][l].id&&kt[i][k].id!=j&&kt[j][l].id!=i) ans=max(ans,kt[i][k].x+kt[j][l].x);
			}
	printf("%lld",ans);			
	return 0;
}

