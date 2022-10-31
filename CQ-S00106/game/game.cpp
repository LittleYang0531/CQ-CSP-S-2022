#include<bits/stdc++.h>
#define ll long long
#define lowbit(x) (x&-x)
#define ls(p) (p<<1)
#define rs(p) (p<<1|1) 
#define MOD (1000000007)
#define MAXN (100005)
#define MAXM (100005)
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
void write(ll x,bool f)
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
void print(ll x,char ch)
{
	write(x,1);
	if(ch) putchar(ch);
}
int n,m,q;
int F[MAXN][19][2],G[MAXM][19][2],Log[MAXN];
ll qFmin(int l,int r)
{
	int s=Log[r-l+1];
	return min(F[l][s][0],F[r-(1<<s)+1][s][0]);
}
ll qFmax(int l,int r)
{
	int s=Log[r-l+1];
	return max(F[l][s][1],F[r-(1<<s)+1][s][1]);
}
ll qGmin(int l,int r)
{
	int s=Log[r-l+1];
	return min(G[l][s][0],G[r-(1<<s)+1][s][0]);
}
ll qGmax(int l,int r)
{
	int s=Log[r-l+1];
	return max(G[l][s][1],G[r-(1<<s)+1][s][1]);
}
int main()
{
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	read(n),read(m),read(q);
	for(int i=2;i<=n;i++)
		Log[i]=Log[i>>1]+1;
	for(int i=1;i<=n;i++)
	{
		read(F[i][0][0]);
		F[i][0][1]=F[i][0][0]; 
	}
	for(int i=1;i<=m;i++)
	{
		read(G[i][0][0]);
		G[i][0][1]=G[i][0][0];
	}
	for(int j=1;j<=Log[n];j++)
	{
		for(int i=1;i+(1<<j)-1<=n;i++)
		{
			F[i][j][0]=min(F[i][j-1][0],F[i+(1<<(j-1))][j-1][0]);
			F[i][j][1]=max(F[i][j-1][1],F[i+(1<<(j-1))][j-1][1]);
		}
	}
	for(int j=1;j<=Log[m];j++)
	{
		for(int i=1;i+(1<<j)-1<=m;i++)
		{
			G[i][j][0]=min(G[i][j-1][0],G[i+(1<<(j-1))][j-1][0]);
			G[i][j][1]=max(G[i][j-1][1],G[i+(1<<(j-1))][j-1][1]);
		}
	}
	while(q--)
	{
		int l1,r1,l2,r2;
		read(l1),read(r1),read(l2),read(r2);
		if(!(l1^r1))
		{
			if(F[l1][0][0]<0) print((ll)F[l1][0][0]*qGmax(l2,r2),'\n');
			else print((ll)F[l1][0][0]*qGmin(l2,r2),'\n');
			continue;
		}
		if(!(l2^r2))
		{
			if(G[l2][0][0]<0) print((ll)G[l2][0][0]*qFmin(l1,r1),'\n');
			else print((ll)G[l2][0][0]*qFmax(l1,r1),'\n');
			continue;
		}
		print(qFmax(l1,r1)*qGmin(l2,r2),'\n');
	}
	return 0;
}
