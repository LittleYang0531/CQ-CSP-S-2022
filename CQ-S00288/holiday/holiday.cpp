#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;
#define maxn 2505
#define maxm 10005
#define LL long long
struct node{
	int to,next;
}e[maxm<<1];
int h[maxn],np=0;
void add(int u,int v)
{
	e[++np]=(node){v,h[u]};
	h[u]=np;
}
int n,m,k;
LL a[maxn];
int vis[10];
LL ans=0;
void dfs(int u,LL sum,int z,int step)
{
	if(step>4) return ;
//	cout<<"! "<<u<<' '<<sum<<'\n';
//	for(int i=1;i<=step;i++) cout<<vis[i]<<' ';
//	cout<<'\n';
//	cout<<sum<<'\n';
	if(u==1 && step==4)
	{
//		for(int i=1;i<=step;i++) cout<<vis[i]<<' ';
//		cout<<sum<<'\n';
		ans=max(ans,sum);
		return ;
	}
	for(int p=h[u];p;p=e[p].next)
	{
		if(z>0) dfs(e[p].to,sum,z-1,step);
		if(step==4 && e[p].to==1)
		{
			ans=max(ans,sum);
			return ;
		}
		if(e[p].to==1) continue ;
		bool f=1;
		for(int i=1;i<=step;i++)
			if(vis[i]==e[p].to)
			{
				f=0;
				break;
			}
		if(!f) continue ;
		vis[step+1]=e[p].to;
		LL v=a[e[p].to];
		a[e[p].to]=0;
		dfs(e[p].to,sum+v,k,step+1);
		a[e[p].to]=v;
	}	
}

void dfs2(int u,LL sum,int step)
{
	if(step==5 && u==1)
	{
		ans=max(ans,sum);
		return ;
	}
	if(step==5) return ;
	for(int p=h[u];p;p=e[p].next)
	{
		bool f=1;
		for(int i=1;i<=step;i++) if(vis[i]==e[p].to) {f=0;break;}
		dfs2(e[p].to,sum+a[e[p].to],step+1);
	}
}
signed main()
{
	freopen("holiday.in","r",stdin);
	freopen("holiday.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin>>n>>m>>k;
	for(int i=2;i<=n;i++) cin>>a[i];
	int x,y;
	for(int i=1;i<=m;i++)
	{
		cin>>x>>y;
		add(x,y); add(y,x);
	}
	if(n<=10 && m<=20)
	{
//		k++;
		dfs(1,0,k,0);
		cout<<ans;
		return 0;
	}
	if(k==0)
	{
		dfs2(1,0,0);
		cout<<ans;
		return 0;
	}
//	dfs3()
	return 0;
}
