#include<bits/stdc++.h>
using namespace std;
int n,m,t,u,v,q,flg,f[500005],sz[500005];
struct node {
	int e,p;
};
vector<node>a[500005];
bool check() {
	for(int i=1; i<=n; i++) {
		if(sz[i]!=1) {
			return false;
		}
	}
	
	return true;
}
int main() {
	freopen("galaxy.in","r",stdin);
	freopen("galaxy.out","w",stdout);
	cin>>n>>m;
	for(int i=1; i<=m; i++) {
		cin>>u>>v;
		sz[u]++;
		a[v].push_back((node) {
			u,0
		});
	}
	cin>>q;
	while(q--) {

		cin>>t;
		if(t==1) {
			cin>>u>>v;
			sz[u]--;
			for(int i=0; i<a[v].size(); i++) {
				if(a[v][i].e==u) {
					a[v][i].p=1;
					break;
				}
			}
		} else if(t==2) {
			cin>>v;
			for(int i=0; i<a[v].size(); i++) {
				if(a[v][i].p==0) {
					a[v][i].p=1;
					sz[a[v][i].e]--;
				}

			}

		} else if(t==3) {
			cin>>u>>v;
			sz[u]++;
			for(int i=0; i<a[v].size(); i++) {
				if(a[v][i].e==u) {
					a[v][i].p=0;
					break;
				}
			}
		} else if(t==4) {
			cin>>v;
			for(int i=0; i<a[v].size(); i++) {
				if(a[v][i].p==1) {
					a[v][i].p=0;
					sz[a[v][i].e]++;
				}

			}
		}
		if(check()) {
			cout<<"YES"<<endl;
		} else {
			cout<<"NO"<<endl;
		}
	}
}
/*
3 6
2 3
2 1
1 2
1 3
3 1
3 2
11
1 3 2
1 2 3
1 1 3
1 1 2
3 1 3
3 3 2
2 3
1 3 1
3 1 3
4 2
1 3 2
*/
