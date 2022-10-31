#include <iostream>
#include <vector>
#include <set>
#include <queue>
#include <cstring>
#include <algorithm>
#define int long long
using namespace std;

namespace fastio{
    inline int in(){
        char c = getchar();
        int f = 1,w = 0;
        while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();};
        while(c>='0'&&c<='9'){(w*=10)+=(c^48),c=getchar();};
        return f*w;
    }
    char s[30];
    int top;
    inline void out(int x){
        if(x<0){
            putchar('-');
            x = -x;
        }
        do{s[++top]=x%10;x/=10;}while(x);
        while(top)putchar(s[top--]^48);
    }
};
using fastio::in;
using fastio::out;

typedef pair<int,int> PII;
const int N = 2505;
vector<int> g[N];
set<PII> f[N];
int dis[N][N];
bool b[N];
int w[N];
int n,m,K;

inline void bfs(int begin){
    memset(b,false,sizeof(b));
    queue<int> q;
    q.push(begin);
    dis[begin][begin] = 0;
    while(q.size()){
        auto u = q.front();
        q.pop();
        if(b[u])
            continue;
        b[u] = true;
        for(auto v:g[u]){
            if(dis[begin][v]>dis[begin][u]+1){
                dis[begin][v] = dis[begin][u]+1;
                q.push(v);
            }
        }
    }
}

signed main(){
    freopen("holiday.in","r",stdin);
    freopen("holiday.out","w",stdout);
    n = in(),m = in(),K = in()+1;
    for(int k=2;k<=n;k++)
        w[k] = in();
    for(int k=1;k<=m;k++){
        int a = in(),b = in();
        g[a].push_back(b);
        g[b].push_back(a);
    }
    memset(dis,0x3f,sizeof(dis));
    for(int k=1;k<=n;k++)
        bfs(k);
    // for(int k=1;k<=n;k++){
    //     for(int j=1;j<=n;j++)
    //         cout <<dis[k][j] << " ";
    //     cout << endl;
    // }
    for(int k=2;k<=n;k++){
        if(dis[1][k]>K)
            continue;
        for(int j=2;j<=n;j++){
            if(k==j||dis[k][j]>K)
                continue;
            f[j].insert({w[k],k});
        }
    }
    // for(int k=1;k<=n;k++){
    //     cout <<k<<":"<< endl;
    //     for(auto tmp:f[k])
    //         cout << tmp.second <<" ";
    //     cout <<endl;
    // }
    int ans = 0;
    for(int k=2;k<=n;k++){
        for(int j=2;j<=n;j++){
            if(k==j||dis[k][j]>K)
                continue;
            if(!f[k].size()||!f[j].size())
                continue;
            //cout <<k <<" " << j << endl;
            auto x = --f[k].end(),y = --f[j].end();
            while((*y).second==k&&y!=f[j].begin())
                y--;
            if((*y).second==k)
                continue;
            while(((*x).second==j||(*x).second==(*y).second)&&x!=f[k].begin())
                x--;
            if((*x).second==j||(*x).second==(*y).second)
                continue;
            ans = max(ans,(*x).first+(*y).first+w[k]+w[j]);

        }
    }
    out(ans);
    return 0;
}
//拜托了