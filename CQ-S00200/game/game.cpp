/*
wonwon~ wonderhoy!
Wonderhoy!
*/
#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const LL inf=1e10;
LL read()
{
	LL x=0,f=1;
	char c=getchar();
	while(!isdigit(c))	f=(c=='-'?-1:f),c=getchar();
	while(isdigit(c))	x=(x<<1)+(x<<3)+(c^'0'),c=getchar();
	return x*f;
}
void write(LL x)
{
	if(x<0)	putchar('-'),x=-x;
	if(x>9)	write(x/10);
	putchar(x%10+'0');
}
LL lgs[100005];
struct ST{
	LL n;
	LL a[100005];
	void scan(LL N)
	{
		n=N;
		for(LL i=1;i<=n;++i)	a[i]=read();
	}
	LL mx[18][100005],mn[18][100005];
	LL bl[18][100005],ab[18][100005];
	void build()
	{
		for(LL i=1;i<=n;++i)	mx[0][i]=mn[0][i]=a[i];
		for(LL i=1;i<=n;++i)
		{
			if(a[i]==0)	bl[0][i]=ab[0][i]=0;
			else if(a[i]>0)	ab[0][i]=a[i],bl[0][i]=-inf;
			else	ab[0][i]=inf,bl[0][i]=a[i];
		}
		for(LL i=1;i<=17;++i)
		{
			for(LL j=1;j+(1<<i)-1<=n;++j)
			{
				mx[i][j]=max(mx[i-1][j],mx[i-1][j+(1<<(i-1))]);
				bl[i][j]=max(bl[i-1][j],bl[i-1][j+(1<<(i-1))]);
				mn[i][j]=min(mn[i-1][j],mn[i-1][j+(1<<(i-1))]);
				ab[i][j]=min(ab[i-1][j],ab[i-1][j+(1<<(i-1))]);
			}
		}
	}
	inline LL operator () (LL l,LL r,LL id) const
	{
		LL d=lgs[r-l+1];
		if(id&1)
		{
			if(id==1)	return max(mx[d][l],mx[d][r-(1<<d)+1]);
			return max(bl[d][l],bl[d][r-(1<<d)+1]);
		}
		else
		{
			if(id==2)	return min(mn[d][l],mn[d][r-(1<<d)+1]);
			return min(ab[d][l],ab[d][r-(1<<d)+1]);
		}
	}
}A,B;
LL n,m,q;
int main(){
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	n=read(),m=read(),q=read();
	for(LL i=2;i<=100000;++i)	lgs[i]=lgs[i>>1]+1;
	A.scan(n);
	B.scan(m);
//	for(int i=547;i<=693;++i)	printf("%lld ",A.a[i]);puts("");
//	for(int i=576;i<=976;++i)	printf("%lld ",B.a[i]);puts("");
	A.build(),B.build();
	while(q-->0)
	{
		LL l1=read(),r1=read(),l2=read(),r2=read();
		LL maxn=B(l2,r2,1),minn=B(l2,r2,2);
		if(maxn>0 && minn<0)
		{
			LL bel=A(l1,r1,3),abo=A(l1,r1,4);
			if(abo==inf)	write(bel*maxn);
			else if(bel==-inf)	write(abo*minn);
			else	write(max(min(bel*maxn,bel*minn),min(abo*minn,abo*maxn)));
			puts("");
		}
		else
		{
			if(minn>=0)
			{
				LL c=A(l1,r1,1);
				if(c<=0)	write(c*maxn),puts("");
				else	write(c*minn),puts("");
			}
			else
			{
				LL c=A(l1,r1,2);
				if(c>=0)	write(c*minn),puts("");
				else	write(c*maxn),puts("");
			}
		}
	}
	return 0;
}
