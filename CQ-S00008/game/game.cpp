#include<bits/stdc++.h>
using namespace std;
#define int long long
inline int read(){
	register int x=0,f=1;
	char ch=getchar();
	while(ch>'9'||ch<'0'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9')x=(x<<1)+(x<<3)+(ch^48),ch=getchar();
	return x*f;
}
int n,m,q;
int a[100001],b[100001];
int maxa[100001][20],mina[100001][20];
int maxb[100001][20],minb[100001][20];
signed main(){
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	n=read();m=read();q=read();
	int sub=1;
	for(int i=1;i<=n;i++){
		a[i]=read();
		if(a[i]<=0)sub=0;
		maxa[i][0]=mina[i][0]=a[i];
	}
	int k=log2(n);
	for(int j=1;j<=k;j++)
	for(int i=1;i+(1<<j)-1<=n;i++){
		maxa[i][j]=max(maxa[i][j-1],maxa[i+(1<<(j-1))][j-1]);
		mina[i][j]=min(mina[i][j-1],mina[i+(1<<(j-1))][j-1]);
	}
	for(int i=1;i<=m;i++){
		b[i]=read();
		if(b[i]<=0)sub=0;
		maxb[i][0]=minb[i][0]=b[i];
	}
	k=log2(m);
	for(int j=1;j<=k;j++)
	for(int i=1;i+(1<<j)-1<=m;i++){
		maxb[i][j]=max(maxb[i][j-1],maxb[i+(1<<(j-1))][j-1]);
		minb[i][j]=min(minb[i][j-1],minb[i+(1<<(j-1))][j-1]);
	}
	if(n<=1000&&m<=1000&&q<=1000)sub=2;
	while(q--){
		int l1=read(),r1=read(),l2=read(),r2=read();
		if(sub==2){
			int minx=1e18,maxx=-1e18;
			for(int i=l2;i<=r2;i++){
				minx=min(minx,b[i]);
				maxx=max(maxx,b[i]);
			}
			int ans=-1e18;
			for(int i=l1;i<=r1;i++){
				if(a[i]==0)ans=max(ans,0ll);
				if(a[i]>0)
					ans=max(a[i]*minx,ans);
				if(a[i]<0)
					ans=max(a[i]*maxx,ans);
			}
			printf("%lld\n",ans);
		}
		else if(sub==1){
			int k1=log2(r1-l1+1);
			int k2=log2(r2-l2+1);
			int maxx=max(maxa[l1][k1],maxa[r1-(1<<k1)+1][k1]);
			int minn=min(minb[l2][k2],minb[r2-(1<<k2)+1][k2]);
			printf("%lld\n",maxx*minn);
		}else if(l1==r1){
			if(a[l1]==0)puts("0");
			if(a[l1]>0){
				int k2=log2(r2-l2+1);
				int minn=min(minb[l2][k2],minb[r2-(1<<k2)+1][k2]);
				printf("%lld\n",minn*a[l1]);
			}
			if(a[l1]<0){
				int k2=log2(r2-l2+1);
				int maxx=max(maxb[l2][k2],maxb[r2-(1<<k2)+1][k2]);
				printf("%lld\n",maxx*a[l1]);
			}
		}else if(l2==r2){
			if(b[l2]==0)puts("0");
			if(b[l2]<0){
				int k1=log2(r1-l1+1);
				int minn=min(mina[l1][k1],mina[r1-(1<<k1)+1][k1]);
				printf("%lld\n",minn*b[l2]);
			}
			if(b[l2]>0){
				int k1=log2(r1-l1+1);
				int maxx=max(maxa[l1][k1],maxa[r1-(1<<k1)+1][k1]);
				printf("%lld\n",maxx*b[l2]);
			}
		}
	}
	return 0;
}
/*
5 6 10
-2 3 0 -3 2
-9 3 -5 2 4 0
1 3 4 4
1 5 3 3*/
