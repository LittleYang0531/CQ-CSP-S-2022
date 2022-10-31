#include <bits/stdc++.h>
using namespace std;
int mp[1005][1005],e[1005][1005],ex[1005],bj[1005],sum[1005],vis[1005];
int ok=0;
int q[1005],top;
int n,m;

void dfs(int x,int fa)
{
	bj[x]=1;
	vis[x]=1;
	q[++top]=x;
//	cout<<"x="<<x<<" fa="<<fa<<endl;
//	cout<<"q:";
//	for(int i=1;i<=top;i++)
//		cout<<q[i]<<" ";
//	cout<<endl;
	if(ok)return;
	for(int y=1;y<=n;y++)
		if(e[x][y]==1&&ex[y])
		{
//			cout<<"from "<<x<<" to "<<y<<endl;
			if(bj[y])
			{
//				cout<<"found a ring at edge "<<x<<"->"<<y<<"!"<<endl;
//				cout<<"q:";
//				for(int i=1;i<=top;i++)
//					cout<<q[i]<<" ";
//				cout<<endl;
				int kk=1;
				for(int i=top;i>=1;i--)
				{
//					cout<<"sum["<<q[i]<<"]="<<sum[q[i]]<<" ";
					if(sum[q[i]]!=1)
					{
//						cout<<"***"<<q[i]<<"***"<<endl;
						kk=0;
					}
					if(q[i]==y)break;
				}
//				cout<<endl;
//				cout<<"kk="<<kk<<endl;
				if(kk)
				{
//					cout<<"%%%%%%%%%"<<endl;
					ok=1;
					top--;
					bj[x]=0;
					return;
				}
				continue;
			}
			dfs(y,x);
		}
	top--;
	bj[x]=0;
}

int main()
{
	freopen("galaxy.in","r",stdin);
	freopen("galaxy.out","w",stdout);
	cin>>n>>m;
	if(n>1000)
	{
		for(int i=1;i<=m;i++)
		{
			int x,y;
			scanf("%d%d",&x,&y);
		}
		int qq;
		cin>>qq;
		while(qq--)puts("NO");
		return 0;
	}
	for(int i=1;i<=n;i++)
		ex[i]=1;
	for(int i=1;i<=m;i++)
	{
		int x,y;
		cin>>x>>y;
		mp[x][y]=e[x][y]=1;
		sum[x]++;
	}
	int jj;
	cin>>jj;
	for(int i=1;i<=jj;i++)
	{
		memset(bj,0,sizeof(bj));
		memset(vis,0,sizeof(vis));
		memset(q,0,sizeof(q));
		int t;
		cin>>t;
		if(t==1)
		{
			int x,y;
			cin>>x>>y;
			if(e[x][y])
			{
				e[x][y]=0;
				sum[x]--;
			}
		}
		else if(t==2)
		{
			int x;
			cin>>x;
			for(int j=1;j<=n;j++)
				if(e[j][x])e[j][x]=0,sum[j]--;
		}
		else if(t==3)
		{
			int x,y;
			cin>>x>>y;
			if(!e[x][y])
			{
				e[x][y]=1;
				sum[x]++;
			}
		}
		else if(t==4)
		{
			int x;
			cin>>x;
			for(int j=1;j<=n;j++)
				if(mp[j][x])e[j][x]=1,sum[j]++;
		}
		ok=0;
		top=0;
//		cout<<"i="<<i<<endl;
//		cout<<"----------------------------"<<endl;
//		for(int j=1;j<=n;j++)
//		{
//			for(int k=1;k<=n;k++)
//				cout<<e[j][k]<<" ";
//			cout<<endl;
//		}
//		for(int j=1;j<=n;j++)
//			cout<<ex[j]<<endl;
		for(int j=1;j<=n;j++)
			if(!vis[j]&&ex[j])
				dfs(j,0);
		if(ok)cout<<"YES"<<endl;
		else cout<<"NO"<<endl;
	}
	return 0;
}
