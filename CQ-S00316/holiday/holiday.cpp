/*
边权为 1
选出一个长度 <= 5*(k+1) 的环, 并选出环上的 4 个点使得其权值和最大, 并满足 4 个钦定点间距离不超过 k+1
S_u 为 从 u 出发走不超过 k+1 条边能到达的点集 (不包括 u 本身)
*/
#include <stdio.h>
#include <vector>
#define rep(i,a,b) for (int i(a); i<=(b); ++i)
#define drep(i,b,a) for (int i(b); i>=(a); --i)
inline long long rint() {
    long long n(0), f(1);
    char s(getchar());
    for (; s<'0'||s>'9'; s=getchar())
        if (s == '-') f = -1;
    for (; s>='0'&&s<='9'; s=getchar())
        n = n*10+s-48;
    return n*f;
}

const int kMaxN = 2600;
const int kMaxM = 10100;
int n, m, K;
long long s[kMaxN];
unsigned long long ans, cur;
bool vis[kMaxN];
std::vector<int> adj[kMaxN];

void dfs(int u, int h, int d) {
    vis[u] = 1;
    for (auto v : adj[u]) {
        if (h == 4 && v == 1) {
            ans = std::max(ans, cur);
            vis[u] = 0;
            return;
        }
        if (!vis[v] && d <= K) {
            dfs(v, h, d+1);
            cur += s[v];
            dfs(v, h+1, 0);
            cur -= s[v];
        }
    }
    vis[u] = 0;
}

signed main() {
    freopen("holiday.in", "r", stdin);
    freopen("holiday.out", "w", stdout);
    n = rint(), m = rint(), K = rint();
    rep(i,2,n) s[i] = rint();
    for (int i=1,x,y; i<=m; ++i) {
        x = rint(), y = rint();
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    dfs(1, 0, 0);
    printf("%llu\n", ans);
}
/*
为什么我不会 T1...
不知道多少分, 不管了

存一下考场的工具

## cp.cpp ##
#include <bits/stdc++.h>

signed main(int argc, const char* argv[]) {
    const std::string cmd = std::string("D:\\CSP2022\\mingw9.3.0\\mingw\\bin\\g++ ")+argv[1]+".cpp"+" -Wall -Wextra -fno-ms-extensions -Wshadow -o "+argv[1];
    printf("%s\n", cmd.c_str());
    std::system(cmd.c_str());
    return 0;
}

## cr.cpp ##
#include <bits/stdc++.h>

signed main(int argc, const char* argv[]) {
    assert(argc == 2);
    const std::string cmd = std::string("D:\\CSP2022\\mingw9.3.0\\mingw\\bin\\g++ ")+argv[1]+".cpp"+" -Wall -Wextra -fno-ms-extensions -Wshadow -o "+argv[1];
    printf("%s\n", cmd.c_str());
    if (std::system(cmd.c_str())){
        printf("Compile failed");
        return 0;
    }
    clock_t beg = clock();
    long ret = std::system((std::string("D:\\CQ-S00316\\")+argv[1]).c_str());
    clock_t end = clock();
    printf("\nProgram terminated in: %ld ms\n", end-beg);
    printf("Returns: %ld", ret);
}

## run.cpp ##
#include <bits/stdc++.h>

signed main(int argc, const char* argv[]) {
    assert(argc == 2);
    clock_t beg = clock();
    long ret = std::system((std::string("D:\\CQ-S00316\\")+argv[1]).c_str());
    clock_t end = clock();
    printf("\nProgram terminated in: %ld ms\n", end-beg);
    printf("Returns: %ld", ret);
}

## template.cpp ##
#include <stdio.h>
#define rep(i,a,b) for (int i(a); i<=(b); ++i)
#define drep(i,b,a) for (int i(b); i>=(a); --i)
inline int rint() {
    int n(0), f(1);
    char s(getchar());
    for (; s<'0'||s>'9'; s=getchar())
        if (s == '-') f = -1;
    for (; s>='0'&&s<='9'; s=getchar())
        n = n*10+s-48;
    return n*f;
}
signed main() {
    printf("%d\n", rint());
}
*/