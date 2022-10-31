#include<bits/stdc++.h>
using namespace std;
const int M=100010,N=100010,T=17;
long long a[N],b[M];
long long amax[N][T],amin[N][T],bmax[M][T],bmin[M][T];
int lo2[N];
int main(){
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	int n,m,q;
	scanf("%d%d%d",&n,&m,&q);
	for(int i=2;i<=max(n,m);i++){
		lo2[i]=lo2[i>>1]+1;
	}
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
	}
	for(int i=1;i<=m;i++){
		scanf("%lld",&b[i]);
	}
	for(int i=1;i<=n;i++){
		amax[i][0]=a[i];
		amin[i][0]=a[i];
	}
	for(int len=1;(1<<len)<=n;len++){
		for(int j=(1<<len);j<=n;j++){
			amax[j][len]=max(amax[j][len-1],amax[j-(1<<(len-1))][len-1]);
			amin[j][len]=min(amin[j][len-1],amin[j-(1<<(len-1))][len-1]);
		}
	}
	for(int i=1;i<=m;i++){
		bmax[i][0]=b[i];
		bmin[i][0]=b[i];
	}
	for(int len=1;(1<<len)<=m;len++){
		for(int j=(1<<len);j<=m;j++){
			bmax[j][len]=max(bmax[j][len-1],bmax[j-(1<<(len-1))][len-1]);
			bmin[j][len]=min(bmin[j][len-1],bmin[j-(1<<(len-1))][len-1]);
		}
	}
	while(q--){
		int l1,r1,l2,r2;
		scanf("%d%d%d%d",&l1,&r1,&l2,&r2);
		if(l2==r2){
			int len=lo2[r1-l1+1];
			if(b[l2]<0){
				printf("%lld",min(amin[r1][len],amin[l1+(1<<len)-1][len])*b[l2]);
			}
			else{
				printf("%lld",max(amax[r1][len],amax[l1+(1<<len)-1][len])*b[l2]);
			}
		}
		else{
			long long ans=LONG_LONG_MIN;
			for(;l1<=r1;l1++){
				int len=lo2[r2-l2+1];
				if(a[l1]<0){
					ans=max(ans,max(bmax[r2][len],bmax[l2+(1<<len)-1][len])*a[l1]);
				}
				else{
					ans=max(ans,min(bmin[r2][len],bmin[l2+(1<<len)-1][len])*a[l1]);
				}
			}
			printf("%lld",ans);
		}
		printf("\n");
	}
	return 0;
}

