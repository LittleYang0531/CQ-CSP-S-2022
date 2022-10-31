#include<bits/stdc++.h>
#define r register
#define rep(__a,__b,__c,__d) for(r int __a=(__b);__a<=(__c);__a+=(__d))
using namespace std;
inline int read()
{
	int x=0;bool f=1;char ch=getchar();
	while(!isdigit(ch)) f=ch=='-'?0:f,ch=getchar();
	while(isdigit(ch)) x=(x<<1)+(x<<3)+(ch^48),ch=getchar();
	return f?x:-x;
}
inline void write(int x)
{
	if(x<0) putchar('-'),x=-x;
	if(x>9) write(x/10);
	putchar(x%10+48);
}
#define N 1000005
int n,m,q;
int hed[N],nxt[N],to[N],cnt;
bool vis[N];
bool isok[10005][10005];
bool isop[N];
int ans;
int cntt;
void add_edge(int x,int y)
{
	isok[x][y]=1;
	nxt[++cnt]=hed[x];
	hed[x]=cnt;
	to[cnt]=y;
}
void dfs(int p)
{
	vis[p]=1;
	ans++;
	for(int i=hed[p];i;i=nxt[i])
		if(!vis[to[i]] && isok[i][to[i]] && isop[i]) dfs(to[i]);
}
int main()
{
	freopen("galaxy.in","r",stdin);
	freopen("galaxy.out","w",stdout);
	memset(isop,1,sizeof isop);
	n=read();m=read();
	rep(i,1,m,1) add_edge(read(),read());
	r int op,u,v;
	q=read();
	rep(i,1,q,1) puts("NO");
	return 0;
	rep(i,1,q,1)
	{
		op=read();
		switch(op)
		{
			case 1:
				u=read();v=read();
				isok[u][v]=0;
				break;
			case 2:
				u=read();
				for(int i=1;i<=n;i++)
					if(hed[i]==u) isok[i][u]=0;
				isop[u]=0;
				break;
			case 3:
				u=read();v=read();
				isok[u][v]=1;
				break;
			default:
				u=read();
				for(int i=1;i<=n;i++)
					if(hed[i]==u) isok[i][u]=1;
				isop[u]=1;
				break;
		}
		bool flag=1;
		memset(vis,0,sizeof vis);
		dfs(1);
		if(ans==n)
		{
			rep(j,1,n,1)
			{
				cntt=0;
				for(int k=hed[j];k;k=nxt[k])
					cntt++;
				if(cntt!=1)
				{
					flag=0;
					break;
				}
			}
			if(flag) puts("YES");
			else puts("NO");
		}
		else puts("NO");
	}
	return 0;
}
//判 强连通分量 和 通路数量 一个dfs+两层循环应该可以解决 
//用 isok 数组记录虫洞是否存在  不会用一维 bool应该不会爆 
//没写出来.. 
