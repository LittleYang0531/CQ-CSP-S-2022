#include<bits/stdc++.h> 
using namespace std;
#define rt register 
int n,m,a[100010],b[100010],l1,r1,l2,r2,dp1[100010][30],dp2[100010][30],q,dp3[100010][30],dp4[100010][30];
inline int read()
{
	int platinum=0,lucadio=1;
	char ch=getchar();
	while(ch<'0'||ch>'9')
	{
		if(ch=='-') lucadio=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9')
	{
		platinum=(platinum<<1)+(platinum<<3)+(ch^48);
		ch=getchar();
	}
	return platinum*lucadio;
}
inline int ST1(int l,int r) //a最大 
{
	int k=log2(r-l+1);
	return max(dp1[l][k],dp1[r-(1<<k)+1][k]);
}
inline int ST2(int l,int r) //b最小 
{
	int k=log2(r-l+1);
	return min(dp2[l][k],dp2[r-(1<<k)+1][k]);
}
inline int ST3(int l,int r) //b最大 
{
	int k=log2(r-l+1);
	return max(dp3[l][k],dp3[r-(1<<k)+1][k]);
}
inline int ST4(int l,int r) //a最小 
{
	int k=log2(r-l+1);
	return min(dp4[l][k],dp4[r-(1<<k)+1][k]);
}
int main()
{
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	n=read(),m=read(),q=read();
	memset(dp2,0x3f3f3f3f,sizeof(dp2));
	memset(dp4,0x3f3f3f3f,sizeof(dp4));
	for(rt int i=1;i<=n;i++)
	{
		a[i]=read();
		dp4[i][0]=a[i];
		dp1[i][0]=a[i];
	}
	for(rt int i=1;i<=m;i++)
	{
		b[i]=read();
		dp3[i][0]=b[i];
		dp2[i][0]=b[i];
	}
	for(rt int i=1;(1<<i)<=n;i++)
	{
		for(rt int j=1;j+(1<<i)-1<=n;j++)
		{
			dp1[j][i]=max(dp1[j][i-1],dp1[j+(1<<(i-1))][i-1]);
		}
	}
	for(rt int i=1;(1<<i)<=n;i++)
	{
		for(rt int j=1;j+(1<<i)-1<=n;j++)
		{
			dp4[j][i]=min(dp4[j][i-1],dp4[j+(1<<(i-1))][i-1]);
		}
	}
	for(rt int i=1;(1<<i)<=m;i++)
	{
		for(rt int j=1;j+(1<<i)-1<=m;j++)
		{
			dp2[j][i]=min(dp2[j][i-1],dp2[j+(1<<(i-1))][i-1]);
		}
	}
	for(rt int i=1;(1<<i)<=m;i++)
	{
		for(rt int j=1;j+(1<<i)-1<=m;j++)
		{
			dp3[j][i]=max(dp3[j][i-1],dp3[j+(1<<(i-1))][i-1]);
		}
	}
	for(rt int i=1;i<=q;i++)
	{
		l1=read(),r1=read(),l2=read(),r2=read();
		if(l1==r1) //左只能选一个，右最小 
		{
			int mn=ST2(l2,r2),mx=ST3(l2,r2);
			if(a[l1]==0)
			{
				printf("0\n");
				continue;
			}
			else if(a[l1]>0) //为正选最小 
			{
				printf("%lld\n",(long long)a[l1]*mn);
				continue;
			}
			else
			{
				printf("%lld\n",(long long)a[l1]*mx);
				continue;
			}
		}
		if(l2==r2)//右一样，左最大。
		{
			int mn=ST4(l1,r1),mx=ST1(l1,r1);
			if(b[l2]==0)
			{
				printf("0\n");
				continue;
			}
			else if(b[l2]>0) //为正选最大 
			{
				printf("%lld\n",(long long)b[l2]*mx);
				continue;
			}
			else
			{
				printf("%lld\n",(long long)b[l2]*mn);
				continue;
			}
		} 
		printf("%lld\n",(long long)ST1(l1,r1)*ST2(l2,r2));
	}
	fclose(stdin);
	fclose(stdout);
}
