#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=2e5+5;
int n,m,q;
int a[N],b[N];
ll MAX1[N][20],MAX2[N][20],MIN1[N][20],MIN2[N][20];
ll get1max(int l,int r) {
	int k=log2(r-l+1);
	return max(MAX1[l][k],MAX1[r-(1<<k)+1][k]);
}
ll get2max(int l,int r) {
	int k=log2(r-l+1);
	return max(MAX2[l][k],MAX2[r-(1<<k)+1][k]);
}
ll get1min(int l,int r) {
	int k=log2(r-l+1);
	return min(MIN1[l][k],MIN1[r-(1<<k)+1][k]);
}
ll get2min(int l,int r) {
	int k=log2(r-l+1);
	return min(MIN2[l][k],MIN2[r-(1<<k)+1][k]);
}
void solve1(){
	for(int i=1;i<=q;i++) {
		int l1,l2,r1,r2;
		scanf("%d%d%d%d",&l1,&r1,&l2,&r2);
		printf("%lld\n",get1max(l1,r1)*get2min(l2,r2));
	}
}
void solve() {
	for(int i=1;i<=q;i++) {
		int l1,r1,l2,r2;
		scanf("%d%d%d%d",&l1,&r1,&l2,&r2);
		if(l1==r1) {
			if(a[l1]>0) printf("%lld\n",a[l1]*get2min(l2,r2));
			if(a[l1]<0) printf("%lld\n",a[l1]*get2max(l2,r2));
		}
		else if(l2==r2) {
			if(a[l1]>0) printf("%lld\n",b[l2]*get1max(l2,r2));
			if(a[l1]<0) printf("%lld\n",b[l2]*get1min(l2,r2));
		}
		else {
			ll ans=-1000000000000000000;
			for(int j=l1;j<=r1;j++) {
				ll M;
				if(a[j]>0) M=(ll)a[j]*get2min(l2,r2);
				else M=(ll)a[j]*get2max(l2,r2);
				ans=max(ans,M);
			}
			printf("%lld\n",ans);
		}
	}
}
void solve_RP() {
	int flag=1;
	for(int j=1;(1<<j)<=100005;j++) {
		for(int i=1;i+(1<<j)-1<=100005;i++){
			MAX1[i][j]=-1000000000000000000;
			MIN1[i][j]=1000000000000000000;
			MAX2[i][j]=-1000000000000000000;
			MIN2[i][j]=1000000000000000000;
		}
	}
	scanf("%d%d%d",&n,&m,&q);
	for(int i=1;i<=n;i++) {
		scanf("%d",&a[i]);
		MAX1[i][0]=MIN1[i][0]=a[i];
		if(a[i]<0)flag=0;
	}
	for(int i=1;i<=m;i++) {
		scanf("%d",&b[i]);
		MAX2[i][0]=MIN2[i][0]=b[i];
		if(b[i]<0)flag=0;
	}
	for(int j=1;(1<<j)<=n;j++) {
		for(int i=1;i+(1<<j)-1<=n;i++){
			MAX1[i][j]=max(MAX1[i][j-1],MAX1[i+(1<<(j-1))][j-1]);
			MIN1[i][j]=min(MIN1[i][j-1],MIN1[i+(1<<(j-1))][j-1]);
		}
	}
	
	for(int j=1;(1<<j)<=m;j++) {
		for(int i=1;i+(1<<j)-1<=m;i++){
			MAX2[i][j]=max(MAX2[i][j-1],MAX2[i+(1<<(j-1))][j-1]);
			MIN2[i][j]=min(MIN2[i][j-1],MIN2[i+(1<<(j-1))][j-1]);
		}
	}
	if(flag) {
		solve1();
		return;
	}
	solve();
}
int main() {
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	int T=1;
//	scanf("%d",&T);
	while(T--) {
		solve_RP();
	}
	return 0;
}

//
//
//
//
//#include <bits/stdc++.h>
//using namespace std;
//typedef long long ll;
//const int N=2e5+5;
//int n,m,q;
//int a[N],b[N];
//ll MAX1[N][20],MAX2[N][20],MIN1[N][20],MIN2[N][20],MAX4[N][20],MIN3[N][20],MAX5[N][20],MAX6[N][20];
//ll get1max(int l,int r) {
//	int k=log2(r-l+1);
//	return max(MAX1[l][k],MAX1[r-(1<<k)+1][k]);
//}
//ll get2max(int l,int r) {
//	int k=log2(r-l+1);
//	return max(MAX2[l][k],MAX2[r-(1<<k)+1][k]);
//}
//ll get1min(int l,int r) {
//	int k=log2(r-l+1);
//	return min(MIN1[l][k],MIN1[r-(1<<k)+1][k]);
//}
//ll get2min(int l,int r) {
//	int k=log2(r-l+1);
//	return min(MIN2[l][k],MIN2[r-(1<<k)+1][k]);
//}
//ll get3min(int l,int r) {
//	int k=log2(r-l+1);
//	return min(MIN3[l][k],MIN3[r-(1<<k)+1][k]);
//}
//ll get4max(int l,int r) {
//	int k=log2(r-l+1);
//	return max(MAX4[l][k],MAX4[r-(1<<k)+1][k]);
//}
//ll get5max(int l,int r) {
//	int k=log2(r-l+1);
//	return max(MAX5[l][k],MAX5[r-(1<<k)+1][k]);
//}
//ll get6max(int l,int r) {
//	int k=log2(r-l+1);
//	return max(MAX6[l][k],MAX6[r-(1<<k)+1][k]);
//}
//void solve1(){
//	for(int i=1;i<=q;i++) {
//		int l1,l2,r1,r2;
//		scanf("%d%d%d%d",&l1,&r1,&l2,&r2);
//		printf("%lld\n",get1max(l1,r1)*get2min(l2,r2));
//	}
//}
//void solve() {
//	for(int i=1;i<=q;i++) {
//		int l1,r1,l2,r2;
//		scanf("%d%d%d%d",&l1,&r1,&l2,&r2);
//		if(l1==r1) {
//			if(a[l1]>0) printf("%lld\n",a[l1]*get2min(l2,r2));
//			if(a[l1]<0) printf("%lld\n",a[l1]*get2max(l2,r2));
//		}
//		else if(l2==r2) {
//			if(a[l1]>0) printf("%lld\n",b[l2]*get1max(l2,r2));
//			if(a[l1]<0) printf("%lld\n",b[l2]*get1min(l2,r2));
//		}
//		else {
//			ll ans=-1000000000000000000;
//			ll k1=get2min(l2,r2),k2=get2max(l2,r2);
//			if(k1<0) {
//				ans=max(ans,k1*get3min(l1,r1));
//			}
//			else {
//				if(get1max(l1,r1)>0) {
//					if(get6max(l2,r2)) {
//						ans=max(ans,0ll);
//					}
//					else {
//						ans=max(ans,k1*get1max(l1,r1));
//					}
//				}
//				else ans=max(ans,get1max(l1,r1)*k2);
//			}
//			if(k2>0) {
//				ans=max(ans,k2*get4max(l1,r1));
//			}
//			else {
//				if(get1min(l1,r1)<0) {
//					if(get6max(l2,r2)) {
//						ans=max(ans,0ll);
//					}
//					else {
//						ans=max(ans,k2*get1min(l1,r1));
//					}
//				}
//				else{
//					ans=max(ans,get1min(l1,r1)*k1);
//				}
//			}
//			if(ans<0&&get5max(l1,r1)) ans=0;
//			printf("%lld\n",ans);
//		}
//	}
//}
//void solve_RP() {
//	int flag=1;
//	for(int j=0;(1<<j)<=200005;j++) {
//		for(int i=1;i+(1<<j)-1<=200005;i++){
//			MAX1[i][j]=-1000000000000000000;
//			MIN1[i][j]=1000000000000000000;
//			MAX2[i][j]=-1000000000000000000;
//			MIN2[i][j]=1000000000000000000;
//			MIN3[i][j]=1000000000000000000;
//			MAX4[i][j]=-1000000000000000000;
//		}
//	}
//	scanf("%d%d%d",&n,&m,&q);
//	for(int i=1;i<=n;i++) {
//		scanf("%d",&a[i]);
//		MAX1[i][0]=MIN1[i][0]=a[i];
//		if(a[i]==0) MAX5[i][0]=1;
//		if(a[i]>0) MIN3[i][0]=a[i];
//		if(a[i]<0)flag=0,MAX4[i][0]=a[i];
//	}
//	for(int i=1;i<=m;i++) {
//		scanf("%d",&b[i]);
//		if(b[i]==0) MAX6[i][0]=1;
//		MAX2[i][0]=MIN2[i][0]=b[i];
//		if(b[i]<0)flag=0;
//	}
//	for(int j=1;(1<<j)<=n;j++) {
//		for(int i=1;i+(1<<j)-1<=n;i++){
//			MAX1[i][j]=max(MAX1[i][j-1],MAX1[i+(1<<(j-1))][j-1]);
//			MIN1[i][j]=min(MIN1[i][j-1],MIN1[i+(1<<(j-1))][j-1]);
//			MIN3[i][j]=min(MIN3[i][j-1],MIN3[i+(1<<(j-1))][j-1]);
//			MAX4[i][j]=max(MAX4[i][j-1],MAX4[i+(1<<(j-1))][j-1]);
//			MAX5[i][j]=max(MAX5[i][j-1],MAX5[i+(1<<(j-1))][j-1]);
//		}
//	}
//	
//	for(int j=1;(1<<j)<=m;j++) {
//		for(int i=1;i+(1<<j)-1<=m;i++){
//			MAX2[i][j]=max(MAX2[i][j-1],MAX2[i+(1<<(j-1))][j-1]);
//			MIN2[i][j]=min(MIN2[i][j-1],MIN2[i+(1<<(j-1))][j-1]);
//			MAX6[i][j]=max(MAX6[i][j-1],MAX6[i+(1<<(j-1))][j-1]);
//		}
//	}
//	if(flag) {
//		solve1();
//		return;
//	}
//	solve();
//}
//int main() {
//	freopen("game.in","r",stdin);
//	freopen("game.out","w",stdout);
//	int T=1;
////	scanf("%d",&T);
//	while(T--) {
//		solve_RP();
//	}
//	return 0;
//}
