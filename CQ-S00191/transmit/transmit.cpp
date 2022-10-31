#include <iostream>
#include <vector>
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

const int N = 200005,INF = 0x3f3f3f3f3f3f3f3f;
vector<int> g[N];
int fa[N],dep[N];
int v[N],f[N];
int n,q,K;

void dfs(int u,int father){
    fa[u] = father;
    dep[u] = dep[father]+1;
    for(auto v:g[u]){
        if(v==father)
            continue;
        dfs(v,u);
    }
}

inline int solve(vector<int> &q){
    f[1] = v[q[0]];
    int len = q.size();
    for(int k=2;k<=len;k++){
        f[k] = INF;
        for(int j=max(1ll,k-K);j<k;j++)
            f[k] = min(f[k],f[j]+v[q[k-1]]);
    }
    return f[len];
}

signed main(){
    freopen("transmit.in","r",stdin);
    freopen("transmit.out","w",stdout);
    n = in(),q = in(),K = in();
    for(int k=1;k<=n;k++)
        v[k] = in();
    for(int k=1;k<n;k++){
        int a = in(),b = in();
        g[a].push_back(b);
        g[b].push_back(a);
    }
    dfs(1,0);
    for(int h=1;h<=q;h++){
        int s = in(),t = in();
        vector<int> da,db;
        int a = s,b = t;
        if(dep[a]<dep[b])
            swap(a,b);
        while(dep[a]>dep[b]){
            da.push_back(a);
            a = fa[a];
        }
        while(a!=b){
            da.push_back(a);
            db.push_back(b);
            a = fa[a];
            b = fa[b];
        }
        da.push_back(a);
        for(int k=db.size()-1;~k;k--)
            da.push_back(db[k]);
        if(da[0]!=s){
            vector<int> tmp;
            for(auto x:da)
                tmp.push_back(x);
            da.clear();
            while(tmp.size()){
                da.push_back(tmp.back());
                tmp.pop_back();
            }
        }
        out(solve(da));
        putchar('\n');
    }
    return 0;
}
