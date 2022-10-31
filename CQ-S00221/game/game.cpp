#include<cstdio>
#include<cmath>
#include<algorithm>
using namespace std;
int n,m,q,a[100005],b[100005];
int main(){
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	scanf("%d%d%d",&n,&m,&q);
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	for(int i=1;i<=m;i++)scanf("%d",&b[i]);
	for(int i=1;i<=q;i++){
		int l1,r1,l2,r2;
		int lb=-99999999;
		int qs=99999999;
		scanf("%d%d%d%d",&l1,&r1,&l2,&r2);
		for(int j=l1;j<=r1;j++)
			lb=max(lb,a[j]);
		for(int j=l2;j<=r2;j++)
			qs=min(qs,b[j]);
		
		printf("%lld\n",(long long)lb*qs);
	}
	return 0;
}
