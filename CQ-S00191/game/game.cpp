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

const int N = 300005,M = 18,INF = 0x7fffffffffffffff;
// int st1[M][N],st2[M][N],st3[M][N],st4[M][N];//A>=0的最大值 A>=0的最小值 A<=0的最大值 A<=0的最小值
// int st5[M][N],st6[M][N];//B的最大值 B的最小值
int a[N],b[N];
int n,m,q;

class maxST{
    public:
        int st[M][N];

        inline void init(int len){
            for(int k=1;k<M;k++)
                for(int j=1;j+(1<<(k-1))<=len;j++)
                    st[k][j] = max(st[k-1][j],st[k-1][j+(1<<(k-1))]);
        }

        inline int query(int l,int r){  
            int x = __lg(r-l+1);
            return max(st[x][l],st[x][r-(1<<x)+1]);
        }
}st1,st3,st5;
class minST{
    public:
        int st[M][N];

        inline void init(int len){
            for(int k=1;k<M;k++)
                for(int j=1;j+(1<<(k-1))<=len;j++)
                    st[k][j] = min(st[k-1][j],st[k-1][j+(1<<(k-1))]);
        }

        inline int query(int l,int r){  
            int x = __lg(r-l+1);
            return min(st[x][l],st[x][r-(1<<x)+1]);
        }
}st2,st4,st6;

signed main(){
    freopen("game.in","r",stdin);
    freopen("game.out","w",stdout);
    n = in(),m = in(),q = in();
    for(int k=1;k<=n;k++){
        a[k] = in();
        if(a[k]>0){
            st1.st[0][k] = st2.st[0][k] = a[k];
            st3.st[0][k] = -INF;
            st4.st[0][k] = INF;
        }
        else{
            st1.st[0][k] = -INF;
            st2.st[0][k] = INF;
            st3.st[0][k] = st4.st[0][k] = a[k];
        }
    }
    for(int k=1;k<=m;k++){
        b[k] = in();
        st5.st[0][k] = st6.st[0][k] = b[k];
    }
    st1.init(n);
    st2.init(n);
    st3.init(n);
    st4.init(n);
    st5.init(m);
    st6.init(m);
    for(int t=1;t<=q;t++){
        int l1 = in(),r1 = in(),l2 = in(),r2 = in();
        int ca,cb;
        if(st6.query(l2,r2)>=0){
            ca = max(st1.query(l1,r1),st3.query(l1,r1));
            if(ca<0)
                cb = st5.query(l2,r2);
            else
                cb = st6.query(l2,r2);
        }
        else if(st5.query(l2,r2)<=0){
            ca = min(st2.query(l1,r1),st4.query(l1,r1));
            if(ca<0)
                cb = st5.query(l2,r2);
            else
                cb = st6.query(l2,r2);
        }
        else{
            int ans = -INF;
            ca = st2.query(l1,r1);
            cb = st6.query(l2,r2);
            if(ca<INF&&ca>-INF&&cb<INF&&cb>-INF)
                ans = max(ans,ca*cb);
            ca = st3.query(l1,r1);
            cb = st5.query(l2,r2);
            if(ca<INF&&ca>-INF&&cb<INF&&cb>-INF)
                ans = max(ans,ca*cb);
            out(ans);
            putchar('\n');
            continue;
        }
        out(ca*cb);
        putchar('\n');
    }
    return 0;
}
//拜托了