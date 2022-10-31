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
#define N 20005
int n,m,k;
int hed[N],nxt[N],to[N],w[N],vis[N],cnt;
bool addeds[5005][5005];
void add_edge(int x,int y)
{
	addeds[x][y]=addeds[y][x]=1;
	nxt[++cnt]=hed[x];
	hed[x]=cnt;
	to[cnt]=y;
	
	nxt[++cnt]=hed[y];
	hed[y]=cnt;
	to[cnt]=x;
}
void add_edge2(int x,int y)
{
	addeds[x][y]=1;
	nxt[++cnt]=hed[x];
	hed[x]=cnt;
	to[cnt]=y;
}
int ans;
void dfs(int p,int sum,int dep)
{
	if(dep==5)
	{
		if(p==1)
			ans=sum>ans?sum:ans;
		return;
	}
	vis[p]=1;
	for(int i=hed[p];i;i=nxt[i])
	{
		if(!vis[to[i]] || (p==4&&to[i]==1)) dfs(to[i],sum+w[p],dep+1),vis[to[i]]=0;
	}
}
void init(int p,int dep,int st)
{
	vis[p]=1;
	if(dep>0 && dep<=k && !addeds[p][st]) add_edge2(p,st);
	for(int i=hed[p];i;i=nxt[i])
		if(!vis[to[i]]) init(to[i],dep+1,st);
}
int main()
{
	freopen("holiday.in","r",stdin);
	freopen("holiday.out","w",stdout);
	n=read();m=read();k=read();
	rep(i,2,n,1) w[i]=read();
	rep(i,1,m,1) add_edge(read(),read());
	for(int i=1;i<=n;i++)
		init(i,-1,i),memset(vis,0,sizeof vis);
	dfs(1,0,0);
	write(ans);
	return 0;
}
