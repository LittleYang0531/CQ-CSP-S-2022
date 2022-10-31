#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;
#define maxn 200005
#define LL long long
#define inf 0x7fffffffffffffff/2
struct node{
	int to,next;
}e[maxn];
int h[maxn],np=0;
void add(int u,int v)
{
	e[++np]=(node){v,h[u]};
	h[u]=np;
}
int n,q,k;
int a[maxn];
LL ans;
//bool f=0;
//bool vis[maxn];
void dfs(int u,int to,int fa,LL sum,int z)
{
	if(sum>=ans) return ;
	if(u==to) {ans=sum;return ;}
	for(int p=h[u];p;p=e[p].next)
	{
		int v=e[p].to;
		if(v==fa) continue ;
		if(z==1 || v==to)
		{
//			vis[v]=1;
			dfs(v,to,u,sum+a[v],k);
//			vis[v]=0;
		}
		else
		{
//			vis[v]=1;
			dfs(v,to,u,sum+a[v],k);
//			vis[v]=0;
			dfs(v,to,u,sum,z-1);
		}
	}
}
signed main()
{
	freopen("transmit.in","r",stdin);
	freopen("transmit.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin>>n>>q>>k;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1,x,y;i<n;i++)
	{
		cin>>x>>y;
		add(x,y); add(y,x);
	}
	while(q--)
	{
//		f=0;
		ans=inf;
		int u,v;
		cin>>u>>v;
		dfs(u,v,0,(long long)(a[u]),k);
		cout<<ans<<'\n';
	}
	return 0;
}
