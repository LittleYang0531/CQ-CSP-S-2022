#include<bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
#define fir first
#define sec second
using namespace std;

const int maxn=500005;
const int inf=0x3f3f3f3f;

int cd[maxn];
int cnt[maxn];
map<int,bool> to[maxn];
map<int,bool> back[maxn];
map<int,bool> backe[maxn];

signed main() {
	freopen("galaxy.in","r",stdin);
	freopen("galaxy.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	int n,m,q;
	cin>>n>>m;
	for(int i=1;i<=m;i++) {
		int x,y;
		cin>>x>>y;
		to[x][y]=true;
		back[y][x]=true;
		cd[x]++;
	}
	cin>>q;
	if(n<=1000&&q<=1000) {
		while(q--) {
			int t,x,y;
			cin>>t>>x;
			if(t==1||t==3) {
				cin>>y;
			}
			if(t==1) {
				to[x][y]=false;
				back[y][x]=false;
				cd[x]--;
			} else if(t==2) {
				for(pii p:back[x]) {
					if(p.sec) {
						back[x][p.fir]=false;
						to[p.fir][x]=false;
						cd[p.fir]--;
					}
				}
			} else if(t==3) {
				to[x][y]=true;
				back[y][x]=true;
				cd[x]++;
			} else {
				for(pii p:back[x]) {
					if(!p.sec) {
						back[x][p.fir]=true;
						to[p.fir][x]=true;
						cd[p.fir]++;
					}
				}
			}
			bool f=true;
			for(int i=1;i<=n;i++) {
				if(cd[i]!=1) {
					f=false;
				}
			}
			cout<<(f?"YES":"NO")<<"\n";
		}
	} else {
		auto add=[&](int x,int y) {
			cnt[x]+=y;
		};
		for(int i=1;i<=n;i++) {
			add(cd[i],1);
		}
		while(q--) {
			int t,x,y;
			cin>>t>>x;
			if(t==1||t==3) {
				cin>>y;
			}
			if(t==1) {
				back[y][x]=false;
				backe[y][x]=true;
				add(cd[x],-1);
				cd[x]--;
				add(cd[x],1);
			} else if(t==2) {
				for(pii p:back[x]) {
					backe[x][p.fir]=true;
					add(cd[p.fir],-1);
					cd[p.fir]--;
					add(cd[p.fir],1);
				}
				back[x].clear();
			} else if(t==3) {
				back[y][x]=true;
				backe[y][x]=false;
				add(cd[x],-1);
				cd[x]++;
				add(cd[x],1);
			} else {
				for(pii y:backe[x]) {
					back[x][y.fir]=true;
					add(cd[y.fir],-1);
					cd[y.fir]++;
					add(cd[y.fir],1);
				}
				backe[x].clear();
			}
			
			cout<<(cnt[1]==n?"YES":"NO")<<"\n";
		}
	}
}
