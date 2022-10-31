#include<bits/stdc++.h>
using namespace std;
int read()
{
	char ch;
	int t = 0,op = 1;
	ch = getchar();
	while(ch!='-'&&(ch>'9'||ch<'0'))
		ch = getchar();
	if(ch=='-')
		op = -1,ch = getchar();
	while(ch<='9'&&ch>='0')
		t = (t<<1)+(t<<3)+ch-48,ch = getchar();
	return t*op;
}
const int N = 5*1e5+5;
int n,m,q,hed[N],nxt[N],to[N],lj[N],cnt;
bool vis[N],v[N],vis1[N];
void add(int x,int y)
{
	cnt++;
	nxt[cnt] = hed[x];
	to[cnt] = y;
	hed[x] = cnt;
	vis1[x] = 1;
	lj[x]++;
}
bool v1;
int jyh[N];
bool ok1(int x)
{
	v[x] = 1;
	if(jyh[x]>=0)
		return jyh[x];
	if(v1||vis1[x]==0)
		return jyh[x] = 1;
	bool s = 1,ss = 0;
	for(int i = hed[x];i;i = nxt[i])
		if(vis[i]==0)
		{
			int y = to[i];
			ss = 1;
			if(v[y]==1||v1||jyh[y]==1)
				return jyh[x] = 1;
			s = ok1(y);
			if(s==0)
				return jyh[x] = 0;
		}
	return jyh[x] = (s&&ss);
}
bool ok2()
{
	for(int i = 1;i<=n;i++)
		if(lj[i]!=1&&vis1[i])
			return 0;
	return 1;
}
int main()
{
	freopen("galaxy.in","r",stdin);
	freopen("galaxy.out","w",stdout);
	n = read(),m = read();
	for(int i = 1;i<=m;++i)
	{
		int x = read(),y = read();
		add(x,y);
	}
	q = read();
	for(int i = 1;i<=q;++i)
	{
		int op = read(),p = read(),q1;
		if(op==1||op==3)
		{
			q1 = read();
			for(int i = hed[p];i;i = nxt[i])
				if(to[i]==q1)
				{
					if(op==1)
						vis[i] = 1;
					else vis[i] = 0;
					break;
				}
		}
		else
			for(int i = hed[p];i;i = nxt[i])
				if(op==2)
					vis[i] = 1;
				else vis[i] = 0,lj[p]++;
		if(op==1) lj[p]--;
		else if(op==2)
			lj[p] = 0,vis1[p] = 0;
		else if(op==3) lj[p]++;
		else vis1[p] = 1;
		if(ok2()==0)
		{
			printf("NO\n");
			continue;
		}
		memset(jyh,-1,sizeof jyh);
		for(int i = 1;i<=n;i++)
		{
			memset(v,0,sizeof v);
			v1 = 0;
			if(ok1(i)==0)
				goto nxt;
		}
		printf("YES\n");
		continue;
		nxt:;
		printf("NO\n");
	}
	return 0;
}

