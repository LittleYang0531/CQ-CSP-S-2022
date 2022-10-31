#include<bits/stdc++.h>
#define rd read()
using namespace std;
int n,m,q,u,v,t,enm;
int flag=0,vis[100];
struct Edge{
	int to,next;
}edge[100];
int head[100];
void addedge(int from,int to)
	{
		enm++;
		edge[enm].to=to;
		edge[enm].next=head[from];
		head[from]=enm;
	}
void dfs(int p)
	{
		if (vis[p]==1)
			{
				flag==-1;
			}
		int cdu=0;
		if (flag==0)
			{
				for (int i=head[p];i;i=edge[i].next)
					{
						if (edge[i].to<=0) continue;
						if (cdu==0)
							cdu=edge[i].to;
						else
							{
								flag=1;
								return;
							}
					}
				vis[p]=1;
				dfs(cdu);
				vis[p]=0;
			}
		return;
	}
int read()
	{
		int x=0,f=1;
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
int main()
	{
		/*
		ÈÉÐçÖ®Çï£¬ÆßÔÂ¼ÈÍû£¬ 
		*/ 
		freopen("galaxy.in","r",stdin);
		freopen("galaxy.out","w",stdout);
		n=rd;m=rd;
		for (int i=1;i<=m;i++)
			{
				u=rd,v=rd;
				addedge(u,v);
			}
		q=rd;
		for (int i=1;i<=q;i++)
			{
				flag=false;
				memset(vis,false,sizeof(vis));
				t=rd;u=rd;
				if (t==1)
					{
						v=rd;
						for (int i=head[u];i;i=edge[i].next)
							if (edge[i].to==v)
								{
									edge[i].to*=-1;
									break;
								}
					}
				if (t==2)
					{
						for (int i=1;i<=enm;i++)
							{
								if (edge[i].to==u)
									edge[i].to*=-1;
							}
					}
				if (t==3)
					{
						v=rd;
						for (int i=head[u];i;i=edge[i].next)
							if (edge[i].to==v*-1)
								{
									edge[i].to*=-1;
									break;
								}
					}
				if (t==4)
					{
						for (int i=1;i<=enm;i++)
							{
								if (edge[i].to==u*-1)
									edge[i].to*=-1;
							}
					}
				dfs(1);
				if (flag==1 or flag==0) printf("NO\n");
				else if (flag==-1) printf("YES\n");
			}
	}

