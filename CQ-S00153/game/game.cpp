#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
LL n,m,q,a[100010],b[100010],sa[100010],sb[100010];
int l1,r1,l2,r2,zero[100010],tot;
int main(){
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	scanf("%lld%lld%lld",&n,&m,&q);
	for(int i=1;i<=n;++i){
		scanf("%lld",&a[i]);
		if(a[i]>0)sa[i]=sa[i-1]+1;
		else sa[i]=sa[i-1];
		if(a[i]==0)zero[++tot]=i;
	}
	for(int i=1;i<=m;++i){
		scanf("%lld",&b[i]);
		if(b[i]>0)sb[i]=sb[i-1]+1;
		else sb[i]=sb[i-1];
	}
	for(int i=1;i<=q;++i){
		scanf("%d%d%d%d",&l1,&r1,&l2,&r2);
		if(sb[r2]-sb[l2-1]<r2-l2+1&&sb[r2]-sb[l2-1]!=0){//b有正有负 结果<=0
			LL w=upper_bound(zero+1,zero+1+tot,l1)-zero;
			if(zero[w]<=r1){
				printf("0\n");
			}else{
				LL minn=1e18+2,minn2=1e18+2;
				LL ans;
				for(LL j=l1;j<=r1;++j){
					if(a[j]>=0)minn=min(minn,a[j]);
				}
				for(LL j=l2;j<=r2;++j){
					if(b[j]<=0)minn2=min(minn2,b[j]);
				}
				ans=1ll*minn*minn2;
				LL maxx=-1e18-2,maxx2=-1;
				for(LL j=l1;j<=r1;++j){
					if(a[j]<=0)maxx=max(maxx,a[j]);
				}
				for(LL j=l2;j<=r2;++j){
					if(b[j]>=0)maxx2=max(maxx2,b[j]);
				}
				printf("%lld\n",max(ans,1ll*maxx*maxx2));
			}
		}else if(sb[r2]-sb[l2-1]==0){//全负
			if(sa[r1]-sa[l1-1]<r1-l1+1){
				LL minn=1e18+2,maxx=-1e18-2;
				for(LL j=l1;j<=r1;++j){
					minn=min(minn,a[j]);
				}
				for(LL j=l2;j<=r2;++j){
					maxx=max(maxx,b[j]);
				}
				printf("%lld\n",1ll*minn*maxx);
			}else{//全正
				LL minn=1e18+2,minn2=1e18+2;
				for(LL j=l1;j<=r1;++j){
					minn=min(minn,a[j]);
				}
				for(LL j=l2;j<=r2;++j){
					minn2=min(minn2,b[j]);
				}
				printf("%lld\n",1ll*minn*minn2);
			}
		}else{//b全正
			if(sa[r1]-sa[l1-1]!=0){
				LL maxx=-1e18-2,minn=1e18+2;
				for(int j=l1;j<=r1;++j){
					maxx=max(maxx,a[j]);
				}
				for(int j=l2;j<=r2;++j){
					minn=min(minn,b[j]);
				}
				printf("%lld\n",1ll*maxx*minn);
			}else{//a全负
				LL maxx=-1e18-2,maxx2=0;
				for(LL j=l1;j<=r1;++j){
					maxx=max(maxx,a[j]);
				}
				for(LL j=l2;j<=r2;++j){
					maxx2=max(maxx2,b[j]);
				}
				printf("%lld\n",1ll*maxx*maxx2);
			}
		}
	}
	return 0;
}
