#include<bits/stdc++.h>
using namespace std;
int n,m,q;
struct node
{
	int tar,nxt;
	bool flg;
}arr[1000005];
int fst[1000005],cnt;
void adds(int x,int y)
{
	arr[++cnt].tar=y,arr[cnt].flg=1,arr[cnt].nxt=fst[x],fst[x]=cnt;
}
stack<int> p;
bool checkit;
int cntt,dfn[1000005],low[1000005];
bool instack[1000005];
void tarjan(int x)
{
	dfn[x]=++cntt;
	low[x]=dfn[x];
	instack[x]=true;
	p.push(x);
	for(int i=fst[x];i;i=arr[i].nxt)
	{
		if(!arr[i].flg) continue;
		int j=arr[i].tar;
		if(!dfn[j])
		{
			tarjan(j);
			low[x]=min(low[x],low[j]);
		}
		else if(instack[j])
		{
			low[x]=min(low[x],dfn[j]);
		}
	}
	if(low[x]==dfn[x])
	{
		int len=0;
		while(!p.empty())
		{
			len++;
			if(p.top()==x) break;
			p.pop();
		}
		if(len==1) checkit=0;
	}
}
bool check()
{
	for(int i=1;i<=n;++i)
	{
		int flg=0;
		for(int j=fst[i];j;j=arr[j].nxt)
		{
			if(!arr[j].flg) continue;
			flg++;
			if(flg>1) return false;
		}
		if(!flg) return false;
	}
	while(!p.empty()) p.pop();
	checkit=1;
	for(int i=1;i<=n;++i)	dfn[i]=0;
	cntt=0;
	for(int i=1;i<=n;++i)
	{
		if(!dfn[i])
		tarjan(i);
		if(!checkit) return checkit;
	}
//	cout<<"ok"<<" "<<checkit<<endl;
	return checkit;
}
int main()
{
	freopen("galaxy.in","r",stdin);
	freopen("galaxy.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;++i)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		adds(x,y);
	}
	scanf("%d",&q);
	while(q--)
	{
		int op,u,v;
		scanf("%d%d",&op,&u);
		if(op==1)
		{
			scanf("%d",&v);
			for(int i=fst[u];i;i=arr[i].nxt)
			{
				if(arr[i].tar==v)
				{
					arr[i].flg=0;
					break;
				}
			}
		}
		else if(op==2)
		{
			for(int i=1;i<=n;++i)
			{
				for(int j=fst[i];j;j=arr[j].nxt)
				{
					if(arr[j].tar==u)
					arr[j].flg=0;
				}
			}
		}
		else if(op==3)
		{
			scanf("%d",&v);
			for(int i=fst[u];i;i=arr[i].nxt)
			{
				if(arr[i].tar==v)
				{
					arr[i].flg=1;
					break;
				}
			}
		}
		else
		{
			for(int i=1;i<=n;++i)
			{
				for(int j=fst[i];j;j=arr[j].nxt)
				{
					if(arr[j].tar==u)
					arr[j].flg=1;
				}
			}
		}
		if(check()) puts("YES");
		else puts("NO");
	}
	return 0;
}

