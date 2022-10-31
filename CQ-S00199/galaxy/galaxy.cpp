#include<stdio.h>
#include<set>
#include<algorithm>
int n,m,q;
int u,v;
int U[500005],V[500005];
bool del[500005];
int rt[500005];
int op;
bool f;
std::set<int> to[500005];
std::set<int> now[500005];
int sum;
int main()
{
	freopen("galaxy.in","r",stdin);
	freopen("galaxy.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++)
	{
		scanf("%d%d",&U[i],&V[i]);
	}
	scanf("%d",&q);
	if((long long)n*q+(long long)m*q<=20000000ll)
	{
		for(int i=1;i<=m;i++)
		{
			rt[U[i]]++;
		}
		while(q--)
		{
			scanf("%d",&op);
			if(op==1)
			{
				scanf("%d%d",&u,&v);
				for(int i=1;i<=m;i++)
				{
					if(U[i]==u&&V[i]==v)
					{
						del[i]=true;
						break;
					}
				}
				rt[u]--;
			}
			else if(op==2)
			{
				scanf("%d",&u);
				for(int i=1;i<=m;i++)
				{
					if(V[i]==u&&!del[i])
					{
						del[i]=true;
						rt[U[i]]--;
					}
				}
			}
			else if(op==3)
			{
				scanf("%d%d",&u,&v);
				for(int i=1;i<=m;i++)
				{
					if(U[i]==u&&V[i]==v)
					{
						del[i]=false;
						break;
					}
				}
				rt[u]++;
			}
			else
			{
				scanf("%d",&u);
				for(int i=1;i<=m;i++)
				{
					if(V[i]==u&&del[i])
					{
						del[i]=false;
						rt[U[i]]++;
					}
				}
			}
			f=true;
			for(int i=1;i<=n;i++)
			{
//				printf("%d ",rt[i]);
				if(rt[i]<1||rt[i]>1)
				{
					f=false;
					break;
				}
			}
//			printf("\n");
			printf("%s\n",f?"YES":"NO");
		}
	}
	else
	{
		for(int i=1;i<=m;i++)
		{
			rt[U[i]]++;
			to[V[i]].insert(U[i]);
			now[V[i]].insert(U[i]);
		}
		sum=0;
		for(int i=1;i<=n;i++)
		{
			if(rt[i]==1)
			{
				++sum;
			}
		}
		while(q--)
		{
			scanf("%d",&op);
			if(op==1)
			{
				scanf("%d%d",&u,&v);
				now[v].erase(now[v].lower_bound(u));
				if(rt[u]==1)
				{
					--sum;
				}
				rt[u]--;
				if(rt[u]==1)
				{
					++sum;
				}
			}
			else if(op==2)
			{
				scanf("%d",&u);
				for(int i:now[u])
				{
					if(rt[i]==1)
					{
						--sum;
					}
					rt[i]--;
					if(rt[i]==1)
					{
						++sum;
					}
				}
				now[u].clear();
			}
			else if(op==3)
			{
				scanf("%d%d",&u,&v);
				now[v].insert(u);
				if(rt[u]==1)
				{
					--sum;
				}
				rt[u]++;
				if(rt[u]==1)
				{
					++sum;
				}
			}
			else
			{
				scanf("%d",&u);
				for(int i:now[u])
				{
					if(rt[i]==1)
					{
						--sum;
					}
					rt[i]--;
					if(rt[i]==1)
					{
						++sum;
					}
				}
				for(int i:to[u])
				{
					if(rt[i]==1)
					{
						--sum;
					}
					rt[i]++;
					if(rt[i]==1)
					{
						++sum;
					}
				}
				now[u]=to[u];
			}
//			for(int i=1;i<=n;i++)
//			{
//				printf("%d ",rt[i]);
//			}
//			printf("\n");
			printf("%s\n",sum==n?"YES":"NO");
		}
	}
	return 0;
}
/*
3 6
2 3
2 1
1 2
1 3
3 1
3 2
11
1 3 2
1 2 3
1 1 3
1 1 2
3 1 3
3 3 2
2 3
1 3 1
3 1 3
4 2
1 3 2
*/
