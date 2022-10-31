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
#define int ll
using namespace std;
const int N=2510;
int n,m,k;
ll val[N];
bool vis[N];
int dis[N][N];
queue <int> q;
vector <int> p[N];
priority_queue <pii> maxn[N];
ll ans;
void bfs(int x){
	q.push(x);
	dis[x][x]=-1;
	fr1(i,1,n){
		if(i!=x){
			dis[x][i]=INT_MAX;
		}
	}
	while(!q.empty()){
		int u=q.front();
//		cout<<"!"<<u<<endl;
		q.pop();
		if(vis[u]){
			continue;
		}
		vis[u]=1;
		fv(i,p[u]){
			int v=p[u][i];
//			cout<<"?"
			dis[x][v]=min(dis[x][v],dis[x][u]+1);
			if(!vis[v]){
				q.push(v);
			}
		}
	}
	if(x!=1){
		fr1(i,2,n){
			if(i==x){
				continue;
			}
			if(dis[1][i]<=k&&dis[x][i]<=k){
				if(maxn[x].size()<(n<=1000?n:5)){
					maxn[x].push(mp(-val[i],i));
				}
				else{
					if(-maxn[x].top().fi<val[i]){
						maxn[x].pop();
						maxn[x].push(mp(-val[i],i));
					}
				}
			}
		}	
	}
	memset(vis,0,sizeof(vis));
}
void bf(int x,int y){
	priority_queue <pii> t;
//	t=maxn[x];
	vector <int> l,r;
	t=maxn[x];
	while(!t.empty()){
		l.pb(t.top().se);
		t.pop();
	}
	t=maxn[y];
	while(!t.empty()){
		r.pb(t.top().se);
		t.pop();
	}
	fv(i,l){
		fv(j,r){
			if(r[j]!=x&&r[j]!=y&&l[i]!=x&&l[i]!=y&&r[j]!=l[i]){
//				cout<<i<<"?"<<j<<endl;
				ans=max(ans,val[x]+val[y]+val[l[i]]+val[r[j]]);
			}
		}
	}
}
signed main(){
	freopen("holiday.in","r",stdin);
	freopen("holiday.out","w",stdout);
	ios::sync_with_stdio(false);
	cin>>n>>m>>k;
	fr1(i,2,n){
		cin>>val[i];
	}
	fr1(i,1,m){
		int u,v;
		cin>>u>>v;
		p[u].pb(v);
		p[v].pb(u);
	}
	fr1(i,1,n){
		bfs(i);
	}
//	fr1(i,1,n){
//		fr1(j,1,n){
//			cout<<i<<","<<j<<":"<<dis[i][j]<<endl;
//		}
//	}
	fr1(i,2,n){//b
		fr1(j,2,n){//c
			if(i==j){
				continue;
			}
			if(dis[i][j]>k){
				continue;
			}
//			cout<<i<<"!"<<j<<endl;
			bf(i,j);
//			cout<<i<<","<<j<<","<<ans<<endl;
//			ans=max(ans,val[i]+val[j]+maxn[i]+maxn[j]);
		}
	}
	cout<<ans<<endl;
	ET;
}
//RP++
//Don't FST.
