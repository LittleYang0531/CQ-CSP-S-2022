#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
#include <algorithm>
#include <unordered_map>
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

const int N = 500005;
unordered_map<int,int> b[N];
int inde[N],oude[N];
vector<int> g[N];//反图
vector<int> g2[N];
int cntou,cntin;
int n,m,q;

inline void update1(int u,int v){
    if(oude[u]==1)
        cntou--;
    oude[u]--;
    if(oude[u]==1)
        cntou++;
    if(inde[v]>0)
        cntin--;
    inde[v]--;
    if(inde[v]>0)
        cntin++;
}

inline void update2(int u,int v){
    if(oude[u]==1)
        cntou--;
    oude[u]++;  
    if(oude[u]==1)
        cntou++;
    if(inde[v]>0)
        cntin--;
    inde[v]++;
    if(inde[v]>0)
        cntin++;
}

namespace Check{
    int inn[N];
    bool vis[N];

    inline bool check(){
        for(int k=1;k<=n;k++){
            inn[k] = inde[k];
            vis[k] = false;
        }
        queue<int> q;
        for(int k=1;k<=n;k++)
            if(!inn[k])
                q.push(k);
        while(q.size()){
            auto u = q.front();
            q.pop();
            for(auto v:g2[u]){
            	if(b[u][v])
            		continue;
                if(!(--inn[v]))
                    q.push(v);
			}
        }
        for(int k=1;k<=n;k++)
            if(inn[k]>0)
                q.push(k);
        while(q.size()){
            auto u = q.front();
            q.pop();
            if(vis[u])
                continue;
            vis[u] = true;
            for(auto v:g[u]){
            	if(b[v][u])
            		continue;
                if(!vis[v])
                    q.push(v);
			}
        }
        for(int k=1;k<=n;k++)
            if(!vis[k])
                return false;
        return true;
    }
}

int main(){
    freopen("galaxy.in","r",stdin);
    freopen("galaxy.out","w",stdout);
    n = in(),m = in();
    for(int k=1;k<=m;k++){
        int u = in(),v = in();
        g[v].push_back(u);
        g2[u].push_back(v);
        oude[u]++;
        inde[v]++;
    }
    for(int k=1;k<=n;k++){
        if(inde[k]>0)
            cntin++;
        if(oude[k]==1)
            cntou++;
    }
    q = in();
    while(q--){
        int ops = in();
        if(ops==1){
            int u = in(),v = in();
            update1(u,v);
            b[u][v] = true;
        }
        else if(ops==2){
            int v = in();
            for(auto u:g[v]){
                if(b[u][v])
                    continue;
                update1(u,v);
                b[u][v] = true;
            }
        }
        else if(ops==3){
            int u = in(),v = in();
            update2(u,v);
            b[u][v] = false;
        }
        else{
            int v = in();
            for(auto u:g[v]){
                if(!b[u][v])
                    continue;
                update2(u,v);
                b[u][v] = false;
            }
        }
        if(Check::check()&&cntou==n)
            puts("YES");
        else
            puts("NO");
    }
    return 0;
}
//拜托了