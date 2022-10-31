#include<bits/stdc++.h>
#define ll long long
#define LL __int128
#define lowbit(x) (x&-x)
#define ls(p) (p<<1)
#define rs(p) (p<<1|1) 
#define MOD (1000000007)
#define MAXN (2505)
#define MAXM (10005)
#define debug(x) cerr<<#x<<" = "<<x;
using namespace std;
void read(int &x)
{
	char ch=0;bool f=0;x=0;
	while(ch<'0'||ch>'9'){f|=!(ch^'-');ch=getchar();}
	while(ch>='0'&&ch<='9'){x=(x<<3)+(x<<1)+(ch^48);ch=getchar();}
	x=f?-x:x;
}
void read(ll &x)
{
	char ch=0;bool f=0;x=0;
	while(ch<'0'||ch>'9'){f|=!(ch^'-');ch=getchar();}
	while(ch>='0'&&ch<='9'){x=(x<<3)+(x<<1)+(ch^48);ch=getchar();}
	x=f?-x:x;
}
void write(LL x,bool f)
{
	if(!x)
	{
		if(f) putchar('0');
		return;
	}
	if(x<0)
	{
		putchar('-');
		x=-x;
	}
	write(x/10,0);
	putchar((x%10)^48);
}
void print(LL x,char ch)
{
	write(x,1);
	if(ch) putchar(ch);
}
ll qpow(ll x,ll y)
{
	ll res=1;
	while(y)
	{
		if(y&1) res=res*x%MOD;
		x=x*x%MOD,y>>=1;
	}
	return res;
}
int cnt;
int head[MAXN],nxt[MAXM<<1],to[MAXM<<1];
void add(int u,int v)
{
	++cnt;
	to[cnt]=v;
	nxt[cnt]=head[u],head[u]=cnt;
}
struct node{
	int to,w;
};
bool operator<(node x,node y){return x.w>y.w;}
int n,m,k;
int f[MAXN][MAXN];
ll w[MAXN];
bool vis[MAXN],tg[MAXN][MAXN];
priority_queue<node> q;
void DJ(int st)
{
	memset(vis,0,sizeof(vis));
	while(!q.empty()) q.pop();
	f[st][st]=0;
	q.push((node){st,0});
	while(!q.empty())
	{
		int u=q.top().to;
		q.pop();
		if(vis[u]) continue;
		vis[u]=1;
		if(f[st][u]>k) continue;
		for(int i=head[u];i;i=nxt[i])
		{
			int v=to[i];
			if(f[st][u]+1<f[st][v])
			{
				f[st][v]=f[st][u]+1;
				q.push((node){v,f[st][v]});
			}
		}
	}
}
int tx,ty;
vector<int> Nxt[MAXN];
int main()
{
	freopen("holiday.in","r",stdin);
	freopen("holiday.out","w",stdout);
	LL mv=0,ans=0;
	read(n),read(m),read(k);
	for(int i=2;i<=n;i++)
	{
		read(w[i]);
		mv=max(mv,(LL)w[i]);
	}
	++k;
	memset(f,127,sizeof(f));
	for(int i=1;i<=m;i++)
	{
		read(tx),read(ty);
		add(tx,ty);
		add(ty,tx);
	}
	for(int i=1;i<=n;i++)
		DJ(i);
	for(int i=1;i<=n;i++)
	{
		tg[i][i]=1;
		for(int j=1;j<=n;j++)
		{
			if(f[i][j]<=k&&(i^j))
			{
				tg[i][j]=1;
				Nxt[i].push_back(j);
			}
		}
	}
	for(const auto A:Nxt[1])
	{
		for(const auto D:Nxt[1])
		{
			if(w[A]+w[D]+mv+mv<=ans) continue;
			if(A^D)
			{
				for(const auto B:Nxt[A])
				{
					if(!(B^A)) continue;
					if(!(B^D)) continue;
					if(w[A]+w[B]+w[D]+mv<=ans) continue;
					for(const auto C:Nxt[D])
					{
						if(!(C^A)) continue;
						if(!(C^B)) continue;
						if(!(C^D)) continue;
						if(tg[B][C])
							ans=max(ans,(LL)w[A]+(LL)w[B]+(LL)w[C]+(LL)w[D]);
					}
				}
			}
		}
	}
	print(ans,0);
	return 0;
}
