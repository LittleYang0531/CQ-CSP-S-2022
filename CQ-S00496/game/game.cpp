#include<bits/stdc++.h>
#define int long long
using namespace std;
const int INF=999999999999999999ll;
int n,m,Q;
int a[100005],b[100005],lo[100005],sum1[100005],sum2[100005],s[5],t[5];
int p1x[2][100005][21],p1n[2][100005][21],p2x[2][100005][21],p2n[2][100005][21];
void st() {
	for(int i=1;i<=n;i++) {
		p1x[0][i][0]=p1x[1][i][0]=-INF;
		if(a[i]>0) p1x[0][i][0]=a[i];
		if(a[i]<0) p1x[1][i][0]=a[i];
	}
	for(int i=1;i<=n;i++) {
		p1n[0][i][0]=p1n[1][i][0]=INF;
		if(a[i]>0) p1n[0][i][0]=a[i];
		if(a[i]<0) p1n[1][i][0]=a[i];
	}
	for(int i=1;i<=m;i++) {
		p2x[0][i][0]=p2x[1][i][0]=-INF;
		if(b[i]>0) p2x[0][i][0]=b[i];
		if(b[i]<0) p2x[1][i][0]=b[i];
	}
	for(int i=1;i<=m;i++) {
		p2n[0][i][0]=p2n[1][i][0]=INF;
		if(b[i]>0) p2n[0][i][0]=b[i];
		if(b[i]<0) p2n[1][i][0]=b[i];
	}
	for(int j=1;(1<<j)<=n;j++) {
		for(int i=1;i+(1<<j)-1<=n;i++) {
			p1x[0][i][j]=max(p1x[0][i][j-1],p1x[0][i+(1<<j-1)][j-1]);
			p1n[0][i][j]=min(p1n[0][i][j-1],p1n[0][i+(1<<j-1)][j-1]);
			p1x[1][i][j]=max(p1x[1][i][j-1],p1x[1][i+(1<<j-1)][j-1]);
			p1n[1][i][j]=min(p1n[1][i][j-1],p1n[1][i+(1<<j-1)][j-1]);
		}
	}
	for(int j=1;(1<<j)<=m;j++) {
		for(int i=1;i+(1<<j)-1<=m;i++) {
			p2x[0][i][j]=max(p2x[0][i][j-1],p2x[0][i+(1<<j-1)][j-1]);
			p2n[0][i][j]=min(p2n[0][i][j-1],p2n[0][i+(1<<j-1)][j-1]);
			p2x[1][i][j]=max(p2x[1][i][j-1],p2x[1][i+(1<<j-1)][j-1]);
			p2n[1][i][j]=min(p2n[1][i][j-1],p2n[1][i+(1<<j-1)][j-1]);
		}
	}
}
int ask(int l,int r,int op,int op2,int op3) {
	int k=lo[r-l+1];
	if(op==1) {
		if(op2==0) return max(p1x[op3][l][k],p1x[op3][r-(1<<k)+1][k]);
		if(op2==1) return min(p1n[op3][l][k],p1n[op3][r-(1<<k)+1][k]);
	}
	else {
		if(op2==0) return max(p2x[op3][l][k],p2x[op3][r-(1<<k)+1][k]);
		if(op2==1) return min(p2n[op3][l][k],p2n[op3][r-(1<<k)+1][k]);
	}
}
signed main() {
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	scanf("%lld%lld%lld",&n,&m,&Q);
	for(int i=1;i<=max(n,m);i++) lo[i]=log2(i);
	for(int i=1;i<=n;i++) scanf("%lld",&a[i]);
	for(int i=1;i<=m;i++) scanf("%lld",&b[i]);
	for(int i=1;i<=n;i++) sum1[i]=sum1[i-1]+(a[i]==0);
	for(int i=1;i<=m;i++) sum2[i]=sum2[i-1]+(b[i]==0);
	st();
	while(Q--) {
		int x,y,xx,yy,ans=-INF;scanf("%lld%lld%lld%lld",&x,&y,&xx,&yy);
		s[1]=ask(x,y,1,0,0),s[2]=ask(x,y,1,0,1),s[3]=ask(x,y,1,1,0),s[4]=ask(x,y,1,1,1);
		t[1]=ask(xx,yy,2,0,0),t[2]=ask(xx,yy,2,0,1),t[3]=ask(xx,yy,2,1,0),t[4]=ask(xx,yy,2,1,1);
		for(int i=1;i<=4;i++) {
			if(s[i]==INF||s[i]==-INF) continue;
			int res=INF;
			for(int j=1;j<=4;j++) {
				if(t[j]==INF||t[j]==-INF) continue;
				res=min(res,s[i]*t[j]);
			}
			if(res!=INF) ans=max(ans,res);
		}
		if(sum1[y]-sum1[x-1]>=1) ans=max(ans,0ll);
		if(sum2[yy]-sum2[xx-1]>=1) ans=min(ans,0ll);
		printf("%lld\n",ans);
	}
	return 0;
}
