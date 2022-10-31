#include<bits/stdc++.h>
using namespace std;
struct node
{
	int to,next;
}e[20005],e1[20005];
int n,m,k,s[2505],cnt,h[10005];
void add(int x,int y)
{
	e[++cnt].to=y;
	e[cnt].next=h[x];
	h[x]=cnt;
}
int vis[2505],ans=-1;
void dfs_spe(int root,int step,int now)
{
	if(step==5)
	{
		if(root==1)ans=max(ans,now);
		return ;
	}
	for(int i=h[root];i;i=e[i].next)
	{
		int y=e[i].to;
		if(vis[y])continue;
		vis[y]=1;
		dfs_spe(y,step+1,now+s[y]);
		vis[y]=0;
	}
}
int v[2505];
int h1[10005],cnt1;
void add1(int x,int y)
{
	e1[++cnt1].to=y;
	e1[cnt1].next=h1[x];
	h1[x]=cnt1;
}
int g[2505][2505];
void dfs(int root,int fqr,int step)
{
	if(step==k+1)return ;
	v[root]=1;
	for(int i=h[root];i;i=e[i].next)
	{
		int y=e[i].to;
		if(v[y])continue;
		if(!g[fqr][y])
		{
			add1(fqr,y);
			add1(y,fqr);
			g[fqr][y]=g[y][fqr]=1;			
		}
//		cout<<fqr<<' '<<root<<' '<<y<<' '<<step<<'\n';
		dfs(y,fqr,step+1);
	}
}
void prepare()
{
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)v[j]=0;
//		cout<<"prepare: \n";
		dfs(i,i,0);
	}
}
int kong[2505];
void dfs_now(int root,int now,int step)
{
	if(step==5)
	{
		if(root==1)ans=max(ans,now);
		return ;
	}
	for(int i=h1[root];i;i=e1[i].next)
	{
		int y=e1[i].to;
		if(!kong[y])
		{
			kong[y]=1;
//			cout<<root<<' '<<y<<' '<<s[y]<<' '<<now<<'\n';
			dfs_now(y,now+s[y],step+1);
			kong[y]=0;			
		}
		else if(y==1&&step==4)
		{
			dfs_now(y,now+s[y],step+1);
		}
	}
}
int main()
{	
	freopen("holiday.in","r",stdin);
	freopen("holiday.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(NULL);cout.tie(NULL);
	cin>>n>>m>>k;
	for(int i=1;i<=n-1;i++)cin>>s[i+1];
	for(int i=1;i<=m;i++)
	{
		int x,y;
		cin>>x>>y;
		add(x,y);
		add(y,x);
	}
	if(k==0)
	{
		dfs_spe(1,0,0);
		cout<<ans;
		return 0;
	}
	else
	{
		prepare();
//		cout<<"dfsnow: \n";
		kong[1]=1;
		dfs_now(1,0,0);
		cout<<ans;
	}
	return 0;
}
/*
8 8 1
9 7 1 8 2 3 6
1 2
2 3
3 4
4 5
5 6
6 7
7 8
8 1

7 9 0
1 1 1 2 3 4
1 2
2 3
3 4
1 5
1 6
1 7
5 4
6 4
7 4
*/
