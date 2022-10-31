//sto hasinon orz bless me AC
#include<bits/stdc++.h>
using namespace std;
int n,m,q,u,v,op,sz;
int f[1005];
bool fl;
bitset<1005> a[1005],b[1005],vis;
inline int read()
{
	int x(0);char ch(getchar());
	while(ch<48||ch>57) ch=getchar();
	while(ch>=48&&ch<=57) x=x*10+(ch^48),ch=getchar();
	return x;
}
bool dfs(int x)
{
	vis[x]=1;
	if(~f[x]) return f[x];
	for(int i=1;i<=n;i++)
		if(a[x][i]&&(vis[i]||dfs(i))) return f[x]=1;
	return f[x]=0;
}
int main()
{
	freopen("galaxy.in","r",stdin);
	freopen("galaxy.out","w",stdout);
	n=read(),m=read();
	for(int i=1;i<=m;i++)
	{
		u=read(),v=read();
		a[u][v]=b[u][v]=1;
	}
	q=read();
	while(q--)
	{
		op=read();
		switch(op)
		{
			case 1:{
				u=read(),v=read();
				a[u][v]=0;
				break;
			}
			case 2:{
				u=read();
				for(int i=1;i<=n;i++)
					if(b[i][u]) a[i][u]=0;
				break;
			}
			case 3:{
				u=read(),v=read();
				a[u][v]=1;
				break;
			}
			case 4:{
				u=read();
				for(int i=1;i<=n;i++) 
					if(b[i][u]) a[i][u]=1;
				break;
			}
		}
		memset(f,-1,sizeof(f));
		vis.reset();fl=0;
		for(int i=1;i<=n;i++)
		{
			sz=a[i].count();
			if(sz!=1||!dfs(i)) {fl=1;break;}
		}
		if(fl) puts("NO");
		else puts("YES");
	}
	return 0;
}

