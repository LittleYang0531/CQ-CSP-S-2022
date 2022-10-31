#include <bits/stdc++.h> 
using namespace std;
long long n,m,q,a[100001],aa[100001],b[100001],f[2][100001][20],f1[2][100001][20],f2[2][100001][20];
int main(){
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	scanf("%lld%lld%lld",&n,&m,&q);
	for(long long i=1;i<=n;i++)
		scanf("%lld",&a[i]);
	for(long long i=1;i<=m;i++)
		scanf("%lld",&b[i]);
	for(long long i=1;i<=n;i++)
		f1[1][i][0]=a[i];
	for(long long j=1;(1<<j)<=n;j++)
		for(long long i=1;i<=n;i++)
			f1[1][i][j]=max(f1[1][i][j-1],f1[1][i+(1<<j-1)][j-1]);
	for(long long i=1;i<=n;i++)
		f2[0][i][0]=a[i];
	for(long long j=1;(1<<j)<=n;j++)
		for(long long i=1;i<=n;i++)
			f2[0][i][j]=min(f2[0][i][j-1],f2[0][i+(1<<j-1)][j-1]);
	for(long long i=1;i<=n;i++){
		aa[i]=a[i];
		if(aa[i]<0)
			aa[i]=0x3f3f3f3f;
		f1[0][i][0]=aa[i];
	}
	for(long long j=1;(1<<j)<=n;j++)
		for(long long i=1;i<=n;i++)
			f1[0][i][j]=min(f1[0][i][j-1],f1[0][i+(1<<j-1)][j-1]);
	for(long long i=1;i<=n;i++){
		aa[i]=a[i];
		if(aa[i]>0)
			aa[i]=-0x3f3f3f3f;
		f2[1][i][0]=aa[i];
	}
	for(long long j=1;(1<<j)<=n;j++)
		for(long long i=1;i<=n;i++)
			f2[1][i][j]=max(f2[1][i][j-1],f2[1][i+(1<<j-1)][j-1]);
	for(long long i=1;i<=m;i++)
		f[1][i][0]=b[i];
	for(long long j=1;(1<<j)<=m;j++)
		for(long long i=1;i<=m;i++)
			f[1][i][j]=max(f[1][i][j-1],f[1][i+(1<<j-1)][j-1]);
	for(long long i=1;i<=m;i++)
		f[0][i][0]=b[i];
	for(long long j=1;(1<<j)<=m;j++)
		for(long long i=1;i<=m;i++)
			f[0][i][j]=min(f[0][i][j-1],f[0][i+(1<<j-1)][j-1]);
	for(long long i=1;i<=q;i++){
		long long l1,r1,l2,r2,k1,k2,mf0,mf1,mf10,mf11,mf21,mf20;
		scanf("%lld%lld%lld%lld",&l1,&r1,&l2,&r2);
		if(r1-l1!=0)
			k1=log2(r1-l1);
		else
			k1=0;
		if(r2-l2!=0)
			k2=log2(r2-l2);
		else
			k2=0;
		mf0=min(f[0][l2][k2],f[0][r2-(1<<k2)+1][k2]);
		mf1=max(f[1][l2][k2],f[1][r2-(1<<k2)+1][k2]);
		mf11=max(f1[1][l1][k1],f1[1][r1-(1<<k1)+1][k1]);
		mf10=min(f1[0][l1][k1],f1[0][r1-(1<<k1)+1][k1]);
		mf21=max(f2[1][l1][k1],f2[1][r1-(1<<k1)+1][k1]);
		mf20=min(f2[0][l1][k1],f2[0][r1-(1<<k1)+1][k1]);
		if(mf0>0){
			printf("%lld\n",mf0*mf11);
			continue;
		}
		if(mf1<0){
			printf("%lld\n",mf1*mf20);
			continue;
		}
		printf("%lld\n",max(mf10*mf0,mf21*mf1));
	}
	return 0;
}
