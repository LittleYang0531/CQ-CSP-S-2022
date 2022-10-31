#include<bits/stdc++.h>
using namespace std;
char buf[1<<23],*p1,*p2;
//#define getchar (p1==p2&&(p2=(p1=buf)+fread(buf,1,1<<21,stdin),p1==p2)?EOF:*p1++)
void read(int &x)
{
	x=0;
	char ch=getchar();
	while(ch<'0'||ch>'9')ch=getchar();
	while(ch>='0'&&ch<='9')x=(x<<3)+(x<<1)+(ch^48),ch=getchar();
}
const int N=500000;
struct Edge{
	int self,next;
	bool flag;
}edge[N+5];
int n,m,q;
int to[N+5],o;
int d[N+5];
map<pair<int,int>,int>ma;
int gcnt;
void add_edge(int x,int y)
{
	edge[++o].self=y;
	edge[o].next=to[x];
	to[x]=o;
	edge[o].flag=1;
}
inline void update(const int &x,const int &value)
{
	if(d[x]==1)--gcnt;
	d[x]+=value;
	if(d[x]==1)++gcnt;
}
int main()
{
	freopen("galaxy.in","r",stdin);
	freopen("galaxy.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	read(n),read(m);
	for(int i=1;i<=m;++i)
	{
		int x,y;
		read(x),read(y);
		add_edge(y,x);
		ma[make_pair(x,y)]=i;
		update(x,1);
	}
	read(q);
	while(q--)
	{
		int flag;
		read(flag);
		if(flag==1)
		{
			int x,y,inx;
			read(x),read(y);
			inx=ma[make_pair(x,y)];
			assert(edge[inx].flag&&edge[inx].self==x);
			edge[inx].flag=0;
			update(x,-1);
		}
		else if(flag==2)
		{
			int x;
			read(x);
			for(int i=to[x];i;i=edge[i].next)
			{
				if(edge[i].flag)
				{
					edge[i].flag=0;
					update(edge[i].self,-1);
				}
			}
		}
		else if(flag==3)
		{
			int x,y,inx;
			read(x),read(y);
			inx=ma[make_pair(x,y)];
			assert(!edge[inx].flag&&edge[inx].self==x);
			edge[inx].flag=1;
			update(x,1);
		}
		else
		{
			int x;
			read(x);
			for(int i=to[x];i;i=edge[i].next)
			{
				if(!edge[i].flag)
				{
					edge[i].flag=1;
					update(edge[i].self,1);
				}
			}
		}
		cout<<(gcnt==n?"YES\n":"NO\n");
	}
	return 0;
}
