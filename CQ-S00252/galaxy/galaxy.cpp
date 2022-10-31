//Author: Zealous_YH in CSP-S2022
//Su Chanzi & Xiaobao
#include <bits/stdc++.h>
#define ET return 0
#define fr1(i,a,b) for(int (i)=(a);(i)<=(b);(i)++)
#define fr2(i,a,b) for(int (i)=(a);(i)>=(b);(i)++)
#define fv(i,p) for(int (i)=0;(i)<(p).size();(i)++)
#define ll long long
#define ull unsigned ll
#define mp make_pair
#define pb push_back
#define ptc putchar
#define il inline
#define pii pair<int,int>
#define pll pair<ll,ll>
#define fi first
#define se second
using namespace std;
const int N=5e5+10;
int n,m,q,u,v;
vector <int> g[N];
int opt;
bool vis[N];
map <pii,bool> p;
bool f;
void dfs(int x){
	vis[x]=1;
	fv(i,g[x]){
		int v=g[x][i];
		if(p.count(mp(x,v))){
			continue;
		}
		if(vis[v]){
			f=1;
			continue;
		}
		dfs(v);
	}
}
bool check(){
	fr1(i,1,n){
		int cnt=0;
		fv(j,g[i]){
			int v=g[i][j];
			cnt+=(!p.count(mp(i,v)));
		}
		if(cnt!=1){
			return false;
		}
	}
	fr1(i,1,n){
		memset(vis,0,sizeof(vis));
		f=0;
		dfs(i);
		if(!f){
			return false;
		}
	}
	return true;
}
int main(){
	freopen("galaxy.in","r",stdin);
	freopen("galaxy.out","w",stdout);
	cin>>n>>m;
	fr1(i,1,m){
		cin>>u>>v;
		g[u].pb(v);
//		p[v].pb(u);
	}
	cin>>q;
	while(q--){
		cin>>opt;
		if(opt==1){
			cin>>u>>v;
			p[mp(u,v)]=1;
		}
		else if(opt==2){
			cin>>u;
			fr1(i,1,n){
				fv(j,g[i]){
					int v=g[i][j];
					if(v==u){
						p[mp(i,v)]=1;
//						p[mp(v,i)]=1;
					}
				}
			}
		}
		else if(opt==3){
			cin>>u>>v;
			p.erase(mp(u,v));
//			p.erase(mp(v,u));
		}
		else if(opt==4){
			cin>>u;
			fr1(i,1,n){
				fv(j,g[i]){
					int v=g[i][j];
					if(v==u&&p.count(mp(i,v))){
						p.erase(mp(i,v));
//						p.erase(mp(v,i));
					}
				}
			}
		}
		cout<<(check()==1?"YES":"NO")<<endl;
//		fr1(i,1,n){
//			fv(j,g[i]){
//				cout<<i<<","<<g[i][j]<<":"<<p.count(mp(i,g[i][j]))<<endl;
//			}
//		}
	}
	ET;
}
//RP++
//Don't FST.

