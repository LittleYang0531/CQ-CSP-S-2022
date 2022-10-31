#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=1e5+10;
ll a[N],b[N];
ll Max1[N][20],Max2[N][20],Min1[N][20],Min2[N][20];
ll mi1z[N][20],ma1f[N][20];
int main(){
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	int q,flag=1,n,m;
	scanf("%d%d%d",&n,&m,&q);
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
		Max1[i][0]=Min1[i][0]=a[i];
		if(a[i]>0)mi1z[i][0]=a[i],ma1f[i][0]=-1e18;
		if(a[i]<0)mi1z[i][0]=1e18,ma1f[i][0]=a[i];
		if(a[i]<=0)flag=0;
	}
	for(int i=1;i<=m;i++){
		scanf("%lld",&b[i]);
		Max2[i][0]=Min2[i][0]=b[i];
		if(b[i]<=0)flag=0;
	}
	for(int i=1;i<=log2(n);i++)for(int j=1;j+(1<<i)-1<=n;j++)
		Max1[j][i]=max(Max1[j][i-1],Max1[j+(1<<i-1)][i-1]),Min1[j][i]=min(Min1[j][i-1],Min1[j+(1<<i-1)][i-1]),
		ma1f[j][i]=max(ma1f[j][i-1],ma1f[j+(1<<i-1)][i-1]),mi1z[j][i]=min(mi1z[j][i-1],mi1z[j+(1<<i-1)][i-1]);
	for(int i=1;i<=log2(m);i++)for(int j=1;j+(1<<i)-1<=m;j++)
		Max2[j][i]=max(Max2[j][i-1],Max2[j+(1<<i-1)][i-1]),Min2[j][i]=min(Min2[j][i-1],Min2[j+(1<<i-1)][i-1]);
	if(flag){
		while(q--){
			int l1,r1,l2,r2;
			scanf("%d%d%d%d",&l1,&r1,&l2,&r2);
			int t1=log2(r1-l1+1),t2=log2(r2-l2+1);
			printf("%lld\n",max(Max1[l1][t1],Max1[r1-(1<<t1)+1][t1])*min(Min2[l2][t2],Min2[r2-(1<<t2)+1][t2]));
		}
		return 0;
	}
	while(q--){
		int l1,r1,l2,r2;
		scanf("%d%d%d%d",&l1,&r1,&l2,&r2);
		int t1=log2(r1-l1+1),t2=log2(r2-l2+1);
		if(n<=1000){
			ll ans=-1e18;
			for(int i=l1;i<=r1;i++){
				if(a[i]==0)ans=max(0ll,ans);
				else if(a[i]<0){
					ans=max(ans,a[i]*max(Max2[l2][t2],Max2[r2-(1<<t2)+1][t2]));
				}else ans=max(ans,a[i]*min(Min2[l2][t2],Min2[r2-(1<<t2)+1][t2]));
			}
			printf("%lld\n",ans);
		}else if(r1==l1){
			printf("%lld\n",a[l1]*min(Min2[l2][t2],Min2[r2-(1<<t2)+1][t2]));
		}else if(r2==l2)printf("%lld\n",b[l2]*max(Max1[l1][t1],Max1[r1-(1<<t1)+1][t1]));
		else{
			ll max1=max(Max1[l1][t1],Max1[r1-(1<<t1)+1][t1]),min1=min(Min1[l1][t1],Min1[r1-(1<<t1)+1][t1]);
			ll max2=max(Max2[l2][t2],Max2[r2-(1<<t2)+1][t2]),min2=min(Min2[l2][t2],Min2[r2-(1<<t2)+1][t2]);
			ll maf=max(ma1f[l1][t1],ma1f[r1-(1<<t1)+1][t1]),miz=min(mi1z[l1][t1],mi1z[r1-(1<<t1)+1][t1]);
			if(min1>0){
				if(min2>=0)printf("%lld\n",max1*min2);
				else printf("%lld\n",min2*min1);
			}else if(min1<0&&max1>0){
				if(min2>=0)printf("%lld\n",min2*max1);
				else if(min2<0&&max2>=0)printf("%lld\n",max(max2*maf,min2*miz));
				else printf("%lld\n",min1*max2);
			}else{
				if(min2>=0)printf("%lld\n",max1*max2);
				else if(min2<0&&max2>=0) printf("%lld\n",max1*max2);
				else printf("%lld\n",min1*max2);
			}
		}
	}
	/*3 2 2
	1 2 3
	6 9
	1 3 1 2
	2 3 2 2*/
	return 0;
}
