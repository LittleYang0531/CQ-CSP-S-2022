#include<bits/stdc++.h>

using namespace std;

const int N=1e5+5,K=20;

typedef long long LL;

int n,m,q;
LL a[N],b[N];
LL f1[N][K],f2[N][K],f3[N][K],f4[N][K],f5[N][K];
LL g1[N][K],g2[N][K],g3[N][K],g4[N][K],g5[N][K];

inline LL qmax(LL x,LL y)
{
	return x&&y?max(x,y):min(x,y);
}

inline LL qmin(LL x,LL y)
{
	return x&&y?min(x,y):max(x,y);
}

void init()
{
	for(int i=1;i<=n;i++)
		if(a[i]>0)f1[i][0]=f2[i][0]=a[i];
		else if(a[i]<0)f3[i][0]=f4[i][0]=a[i];
		else f5[i][0]=1;
	
	for(int j=1;(1<<j)<=n;j++)
		for(int i=1;i+(1<<j)-1<=n;i++)
			f1[i][j]=max(f1[i][j-1],f1[i+(1<<j-1)][j-1]);
	
	for(int j=1;(1<<j)<=n;j++)
		for(int i=1;i+(1<<j)-1<=n;i++)
			f2[i][j]=qmin(f2[i][j-1],f2[i+(1<<j-1)][j-1]);
	
	for(int j=1;(1<<j)<=n;j++)
		for(int i=1;i+(1<<j)-1<=n;i++)
			f3[i][j]=qmax(f3[i][j-1],f3[i+(1<<j-1)][j-1]);
	
	for(int j=1;(1<<j)<=n;j++)
		for(int i=1;i+(1<<j)-1<=n;i++)
			f4[i][j]=min(f4[i][j-1],f4[i+(1<<j-1)][j-1]);
	
	for(int j=1;(1<<j)<=n;j++)
		for(int i=1;i+(1<<j)-1<=n;i++)
			f5[i][j]=max(f5[i][j-1],f5[i+(1<<j-1)][j-1]);
	
	
	for(int i=1;i<=n;i++)
		if(b[i]>0)g1[i][0]=g2[i][0]=b[i];
		else if(b[i]<0)g3[i][0]=g4[i][0]=b[i];
		else g5[i][0]=1;
	
	for(int j=1;(1<<j)<=n;j++)
		for(int i=1;i+(1<<j)-1<=n;i++)
			g1[i][j]=max(g1[i][j-1],g1[i+(1<<j-1)][j-1]);
	
	for(int j=1;(1<<j)<=n;j++)
		for(int i=1;i+(1<<j)-1<=n;i++)
			g2[i][j]=qmin(g2[i][j-1],g2[i+(1<<j-1)][j-1]);
	
	for(int j=1;(1<<j)<=n;j++)
		for(int i=1;i+(1<<j)-1<=n;i++)
			g3[i][j]=qmax(g3[i][j-1],g3[i+(1<<j-1)][j-1]);
	
	for(int j=1;(1<<j)<=n;j++)
		for(int i=1;i+(1<<j)-1<=n;i++)
			g4[i][j]=min(g4[i][j-1],g4[i+(1<<j-1)][j-1]);
	
	for(int j=1;(1<<j)<=n;j++)
		for(int i=1;i+(1<<j)-1<=n;i++)
			g5[i][j]=max(g5[i][j-1],g5[i+(1<<j-1)][j-1]);
}

inline LL queryf1(int l,int r)
{
	int x=log2(r-l+1);
	return max(f1[l][x],f1[r-(1<<x)+1][x]);
}

inline LL queryf2(int l,int r)
{
	int x=log2(r-l+1);
	return qmin(f2[l][x],f2[r-(1<<x)+1][x]);
}

inline LL queryf3(int l,int r)
{
	int x=log2(r-l+1);
	return qmax(f3[l][x],f3[r-(1<<x)+1][x]);
}

inline LL queryf4(int l,int r)
{
	int x=log2(r-l+1);
	return min(f4[l][x],f4[r-(1<<x)+1][x]);
}

inline LL queryf5(int l,int r)
{
	int x=log2(r-l+1);
	return max(f5[l][x],f5[r-(1<<x)+1][x]);
}

inline LL queryg1(int l,int r)
{
	int x=log2(r-l+1);
	return max(g1[l][x],g1[r-(1<<x)+1][x]);
}

inline LL queryg2(int l,int r)
{
	int x=log2(r-l+1);
	return qmin(g2[l][x],g2[r-(1<<x)+1][x]);
}

inline LL queryg3(int l,int r)
{
	int x=log2(r-l+1);
	return qmax(g3[l][x],g3[r-(1<<x)+1][x]);
}

inline LL queryg4(int l,int r)
{
	int x=log2(r-l+1);
	return min(g4[l][x],g4[r-(1<<x)+1][x]);
}

inline LL queryg5(int l,int r)
{
	int x=log2(r-l+1);
	return max(g5[l][x],g5[r-(1<<x)+1][x]);
}

inline LL f(int l1,int r1,int l2,int r2)
{
	LL  a1=queryf1(l1,r1),
		a2=queryf2(l1,r1),
		a3=queryf3(l1,r1),
		a4=queryf4(l1,r1),
		a5=queryf5(l1,r1),
		b1=queryg1(l2,r2),
		b2=queryg2(l2,r2),
		b3=queryg3(l2,r2),
		b4=queryg4(l2,r2),
		b5=queryg5(l2,r2);
	if(a5&&b1&&b3)return 0;
	if(a1&&a3)
	{
		if(b1&&b3)return max(a2*b4,a3*b1);
		if(b5)return 0;
		if(b1)return a1*b2;
		return a4*b3;
	}
	if(a1)
	{
		if(b3)return a5?0:a2*b4;
		if(b5)return 0;
		return a1*b2;
	}
	if(a3)
	{
		if(b1)return a5?0:a3*b1;
		if(b5)return 0;
		return a4*b3;
	}
	return 0;
}

int main()
{
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	
	scanf("%d%d%d",&n,&m,&q);
	for(int i=1;i<=n;i++)scanf("%lld",&a[i]);
	for(int i=1;i<=m;i++)scanf("%lld",&b[i]);
	init();
	while(q--)
	{
		int l1,r1,l2,r2;
		scanf("%d%d%d%d",&l1,&r1,&l2,&r2);
		printf("%lld\n",f(l1,r1,l2,r2));
	}
	return 0;
}
