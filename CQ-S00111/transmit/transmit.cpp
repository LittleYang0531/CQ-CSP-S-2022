#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const int MAXN=1e4+5;
const ll INF=1e9+7;
int n,q,k;
bool com[MAXN][MAXN],use[MAXN];
ll v[MAXN],ans;

int read()
{
	int x=0,f=1;
	char c=getchar();
	while(!isdigit(c))
	{
		if(c=='-') f=-1;
		c=getchar();
	}
	while(isdigit(c))
		x=x*10+c-'0',c=getchar();
	return x*f;
}

void write(ll x)
{
	if(x<0) putchar('-'),x=-x;
	if(x>9) write(x/10);
	putchar(x%10+'0');
}

void dfs(int t,int point,ll value)
{
	if(point==t)
	{
		ans=min(ans,value);
		return;
	}
	if(value>ans) return;
	if(use[point]) return;
	use[point]=true;
	for(int i=1;i<=n;i++)
		if(com[point][i]&&point!=i)
			dfs(t,i,value+v[i]);
	use[point]=false;
}

int main()
{
	freopen("transmit.in","r",stdin);
	freopen("transmit.out","w",stdout);
	n=read();
	q=read();
	k=read();
	for(int i=1;i<=n;i++) v[i]=read();
	for(int i=1;i<n;i++)
	{
		int a,b;
		a=read();
		b=read();
		com[a][b]=true;
		com[b][a]=true;
	}
	while(q--)
	{
		ans=INF;
		int s,t;
		s=read();
		t=read();
		dfs(t,s,v[t]);
		write(ans),putchar('\n');
	}
	return 0;
}

