#include<iostream>
#include<iomanip>
#include<cstring>
#include<cstdio>
#include<cmath>
#include<algorithm>
using namespace std;
int n,m,k,cnt,cnt2,tot;
long long c[2005],mx[2005][3],s,ans;
int h[2005],h2[2005],d[2005],f[2005][2005];
int w[2005],bj[2005],id[2005][3];
struct xin{
	int next,to;
}a[20005],mp[20000005];
inline void xing(int x,int y)
{
	++cnt;
	a[cnt].next=h[x];
	a[cnt].to=y;
	h[x]=cnt;
}
inline void xing2(int x,int y)
{
	++cnt2;
	mp[cnt2].next=h2[x];
	mp[cnt2].to=y;
	h2[x]=cnt2;
}
inline int read()
{
	int s=0;
	char ch=getchar();
	while(ch<'0'||ch>'9') ch=getchar();
	while(ch>='0'&&ch<='9') s=(s<<3)+(s<<1)+(ch^48),ch=getchar();
	return s;
}
inline void putch(int u)
{
	if(u<0) putchar('-'),u=-u;
	int s=0;
	char ch[20];
	while(u)
	{
		ch[++s]=(u%10)^48;
		u/=10;
	}
	if(!s) ch[++s]=48;
	for(int i=s;i;i--)
		putchar(ch[i]);
	putchar('\n');
}
inline void bfs(int u)
{
	int l,r;
	d[l=r=1]=u;
	w[u]=0;
	bj[u]=1;
	while(l<=r)
	{
		int x=d[l++];
//		printf("%d\n",x);
		for(int i=h[x];i;i=a[i].next)
		{
			int y=a[i].to;
			if(bj[y]) continue;
			bj[y]=1;
			w[y]=w[x]+1;
//			if(x==y) while(1);
			xing2(u,y);
			f[u][y]=1;
			if(w[y]<=k) d[++r]=y;
		}
		
	}
	for(int i=1;i<=n;i++)
		bj[i]=0;
}
int main()
{
	freopen("holiday.in","r",stdin);
	freopen("holiday.out","w",stdout);
	n=read(); m=read(); k=read();
	for(int i=2;i<=n;i++) 
		scanf("%lld",&c[i]);
	for(int i=1,x,y;i<=m;i++)
		x=read(),y=read(),xing(x,y),xing(y,x);
	for(int i=1;i<=n;i++)
		bfs(i);
//	puts("1");
//	printf("%d\n",cnt2);
	for(int u=2;u<=n;u++)
	{
		for(int i=h2[u];i;i=mp[i].next)
		{
			int y=mp[i].to;
//			printf("%d %d %d\n",i,mp[i].next,y);
			if(y==1||!f[1][y]) continue;
			if(mx[u][0]<c[y])
				mx[u][2]=mx[u][1],mx[u][1]=mx[u][0],mx[u][0]=c[y],
				id[u][2]=id[u][1],id[u][1]=id[u][0],id[u][0]=y;
			else if(mx[u][1]<c[y])
				mx[u][2]=mx[u][1],mx[u][1]=c[y],
				id[u][2]=id[u][1],id[u][1]=y;
			else if(mx[u][2]<c[y])
				mx[u][2]=c[y],id[u][2]=y;
		}
//		printf("%d\n%d %lld\n%d %lld \n%d %lld\n",u,id[u][0],mx[u][0],id[u][1],mx[u][1],id[u][2],mx[u][2]);
	}
	for(int i=2;i<=n;i++)
	for(int j=h2[i];j;j=mp[j].next)
	{
		int y=mp[j].to;
		if(y<i) continue;
		if(y==1) continue;
		if((!id[i][0])||(!id[y][0])) continue;
		s=c[i]+c[y];
		int k1=0,k2=0;
		if(id[i][0]==y) k1++;
		if(id[y][0]==i) k2++;
		if((!id[i][k1])||(!id[y][k2])) continue;
		if(id[i][k1]!=id[y][k2]) s+=mx[i][k1]+mx[y][k2];
		else
		{
			s+=mx[i][k1];
			k1++;k2++;
			if(id[i][k1]==y) k1++;
			if(id[y][k2]==i) k2++;
			if(id[i][k1]==0&&id[y][k2]==0) 
			{
				s=0;
				continue;
			}
			if(id[i][k1]==0) s+=mx[y][k2];
			else if(id[y][k2]==0) s+=mx[i][k1];
			else s+=max(mx[i][k1],mx[y][k2]);
		}
//		printf("%d %d %lld\n",i,y,s);
		ans=max(ans,s);
	}
	printf("%lld\n",ans);
}
