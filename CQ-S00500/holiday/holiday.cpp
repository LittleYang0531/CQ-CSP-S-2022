#include <bits/stdc++.h>
#define int long long

#define rep(i, a, b) for (int i = (a); i <= (b); i ++)
#define dep(i, a, b) for (int i = (a); i >= (b); i --)

using namespace std;
typedef pair<int,int> pii;
const int N = 2500 + 5;
int n, m, k,tmp[N],dis[N],a[N],ans;
vector <int>e[N];
int f[N],g[N];

void BFS() {
  priority_queue <pii ,vector <pii>, greater<pii> > q;
  q.push({0,1});
  memset(dis,127,sizeof dis),dis[1] =0;
  while(!q.empty()){
    int u=q.top().second, d =q.top().first; q.pop();
    if ( dis[u] != d ) continue;
    for(auto v : e[u]) {
      if ( dis[u] + 1 < dis[v]) dis[v]=dis[u]+1,q.push({dis[v],v});
    }
  }
}

void DJ(int s){
  priority_queue <pii ,vector <pii>, greater<pii> > q;
  q.push({0,s});
  memset(tmp,127,sizeof tmp),tmp[s] =0;
  while(!q.empty()){
    int u=q.top().second, d =q.top().first; q.pop();
    if ( tmp[u] != d||tmp[u]>k+1 ) continue;
    if ( u != 1 && u != s && dis[u] <=k+1 ) {
      if ( a[u] > a[g[s]]) g[s]=u;
      if(a[g[s]]>a[f[s]]) swap(f[s],g[s]);
    }
    for(auto v : e[u]) {
      if ( tmp[u] + 1 < tmp[v]) tmp[v]=tmp[u]+1,q.push({tmp[v],v});
    }
  } 
}

int check(int u,int v,int w,int i){
  if(u==0||v==0||w==0||i==0)return 0;
  if (u==v||u==w||u==i) return 0;
  if(v==w||v==i) return 0;
  if(w==i) return 0;
  return 1;
}

void sol(int s){
  priority_queue <pii ,vector <pii>, greater<pii> > q;
  q.push({0,s});
  memset(tmp,127,sizeof tmp),tmp[s] =0;
  while(!q.empty()){
    int u=q.top().second, d =q.top().first; q.pop();
    if ( tmp[u] != d||tmp[u]>k+1 ) continue;
    if ( u != 1 && u != s ) {
      int i = s, j = u;
      int x=f[i],y=f[j];
      if (check(x,y,i,j)) ans=max(ans,a[i]+a[j]+a[x]+a[y]);
      else{
        x=g[i],y=f[j];
        if(check(x,y,i,j))ans=max(ans,a[i]+a[j]+a[x]+a[y]);
        x=f[i],y=g[j];
        if(check(x,y,i,j))ans=max(ans,a[i]+a[j]+a[x]+a[y]);
        x=g[i],y=g[j];
        if(check(x,y,i,j))ans=max(ans,a[i]+a[j]+a[x]+a[y]);
      }    
    }
    for(auto v : e[u]) {
      if ( tmp[u] + 1 < tmp[v]) tmp[v]=tmp[u]+1,q.push({tmp[v],v});
    }
  } 
}

signed main() {
  freopen("holiday.in","r",stdin);
  freopen("holiday.out","w",stdout);
  ios::sync_with_stdio(0), cin.tie(0);
  cin >> n >> m >> k;
  rep(i,2,n)cin>>a[i];
  while ( m -- ) {
    int a, b; cin >> a >> b;
    e[a].emplace_back(b), e[b].emplace_back(a);
  }
  BFS();
  rep(i,2,n) DJ(i);
  rep(i,2,n) sol(i);
  cout<<ans;
  return 0;
}
