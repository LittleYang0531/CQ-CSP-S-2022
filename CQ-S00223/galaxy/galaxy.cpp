#include<map>
#include<cstdio>
using namespace std;
inline void read(int &hhh)
{
	int x=0;
	char c=getchar();
	while((c>'9'||c<'0')&&c!='-')	c=getchar();
	if(c!='-')	x=c^'0';
	char d=getchar();
	while(d>='0'&&d<='9')
	{
		x=(x<<1)+(x<<3)+(d^'0');
		d=getchar();
	}
	if(c!='-')	hhh=x;
	else	hhh=-x;
}
map<int,int> st[500010];
int n,m,u,v,q,in[500010],out[500010],OUT,ori[500010],oro[500010];
inline void del(int x,int y)
{
	st[y][x]=0;
	--in[y];
	if(out[x]==1)	--OUT;
	--out[x];
	if(out[x]==1)	++OUT;
}
inline void add(int x,int y)
{
	st[y][x]=1;
	++in[y];
	if(out[x]==1)	--OUT;
	++out[x];
	if(out[x]==1)	++OUT;
}
int head[500010],to[500010],nxt[500010],cntot;
inline void addedge(int one,int ano)
{
	nxt[++cntot]=head[one];
	to[cntot]=ano;
	head[one]=cntot;
}
int op;
int main()
{
	freopen("galaxy.in","r",stdin);
	freopen("galaxy.out","w",stdout);
	read(n);
	read(m);
	for(int i=1;i<=m;++i)
	{
		read(u);
		read(v);
		++ori[v];
		++oro[u];
		add(u,v);
		addedge(v,u);
	}
	read(q);
	for(int i=1;i<=q;++i)
	{
		read(op);
		if(op==1)
		{
			read(u);
			read(v);
			del(u,v);
		}
		else if(op==2)
		{
			read(u);
			if(in[u])
			{
				for(int j=head[u];j;j=nxt[j])
				{
					int y=to[j];
					if(st[u][y])	del(y,u);
				}
			}
		}
		else if(op==3)
		{
			read(u);
			read(v);
			add(u,v);
		}
		else
		{
			read(u);
			if(in[u]!=ori[u])
			{
				for(int j=head[u];j;j=nxt[j])
				{
					int y=to[j];
					if(!st[u][y])	add(y,u);
				}
			}
		}
		if(OUT==n)	puts("YES");
		else	puts("NO");
	}
	return 0;
}
