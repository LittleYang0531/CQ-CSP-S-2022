#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll M=5005,MAXN=9223372036854775807;
ll n,m,f[M],dp[M][M],dis[M][M],h[M],cnt;
bool vis[M],b[M][M];
struct node
{
	ll to,next,w;
}e[1000];
void add(int u,int v,int w)
{
	e[++cnt].w=w;
	e[cnt].to=v;
	e[cnt].next=h[u];
	h[u]=cnt;
}
int main()
{
	freopen("transmit.in","r",stdin);
	freopen("transmit.out","w",stdout);
	return 0;
}
