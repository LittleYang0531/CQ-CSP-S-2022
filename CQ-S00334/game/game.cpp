#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,m,q;
const int maxn=1e5+5;
int a[maxn],b[maxn];
int maxx1[maxn][25],minn1[maxn][25],maxx2[maxn][25],minn2[maxn][25],g[maxn]; 
int getmax1(int l,int r){
	int k=g[r-l+1];
	return max(maxx1[l][k],maxx1[r-(1<<k)+1][k]);
}
int getmin1(int l,int r){
	int k=g[r-l+1];
	return min(minn1[l][k],minn1[r-(1<<k)+1][k]);
}
int getmax2(int l,int r){
	int k=g[r-l+1];
	return max(maxx2[l][k],maxx2[r-(1<<k)+1][k]);
}
int getmin2(int l,int r){
	int k=g[r-l+1];
	return min(minn2[l][k],minn2[r-(1<<k)+1][k]);
}
int main(){
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout); 
	scanf("%d%d%d",&n,&m,&q);
	memset(minn1,127,sizeof(minn1));
	memset(minn2,127,sizeof(minn2));
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		maxx1[i][0]=minn1[i][0]=a[i];
	}
	for(int i=1;i<=m;i++){
		scanf("%d",&b[i]);
		maxx2[i][0]=minn2[i][0]=b[i];
	}
//	printf("OK\n");
	g[1]=0;
	for(int i=2;i<=m;i++)	g[i]=g[i/2]+1;
	for(int i=1;(1<<i)<=n;i++){
//		printf("A");
		for(int x=1;x+(1<<i)-1<=n;x++){
			maxx1[x][i]=max(maxx1[x][i-1],maxx1[x+(1<<(i-1))][i-1]);
			minn1[x][i]=min(minn1[x][i-1],minn1[x+(1<<(i-1))][i-1]);
//			printf("(%d,%d) %d %d\n",x,x+(1<<i)-1,maxx[x][i],minn[x][i]);
		}
	}
	for(int i=1;(1<<i)<=m;i++){
//		printf("A");
		for(int x=1;x+(1<<i)-1<=m;x++){
			maxx2[x][i]=max(maxx2[x][i-1],maxx2[x+(1<<(i-1))][i-1]);
			minn2[x][i]=min(minn2[x][i-1],minn2[x+(1<<(i-1))][i-1]);
//			printf("(%d,%d) %d %d\n",x,x+(1<<i)-1,maxx[x][i],minn[x][i]);
		}
	}
	/*for(int i=1;i<=5;i++){
		int l,r;
		scanf("%d%d",&l,&r);
		printf("%d %d\n",getmax(l,r),getmin(l,r));
	}*/
	while(q--){
		int l1,l2,r1,r2;
		scanf("%d%d%d%d",&l1,&r1,&l2,&r2);
		if(l1==r1){
			if(a[l1]==0)	printf("0\n");
			else if(a[l1]>0){
				ll ans=(ll)a[l1]*(ll)getmin2(l2,r2);
				printf("%lld\n",ans);
			}else if(a[l1]<0){
				ll ans=(ll)a[l1]*(ll)getmax2(l2,r2);
				printf("%lld\n",ans);
			}
		}else if(l2==r2){
			if(b[l2]==0)	printf("0\n");
			else if(b[l2]>0){
				ll ans=(ll)b[l2]*(ll)getmax1(l1,r1);
				printf("%lld\n",ans);
			}else if(b[l2]<0){
				ll ans=(ll)b[l2]*(ll)getmin1(l1,r1);
				printf("%lld\n",ans);
			}
		}else{
			ll ans=-1e18-1;
			for(int i=l1;i<=r1;i++){
				if(a[i]==0)	ans=max(ans,(ll)0);
				else if(a[i]>0)	ans=max(ans,(ll)a[i]*(ll)getmin2(l2,r2));
				else	ans=max(ans,(ll)a[i]*(ll)getmax2(l2,r2));
			}
			printf("%lld\n",ans);
		}
	}
	return 0;
}
