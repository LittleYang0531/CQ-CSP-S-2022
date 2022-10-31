#include<bits/stdc++.h>
#define rr register
#define MYMIN (-1LL<<63LL)
#define MYMAX ((1LL<<63LL)-1LL)
#define int long long
#define rep(__a,__b,__c,__d) for(rr int __a=(__b);__a<=(__c);__a+=(__d))
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
int n,m,q,a[100005],b[100005];
int c[5005][5005];
int ans,ans1;
struct NoDe
{
	int lx,rx,ly,ry;
}p[100005];
signed main()
{
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	n=read();m=read();q=read();
	rep(i,1,n,1) a[i]=read();
	rep(i,1,m,1) b[i]=read();
	rep(i,1,n,1) rep(j,1,m,1) c[i][j]=a[i]*b[j];
	rep(k,1,q,1)
	{
		p[k].lx=read();
		p[k].ly=read();
		p[k].rx=read();
		p[k].ry=read();
		ans1=MYMIN;
		rep(i,p[k].lx,p[k].ly,1)
		{
			ans=MYMAX;
			rep(j,p[k].rx,p[k].ry,1)
				ans=c[i][j]<ans?c[i][j]:ans;
			ans1=ans>ans1?ans:ans1;
		}
		write(ans1);putchar('\n');
	}
	return 0;
}


