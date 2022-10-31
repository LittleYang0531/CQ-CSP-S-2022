#include<bits/stdc++.h>
#define ll long long
#define int long long
#define pii pair<ll,int>
#define fir first
#define sec second
using namespace std;

const int maxn=2505;
const int B=4;
const int inf=0x3f3f3f3f;

int d[maxn][maxn];
bool vis[maxn];
ll a[maxn];
vector<int> graph[maxn];
vector<pii> v[maxn];
multiset<pii> s[maxn];

void bfs(int x,int *d) {
	memset(vis,0,sizeof(vis));
	queue<int> q;
	q.push(x);
	vis[x]=true;
	while(q.size()) {
		int x=q.front();
		q.pop();
		for(int to:graph[x]) {
			if(!vis[to]) {
				vis[to]=true;
				d[to]=d[x]+1;
				q.push(to);
			}
		}
	}
}

signed main() {
	freopen("holiday.in","r",stdin);
	freopen("holiday.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	int n,m,k;
	cin>>n>>m>>k;
	for(int i=2;i<=n;i++) {
		cin>>a[i];
	}
	for(int i=1;i<=m;i++) {
		int x,y;
		cin>>x>>y;
		graph[x].push_back(y);
		graph[y].push_back(x);
	}
	for(int i=1;i<=n;i++) {
		bfs(i,d[i]);
	}
	k++;
	for(int x=1;x<=n;x++) {
		for(int p=1;p<=n;p++) {
			if(p==x||p==1) {
				continue;
			}
			if(d[1][p]<=k&&d[p][x]<=k) {
				s[x].insert({a[p],p});
				while(s[x].size()>B) {
					s[x].erase(s[x].begin());
				}
			}
		}
	}
	for(int x=1;x<=n;x++) {
		while(s[x].size()) {
			v[x].push_back(*s[x].begin());
			s[x].erase(s[x].begin());
		}
	}
	ll ans=0;
	for(int x=1;x<=n;x++) {
		for(int y=1;y<=n;y++) {
			if(d[x][y]>k||x==y) {
				continue;
			}
			for(pii p:v[x]) {
				for(pii q:v[y]) {
					if(p.sec==x||p.sec==y||q.sec==x||q.sec==y||p.sec==q.sec) {
						continue;
					}
					ans=max(ans,a[x]+a[y]+p.fir+q.fir);
				}
			}
		}
	}
	cout<<ans<<"\n";
	cerr<<clock()<<"\n";
}
