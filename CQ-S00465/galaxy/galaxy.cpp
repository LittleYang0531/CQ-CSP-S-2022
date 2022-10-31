/*
T3:基环树
给一个图
删一条边
恢复一条边
删一个点的所有入边
恢复一个点的所有入边

一条边只有2种状态

暴力操作，询问 O(1) 判断是否为基环树森林，40分
10分不删点，可做吗 


快速维护一个点的出入度，可做吗 
50分：暴力维护
可能有更多这样的分 
*/
#include <bits/stdc++.h>

using namespace std;
const int MAXN=1e6+50;

int In[MAXN],Out[MAXN];
struct Edge
{
	int x,y,Next;
}e[MAXN<<1];
int elast[MAXN],tot;
void Add(int x,int y)
{
	tot++;
	e[tot].x=x;
	e[tot].y=y;
	e[tot].Next=elast[x];
	elast[x]=tot;
}
int N,M,Q;

map<int,int>Mp[MAXN];
bool Cut[MAXN];

set<int>S;

int main()
{
	freopen("galaxy.in","r",stdin);
	freopen("galaxy.out","w",stdout);
	scanf("%d%d",&N,&M);
	for(int i=1;i<=M;i++)
	{
		int x,y;
		scanf("%d%d",&x,&y);//x->y
		Out[x]++;
		In[y]++;
		Add(y,x);Mp[x][y]=tot;
	}
	for(int i=1;i<=N;i++)
	{
		if(Out[i]!=1)
		{
			S.insert(i);
		}
	}
	scanf("%d",&Q);
	while(Q--)
	{
		int op,u,v;
		scanf("%d",&op);
		if(op==1)
		{
			scanf("%d%d",&u,&v);
			Cut[Mp[u][v]]=true;
			Out[u]--;
			In[v]--;
			if(Out[u]==1)
			S.erase(u);
			else
			S.insert(u);
		}
		if(op==2)//把一个点的入度删完了，不可能有戏 
		{
			scanf("%d",&u);
		//	S.insert(u);
			for(int i=elast[u];i;i=e[i].Next)
			{
				v=e[i].y;
				if(Cut[i]==false)
				{
					Cut[i]=true;
					Out[v]--;
					if(Out[v]==1)
					S.erase(v);
					else
					S.insert(v);
					In[u]--;
				}
			}
		}
		if(op==3)
		{
			scanf("%d%d",&u,&v);
			Cut[Mp[u][v]]=false;
			Out[u]++;
			In[v]++;
			if(Out[u]==1)
			S.erase(u);
			else
			S.insert(u);
		}
		if(op==4)
		{
			scanf("%d",&u);
			for(int i=elast[u];i;i=e[i].Next)
			{
				v=e[i].y;
				if(Cut[i]==true)
				{
					Cut[i]=false;
					Out[v]++;
					if(Out[v]==1)
					S.erase(v);
					else
					S.insert(v);
					In[u]++;
				}
			}
			
		}
		if(S.size()==0)
		{
			puts("YES");
		}
		else
		{
			puts("NO");
		}
//		cout<<S.size()<<endl;
//		cout<<Q<<endl;
//		for(int i=1;i<=N;i++)
//		cout<<i<<" "<<In[i]<<" "<<Out[i]<<endl; 
	}
	return 0;
}

