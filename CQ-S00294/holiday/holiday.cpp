#include<bits/stdc++.h>

#define  Int  long long int
#define  Pub  public
#define  rand  Rand
using std::min;using std::max;
std::mt19937 rand(time(0));

int n,m,k;
class Edge{
Pub:int v,nxt;
}e[20005];
class Vertex{
Pub:Int s;
    int to1[2505],cnt1;
    int to2[2505],cnt2;
}p[2505];
bool oh[2505][2505];
int cntE;
void add_Edge(int u,int v){
    p[u].to1[++p[u].cnt1]=v;
    p[v].to1[++p[v].cnt1]=u;
}

int vis[2505];
void dfs1(int u,int x,int kk){
    if(kk>k)return;
    if(vis[x]==u)return;
    else vis[x]=u;
    oh[u][x]=1;
    p[u].to2[++p[u].cnt2]=x;
    for(int i=1;i<=p[x].cnt1;++i)dfs1(u,p[x].to1[i],kk+1);
}
Int ans;
bool siv[2505];
void dfs2(int x,int kk,Int A){
    if(kk==4){
        if(oh[x][1])ans=max(ans,A+p[x].s);
        else return;
    }
    if(siv[x])return;
    siv[x]=1;
    for(int i=1;i<=p[x].cnt2;++i)dfs2(p[x].to2[i],kk+1,A+p[x].s);
    siv[x]=0;
}

int main(){
    freopen("holiday.in","r",stdin);
    freopen("holiday.out","w",stdout);
    
    scanf("%d%d%d",&n,&m,&k);
    for(int i=2;i<=n;++i)scanf("%lld",&p[i].s);
    for(int i=1,u,v;i<=m;++i){
        scanf("%d%d",&u,&v);
        add_Edge(u,v);
    }
    for(int i=1;i<=n;++i)dfs1(i,i,-1);
    dfs2(1,0,0);
    printf("%lld",ans);
    return 0;
}
