#include <bits/stdc++.h>
using namespace std;
#define int long long

#define rep(i, a, b) for (int i = (a); i <= (b); i ++)
#define dep(i, a, b) for (int i = (a); i >= (b); i --)

const int N=5e5+5,M=5e5+5;
int n,m,head[N],to[M],nxt[M],ecnt,from[M],du[N],mark[M],cnt[M];
map<pair<int,int>,int>mp;
void add(int u,int v){to[++ecnt]=v,from[ecnt]=u,nxt[ecnt]=head[u],head[u]=ecnt;du[u]++;}
int ok[N],scc[N],tot,siz[N];
int dfn[N],low[N],tim,vis[N],sta[N],tp;

void tarjan(int u){
  dfn[u]=low[u]=++tim;
  sta[++tp]=u,vis[u]=1;
  for(int i=head[u]; i; i = nxt[i]){
    if(mark[i]==0)continue;
    int v=to[i];
    if(!dfn[v]){
      tarjan(v);
      low[u]=min(low[u],low[v]);
    }
    else if(vis[v]) low[u]=min(low[u],dfn[v]);
  }
  if(low[u]==dfn[u]){
    vis[u]=0,scc[u]=++tot,siz[tot]=1;
    while(sta[tp]!=u){
      scc[sta[tp]]=tot,vis[sta[tp]]=0,siz[tot]++,--tp;
    }
    --tp;
  }
}

int dfs(int u){
  if(siz[scc[u]]>1) return 1;
  for(int i=head[u];i;i=nxt[i]) if(mark[i]) {
    int v=dfs(to[i]);if(v)return 1;
  }
  return 0;
}

int check(){
  int fl=cnt[0];
  rep(i,2,m) if(cnt[i]) fl=1;
  if(fl)return 0;
  memset(dfn,0,sizeof dfn),tim=tot=0;
  rep(i,1,n)if(!dfn[i]) tarjan(i);
  rep(i,1,n){
    int v=dfs(i);if(v==0)return 0;
  }
  return 1;
}

signed main(){
  freopen("galaxy.in","r",stdin);
  freopen("galaxy.out","w",stdout);
  ios::sync_with_stdio(0),cin.tie(0);
  cin>>n>>m;
  rep(i,1,m){
    int a,b;cin>>a>>b;
    mp[{a,b}]=i,mark[i]=1,add(a,b);
  }
  rep(i,1,n)cnt[du[i]]++;
  int q;cin>>q;
  while(q--){
    int op,a,b;cin>>op;
    if(op==1){
      cin>>a>>b;
      int id=mp[{a,b}];
      if(mark[id]) mark[id]=0,cnt[du[a]]--,du[a]--,cnt[du[a]]++;
      cout <<(check()?"YES":"NO")<<'\n';
    }
    else if(op==2){
      cin>>a;
      rep(i,1,m)if(to[i]==a&&mark[i]==1){
        mark[i]=0;
        int u=from[i];
        cnt[du[u]]--,du[u]--,cnt[du[u]]++;
      }
      cout<<(check()?"YES":"NO")<<'\n';
    }
    else if(op==3){
      cin>>a>>b;
      int id=mp[{a,b}];
      if(!mark[id])mark[id]=1,cnt[du[a]]--,du[a]++,cnt[du[a]]++;
      cout <<(check()?"YES":"NO")<<'\n';      
    }
    else{
      cin>>a;
      rep(i,1,m)if(to[i]==a&&mark[i]==0){
        mark[i]=1;
        int u=from[i];
        cnt[du[u]]--,du[u]++,cnt[du[u]]++;
      }
      cout<<(check()?"YES":"NO")<<'\n';      
    }
  }
  return 0;
}
