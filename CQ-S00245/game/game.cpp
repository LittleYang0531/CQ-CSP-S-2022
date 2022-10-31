#include<bits/stdc++.h>
#define ll long long
#define int long long
#define pii pair<int,int>
#define fir first
#define sec second
using namespace std;

const int maxn=100005;
const int logn=20;
const int inf=0x3f3f3f3f;

struct Get {
	struct ST {
		int n;
		int lg[maxn];
		int st[logn][maxn];
		function<int(int,int)> get;
		void init(int tn,int *a,function<int(int,int)> tget) {
			n=tn;
			get=tget;
			for(int i=1;i<=n;i++) {
				st[0][i]=a[i];
			}
			for(int i=2;i<=n;i++) {
				lg[i]=lg[i>>1]+1;
			}
			for(int i=1;(1<<i)<=n;i++) {
				for(int j=1;j+(1<<i)-1<=n;j++) {
					st[i][j]=get(st[i-1][j],st[i-1][j+(1<<(i-1))]);
				}
			}
		}
		int ask(int l,int r) {
			int k=lg[r-l+1];
			return get(st[k][l],st[k][r-(1<<k)+1]);
		}
	} st[4];
	int s[maxn];
	int ta[4][maxn];
	void init(int n,int *a) {
		for(int i=1;i<=n;i++) {
			s[i]=s[i-1];
			if(a[i]==0) {
				s[i]++;
				continue;
			}
			if(a[i]<0) {
				ta[0][i]=a[i];
				ta[1][i]=a[i];
				ta[2][i]=inf;
				ta[3][i]=-inf;
			} else {
				ta[0][i]=inf;
				ta[1][i]=-inf;
				ta[2][i]=a[i];
				ta[3][i]=a[i];
			}
		}
		st[0].init(n,ta[0],[&](int x,int y) {
			return min(x,y);
		});
		st[1].init(n,ta[1],[&](int x,int y) {
			return max(x,y);
		});
		st[2].init(n,ta[2],[&](int x,int y) {
			return min(x,y);
		});
		st[3].init(n,ta[3],[&](int x,int y) {
			return max(x,y);
		});
	}
	vector<int> ask(int l,int r) {
		vector<int> t;
		if(s[r]-s[l-1]) {
			t.push_back(0);
		}
		for(int i=0;i<=3;i++) {
			int p=st[i].ask(l,r);
			if(p==-inf||p==inf) {
				continue;
			}
			t.push_back(p);
		}
		return t;
	}
} g[2];

int a[maxn];
int b[maxn];

signed main() {
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	int n,m,q;
	cin>>n>>m>>q;
	for(int i=1;i<=n;i++) {
		cin>>a[i];
	}
	for(int i=1;i<=m;i++) {
		cin>>b[i];
	}
	g[0].init(n,a);
	g[1].init(m,b);
	while(q--) {
		int a,b,c,d;
		cin>>a>>b>>c>>d;
		vector<int> x=g[0].ask(a,b),y=g[1].ask(c,d);
//		for(int t:x) {
//			cerr<<t<<" ";
//		} 
//		cerr<<"\n";
//		for(int t:y) {
//			cerr<<t<<" ";
//		} 
//		cerr<<"\n";
		ll Max=-1ll*inf*inf;
		for(int p:x) {
			ll Min=1ll*inf*inf;
			for(int q:y) {
				Min=min(Min,1ll*p*q);
			} 
			Max=max(Max,Min);
		}
		cout<<Max<<"\n";
	}
	cerr<<clock()<<"\n";
}
