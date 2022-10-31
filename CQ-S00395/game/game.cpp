//sto hualian orz bless me AC 
#include<bits/stdc++.h>
#define inf 1000000005
using namespace std;
int n,m,q,la,lb,ra,rb,zm,ami,bmi,fm,ama,bma,g;
bool az,af,bz,bf;
long long ans;
int a[100005],b[100005],lg[100005],stama[18][100005],stbma[18][100005],stami[18][100005],stbmi[18][100005],ta[18][100005],tb[18][100005];
inline int read()
{
	int x(0),xx(1);char ch(getchar());
	while(ch<48||ch>57) {if(ch=='-') xx=-1;ch=getchar();}
	while(ch>=48&&ch<=57) x=x*10+(ch^48),ch=getchar();
	return x*xx;
}
int st[21],ct;
inline void pr(long long x)
{
	if(x<0) putchar('-'),x=-x;
	do st[++ct]=x%10,x/=10;while(x);
	while(ct) putchar(st[ct--]^48);
	putchar('\n');
}
int main()
{
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	n=read(),m=read(),q=read();
	for(int i=1;i<=n;i++) 
	{
		stama[0][i]=stami[0][i]=a[i]=read();
		if(a[i]<0) ta[0][i]=inf;
		else ta[0][i]=a[i];
		if(a[i]>0) tb[0][i]=-inf;
		else tb[0][i]=a[i];
	}
	for(int i=1;i<=m;i++) stbma[0][i]=stbmi[0][i]=b[i]=read();
	lg[1]=0;for(int i=2;i<=100000;i++) lg[i]=lg[i>>1]+1;
	for(int i=1;i<=17;i++)
		for(int j=1;j+(1<<i)-1<=n;j++)
			stama[i][j]=max(stama[i-1][j],stama[i-1][j+(1<<i-1)]),
			tb[i][j]=max(tb[i-1][j],tb[i-1][j+(1<<i-1)]),
			stami[i][j]=min(stami[i-1][j],stami[i-1][j+(1<<i-1)]),
			ta[i][j]=min(ta[i-1][j],ta[i-1][j+(1<<i-1)]);
	for(int i=1;i<=17;i++)
		for(int j=1;j+(1<<i)-1<=m;j++)
			stbma[i][j]=max(stbma[i-1][j],stbma[i-1][j+(1<<i-1)]),
			stbmi[i][j]=min(stbmi[i-1][j],stbmi[i-1][j+(1<<i-1)]);
	
	while(q--)
	{
		la=read(),ra=read(),lb=read(),rb=read();
		zm=ami=bmi=inf,fm=ama=bma=-inf,az=af=bz=bf=0;
		g=lg[ra-la+1];
		ama=max(stama[g][la],stama[g][ra-(1<<g)+1]);
		ami=min(stami[g][la],stami[g][ra-(1<<g)+1]);
		zm=min(ta[g][la],ta[g][ra-(1<<g)+1]);
		fm=max(tb[g][la],tb[g][ra-(1<<g)+1]);
		g=lg[rb-lb+1];
		bma=max(stbma[g][lb],stbma[g][rb-(1<<g)+1]);
		bmi=min(stbmi[g][lb],stbmi[g][rb-(1<<g)+1]);
		if(ama>=0) az=1;
		if(ami<=0) af=1;
		if(bma>=0) bz=1;
		if(bmi<=0) bf=1;		
		if(az&&!af&&!bz&&bf||az&&!af&&bz&&bf) ans=1ll*ami*bmi;
		if(!az&&af&&!bz&&bf||az&&af&&!bz&&bf) ans=1ll*ami*bma;
		if(az&&!af&&bz&&!bf||az&&af&&bz&&!bf) ans=1ll*ama*bmi;
		if(!az&&af&&bz&&!bf||!az&&af&&bz&&bf) ans=1ll*ama*bma;
		if(az&&af&&bz&&bf) ans=max(1ll*zm*bmi,1ll*fm*bma);
		pr(ans);
	}
	return 0;
}

