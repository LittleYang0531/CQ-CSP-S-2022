#include<iostream>
#include<iomanip>
#include<cstring>
#include<cstdio>
#include<cmath>
#include<algorithm>
using namespace std;
int n,m,k,q,s,ans,cnt,tot;
int h[500005],rd[500005],cd[500005];
int a[5005][5005],c[5005][5005];
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
int main()
{
	freopen("galaxy.in","r",stdin);
	freopen("galaxy.out","w",stdout);
	n=read();m=read();
	if(n>5000)
	{
		for(int i=1,x,y;i<=m;i++)
			x=read(),y=read(),rd[y]++,cd[x]++;
		for(int i=1;i<=n;i++)
			if(cd[i]==1) s++;
		q=read();
		for(int i=1,x,y,opt;i<=q;i++)
		{
			opt=read();
			if(opt==1)
			{
				x=read();
				y=read();
				rd[y]--;cd[x]--;
				if(cd[x]==1) s++;
				else if(cd[x]==0) s--;
				if(s==n) putchar('Y'),putchar('E'),putchar('S'),putchar('\n');
				else putchar('N'),putchar('O'),putchar('\n');
			}
			else if(opt==3)
			{
				x=read();
				y=read();
				rd[y]++;cd[x]++;
				if(cd[x]==1) s++;
				else if(cd[x]==2) s--;
				if(s==n) putchar('Y'),putchar('E'),putchar('S'),putchar('\n');
				else putchar('N'),putchar('O'),putchar('\n');
			}
		}		
	}
	else
	{
		for(int i=1,x,y;i<=m;i++)
			x=read(),y=read(),a[x][y]=c[x][y]=1,rd[y]++,cd[x]++;
		for(int i=1;i<=n;i++)
			if(cd[i]==1) s++;
		q=read();
		for(int i=1,x,y,opt;i<=q;i++)
		{
			opt=read();
			if(opt==1)
			{
				x=read();
				y=read();
				rd[y]--;cd[x]--;
				a[x][y]=0;
				if(cd[x]==1) s++;
				else if(cd[x]==0) s--;
				if(s==n) putchar('Y'),putchar('E'),putchar('S'),putchar('\n');
				else putchar('N'),putchar('O'),putchar('\n');
			}
			else if(opt==2)
			{
				x=read();
				for(int i=1;i<=n;i++)
					if(a[i][x]) 
					{
						a[i][x]=0;
						cd[i]--,rd[x]--;
						if(cd[i]==1) s++;
						else if(cd[i]==0) s--;
					}
				if(s==n) putchar('Y'),putchar('E'),putchar('S'),putchar('\n');
				else putchar('N'),putchar('O'),putchar('\n');
			}
			else if(opt==3)
			{
				x=read();
				y=read();
				a[x][y]=1;
				rd[y]++;cd[x]++;
				if(cd[x]==1) s++;
				else if(cd[x]==2) s--;
				if(s==n) putchar('Y'),putchar('E'),putchar('S'),putchar('\n');
				else putchar('N'),putchar('O'),putchar('\n');
			}
			else if(opt==4)
			{
				x=read();
				for(int i=1;i<=n;i++)
					if(c[i][x]&&!a[i][x]) 
					{
						a[i][x]=1;
						cd[i]++,rd[x]++;
						if(cd[i]==1) s++;
						else if(cd[i]==2) s--;
					}
				if(s==n) putchar('Y'),putchar('E'),putchar('S'),putchar('\n');
				else putchar('N'),putchar('O'),putchar('\n');
			}
		}		
	}
}
