#include <bits/stdc++.h>
using namespace std;
const int N=1e3+5;
int a[N],b[N],n,m,q;
long long maa[N],mib[N],c[N][N];
int main(){
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	memset(maa,0x3f,sizeof(maa));
	memset(mib,-0x3f,sizeof(mib));
	scanf("%d%d%d",&n,&m,&q);
	for(int i = 1;i <=n;i++){
		scanf("%d",&a[i]);
	}
	for(int i = 1;i <=m;i++){
		scanf("%d",&b[i]);
	}
	for(int i = 1;i <=n;i++){
		for(int j = 1;j <= m;j++){
			c[i][j]=a[i]*b[j];
			maa[i]=min(maa[i],c[i][j]);
		}
	}
	int l1,r1,l2,r2;
	while(q--){
		scanf("%d%d%d%d",&l1,&r1,&l2,&r2);
		long long ans=-1e10;
		for(int i = l1;i<=r1;i++){
			long long a2=c[i][l2];
			for(int j = l2+1;j<=r2;j++){
				if(c[i][j]<a2){
					a2=c[i][j];
				}
			}
			ans=max(ans,a2);
		}
		printf("%lld\n",ans);
	}
}
