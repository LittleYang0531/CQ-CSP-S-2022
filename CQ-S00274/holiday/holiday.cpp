#include<bits/stdc++.h>
#define maxn 2505
#define maxm 10005
#define ll long long
using namespace std;
int n,m,k;
ll a[maxn];
struct node{
	int to,next;
}e[maxm*4];
int cnt,h[maxn];
bool vis[maxn];
ll sum,ans;
inline void edge(int u, int v)
{
	e[++cnt].to = v;
	e[cnt].next = h[u];
	h[u] = cnt;
}
inline void dfs(int tp, int yu)
{
	for (int i=h[tp]; i; i=e[i].next)
	{
		int y=e[i].to;
		if (yu-1==0 && y==1)
		{
			ans = max(ans,sum);
//			cout<<endl<<"sum : "<<sum<<endl;
//			cout<<"ans : "<<ans<<endl;
			break;
		}
		if (vis[y]==0 && yu-1!=0 && y!=1)
		{
			vis[y] = 1;
			sum += a[y];
//			cout<<y<<" ";
			dfs(y,yu-1);
			sum -= a[y];
			vis[y] = 0;
		}
	}
	return ;
}
inline void dfs2(int tp, int yu, int pd)
{
	if (pd>k)
		return ;
	if (yu==0)
	{
		if (tp==1)
			ans = max(ans,sum);
		return ;
	}
	for (int i=h[tp]; i; i=e[i].next)
	{
		int y=e[i].to;
		if (pd==k)
		{
			if (vis[y]==1)
				continue;
			else
			{
				vis[y] = 1;
				sum += a[y];
				dfs2(y,yu-1,0);
				sum -= a[y];
				vis[y] = 0;
			}
		}
		else
		{
			if (vis[y]==1)
				dfs2(y,yu,pd+1);
			else
			{
				vis[y] = 1;
				sum += a[y];
				dfs2(y,yu-1,0);
				sum -= a[y];
				vis[y] = 0;
				
				dfs2(y,yu,pd+1);
			}
		}
	}
}
int main()
{
	freopen("holiday.in","r",stdin);
	freopen("holiday.out","w",stdout);
	cin>>n>>m>>k;
	for (int i=1; i<n; i++)
		scanf("%lld",&a[i+1]);
	for (int i=1; i<=m; i++)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		edge(x,y);
		edge(y,x);
	}
	if (k==0)
	{
		vis[1] = 1;
		dfs(1,5);
		cout<<ans;	
	}
	else
	{
		dfs2(1,5,0);
		cout<<ans;
	}
	return 0;
}
