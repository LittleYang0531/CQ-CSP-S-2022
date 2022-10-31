#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;
const int maxn=1003;
int n,m,q;
long long c[maxn][maxn][11],a[maxn],b[maxn],minn;
int main()
{
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	scanf("%d%d%d",&n,&m,&q);
	if(n>1000||m>1000) return 0;
	for(int i=1;i<=n;++i) scanf("%lld",&a[i]);
	for(int i=1;i<=m;++i) scanf("%lld",&b[i]);
	for(int i=1;i<=n;++i) for(int j=1;j<=m;++j) c[i][j][0]=a[i]*b[j];
	int k2=log2(m);
	for(int i=1;i<=n;++i)
		for(int j=1;j<=k2;++j)
			for(int k=1;k+(1<<j)<=m+1;++k)
				c[i][k][j]=min(c[i][k][j-1],c[i][k+(1<<j-1)][j-1]);
	while(q--){
		int l1,r1,l2,r2,l3,r3;scanf("%d%d%d%d",&l1,&r1,&l3,&r3);
		long long minn,mn,id=-1;
		for(int i=l1;i<=r1;++i){
			mn=9223372036854775807,l2=l3,r2=r3;
			for(int j=k2;j+1;--j) if(l2+(1<<j)<=r2+1) mn=min(mn,c[i][l2][j]),l2=l2+(1<<j);
			if(id==-1||mn>minn) minn=mn,id=1;
		}cout<<minn<<'\n';
	}
	return 0;
}
