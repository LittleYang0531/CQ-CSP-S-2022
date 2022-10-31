#include<bits/stdc++.h>
#define N 1000005
#define int long long
using namespace std;
int n,Q,k,v[N],d[N],f[N][25],dp[N],onpt[N];
vector<int>pt,son[N];
stack<int>st;
int q[N],l,r;
inline int re()
{
	int x=0,f=1;
	char ch=getchar();
	while(ch<'0'||ch>'9')
	{
		if(ch=='-') f=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9')
	{
		x=(x<<1)+(x<<3)+(ch^48);
		ch=getchar();
	}
	return f*x;
}
void dfs(int x,int prt)
{
	d[x]=d[prt]+1;
	f[x][0]=prt;
	for(int i=1;i<=20;i++) f[x][i]=f[f[x][i-1]][i-1];
	for(int y:son[x]) if(y!=prt) dfs(y,x);
}
int lca(int x,int y)
{
	if(d[x]<d[y]) swap(x,y);
	for(int i=20;i>=0;i--)
		if(d[f[x][i]]>=d[y]) x=f[x][i];
	if(x==y) return x;
	for(int i=20;i>=0;i--)
		if(f[x][i]!=f[y][i]) x=f[x][i],y=f[y][i];
	return f[x][0];
}
int getdis(int x,int y)
{
	int L=lca(x,y);
	return d[x]+d[y]-2*d[L];
}
int solve(int s,int t)
{
	int L=lca(s,t);
	pt.clear();
	l=1,r=0;
	for(int i=1;i<=n;i++) dp[i]=1e13,onpt[i]=0;
	while(st.size()) st.pop();
	while(s!=L) pt.push_back(s),s=f[s][0];
	pt.push_back(L);
	while(t!=L) st.push(t),t=f[t][0];
	while(st.size()) pt.push_back(st.top()),st.pop();
	int m=pt.size();
	for(int i=0;i<m;i++) onpt[pt[i]]=1;
	dp[pt[0]]=v[pt[0]];
	for(int x:son[pt[0]])
	{
		if(onpt[x]) continue;
		dp[x]=dp[pt[0]]+v[x];
		q[++r]=x;
	}
	for(int i=1;i<m;i++)
	{
		int x=pt[i];
		for(int j=i-1;j>=max(0ll,i-k);j--)
			dp[x]=min(dp[x],dp[pt[j]]+v[x]);
		for(int j=l;j<=r;j++)
			if(getdis(x,q[j])<=k) dp[x]=min(dp[x],dp[q[j]]+v[x]);
			else l++;
		for(int y:son[x])
		{
			if(onpt[y]) continue;
			for(int j=i;j>=max(0ll,i-k+1);j--) dp[y]=min(dp[y],dp[pt[j]]+v[y]);
			q[++r]=y;
		}
	}
	return dp[pt[m-1]];
}
signed main()
{
	freopen("transmit.in","r",stdin);
	freopen("transmit.out","w",stdout);
	n=re(),Q=re(),k=re();
	for(int i=1;i<=n;i++) v[i]=re();
	for(int i=1,x,y;i<n;i++)
	{
		x=re(),y=re();
		son[x].push_back(y);
		son[y].push_back(x);
	}
	dfs(1,0);
	for(int s,t;Q--;)
	{
		s=re(),t=re();
		printf("%lld\n",solve(s,t));
	}
	return 0;
}
/*
d**kwish       \
hhpq			\
push_and_knock   \
junkfood 		  \
multiset		   \				
horse               \                   Orz
chicken(unrated)    /
stasis             /
jason_sun         /
rxm              /
geng            /
captainWei     /
soup          /
*/
