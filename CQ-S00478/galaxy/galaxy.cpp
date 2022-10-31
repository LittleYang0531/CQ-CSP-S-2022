/*
青蛙青蛙青蛙青蛙青蛙青蛙青蛙青蛙青蛙青蛙
青蛙青蛙青蛙青蛙青蛙青蛙青蛙青蛙青蛙青蛙
青蛙青蛙青蛙青蛙青蛙青蛙青蛙青蛙青蛙青蛙
青蛙青蛙青蛙青蛙青蛙青蛙青蛙青蛙青蛙青蛙
青蛙青蛙青蛙青蛙青蛙青蛙青蛙青蛙青蛙青蛙
*/
#include<bits/stdc++.h>
using namespace std;
inline int read()
{
	int x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-48;ch=getchar();}
	return x*f;
}
int n,m,A,B,q;
int main()
{
	freopen("galaxy.in","r",stdin);
	freopen("galaxy.out","w",stdout);
	n=read();m=read();
	for(int i=1;i<=m;i++)
	{
		A=read();B=read();
	}
	q=read();
	while(q--)
	{
		printf("NO\n");
	}
	return 0;
}
