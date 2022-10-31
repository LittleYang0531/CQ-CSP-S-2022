#include<bits/stdc++.h>
#define rd read()
#define ll long long
using namespace std;
const int N=305,M=1005;
ll n,m,k,val[N],ans=-1;
int enm;
ll read()
	{
		ll x=0,f=1;
		char c=getchar();
		while (c<'0' or c>'9')
			{
				if (c=='-')
					f=-1;
				c=getchar();
			}
		while (c>='0' and c<='9')
			{
				x=x*10+(c-'0');
				c=getchar();
			}
		return x*f;
	}
struct Edge{
	int to,next;
}edge[M];
int head[N];
void addedge(int from,int to)
	{
		enm++;
		edge[enm].to=to;
		edge[enm].next=head[from];
		head[from]=enm;
	}
void dfs(int p,int fr,ll res,int cnt)
	{
		if (cnt>=5)
			{
				if (cnt==5 and p==1) ans=max(ans,res);
				else
					return;
			}
		for(int i=head[p];i;i=edge[i].next)
			{
				if (edge[i].to==fr)
					continue;
				dfs(edge[i].to,p,res+val[edge[i].to],cnt+1);
			}
	}
int main()
	{
		freopen("holiday.in","r",stdin);
		freopen("holiday.out","w",stdout);
		n=rd,m=rd,k=rd;
		for (int i=2;i<=n;i++)
			val[i]=read();
		for (int i=1;i<=m;i++)
			{
				int f=rd,t=rd;
				addedge(f,t);
				addedge(t,f);
			}
		dfs(1,0,0,0);
		cout<<ans;
	}

