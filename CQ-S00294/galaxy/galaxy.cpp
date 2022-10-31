#include<bits/stdc++.h>

#define  Int  long long int
#define  Pub  public
#define  rand  Rand
using std::min;using std::max;
std::mt19937 rand(time(0));

int readint(){
    int x=0;char c=0;
    while(c<'0'||c>'9')c=getchar();
    while(c>='0'&&c<='9')x=(x<<3)+(x<<1)+c-'0',c=getchar();
    return x;
}

int n,m,q;
std::vector<int> b[500005];
std::set<int> to[500005],fr[500005];
int ohno,si;

void solve1(int u,int v){
    to[u].erase(v);
    fr[v].erase(u);
    si=to[u].size();
    if(si==1)--ohno;
    if(si==0)++ohno;
}
void solve2(int u,int v){
    to[u].insert(v);
    fr[v].insert(u);
    si=to[u].size();
    if(si==1)--ohno;
    if(si==2)++ohno;
}

int main(){
    freopen("galaxy.in","r",stdin);
    freopen("galaxy.out","w",stdout);
    
    n=readint(),m=readint();
    for(int i=1,u,v;i<=m;++i){
        u=readint(),v=readint();
        b[v].push_back(u);
        to[u].insert(v);
        fr[v].insert(u);
    }
    for(int i=1;i<=n;++i)if(to[i].size()!=1)++ohno;
    q=readint();
    int u,v;char t;
    while(~--q){
        t=getchar();
        if(t=='1'){
            u=readint(),v=readint();
            solve1(u,v);
        }
        if(t=='2'){
            u=readint();
            std::set<int> uu=fr[u];
            for(int i:uu)solve1(i,u);
        }
        if(t=='3'){
            u=readint(),v=readint();
            solve2(u,v);
        }
        if(t=='4'){
            u=readint();
            for(int i:b[u])if(to[i].find(u)==to[i].end())solve2(i,u);
        }
        if(ohno==0)putchar('Y'),putchar('E'),putchar('S'),putchar('\n');
        else putchar('N'),putchar('O'),putchar('\n');
    }
    
    return 0;
}
