#include<bits/stdc++.h>
using namespace std;
const int maxn=2e5+2;
const long long inf64=1e18;
int n,Q,k;
int cnt=1;
int hed[maxn],siz[maxn],maxson[maxn],dep[maxn];
long long va[maxn],dis[maxn][4];
long long z[4];
long long ans[maxn];
bool vis[maxn],in[maxn];
struct node_edge{
    int nxt,to;
}G[maxn*2];
struct node_q{
    int id,t;
};
vector<node_q>q[maxn];
void add(int u,int v){
    G[++cnt]=(node_edge){hed[u],v};
    hed[u]=cnt;
    return ;
}
int find_root(int x,int f,int rt,int all){
    siz[x]=1,maxson[x]=0;
    for(int i=hed[x],v;i;i=G[i].nxt){
        v=G[i].to;
        if(v==f||vis[v])continue;
        rt=find_root(v,x,rt,all);
        siz[x]+=siz[v];
        maxson[x]=max(maxson[x],siz[v]);
    }
    maxson[x]=max(maxson[x],all-siz[x]);
    if(!rt||maxson[x]<maxson[rt])rt=x;
    return rt;
}
void calc(int x,int f,int ff,int fff,int rt){
    dep[x]=dep[f]+1;
    if(dep[x]<=k)z[dep[x]]=min(z[dep[x]],va[x]);
    for(int i=0;i<=k;i++)dis[x][i]=inf64;
    for(int i=0;i<=k;i++){
        if(dep[x]==i)dis[x][i]=min(dis[x][i],va[x]);
        if(f&&k>=1)dis[x][i]=min(dis[x][i],dis[f][i]+va[x]);
        if(ff&&k>=2)dis[x][i]=min(dis[x][i],dis[ff][i]+va[x]);
        if(fff&&k>=3)dis[x][i]=min(dis[x][i],dis[fff][i]+va[x]);
    }
    long long mi;
    for(int i=0,v,id;i<q[x].size();i++){
        v=q[x][i].t,id=q[x][i].id;
        if(in[v]){
            mi=inf64;
            for(int j=0;j<=k;j++){
                mi=min(mi,dis[x][j]);
                ans[id]=min(ans[id],dis[v][k-j]+mi);
            }
            ans[id]=min(ans[id],dis[v][0]+dis[x][0]-va[rt]);

        }
    }
    for(int i=hed[x],v;i;i=G[i].nxt){
        v=G[i].to;
        if(v==f||vis[v])continue;
        calc(v,x,f,ff,rt);
    }
    return ;
}
void calc2(int x,int f){    
    long long mi1,mi2;
    for(int i=0,v,id;i<q[x].size();i++){
        v=q[x][i].t,id=q[x][i].id;
        if(in[v]){
            mi1=mi2=inf64;
            for(int j=0;j<=k;j++){
                mi1=min(mi1,dis[x][j]);
                mi2=min(mi2,dis[v][j]);
                // if(id==5){
                //     printf("do %d %lld %lld %lld %d\n",j,mi1,mi2,z[k-j],dep[4]);
                // }
                ans[id]=min(ans[id],mi1+mi2+z[k-j]);
            }
        }
    }
    for(int i=hed[x],v;i;i=G[i].nxt){
        v=G[i].to;
        if(v==f||vis[v])continue;
        calc2(v,x);
    }
    return ;
}
void modi(int x,int f,bool ty){
    in[x]=ty;
    for(int i=hed[x],v;i;i=G[i].nxt){
        v=G[i].to;
        if(v==f||vis[v])continue;
        modi(v,x,ty);
    }
    return ;
}
void solve(int x,int all){
    // printf("solve %d\n",x);
    vis[x]=1;
    dis[x][0]=va[x];
    dis[x][1]=dis[x][2]=dis[x][3]=inf64;
    dep[x]=0;
    in[x]=1;
    for(int i=0;i<=k;i++)z[i]=inf64;
    for(int i=hed[x],v;i;i=G[i].nxt){
        v=G[i].to;
        if(vis[v])continue;
        calc(v,x,0,0,x);
        modi(v,x,1);
    }
    modi(x,0,0);
    for(int i=hed[x],v;i;i=G[i].nxt){
        v=G[i].to;
        if(vis[v])continue;
        calc2(v,x);
        modi(v,x,1);
    }
    modi(x,0,0);
    int nrt,newall;
    for(int i=hed[x],v;i;i=G[i].nxt){
        v=G[i].to;
        if(vis[v])continue;
        newall=((siz[v]>siz[x])?all-siz[x]:siz[v]);
        nrt=find_root(v,x,0,newall);
        solve(nrt,newall);
    }
    return ;
}
int main(){
    freopen("transmit.in","r",stdin);
    freopen("transmit.out","w",stdout);
    scanf("%d%d%d",&n,&Q,&k);
    for(int i=1;i<=n;i++){
        scanf("%lld",&va[i]);
    }
    int u,v;
    for(int i=1;i<n;i++){
        scanf("%d%d",&u,&v);
        add(u,v);
        add(v,u);
    }
    for(int i=1;i<=Q;i++){
        scanf("%d%d",&u,&v);
        q[u].push_back((node_q){i,v});
        q[v].push_back((node_q){i,u});
    }
    memset(ans,0x3f3f3f3f,sizeof(ans));
    int rt=find_root(1,0,0,n);
    solve(rt,n);
    for(int i=1;i<=Q;i++){
        printf("%lld\n",ans[i]);
    }
    return 0;
}