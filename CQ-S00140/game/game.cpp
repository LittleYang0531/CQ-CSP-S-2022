#include<bits/stdc++.h>
using namespace std;
int n,m,q,a[100001],b[100001],l1,r1,l2,r2,f[100001][30],ff[100001][30],pd;
long long c[1001][1001],ans;
int main(){
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	scanf("%d%d%d",&n,&m,&q);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		if(a[i]<0) pd=1;
		f[i][0]=a[i];
	}
	for(int i=1;i<=m;i++){
		scanf("%d",&b[i]);
		if(b[i]<0) pd=1;
		ff[i][0]=b[i];
	}
	if(!pd&&n>=200&&m>=200&&q>=200){
		int nn=log(n);
		for(int j=1;j<=nn;j++){
			for(int i=1;i+(1<<j)-1<=n;i++){
				f[i][j]=max(f[i][j-1],f[i+(1<<j-1)][j-1]);
			}
		}
		nn=log(m);
		for(int j=1;j<=nn;j++){
			for(int i=1;i+(1<<j)-1<=m;i++){
				ff[i][j]=min(ff[i][j-1],ff[i+(1<<j-1)][j-1]);
			}
		}
	}else{
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++){
				c[i][j]=a[i]*b[j];
			}
		}
	}
	while(q--){
		scanf("%d%d%d%d",&l1,&r1,&l2,&r2);
		if(!pd&&n>=200&&m>=200&&q>=200){
			int nn=log(r1-l1+1),n1=log(r2-l2+1);
			long long k1=max(f[l1][nn],f[r1-(1<<nn)+1][nn]),k2=min(ff[l2][n1],ff[r2-(1<<n1)+1][n1]);
			printf("%lld\n",k1*k2);
			continue;
		}
		ans=-0x7ffffffffffffff;
		for(int i=l1;i<=r1;i++){
			long long w=0x7ffffffffffffff;
			for(int j=l2;j<=r2;j++){
				w=min(w,c[i][j]);
			}
			ans=max(ans,w);
		}
		printf("%lld\n",ans);
	}
	return 0;
}
