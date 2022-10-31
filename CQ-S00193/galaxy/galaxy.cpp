#include<bits/stdc++.h>
using namespace std;
const int maxn=1e3+2,maxm=1e4+2;
int n,m,Q;
int cnt=1,idx;
int hed[maxn],dfn[maxn],low[maxn];
int id[maxn][maxn];
int top,sta[maxn];
bool ins[maxn],is[maxn];
struct node_edge{
    int nxt,to;
    bool val,can;
}G[maxm*2];
int cd[maxn];
int scccnt;
vector<int>scc[maxn];
void add(int u,int v,bool w){
    G[++cnt]=(node_edge){hed[u],v,w,1};
    hed[u]=cnt;
    return ;
}
void tarjan(int x){
    dfn[x]=low[x]=++idx;
    sta[++top]=x,ins[x]=1;
    for(int i=hed[x],v;i;i=G[i].nxt){
        v=G[i].to;
        if(!G[i].can||!G[i].val)continue;
        if(!dfn[v]){
            tarjan(v);
            low[x]=min(low[x],low[v]);
        }
        else if(ins[v])low[x]=min(low[x],dfn[v]);
    }
    if(low[x]==dfn[x]){
        // scccnt++;
        while(sta[top]!=x){
            is[sta[top]]=1,ins[sta[top]]=0;
            // scc[scccnt].push_back(sta[top--]);
            top--;
        }
        is[sta[top]]=1,ins[sta[top]]=0;
        // scc[scccnt].push_back(sta[top--]);
    }
    return ;
}
int main(){
    freopen("galaxy.in","r",stdin);
    freopen("galaxy.out","w",stdout);
    scanf("%d%d",&n,&m);
    int u,v;
    for(int i=1;i<=m;i++){
        scanf("%d%d",&u,&v);
        add(u,v,1);
        id[u][v]=cnt;
        add(v,u,0);
        cd[u]++;
    }
    scanf("%d",&Q);
    int op;
    for(int i=1;i<=Q;i++){
        scanf("%d",&op);
        if(op==1){
            scanf("%d%d",&u,&v);
            G[id[u][v]].can=G[id[u][v]^1].can=0;
            cd[u]--;
        }
        else if(op==2){
            scanf("%d",&u);
            for(int j=hed[u];j;j=G[j].nxt){
                if(G[j].val)continue;
                if(G[j].can){
                    cd[G[j].to]--;
                    G[j].can=G[j^1].can=0;
                }
            }
        }
        else if(op==3){
            scanf("%d%d",&u,&v);
            G[id[u][v]].can=G[id[u][v]^1].can=1;
            cd[u]++;
        }
        else {
            scanf("%d",&u);
            for(int j=hed[u];j;j=G[j].nxt){
                if(G[j].val)continue;
                if(!G[j].can){
                    G[j].can=G[j^1].can=1;
                    cd[G[j].to]++;
                }
            }
        }
        // memset(ins,0,sizeof(ins));
        // memset(is,0,sizeof(is));
        // memset(dfn,0,sizeof(dfn));
        for(int i=1;i<=n;i++)ins[i]=is[i]=dfn[i]=0;
        top=idx=0;
        bool f=1;
        // for(int i=1;i<=scccnt;i++)scc[i].clear();
        // scccnt=0;
        // printf("Cd:");
        for(int i=1;i<=n;i++){
            if(!dfn[i]){
                tarjan(i);
            }
            if(cd[i]!=1||!is[i])f=0;
            // printf("%d ",cd[i]);
        }
        // printf("\n");
        // printf("scc:%d\n",scccnt);
        // for(int i=1;i<=scccnt;i++){
        //     for(int j=0;j<scc[i].size();j++)printf("%d ",scc[i][j]);
        //     putchar('\n');
        // }
        printf("%s\n",((f)?"YES":"NO"));
    }
    return 0;
}