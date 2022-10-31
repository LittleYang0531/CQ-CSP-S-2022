#include <bits/stdc++.h>
#define ll long long
using namespace std;
void read(int &x)
{
    x=0;int f=1;char c=getchar();
    while(!('0'<=c&&c<='9')){if(c=='-')f=-1;c=getchar();}
    while('0'<=c&&c<='9'){x=x*10+c-'0';c=getchar();}
    x*=f;
}
void read(ll &x)
{
    x=0;int f=1;char c=getchar();
    while(!('0'<=c&&c<='9')){if(c=='-')f=-1;c=getchar();}
    while('0'<=c&&c<='9'){x=x*10+c-'0';c=getchar();}
    x*=f;
}
int n,m,k;
ll Val[2505],Dis[2505];
vector <int> G[2505],G2[2505];
void BFS(int S)
{
    for(int i=1;i<=n;i++) Dis[i]=1e9;
    queue<int>Q;Q.push(S);Dis[S]=0;
    while(!Q.empty())
    {
        int u=Q.front();Q.pop();
        if(Dis[u]>=k) break;
//        cerr<<u<<":dis="<<Dis[u]<<endl;
        for(int i=0;i<G[u].size();i++)
        {
            int v=G[u][i];
//            cerr<<u<<" "<<v<<endl;
            if(Dis[v]!=1e9) continue;
            Q.push(v); Dis[v]=Dis[u]+1;
        }
    }
    for(int i=1;i<=n;i++)
        if(Dis[i]<=k&&i!=S) G2[S].push_back(i);//cerr<<S<<" "<<i<<endl;
}
int Now;
bool vis[2505];
ll f[2505][2505][4];
void DFS(int u,int dep,ll V)
{
	if(1.0*clock()/CLOCKS_PER_SEC<=1.50) return;
    vis[u]=true;
    if(f[Now][u][dep-1]>V) {vis[u]=false;return;}
    f[Now][u][dep-1]=V;
    if(dep==4) {vis[u]=false;return;}
    for(int i=0;i<G[u].size();i++)
    {
        int v=G[u][i];
        if(vis[v]) continue;
        DFS(v,dep+1,V+Val[v]);
    }
    vis[u]=false;
}
int main() {
	srand(time(0));
    freopen("holiday.in","r",stdin);
    freopen("holiday.out","w",stdout);
    read(n);read(m);read(k);k++;
//    cerr<<n<<" "<<m<<" "<<k<<endl;
    for(int i=2;i<=n;i++) read(Val[i]);
    for(int i=1,u,v;i<=m;i++)
    {
        read(u);read(v);
        G[u].push_back(v);
        G[v].push_back(u);
    }
    for(int i=1;i<=n;i++) BFS(i);
    for(int i=1;i<=n;i++) G[i]=G2[i];
    ll Ans=0;
    do{
//    	for(int i=1;i<=n;i++) for(int j=1;j<=n;j++) f[i][j][0]=f[i][j][1]=f[i][j][2]=f[i][j][3]=0;
    	for(int i=1;i<=n;i++)
    		for(int j=1;j<G[i].size();j++) swap(G[i][j],G[i][rand()%j]);
    	for(int i=2;i<=n;i++)
    	{
        	Now=i;
        	for(int j=1;j<=n;j++) vis[j]=0;
        	DFS(i,1,Val[i]);
        	if(1.0*clock()/CLOCKS_PER_SEC<=1.50) break;
    	}
    	for(int i=0;i<G[1].size();i++)
        	for(int j=i+1;j<G[1].size();j++) Ans=max(Ans,f[G[1][i]][G[1][j]][3]);
	}while(1.0*clock()/CLOCKS_PER_SEC<=1.50);
    printf("%lld",Ans);
//    cerr<<1.0*clock()/CLOCKS_PER_SEC<<endl;
    return 0;
}
/*
清夜无尘，月色如银，酒斟时，须满十分；浮名浮利，虚苦劳神，叹隙中驹，石中火，梦中身。
虽抱文章，开口谁亲，且陶陶，乐尽天真；几时归去，作个闲人，对一张琴，一壶酒，一溪云。
*/
