#include<bits/stdc++.h>
#define int long long
using namespace std;
const int maxn=1e5+5;
int n,m,q,a[maxn],b[maxn],Log[maxn],dp[2][maxn][15][4];
inline int read(){
	int res=0,f=0;
	char ch=getchar();
	while(ch<'0'||ch>'9'){
		f|=(ch=='-');
		ch=getchar();
	}
	while(ch>='0'&&ch<='9'){
		res=(res<<1)+(res<<3)+(ch^'0');
		ch=getchar();
	} 
	return f?-res:res;
}
inline int Qmax(int p1,int l,int r,int p2){
	int k=Log[r-l+1];
	return max(dp[p1][l][k][p2],dp[p1][r-(1<<k)+1][k][p2]);
}
inline int Qmin(int p1,int l,int r,int p2){
	int k=Log[r-l+1];
	return min(dp[p1][l][k][p2],dp[p1][r-(1<<k)+1][k][p2]);
}
signed main(){
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	n=read(),m=read(),q=read();
	for(int i=2;i<=max(n,m);++i)
		Log[i]=Log[i>>1]+1;
	for(int i=1;i<=max(n,m);++i)
		dp[0][i][0][0]=dp[1][i][0][0]=dp[0][i][0][2]=dp[1][i][0][2]=-2e9,dp[0][i][0][1]=dp[1][i][0][1]=dp[0][i][0][3]=dp[1][i][0][3]=2e9;
	for(int i=1;i<=n;++i){
		a[i]=read();
		if(a[i]<=0)
			dp[0][i][0][2]=dp[0][i][0][3]=a[i];
		else
			dp[0][i][0][0]=dp[0][i][0][1]=a[i]; 
	}
	for(int i=1;i<=m;++i){
		b[i]=read();
		if(b[i]<=0)
			dp[1][i][0][2]=dp[1][i][0][3]=b[i];
		else
			dp[1][i][0][0]=dp[1][i][0][1]=b[i];
	}
	for(int j=1;(1<<j)<=n;++j){
		for(int i=1;i+(1<<j)-1<=n;++i){
			dp[0][i][j][0]=max(dp[0][i][j-1][0],dp[0][i+(1<<j-1)][j-1][0]);
			dp[0][i][j][1]=min(dp[0][i][j-1][1],dp[0][i+(1<<j-1)][j-1][1]);
			dp[0][i][j][2]=max(dp[0][i][j-1][2],dp[0][i+(1<<j-1)][j-1][2]);
			dp[0][i][j][3]=min(dp[0][i][j-1][3],dp[0][i+(1<<j-1)][j-1][3]);
		}
		for(int i=1;i+(1<<j)-1<=m;++i){
			dp[1][i][j][0]=max(dp[1][i][j-1][0],dp[1][i+(1<<j-1)][j-1][0]);
			dp[1][i][j][1]=min(dp[1][i][j-1][1],dp[1][i+(1<<j-1)][j-1][1]);
			dp[1][i][j][2]=max(dp[1][i][j-1][2],dp[1][i+(1<<j-1)][j-1][2]);
			dp[1][i][j][3]=min(dp[1][i][j-1][3],dp[1][i+(1<<j-1)][j-1][3]);
		}
	}
	while(q--){
		int l1=read(),r1=read(),l2=read(),r2=read();
		if(Qmax(0,l1,r1,2)==-2e9){
			if(Qmax(1,l2,r2,2)==-2e9)
				printf("%lld\n",Qmax(0,l1,r1,0)*Qmin(1,l2,r2,1));
			else
				printf("%lld\n",Qmin(0,l1,r1,1)*Qmin(1,l2,r2,3));
		} else if(Qmax(0,l1,r1,0)==-2e9){
			if(Qmax(1,l2,r2,0)==-2e9)
				printf("%lld\n",Qmin(0,l1,r1,3)*Qmax(1,l2,r2,2));
			else
				printf("%lld\n",Qmax(0,l1,r1,2)*Qmax(1,l2,r2,0));
		} else{
			if(Qmax(1,l2,r2,0)==-2e9)
				printf("%lld\n",Qmin(0,l1,r1,3)*Qmax(1,l2,r2,2));
			else if(Qmax(1,l2,r2,2)==-2e9)
				printf("%lld\n",Qmax(0,l1,r1,0)*Qmin(1,l2,r2,1));
			else
				printf("%lld\n",max(Qmax(0,l1,r1,2)*Qmax(1,l2,r2,0),Qmin(0,l1,r1,1)*Qmin(1,l2,r2,3)));
		} 
	}
	return 0;
}
