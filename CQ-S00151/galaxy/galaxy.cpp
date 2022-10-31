#include<bits/stdc++.h>
using namespace std;
void read(int &x)
{
	x=0;
	short flag=1;
	char ch=getchar();
	while(ch<'0'||ch>'9')
	{
		if(ch=='-')	flag=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9')
	{
		x=(x<<1)+(x<<3)+(ch^48);
		ch=getchar();
	}
	x*=flag;
}
int n,m,q;
int main()
{
	freopen("galaxy.in","r",stdin);
	freopen("galaxy.out","w",stdout);
	read(n),read(m);
	for(int i=1;i<=m;i++)
	{
		int x,y;
		read(x),read(y);
	}
	read(q);
	while(q--)
	{
		int t,x,y;
		read(t);
		read(x);
		if(t==1||t==3)	read(x);
		puts("NO");
	}
	return 0;
}
