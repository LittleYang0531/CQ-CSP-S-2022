#include<bits/stdc++.h>
using namespace std;
const int MAXN=1e5+5; 
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
int a[MAXN],b[MAXN];
int Max1[MAXN][20],Min1[MAXN][20],Max2[MAXN][20],Min2[MAXN][20];
int lg[MAXN];
int sum[MAXN][2],num[MAXN][2];
void ST()
{
	for(int i=1;i<=n;i++)
	{
		for(int j=0;j<=20;j++)	Max1[i][j]=-1e9,Min1[i][j]=1e9;
	}
	for(int i=1;i<=m;i++)
	{
		for(int j=0;j<=20;j++)	Max2[i][j]=-1e9,Min2[i][j]=1e9;
	}
	for(int i=1;i<=n;i++)	Max1[i][0]=Min1[i][0]=a[i],Max2[i][0]=Min2[i][0]=b[i];
	int k=lg[n];
	for(int j=1;j<=k;j++)
	{
		for(int i=1;i<=n;i++)
		{
			Max1[i][j]=max(Max1[i][j],max(Max1[i][j-1],Max1[i+(1<<j-1)][j-1]));
			Min1[i][j]=min(Min1[i][j],min(Min1[i][j-1],Min1[i+(1<<j-1)][j-1]));
		}
	}
	k=lg[m];
	for(int j=1;j<=k;j++)
	{
		for(int i=1;i<=m;i++)
		{
			Max2[i][j]=max(Max2[i][j],max(Max2[i][j-1],Max2[i+(1<<j-1)][j-1]));
			Min2[i][j]=min(Min2[i][j],min(Min2[i][j-1],Min2[i+(1<<j-1)][j-1]));
		}
	}
}
int query1(int l,int r,int flag)
{
	int k=lg[r-l+1];
	if(!flag)	return max(Max1[l][k],Max1[r-(1<<k)+1][k]);
	else	return max(Max2[l][k],Max2[r-(1<<k)+1][k]);
}
int query2(int l,int r,int flag)
{
	int k=lg[r-l+1];
	if(!flag)	return min(Min1[l][k],Min1[r-(1<<k)+1][k]);
	else	return min(Min2[l][k],Min2[r-(1<<k)+1][k]);
}
set<long long> st;
int main()
{
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	read(n),read(m),read(q);
	for(int i=1;i<=n;i++)	read(a[i]),sum[i][0]=sum[i-1][0]+(!a[i]),num[i][0]=num[i-1][0]+(a[i]<0);
	for(int i=1;i<=m;i++)	read(b[i]),sum[i][1]=sum[i-1][1]+(!b[i]),num[i][1]=num[i-1][1]+(b[i]<0);
	lg[2]=1;
	for(int i=3;i<=max(n,m)+1;i++)	lg[i]=lg[i>>1]+1;
	ST();
	while(q--)
	{
		int l1,r1,l2,r2;
		read(l1),read(r1),read(l2),read(r2);
		if(l1==r1)
		{
			if(l2==r2)	printf("%lld\n",1ll*a[l1]*b[l2]);
			else
			{
				if(a[l1]>0)	printf("%lld\n",1ll*a[l1]*query2(l2,r2,1));
				else if(a[l1]==0)	puts("0");
				else	printf("%lld\n",1ll*a[l1]*query1(l2,r2,1));
			}
		}
		else if(l2==r2)
		{
			if(b[l2]>0)	printf("%lld\n",1ll*b[l2]*query1(l1,r1,0));
			else if(b[l2]=0)	puts("0");
			else	printf("%lld\n",1ll*b[l2]*query2(l1,r1,0));
		}
		else
		{
			if(num[l1-1][0]==num[r1][0]&&num[l2-1][1]==num[r2][1]&&sum[l1-1][0]==sum[r1][0]&&sum[l2-1][1]==sum[r2][1])	printf("%lld\n",1ll*query1(l1,r1,0)*(query2(l2,r2,1)));
			else if(num[r2][1]-num[l2-1][1]==r2-l2+1)
			{
				int X=query2(l1,r1,0);
				if(X<0)	printf("%lld\n",1ll*X*query1(l2,r2,1));
				else	printf("%lld\n",1ll*X*query2(l2,r2,1));
			}
			else if(num[l2-1][1]!=num[r2][1]&&sum[l1-1][0]!=sum[r1][0])	puts("0");
			else if(r1-l1+1-(sum[r1][0]-sum[l1-1][0])-(num[r1][0]-num[l1-1][0])>0&&sum[l2-1][1]!=sum[r2][1])	puts("0");
			else
			{
				st.clear();
				for(int i=l1;i<=r1;i++)
				{
					for(int j=l2;j<=r2;j++)	st.insert(a[i]*b[j]);
				}
				int X=st.size();
				if(X&1)	X=X/2+1;
				else	X/=2;
				for(set<long long>::iterator it=st.begin();it!=st.end();it++)
				{
					X--;
					if(!X)
					{
						printf("%lld\n",*it);
						break;
					}
				}
			}
		}
	}
	return 0;
}
