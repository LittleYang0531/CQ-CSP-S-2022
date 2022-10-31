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
#define N 200005
int n,q,k;
int hed[N],nxt[N],to[N],vis[N],cnt;
int x,y;
void add_edge(int x,int y)
{
	nxt[++cnt]=hed[x];
	hed[x]=cnt;
	to[cnt]=y;
	
	nxt[++cnt]=hed[y];
	hed[y]=cnt;
	to[cnt]=x;
}
int main()
{
	freopen("transmit.in","r",stdin);
	freopen("transmit.out","w",stdout);
	n=read();q=read();k=read();
	rep(i,1,n-1,1) add_edge(read(),read());
	rep(i,1,q,1) 
	{
		x=read();y=read();
		printf("%d\n",x+y);
	}
	return 0;
}


