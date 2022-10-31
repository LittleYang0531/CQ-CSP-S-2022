#include<bits/stdc++.h>
using namespace std;
int read(){
	int x=0;char c=getchar();bool f=0;
	while(c>'9'||c<'0')f|=(c=='-'),c=getchar();
	while(c>='0'&&c<='9')x=(x<<1)+(x<<3)+(c^'0'),c=getchar();
	return f?-x:x;
}
int n,m,q,a[1005],b[1005],Log[1005];
long long c[1005][1005],dp[1005][1005][15];
long long Get(int i,int l,int r){
	int k=Log[r-l+1];
	return min(dp[i][l][k],dp[i][r-(1<<k)+1][k]);
}
int main()
{
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	n=read(),m=read(),q=read();
	for(int i=1;i<=n;i++)a[i]=read();
	for(int i=1;i<=m;i++)b[i]=read();
	for(int i=1;i<=n;i++)for(int j=1;j<=m;j++)c[i][j]=1LL*a[i]*b[j];
	for(int i=2;i<=1000;i++)Log[i]=Log[i>>1]+1;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++)dp[i][j][0]=c[i][j];
		for(int j=1;(1<<j)<=m;j++){
			for(int k=1;k+(1<<j)-1<=m;k++){
				dp[i][k][j]=min(dp[i][k][j-1],dp[i][k+(1<<j-1)][j-1]);
			}
		}
	}
	int l1,l2,r1,r2;
	while(q--){
		l1=read(),r1=read(),l2=read(),r2=read();
		long long ans=-4e18;
		for(int i=l1;i<=r1;i++){
			ans=max(ans,Get(i,l2,r2));
		}
		printf("%lld\n",ans);
	}
	return 0;
}
