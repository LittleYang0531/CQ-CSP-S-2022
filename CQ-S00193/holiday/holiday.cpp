#include<bits/stdc++.h>
using namespace std;
const int maxn=2502,maxm=1e4+2;
const long long inf64=1e18;
int n,m,k;
int cnt=1;
int hed[maxn],fir[maxn],sec[maxn],thi[maxn],d[maxn];
long long va[maxn];
bool can[maxn],ok[maxn][maxn];
int he,ta,q[maxn];
long long ans;
struct node_edge{
    int nxt,to;
}G[maxm*2];
void add(int u,int v){
    G[++cnt]=(node_edge){hed[u],v};
    hed[u]=cnt;
    return ;
}
void bfs(int S){
    he=1,ta=0;
    memset(d,-1,sizeof(d));
    d[S]=0;
    q[++ta]=S;
    int x;
    while(he<=ta){
        x=q[he++];
        for(int i=hed[x],v;i;i=G[i].nxt){
            v=G[i].to;
            if(d[v]!=-1)continue;
            d[v]=d[x]+1;
            if(d[v]<k+1){
                q[++ta]=v;
            }
        }
    }
    return ;
}
void upd(int a,int b,int c,int d){
    ans=max(ans,va[a]+va[b]+va[c]+va[d]);
    // printf("upd %d %d %d %d %lld\n",a,b,c,d,ans);
    return ;
}
int main(){
    freopen("holiday.in","r",stdin);
    freopen("holiday.out","w",stdout);
    scanf("%d%d%d",&n,&m,&k);
    for(int i=2;i<=n;i++){
        scanf("%lld",&va[i]);
    }
    int u,v;
    for(int i=1;i<=m;i++){
        scanf("%d%d",&u,&v);
        add(u,v);
        add(v,u);
    }
    bfs(1);
    for(int i=2;i<=n;i++){
        if(d[i]!=-1)can[i]=1;
    }
    for(int i=2;i<=n;i++){
        bfs(i);
        for(int j=2;j<=n;j++){
            if(i==j||d[j]==-1)continue;
            ok[i][j]=1;
            // printf("ok %d %d %d\n",i,j,d[j]);
            if(!can[j])continue;
            if(!fir[i]||va[j]>va[fir[i]]){
                thi[i]=sec[i];
                sec[i]=fir[i];
                fir[i]=j;
            }
            else if(!sec[i]||va[j]>va[sec[i]]){
                thi[i]=sec[i];
                sec[i]=j;
            }
            else if(!thi[i]||va[j]>va[thi[i]]){
                thi[i]=j;
            }
        }
    }
    // for(int i=1;i<=n;i++){
    //     printf("la %d %d %d %d\n",i,fir[i],sec[i],thi[i]);
    // }
    int af,as,bf,bs;
    ans=-1;
    va[0]=-inf64;
    for(int i=2;i<=n;i++){
        for(int j=2;j<=n;j++){
            if(i==j||!ok[i][j])continue;
            af=as=bf=bs=0;
            if(fir[i]==j)af=sec[i],as=thi[i];
            else {
                af=fir[i];
                if(sec[i]==j)as=thi[i];
                else as=sec[i];
            }
            if(fir[j]==i)bf=sec[j],bs=thi[j];
            else {
                bf=fir[j];
                if(sec[j]==i)bs=thi[j];
                else bs=sec[j];
            }
            if(af==bf){
                upd(af,bs,i,j);
                upd(as,bf,i,j);
                // ans=max(ans,va[af]+va[bs]+va[i]+va[j]);
                // ans=max(ans,va[as]+va[bf]+va[i]+va[j]);
            }
            else {
                upd(af,bf,i,j);
                // ans=max(ans,va[af]+va[bf]+va[i]+va[j]);
            }
        }
    }
    printf("%lld\n",ans);
    return 0;
}